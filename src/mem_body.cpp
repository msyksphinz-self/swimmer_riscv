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
#include <sstream>
#include <iomanip>
#include <unordered_map>
#include <algorithm>
#include <memory>
#include <stdio.h>
#include <inttypes.h>

#include "mem_body.hpp"


MemResult operator|(MemResult L, MemResult R) {
  return static_cast<MemResult>(static_cast<uint64_t>(L) | static_cast<uint64_t>(R));
}

MemResult operator&(MemResult L, MemResult R) {
  return static_cast<MemResult>(static_cast<uint64_t>(L) & static_cast<uint64_t>(R));
}

/*!
 * Reference from Memory
 * \param addr address
 * \param env RISCV environment
 */
template <typename AccType>
MemResult Memory::LoadMemory (Addr_t addr, Byte_t *data)
{
  const size_t AccSize = sizeof(AccType);

  Addr_t phy_addr = addr;

  MemResult result = SearchMemTable (phy_addr, AccSize, data);

  if (AccSize == 1) {
    return result;
  } else if ((addr & (AccSize-1)) == 0) {
    return result;
  } else {
    return result | MemResult::MemMisAlign;
  }
}


template <typename AccType>
MemResult Memory::StoreMemory (Addr_t addr, Byte_t *data)
{
  const size_t AccSize     = sizeof(AccType);
  const size_t AccSizeLog  = std::log2(AccSize);
  const size_t AccSizeMask = (0x01 << AccSizeLog)-1;

  Addr_t phy_addr = addr;

  if (AccSize == 1) {
    InsertMemTable (phy_addr, AccSize, data);
    return MemResult::MemNoExcept;
  } else if ((phy_addr & AccSizeMask) == 0) {
    InsertMemTable (phy_addr, AccSize, data);
    return MemResult::MemNoExcept;
  } else {
    return MemResult::MemMisAlign;
  }
}


MemResult Memory::SearchMemTable (Addr_t addr, size_t acc_size, Byte_t *data)
{
  std::unordered_map<Addr_t, std::shared_ptr<MemoryBlock>>::iterator it;
  Addr_t baseaddr = addr & BaseMask;

  if ((it = m_memory_vec.find (baseaddr)) != m_memory_vec.end()) {
    it->second->ReadBytePtr (addr - baseaddr, acc_size, data);
    // for (size_t idx = 0; idx < acc_size; idx++) {
    //   data[idx] = it->second->ReadByte (addr - baseaddr + idx);
    // }
    return MemResult::MemNoExcept;
  } else {
    // *data = 0xa5;
    *data = 0x00;
    return MemResult::MemNotDefined;
  }

}


MemResult Memory::SearchMemTable (Addr_t addr, Byte_t *data)
{
  std::unordered_map<Addr_t, std::shared_ptr<MemoryBlock>>::iterator it;
  Addr_t baseaddr = addr & BaseMask;

  if ((it = m_memory_vec.find (baseaddr)) != m_memory_vec.end()) {
    *data = it->second->ReadByte (static_cast<Addr_t>(addr - baseaddr));
    return MemResult::MemNoExcept;
  } else {
    // *data = 0xa5;
    *data = 0x00;
    return MemResult::MemNotDefined;
  }
}


MemResult Memory::InsertMemTable (Addr_t addr, Word_t data)
{
  // at first, traverse memory table and check memory region is already registered or not

  std::unordered_map<Addr_t, std::shared_ptr<MemoryBlock>>::iterator it;
  Addr_t baseaddr = addr & BaseMask;

  if ((it = m_memory_vec.find (baseaddr)) != m_memory_vec.end()) {
    it->second->WriteByte (addr - baseaddr, static_cast<Byte_t>(data));
    return MemResult::MemNoExcept;
  }

  std::shared_ptr<MemoryBlock> memory_block (new MemoryBlock (baseaddr, (~BaseMask)+1, 0x7));

  memory_block->WriteByte (addr - baseaddr, static_cast<Byte_t>(data));
  m_memory_vec.insert (std::make_pair(baseaddr, memory_block));

  return MemResult::MemNewRegion;
}


