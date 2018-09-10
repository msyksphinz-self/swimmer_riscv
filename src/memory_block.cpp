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

#include "memory_block.hpp"
#include <string.h>
#include <memory>
#include <cassert>

MemoryBlock::MemoryBlock (Addr_t baseaddr, Addr_t blocksize, uint8_t permission)
{
  m_baseaddr   = baseaddr;
  m_blocksize  = blocksize;
  m_permission = permission;
  m_memory = std::unique_ptr<Byte_t[]> (new Byte_t[blocksize * sizeof(Byte_t)]);
  // memset (m_memory.get(), 0xa5, blocksize * sizeof(Byte_t));
  memset (m_memory.get(), 0x00, blocksize * sizeof(Byte_t));
}


Byte_t MemoryBlock::ReadByte (Addr_t addr)
{
  assert(addr < m_blocksize);
  return m_memory[addr];
}

void MemoryBlock::ReadBytePtr (Addr_t addr, size_t acc_size, Byte_t *data)
{
  assert(addr < m_blocksize);
  Byte_t *ret_ptr;
  memcpy (data, &m_memory[addr], acc_size);
}


void MemoryBlock::WriteByte (Addr_t addr, Byte_t data)
{
  assert(addr < m_blocksize);
  m_memory[addr] = data;
  return;
}


void MemoryBlock::WriteBytePtr (Addr_t addr, size_t acc_size, Byte_t *data)
{
  assert(addr < m_blocksize);
  memcpy (&m_memory[addr], data, acc_size);
  return;
}
