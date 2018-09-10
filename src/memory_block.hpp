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

#include <memory>
#include <stdint.h>
#include "./basic.hpp"

enum MemoryMode {exec_bit  = 0,
         write_bit = 1,
         read_bit  = 2};

class MemoryBlock {

 private:

  MemoryMode m_mode;

  Addr_t   m_baseaddr;
  Addr_t   m_blocksize;
  uint8_t  m_permission;

  std::unique_ptr<Byte_t[]> m_memory;

 public:

  MemoryBlock (Addr_t baseaddr, Addr_t blocksize, uint8_t permission);

  Addr_t GetBaseAddr(void) const {
    return m_baseaddr;
  }

  Addr_t GetBlockSize (void) const {
    return m_blocksize;
  }

  uint8_t GetPermission (void) const {
    return m_permission;
  }

  Byte_t  ReadByte (Addr_t addr);
  void    WriteByte (Addr_t addr, Byte_t data);
  void ReadBytePtr  (Addr_t addr, size_t acc_size, Byte_t *data);
  void WriteBytePtr (Addr_t addr, size_t acc_size, Byte_t *data);
  class LessA {
    Addr_t m_addr;
  public:
    bool operator () (const MemoryBlock *const A) {
      // fprintf (stdout, "<operator () %08x <= %08x %08xis called.>\n",
      //      m_addr,
      //      A->GetBaseAddr(),
      //      A->GetBlockSize());
      return (A->GetBaseAddr() <= m_addr &&
          m_addr < (A->GetBaseAddr() + A->GetBlockSize()));
    }
    LessA (Addr_t addr) { m_addr = addr; }
  };
};
