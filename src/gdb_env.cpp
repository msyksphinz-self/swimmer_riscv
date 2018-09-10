/*
 * Copyright (c) 2016, msyksphinz
 * All rights reserved.
 *
 *   Redistribution and use in source and binary forms, with or without
 *   modification, are permitted provided that the following conditions are met:
 *   * Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *   * Neither the name of the copyright holder nor the
 *     names of its contributors may be used to endorse or promote products
 *     derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 *   ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY
 *   DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 *   (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 *   ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 *   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/** Sorry this code is almost based on rsp-server.cp in or1ksim **/


#include <iostream>
#include <iomanip>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/tcp.h>
#include <netinet/in.h>
#include <signal.h>
#include <fcntl.h>
#include <string.h>

#include "./gdb_env.hpp"
#include "./basic.hpp"


GdbServer::GdbServer (void)
{
  m_client_waiting =  0;		/* GDB client is not waiting for us */
  m_client_fd    = -1;		/* i.e. invalid */
  m_sigval     =  0;		/* No exception */

  /* Set up the matchpoint hash table */
  for (int i = 0; i < MP_HASH_SIZE; i++) {
    m_mp_hash[i] = NULL;
  }
}


GdbEnv::GdbEnv (EnvBase *env, int gdb_port)
{
  m_pe_thread = env;
  m_serial_port = gdb_port;

  m_gdb_server = std::unique_ptr<GdbServer> (new GdbServer());
}


void GdbEnv::HandleGdb (void)
{
  /* If we have no RSP client, wait until we get one. */
  while (m_gdb_server->GetClientFd() == -1) {
    GetClientPort ();
    m_gdb_server->SetClientWait (0);		/* No longer waiting */
  }

  /* If we have an unacknowledged exception tell the GDB client. If this
     exception was a trap due to a memory breakpoint, then adjust the NPC. */
  if (m_gdb_server->GetClientWait () != 0) {
    // if ((TARGET_SIGNAL_TRAP == m_gdb_server->GetSigVal()) &&
    //   (mp_hash_lookup (BP_MEMORY, cpu_state.sprs[SPR_PPC]) != NULL)) {
    //   set_npc (cpu_state.sprs[SPR_PPC]);
    // }

    // rsp_report_exception();
    m_gdb_server->SetClientWait (0);		/* No longer waiting */
  }

  /* Get a RSP client request */
  // rsp_client_request ();

}


