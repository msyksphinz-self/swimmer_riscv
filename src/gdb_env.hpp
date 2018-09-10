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


#pragma once

#include <stdint.h>
#include <vector>
#include <memory>
#include "env.hpp"
#include "basic.hpp"

/*! Size of the matchpoint hash table. Largest prime < 2^10 */
#define MP_HASH_SIZE  1021

/*! Name of the Or1ksim RSP service */
#define MIPS64_RSP_SERVICE  "mips64-rsp"
#define MIPS32_RSP_SERVICE  "mips32-rsp"
#define RISCV_RSP_SERVICE   "riscv-rsp"

#define MAX_GRPS   32             /*!< Maximum GPRs */
#define NUM_REGS   (MAX_GRPS + 3)	/*!< Total GDB registers */
#define GDB_BUF_MAX  ((NUM_REGS) * 8 + 1)


/*!
 * Data structure for RSP buffers.
 * Can't be null terminated, since it may
 * include zero bytes
 */
struct rsp_buf
{
  char  data[GDB_BUF_MAX];
  int   len;
};


/*! Definition of GDB target signals. Data taken from the GDB 6.8
  source. Only those we use defined here. */
enum target_signal {
  TARGET_SIGNAL_NONE =  0,
  TARGET_SIGNAL_INT  =  2,
  TARGET_SIGNAL_ILL  =  4,
  TARGET_SIGNAL_TRAP =  5,
  TARGET_SIGNAL_FPE  =  8,
  TARGET_SIGNAL_BUS  = 10,
  TARGET_SIGNAL_SEGV = 11,
  TARGET_SIGNAL_ALRM = 14,
  TARGET_SIGNAL_USR2 = 31,
  TARGET_SIGNAL_PWR  = 32
};


enum mp_type {
  BP_MEMORY   = 0,
  BP_HARDWARE = 1,
  WP_WRITE  = 2,
  WP_READ   = 3,
  WP_ACCESS   = 4
};


enum GdbStatus {
  GDB_NORMAL  = 0,
  GDB_ILLEGAL = 1,
  GDB_KILL  = 2
};


typedef struct {
  enum mp_type type;
  Addr_t     addr;
  Word_t     instr;
} mp_entry;


class GdbServer {
private:
  int32_t   m_client_waiting;
  int32_t   m_proto_num;
  int32_t   m_client_fd;
  int32_t   m_sigval;
  mp_entry *m_mp_hash[MP_HASH_SIZE];
public:
  GdbServer ();

  int32_t GetClientWait (void) { return m_client_waiting; }
  int32_t GetProtoNum (void)   { return m_proto_num; }
  int32_t GetClientFd (void)   { return m_client_fd; }
  int32_t GetSigVal (void)   { return m_sigval; }

  void SetClientWait (int32_t client_waiting) { m_client_waiting = client_waiting; }
  void SetProtoNum   (int32_t proto_num)    { m_proto_num    = proto_num; }
  void SetClientFd   (int32_t client_fd)    { m_client_fd    = client_fd; }
  void SetSigVal   (int32_t sigval)     { m_sigval     = sigval; }
};


class GdbEnv {
private:
  EnvBase   *m_pe_thread;
  std::unique_ptr<GdbServer> m_gdb_server;

  bool IsEqualHead (const std::string str1, const std::string str2);
  template <class T> T ReverseByte (T data);

  uint32_t m_serial_port;
  /*! String to map hex digits to chars */
  const std::string hexchars = "0123456789abcdef";
public:
  GdbEnv (EnvBase *env, int port);

  void HandleGdb ();
  void GetClientPort ();

  GdbStatus HandleClientRequest ();
  void DumpGeneralRegisters (void);

  void SendPacketString (const std::string str);


  void PutPacket (std::string buf);
  std::string GetPacket ();

  void PutRSPChar (char c);
  int  GetRSPChar ();

  void CloseRSPClient (void);

  int Hex (int c) {
    return ((c >= 'a') && (c <= 'f')) ? c - 'a' + 10 :
         ((c >= '0') && (c <= '9')) ? c - '0' :
         ((c >= 'A') && (c <= 'F')) ? c - 'A' + 10 : -1;

  }
};
