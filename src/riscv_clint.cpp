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

#include "riscv_clint.hpp"

RiscvClint_t::RiscvClint_t(RiscvPeThread *pe_thread, Addr_t base_addr, Addr_t size)
    : RiscvMMDevice_t (pe_thread, base_addr, size)
{
  for (int core = 0; core < NumCores; core++) {
    m_mtimecmp[core] = 0;
  }
  m_mtime = 0;
}


/* 0000 msip hart 0
 * 0004 msip hart 1
 * 4000 mtimecmp hart 0 lo
 * 4004 mtimecmp hart 0 hi
 * 4008 mtimecmp hart 1 lo
 * 400c mtimecmp hart 1 hi
 * bff8 mtime lo
 * bffc mtime hi
 */

MemResult RiscvClint_t::Load (Addr_t addr, size_t len, Byte_t *data)
{
  // m_pe_thread->InfoPrint ("<Info: RiscvClint Load Addr = %016lx, Size = %d>\n", addr, word_size);
  if (addr >= MSIP_BASE && addr + len <= MSIP_BASE + NumCores *sizeof(UWord_t)) {

    std::vector<UWord_t> msip(NumCores);
    for (size_t i = 0; i < NumCores ; ++i) {
      UDWord_t mip;
      m_pe_thread->CSRReadNoTrace (SYSREG_ADDR_MIP, &mip, PrivMode::PrivMachine);
      msip[i] = ExtractBitField (mip, SYSREG_MIP_MSIP_MSB, SYSREG_MIP_MSIP_LSB);
    }

    memcpy(data, (Byte_t*)&msip[0] + addr - MSIP_BASE, len);
  } else if (addr >= MTIMECMP_BASE && addr + len <= MTIMECMP_BASE + NumCores *sizeof(UDWord_t)) {
    memcpy(data, (Byte_t*)&m_mtimecmp[0] + addr - MTIMECMP_BASE, len);
  } else if (addr >= MTIME_BASE && addr + len <= MTIME_BASE + sizeof(UDWord_t)) {
    memcpy(data, (Byte_t*)&m_mtime + addr - MTIME_BASE, len);
  } else {
    return MemResult::MemNotDefined;
  }
  return MemResult::MemNoExcept;
}

MemResult RiscvClint_t::Store (Addr_t addr, size_t len, Byte_t *data)
{
  if (addr >= MSIP_BASE && addr + len <= MSIP_BASE + NumCores *sizeof(UWord_t)) {
    std::vector<UWord_t> msip(NumCores);
    std::vector<UWord_t> mask(NumCores, 0);
    memcpy((Byte_t*)&msip[0] + addr - MSIP_BASE, data, len);
    memset((Byte_t*)&mask[0] + addr - MSIP_BASE, 0xff, len);
    for (size_t i = 0; i < NumCores ; ++i) {
      if (!(mask[i] & 0xFF)) continue;

      UDWord_t mip;
      m_pe_thread->CSRReadNoTrace (SYSREG_ADDR_MIP, &mip, PrivMode::PrivMachine);

      if (msip[i] & 1) {
        mip = SetBitField (mip, 1, SYSREG_MIP_MSIP_MSB, SYSREG_MIP_MSIP_LSB);
      } else {
        mip = SetBitField (mip, 0, SYSREG_MIP_MSIP_MSB, SYSREG_MIP_MSIP_LSB);
      }

      m_pe_thread->CSRWrite (SYSREG_ADDR_MIP, mip, PrivMode::PrivMachine);
    }
  } else if (addr >= MTIMECMP_BASE && addr + len <= MTIMECMP_BASE + NumCores *sizeof(UDWord_t)) {
    memcpy((Byte_t*)&m_mtimecmp[0] + addr - MTIMECMP_BASE, data, len);
  } else if (addr >= MTIME_BASE && addr + len <= MTIME_BASE + sizeof(UDWord_t)) {
    memcpy((Byte_t*)&m_mtime + addr - MTIME_BASE, data, len);
  } else {
    return MemResult::MemNotDefined;
  }
  Increment(0);
  return MemResult::MemNoExcept;
}


void RiscvClint_t::Increment(UDWord_t inc)
{
  m_mtime += inc;
  m_pe_thread->DebugPrint("<Info: %d increment mtime = %016lx, mtimecmp = %016lx>\n",
                          m_pe_thread->GetStep(),
                          m_mtime, m_mtimecmp[0]);

  for (size_t i = 0; i < NumCores ; i++) {

    UDWord_t mip;
    m_pe_thread->CSRReadNoTrace (SYSREG_ADDR_MIP, &mip, PrivMode::PrivMachine);

    mip = SetBitField (mip, 0, SYSREG_MIP_MTIP_MSB, SYSREG_MIP_MTIP_LSB);
    if (m_mtime >= m_mtimecmp[i]) {
      m_pe_thread->DebugPrint("<Info: set MIP>\n");
      mip = SetBitField (mip, 1, SYSREG_MIP_MTIP_MSB, SYSREG_MIP_MTIP_LSB);
    }

    m_pe_thread->CSRWrite (SYSREG_ADDR_MIP, mip, PrivMode::PrivMachine);
  }
}