void GdbEnv::GetClientPort (void)
{
  int         tmp_fd;		/* Temporary descriptor for socket */
  int         optval;		/* Socket options */
  struct sockaddr_in  sock_addr;	/* Socket address */
  socklen_t       len;		/* Size of the socket address */

  /* 0 is used as the RSP port number to indicate that we should use the
     service name instead. */
  if (m_serial_port == 0) {
    struct servent *service = getservbyname (MIPS64_RSP_SERVICE, "tcp");
    if (service == NULL) {
      std::cerr << "Warning: RSP unable to find service \"" << MIPS64_RSP_SERVICE "\": strerror (errno)\n";
      return;
    }
    m_serial_port = ntohs (service->s_port);
  }

  /* Open a socket on which we'll listen for clients */
  tmp_fd = socket (PF_INET, SOCK_STREAM, IPPROTO_TCP);
  if (tmp_fd < 0) {
    fprintf (stderr, "ERROR: Cannot open RSP socket\n");
    exit (EXIT_FAILURE);
  }

  /* Allow rapid reuse of the port on this socket */
  optval = 1;
  setsockopt (tmp_fd, SOL_SOCKET, SO_REUSEADDR, (char *)&optval,
        sizeof (optval));

  /* Bind the port to the socket */
  sock_addr.sin_family    = PF_INET;
  sock_addr.sin_port    = htons (m_serial_port);
  sock_addr.sin_addr.s_addr = INADDR_ANY;
  if (bind (tmp_fd, (struct sockaddr *) &sock_addr, sizeof (sock_addr))) {
    std::cerr << "ERROR: Cannot bind to RSP socket\n";
    exit (EXIT_FAILURE);
  }

  /* Listen for (at most one) client */
  if (listen (tmp_fd, 1)) {
    std::cerr << "ERROR: Cannot listen on RSP socket\n";
    exit (EXIT_FAILURE);
  }

  std::cout << "Listening for RSP on port " << m_serial_port << std::endl;

  /* Accept a client which connects */
  len = sizeof (socklen_t);		/* Bug fix by Julius Baxter */
  int32_t client_fd = accept (tmp_fd, (struct sockaddr *)&sock_addr, &len);
  if (client_fd == -1) {
    fprintf (stderr, "Warning: Failed to accept RSP client\n");
    return;
  }

  m_gdb_server->SetClientFd (client_fd);

  /* Enable TCP keep alive process */
  optval = 1;
  setsockopt (client_fd, SOL_SOCKET, SO_KEEPALIVE, (char *)&optval,
        sizeof (optval));

  /* Don't delay small packets, for better interactive response (disable
     Nagel's algorithm) */
  optval = 1;
  setsockopt (client_fd, IPPROTO_TCP, TCP_NODELAY, (char *)&optval,
        sizeof (optval));

  /* Socket is no longer needed */
  close (tmp_fd);			/* No longer need this */
  signal (SIGPIPE, SIG_IGN);		/* So we don't exit if client dies */

  std::cout << "Remote debugging from host" << inet_ntoa (sock_addr.sin_addr) << "\n";

  return;
}


