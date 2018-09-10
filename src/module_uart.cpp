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

#include "./module_uart.hpp"
#include "./env.hpp"


MemResult ModuleUart::LoadData (Addr_t addr, Size_t size, Word_t *data)
{
  m_env->DebugPrint ("<UART: Load (%08x)\n", addr);
  if ((addr & 0x0fff) == 0x000003fd) { //
    *data = 0x00000020;
  } else {
    *data = 0x00000000;
  }
  m_env->GetTrace()->RecordTrace (TraceType::MemWrite, addr, *data);

  return MemResult::MemNoExcept;
}


MemResult ModuleUart::StoreData (Addr_t addr, Size_t size, Word_t data)
{
  m_env->DebugPrint ("<UART: Store (%08x)<=%02x> %c\n", static_cast<uint32_t>(addr), data, static_cast<char>(data & 0x00FFU));
  if ((addr & 0x0fff) == 0x000003f8) {
    fprintf (m_uart_fp, "%c", static_cast<char>(data & 0x00FFU));
  }
  m_env->GetTrace()->RecordTrace (TraceType::MemWrite, addr, data);

  return MemResult::MemNoExcept;
}


ModuleUart::ModuleUart (EnvBase *env, FILE *uart_fp)
{
  m_env = env;
  m_uart_fp = uart_fp;
}
