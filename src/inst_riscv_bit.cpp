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

#include <stdint.h>
#include <gmpxx.h>
#include <iostream>
#include <iomanip>
#include "inst_list_riscv.hpp"
#include "dec_utils_riscv.hpp"
#include "softfloat.h"
#include "riscv_pe_thread.hpp"
#include "inst_riscv.hpp"
#include "riscv_sysreg_impl.hpp"
#include "inst_ops.hpp"
#include "riscv_sysreg_bitdef.hpp"


uint32_t shuffle32_stage(uint32_t src, uint32_t maskL, uint32_t maskR, int N)
{
  uint32_t x = src & ~(maskL | maskR);
  x |= ((src << N) & maskL) | ((src >> N) & maskR);
  return x;
}

uint32_t shfl32(uint32_t rs1, uint32_t rs2)
{
  uint32_t x = rs1;
  int shamt = rs2 & 15;
  if (shamt & 8) x = shuffle32_stage(x, 0x00ff0000, 0x0000ff00, 8);
  if (shamt & 4) x = shuffle32_stage(x, 0x0f000f00, 0x00f000f0, 4);
  if (shamt & 2) x = shuffle32_stage(x, 0x30303030, 0x0c0c0c0c, 2);
  if (shamt & 1) x = shuffle32_stage(x, 0x44444444, 0x22222222, 1);
  return x;
}


uint32_t unshfl32(uint32_t rs1, uint32_t rs2)
{
  uint32_t x = rs1;
  int shamt = rs2 & 15;
  if (shamt & 1) x = shuffle32_stage(x, 0x44444444, 0x22222222, 1);
  if (shamt & 2) x = shuffle32_stage(x, 0x30303030, 0x0c0c0c0c, 2);
  if (shamt & 4) x = shuffle32_stage(x, 0x0f000f00, 0x00f000f0, 4);
  if (shamt & 8) x = shuffle32_stage(x, 0x00ff0000, 0x0000ff00, 8);
  return x;
}


uint64_t shuffle64_stage(uint64_t src, uint64_t maskL, uint64_t maskR, int N)
{
  uint64_t x = src & ~(maskL | maskR);
  x |= ((src << N) & maskL) | ((src >> N) & maskR);
  return x;
}


uint64_t shfl64(uint64_t rs1_val, uint64_t rs2_val)
{
  uint64_t x = rs1_val;
  int shamt = rs2_val & 31;
  if (shamt & 16) x = shuffle64_stage(x, 0x0000ffff00000000LL,
                                      0x00000000ffff0000LL, 16);
  if (shamt & 8) x = shuffle64_stage(x, 0x00ff000000ff0000LL,
                                     0x0000ff000000ff00LL, 8);
  if (shamt & 4) x = shuffle64_stage(x, 0x0f000f000f000f00LL,
                                     0x00f000f000f000f0LL, 4);
  if (shamt & 2) x = shuffle64_stage(x, 0x3030303030303030LL,
                                     0x0c0c0c0c0c0c0c0cLL, 2);
  if (shamt & 1) x = shuffle64_stage(x, 0x4444444444444444LL,
                                     0x2222222222222222LL, 1);
  return x;
}


uint64_t unshfl64(uint64_t rs1_val, uint64_t rs2_val)
{
  uint64_t x = rs1_val;
  int shamt = rs2_val & 31;
  if (shamt & 1) x = shuffle64_stage(x, 0x4444444444444444LL,
                                     0x2222222222222222LL, 1);
  if (shamt & 2) x = shuffle64_stage(x, 0x3030303030303030LL,
                                     0x0c0c0c0c0c0c0c0cLL, 2);
  if (shamt & 4) x = shuffle64_stage(x, 0x0f000f000f000f00LL,
                                     0x00f000f000f000f0LL, 4);
  if (shamt & 8) x = shuffle64_stage(x, 0x00ff000000ff0000LL,
                                     0x0000ff000000ff00LL, 8);
  if (shamt & 16) x = shuffle64_stage(x, 0x0000ffff00000000LL,
                                      0x00000000ffff0000LL, 16);
  return x;
}


UDWord_t slo(UDWord_t rs1, UDWord_t rs2, int xlen)
{
  int shamt = rs2 & (xlen - 1);
  return ~(~rs1 << shamt);
}