GdbStatus GdbEnv::HandleClientRequest ()
{
  std::string packet_str = GetPacket ();

  std::cerr << "Packet : " << packet_str << '\n';

  if (packet_str.empty () == true) {
    CloseRSPClient ();
    return GDB_ILLEGAL;
  }

  switch (packet_str.front()) {
  case '?' : {
    PutPacket ("S05");
    break;
  }
  case 'c' : {
    m_pe_thread->SetMaxCycle(1);
    m_pe_thread->StepSimulation (1, LoopType_t::InfLoop);
    m_pe_thread->FlushDbgFile ();
    m_pe_thread->FlushTraceFp ();
    m_pe_thread->SetDebugTrace(true); // Temporary Added
    PutPacket ("S05");
    break;
  }
  case 'k' : {
    return GDB_KILL;
  }
  case 'q' : {
    if (IsEqualHead (packet_str, "qSupported")) {
      std::stringstream str;
      // str << "PacketSize=" << std::hex << GDB_BUF_MAX;
      str << "PacketSize=" << GDB_BUF_MAX;
      PutPacket (str.str());
    } else if (IsEqualHead (packet_str, "qTStatus")) {
      PutPacket ("");
    } else if (IsEqualHead (packet_str, "qTfV")) {
      PutPacket ("QTinit");
    } else if (IsEqualHead (packet_str, "qTsV")) {
      PutPacket ("QTDV:25:25:1:pc");
    } else {
      PutPacket ("");
    }
    break;
  }
  case 'g' : {
    DumpGeneralRegisters ();
    break;
  }
  case 'G' : {
    SendPacketString ("OK");
    break;
  }
  case 'p' : {
    int reg_addr = 0;
    for (unsigned int idx = 1; idx < packet_str.length(); idx++) {
      reg_addr = reg_addr * 16 + Hex (packet_str[idx]);
    }

    DWord_t res;
    if (reg_addr == 0x25) { // Todo: Need to fix
      res = m_pe_thread->GetPC ();
      std::cout << "PC = " << std::hex << res << '\n';
    } else if(reg_addr < 32) {
      res = m_pe_thread->ReadGReg<DWord_t>(reg_addr);
    } else {
      res = 0x0;
    }
    DWord_t reversed_res = ReverseByte<DWord_t>(res);
    std::stringstream str;
    str << std::hex << std::setw(16) << std::setfill('0') << reversed_res;
    SendPacketString (str.str());
    break;
  }
  case 'P' : {
    SendPacketString ("OK");
    break;
  }
  case 'm' : {
    Addr_t mem_base = 0;
    Addr_t mem_size = 0;
    unsigned int idx;
    for (idx = 1; packet_str[idx] != ','; idx++) {
      mem_base = (mem_base << 4) | Hex (packet_str[idx]);
    }
    idx++;
    for (; idx < packet_str.length(); idx++) {
      mem_size = (mem_size << 4) | Hex (packet_str[idx]);
    }

    std::stringstream str;
    for (Addr_t i = 0; i < mem_size; i++) {
      Word_t word;
      m_pe_thread->LoadMemory (mem_base + i, &word);

      str << std::hex << std::setw(2) << std::setfill('0') << (word & 0xFF);
    }
    SendPacketString (str.str());
    break;
  }
  case 'H' : {
    PutPacket ("OK");
    break;
  }
  case 'X' : {
    // Memory Download
    Addr_t mem_base = -1;
    Addr_t mem_size = 0;
    unsigned int idx;
    for (idx = 1; packet_str[idx] != ','; idx++) {
      mem_base = (mem_base << 4) | Hex (packet_str[idx]);
    }
    idx++;
    for (idx = 1; packet_str[idx] != ':'; idx++) {
      mem_size = (mem_size << 4) | Hex (packet_str[idx]);
    }
    idx++;
    const char *packet_char = packet_str.c_str();
    for (; idx < packet_str.length();) {
      Word_t mem_data = 0;
      for (int i = 0; i < 4 && idx < packet_str.length(); i++) {
        if (packet_char[idx] == '}') {
          mem_data |= ((packet_char[++idx] & 0x0FF) ^ 0x20) << (i * 8);
        } else {
          mem_data |= (packet_char[idx] & 0x0FF) << (i * 8);
        }
        idx++;
      }

      m_pe_thread->StoreMemoryDebug (mem_base, reinterpret_cast<Byte_t *>(mem_data));
      mem_base += 4;
    }
    PutPacket ("OK");
    break;
  }
  case 'M' : {
    // Memory Download
    Addr_t  mem_addr = -1;
    DWord_t mem_data = 0;
    unsigned int idx;
    for (idx = 1; packet_str[idx] != ','; idx++) {
      mem_addr = (mem_addr << 4) | Hex (packet_str[idx]);
    }
    idx++;
    for (; idx != packet_str.length(); idx++) {
      mem_data = (mem_data << 4) | Hex (packet_str[idx]);
    }
    std::cout << "Command M is not supported.\n";
    // m_pe_thread->StoreMemoryDebug<DWord_t> (mem_addr, &mem_data);
    // PutPacket ("OK");
    break;
  }
  case 's' : {
    std::cerr << "Current Step = " << m_pe_thread->GetStep () << "\n";
    m_pe_thread->SetStep (m_pe_thread->GetStep () + 1);
    m_pe_thread->StepSimulation (1, LoopType_t::FiniteLoop);
    PutPacket ("S05");
    break;
  }
  case 'z' : {
    // Remove BreakPoint
    Addr_t break_addr = 0x00;
    if (IsEqualHead (packet_str, "z0")) {
      unsigned int idx;
      for (idx = 3; packet_str[idx] != ',' && idx < packet_str.length(); idx++) {
        break_addr = (break_addr << 4) | Hex (packet_str[idx]);
      }
      if (idx >= packet_str.length()) {
        PutPacket ("E00");
      } else {
        if (m_pe_thread->RemovePCBreak(break_addr)) {
          PutPacket ("OK");
        } else {
          PutPacket ("E00");
        }
      }
    }
    break;
  }
  case 'Z' : {
    // Set BreakPoint
    Addr_t break_addr = 0x00;

    if (IsEqualHead (packet_str, "Z0")) {
      unsigned int idx;
      for (idx = 3; packet_str[idx] != ',' && idx < packet_str.length(); idx++) {
        break_addr = (break_addr << 4) | Hex (packet_str[idx]);
      }
      if (idx >= packet_str.length()) {
        PutPacket ("E00");
      } else {
        m_pe_thread->AddPCBreak (break_addr);
        PutPacket ("OK");
      }
    }
    break;
  }
  case 'v' : {
    // multi-letter name, up to the first ‘;’ or ‘?’ (or the end of the packet).
    if (IsEqualHead (packet_str, "vCont?")) {
      // vCont Packet is not supported.
      PutPacket ("");
    }
    break;
  }
  default:
    std::cerr << "Unrecognized Packet : " << packet_str << '\n';
    PutPacket ("");
    break;
  }

  return GDB_NORMAL;
}