MemResult Memory::InsertMemTable (Addr_t addr, size_t acc_size, Byte_t *data)
{
  // at first, traverse memory table and check memory region is already registered or not

  std::unordered_map<Addr_t, std::shared_ptr<MemoryBlock>>::iterator it;
  Addr_t baseaddr = addr & BaseMask;

  if ((it = m_memory_vec.find (baseaddr)) != m_memory_vec.end()) {
    it->second->WriteBytePtr (addr - baseaddr, acc_size, data);
    // for (size_t idx = 0; idx < acc_size; idx++) {
    //   it->second->WriteByte (addr - baseaddr + idx, data[idx]);
    // }
    return MemResult::MemNoExcept;
  }

  std::shared_ptr<MemoryBlock> memory_block (new MemoryBlock (baseaddr, (~BaseMask)+1, 0x7));

  memory_block->WriteBytePtr (addr - baseaddr, acc_size, data);
  // for (size_t idx = 0; idx < acc_size; idx++) {
  //   memory_block->WriteByte (addr - baseaddr + idx, data[idx]);
  // }
  m_memory_vec.insert (std::make_pair(baseaddr, memory_block));

  return MemResult::MemNewRegion;
}


void Memory::DumpMemory (FILE *fp)
{
  for (auto it = m_memory_vec.begin(); it != m_memory_vec.end(); it++) {
    Addr_t base_addr = it->second->GetBaseAddr ();
    for (Addr_t addr = 0; addr < it->second->GetBlockSize(); addr+=64) {
      std::stringstream str;
      str << std::setw(10) << std::hex << std::setfill('0') << (addr + base_addr);
      fprintf (fp, "%s", str.str().c_str());
      for (int byte_addr = 64-1; byte_addr >= 0; byte_addr--) {
      // for (Addr_t byte_addr = 0; byte_addr < 16; byte_addr++) {
        UByte_t data = it->second->ReadByte (static_cast<Addr_t>(addr + byte_addr));
        fprintf (fp, "%02x", data);
      }
      fprintf (fp, "\n");
    }
  }
}

void Memory::GenCleanMemoryFile (FILE *fp)
{
  fprintf (fp, "#DATA\n#ORG 00000000\n");
  for (auto it = m_memory_vec.begin(); it != m_memory_vec.end(); it++) {
    Addr_t base_addr = it->second->GetBaseAddr ();
    for (Addr_t addr = 0; addr < it->second->GetBlockSize(); addr+=4) {
      fprintf (fp, "@%08lx 00000000\n", addr + base_addr);
    }
  }
}



template MemResult Memory::LoadMemory<UByte_t>  (Addr_t addr, Byte_t *data);
template MemResult Memory::LoadMemory<Byte_t>   (Addr_t addr, Byte_t *data);
template MemResult Memory::LoadMemory<HWord_t>  (Addr_t addr, Byte_t *data);
template MemResult Memory::LoadMemory<UHWord_t> (Addr_t addr, Byte_t *data);
template MemResult Memory::LoadMemory<Word_t>   (Addr_t addr, Byte_t *data);
template MemResult Memory::LoadMemory<UWord_t>  (Addr_t addr, Byte_t *data);
template MemResult Memory::LoadMemory<DWord_t>  (Addr_t addr, Byte_t *data);
template MemResult Memory::LoadMemory<UDWord_t> (Addr_t addr, Byte_t *data);

template MemResult Memory::StoreMemory<Byte_t>  (Addr_t addr, Byte_t *data);
template MemResult Memory::StoreMemory<UByte_t> (Addr_t addr, Byte_t *data);
template MemResult Memory::StoreMemory<HWord_t> (Addr_t addr, Byte_t *data);
template MemResult Memory::StoreMemory<UHWord_t>(Addr_t addr, Byte_t *data);
template MemResult Memory::StoreMemory<Word_t>  (Addr_t addr, Byte_t *data);
template MemResult Memory::StoreMemory<UWord_t> (Addr_t addr, Byte_t *data);
template MemResult Memory::StoreMemory<DWord_t> (Addr_t addr, Byte_t *data);
template MemResult Memory::StoreMemory<UDWord_t>(Addr_t addr, Byte_t *data);