void InstEnv::RISCV_INST_ANDN (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UDWord_t rs1_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs1_addr));
  UDWord_t rs2_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs2_addr));

  DWord_t res = rs1_val & ~rs2_val;

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_ORN (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UDWord_t rs1_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs1_addr));
  UDWord_t rs2_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs2_addr));

  DWord_t res = rs1_val | ~rs2_val;

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_XNOR (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UDWord_t rs1_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs1_addr));
  UDWord_t rs2_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs2_addr));

  DWord_t res = rs1_val ^ ~rs2_val;

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_SLO (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UDWord_t rs1_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs1_addr));
  UDWord_t rs2_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs2_addr));

  uint32_t shamt = rs2_val & (m_pe_thread->GetBitModeInt() - 1);
  DWord_t res = ~(~rs1_val << shamt);

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_SRO (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UDWord_t rs1_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs1_addr));
  UDWord_t rs2_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs2_addr));

  uint32_t shamt = rs2_val & (m_pe_thread->GetBitModeInt() - 1);
  DWord_t res = ~(~rs1_val >> shamt);

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_ROL (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UDWord_t rs1_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs1_addr));
  UDWord_t rs2_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs2_addr));

  uint32_t shamt = rs2_val & (m_pe_thread->GetBitModeInt() - 1);
  DWord_t res = (rs1_val << shamt) | (rs1_val >> ((m_pe_thread->GetBitModeInt() - shamt) & (m_pe_thread->GetBitModeInt() - 1)));

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_ROR (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UDWord_t rs1_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs1_addr));
  UDWord_t rs2_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs2_addr));

  uint32_t shamt = rs2_val & (m_pe_thread->GetBitModeInt() - 1);
  DWord_t res = (rs1_val >> shamt) | (rs1_val << ((m_pe_thread->GetBitModeInt() - shamt) & (m_pe_thread->GetBitModeInt() - 1)));

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_SH1ADD (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UDWord_t rs1_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs1_addr));
  UDWord_t rs2_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs2_addr));

  DWord_t res = (rs1_val << 1) + rs2_val;

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_SH2ADD (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UDWord_t rs1_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs1_addr));
  UDWord_t rs2_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs2_addr));

  DWord_t res = (rs1_val << 2) + rs2_val;

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_SH3ADD (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UDWord_t rs1_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs1_addr));
  UDWord_t rs2_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs2_addr));

  DWord_t res = (rs1_val << 3) + rs2_val;

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_SBCLR (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UDWord_t rs1_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs1_addr));
  UDWord_t rs2_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs2_addr));

  int shamt = rs2_val & (m_pe_thread->GetBitModeInt() - 1);
  DWord_t res = rs1_val | (UDWord_t(1) << shamt);

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_SBSET (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UDWord_t rs1_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs1_addr));
  UDWord_t rs2_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs2_addr));

  int shamt = rs2_val & (m_pe_thread->GetBitModeInt() - 1);
  DWord_t res = rs1_val & ~(UDWord_t(1) << shamt);

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_SBINV (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UDWord_t rs1_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs1_addr));
  UDWord_t rs2_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs2_addr));

  int shamt = rs2_val & (m_pe_thread->GetBitModeInt() - 1);
  DWord_t res = rs1_val ^ (UDWord_t(1) << shamt);

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_SBEXT (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UDWord_t rs1_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs1_addr));
  UDWord_t rs2_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs2_addr));

  int shamt = rs2_val & (m_pe_thread->GetBitModeInt() - 1);
  DWord_t res = 1 & (rs1_val >> shamt);

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_GORC (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UDWord_t rs1_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs1_addr));
  UDWord_t rs2_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs2_addr));

  DWord_t res = 0;

  if (m_pe_thread->GetBitMode() == RiscvBitMode_t::Bit32) {
    uint32_t x = rs1_val;
    int shamt = rs2_val & 31;
    if (shamt & 1) x |= ((x & 0x55555555) << 1) | ((x & 0xAAAAAAAA) >> 1);
    if (shamt & 2) x |= ((x & 0x33333333) << 2) | ((x & 0xCCCCCCCC) >> 2);
    if (shamt & 4) x |= ((x & 0x0F0F0F0F) << 4) | ((x & 0xF0F0F0F0) >> 4);
    if (shamt & 8) x |= ((x & 0x00FF00FF) << 8) | ((x & 0xFF00FF00) >> 8);
    if (shamt & 16) x |= ((x & 0x0000FFFF) << 16) | ((x & 0xFFFF0000) >> 16);

    res = 1 & (rs1_val >> shamt);
  } else if (m_pe_thread->GetBitMode() == RiscvBitMode_t::Bit64) {
    uint64_t x = rs1_val;
    int shamt = rs2_val & 63;
    if (shamt & 1) x |= ((x & 0x5555555555555555LL) << 1) |
                        ((x & 0xAAAAAAAAAAAAAAAALL) >> 1);
    if (shamt & 2) x |= ((x & 0x3333333333333333LL) << 2) |
                        ((x & 0xCCCCCCCCCCCCCCCCLL) >> 2);
    if (shamt & 4) x |= ((x & 0x0F0F0F0F0F0F0F0FLL) << 4) |
                        ((x & 0xF0F0F0F0F0F0F0F0LL) >> 4);
    if (shamt & 8) x |= ((x & 0x00FF00FF00FF00FFLL) << 8) |
                        ((x & 0xFF00FF00FF00FF00LL) >> 8);
    if (shamt & 16) x |= ((x & 0x0000FFFF0000FFFFLL) << 16) |
                         ((x & 0xFFFF0000FFFF0000LL) >> 16);
    if (shamt & 32) x |= ((x & 0x00000000FFFFFFFFLL) << 32) |
                         ((x & 0xFFFFFFFF00000000LL) >> 32);

    res = 1 & (rs1_val >> shamt);
  }

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_GREV (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UDWord_t rs1_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs1_addr));
  UDWord_t rs2_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs2_addr));

  UDWord_t res = 0;
  for (int i = 0; i < m_pe_thread->GetBitModeInt(); i++) {
    int j = (i ^ rs2_val) & (m_pe_thread->GetBitModeInt()-1);
    res |= ((rs1_val >> i) & 1) << j;
  }

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_SLOI (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UDWord_t rs1_val = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs1_addr));
  DWord_t imm     = ExtractBitField (inst_hex, 26, 20);

  uint32_t shamt = imm & (m_pe_thread->GetBitModeInt() - 1);
  DWord_t res = ~(~rs1_val << shamt);

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_SROI (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UDWord_t rs1_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs1_addr));
  UDWord_t imm      = ExtractBitField (inst_hex, 26, 20);

  uint32_t shamt = imm & (m_pe_thread->GetBitModeInt() - 1);
  UDWord_t res = ~(~rs1_val >> shamt);

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_RORI (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UDWord_t rs1_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs1_addr));
  DWord_t imm      = ExtractBitField (inst_hex, 26, 20);

  uint32_t shamt = imm & (m_pe_thread->GetBitModeInt() - 1);
  DWord_t res = (rs1_val >> shamt) | (rs1_val << ((m_pe_thread->GetBitModeInt() - shamt) & (m_pe_thread->GetBitModeInt() - 1)));

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_SBCLRI (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UDWord_t rs1_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs1_addr));
  DWord_t imm      = ExtractBitField (inst_hex, 26, 20);

  int shamt = imm & (m_pe_thread->GetBitModeInt() - 1);
  DWord_t res = rs1_val | (UDWord_t(1) << shamt);

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_SBSETI (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UDWord_t rs1_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs1_addr));
  DWord_t imm      = ExtractBitField (inst_hex, 26, 20);

  int shamt = imm & (m_pe_thread->GetBitModeInt() - 1);
  DWord_t res = rs1_val & ~(UDWord_t(1) << shamt);

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_SBINVI (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UDWord_t rs1_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs1_addr));
  DWord_t imm      = ExtractBitField (inst_hex, 26, 20);

  int shamt = imm & (m_pe_thread->GetBitModeInt() - 1);
  DWord_t res = rs1_val ^ (UDWord_t(1) << shamt);

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_SBEXTI (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UDWord_t rs1_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs1_addr));
  DWord_t imm      = ExtractBitField (inst_hex, 26, 20);

  int shamt = imm & (m_pe_thread->GetBitModeInt() - 1);
  DWord_t res = 1 & (rs1_val >> shamt);

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_GORCI (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UDWord_t rs1_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs1_addr));
  DWord_t imm      = ExtractBitField (inst_hex, 26, 20);

  int shamt = imm & (m_pe_thread->GetBitModeInt() - 1);

  DWord_t res = 0;
  if (m_pe_thread->GetBitMode() == RiscvBitMode_t::Bit32) {
    uint32_t x = rs1_val;
    int shamt = imm & 31;
    if (shamt & 1) x |= ((x & 0x55555555) << 1) | ((x & 0xAAAAAAAA) >> 1);
    if (shamt & 2) x |= ((x & 0x33333333) << 2) | ((x & 0xCCCCCCCC) >> 2);
    if (shamt & 4) x |= ((x & 0x0F0F0F0F) << 4) | ((x & 0xF0F0F0F0) >> 4);
    if (shamt & 8) x |= ((x & 0x00FF00FF) << 8) | ((x & 0xFF00FF00) >> 8);
    if (shamt & 16) x |= ((x & 0x0000FFFF) << 16) | ((x & 0xFFFF0000) >> 16);

    res = 1 & (rs1_val >> shamt);
  } else if (m_pe_thread->GetBitMode() == RiscvBitMode_t::Bit64) {
    uint64_t x = rs1_val;
    int shamt = imm & 63;
    if (shamt & 1) x |= ((x & 0x5555555555555555LL) << 1) |
                        ((x & 0xAAAAAAAAAAAAAAAALL) >> 1);
    if (shamt & 2) x |= ((x & 0x3333333333333333LL) << 2) |
                        ((x & 0xCCCCCCCCCCCCCCCCLL) >> 2);
    if (shamt & 4) x |= ((x & 0x0F0F0F0F0F0F0F0FLL) << 4) |
                        ((x & 0xF0F0F0F0F0F0F0F0LL) >> 4);
    if (shamt & 8) x |= ((x & 0x00FF00FF00FF00FFLL) << 8) |
                        ((x & 0xFF00FF00FF00FF00LL) >> 8);
    if (shamt & 16) x |= ((x & 0x0000FFFF0000FFFFLL) << 16) |
                         ((x & 0xFFFF0000FFFF0000LL) >> 16);
    if (shamt & 32) x |= ((x & 0x00000000FFFFFFFFLL) << 32) |
                         ((x & 0xFFFFFFFF00000000LL) >> 32);

    res = 1 & (rs1_val >> shamt);
  }

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_GREVI (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UDWord_t rs1_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs1_addr));
  DWord_t imm      = ExtractBitField (inst_hex, 26, 20);

  UDWord_t res = 0;
  for (int i = 0; i < m_pe_thread->GetBitModeInt(); i++) {
    int j = (i ^ imm) & (m_pe_thread->GetBitModeInt()-1);
    res |= ((rs1_val >> i) & 1) << j;
  }

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_CMIX (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rs3_addr = ExtractR3Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UDWord_t rs1_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs1_addr));
  UDWord_t rs2_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs2_addr));
  DWord_t rs3_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<DWord_t> (rs3_addr));

  DWord_t res = (rs1_val & rs2_val) | (rs3_val & ~rs2_val);

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_CMOV (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rs3_addr = ExtractR3Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UDWord_t rs1_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs1_addr));
  UDWord_t rs2_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs2_addr));
  DWord_t rs3_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<DWord_t> (rs3_addr));

  DWord_t res = rs2_val ? rs1_val : rs3_val;

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_FSL (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rs3_addr = ExtractR3Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UDWord_t rs1_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs1_addr));
  UDWord_t rs2_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs2_addr));
  DWord_t rs3_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<DWord_t> (rs3_addr));

  int shamt = rs2_val & (2*m_pe_thread->GetBitModeInt() - 1);
  UDWord_t A = rs1_val, B = rs3_val;
  if (shamt >= m_pe_thread->GetBitModeInt()) {
    shamt -= m_pe_thread->GetBitModeInt();
    A = rs3_val;
    B = rs1_val;
  }
  DWord_t res = shamt ? (rs1_val << shamt) | (B >> (m_pe_thread->GetBitModeInt()-shamt)) : A;

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);

}