void GdbEnv::PutPacket (std::string buf)
{
  int  ch;				/* Ack char */

  /* Construct $<packet info>#<checksum>. Repeat until the GDB client
     acknowledges satisfactory receipt. */
  do {
    unsigned char checksum = 0;	/* Computed checksum */
    unsigned int  count  = 0;	/* Index into the buffer */

#if RSP_TRACE
    printf ("Putting %s\n", buf.c_str());
    fflush (stdout);
#endif

    PutRSPChar ('$');		/* Start char */

    /* Body of the packet */
    for (count = 0; count < buf.length(); count++) {
      unsigned char  ch = buf[count];

      /* Check for escaped chars */
      if (('$' == ch) || ('#' == ch) || ('*' == ch) || ('}' == ch)) {
        ch     ^= 0x20;
        checksum += (unsigned char)'}';
        PutRSPChar ('}');
      }

      checksum += ch;
      PutRSPChar (ch);
    }

    PutRSPChar ('#');		/* End char */

    /* Computed checksum */
    PutRSPChar (hexchars[checksum >> 4]);
    PutRSPChar (hexchars[checksum % 16]);

    /* Check for ack of connection failure */
    ch = GetRSPChar ();
    if (-1 == ch) {
      return;			/* Fail the put silently. */
    }
  }
  while ('+' != ch);
}


void GdbEnv::SendPacketString (const std::string str)
{
  PutPacket (str);
}


std::string GdbEnv::GetPacket ()
{
  std::string buf = "";

  /* Keep getting packets, until one is found with a valid checksum */
  while (1) {
    unsigned char  checksum;		/* The checksum we have computed */
    int      count;		/* Index into the buffer */
    int 	   ch;		/* Current character */

    /* Wait around for the start character ('$'). Ignore all other
       characters */
    ch = GetRSPChar ();
    while (ch != '$')  {
      if (-1 == ch) {
        return  NULL;		/* Connection failed */
      }

      ch = GetRSPChar ();
    }

    /* Read until a '#' or end of buffer is found */
    checksum =  0;
    count = 0;
    // while (count < GDB_BUF_MAX - 1) {
    while (count < GDB_BUF_MAX * 100) {
      ch = GetRSPChar ();

      /* Check for connection failure */
      if (-1 == ch) {
        return  NULL;
      }

      /* If we hit a start of line char begin all over again */
      if ('$' == ch) {
        checksum =  0;
        count  =  0;

        continue;
      }

      /* Break out if we get the end of line char */
      if ('#' == ch) {
        break;
      }

      /* Update the checksum and add the char to the buffer */

      checksum = checksum + (unsigned char)ch;
      buf += (char)ch;
      count++;
    }

    /* Mark the end of the buffer with EOS - it's convenient for non-binary
       data to be valid strings. */

    /* If we have a valid end of packet char, validate the checksum */
    if ('#' == ch) {
      unsigned char  xmitcsum;	/* The checksum in the packet */

      ch = GetRSPChar ();
      if (-1 == ch) {
        return  NULL;		/* Connection failed */
      }
      xmitcsum = Hex (ch) << 4;

      ch = GetRSPChar ();
      if (-1 == ch) {
        return  NULL;		/* Connection failed */
      }

      xmitcsum += Hex (ch);

      /* If the checksums don't match print a warning, and put the
         negative ack back to the client. Otherwise put a positive ack. */
      if (checksum != xmitcsum) {
        std::cerr << "Warning: Bad RSP checksum: Computed "
              << "0x" << std::hex << checksum << ", received 0x" << xmitcsum << '\n';

        PutRSPChar ('-');	/* Failed checksum */
      } else {
        PutRSPChar ('+');	/* successful transfer */
        break;
      }
    } else {
      std::cerr << "Warning: RSP packet overran buffer : " << buf.length() << "\n";
      std::cerr << static_cast<char>(ch) << '\n';
    }
  }

  return buf;				/* Success */
}


