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

#include <unordered_map>
#include <iostream>
#include <memory>

#include "memory_block.hpp"

enum class MemResult {
  MemNoExcept   = 0,
  MemMisAlign   = 1 << 0,
  MemNotDefined = 1 << 1,
  MemNewRegion  = 1 << 2,
  MemTlbError   = 1 << 3
};


class MemoryBlock;

class Memory
{
 private:
  std::unordered_map <Addr_t, std::shared_ptr<MemoryBlock>> m_memory_vec;  // memory table
  static const Addr_t BaseMask = static_cast<Addr_t>(~0x00000FFFULL);

 protected:

  MemResult SearchMemTable (Addr_t addr, Byte_t *data);
  MemResult SearchMemTable (Addr_t addr, size_t acc_size, Byte_t *data);
  MemResult InsertMemTable (Addr_t addr, Word_t data);
  MemResult InsertMemTable (Addr_t addr, size_t acc_size, Byte_t *data);

 public:

  static Addr_t GetBaseMask () { return BaseMask; }

  template <typename AccType> MemResult LoadMemory (Addr_t addr, Byte_t *data);
  template <typename AccType> MemResult StoreMemory (Addr_t addr, Byte_t *data);
  void DumpMemory (FILE *fp);
  void GenCleanMemoryFile (FILE *fp);

};