void InstEnv::RISCV_INST_FSR (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rs3_addr = ExtractR3Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UDWord_t rs1_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs1_addr));
  UDWord_t rs2_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs2_addr));
  DWord_t rs3_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<DWord_t> (rs3_addr));

  int shamt = rs2_val & (2*m_pe_thread->GetBitModeInt() - 1);
  UDWord_t A = rs1_val, B = rs3_val;
  if (shamt >= m_pe_thread->GetBitModeInt()) {
    shamt -= m_pe_thread->GetBitModeInt();
    A = rs3_val;
    B = rs1_val;
  }
  DWord_t res = shamt ? (rs1_val >> shamt) | (B << (m_pe_thread->GetBitModeInt()-shamt)) : A;

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_FSRI (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs3_addr = ExtractR3Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UDWord_t rs1_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs1_addr));
  DWord_t rs3_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<DWord_t> (rs3_addr));
  DWord_t imm     = ExtractBitField (inst_hex, 26, 20);

  int shamt = imm & (2*m_pe_thread->GetBitModeInt() - 1);
  UDWord_t A = rs1_val, B = rs3_val;
  if (shamt >= m_pe_thread->GetBitModeInt()) {
    shamt -= m_pe_thread->GetBitModeInt();
    A = rs3_val;
    B = rs1_val;
  }
  DWord_t res = shamt ? (rs1_val >> shamt) | (B << (m_pe_thread->GetBitModeInt()-shamt)) : A;

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_CLZ (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UDWord_t rs1_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs1_addr));

  DWord_t res = m_pe_thread->GetBitModeInt();
  for (int count = 0; count < m_pe_thread->GetBitModeInt(); count++) {
    if ((rs1_val << count) >> (m_pe_thread->GetBitModeInt() - 1)) {
      res = count;
      break;
    }
  }

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_CTZ (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UDWord_t rs1_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs1_addr));

  DWord_t res = m_pe_thread->GetBitModeInt();
  for (int count = 0; count < m_pe_thread->GetBitModeInt(); count++) {
    if ((rs1_val >> count) & 1) {
      res = count;
      break;
    }
  }

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_PCNT (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UDWord_t rs1_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs1_addr));
  UDWord_t rs2_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs2_addr));

  int count = 0;
  for (int index = 0; index < m_pe_thread->GetBitModeInt(); index++)
    count += (rs1_val >> index) & 1;
  DWord_t res = count;

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}

