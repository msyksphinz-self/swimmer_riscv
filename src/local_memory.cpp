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

#include <cmath>
#include "local_memory.hpp"

template <typename AccType>
MemResult LocalMemory::LoadMemory (Addr_t addr, Byte_t *data)
{
  const size_t AccSize     = sizeof(AccType);
  const size_t AccSizeLog  = std::log2(AccSize);
  const size_t AccSizeMask = (0x01 << AccSizeLog)-1;

  Addr_t phy_addr = addr & ~AccSizeMask;

  for (size_t i = 0; i < AccSize; i++) {
    SearchMemTable (phy_addr+i, (data+i));
  }

  if (AccSize == 1) {
    return MemResult::MemNoExcept;
  } else if ((phy_addr & AccSizeMask) == 0) {
    return MemResult::MemNoExcept;
  } else {
    return MemResult::MemMisAlign;
  }
}


template <typename AccType>
MemResult LocalMemory::StoreMemory (Addr_t addr, Byte_t *data)
{
  const size_t AccSize     = sizeof(AccType);
  const size_t AccSizeLog  = std::log2(AccSize);
  const size_t AccSizeMask = (0x01 << AccSizeLog)-1;

  Addr_t phy_addr = addr & ~AccSizeMask;

  if (AccSize == 1) {
    InsertMemTable (phy_addr, *data);
    return MemResult::MemNoExcept;
  } else if ((phy_addr & AccSizeMask) == 0) {
    for (size_t i = 0; i < AccSize; i++) {
      InsertMemTable (phy_addr+i, *(data+i));
    }
    return MemResult::MemNoExcept;
  } else {
    return MemResult::MemMisAlign;
  }
}


LocalMemory::LocalMemory()
{
}


template MemResult LocalMemory::LoadMemory<UByte_t>  (Addr_t addr, Byte_t *data);
template MemResult LocalMemory::LoadMemory<Byte_t>   (Addr_t addr, Byte_t *data);
template MemResult LocalMemory::LoadMemory<HWord_t>  (Addr_t addr, Byte_t *data);
template MemResult LocalMemory::LoadMemory<UHWord_t> (Addr_t addr, Byte_t *data);
template MemResult LocalMemory::LoadMemory<Word_t>   (Addr_t addr, Byte_t *data);
template MemResult LocalMemory::LoadMemory<UWord_t>  (Addr_t addr, Byte_t *data);
template MemResult LocalMemory::LoadMemory<DWord_t>  (Addr_t addr, Byte_t *data);
template MemResult LocalMemory::LoadMemory<UDWord_t> (Addr_t addr, Byte_t *data);

template MemResult LocalMemory::StoreMemory<Byte_t>  (Addr_t addr, Byte_t *data);
template MemResult LocalMemory::StoreMemory<UByte_t> (Addr_t addr, Byte_t *data);
template MemResult LocalMemory::StoreMemory<HWord_t> (Addr_t addr, Byte_t *data);
template MemResult LocalMemory::StoreMemory<UHWord_t>(Addr_t addr, Byte_t *data);
template MemResult LocalMemory::StoreMemory<Word_t>  (Addr_t addr, Byte_t *data);
template MemResult LocalMemory::StoreMemory<UWord_t> (Addr_t addr, Byte_t *data);
template MemResult LocalMemory::StoreMemory<DWord_t> (Addr_t addr, Byte_t *data);
template MemResult LocalMemory::StoreMemory<UDWord_t>(Addr_t addr, Byte_t *data);