void GdbEnv::PutRSPChar (char  c)
{
  /* Write until successful (we retry after interrupts) or catastrophic
     failure. */
  while (1) {
    switch (write (m_gdb_server->GetClientFd (), &c, sizeof (c))) {
    case -1:
      /* Error: only allow interrupts or would block */
      if ((EAGAIN != errno) && (EINTR != errno)) {
        std::cerr <<  "Warning: Failed to write to RSP client: "
              << "Closing client connection: " << errno << '\n';
        CloseRSPClient ();
        return;
      }

      break;

    case 0:
      break;		/* Nothing written! Try again */

    default:
      return;		/* Success, we can return */
    }
  }
}


/*---------------------------------------------------------------------------*/
/*!Get a single character from the client socket

  This should only be called if the client is open, but we check for safety.

  @return  The character read, or -1 on failure               */
/*---------------------------------------------------------------------------*/
int GdbEnv::GetRSPChar ()
{
  /* Non-blocking read until successful (we retry after interrupts) or
     catastrophic failure. */
  while (1)  {
    unsigned char  c;

    switch (read (m_gdb_server->GetClientFd (), &c, sizeof (c))) {
    case -1:
      /* Error: only allow interrupts */
      if ((EAGAIN != errno) && (EINTR != errno))  {
        std::cerr << "Warning: Failed to read from RSP client: "
              << "Closing client connection: " << errno << '\n';
        CloseRSPClient ();
        return  -1;
      }

      break;

    case 0:
      // EOF
      CloseRSPClient ();
      return  -1;

    default:
      return  c & 0xff; /* Success, we can return (no sign extend!) */
    }
  }
}


void GdbEnv::DumpGeneralRegisters (void)
{
  std::stringstream str;
  for (Addr_t idx = 0; idx < 32; idx++) {
    DWord_t val = m_pe_thread->ReadGReg<DWord_t>(idx);
    DWord_t reversed_val = ReverseByte<DWord_t>(val);

    str << std::hex << std::setw(16) << std::setfill('0') << reversed_val;
  }
  SendPacketString (str.str().c_str());
}


void GdbEnv::CloseRSPClient (void)
{
  close (m_gdb_server->GetClientFd ());
}


bool GdbEnv::IsEqualHead (const std::string str1, const std::string str2)
{
  uint32_t len2 = str2.length();
  if (str1.substr(0, len2) == str2) {
    return true;
  } else {
    return false;
  }
}


template <class T> T GdbEnv::ReverseByte (T data)
{
  T reversed_data = 0;
  const int byte_size = sizeof (T);
  for (int idx = 0; idx < byte_size; idx++) {
    Byte_t byte = data & 0x0FF;
    reversed_data = reversed_data << 8 | (byte & 0x0FF);
    data >>= 8;
  }
  return reversed_data;
}


template Word_t  GdbEnv::ReverseByte (Word_t data);
template DWord_t GdbEnv::ReverseByte (DWord_t data);