void InstEnv::RISCV_INST_BMATFLIP (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UDWord_t rs1_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs1_addr));
  UDWord_t rs2_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs2_addr));

  uint64_t x = rs1_val;
  x = shfl64(x, 31);
  x = shfl64(x, 31);
  x = shfl64(x, 31);
  DWord_t res = x;

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_SEXT_B (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UDWord_t rs1_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs1_addr));

  DWord_t res = DWord_t(rs1_val << (m_pe_thread->GetBitModeInt()-8)) >> (m_pe_thread->GetBitModeInt()-8);

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_SEXT_H (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UDWord_t rs1_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs1_addr));

  DWord_t res = DWord_t(rs1_val << (m_pe_thread->GetBitModeInt()-16)) >> (m_pe_thread->GetBitModeInt()-16);

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}

void InstEnv::RISCV_INST_CRC32_B (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  DWord_t rs1_val  = m_pe_thread->ReadGReg<DWord_t> (rs1_addr);

  DWord_t res = m_pe_thread->crc32(rs1_val, 8);

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_CRC32_H (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  DWord_t rs1_val  = m_pe_thread->ReadGReg<DWord_t> (rs1_addr);

  DWord_t res = m_pe_thread->crc32(rs1_val, 16);

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_CRC32_W (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  DWord_t rs1_val  = m_pe_thread->ReadGReg<DWord_t> (rs1_addr);

  Word_t res_32 = m_pe_thread->crc32(rs1_val, 32);
  UDWord_t res = ExtendSign(res_32, 31);

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_CRC32_D (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  DWord_t rs1_val  = m_pe_thread->ReadGReg<DWord_t> (rs1_addr);

  DWord_t res = m_pe_thread->crc32(rs1_val, 64);

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_CRC32C_B (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  DWord_t rs1_val  = m_pe_thread->ReadGReg<DWord_t> (rs1_addr);

  DWord_t res = m_pe_thread->crc32_c(rs1_val, 8);

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_CRC32C_H (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  DWord_t rs1_val  = m_pe_thread->ReadGReg<DWord_t> (rs1_addr);

  DWord_t res = m_pe_thread->crc32_c(rs1_val, 16);

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_CRC32C_W (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  DWord_t rs1_val  = m_pe_thread->ReadGReg<DWord_t> (rs1_addr);

  DWord_t res = m_pe_thread->crc32_c(rs1_val, 32);

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_CRC32C_D (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UDWord_t rs1_val = m_pe_thread->ReadGReg<UDWord_t> (rs1_addr);
  UDWord_t res     = m_pe_thread->crc32_c(rs1_val, 64);

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_CLMUL (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UDWord_t rs1_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs1_addr));
  UDWord_t rs2_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs2_addr));

  UDWord_t res = 0;
  for (int i = 0; i < m_pe_thread->GetBitModeInt(); i++)
    if ((rs2_val >> i) & 1)
      res ^= rs1_val << i;

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_CLMULR (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UDWord_t rs1_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs1_addr));
  UDWord_t rs2_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs2_addr));

  UDWord_t res = 0;
  for (int i = 0; i < m_pe_thread->GetBitModeInt(); i++)
    if ((rs2_val >> i) & 1)
      res ^= rs1_val >> (m_pe_thread->GetBitModeInt()-i-1);

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_CLMULH (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UDWord_t rs1_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs1_addr));
  UDWord_t rs2_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs2_addr));

  UDWord_t res = 0;
  for (int i = 1; i < m_pe_thread->GetBitModeInt(); i++)
    if ((rs2_val >> i) & 1)
      res ^= rs1_val >> (m_pe_thread->GetBitModeInt()-i);

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_MIN (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UDWord_t rs1_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs1_addr));
  UDWord_t rs2_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs2_addr));

  DWord_t res = (DWord_t)rs1_val < (DWord_t)rs2_val ? rs1_val : rs2_val;

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_MAX (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UDWord_t rs1_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs1_addr));
  UDWord_t rs2_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs2_addr));

  DWord_t res = (DWord_t)rs1_val > (DWord_t)rs2_val ? rs1_val : rs2_val;

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_MINU (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UDWord_t rs1_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs1_addr));
  UDWord_t rs2_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs2_addr));

  UDWord_t res = (UDWord_t)rs1_val < (UDWord_t)rs2_val ? rs1_val : rs2_val;

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_MAXU (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UDWord_t rs1_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs1_addr));
  UDWord_t rs2_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs2_addr));

  UDWord_t res = (UDWord_t)rs1_val > (UDWord_t)rs2_val ? rs1_val : rs2_val;

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_SHFL (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UDWord_t rs1_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs1_addr));
  UDWord_t rs2_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs2_addr));

  if (m_pe_thread->GetBitMode() == RiscvBitMode_t::Bit32) {
    UDWord_t res = shfl32(rs1_val, rs2_val);
    m_pe_thread->WriteGReg<Word_t> (rd_addr, res);
  } else {
    UDWord_t res = shfl64(rs1_val, rs2_val);
    m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
  }
}


void InstEnv::RISCV_INST_UNSHFL (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UDWord_t rs1_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs1_addr));
  UDWord_t rs2_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs2_addr));

  if (m_pe_thread->GetBitMode() == RiscvBitMode_t::Bit32) {
    UDWord_t res = unshfl32(rs1_val, rs2_val);
    m_pe_thread->WriteGReg<Word_t> (rd_addr, res);
  } else {
    UDWord_t res = unshfl64(rs1_val, rs2_val);
    m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
  }
}


void InstEnv::RISCV_INST_BDEP (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UDWord_t rs1_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs1_addr));
  UDWord_t rs2_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs2_addr));

  UDWord_t res = 0;
  for (int i = 0, j = 0; i < m_pe_thread->GetBitModeInt(); i++)
    if ((rs2_val >> i) & 1) {
      if ((rs1_val >> j) & 1)
        res |= UDWord_t(1) << i;
      j++;
    }

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_BEXT (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UDWord_t rs1_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs1_addr));
  UDWord_t rs2_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs2_addr));

  UDWord_t res = 0;
  for (int i = 0, j = 0; i < m_pe_thread->GetBitModeInt(); i++)
    if ((rs2_val >> i) & 1) {
      if ((rs1_val >> i) & 1)
        res |= UDWord_t(1) << j;
      j++;
    }

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_PACK (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UDWord_t rs1_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs1_addr));
  UDWord_t rs2_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs2_addr));


  UDWord_t lower = (rs1_val << m_pe_thread->GetBitModeInt()/2) >> m_pe_thread->GetBitModeInt()/2;
  UDWord_t upper = rs2_val << m_pe_thread->GetBitModeInt()/2;
  UDWord_t res = lower | upper;

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_PACKU (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UDWord_t rs1_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs1_addr));
  UDWord_t rs2_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs2_addr));

  UDWord_t lower = rs1_val >> m_pe_thread->GetBitModeInt()/2;
  UDWord_t upper = (rs2_val >> m_pe_thread->GetBitModeInt()/2) << m_pe_thread->GetBitModeInt()/2;
  UDWord_t res = lower | upper;

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}

