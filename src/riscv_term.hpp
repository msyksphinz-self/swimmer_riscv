/*
 * Copyright (c) 2015, msyksphinz
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

#include <termios.h>
#include <unistd.h>
#include <poll.h>
#include <signal.h>
#include <stdlib.h>

class RiscvTerm_t : public RiscvDevice_t
{
 public:
  RiscvTerm_t(uint32_t dev_id, RiscvPeThread *pe_thread)
      : RiscvDevice_t(dev_id, pe_thread), restore_tios(false)
  {
    // if (tcgetattr(0, &old_tios) == 0)
    // {
    //   struct termios new_tios = old_tios;
    //   // new_tios.c_lflag &= ~(ICANON | ECHO);
    //   new_tios.c_lflag &= ~(ICANON);
    //   if (tcsetattr(0, TCSANOW, &new_tios) == 0)
    //     restore_tios = true;
    // }
  }

  ~RiscvTerm_t()
  {
    // fflush (stdout);
    // if (restore_tios)
    //   tcsetattr(0, TCSANOW, &old_tios);
  }

  void HandleCommand (UDWord_t cmd) {
    if (COMMAND(cmd) == 0) {
      m_req_count ++;
      // StdInRead ();
    } else {
      write (PAYLOAD(cmd));
    }
  }

  void Tick ();

 private:
  int read();
  void write(char ch);

  void StdInRead () {
    int read_data;
    // DWord_t fromhost;
    // GetPeThread()->LoadFrom_FromHost (&fromhost);
    // if (fromhost == 0) {
    if ((m_req_count > 0) &&
        ((read_data = read()) != -1)) {
      read_data = 0x100 | read_data;

      uint64_t resp_data = static_cast<uint64_t>(GetDevId()) << 56 | read_data;
      GetPeThread()->StoreTo_FromHost (resp_data);
      GetPeThread()->DebugPrint("<Info: Tick read enable() = %x, resp_data = %016lx>\n", read_data, resp_data);
      m_req_count--;
      //}
    }
  }

  int32_t m_req_count = 0;
  struct termios old_tios;
  bool restore_tios;
};


int RiscvTerm_t::read()
{
  struct pollfd pfd;
  pfd.fd = 0;
  pfd.events = POLLIN;
  int ret = poll(&pfd, 1, 0);
  if (ret <= 0 || !(pfd.revents & POLLIN))
    return -1;

  unsigned char ch;
  ret = ::read(0, &ch, 1);
  return ret <= 0 ? -1 : ch;
}

void RiscvTerm_t::write(char ch)
{
  if (::write(1, &ch, 1) != 1)
    abort();
}


void RiscvTerm_t::Tick()
{
  StdInRead ();
}