uint64_t bmatflip(uint64_t rs1)
{
  uint64_t x = rs1;
  x = shfl64(x, 31);
  x = shfl64(x, 31);
  x = shfl64(x, 31);
  return x;
}


void InstEnv::RISCV_INST_BMATOR (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UDWord_t rs1_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs1_addr));
  UDWord_t rs2_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs2_addr));

  // transpose of rs2
  uint64_t rs2t = bmatflip(rs2_val);
  uint8_t u[8]; // rows of rs1
  uint8_t v[8]; // cols of rs2
  for (int i = 0; i < 8; i++) {
    u[i] = rs1_val >> (i*8);
    v[i] = rs2t >> (i*8);
  }
  uint64_t res = 0;
  for (int i = 0; i < 64; i++) {
    if ((u[i / 8] & v[i % 8]) != 0)
      res |= 1LL << i;
  }

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


UDWord_t pcnt(UDWord_t rs1, unsigned int xlen)
{
  int count = 0;
  for (int index = 0; index < xlen; index++)
    count += (rs1 >> index) & 1;
  return count;
}


void InstEnv::RISCV_INST_BMATXOR (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UDWord_t rs1_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs1_addr));
  UDWord_t rs2_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs2_addr));

  // transpose of rs2
  uint64_t rs2t = bmatflip(rs2_val);
  uint8_t u[8]; // rows of rs1
  uint8_t v[8]; // cols of rs2
  for (int i = 0; i < 8; i++) {
    u[i] = rs1_val >> (i*8);
    v[i] = rs2t >> (i*8);
  }
  uint64_t res = 0;
  for (int i = 0; i < 64; i++) {
    if (pcnt(u[i / 8] & v[i % 8], m_pe_thread->GetBitModeInt()) & 1)
      res |= 1LL << i;
  }

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_PACKH (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UDWord_t rs1_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs1_addr));
  UDWord_t rs2_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs2_addr));

  UDWord_t lower = rs1_val & 255;
  UDWord_t upper = (rs2_val & 255) << 8;
  UDWord_t res = lower | upper;

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_BFP (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UDWord_t rs1_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs1_addr));
  UDWord_t rs2_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs2_addr));

  UDWord_t cfg = rs2_val >> (m_pe_thread->GetBitModeInt()/2);
  if ((cfg >> 30) == 2)
    cfg = cfg >> 16;
  int len = (cfg >> 8) & (m_pe_thread->GetBitModeInt()/2-1);
  int off = cfg & (m_pe_thread->GetBitModeInt()-1);
  len = len ? len : m_pe_thread->GetBitModeInt()/2;
  UDWord_t mask = slo(0, len, m_pe_thread->GetBitModeInt()) << off;
  UDWord_t data = rs2_val << off;
  DWord_t res = (data & mask) | (rs1_val & ~mask);

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_SHFLI (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UDWord_t rs1_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs1_addr));
  DWord_t imm      = ExtractBitField (inst_hex, 25, 20);

  if (m_pe_thread->GetBitMode() == RiscvBitMode_t::Bit64) {
    UDWord_t res = shfl32(rs1_val, imm);
    m_pe_thread->WriteGReg<Word_t> (rd_addr, res);
  } else {
    UDWord_t res = shfl64(rs1_val, imm);
    m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
  }
}


void InstEnv::RISCV_INST_UNSHFLI (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UDWord_t rs1_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs1_addr));
  DWord_t imm      = ExtractBitField (inst_hex, 25, 20);

  if (m_pe_thread->GetBitMode() == RiscvBitMode_t::Bit64) {
    UDWord_t res = unshfl32(rs1_val, imm);
    m_pe_thread->WriteGReg<Word_t> (rd_addr, res);
  } else {
    UDWord_t res = unshfl64(rs1_val, imm);
    m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
  }
}


void InstEnv::RISCV_INST_ADDIWU (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UDWord_t rs1_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs1_addr));
  DWord_t imm      = ExtractBitField (inst_hex, 25, 20);

  UDWord_t result64 = rs1_val + imm;
  UWord_t res = (uint32_t)result64;

  m_pe_thread->WriteGReg<Word_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_ADDWU (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UDWord_t rs1_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs1_addr));
  UDWord_t rs2_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs2_addr));

  UDWord_t result64 = rs1_val + rs2_val;
  UWord_t res = (uint32_t)result64;

  m_pe_thread->WriteGReg<Word_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_SUBWU (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UDWord_t rs1_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs1_addr));
  UDWord_t rs2_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs2_addr));

  UDWord_t result64 = rs1_val - rs2_val;
  UWord_t res = (uint32_t)result64;

  m_pe_thread->WriteGReg<Word_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_ADDU_W (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UDWord_t rs1_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs1_addr));
  UDWord_t rs2_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs2_addr));

  UDWord_t rs2u = (uint32_t)rs2_val;
  UDWord_t res = rs1_val + rs2u;

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_SUBU_W (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UDWord_t rs1_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs1_addr));
  UDWord_t rs2_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs2_addr));

  UDWord_t rs2u = (uint32_t)rs2_val;
  UDWord_t res = rs1_val - rs2u;

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_SLOW (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UWord_t rs1_val  = m_pe_thread->ReadGReg<UWord_t> (rs1_addr);
  UWord_t rs2_val  = m_pe_thread->ReadGReg<UWord_t> (rs2_addr);

  uint32_t shamt = rs2_val & (m_pe_thread->GetBitModeInt() - 1);
  Word_t res_32 = ~(~rs1_val << shamt);
  UDWord_t res = ExtendSign(res_32, 31);

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_SROW (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UWord_t rs1_val  = m_pe_thread->ReadGReg<UWord_t> (rs1_addr);
  UWord_t rs2_val  = m_pe_thread->ReadGReg<UWord_t> (rs2_addr);

  uint32_t shamt = rs2_val & (m_pe_thread->GetBitModeInt() - 1);
  UWord_t res_32 = ~(~rs1_val >> shamt);
  UDWord_t res = ExtendSign(res_32, 31);

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_ROLW (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UWord_t rs1_val  = m_pe_thread->ReadGReg<UWord_t> (rs1_addr);
  UWord_t rs2_val  = m_pe_thread->ReadGReg<UWord_t> (rs2_addr);

  uint32_t shamt = rs2_val & (m_pe_thread->GetBitModeInt() - 1);
  UWord_t res_32 = (rs1_val << shamt) | (rs1_val >> ((m_pe_thread->GetBitModeInt() - shamt) & (m_pe_thread->GetBitModeInt() - 1)));
  UDWord_t res = ExtendSign(res_32, 31);

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_RORW (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UWord_t rs1_val  = m_pe_thread->ReadGReg<UWord_t> (rs1_addr);
  UWord_t rs2_val  = m_pe_thread->ReadGReg<UWord_t> (rs2_addr);

  uint32_t shamt = rs2_val & (m_pe_thread->GetBitModeInt() - 1);
  UWord_t res_32 = (rs1_val >> shamt) | (rs1_val << ((m_pe_thread->GetBitModeInt() - shamt) & (m_pe_thread->GetBitModeInt() - 1)));
  UDWord_t res = ExtendSign(res_32, 31);

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_SH1ADDU_W (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UWord_t rs1_val  = m_pe_thread->ReadGReg<UWord_t> (rs1_addr);
  UWord_t rs2_val  = m_pe_thread->ReadGReg<UWord_t> (rs2_addr);

  UWord_t res_32 = (rs1_val << 1) + rs2_val;
  UDWord_t res = ExtendSign(res_32, 31);

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_SH2ADDU_W (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UWord_t rs1_val  = m_pe_thread->ReadGReg<UWord_t> (rs1_addr);
  UWord_t rs2_val  = m_pe_thread->ReadGReg<UWord_t> (rs2_addr);

  Word_t res_32 = (rs1_val << 2) + rs2_val;
  UDWord_t res = ExtendSign(res_32, 31);

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_SH3ADDU_W (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UWord_t rs1_val  = m_pe_thread->ReadGReg<UWord_t> (rs1_addr);
  UWord_t rs2_val  = m_pe_thread->ReadGReg<UWord_t> (rs2_addr);

  Word_t res_32 = (rs1_val << 3) + rs2_val;
  UDWord_t res = ExtendSign(res_32, 31);

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_SBCLRW (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UWord_t rs1_val  = m_pe_thread->ReadGReg<UWord_t> (rs1_addr);
  UWord_t rs2_val  = m_pe_thread->ReadGReg<UWord_t> (rs2_addr);

  int shamt = rs2_val & (m_pe_thread->GetBitModeInt() - 1);
  Word_t res_32 = rs1_val | (UWord_t(1) << shamt);
  UDWord_t res = ExtendSign(res_32, 31);

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_SBSETW (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UWord_t rs1_val  = m_pe_thread->ReadGReg<UWord_t> (rs1_addr);
  UWord_t rs2_val  = m_pe_thread->ReadGReg<UWord_t> (rs2_addr);

  int shamt = rs2_val & (m_pe_thread->GetBitModeInt() - 1);
  Word_t res_32 = rs1_val & ~(UWord_t(1) << shamt);
  UDWord_t res = ExtendSign(res_32, 31);

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_SBINVW (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UWord_t rs1_val  = m_pe_thread->ReadGReg<UWord_t> (rs1_addr);
  UWord_t rs2_val  = m_pe_thread->ReadGReg<UWord_t> (rs2_addr);

  int shamt = rs2_val & (m_pe_thread->GetBitModeInt() - 1);
  Word_t res_32 = rs1_val ^ (UWord_t(1) << shamt);
  UDWord_t res = ExtendSign(res_32, 31);

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_SBEXTW (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UWord_t rs1_val  = m_pe_thread->ReadGReg<UWord_t> (rs1_addr);
  UWord_t rs2_val  = m_pe_thread->ReadGReg<UWord_t> (rs2_addr);

  int shamt = rs2_val & (m_pe_thread->GetBitModeInt() - 1);
  Word_t res_32 = 1 & (rs1_val >> shamt);
  UDWord_t res = ExtendSign(res_32, 31);

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_GORCW (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UWord_t rs1_val  = m_pe_thread->ReadGReg<UWord_t> (rs1_addr);
  UWord_t rs2_val  = m_pe_thread->ReadGReg<UWord_t> (rs2_addr);

  Word_t res_32 = 0;

  if (m_pe_thread->GetBitMode() == RiscvBitMode_t::Bit32) {
    uint32_t x = rs1_val;
    int shamt = rs2_val & (m_pe_thread->GetBitModeInt() - 1);
    if (shamt & 1) x |= ((x & 0x55555555) << 1) | ((x & 0xAAAAAAAA) >> 1);
    if (shamt & 2) x |= ((x & 0x33333333) << 2) | ((x & 0xCCCCCCCC) >> 2);
    if (shamt & 4) x |= ((x & 0x0F0F0F0F) << 4) | ((x & 0xF0F0F0F0) >> 4);
    if (shamt & 8) x |= ((x & 0x00FF00FF) << 8) | ((x & 0xFF00FF00) >> 8);
    if (shamt & 16) x |= ((x & 0x0000FFFF) << 16) | ((x & 0xFFFF0000) >> 16);

    res_32 = 1 & (rs1_val >> shamt);
  }

  UDWord_t res = ExtendSign(res_32, 31);
  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);

}


void InstEnv::RISCV_INST_GREVW (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UWord_t rs1_val  = m_pe_thread->ReadGReg<UWord_t> (rs1_addr);
  UWord_t rs2_val  = m_pe_thread->ReadGReg<UWord_t> (rs2_addr);

  UWord_t res_32 = 0;
  for (int i = 0; i < m_pe_thread->GetBitModeInt(); i++) {
    int j = (i ^ rs2_val) & (m_pe_thread->GetBitModeInt()-1);
    res_32 |= ((rs1_val >> i) & 1) << j;
  }

  UDWord_t res = ExtendSign(res_32, 31);
  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_SLOIW (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UDWord_t rs1_val = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs1_addr));
  DWord_t imm     = ExtractBitField (inst_hex, 24, 20);

  uint32_t shamt = imm & (m_pe_thread->GetBitModeInt() - 1);
  Word_t res_32 = ~(~rs1_val << shamt);

  UDWord_t res = ExtendSign(res_32, 31);
  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_SROIW (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UWord_t rs1_val = m_pe_thread->ReadGReg<UWord_t> (rs1_addr);
  DWord_t imm     = ExtractBitField (inst_hex, 24, 20);

  uint32_t shamt = imm & (m_pe_thread->GetBitModeInt() - 1);
  UWord_t res_32 = ~(~rs1_val >> shamt);
  UDWord_t res = ExtendSign(res_32, 31);

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_RORIW (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UWord_t rs1_val = m_pe_thread->ReadGReg<UWord_t> (rs1_addr);
  DWord_t imm     = ExtractBitField (inst_hex, 24, 20);

  uint32_t shamt = imm & (m_pe_thread->GetBitModeInt() - 1);
  UWord_t  res_32 = (rs1_val >> shamt) | (rs1_val << ((m_pe_thread->GetBitModeInt() - shamt) & (m_pe_thread->GetBitModeInt() - 1)));
  DWord_t  res = ExtendSign(res_32, 31);

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_SBCLRIW (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UWord_t rs1_val  = m_pe_thread->ReadGReg<Word_t> (rs1_addr);
  DWord_t imm      = ExtractBitField (inst_hex, 26, 20);

  int     shamt = imm & (m_pe_thread->GetBitModeInt() - 1);
  UWord_t res_32   = rs1_val | (UWord_t(1) << shamt);
  UDWord_t res = ExtendSign(res_32, 31);

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_SBSETIW (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UWord_t rs1_val  = m_pe_thread->ReadGReg<Word_t> (rs1_addr);
  DWord_t imm      = ExtractBitField (inst_hex, 24, 20);

  int shamt = imm & (m_pe_thread->GetBitModeInt() - 1);
  UWord_t res_32 = rs1_val & ~(UWord_t(1) << shamt);
  UDWord_t res = ExtendSign(res_32, 31);

  m_pe_thread->WriteGReg<UWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_SBINVIW (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UWord_t rs1_val  = m_pe_thread->ReadGReg<Word_t> (rs1_addr);
  DWord_t imm      = ExtractBitField (inst_hex, 24, 20);

  int shamt = imm & (m_pe_thread->GetBitModeInt() - 1);
  UWord_t res_32 = rs1_val ^ (UWord_t(1) << shamt);
  UDWord_t res = ExtendSign(res_32, 31);

  m_pe_thread->WriteGReg<UWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_GORCIW (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UWord_t rs1_val  = m_pe_thread->ReadGReg<Word_t> (rs1_addr);
  DWord_t imm      = ExtractBitField (inst_hex, 24, 20);

  int shamt = imm & (m_pe_thread->GetBitModeInt() - 1);

  UWord_t res_32 = 0;
  if (m_pe_thread->GetBitMode() == RiscvBitMode_t::Bit32) {
    uint32_t x = rs1_val;
    int shamt = imm & (m_pe_thread->GetBitModeInt() - 1);
    if (shamt & 1) x |= ((x & 0x55555555) << 1) | ((x & 0xAAAAAAAA) >> 1);
    if (shamt & 2) x |= ((x & 0x33333333) << 2) | ((x & 0xCCCCCCCC) >> 2);
    if (shamt & 4) x |= ((x & 0x0F0F0F0F) << 4) | ((x & 0xF0F0F0F0) >> 4);
    if (shamt & 8) x |= ((x & 0x00FF00FF) << 8) | ((x & 0xFF00FF00) >> 8);
    if (shamt & 16) x |= ((x & 0x0000FFFF) << 16) | ((x & 0xFFFF0000) >> 16);

    res_32 = 1 & (rs1_val >> shamt);
  }

  UDWord_t res = ExtendSign(res_32, 31);
  m_pe_thread->WriteGReg<UWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_GREVIW (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UWord_t rs1_val  = m_pe_thread->ReadGReg<Word_t> (rs1_addr);
  DWord_t imm      = ExtractBitField (inst_hex, 24, 20);

  UWord_t res_32 = 0;
  for (int i = 0; i < m_pe_thread->GetBitModeInt(); i++) {
    int j = (i ^ imm) & (m_pe_thread->GetBitModeInt()-1);
    res_32 |= ((rs1_val >> i) & 1) << j;
  }

  UDWord_t res = ExtendSign(res_32, 31);
  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_FSLW (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rs3_addr = ExtractR3Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UWord_t rs1_val  = m_pe_thread->ReadGReg<UWord_t> (rs1_addr);
  UWord_t rs2_val  = m_pe_thread->ReadGReg<UWord_t> (rs2_addr);
  DWord_t rs3_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<DWord_t> (rs3_addr));

  int shamt = rs2_val & (2*32 - 1);
  UWord_t A = rs1_val, B = rs3_val;
  if (shamt >= 32) {
    shamt -= 32;
    A = rs3_val;
    B = rs1_val;
  }
  Word_t res_32 = shamt ? (rs1_val << shamt) | (B >> (32-shamt)) : A;
  UDWord_t res = ExtendSign(res_32, 31);

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_FSRW (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rs3_addr = ExtractR3Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UWord_t rs1_val  = m_pe_thread->ReadGReg<UWord_t> (rs1_addr);
  UWord_t rs2_val  = m_pe_thread->ReadGReg<UWord_t> (rs2_addr);
  DWord_t rs3_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<DWord_t> (rs3_addr));

  int shamt = rs2_val & (2*32 - 1);
  UWord_t A = rs1_val, B = rs3_val;
  if (shamt >= 32) {
    shamt -= 32;
    A = rs3_val;
    B = rs1_val;
  }
  Word_t res_32 = shamt ? (rs1_val >> shamt) | (B << (32-shamt)) : A;
  UDWord_t res = ExtendSign(res_32, 31);

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_FSRIW (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs3_addr = ExtractR3Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UWord_t rs1_val  = m_pe_thread->ReadGReg<UWord_t> (rs1_addr);
  DWord_t rs3_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<DWord_t> (rs3_addr));
  DWord_t imm     = ExtractBitField (inst_hex, 26, 20);

  int shamt = imm & (2*32 - 1);
  UWord_t A = rs1_val, B = rs3_val;
  if (shamt >= 32) {
    shamt -= 32;
    A = rs3_val;
    B = rs1_val;
  }
  Word_t res_32 = shamt ? (rs1_val >> shamt) | (B << (32-shamt)) : A;
  UDWord_t res = ExtendSign(res_32, 31);

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_CLZW (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UWord_t rs1_val  = m_pe_thread->ReadGReg<UWord_t> (rs1_addr);

  UWord_t res_32 = 32;
  for (int count = 0; count < 32; count++) {
    if ((rs1_val << count) >> 31) {
      res_32 = count;
      break;
    }
  }

  UDWord_t res = ExtendSign(res_32, 31);
  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_CTZW (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UWord_t rs1_val  = m_pe_thread->ReadGReg<UWord_t> (rs1_addr);

  Word_t res_32 = 32;
  for (int count = 0; count < 32; count++) {
    if ((rs1_val >> count) & 1) {
      res_32 = count;
      break;
    }
  }
  UDWord_t res = ExtendSign(res_32, 31);
  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_PCNTW (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UWord_t rs1_val  = m_pe_thread->ReadGReg<UWord_t> (rs1_addr);
  UWord_t rs2_val  = m_pe_thread->ReadGReg<UWord_t> (rs2_addr);

  int count = 0;
  for (int index = 0; index < 32; index++)
    count += (rs1_val >> index) & 1;
  Word_t res_32 = count;

  UDWord_t res = ExtendSign(res_32, 31);
  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_CLMULW (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UWord_t rs1_val  = m_pe_thread->ReadGReg<UWord_t> (rs1_addr);
  UWord_t rs2_val  = m_pe_thread->ReadGReg<UWord_t> (rs2_addr);

  UWord_t res_32 = 0;
  for (int i = 0; i < 32; i++)
    if ((rs2_val >> i) & 1)
      res_32 ^= rs1_val << i;

  UDWord_t res = ExtendSign(res_32, 31);
  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_CLMULRW (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UWord_t rs1_val  = m_pe_thread->ReadGReg<UWord_t> (rs1_addr);
  UWord_t rs2_val  = m_pe_thread->ReadGReg<UWord_t> (rs2_addr);

  UWord_t res_32 = 0;
  for (int i = 0; i < 32; i++)
    if ((rs2_val >> i) & 1)
      res_32 ^= rs1_val >> (32-i-1);

  UDWord_t res = ExtendSign(res_32, 31);
  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_CLMULHW (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UWord_t rs1_val  = m_pe_thread->ReadGReg<UWord_t> (rs1_addr);
  UWord_t rs2_val  = m_pe_thread->ReadGReg<UWord_t> (rs2_addr);

  UWord_t res_32 = 0;
  for (int i = 1; i < 32; i++)
    if ((rs2_val >> i) & 1)
      res_32 ^= rs1_val >> (32-i);

  UDWord_t res = ExtendSign(res_32, 31);
  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_SHFLW (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UWord_t rs1_val  = m_pe_thread->ReadGReg<UWord_t> (rs1_addr);
  UWord_t rs2_val  = m_pe_thread->ReadGReg<UWord_t> (rs2_addr);

  if (m_pe_thread->GetBitMode() == RiscvBitMode_t::Bit64) {
    UWord_t res_32 = shfl32(rs1_val, rs2_val);
    UDWord_t res = ExtendSign(res_32, 31);
    m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
  } else {
    UWord_t res_32 = shfl64(rs1_val, rs2_val);
    m_pe_thread->WriteGReg<DWord_t> (rd_addr, res_32);
  }
}


void InstEnv::RISCV_INST_UNSHFLW (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UWord_t rs1_val  = m_pe_thread->ReadGReg<UWord_t> (rs1_addr);
  UWord_t rs2_val  = m_pe_thread->ReadGReg<UWord_t> (rs2_addr);

  if (m_pe_thread->GetBitMode() == RiscvBitMode_t::Bit32) {
    UWord_t res_32 = unshfl32(rs1_val, rs2_val);
    UDWord_t res = ExtendSign(res_32, 31);
    m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
  }
}


void InstEnv::RISCV_INST_BDEPW (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UWord_t rs1_val  = m_pe_thread->ReadGReg<UWord_t> (rs1_addr);
  UWord_t rs2_val  = m_pe_thread->ReadGReg<UWord_t> (rs2_addr);

  UWord_t res_32 = 0;
  for (int i = 0, j = 0; i < 32; i++)
    if ((rs2_val >> i) & 1) {
      if ((rs1_val >> j) & 1)
        res_32 |= UWord_t(1) << i;
      j++;
    }

  UDWord_t res = ExtendSign(res_32, 31);
  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_BEXTW (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UWord_t rs1_val  = m_pe_thread->ReadGReg<UWord_t> (rs1_addr);
  UWord_t rs2_val  = m_pe_thread->ReadGReg<UWord_t> (rs2_addr);

  UWord_t res_32 = 0;
  for (int i = 0, j = 0; i < 32; i++)
    if ((rs2_val >> i) & 1) {
      if ((rs1_val >> i) & 1)
        res_32 |= UWord_t(1) << j;
      j++;
    }

  UDWord_t res = ExtendSign(res_32, 31);
  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_PACKW (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UWord_t rs1_val  = m_pe_thread->ReadGReg<UWord_t> (rs1_addr);
  UWord_t rs2_val  = m_pe_thread->ReadGReg<UWord_t> (rs2_addr);

  UWord_t lower = (rs1_val << 32/2) >> 32/2;
  UWord_t upper = rs2_val << 32/2;
  UWord_t res_32 = lower | upper;

  UDWord_t res = ExtendSign(res_32, 31);
  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_PACKUW (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UWord_t rs1_val  = m_pe_thread->ReadGReg<UWord_t> (rs1_addr);
  UWord_t rs2_val  = m_pe_thread->ReadGReg<UWord_t> (rs2_addr);

  UWord_t lower = rs1_val >> 32/2;
  UWord_t upper = (rs2_val >> 32/2) << 32/2;
  UWord_t res_32 = lower | upper;
  UDWord_t res = ExtendSign(res_32, 31);

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_BFPW (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UWord_t rs1_val  = m_pe_thread->ReadGReg<UWord_t> (rs1_addr);
  UWord_t rs2_val  = m_pe_thread->ReadGReg<UWord_t> (rs2_addr);

  UWord_t cfg = rs2_val >> (32/2);
  if ((cfg >> 30) == 2)
    cfg = cfg >> 16;
  int len = (cfg >> 8) & (32/2-1);
  int off = cfg & (32-1);
  len = len ? len : 32/2;
  UWord_t mask = slo(0, len, 32) << off;
  UWord_t data = rs2_val << off;
  Word_t res_32 = (data & mask) | (rs1_val & ~mask);
  UDWord_t res = ExtendSign(res_32, 31);

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}
