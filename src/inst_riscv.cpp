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

#include "inst_riscv__ALU.cpp"
#include "inst_riscv__FPU.cpp"

InstEnv::InstEnv (RiscvPeThread *env)
{
  m_pe_thread = env;
}


void InstEnv::RISCV_Inst_Exec (InstId_t index, InstWord_t inst_hex)
{
  (this->*m_inst_exec_func[static_cast<uint32_t>(index)]) (inst_hex);

  return;
}


void InstEnv::RISCV_INST_LUI (InstWord_t inst_hex)
{
  RegAddr_t rd_addr = ExtractRDField (inst_hex);
  DWord_t   imm   = ExtendSign (ExtractBitField (inst_hex, 31, 12), 19);
  DWord_t   res   = m_pe_thread->SExtXlen (imm << 12);

  m_pe_thread->WriteGReg (rd_addr, res);
}


void InstEnv::RISCV_INST_AUIPC (InstWord_t inst_hex)
{
  RegAddr_t rd_addr = ExtractRDField (inst_hex);
  DWord_t   imm     = ExtendSign (ExtractBitField (inst_hex, 31, 12), 19);
  DWord_t   mask    = ~0xfff;
  UDWord_t  res   = ((imm << 12) & mask) + m_pe_thread->GetPC ();

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, m_pe_thread->SExtXlen(res));
}


void InstEnv::RISCV_INST_JAL (InstWord_t inst_hex)
{
  RegAddr_t rd_addr = ExtractRDField (inst_hex);
  Addr_t    imm     = ExtractUJField (inst_hex);
  Addr_t    pc_addr = m_pe_thread->GetPC ();
  Addr_t    res_pc  = imm + pc_addr;

  m_pe_thread->WriteGReg (rd_addr, m_pe_thread->SExtXlen(pc_addr + 4));

  // if (!m_pe_thread->IsSupportCMode()) {
  //   res_pc = res_pc & ~0x03ULL;  // If Compress Mode is disabled, return PC should be 4-byte aligned.
  // }
  m_pe_thread->SetPC (m_pe_thread->UExtXlen(res_pc));
  m_pe_thread->SetJumped (true);

  m_pe_thread->IsBranchTaken (pc_addr);
  m_pe_thread->UpdateBranchPrediction (pc_addr, true);
}


void InstEnv::RISCV_INST_JALR (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rd_addr = ExtractRDField (inst_hex);
  Addr_t    imm    = ExtractIField (inst_hex);
  Addr_t    pc_addr  = m_pe_thread->GetPC ();
  Addr_t    rs1_val  = m_pe_thread->ReadGReg<Addr_t> (rs1_addr);
  Addr_t    res_pc   = rs1_val + imm;
  // JALR ignores lowest LSB
  res_pc = m_pe_thread->UExtXlen (res_pc & (~0x01));

  // if ((res_pc & 0x3) == 0x0) {
  // RVC
  m_pe_thread->WriteGReg (rd_addr, m_pe_thread->SExtXlen(pc_addr + 4));
  // }

  // if (!m_pe_thread->IsSupportCMode()) {
  //   res_pc = res_pc & ~0x03ULL;  // If Compress Mode is disabled, return PC should be 4-byte aligned.
  // }
  m_pe_thread->SetPC (m_pe_thread->UExtXlen(res_pc));
  m_pe_thread->SetJumped (true);

  m_pe_thread->IsBranchTaken (pc_addr);
  m_pe_thread->UpdateBranchPrediction (pc_addr, true);
}


void InstEnv::RISCV_INST_SLLI (InstWord_t inst_hex)
{
  // 32-bit Mode shamt[5] == 1 is illegal
  if (m_pe_thread->GetBitMode() == RiscvBitMode_t::Bit32 && ExtractBitField(inst_hex, 25, 25)) {
    m_pe_thread->GenerateException (ExceptCode::Except_IllegalInst, 0);
    return;
  }

  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UDWord_t rs1_val = m_pe_thread->ReadGReg<UDWord_t> (rs1_addr);
  UDWord_t shamt   = ExtractBitField (inst_hex, 25, 20);
  UDWord_t res     = m_pe_thread->SExtXlen(m_pe_thread->UExtXlen(rs1_val) << shamt);
  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_SRLI (InstWord_t inst_hex)
{
  // 32-bit Mode shamt[5] == 1 is illegal
  if (m_pe_thread->GetBitMode() == RiscvBitMode_t::Bit32 && ExtractBitField(inst_hex, 25, 25)) {
    m_pe_thread->GenerateException (ExceptCode::Except_IllegalInst, 0);
    return;
  }

  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UDWord_t rs1_val = m_pe_thread->ReadGReg<UDWord_t> (rs1_addr);
  UDWord_t shamt   = ExtractBitField (inst_hex, 25, 20);
  UDWord_t res     = m_pe_thread->SExtXlen(m_pe_thread->UExtXlen(rs1_val) >> shamt);
  m_pe_thread->WriteGReg<DWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_SRAI (InstWord_t inst_hex)
{
  // 32-bit Mode shamt[5] == 1 is illegal
  if (m_pe_thread->GetBitMode() == RiscvBitMode_t::Bit32 && ExtractBitField(inst_hex, 25, 25)) {
    m_pe_thread->GenerateException (ExceptCode::Except_IllegalInst, 0);
    return;
  }

  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  DWord_t rs1_val = m_pe_thread->ReadGReg<DWord_t> (rs1_addr);
  DWord_t shamt   = ExtractBitField (inst_hex, 25, 20);
  DWord_t res     = m_pe_thread->SExtXlen(rs1_val >> shamt);
  m_pe_thread->WriteGReg<DWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_BEQ (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);

  DWord_t rs1_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<DWord_t> (rs1_addr));
  DWord_t rs2_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<DWord_t> (rs2_addr));
  DWord_t  imm    = ExtractSBField (inst_hex);

  Addr_t current_pc = m_pe_thread->GetPC();
  m_pe_thread->IsBranchTaken (current_pc);

  bool taken = (rs1_val == rs2_val);
  if (taken) {
    DWord_t res_pc = current_pc + imm;
    // if (!m_pe_thread->IsSupportCMode()) {
    //   res_pc = res_pc & ~0x03ULL;  // If Compress Mode is disabled, return PC should be 4-byte aligned.
    // }
    m_pe_thread->SetPC (m_pe_thread->UExtXlen(res_pc));
    m_pe_thread->SetJumped (true);
  }

  m_pe_thread->UpdateBranchPrediction (current_pc, taken);
}


void InstEnv::RISCV_INST_BNE (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);

  DWord_t rs1_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<DWord_t> (rs1_addr));
  DWord_t rs2_val  = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<DWord_t> (rs2_addr));
  DWord_t imm      = ExtractSBField (inst_hex);

  Addr_t current_pc = m_pe_thread->GetPC();
  m_pe_thread->IsBranchTaken (current_pc);

  bool taken = (rs1_val != rs2_val);
  if (taken) {
    Addr_t res_pc = current_pc + imm;
    // if (!m_pe_thread->IsSupportCMode()) {
    //   res_pc = res_pc & ~0x03ULL;  // If Compress Mode is disabled, return PC should be 4-byte aligned.
    // }
    m_pe_thread->SetPC (m_pe_thread->UExtXlen(res_pc));
    m_pe_thread->SetJumped (true);
  }

  m_pe_thread->UpdateBranchPrediction (current_pc, taken);
}


void InstEnv::RISCV_INST_BLT (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);

  DWord_t rs1_val = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<DWord_t> (rs1_addr));
  DWord_t rs2_val = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<DWord_t> (rs2_addr));
  DWord_t imm     = ExtractSBField (inst_hex);

  Addr_t current_pc = m_pe_thread->GetPC();
  m_pe_thread->IsBranchTaken (current_pc);

  bool taken = (rs1_val < rs2_val);
  if (taken) {
    DWord_t res_pc = current_pc + imm;
    // if (!m_pe_thread->IsSupportCMode()) {
    //   res_pc = res_pc & ~0x03ULL;  // If Compress Mode is disabled, return PC should be 4-byte aligned.
    // }
    m_pe_thread->SetPC (m_pe_thread->UExtXlen(res_pc));
    m_pe_thread->SetJumped (true);
  }

  m_pe_thread->UpdateBranchPrediction (current_pc, taken);

}


void InstEnv::RISCV_INST_BGE (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);

  DWord_t rs1_val = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<DWord_t> (rs1_addr));
  DWord_t rs2_val = m_pe_thread->SExtXlen (m_pe_thread->ReadGReg<DWord_t> (rs2_addr));
  DWord_t imm     = ExtractSBField (inst_hex);

  Addr_t current_pc = m_pe_thread->GetPC();
  m_pe_thread->IsBranchTaken (current_pc);

  bool taken = (rs1_val >= rs2_val);
  if (taken) {
    DWord_t res_pc = current_pc + imm;
    // if (!m_pe_thread->IsSupportCMode()) {
    //   res_pc = res_pc & ~0x03ULL;  // If Compress Mode is disabled, return PC should be 4-byte aligned.
    // }
    m_pe_thread->SetPC (m_pe_thread->UExtXlen(res_pc));
    m_pe_thread->SetJumped (true);
  }

  m_pe_thread->UpdateBranchPrediction (current_pc, taken);

}


void InstEnv::RISCV_INST_BLTU (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);

  UDWord_t rs1_val = m_pe_thread->UExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs1_addr));
  UDWord_t rs2_val = m_pe_thread->UExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs2_addr));
  DWord_t  imm     = ExtractSBField (inst_hex);

  Addr_t current_pc = m_pe_thread->GetPC();
  m_pe_thread->IsBranchTaken (current_pc);

  bool taken = (rs1_val < rs2_val);
  if (taken) {
    DWord_t res_pc = current_pc + imm;
    // if (!m_pe_thread->IsSupportCMode()) {
    //   res_pc = res_pc & ~0x03ULL;  // If Compress Mode is disabled, return PC should be 4-byte aligned.
    // }
    m_pe_thread->SetPC (m_pe_thread->UExtXlen(res_pc));
    m_pe_thread->SetJumped (true);
  }

  m_pe_thread->UpdateBranchPrediction (current_pc, taken);

}


void InstEnv::RISCV_INST_BGEU (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);

  UDWord_t rs1_val = m_pe_thread->UExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs1_addr));
  UDWord_t rs2_val = m_pe_thread->UExtXlen (m_pe_thread->ReadGReg<UDWord_t> (rs2_addr));
  DWord_t  imm     = ExtractSBField (inst_hex);

  Addr_t current_pc = m_pe_thread->GetPC ();
  m_pe_thread->IsBranchTaken (current_pc);

  bool taken;
  if (std::is_same<DWord_t, Word_t>::value) {
    taken = static_cast<UWord_t >(rs1_val) >= static_cast<UWord_t >(rs2_val);
  } else {
    taken = static_cast<UDWord_t>(rs1_val) >= static_cast<UDWord_t>(rs2_val);
  }

  if (taken) {
    DWord_t res_pc = current_pc + imm;
    // if (!m_pe_thread->IsSupportCMode()) {
    //   res_pc = res_pc & ~0x03ULL;  // If Compress Mode is disabled, return PC should be 4-byte aligned.
    // }
    m_pe_thread->SetPC (m_pe_thread->UExtXlen(res_pc));
    m_pe_thread->SetJumped (true);
  }

  m_pe_thread->UpdateBranchPrediction (current_pc, taken);

}


void InstEnv::RISCV_INST_LB (InstWord_t inst_hex)
{
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);

  DWord_t rs1_val  = m_pe_thread->ReadGReg<DWord_t> (rs1_addr);
  DWord_t imm      = ExtractIField (inst_hex);

  Addr_t  mem_addr = m_pe_thread->UExtXlen (rs1_val + imm);

  Byte_t  res;
  MemResult except = m_pe_thread->LoadFromBus (mem_addr, &res);
  if (except == MemResult::MemMisAlign) {
    m_pe_thread->GenerateException (ExceptCode::Except_LoadAddrMisalign, mem_addr);
    return;
  }
  if (except == MemResult::MemTlbError) {
    m_pe_thread->GenerateException (ExceptCode::Except_LoadPageFault, mem_addr);
    return;
  }

  Word_t res_word = ExtendSign (res, 7);

  m_pe_thread->WriteGReg (rd_addr, res_word);
}


void InstEnv::RISCV_INST_LH (InstWord_t inst_hex)
{
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);

  DWord_t  rs1_val  = m_pe_thread->ReadGReg<DWord_t> (rs1_addr);
  DWord_t  imm      = ExtractIField (inst_hex);

  Addr_t  mem_addr = m_pe_thread->UExtXlen (rs1_val + imm);

  HWord_t  res;
  MemResult except = m_pe_thread->LoadFromBus (mem_addr, &res);
  if (except == MemResult::MemMisAlign) {
    m_pe_thread->GenerateException (ExceptCode::Except_LoadAddrMisalign, mem_addr);
    return;
  }
  if (except == MemResult::MemTlbError) {
    m_pe_thread->GenerateException (ExceptCode::Except_LoadPageFault, mem_addr);
    return;
  }

  Word_t res_word = ExtendSign ((res & 0x0000ffff), 15);
  m_pe_thread->WriteGReg (rd_addr, res_word);
}


void InstEnv::RISCV_INST_LW (InstWord_t inst_hex)
{
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);

  DWord_t rs1_val  = m_pe_thread->ReadGReg<DWord_t> (rs1_addr);
  DWord_t imm      = ExtractIField (inst_hex);

  Addr_t  mem_addr = m_pe_thread->UExtXlen (rs1_val + imm);

  Word_t  res_32;
  MemResult except = m_pe_thread->LoadFromBus (mem_addr, &res_32);
  DWord_t res = res_32;  // just extending sign

  if (except == MemResult::MemMisAlign) {
    m_pe_thread->GenerateException (ExceptCode::Except_LoadAddrMisalign, mem_addr);
    return;
  }
  if (except == MemResult::MemTlbError) {
    m_pe_thread->GenerateException (ExceptCode::Except_LoadPageFault, mem_addr);
    return;
  }

  m_pe_thread->WriteGReg (rd_addr, res);
}


void InstEnv::RISCV_INST_LBU (InstWord_t inst_hex)
{
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);

  DWord_t rs1_val  = m_pe_thread->ReadGReg<DWord_t> (rs1_addr);
  DWord_t imm      = ExtractIField (inst_hex);

  Addr_t  mem_addr = m_pe_thread->UExtXlen (rs1_val + imm);

  Byte_t  res;
  MemResult except = m_pe_thread->LoadFromBus (mem_addr, &res);
  if (except == MemResult::MemMisAlign) {
    m_pe_thread->GenerateException (ExceptCode::Except_LoadAddrMisalign, mem_addr);
    return;
  }
  if (except == MemResult::MemTlbError) {
    m_pe_thread->GenerateException (ExceptCode::Except_LoadPageFault, mem_addr);
    return;
  }

  UWord_t res_w = res & 0x000000ff;
  m_pe_thread->WriteGReg (rd_addr, res_w);
}


void InstEnv::RISCV_INST_LHU (InstWord_t inst_hex)
{
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);

  DWord_t rs1_val  = m_pe_thread->ReadGReg<DWord_t> (rs1_addr);
  DWord_t imm      = ExtractIField (inst_hex);

  Addr_t  mem_addr = m_pe_thread->UExtXlen (rs1_val + imm);

  HWord_t  res;
  MemResult except = m_pe_thread->LoadFromBus (mem_addr, &res);
  if (except == MemResult::MemMisAlign) {
    m_pe_thread->GenerateException (ExceptCode::Except_LoadAddrMisalign, mem_addr);
    return;
  }
  if (except == MemResult::MemTlbError) {
    m_pe_thread->GenerateException (ExceptCode::Except_LoadPageFault, mem_addr);
    return;
  }

  Word_t res_w = res & 0x0000ffff;
  m_pe_thread->WriteGReg (rd_addr, res_w);
}


void InstEnv::RISCV_INST_SB (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);

  DWord_t rs1_val = m_pe_thread->ReadGReg<UDWord_t> (rs1_addr);
  UWord_t rs2_val  = m_pe_thread->ReadGReg<Word_t> (rs2_addr);
  DWord_t  imm    = ExtractSField (inst_hex);

  Addr_t  mem_addr = m_pe_thread->UExtXlen (rs1_val + imm);

  Byte_t  store_data = rs2_val & 0x000000ff;
  MemResult except = m_pe_thread->StoreToBus (mem_addr, store_data);
  if (except == MemResult::MemMisAlign) {
    m_pe_thread->GenerateException (ExceptCode::Except_StoreAddrMisalign, mem_addr);
    return;
  }
  if (except == MemResult::MemTlbError) {
    m_pe_thread->GenerateException (ExceptCode::Except_StorePageFault, mem_addr);
    return;
  }

}


void InstEnv::RISCV_INST_SH (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);

  DWord_t rs1_val = m_pe_thread->ReadGReg<UDWord_t> (rs1_addr);
  UWord_t rs2_val  = m_pe_thread->ReadGReg<Word_t> (rs2_addr);
  DWord_t  imm    = ExtractSField (inst_hex);

  Addr_t  mem_addr = m_pe_thread->UExtXlen (rs1_val + imm);

  HWord_t store_data = rs2_val & 0x0000ffff;
  MemResult except = m_pe_thread->StoreToBus (mem_addr, store_data);
  if (except == MemResult::MemMisAlign) {
    m_pe_thread->GenerateException (ExceptCode::Except_StoreAddrMisalign, mem_addr);
    return;
  }
  if (except == MemResult::MemTlbError) {
    m_pe_thread->GenerateException (ExceptCode::Except_StorePageFault, mem_addr);
    return;
  }
}


void InstEnv::RISCV_INST_SW (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);

  Addr_t rs1_val = m_pe_thread->ReadGReg<Addr_t> (rs1_addr);
  Word_t rs2_val = m_pe_thread->ReadGReg<Word_t> (rs2_addr);
  Addr_t imm     = ExtractSField (inst_hex);

  Addr_t mem_addr = m_pe_thread->UExtXlen (rs1_val + imm);

  MemResult except = m_pe_thread->StoreToBus (mem_addr, rs2_val);
  if (except == MemResult::MemMisAlign) {
    m_pe_thread->GenerateException (ExceptCode::Except_StoreAddrMisalign, mem_addr);
    return;
  }
  if (except == MemResult::MemTlbError) {
    m_pe_thread->GenerateException (ExceptCode::Except_StorePageFault, mem_addr);
    return;
  }
}


void InstEnv::RISCV_INST_FENCE (InstWord_t inst_hex)
{
  /* As ISS, do nothing */
}


void InstEnv::RISCV_INST_FENCE_I (InstWord_t inst_hex)
{
  /* As ISS, do nothing */
}


// void InstEnv::RISCV_INST_RDCYCLE (InstWord_t inst_hex) {}
// void InstEnv::RISCV_INST_RDCYCLEH (InstWord_t inst_hex) {}
// void InstEnv::RISCV_INST_RDTIME (InstWord_t inst_hex) {}
// void InstEnv::RISCV_INST_RDTIMEH (InstWord_t inst_hex) {}
// void InstEnv::RISCV_INST_RDINSTRET (InstWord_t inst_hex) {}
// void InstEnv::RISCV_INST_RDINSTRETH (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_MUL (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  DWord_t rs1_val  = m_pe_thread->ReadGReg<DWord_t> (rs1_addr);
  DWord_t rs2_val  = m_pe_thread->ReadGReg<DWord_t> (rs2_addr);

  bool is_result_minus = ((rs1_val < 0) && (rs2_val > 0)) ||
                         ((rs1_val > 0) && (rs2_val < 0));

  std::stringstream rs1_str, rs2_str;
  rs1_str << rs1_val;
  rs2_str << rs2_val;

  mpz_class rs1_mpz, rs2_mpz;
  rs1_mpz.set_str(rs1_str.str(), 10);
  rs2_mpz.set_str(rs2_str.str(), 10);
  mpz_class res_mpz = (rs1_mpz * rs2_mpz);

  DWord_t res = res_mpz.get_ui ();
  if (is_result_minus) {
    res = ~res + 1;
  }
  res = m_pe_thread->SExtXlen (res);
  m_pe_thread->WriteGReg<DWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_MULH (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  if (m_pe_thread->GetBitMode() == RiscvBitMode_t::Bit32) {
    DWord_t rs1_val  = m_pe_thread->ReadGReg<DWord_t> (rs1_addr);
    DWord_t rs2_val  = m_pe_thread->ReadGReg<DWord_t> (rs2_addr);
    DWord_t res = rs1_val * rs2_val;

    Word_t  res_hi = (res >> 32) & 0x0ffffffffULL;
    m_pe_thread->WriteGReg (rd_addr, res_hi);
  } else if (m_pe_thread->GetBitMode() == RiscvBitMode_t::Bit64) {
    DWord_t rs1_val  = m_pe_thread->ReadGReg<DWord_t> (rs1_addr);
    DWord_t rs2_val  = m_pe_thread->ReadGReg<DWord_t> (rs2_addr);

    std::stringstream rs1_str, rs2_str;
    rs1_str << rs1_val;
    rs2_str << rs2_val;
    mpz_class rs1_mpz, rs2_mpz;
    rs1_mpz.set_str(rs1_str.str(), 10);
    rs2_mpz.set_str(rs2_str.str(), 10);

    mpz_class xlen_mpz (1);
    mpz_class mpz_2 (2);
    for (int i = 0; i < 64; i++) {
      xlen_mpz = xlen_mpz * mpz_2;
    }
    mpz_class res_mpz = (rs1_mpz * rs2_mpz) / xlen_mpz;

    Word_t res_hi = res_mpz.get_si ();
    m_pe_thread->WriteGReg (rd_addr, res_hi);
  }
}


void InstEnv::RISCV_INST_MULHSU (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  if (m_pe_thread->GetBitMode() == RiscvBitMode_t::Bit32) {
    Word_t  rs1_val = m_pe_thread->ReadGReg<Word_t> (rs1_addr);
    UWord_t rs2_val = m_pe_thread->ReadGReg<UWord_t> (rs2_addr);

    DWord_t res64   = (DWord_t)rs1_val * (UDWord_t)rs2_val;
    Word_t  res_hi  = (res64 >> 32) & 0x0ffffffffUL;
    m_pe_thread->WriteGReg (rd_addr, res_hi);
  } else if (m_pe_thread->GetBitMode() == RiscvBitMode_t::Bit64) {
    DWord_t  rs1_val = m_pe_thread->ReadGReg<DWord_t> (rs1_addr);
    UDWord_t rs2_val = m_pe_thread->ReadGReg<UDWord_t> (rs2_addr);

    bool is_result_minus = ((rs1_val < 0) && (rs2_val > 0)) ||
                           ((rs1_val > 0) && (rs2_val < 0));

    std::stringstream rs1_str, rs2_str;
    rs1_str << rs1_val;
    rs2_str << rs2_val;

    mpz_class rs1_mpz, rs2_mpz;
    rs1_mpz.set_str(rs1_str.str(), 10);
    rs2_mpz.set_str(rs2_str.str(), 10);

    mpz_class mpz_2 (2);
    mpz_class res_mpz2 = (rs1_mpz * rs2_mpz);
    for (int i = 0; i < 64; i++) {
      res_mpz2 = res_mpz2 / mpz_2;
    }

    DWord_t res = res_mpz2.get_ui ();
    if (is_result_minus) {
      res = ~res;
    }

    m_pe_thread->WriteGReg (rd_addr, res);
  }
}


void InstEnv::RISCV_INST_MULHU (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  if (m_pe_thread->GetBitMode() == RiscvBitMode_t::Bit32) {
    UWord_t  rs1_val = m_pe_thread->ReadGReg<UWord_t> (rs1_addr);
    UWord_t  rs2_val = m_pe_thread->ReadGReg<UWord_t> (rs2_addr);
    UDWord_t res64   = (UDWord_t)rs1_val * (UDWord_t)rs2_val;
    UDWord_t res_hi  = m_pe_thread->SExtXlen ((res64 >> 32) & 0xffffffffULL);

    m_pe_thread->WriteGReg (rd_addr, res_hi);
  } else if (m_pe_thread->GetBitMode() == RiscvBitMode_t::Bit64) {
    UDWord_t rs1_val = m_pe_thread->ReadGReg<UDWord_t> (rs1_addr);
    UDWord_t rs2_val = m_pe_thread->ReadGReg<UDWord_t> (rs2_addr);
    // UDWord_t res64   = (DWord_t)rs1_val * (DWord_t)rs2_val;

    std::stringstream rs1_str, rs2_str;
    rs1_str << rs1_val;
    rs2_str << rs2_val;
    mpz_class rs1_mpz, rs2_mpz;
    rs1_mpz.set_str(rs1_str.str(), 10);
    rs2_mpz.set_str(rs2_str.str(), 10);

    mpz_class xlen_mpz (1);
    mpz_class mpz_2 (2);
    for (int i = 0; i < 64; i++) {
      xlen_mpz = xlen_mpz * mpz_2;
    }
    mpz_class res_tmp = rs1_mpz * rs2_mpz;
    mpz_class res_mpz = (rs1_mpz * rs2_mpz);
    for (int i = 0; i < 64; i++) {
      res_mpz = res_mpz / mpz_2;
    }
    UDWord_t res_hi = res_mpz.get_ui ();

    m_pe_thread->WriteGReg (rd_addr, res_hi);
  }
}


void InstEnv::RISCV_INST_DIV (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  if (m_pe_thread->GetBitMode() == RiscvBitMode_t::Bit32) {
    Word_t rs1_val = m_pe_thread->ReadGReg<Word_t> (rs1_addr);
    Word_t rs2_val = m_pe_thread->ReadGReg<Word_t> (rs2_addr);
    Word_t res     = InstOps::IntDiv32 (rs1_val, rs2_val);
    m_pe_thread->WriteGReg (rd_addr, res);
  } else {
    DWord_t rs1_val = m_pe_thread->ReadGReg<DWord_t> (rs1_addr);
    DWord_t rs2_val = m_pe_thread->ReadGReg<DWord_t> (rs2_addr);

    DWord_t res;
    if (rs2_val == 0) {
      res = -1;
    } else if ((rs1_val == INT64_MIN) && (rs2_val == -1)) {
      res = INT64_MIN;
    } else {
      res = rs1_val / rs2_val;
    }
    m_pe_thread->WriteGReg (rd_addr, res);
  }
}


void InstEnv::RISCV_INST_DIVU (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UDWord_t rs1_val  = m_pe_thread->UExtXlen(m_pe_thread->ReadGReg<UDWord_t> (rs1_addr));
  UDWord_t rs2_val  = m_pe_thread->UExtXlen(m_pe_thread->ReadGReg<UDWord_t> (rs2_addr));

  UDWord_t res;
  if (m_pe_thread->GetBitMode() == RiscvBitMode_t::Bit32) {
    res = m_pe_thread->SExtXlen(InstOps::UIntDiv32 (rs1_val, rs2_val));
  } else {
    res = InstOps::UIntDiv64 (rs1_val, rs2_val);
  }
  m_pe_thread->WriteGReg (rd_addr, res);
}



void InstEnv::RISCV_INST_REM (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  if (m_pe_thread->GetBitMode() == RiscvBitMode_t::Bit32) {
    Word_t rs1_val = m_pe_thread->ReadGReg<Word_t> (rs1_addr);
    Word_t rs2_val = m_pe_thread->ReadGReg<Word_t> (rs2_addr);

    Word_t res;
    if (rs2_val == 0) {
      res = rs1_val;
    } else if (rs2_val == -1) {
      res = 0;
    } else {
      res = rs1_val % rs2_val;
    }
    m_pe_thread->WriteGReg (rd_addr, res);
  } else {
    DWord_t rs1_val = m_pe_thread->ReadGReg<DWord_t> (rs1_addr);
    DWord_t rs2_val = m_pe_thread->ReadGReg<DWord_t> (rs2_addr);

    DWord_t res;
    if (rs2_val == 0) {
      res = rs1_val;
    } else if (rs2_val == -1) {
      res = 0;
    } else {
      res = rs1_val % rs2_val;
    }
    m_pe_thread->WriteGReg (rd_addr, res);
  }
}


void InstEnv::RISCV_INST_REMU (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  if (m_pe_thread->GetBitMode() == RiscvBitMode_t::Bit32) {
    UWord_t rs1_val  = m_pe_thread->ReadGReg<UWord_t> (rs1_addr);
    UWord_t rs2_val  = m_pe_thread->ReadGReg<UWord_t> (rs2_addr);

    UWord_t  res;
    if (rs2_val == 0) {
      res = rs1_val;
    // } else if (rs2_val == static_cast<UWord_t>(-1)) {
    //   res = rs1_val;
    } else {
      res = rs1_val % rs2_val;
    }
    m_pe_thread->WriteGReg (rd_addr, m_pe_thread->SExtXlen(res));
  } else {
    UDWord_t rs1_val  = m_pe_thread->ReadGReg<UDWord_t> (rs1_addr);
    UDWord_t rs2_val  = m_pe_thread->ReadGReg<UDWord_t> (rs2_addr);

    UDWord_t  res;
    if (rs2_val == 0) {
      res = rs1_val;
    // } else if (rs2_val == static_cast<UDWord_t>(-1)) {
    //   res = rs1_val;
    } else {
      res = rs1_val % rs2_val;
    }
    m_pe_thread->WriteGReg (rd_addr, res);
  }
}


void InstEnv::RISCV_INST_LR_W (InstWord_t inst_hex)
{
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);

  DWord_t rs1_val  = m_pe_thread->ReadGReg<DWord_t> (rs1_addr);

  Addr_t  mem_addr = m_pe_thread->UExtXlen (rs1_val);

  Word_t  res_32;
  MemResult except = m_pe_thread->LoadFromBus (mem_addr, &res_32);
  DWord_t res = res_32;  // just extending sign

  if (except == MemResult::MemMisAlign) {
    m_pe_thread->GenerateException (ExceptCode::Except_LoadAddrMisalign, mem_addr);
    return;
  }
  if (except == MemResult::MemTlbError) {
    m_pe_thread->GenerateException (ExceptCode::Except_LoadPageFault, mem_addr);
    return;
  }

  m_pe_thread->SetLoadReservation(mem_addr);
  m_pe_thread->WriteGReg (rd_addr, res);
}


void InstEnv::RISCV_INST_SC_W (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  Addr_t rs1_val = m_pe_thread->ReadGReg<Addr_t> (rs1_addr);
  Word_t rs2_val = m_pe_thread->ReadGReg<Word_t> (rs2_addr);

  Addr_t mem_addr = m_pe_thread->UExtXlen (rs1_val);

  if (m_pe_thread->GetLoadReservation() != mem_addr) {
    m_pe_thread->WriteGReg<Word_t> (rd_addr, 0x1);
    m_pe_thread->ClearLoadReservation();
    return;
  }

  MemResult except = m_pe_thread->StoreToBus (mem_addr, rs2_val);
  if (except == MemResult::MemMisAlign) {
    m_pe_thread->GenerateException (ExceptCode::Except_StoreAddrMisalign, mem_addr);
    return;
  }
  if (except == MemResult::MemTlbError) {
    m_pe_thread->GenerateException (ExceptCode::Except_StorePageFault, mem_addr);
    return;
  }
  m_pe_thread->WriteGReg<Word_t> (rd_addr, 0x0);

  m_pe_thread->ClearLoadReservation();
}


void InstEnv::RISCV_INST_AMOSWAP_W (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  DWord_t rs1_val = m_pe_thread->ReadGReg<DWord_t> (rs1_addr);
  Word_t rs2_val = m_pe_thread->ReadGReg<Word_t> (rs2_addr);

  Addr_t mem_addr = m_pe_thread->UExtXlen (rs1_val);
  MemResult except;
  Word_t mem;
  except = m_pe_thread->LoadFromBus (mem_addr, &mem);
  if (except == MemResult::MemMisAlign) {
    m_pe_thread->GenerateException (ExceptCode::Except_LoadAddrMisalign, mem_addr);
    return;
  }
  if (except == MemResult::MemTlbError) {
    m_pe_thread->GenerateException (ExceptCode::Except_LoadPageFault, mem_addr);
    return;
  }

  except = m_pe_thread->StoreToBus (mem_addr, rs2_val);
  if (except == MemResult::MemMisAlign) {
    m_pe_thread->GenerateException (ExceptCode::Except_StoreAddrMisalign, mem_addr);
    return;
  }
  if (except == MemResult::MemTlbError) {
    m_pe_thread->GenerateException (ExceptCode::Except_StorePageFault, mem_addr);
    return;
  }

  m_pe_thread->WriteGReg (rd_addr, mem);
}


void InstEnv::RISCV_INST_AMOADD_W (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  Addr_t rs1_val  = m_pe_thread->ReadGReg<Addr_t> (rs1_addr);
  Word_t rs2_val  = m_pe_thread->ReadGReg<Word_t> (rs2_addr);

  Addr_t mem_addr = m_pe_thread->UExtXlen (rs1_val);
  MemResult except;
  Word_t mem;
  except = m_pe_thread->LoadFromBus (mem_addr, &mem);
  if (except == MemResult::MemMisAlign) {
    m_pe_thread->GenerateException (ExceptCode::Except_LoadAddrMisalign, mem_addr);
    return;
  }
  if (except == MemResult::MemTlbError) {
    m_pe_thread->GenerateException (ExceptCode::Except_LoadPageFault, mem_addr);
    return;
  }

  Word_t ret = mem + rs2_val;

  except = m_pe_thread->StoreToBus (mem_addr, ret);
  if (except == MemResult::MemMisAlign) {
    m_pe_thread->GenerateException (ExceptCode::Except_StoreAddrMisalign, mem_addr);
    return;
  }
  if (except == MemResult::MemTlbError) {
    m_pe_thread->GenerateException (ExceptCode::Except_StorePageFault, mem_addr);
    return;
  }

  m_pe_thread->WriteGReg (rd_addr, mem);
}


void InstEnv::RISCV_INST_AMOXOR_W (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  DWord_t rs1_val  = m_pe_thread->ReadGReg<UDWord_t> (rs1_addr);
  UWord_t rs2_val  = m_pe_thread->ReadGReg<Word_t> (rs2_addr);

  Addr_t  mem_addr = m_pe_thread->UExtXlen (rs1_val);
  MemResult except;
  Word_t mem;
  except = m_pe_thread->LoadFromBus (mem_addr, &mem);
  if (except == MemResult::MemMisAlign) {
    m_pe_thread->GenerateException (ExceptCode::Except_LoadAddrMisalign, mem_addr);
    return;
  }
  if (except == MemResult::MemTlbError) {
    m_pe_thread->GenerateException (ExceptCode::Except_LoadPageFault, mem_addr);
    return;
  }

  Word_t ret = mem ^ rs2_val;

  except = m_pe_thread->StoreToBus (mem_addr, ret);
  if (except == MemResult::MemMisAlign) {
    m_pe_thread->GenerateException (ExceptCode::Except_StoreAddrMisalign, mem_addr);
    return;
  }
  if (except == MemResult::MemTlbError) {
    m_pe_thread->GenerateException (ExceptCode::Except_StorePageFault, mem_addr);
    return;
  }

  m_pe_thread->WriteGReg (rd_addr, mem);
}


void InstEnv::RISCV_INST_AMOAND_W (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  DWord_t rs1_val = m_pe_thread->ReadGReg<DWord_t> (rs1_addr);
  UWord_t  rs2_val = m_pe_thread->ReadGReg<Word_t> (rs2_addr);

  Addr_t  mem_addr = m_pe_thread->UExtXlen (rs1_val);

  MemResult except;
  Word_t mem;
  except = m_pe_thread->LoadFromBus (mem_addr, &mem);
  if (except == MemResult::MemMisAlign) {
    m_pe_thread->GenerateException (ExceptCode::Except_LoadAddrMisalign, mem_addr);
    return;
  }
  if (except == MemResult::MemTlbError) {
    m_pe_thread->GenerateException (ExceptCode::Except_LoadPageFault, mem_addr);
    return;
  }

  Word_t ret = mem & rs2_val;

  except = m_pe_thread->StoreToBus (mem_addr, ret);
  if (except == MemResult::MemMisAlign) {
    m_pe_thread->GenerateException (ExceptCode::Except_StoreAddrMisalign, mem_addr);
    return;
  }
  if (except == MemResult::MemTlbError) {
    m_pe_thread->GenerateException (ExceptCode::Except_StorePageFault, mem_addr);
    return;
  }

  m_pe_thread->WriteGReg (rd_addr, mem);
}


void InstEnv::RISCV_INST_AMOOR_W (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  DWord_t rs1_val  = m_pe_thread->ReadGReg<UDWord_t> (rs1_addr);
  UWord_t  rs2_val  = m_pe_thread->ReadGReg<Word_t> (rs2_addr);

  Addr_t  mem_addr = m_pe_thread->UExtXlen (rs1_val);

  MemResult except;
  Word_t mem;
  except = m_pe_thread->LoadFromBus (mem_addr, &mem);
  if (except == MemResult::MemMisAlign) {
    m_pe_thread->GenerateException (ExceptCode::Except_LoadAddrMisalign, mem_addr);
    return;
  }
  if (except == MemResult::MemTlbError) {
    m_pe_thread->GenerateException (ExceptCode::Except_LoadPageFault, mem_addr);
    return;
  }

  Word_t ret = mem | rs2_val;

  except = m_pe_thread->StoreToBus (mem_addr, ret);
  if (except == MemResult::MemMisAlign) {
    m_pe_thread->GenerateException (ExceptCode::Except_StoreAddrMisalign, mem_addr);
    return;
  }
  if (except == MemResult::MemTlbError) {
    m_pe_thread->GenerateException (ExceptCode::Except_StorePageFault, mem_addr);
    return;
  }

  m_pe_thread->WriteGReg (rd_addr, mem);
}


void InstEnv::RISCV_INST_AMOMIN_W (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  DWord_t rs1_val  = m_pe_thread->ReadGReg<UDWord_t> (rs1_addr);
  Word_t   rs2_val  = m_pe_thread->ReadGReg<Word_t> (rs2_addr);

  Addr_t  mem_addr = m_pe_thread->UExtXlen (rs1_val);

  MemResult except;
  Word_t mem;
  except = m_pe_thread->LoadFromBus (mem_addr, &mem);
  if (except == MemResult::MemMisAlign) {
    m_pe_thread->GenerateException (ExceptCode::Except_LoadAddrMisalign, mem_addr);
    return;
  }
  if (except == MemResult::MemTlbError) {
    m_pe_thread->GenerateException (ExceptCode::Except_LoadPageFault, mem_addr);
    return;
  }

  Word_t ret = (mem < rs2_val) ? mem : rs2_val;

  except = m_pe_thread->StoreToBus (mem_addr, ret);
  if (except == MemResult::MemMisAlign) {
    m_pe_thread->GenerateException (ExceptCode::Except_StoreAddrMisalign, mem_addr);
    return;
  }
  if (except == MemResult::MemTlbError) {
    m_pe_thread->GenerateException (ExceptCode::Except_StorePageFault, mem_addr);
    return;
  }

  m_pe_thread->WriteGReg (rd_addr, mem);
}


void InstEnv::RISCV_INST_AMOMAX_W (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  DWord_t rs1_val  = m_pe_thread->ReadGReg<UDWord_t> (rs1_addr);
  Word_t   rs2_val  = m_pe_thread->ReadGReg<Word_t> (rs2_addr);

  Addr_t  mem_addr = m_pe_thread->UExtXlen (rs1_val);

  MemResult except;
  Word_t mem;
  except = m_pe_thread->LoadFromBus (mem_addr, &mem);
  if (except == MemResult::MemMisAlign) {
    m_pe_thread->GenerateException (ExceptCode::Except_LoadAddrMisalign, mem_addr);
    return;
  }
  if (except == MemResult::MemTlbError) {
    m_pe_thread->GenerateException (ExceptCode::Except_LoadPageFault, mem_addr);
    return;
  }

  Word_t ret = (mem < rs2_val) ? rs2_val : mem;

  except = m_pe_thread->StoreToBus (mem_addr, ret);
  if (except == MemResult::MemMisAlign) {
    m_pe_thread->GenerateException (ExceptCode::Except_StoreAddrMisalign, mem_addr);
    return;
  }
  if (except == MemResult::MemTlbError) {
    m_pe_thread->GenerateException (ExceptCode::Except_StorePageFault, mem_addr);
    return;
  }

  m_pe_thread->WriteGReg (rd_addr, mem);
}


void InstEnv::RISCV_INST_AMOMINU_W (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  DWord_t rs1_val  = m_pe_thread->ReadGReg<UDWord_t> (rs1_addr);
  UWord_t  rs2_val  = m_pe_thread->ReadGReg<UWord_t> (rs2_addr);

  Addr_t  mem_addr = m_pe_thread->UExtXlen (rs1_val);

  MemResult except;
  Word_t mem;
  except = m_pe_thread->LoadFromBus (mem_addr, &mem);
  if (except == MemResult::MemMisAlign) {
    m_pe_thread->GenerateException (ExceptCode::Except_LoadAddrMisalign, mem_addr);
    return;
  }
  if (except == MemResult::MemTlbError) {
    m_pe_thread->GenerateException (ExceptCode::Except_LoadPageFault, mem_addr);
    return;
  }

  UWord_t mem_u = static_cast<UWord_t>(mem);
  UWord_t ret = (mem_u < rs2_val) ? mem_u : rs2_val;

  except = m_pe_thread->StoreToBus (mem_addr, ret);
  if (except == MemResult::MemMisAlign) {
    m_pe_thread->GenerateException (ExceptCode::Except_StoreAddrMisalign, mem_addr);
    return;
  }
  if (except == MemResult::MemTlbError) {
    m_pe_thread->GenerateException (ExceptCode::Except_StorePageFault, mem_addr);
    return;
  }

  m_pe_thread->WriteGReg (rd_addr, mem);
}


void InstEnv::RISCV_INST_AMOMAXU_W (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  DWord_t rs1_val  = m_pe_thread->ReadGReg<UDWord_t> (rs1_addr);
  UWord_t rs2_val  = m_pe_thread->ReadGReg<UWord_t> (rs2_addr);

  Addr_t  mem_addr = m_pe_thread->UExtXlen (rs1_val);

  MemResult except;
  Word_t mem;
  except = m_pe_thread->LoadFromBus (mem_addr, &mem);
  if (except == MemResult::MemMisAlign) {
    m_pe_thread->GenerateException (ExceptCode::Except_LoadAddrMisalign, mem_addr);
    return;
  }
  if (except == MemResult::MemTlbError) {
    m_pe_thread->GenerateException (ExceptCode::Except_LoadPageFault, mem_addr);
    return;
  }

  UWord_t mem_u = static_cast<UWord_t>(mem);
  UWord_t ret = (mem_u < rs2_val) ? rs2_val : mem_u;

  except = m_pe_thread->StoreToBus (mem_addr, ret);
  if (except == MemResult::MemMisAlign) {
    m_pe_thread->GenerateException (ExceptCode::Except_StoreAddrMisalign, mem_addr);
    return;
  }
  if (except == MemResult::MemTlbError) {
    m_pe_thread->GenerateException (ExceptCode::Except_StorePageFault, mem_addr);
    return;
  }

  m_pe_thread->WriteGReg (rd_addr, mem);
}


void InstEnv::RISCV_INST_FLW (InstWord_t inst_hex)
{
  if (!m_pe_thread->IsFPAvailable ()) {
    m_pe_thread->GenerateException (ExceptCode::Except_IllegalInst, 0);
    return;
  }

  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  DWord_t rs1_val  = m_pe_thread->ReadGReg<UDWord_t> (rs1_addr);
  DWord_t  imm      = ExtractIField (inst_hex);

  Addr_t  mem_addr = m_pe_thread->UExtXlen (rs1_val + imm);

  Word_t  res;
  MemResult except = m_pe_thread->LoadFromBus (mem_addr, &res);
  if (except == MemResult::MemMisAlign) {
    m_pe_thread->GenerateException (ExceptCode::Except_LoadAddrMisalign, mem_addr);
    return;
  }
  if (except == MemResult::MemTlbError) {
    m_pe_thread->GenerateException (ExceptCode::Except_LoadPageFault, mem_addr);
    return;
  }

  UDWord_t res_64= static_cast<UDWord_t>(res) | 0xffffffff00000000ULL;
  m_pe_thread->WriteFReg<UDWord_t> (rd_addr, res_64);
}


void InstEnv::RISCV_INST_FSW (InstWord_t inst_hex)
{
  if (!m_pe_thread->IsFPAvailable ()) {
    m_pe_thread->GenerateException (ExceptCode::Except_IllegalInst, 0);
    return;
  }

  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);

  DWord_t rs1_val  = m_pe_thread->ReadGReg<UDWord_t> (rs1_addr);
  Word_t  rs2_val  = m_pe_thread->ReadFReg<Word_t> (rs2_addr);
  DWord_t imm    = ExtractSField (inst_hex);

  Addr_t  mem_addr = m_pe_thread->UExtXlen (rs1_val + imm);

  MemResult except = m_pe_thread->StoreToBus (mem_addr, rs2_val);
  if (except == MemResult::MemMisAlign) {
    m_pe_thread->GenerateException (ExceptCode::Except_StoreAddrMisalign, mem_addr);
    return;
  }
  if (except == MemResult::MemTlbError) {
    m_pe_thread->GenerateException (ExceptCode::Except_StorePageFault, mem_addr);
    return;
  }
}


void InstEnv::RISCV_INST_FMV_X_W (InstWord_t inst_hex)
{
  RegAddr_t fs_addr = ExtractR1Field (inst_hex);
  RegAddr_t fd_addr = ExtractRDField (inst_hex);

  Word_t fs_val = m_pe_thread->ReadFReg<Word_t> (fs_addr);
  m_pe_thread->WriteGReg<DWord_t> (fd_addr, fs_val);
}


void InstEnv::RISCV_INST_FCLASS_S (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  Word_t rs1_val  = m_pe_thread->ReadFReg<Word_t> (rs1_addr);

  Word_t sign_bit = ExtractBitField (rs1_val, 31, 31);
  Word_t exp_bit  = ExtractBitField (rs1_val, 30, 23);
  Word_t frac_bit = ExtractBitField (rs1_val, 22,  0);

  Word_t res = 0;

  // Negative Inifite
  if (sign_bit == 1 && exp_bit == 0xFF && frac_bit == 0x00) {
    res |= 1;
  }
  // Negative Normal Number
  if (sign_bit == 1 && (exp_bit != 0x00 && exp_bit != 0xFF)) {
    res |= 2;
  }
  // Negative Normal Number
  if (sign_bit == 1 && exp_bit == 0x00 && frac_bit != 0x00) {
    res |= 4;
  }
  // Negative Zero
  if (sign_bit == 1 && exp_bit == 0x00 && frac_bit == 0x00) {
    res |= 8;
  }
  // Plus Zero
  if (sign_bit == 0 && exp_bit == 0x00 && frac_bit == 0x00) {
    res |= 16;
  }
  // Plus Normal Number
  if (sign_bit == 0 && exp_bit == 0x00 && frac_bit != 0x00) {
    res |= 32;
  }
  // Plus Normal Number
  if (sign_bit == 0 && (exp_bit != 0x00 && exp_bit != 0xFF)) {
    res |= 64;
  }
  // Plus Inifite
  if (sign_bit == 0 && exp_bit == 0xFF && frac_bit == 0x00) {
    res |= 128;
  }
  // Signaling NaN
  if (exp_bit == 0xFF && frac_bit != 0x00 && ExtractBitField (frac_bit, 22, 22) == 0) {
    res |= 256;
  }
  // Quiet NaN
  if (exp_bit == 0xFF && frac_bit != 0x00 && ExtractBitField (frac_bit, 22, 22) == 1) {
    res |= 512;
  }

  m_pe_thread->WriteGReg (rd_addr, res);

}


void InstEnv::RISCV_INST_FCVT_S_W (InstWord_t inst_hex)
{
  RegAddr_t fs_addr = ExtractR1Field (inst_hex);
  RegAddr_t fd_addr = ExtractRDField (inst_hex);
  uint8_t   round_mode = m_pe_thread->EncodeRMField(ExtractF3Field (inst_hex));

  Word_t   fs_val  = m_pe_thread->ReadGReg<Word_t> (fs_addr);
  UWord_t  fflags;
  DWord_t  fs_res  = InstOps::Convert_WtoS (fs_val, round_mode, &fflags);
  fs_res |= 0xffffffff00000000ULL;

  m_pe_thread->WriteFReg<DWord_t> (fd_addr, fs_res);
  m_pe_thread->CSRWrite (static_cast<Addr_t>(SYSREG_ADDR_FFLAGS), fflags);
}


void InstEnv::RISCV_INST_FCVT_S_WU (InstWord_t inst_hex)
{
  RegAddr_t fs_addr = ExtractR1Field (inst_hex);
  RegAddr_t fd_addr = ExtractRDField (inst_hex);
  uint8_t   round_mode = m_pe_thread->EncodeRMField(ExtractF3Field (inst_hex));

  UDWord_t fs_val  = m_pe_thread->ReadGReg<UDWord_t> (fs_addr);
  UWord_t fflags;
  DWord_t  fs_res  = InstOps::Convert_WUtoS (fs_val, round_mode, &fflags);
  fs_res |= 0xffffffff00000000ULL;

  m_pe_thread->WriteFReg<DWord_t> (fd_addr, fs_res);
  m_pe_thread->CSRWrite (static_cast<Addr_t>(SYSREG_ADDR_FFLAGS), fflags);
}


void InstEnv::RISCV_INST_FMV_W_X (InstWord_t inst_hex)
{
  RegAddr_t fs_addr = ExtractR1Field (inst_hex);
  RegAddr_t fd_addr = ExtractRDField (inst_hex);

  DWord_t   fs_val  = m_pe_thread->ReadGReg<Word_t> (fs_addr);
  fs_val |= 0xFFFFFFFF00000000ULL; // Boxing
  m_pe_thread->WriteFReg<DWord_t> (fd_addr, fs_val);
}


void InstEnv::RISCV_INST_FLD (InstWord_t inst_hex)
{
  if (!m_pe_thread->IsFPAvailable ()) { return; }

  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  DWord_t rs1_val  = m_pe_thread->ReadGReg<DWord_t> (rs1_addr);
  DWord_t imm      = ExtractIField (inst_hex);

  Addr_t  mem_addr = m_pe_thread->UExtXlen (rs1_val + imm);


  DWord_t  res;
  MemResult except = m_pe_thread->LoadFromBus (mem_addr, &res);

  if (except == MemResult::MemMisAlign) {
    m_pe_thread->GenerateException (ExceptCode::Except_LoadAddrMisalign, mem_addr);
    return;
  }
  if (except == MemResult::MemTlbError) {
    m_pe_thread->GenerateException (ExceptCode::Except_LoadPageFault, mem_addr);
    return;
  }

  m_pe_thread->WriteFReg<DWord_t> (rd_addr, res);

}


void InstEnv::RISCV_INST_FSD (InstWord_t inst_hex)
{
  if (!m_pe_thread->IsFPAvailable ()) { return; }

  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);

  DWord_t  rs1_val  = m_pe_thread->ReadGReg<DWord_t> (rs1_addr);
  DWord_t rs2_val  = m_pe_thread->ReadFReg<UDWord_t> (rs2_addr);
  DWord_t  imm    = ExtractSField (inst_hex);

  Addr_t  mem_addr = m_pe_thread->UExtXlen (rs1_val + imm);

  Word_t rs2_hi = (rs2_val >> 32) & 0x0FFFFFFFFULL;
  Word_t rs2_lo = rs2_val & 0x0FFFFFFFFULL;

  MemResult except = MemResult::MemNoExcept;
  except = m_pe_thread->StoreToBus (mem_addr + 0, rs2_lo);
  except = m_pe_thread->StoreToBus (mem_addr + 4, rs2_hi);
  if (except == MemResult::MemMisAlign) {
    m_pe_thread->GenerateException (ExceptCode::Except_StoreAddrMisalign, mem_addr);
    return;
  }
  if (except == MemResult::MemTlbError) {
    m_pe_thread->GenerateException (ExceptCode::Except_StorePageFault, mem_addr);
    return;
  }
}


void InstEnv::RISCV_INST_FCVT_S_D (InstWord_t inst_hex)
{
  RegAddr_t fs_addr = ExtractR1Field (inst_hex);
  RegAddr_t fd_addr = ExtractRDField (inst_hex);
  uint8_t   round_mode = m_pe_thread->EncodeRMField(ExtractF3Field (inst_hex));

  DWord_t fs_val  = m_pe_thread->ReadFReg<DWord_t> (fs_addr);
  UWord_t fflags;
  DWord_t fs_res  = InstOps::Convert_DtoS (fs_val, round_mode, &fflags);
  fs_res |= 0xffffffff00000000ULL;

  m_pe_thread->WriteFReg<DWord_t> (fd_addr, fs_res);
  m_pe_thread->CSRWrite (static_cast<Addr_t>(SYSREG_ADDR_FFLAGS), fflags);
}


void InstEnv::RISCV_INST_FCVT_D_S (InstWord_t inst_hex)
{
  RegAddr_t fs_addr = ExtractR1Field (inst_hex);
  RegAddr_t fd_addr = ExtractRDField (inst_hex);
  uint8_t   round_mode = m_pe_thread->EncodeRMField(ExtractF3Field (inst_hex));

  Word_t  fs_val  = m_pe_thread->ReadFReg<Word_t> (fs_addr);
  UWord_t fflags;
  DWord_t fs_res  = InstOps::Convert_StoD (fs_val, round_mode, &fflags);

  m_pe_thread->WriteFReg<DWord_t> (fd_addr, fs_res);
  m_pe_thread->CSRWrite (static_cast<Addr_t>(SYSREG_ADDR_FFLAGS), fflags);
}


void InstEnv::RISCV_INST_FCLASS_D (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  DWord_t rs1_val  = m_pe_thread->ReadFReg<DWord_t> (rs1_addr);

  DWord_t sign_bit = ExtractBitField (rs1_val, 63, 63);
  DWord_t exp_bit  = ExtractBitField (rs1_val, 62, 52);
  DWord_t frac_bit = ExtractBitField (rs1_val, 51,  0);

  Word_t res = 0;

  // Negative Inifite
  if (sign_bit == 1 && exp_bit == 0x7FF && frac_bit == 0x00) {
    res |= 1;
  }
  // Negative Normal Number
  if (sign_bit == 1 && (exp_bit != 0x00 && exp_bit != 0x7FF)) {
    res |= 2;
  }
  // Negative Normal Number
  if (sign_bit == 1 && exp_bit == 0x00 && frac_bit != 0x00) {
    res |= 4;
  }
  // Negative Zero
  if (sign_bit == 1 && exp_bit == 0x00 && frac_bit == 0x00) {
    res |= 8;
  }
  // Plus Zero
  if (sign_bit == 0 && exp_bit == 0x00 && frac_bit == 0x00) {
    res |= 16;
  }
  // Plus Normal Number
  if (sign_bit == 0 && exp_bit == 0x00 && frac_bit != 0x00) {
    res |= 32;
  }
  // Plus Normal Number
  if (sign_bit == 0 && (exp_bit != 0x00 && exp_bit != 0x7FF)) {
    res |= 64;
  }
  // Plus Inifite
  if (sign_bit == 0 && exp_bit == 0x7FF && frac_bit == 0x00) {
    res |= 128;
  }
  // Signaling NaN
  if (exp_bit == 0x7FF && frac_bit != 0x00 && ExtractBitField (frac_bit, 51, 51) == 0) {
    res |= 256;
  }
  // Quiet NaN
  if (exp_bit == 0x7FF && frac_bit != 0x00 && ExtractBitField (frac_bit, 51, 51) == 1) {
    res |= 512;
  }

  m_pe_thread->WriteGReg (rd_addr, res);

}


void InstEnv::RISCV_INST_FCVT_W_D (InstWord_t inst_hex)
{
  RegAddr_t fs_addr = ExtractR1Field (inst_hex);
  RegAddr_t fd_addr = ExtractRDField (inst_hex);
  uint8_t   round_mode = m_pe_thread->EncodeRMField(ExtractF3Field (inst_hex));

  DWord_t  fs_val  = m_pe_thread->ReadFReg<DWord_t> (fs_addr);
  UWord_t  fflags;
  Word_t   fs_res  = InstOps::Convert_DtoW (fs_val, round_mode, &fflags);

  m_pe_thread->WriteGReg<Word_t> (fd_addr, fs_res);
  m_pe_thread->CSRWrite (static_cast<Addr_t>(SYSREG_ADDR_FFLAGS), fflags);
}


void InstEnv::RISCV_INST_FCVT_WU_D (InstWord_t inst_hex)
{
  RegAddr_t fs_addr = ExtractR1Field (inst_hex);
  RegAddr_t fd_addr = ExtractRDField (inst_hex);
  uint8_t   round_mode = m_pe_thread->EncodeRMField(ExtractF3Field (inst_hex));

  DWord_t fs_val  = m_pe_thread->ReadFReg<DWord_t> (fs_addr);
  UWord_t fflags;
  Word_t fs_res  = InstOps::Convert_DtoWU (fs_val, round_mode, &fflags);

  m_pe_thread->WriteGReg<Word_t> (fd_addr, fs_res);
  m_pe_thread->CSRWrite (static_cast<Addr_t>(SYSREG_ADDR_FFLAGS), fflags);
}


void InstEnv::RISCV_INST_FCVT_D_W (InstWord_t inst_hex)
{
  RegAddr_t fs_addr = ExtractR1Field (inst_hex);
  RegAddr_t fd_addr = ExtractRDField (inst_hex);
  uint8_t   round_mode = m_pe_thread->EncodeRMField(ExtractF3Field (inst_hex));

  Word_t  fs_val  = m_pe_thread->ReadGReg<Word_t> (fs_addr);
  UWord_t fflags;
  DWord_t fs_res  = InstOps::Convert_WtoD (fs_val, round_mode, &fflags);

  m_pe_thread->WriteFReg<DWord_t> (fd_addr, fs_res);
  m_pe_thread->CSRWrite (static_cast<Addr_t>(SYSREG_ADDR_FFLAGS), fflags);
}


void InstEnv::RISCV_INST_FCVT_D_WU (InstWord_t inst_hex)
{
  RegAddr_t fs_addr = ExtractR1Field (inst_hex);
  RegAddr_t fd_addr = ExtractRDField (inst_hex);
  uint8_t   round_mode = m_pe_thread->EncodeRMField(ExtractF3Field (inst_hex));

  UWord_t fs_val  = m_pe_thread->ReadGReg<UWord_t> (fs_addr);
  UWord_t fflags;
  DWord_t fs_res  = InstOps::Convert_WUtoD (fs_val, round_mode, &fflags);

  m_pe_thread->WriteFReg<DWord_t> (fd_addr, fs_res);
  m_pe_thread->CSRWrite (static_cast<Addr_t>(SYSREG_ADDR_FFLAGS), fflags);
}


void InstEnv::RISCV_INST_CSRRW (InstWord_t inst_hex)
{
  DWord_t   csr_addr = ExtractBitField (inst_hex, 31, 20);
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  DWord_t csr_val;
  if (m_pe_thread->CSRRead (csr_addr, &csr_val) != 0) {
    m_pe_thread->GenerateException (ExceptCode::Except_IllegalInst, 0);
    return;
  }

  DWord_t rs1_val  = m_pe_thread->ReadGReg<DWord_t> (rs1_addr);

  if (m_pe_thread->CSRWrite (csr_addr, rs1_val) == -1) {
    m_pe_thread->GenerateException (ExceptCode::Except_IllegalInst, 0);
    return;
  }
  m_pe_thread->WriteGReg<DWord_t> (rd_addr, csr_val);
}


void InstEnv::RISCV_INST_CSRRS (InstWord_t inst_hex)
{
  // xxx temporary implementation of CSRRS

  DWord_t   csr_addr = ExtractBitField (inst_hex, 31, 20);
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  DWord_t  rs1_val = m_pe_thread->ReadGReg<DWord_t> (rs1_addr);
  DWord_t csr_val;
  if (m_pe_thread->CSRRead (csr_addr, &csr_val) != 0) {
    m_pe_thread->GenerateException (ExceptCode::Except_IllegalInst, 0);
    return;
  }

  if (rs1_addr != 0) {
    if (rs1_val == 0) {
      m_pe_thread->CSRWrite (csr_addr, csr_val);
    } else {
      DWord_t next_csr_val = csr_val | rs1_val;
      if (m_pe_thread->CSRWrite (csr_addr, next_csr_val) != 0) {
        m_pe_thread->GenerateException (ExceptCode::Except_IllegalInst, 0);
        return;
      }
    }
  }
  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, csr_val);
}


void InstEnv::RISCV_INST_CSRRC (InstWord_t inst_hex)
{
  // xxx temporary implementation of CSRRC

  DWord_t   csr_addr = ExtractBitField (inst_hex, 31, 20);
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  DWord_t rs1_val = m_pe_thread->ReadGReg<Word_t> (rs1_addr);
  DWord_t csr_val;
  DWord_t csr_status = m_pe_thread->CSRRead (csr_addr, &csr_val);

  if (csr_status != 0) {
    m_pe_thread->GenerateException (ExceptCode::Except_IllegalInst, 0);
    return;
  }

  if (rs1_addr != 0) {
    if (rs1_val == 0) {
      m_pe_thread->CSRWrite (csr_addr, csr_val);
    } else {
      DWord_t next_csr_val = csr_val & ~rs1_val;
      if (m_pe_thread->CSRWrite (csr_addr, next_csr_val) != 0) {
        return;
      }
    }
  }
  m_pe_thread->WriteGReg (rd_addr, csr_val);
}


void InstEnv::RISCV_INST_CSRRWI (InstWord_t inst_hex)
{
  // xxx temporary implementation of CSRRWI

  RegAddr_t rd_addr  = ExtractRDField (inst_hex);
  DWord_t   csr_addr = ExtractBitField (inst_hex, 31, 20);
  DWord_t   z_imm    = ExtractBitField (inst_hex, 19, 15);

  DWord_t csr_val;
  if (m_pe_thread->CSRRead (csr_addr, &csr_val) != 0) {
    m_pe_thread->GenerateException (ExceptCode::Except_IllegalInst, 0);
    return;
  }
  if (m_pe_thread->CSRWrite (csr_addr, z_imm) == -1) {
    m_pe_thread->GenerateException (ExceptCode::Except_IllegalInst, 0);
    return;
  }
  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, csr_val);
}


void InstEnv::RISCV_INST_CSRRSI (InstWord_t inst_hex)
{
  // xxx temporary implementation of CSRRSI

  RegAddr_t rd_addr  = ExtractRDField (inst_hex);
  DWord_t   csr_addr = ExtractBitField (inst_hex, 31, 20);
  DWord_t   z_imm  = ExtractBitField (inst_hex, 19, 15);

  DWord_t csr_val;
  if (m_pe_thread->CSRRead (csr_addr, &csr_val) != 0) {
    m_pe_thread->GenerateException (ExceptCode::Except_IllegalInst, 0);
    return;
  }
  if (z_imm != 0) {
    DWord_t next_csr_val  = z_imm | csr_val;
    if (m_pe_thread->CSRWrite (csr_addr, next_csr_val) != 0) {
      m_pe_thread->GenerateException (ExceptCode::Except_IllegalInst, 0);
      return;
    }
  }
  m_pe_thread->WriteGReg (rd_addr, csr_val);
}


void InstEnv::RISCV_INST_CSRRCI (InstWord_t inst_hex)
{
  // xxx temporary implementation of CSRRCI

  RegAddr_t rd_addr  = ExtractRDField (inst_hex);
  DWord_t   csr_addr = ExtractBitField (inst_hex, 31, 20);
  DWord_t   z_imm  = ExtractBitField (inst_hex, 19, 15);

  DWord_t csr_val;
  if (m_pe_thread->CSRRead (csr_addr, &csr_val) != 0) {
    m_pe_thread->GenerateException (ExceptCode::Except_IllegalInst, 0);
    return;
  }
  if (z_imm != 0) {
    DWord_t next_csr_val  = ~z_imm & csr_val;
    if (m_pe_thread->CSRWrite (csr_addr, next_csr_val) != 0) {
      m_pe_thread->GenerateException (ExceptCode::Except_IllegalInst, 0);
      return;
    }
  }
  m_pe_thread->WriteGReg (rd_addr, csr_val);
}


void InstEnv::RISCV_INST_ECALL (InstWord_t inst_hex)
{
  Addr_t current_pc = m_pe_thread->GetPC ();

  m_pe_thread->CSRWrite (SYSREG_ADDR_MEPC, current_pc);

  PrivMode curr_priv = m_pe_thread->GetPrivMode ();

  switch (curr_priv) {
    case PrivMode::PrivUser     : {
      m_pe_thread->GenerateException (ExceptCode::Except_EcallFromUMode, 0);

      break;
    }
    case PrivMode::PrivSupervisor : {
      m_pe_thread->GenerateException (ExceptCode::Except_EcallFromSMode, 0);

      break;
    }
    case PrivMode::PrivHypervisor : {
      m_pe_thread->GenerateException (ExceptCode::Except_EcallFromHMode, 0);

      break;
    }
    case PrivMode::PrivMachine  : {
      m_pe_thread->GenerateException (ExceptCode::Except_EcallFromMMode, 0);

      break;
    }
    default : {
      m_pe_thread->DebugPrint ("<Internal Error: unrecognized PrivMode=%d\n", static_cast<int>(curr_priv));
    }
  }

  m_pe_thread->HandleCommand ();

}


void InstEnv::RISCV_INST_EBREAK (InstWord_t inst_hex)
{
  m_pe_thread->GenerateException (ExceptCode::Except_Breakpoint, 0);
  return;
}


void InstEnv::RISCV_INST_MRET (InstWord_t inst_hex)
{
  Addr_t ret_pc = 0x0;

  UDWord_t mstatus;
  if (m_pe_thread->CSRRead (static_cast<Addr_t>(SYSREG_ADDR_MSTATUS), &mstatus) == static_cast<uint32_t>(-1)) {
    m_pe_thread->GenerateException (ExceptCode::Except_IllegalInst, 0);
    return;
  }

  PrivMode next_priv_field = static_cast<PrivMode>(ExtractBitField(mstatus, SYSREG_MSTATUS_MPP_MSB, SYSREG_MSTATUS_MPP_LSB));
  UDWord_t next_mstatus = mstatus;
  next_mstatus = SetBitField (next_mstatus, ExtractBitField(mstatus, SYSREG_MSTATUS_MPIE_MSB, SYSREG_MSTATUS_MPIE_LSB),  SYSREG_MSTATUS_MIE_MSB, SYSREG_MSTATUS_MIE_LSB);
  next_mstatus = SetBitField (next_mstatus, 1,  SYSREG_MSTATUS_MPIE_MSB, SYSREG_MSTATUS_MPIE_LSB);
  next_mstatus = SetBitField (next_mstatus, 0,  SYSREG_MSTATUS_MPP_MSB,  SYSREG_MSTATUS_MPP_LSB );
  m_pe_thread->CSRWrite (static_cast<Addr_t>(SYSREG_ADDR_MSTATUS), next_mstatus);

  m_pe_thread->DebugPrint ("<Info: CPU mode changed from MachineMode to %s>\n",
                           m_pe_thread->PrintPrivMode (next_priv_field).c_str());
  if (m_pe_thread->CSRRead (static_cast<Addr_t>(SYSREG_ADDR_MEPC), &ret_pc) == static_cast<uint32_t>(-1)) {
    m_pe_thread->GenerateException (ExceptCode::Except_IllegalInst, 0);
    return;
  }
  // if (!m_pe_thread->IsSupportCMode()) {
  //   ret_pc = ret_pc & ~0x03ULL;  // If Compress Mode is disabled, return PC should be 4-byte aligned.
  // }
  ret_pc = m_pe_thread->UExtXlen (ret_pc & (~0x01));

  m_pe_thread->SetPrivMode (next_priv_field);
  m_pe_thread->SetPC (m_pe_thread->UExtXlen(ret_pc));
  m_pe_thread->SetJumped (true);
}


void InstEnv::RISCV_INST_SRET (InstWord_t inst_hex)
{
  PrivMode prev_privmode = m_pe_thread->GetPrivMode();
  m_pe_thread->SetPrivMode (PrivMode::PrivMachine);   // Temporary Change Machine

  UDWord_t mstatus;
  if (m_pe_thread->CSRRead (static_cast<Addr_t>(SYSREG_ADDR_MSTATUS), &mstatus) == static_cast<uint32_t>(-1)) {
    m_pe_thread->SetPrivMode (prev_privmode);
    m_pe_thread->GenerateException (ExceptCode::Except_IllegalInst, 0);
    return;
  }
  m_pe_thread->SetPrivMode (prev_privmode);

  PrivMode next_priv = static_cast<PrivMode>(ExtractBitField(mstatus, SYSREG_MSTATUS_SPP_MSB, SYSREG_MSTATUS_SPP_LSB));
  UDWord_t next_mstatus = mstatus;
  next_mstatus = SetBitField (next_mstatus, ExtractBitField(mstatus, SYSREG_MSTATUS_SPIE_MSB, SYSREG_MSTATUS_SPIE_LSB),
							  SYSREG_MSTATUS_SIE_MSB, SYSREG_MSTATUS_SIE_LSB);
  next_mstatus = SetBitField (next_mstatus, 1, SYSREG_MSTATUS_SPIE_MSB, SYSREG_MSTATUS_SPIE_LSB);
  next_mstatus = SetBitField (next_mstatus, static_cast<uint64_t>(PrivMode::PrivUser), SYSREG_MSTATUS_SPP_MSB, SYSREG_MSTATUS_SPP_LSB);

  m_pe_thread->CSRWrite (SYSREG_ADDR_MSTATUS, next_mstatus);

  m_pe_thread->DebugPrint ("<Info: CPU mode changed from %s to %s>\n",
                           m_pe_thread->PrintPrivMode (m_pe_thread->GetPrivMode()).c_str(),
                           m_pe_thread->PrintPrivMode (next_priv).c_str());

  Addr_t ret_pc = 0x0;
  m_pe_thread->CSRRead (static_cast<Addr_t>(SYSREG_ADDR_SEPC), &ret_pc);
  if (!m_pe_thread->IsSupportCMode()) {
    ret_pc = ret_pc & ~0x03ULL;  // If Compress Mode is disabled, return PC should be 4-byte aligned.
  }
  m_pe_thread->SetPrivMode (next_priv);

  m_pe_thread->SetPC (m_pe_thread->UExtXlen(ret_pc));
  m_pe_thread->SetJumped (true);
}


void InstEnv::RISCV_INST_HRET (InstWord_t inst_hex)
{
  Addr_t ret_pc = 0x0;

  UDWord_t hstatus;
  if (m_pe_thread->CSRRead (static_cast<Addr_t>(SYSREG_ADDR_HSTATUS), &hstatus) == static_cast<uint32_t>(-1)) {
    m_pe_thread->GenerateException (ExceptCode::Except_IllegalInst, 0);
    return;
  }

  PrivMode next_priv_field = static_cast<PrivMode>((hstatus >> 8) & 1);
  UDWord_t next_hstatus = ((hstatus & 0x0ffff) >> 3) | (hstatus & 0xffff0000);
  m_pe_thread->CSRWrite (SYSREG_ADDR_HSTATUS, next_hstatus);

  m_pe_thread->DebugPrint ("<Info: CPU mode changed from HypervisorMode to %s>\n",
                     m_pe_thread->PrintPrivMode (next_priv_field).c_str());
  if (m_pe_thread->CSRRead (static_cast<Addr_t>(SYSREG_ADDR_SEPC), &ret_pc) == static_cast<uint32_t>(-1)) {
    m_pe_thread->GenerateException (ExceptCode::Except_IllegalInst, 0);
    return;
  }
  if (!m_pe_thread->IsSupportCMode()) {
    ret_pc = ret_pc & ~0x03ULL;  // If Compress Mode is disabled, return PC should be 4-byte aligned.
  }
  m_pe_thread->SetPrivMode (next_priv_field);

  m_pe_thread->SetPC (m_pe_thread->UExtXlen(ret_pc));
  m_pe_thread->SetJumped (true);
}


void InstEnv::RISCV_INST_URET (InstWord_t inst_hex)
{
  Addr_t ret_pc = 0x0;

  UDWord_t ustatus;
  if (m_pe_thread->CSRRead (static_cast<Addr_t>(SYSREG_ADDR_USTATUS), &ustatus) == static_cast<uint32_t>(-1)) {
    m_pe_thread->GenerateException (ExceptCode::Except_IllegalInst, 0);
    return;
  }

  // PrivMode next_priv_field = static_cast<PrivMode>((ustatus >> 4) & 3);
  UDWord_t next_ustatus = ((ustatus & 0x0ffff) >> 3) | (ustatus & 0xffff0000);
  m_pe_thread->CSRWrite (SYSREG_ADDR_USTATUS, next_ustatus);

  m_pe_thread->DebugPrint ("<Error: ERET in UserMode is prohibited>\n");

  m_pe_thread->SetPC (m_pe_thread->UExtXlen(ret_pc));
  m_pe_thread->SetJumped (true);
}


void InstEnv::RISCV_INST_MRTS (InstWord_t inst_hex)
{
  DWord_t mepc, mcause, mbadaddr;
  DWord_t csr_status = 0;
  csr_status |= m_pe_thread->CSRRead (static_cast<Addr_t>(SYSREG_ADDR_MEPC), &mepc);
  csr_status |= m_pe_thread->CSRRead (static_cast<Addr_t>(SYSREG_ADDR_MCAUSE), &mcause);
  csr_status |= m_pe_thread->CSRRead (static_cast<Addr_t>(SYSREG_ADDR_MTVAL), &mbadaddr);
  m_pe_thread->CSRWrite (SYSREG_ADDR_SEPC,   mepc);
  m_pe_thread->CSRWrite (SYSREG_ADDR_SCAUSE, mcause);
  m_pe_thread->CSRWrite (SYSREG_ADDR_STVAL,  mbadaddr);

  UDWord_t stvec;
  csr_status = m_pe_thread->CSRRead (static_cast<Addr_t>(SYSREG_ADDR_STVEC), &stvec);

  m_pe_thread->SetPrivMode (PrivMode::PrivSupervisor);

  UDWord_t sstatus;
  m_pe_thread->CSRRead (static_cast<Addr_t>(SYSREG_ADDR_SSTATUS), &sstatus);
  sstatus |= 0x10;  // SSTATUS.PS = 1
  m_pe_thread->CSRWrite (SYSREG_ADDR_SSTATUS, sstatus);

  m_pe_thread->SetPC (m_pe_thread->UExtXlen(stvec));
  m_pe_thread->SetJumped (true);
}


void InstEnv::RISCV_INST_MRTH (InstWord_t inst_hex)
{
  UDWord_t mepc, mcause, mbadaddr;
  UDWord_t csr_status = 0;
  csr_status |= m_pe_thread->CSRRead (static_cast<Addr_t>(SYSREG_ADDR_MEPC), &mepc);
  csr_status |= m_pe_thread->CSRRead (static_cast<Addr_t>(SYSREG_ADDR_MCAUSE), &mcause);
  csr_status |= m_pe_thread->CSRRead (static_cast<Addr_t>(SYSREG_ADDR_MTVAL), &mbadaddr);
  m_pe_thread->CSRWrite (SYSREG_ADDR_HEPC,   mepc);
  m_pe_thread->CSRWrite (SYSREG_ADDR_HCAUSE,   mcause);
  m_pe_thread->CSRWrite (SYSREG_ADDR_HBADADDR, mbadaddr);

  UDWord_t htvec;
  csr_status = m_pe_thread->CSRRead (static_cast<Addr_t>(SYSREG_ADDR_HTVEC), &htvec);

  m_pe_thread->SetPrivMode (PrivMode::PrivHypervisor);

  m_pe_thread->SetPC (m_pe_thread->UExtXlen(htvec));
  m_pe_thread->SetJumped (true);
}


void InstEnv::RISCV_INST_WFI (InstWord_t inst_hex)
{
  m_pe_thread->SetCpuWaitMode (true);
  // m_pe_thread->SetJumped (true); // PC not update
  // m_pe_thread->InfoPrint("<Info WFI is not supported>\n");
}


void InstEnv::RISCV_INST_SFENCE_VMA (InstWord_t inst_hex)
{
  m_pe_thread->FlushTlb();
}


void InstEnv::RISCV_INST_LWU (InstWord_t inst_hex)
{
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);

  DWord_t rs1_val = m_pe_thread->ReadGReg<DWord_t> (rs1_addr);
  DWord_t imm     = ExtractIField (inst_hex);

  Addr_t  mem_addr = m_pe_thread->UExtXlen (rs1_val + imm);

  Word_t  res_32;
  MemResult except = m_pe_thread->LoadFromBus (mem_addr, &res_32);
  UWord_t res = static_cast<UWord_t>(res_32);

  if (except == MemResult::MemMisAlign) {
    m_pe_thread->GenerateException (ExceptCode::Except_LoadAddrMisalign, mem_addr);
    return;
  }
  if (except == MemResult::MemTlbError) {
    m_pe_thread->GenerateException (ExceptCode::Except_LoadPageFault, mem_addr);
    return;
  }

  m_pe_thread->WriteGReg (rd_addr, res);
}


void InstEnv::RISCV_INST_LD (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  DWord_t rs1_val  = m_pe_thread->ReadGReg<DWord_t> (rs1_addr);
  DWord_t imm      = ExtractIField (inst_hex);

  Addr_t  mem_addr = m_pe_thread->UExtXlen (rs1_val + imm);

  if ((mem_addr & 0x7) != 0) {
    m_pe_thread->GenerateException (ExceptCode::Except_LoadAddrMisalign, mem_addr);
    return;
  }
  DWord_t res;
  MemResult except = m_pe_thread->LoadFromBus (mem_addr + 0, &res);
  if (except == MemResult::MemMisAlign) {
    m_pe_thread->GenerateException (ExceptCode::Except_LoadAddrMisalign, mem_addr);
    return;
  }
  if (except == MemResult::MemTlbError) {
    m_pe_thread->GenerateException (ExceptCode::Except_LoadPageFault, mem_addr);
    return;
  }

  m_pe_thread->WriteGReg<DWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_SD (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);

  DWord_t rs1_val  = m_pe_thread->ReadGReg<DWord_t> (rs1_addr);
  DWord_t rs2_val  = m_pe_thread->ReadGReg<DWord_t> (rs2_addr);
  DWord_t imm      = ExtractSField (inst_hex);

  Addr_t  mem_addr = m_pe_thread->UExtXlen (rs1_val + imm);

  if ((mem_addr & 0x7) != 0) {
    m_pe_thread->GenerateException (ExceptCode::Except_StoreAddrMisalign, mem_addr);
    return;
  }

  MemResult except = MemResult::MemNoExcept;
  except = m_pe_thread->StoreToBus (mem_addr, rs2_val);
  if (except == MemResult::MemMisAlign) {
    m_pe_thread->GenerateException (ExceptCode::Except_StoreAddrMisalign, mem_addr);
    return;
  }
  if (except == MemResult::MemTlbError) {
    m_pe_thread->GenerateException (ExceptCode::Except_StorePageFault, mem_addr);
    return;
  }
}


void InstEnv::RISCV_INST_ADDIW (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  Word_t  rs1_val = m_pe_thread->ReadGReg<Word_t> (rs1_addr);
  Word_t  imm     = ExtractIField (inst_hex);

  Word_t  res    = rs1_val + imm;
  m_pe_thread->WriteGReg<DWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_SLLIW (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  Word_t rs1_val = m_pe_thread->ReadGReg<Word_t> (rs1_addr);
  Word_t shamt   = ExtractBitField (inst_hex, 24, 20);
  Word_t res     = rs1_val << shamt;
  DWord_t res_d  = ExtendSign (res, 31);
  m_pe_thread->WriteGReg<DWord_t> (rd_addr, res_d);
}


void InstEnv::RISCV_INST_SRLIW (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UWord_t rs1_val = m_pe_thread->ReadGReg<UWord_t> (rs1_addr);
  Word_t  shamt   = ExtractBitField (inst_hex, 24, 20);
  Word_t  res     = rs1_val >> shamt;
  DWord_t res_d = ExtendSign (res, 31);
  m_pe_thread->WriteGReg<DWord_t> (rd_addr, res_d);
}


void InstEnv::RISCV_INST_SRAIW (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  Word_t rs1_val  = m_pe_thread->ReadGReg<Word_t> (rs1_addr);
  Word_t shamt  = ExtractBitField (inst_hex, 24, 20);
  Word_t res    = rs1_val >> shamt;
  DWord_t res_d = ExtendSign (res, 31);
  m_pe_thread->WriteGReg<DWord_t> (rd_addr, res_d);
}


void InstEnv::RISCV_INST_SLLW (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  Word_t rs1_val  = m_pe_thread->ReadGReg<Word_t> (rs1_addr);
  Word_t rs2_val  = m_pe_thread->ReadGReg<Word_t> (rs2_addr);
  rs2_val &= 0x01f;
  Word_t res    = rs1_val << rs2_val;
  DWord_t res_d = ExtendSign (res, 31);
  m_pe_thread->WriteGReg<DWord_t> (rd_addr, res_d);
}


void InstEnv::RISCV_INST_SRLW (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UWord_t rs1_val  = m_pe_thread->ReadGReg<Word_t> (rs1_addr);
  UWord_t rs2_val  = m_pe_thread->ReadGReg<Word_t> (rs2_addr);
  rs2_val &= 0x01f;
  Word_t  res   = rs1_val >> rs2_val;
  DWord_t res_d = ExtendSign (res, 31);
  m_pe_thread->WriteGReg<DWord_t> (rd_addr, res_d);
}


void InstEnv::RISCV_INST_SRAW (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  Word_t rs1_val  = m_pe_thread->ReadGReg<Word_t> (rs1_addr);
  Word_t rs2_val  = m_pe_thread->ReadGReg<Word_t> (rs2_addr);
  rs2_val &= 0x01f;
  Word_t res    = rs1_val >> rs2_val;
  DWord_t res_d = ExtendSign (res, 31);
  m_pe_thread->WriteGReg<DWord_t> (rd_addr, res_d);
}


void InstEnv::RISCV_INST_MULW (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  Word_t rs1_val  = m_pe_thread->ReadGReg<Word_t> (rs1_addr);
  Word_t rs2_val  = m_pe_thread->ReadGReg<Word_t> (rs2_addr);
  Word_t res    = rs1_val * rs2_val;
  DWord_t res_d = ExtendSign (res, 31);
  m_pe_thread->WriteGReg<DWord_t> (rd_addr, res_d);
}


void InstEnv::RISCV_INST_DIVW (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  Word_t rs1_val  = m_pe_thread->ReadGReg<Word_t> (rs1_addr);
  Word_t rs2_val  = m_pe_thread->ReadGReg<Word_t> (rs2_addr);

  Word_t  res;
  if (rs2_val == 0) {
    res = -1;
  } else if ((rs1_val == INT32_MIN) && (rs2_val == -1)) {
    res = INT32_MIN;
  } else {
    res = rs1_val / rs2_val;
  }
  DWord_t res_d = ExtendSign (res, 31);
  m_pe_thread->WriteGReg<DWord_t> (rd_addr, res_d);
}


void InstEnv::RISCV_INST_DIVUW (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UWord_t rs1_val  = m_pe_thread->ReadGReg<Word_t> (rs1_addr);
  UWord_t rs2_val  = m_pe_thread->ReadGReg<Word_t> (rs2_addr);

  UWord_t  res;
  if (rs2_val == 0) {
    res = (UWord_t)(-1);
  } else {
    res = rs1_val / rs2_val;
  }
  DWord_t res_d = ExtendSign (res, 31);
  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res_d);
}


void InstEnv::RISCV_INST_REMW (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  Word_t rs1_val  = m_pe_thread->ReadGReg<Word_t> (rs1_addr);
  Word_t rs2_val  = m_pe_thread->ReadGReg<Word_t> (rs2_addr);

  Word_t res;
  if (rs2_val == 0) {
    res = rs1_val;
  } else if (rs2_val == -1) {
    res = 0;
  } else {
    res = rs1_val % rs2_val;
  }
  DWord_t res_d = ExtendSign (res, 31);
  m_pe_thread->WriteGReg<DWord_t> (rd_addr, res_d);
}


void InstEnv::RISCV_INST_REMUW (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  UWord_t rs1_val  = m_pe_thread->ReadGReg<Word_t> (rs1_addr);
  UWord_t rs2_val  = m_pe_thread->ReadGReg<Word_t> (rs2_addr);

  UWord_t  res;
  if (rs2_val == 0) {
    res = rs1_val;
  // } else if (rs2_val == static_cast<UWord_t>(-1)) {
  //   res = rs1_val;
  } else {
    res = rs1_val % rs2_val;
  }
  DWord_t res_d = ExtendSign (res, 31);
  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res_d);
}


void InstEnv::RISCV_INST_LR_D (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  DWord_t rs1_val  = m_pe_thread->ReadGReg<DWord_t> (rs1_addr);
  Addr_t  mem_addr = m_pe_thread->UExtXlen (rs1_val);

  if ((mem_addr & 0x7) != 0) {
    m_pe_thread->GenerateException (ExceptCode::Except_LoadAddrMisalign, mem_addr);
    return;
  }
  DWord_t res;
  MemResult except = m_pe_thread->LoadFromBus (mem_addr + 0, &res);
  if (except == MemResult::MemMisAlign) {
    m_pe_thread->GenerateException (ExceptCode::Except_LoadAddrMisalign, mem_addr);
    return;
  }
  if (except == MemResult::MemTlbError) {
    m_pe_thread->GenerateException (ExceptCode::Except_LoadPageFault, mem_addr);
    return;
  }
  m_pe_thread->SetLoadReservation(mem_addr);
  m_pe_thread->WriteGReg<DWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_SC_D (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  DWord_t rs1_val  = m_pe_thread->ReadGReg<DWord_t> (rs1_addr);
  DWord_t rs2_val  = m_pe_thread->ReadGReg<DWord_t> (rs2_addr);

  Addr_t  mem_addr = m_pe_thread->UExtXlen (rs1_val);

  if (m_pe_thread->GetLoadReservation() != mem_addr) {
    m_pe_thread->WriteGReg<Word_t> (rd_addr, 0x1);
    return;
  }

  if ((mem_addr & 0x7) != 0) {
    m_pe_thread->GenerateException (ExceptCode::Except_StoreAddrMisalign, mem_addr);
    return;
  }

  MemResult except = MemResult::MemNoExcept;
  except = m_pe_thread->StoreToBus (mem_addr, rs2_val);
  if (except == MemResult::MemMisAlign) {
    m_pe_thread->GenerateException (ExceptCode::Except_StoreAddrMisalign, mem_addr);
    return;
  }
  if (except == MemResult::MemTlbError) {
    m_pe_thread->GenerateException (ExceptCode::Except_StorePageFault, mem_addr);
    return;
  }
  m_pe_thread->WriteGReg<DWord_t> (rd_addr, 0x0);
}


void InstEnv::RISCV_INST_AMOSWAP_D (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  DWord_t rs1_val = m_pe_thread->ReadGReg<DWord_t> (rs1_addr);
  DWord_t rs2_val = m_pe_thread->ReadGReg<DWord_t> (rs2_addr);

  Addr_t  mem_addr = m_pe_thread->UExtXlen (rs1_val);
  MemResult except;
  DWord_t mem;
  except = m_pe_thread->LoadFromBus (mem_addr, &mem);
  if (except == MemResult::MemMisAlign) {
    m_pe_thread->GenerateException (ExceptCode::Except_LoadAddrMisalign, mem_addr);
    return;
  }
  if (except == MemResult::MemTlbError) {
    m_pe_thread->GenerateException (ExceptCode::Except_LoadPageFault, mem_addr);
    return;
  }

  except = m_pe_thread->StoreToBus (rs1_val, rs2_val);
  if (except == MemResult::MemMisAlign) {
    m_pe_thread->GenerateException (ExceptCode::Except_StoreAddrMisalign, mem_addr);
    return;
  }
  if (except == MemResult::MemTlbError) {
    m_pe_thread->GenerateException (ExceptCode::Except_StorePageFault, mem_addr);
    return;
  }
  m_pe_thread->WriteGReg (rd_addr, mem);
}


void InstEnv::RISCV_INST_AMOADD_D (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  DWord_t rs1_val  = m_pe_thread->ReadGReg<DWord_t> (rs1_addr);
  DWord_t rs2_val  = m_pe_thread->ReadGReg<DWord_t> (rs2_addr);

  Addr_t mem_addr = m_pe_thread->UExtXlen (rs1_val);
  MemResult except;
  DWord_t mem;
  except = m_pe_thread->LoadFromBus (mem_addr, &mem);
  if (except == MemResult::MemMisAlign) {
    m_pe_thread->GenerateException (ExceptCode::Except_LoadAddrMisalign, mem_addr);
    return;
  }
  if (except == MemResult::MemTlbError) {
    m_pe_thread->GenerateException (ExceptCode::Except_LoadPageFault, mem_addr);
    return;
  }

  DWord_t ret = mem + rs2_val;

  except = m_pe_thread->StoreToBus (rs1_val, ret);
  if (except == MemResult::MemMisAlign) {
    m_pe_thread->GenerateException (ExceptCode::Except_StoreAddrMisalign, mem_addr);
    return;
  }
  if (except == MemResult::MemTlbError) {
    m_pe_thread->GenerateException (ExceptCode::Except_StorePageFault, mem_addr);
    return;
  }

  m_pe_thread->WriteGReg (rd_addr, mem);
}


void InstEnv::RISCV_INST_AMOXOR_D (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  DWord_t rs1_val  = m_pe_thread->ReadGReg<DWord_t> (rs1_addr);
  DWord_t rs2_val  = m_pe_thread->ReadGReg<DWord_t> (rs2_addr);

  Addr_t mem_addr = m_pe_thread->UExtXlen (rs1_val);
  MemResult except;
  DWord_t mem;
  except = m_pe_thread->LoadFromBus (mem_addr, &mem);
  if (except == MemResult::MemMisAlign) {
    m_pe_thread->GenerateException (ExceptCode::Except_LoadAddrMisalign, mem_addr);
    return;
  }
  if (except == MemResult::MemTlbError) {
    m_pe_thread->GenerateException (ExceptCode::Except_LoadPageFault, mem_addr);
    return;
  }

  DWord_t ret = mem ^ rs2_val;

  except = m_pe_thread->StoreToBus (rs1_val, ret);
  if (except == MemResult::MemMisAlign) {
    m_pe_thread->GenerateException (ExceptCode::Except_StoreAddrMisalign, mem_addr);
    return;
  }
  if (except == MemResult::MemTlbError) {
    m_pe_thread->GenerateException (ExceptCode::Except_StorePageFault, mem_addr);
    return;
  }

  m_pe_thread->WriteGReg (rd_addr, mem);
}


void InstEnv::RISCV_INST_AMOAND_D (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  DWord_t rs1_val  = m_pe_thread->ReadGReg<DWord_t> (rs1_addr);
  DWord_t rs2_val  = m_pe_thread->ReadGReg<DWord_t> (rs2_addr);

  Addr_t mem_addr = m_pe_thread->UExtXlen (rs1_val);
  MemResult except;
  DWord_t mem;
  except = m_pe_thread->LoadFromBus (mem_addr, &mem);
  if (except == MemResult::MemMisAlign) {
    m_pe_thread->GenerateException (ExceptCode::Except_LoadAddrMisalign, mem_addr);
    return;
  }
  if (except == MemResult::MemTlbError) {
    m_pe_thread->GenerateException (ExceptCode::Except_LoadPageFault, mem_addr);
    return;
  }

  DWord_t ret = mem & rs2_val;

  except = m_pe_thread->StoreToBus (rs1_val, ret);
  if (except == MemResult::MemMisAlign) {
    m_pe_thread->GenerateException (ExceptCode::Except_StoreAddrMisalign, mem_addr);
    return;
  }
  if (except == MemResult::MemTlbError) {
    m_pe_thread->GenerateException (ExceptCode::Except_StorePageFault, mem_addr);
    return;
  }

  m_pe_thread->WriteGReg (rd_addr, mem);
}


void InstEnv::RISCV_INST_AMOOR_D (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  DWord_t rs1_val  = m_pe_thread->ReadGReg<DWord_t> (rs1_addr);
  DWord_t rs2_val  = m_pe_thread->ReadGReg<DWord_t> (rs2_addr);

  Addr_t mem_addr = m_pe_thread->UExtXlen (rs1_val);
  MemResult except;
  DWord_t mem;
  except = m_pe_thread->LoadFromBus (mem_addr, &mem);
  if (except == MemResult::MemMisAlign) {
    m_pe_thread->GenerateException (ExceptCode::Except_LoadAddrMisalign, mem_addr);
    return;
  }
  if (except == MemResult::MemTlbError) {
    m_pe_thread->GenerateException (ExceptCode::Except_LoadPageFault, mem_addr);
    return;
  }

  DWord_t ret = mem | rs2_val;

  except = m_pe_thread->StoreToBus (rs1_val, ret);
  if (except == MemResult::MemMisAlign) {
    m_pe_thread->GenerateException (ExceptCode::Except_StoreAddrMisalign, mem_addr);
    return;
  }
  if (except == MemResult::MemTlbError) {
    m_pe_thread->GenerateException (ExceptCode::Except_StorePageFault, mem_addr);
    return;
  }

  m_pe_thread->WriteGReg (rd_addr, mem);
}


void InstEnv::RISCV_INST_AMOMIN_D (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  DWord_t rs1_val  = m_pe_thread->ReadGReg<DWord_t> (rs1_addr);
  DWord_t rs2_val  = m_pe_thread->ReadGReg<DWord_t> (rs2_addr);

  Addr_t mem_addr = m_pe_thread->UExtXlen (rs1_val);
  MemResult except;
  DWord_t mem;
  except = m_pe_thread->LoadFromBus (mem_addr, &mem);
  if (except == MemResult::MemMisAlign) {
    m_pe_thread->GenerateException (ExceptCode::Except_LoadAddrMisalign, mem_addr);
    return;
  }
  if (except == MemResult::MemTlbError) {
    m_pe_thread->GenerateException (ExceptCode::Except_LoadPageFault, mem_addr);
    return;
  }

  DWord_t ret = (mem < rs2_val) ? mem : rs2_val;

  except = m_pe_thread->StoreToBus (rs1_val, ret);
  if (except == MemResult::MemMisAlign) {
    m_pe_thread->GenerateException (ExceptCode::Except_StoreAddrMisalign, mem_addr);
    return;
  }
  if (except == MemResult::MemTlbError) {
    m_pe_thread->GenerateException (ExceptCode::Except_StorePageFault, mem_addr);
    return;
  }

  m_pe_thread->WriteGReg (rd_addr, mem);
}


void InstEnv::RISCV_INST_AMOMAX_D (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  DWord_t rs1_val  = m_pe_thread->ReadGReg<DWord_t> (rs1_addr);
  DWord_t rs2_val  = m_pe_thread->ReadGReg<DWord_t> (rs2_addr);

  Addr_t mem_addr = m_pe_thread->UExtXlen (rs1_val);
  MemResult except;
  DWord_t mem;
  except = m_pe_thread->LoadFromBus (mem_addr, &mem);
  if (except == MemResult::MemMisAlign) {
    m_pe_thread->GenerateException (ExceptCode::Except_LoadAddrMisalign, mem_addr);
    return;
  }
  if (except == MemResult::MemTlbError) {
    m_pe_thread->GenerateException (ExceptCode::Except_LoadPageFault, mem_addr);
    return;
  }

  DWord_t ret = (mem < rs2_val) ? rs2_val : mem;

  except = m_pe_thread->StoreToBus (rs1_val, ret);
  if (except == MemResult::MemMisAlign) {
    m_pe_thread->GenerateException (ExceptCode::Except_StoreAddrMisalign, mem_addr);
    return;
  }
  if (except == MemResult::MemTlbError) {
    m_pe_thread->GenerateException (ExceptCode::Except_StorePageFault, mem_addr);
    return;
  }

  m_pe_thread->WriteGReg (rd_addr, mem);
}


void InstEnv::RISCV_INST_AMOMINU_D (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  DWord_t  rs1_val = m_pe_thread->ReadGReg<DWord_t> (rs1_addr);
  UDWord_t rs2_val = m_pe_thread->ReadGReg<UDWord_t> (rs2_addr);

  Addr_t mem_addr = m_pe_thread->UExtXlen (rs1_val);
  MemResult except;
  DWord_t mem;
  except = m_pe_thread->LoadFromBus (mem_addr, &mem);
  if (except == MemResult::MemMisAlign) {
    m_pe_thread->GenerateException (ExceptCode::Except_LoadAddrMisalign, mem_addr);
    return;
  }
  if (except == MemResult::MemTlbError) {
    m_pe_thread->GenerateException (ExceptCode::Except_LoadPageFault, mem_addr);
    return;
  }

  UDWord_t mem_u = static_cast<UDWord_t>(mem);
  DWord_t  ret = (mem_u < rs2_val) ? mem_u : rs2_val;

  except = m_pe_thread->StoreToBus (rs1_val, ret);
  if (except == MemResult::MemMisAlign) {
    m_pe_thread->GenerateException (ExceptCode::Except_StoreAddrMisalign, mem_addr);
    return;
  }
  if (except == MemResult::MemTlbError) {
    m_pe_thread->GenerateException (ExceptCode::Except_StorePageFault, mem_addr);
    return;
  }

  m_pe_thread->WriteGReg (rd_addr, mem);
}


void InstEnv::RISCV_INST_AMOMAXU_D (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  DWord_t  rs1_val = m_pe_thread->ReadGReg<DWord_t> (rs1_addr);
  UDWord_t rs2_val = m_pe_thread->ReadGReg<UDWord_t> (rs2_addr);

  Addr_t mem_addr = m_pe_thread->UExtXlen (rs1_val);
  MemResult except;
  UDWord_t mem;
  except = m_pe_thread->LoadFromBus (mem_addr, &mem);
  if (except == MemResult::MemMisAlign) {
    m_pe_thread->GenerateException (ExceptCode::Except_LoadAddrMisalign, mem_addr);
    return;
  }
  if (except == MemResult::MemTlbError) {
    m_pe_thread->GenerateException (ExceptCode::Except_LoadPageFault, mem_addr);
    return;
  }

  UDWord_t ret = (mem < rs2_val) ? rs2_val : mem;

  except = m_pe_thread->StoreToBus (rs1_val + 0, ret);
  if (except == MemResult::MemMisAlign) {
    m_pe_thread->GenerateException (ExceptCode::Except_StoreAddrMisalign, mem_addr);
    return;
  }
  if (except == MemResult::MemTlbError) {
    m_pe_thread->GenerateException (ExceptCode::Except_StorePageFault, mem_addr);
    return;
  }

  m_pe_thread->WriteGReg (rd_addr, mem);
}


void InstEnv::RISCV_INST_FCVT_L_S (InstWord_t inst_hex)
{
  RegAddr_t fs_addr = ExtractR1Field (inst_hex);
  RegAddr_t fd_addr = ExtractRDField (inst_hex);
  uint8_t   round_mode = m_pe_thread->EncodeRMField(ExtractF3Field (inst_hex));

  Word_t  fs_val  = m_pe_thread->ReadFReg<Word_t> (fs_addr);
  UWord_t fflags;
  DWord_t fs_res  = InstOps::Convert_StoL (fs_val, round_mode, &fflags);

  m_pe_thread->WriteGReg<DWord_t> (fd_addr, fs_res);
  m_pe_thread->CSRWrite (static_cast<Addr_t>(SYSREG_ADDR_FFLAGS), fflags);
}


void InstEnv::RISCV_INST_FCVT_LU_S (InstWord_t inst_hex)
{
  RegAddr_t fs_addr = ExtractR1Field (inst_hex);
  RegAddr_t fd_addr = ExtractRDField (inst_hex);
  uint8_t   round_mode = m_pe_thread->EncodeRMField(ExtractF3Field (inst_hex));

  UDWord_t fs_val  = m_pe_thread->ReadFReg<UDWord_t> (fs_addr);
  UWord_t  fflags;
  UDWord_t fs_res  = InstOps::Convert_StoLU (fs_val, round_mode, &fflags);

  m_pe_thread->WriteGReg<UDWord_t> (fd_addr, fs_res);
  m_pe_thread->CSRWrite (static_cast<Addr_t>(SYSREG_ADDR_FFLAGS), fflags);
}


void InstEnv::RISCV_INST_FCVT_S_L (InstWord_t inst_hex)
{
  RegAddr_t fs_addr = ExtractR1Field (inst_hex);
  RegAddr_t fd_addr = ExtractRDField (inst_hex);
  uint8_t   round_mode = m_pe_thread->EncodeRMField(ExtractF3Field (inst_hex));

  Word_t  fs_val  = m_pe_thread->ReadGReg<Word_t> (fs_addr);
  UWord_t fflags;
  DWord_t fs_res  = InstOps::Convert_LtoS (fs_val, round_mode, &fflags);
  fs_res |= 0xffffffff00000000ULL;

  m_pe_thread->WriteFReg<DWord_t> (fd_addr, fs_res);
  m_pe_thread->CSRWrite (static_cast<Addr_t>(SYSREG_ADDR_FFLAGS), fflags);
}


void InstEnv::RISCV_INST_FCVT_S_LU (InstWord_t inst_hex)
{
  RegAddr_t fs_addr = ExtractR1Field (inst_hex);
  RegAddr_t fd_addr = ExtractRDField (inst_hex);
  uint8_t   round_mode = m_pe_thread->EncodeRMField(ExtractF3Field (inst_hex));

  UDWord_t fs_val  = m_pe_thread->ReadGReg<UDWord_t> (fs_addr);
  UWord_t  fflags;
  DWord_t  fs_res  = InstOps::Convert_LUtoS (fs_val, round_mode, &fflags);
  fs_res |= 0xffffffff00000000ULL;

  m_pe_thread->WriteFReg (fd_addr, fs_res);
  m_pe_thread->CSRWrite (static_cast<Addr_t>(SYSREG_ADDR_FFLAGS), fflags);
}


void InstEnv::RISCV_INST_FCVT_L_D (InstWord_t inst_hex)
{
  RegAddr_t fs_addr = ExtractR1Field (inst_hex);
  RegAddr_t fd_addr = ExtractRDField (inst_hex);
  uint8_t   round_mode = m_pe_thread->EncodeRMField(ExtractF3Field (inst_hex));

  DWord_t fs_val = m_pe_thread->ReadFReg<DWord_t> (fs_addr);
  UWord_t fflags;
  DWord_t fs_res = InstOps::Convert_DtoL (fs_val, round_mode, &fflags);

  m_pe_thread->WriteGReg<DWord_t> (fd_addr, fs_res);
  m_pe_thread->CSRWrite (static_cast<Addr_t>(SYSREG_ADDR_FFLAGS), fflags);
}


void InstEnv::RISCV_INST_FCVT_LU_D (InstWord_t inst_hex)
{
  RegAddr_t fs_addr = ExtractR1Field (inst_hex);
  RegAddr_t fd_addr = ExtractRDField (inst_hex);
  uint8_t   round_mode = m_pe_thread->EncodeRMField(ExtractF3Field (inst_hex));

  DWord_t  fs_val = m_pe_thread->ReadFReg<DWord_t> (fs_addr);
  UWord_t  fflags;
  UDWord_t fs_res = InstOps::Convert_DtoLU (fs_val, round_mode, &fflags);

  m_pe_thread->WriteGReg<UDWord_t> (fd_addr, fs_res);
  m_pe_thread->CSRWrite (static_cast<Addr_t>(SYSREG_ADDR_FFLAGS), fflags);
}


void InstEnv::RISCV_INST_FMV_X_D (InstWord_t inst_hex)
{
  RegAddr_t fs_addr = ExtractR1Field (inst_hex);
  RegAddr_t fd_addr = ExtractRDField (inst_hex);

  DWord_t   fs_val  = m_pe_thread->ReadFReg<DWord_t> (fs_addr);

  m_pe_thread->WriteGReg<DWord_t> (fd_addr, fs_val);
}


void InstEnv::RISCV_INST_FCVT_D_L (InstWord_t inst_hex)
{
  RegAddr_t fs_addr = ExtractR1Field (inst_hex);
  RegAddr_t fd_addr = ExtractRDField (inst_hex);
  uint8_t   round_mode = m_pe_thread->EncodeRMField(ExtractF3Field (inst_hex));

  DWord_t fs_val = m_pe_thread->ReadGReg<DWord_t> (fs_addr);
  UWord_t fflags;
  DWord_t fs_res = InstOps::Convert_LtoD (fs_val, round_mode, &fflags);

  m_pe_thread->WriteFReg<DWord_t> (fd_addr, fs_res);
  m_pe_thread->CSRWrite (static_cast<Addr_t>(SYSREG_ADDR_FFLAGS), fflags);
}


void InstEnv::RISCV_INST_FCVT_D_LU (InstWord_t inst_hex)
{
  RegAddr_t fs_addr = ExtractR1Field (inst_hex);
  RegAddr_t fd_addr = ExtractRDField (inst_hex);
  uint8_t   round_mode = m_pe_thread->EncodeRMField(ExtractF3Field (inst_hex));

  UDWord_t fs_val = m_pe_thread->ReadGReg<UDWord_t> (fs_addr);
  UWord_t  fflags;
  DWord_t  fs_res = InstOps::Convert_LUtoD (fs_val, round_mode, &fflags);

  m_pe_thread->WriteFReg<DWord_t> (fd_addr, fs_res);
  m_pe_thread->CSRWrite (static_cast<Addr_t>(SYSREG_ADDR_FFLAGS), fflags);
}


void InstEnv::RISCV_INST_FMV_D_X (InstWord_t inst_hex)
{
  RegAddr_t fs_addr = ExtractR1Field (inst_hex);
  RegAddr_t fd_addr = ExtractRDField (inst_hex);

  DWord_t   fs_val  = m_pe_thread->ReadGReg<DWord_t> (fs_addr);

  m_pe_thread->WriteFReg<DWord_t> (fd_addr, fs_val);
}


void InstEnv::RISCV_INST_C_ADDI4SPN (InstWord_t inst_hex)
{
  RegAddr_t rd_addr = ExtractRDField_C (inst_hex);
  DWord_t   imm = (ExtractBitField (inst_hex, 12,11) << 4) |
                  (ExtractBitField (inst_hex, 10, 7) << 6) |
                  (ExtractBitField (inst_hex,  6, 6) << 2) |
                  (ExtractBitField (inst_hex,  5, 5) << 3);

  if (imm == 0) {
    m_pe_thread->GenerateException (ExceptCode::Except_IllegalInst, 0);
    return;
  }

  UDWord_t rs_val = m_pe_thread->ReadGReg<DWord_t> (RS_ADDR_SP);
  UDWord_t res    = rs_val + imm;

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_C_FLD (InstWord_t inst_hex)
{
  RegAddr_t rd_addr   = ExtractRDField_C (inst_hex);
  RegAddr_t base_addr = ExtractR1Field_C (inst_hex);
  DWord_t   imm = (ExtractBitField (inst_hex,  5, 5) << 5) |
                  (ExtractBitField (inst_hex, 12,10) << 1) |
                  (ExtractBitField (inst_hex,  6, 6) << 0);

  DWord_t base_val = m_pe_thread->ReadGReg<DWord_t> (base_addr);
  Addr_t  mem_addr = base_val + imm * 8;

  DWord_t res;
  MemResult except = m_pe_thread->LoadFromBus (mem_addr, &res);
  if (except == MemResult::MemMisAlign) {
    m_pe_thread->GenerateException (ExceptCode::Except_StoreAddrMisalign, mem_addr);
    return;
  }
  if (except == MemResult::MemTlbError) {
    m_pe_thread->GenerateException (ExceptCode::Except_LoadPageFault, mem_addr);
    return;
  }

  m_pe_thread->WriteFReg<DWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_C_LD (InstWord_t inst_hex)
{
  RegAddr_t rd_addr   = ExtractRDField_C (inst_hex);
  RegAddr_t base_addr = ExtractR1Field_C (inst_hex);
  DWord_t   imm = (ExtractBitField (inst_hex,  6, 5) << 6) |
                  (ExtractBitField (inst_hex, 12,10) << 3);

  DWord_t base_val = m_pe_thread->ReadGReg<DWord_t> (base_addr);
  Addr_t  mem_addr = base_val + imm;

  DWord_t res;
  MemResult except = m_pe_thread->LoadFromBus (mem_addr, &res);
  if (except == MemResult::MemMisAlign) {
    m_pe_thread->GenerateException (ExceptCode::Except_StoreAddrMisalign, mem_addr);
    return;
  }
  if (except == MemResult::MemTlbError) {
    m_pe_thread->GenerateException (ExceptCode::Except_LoadPageFault, mem_addr);
    return;
  }

  m_pe_thread->WriteGReg<DWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_C_LW (InstWord_t inst_hex)
{
  RegAddr_t rd_addr   = ExtractRDField_C (inst_hex);
  RegAddr_t base_addr = ExtractR1Field_C (inst_hex);
  Addr_t   imm = (ExtractBitField (inst_hex, 12,10) << 3) |
                 (ExtractBitField (inst_hex,  6, 6) << 2) |
                 (ExtractBitField (inst_hex,  5, 5) << 6);

  DWord_t base_val = m_pe_thread->ReadGReg<DWord_t> (base_addr);
  Addr_t  mem_addr = m_pe_thread->UExtXlen (base_val + imm);

  Word_t  res_32;
  MemResult except = m_pe_thread->LoadFromBus (mem_addr, &res_32);
  if (except == MemResult::MemMisAlign) {
    m_pe_thread->GenerateException (ExceptCode::Except_StoreAddrMisalign, mem_addr);
    return;
  }
  if (except == MemResult::MemTlbError) {
    m_pe_thread->GenerateException (ExceptCode::Except_LoadPageFault, mem_addr);
    return;
  }

  m_pe_thread->WriteGReg<Word_t> (rd_addr, res_32);
}


void InstEnv::RISCV_INST_C_FLW (InstWord_t inst_hex)
{
  RegAddr_t rd_addr   = ExtractRDField_C (inst_hex);
  RegAddr_t base_addr = ExtractR1Field_C (inst_hex);
  DWord_t   imm = (ExtractBitField (inst_hex, 12,10) << 3) |
                  (ExtractBitField (inst_hex,  6, 6) << 2) |
                  (ExtractBitField (inst_hex,  5, 5) << 6);

  DWord_t base_val = m_pe_thread->ReadGReg<DWord_t> (base_addr);
  Addr_t  mem_addr = m_pe_thread->UExtXlen (base_val + imm);

  Word_t  res_32;
  MemResult except = m_pe_thread->LoadFromBus (mem_addr, &res_32);
  if (except == MemResult::MemMisAlign) {
    m_pe_thread->GenerateException (ExceptCode::Except_StoreAddrMisalign, mem_addr);
    return;
  }
  if (except == MemResult::MemTlbError) {
    m_pe_thread->GenerateException (ExceptCode::Except_LoadPageFault, mem_addr);
    return;
  }

  m_pe_thread->WriteFReg<Word_t> (rd_addr, res_32);
}


void InstEnv::RISCV_INST_C_FSD (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_C_SW (InstWord_t inst_hex)
{
  RegAddr_t src_addr  = ExtractRDField_C (inst_hex);
  RegAddr_t base_addr = ExtractR1Field_C (inst_hex);
  Addr_t    imm = (ExtractBitField (inst_hex, 12,10) << 3) |
                  (ExtractBitField (inst_hex,  6, 6) << 2) |
                  (ExtractBitField (inst_hex,  5, 5) << 6);

  Word_t  src_val  = m_pe_thread->ReadGReg<Word_t> (src_addr);
  DWord_t base_val = m_pe_thread->ReadGReg<DWord_t> (base_addr);
  Addr_t  mem_addr = m_pe_thread->UExtXlen (base_val + imm);

  MemResult except = m_pe_thread->StoreToBus (mem_addr, src_val);
  if (except == MemResult::MemMisAlign) {
    m_pe_thread->GenerateException (ExceptCode::Except_StoreAddrMisalign, mem_addr);
    return;
  }
  if (except == MemResult::MemTlbError) {
    m_pe_thread->GenerateException (ExceptCode::Except_StorePageFault, mem_addr);
    return;
  }
}


void InstEnv::RISCV_INST_C_FSW (InstWord_t inst_hex)
{
  RegAddr_t src_addr  = ExtractRDField_C (inst_hex);
  RegAddr_t base_addr = ExtractR1Field_C (inst_hex);
  Addr_t    imm = (ExtractBitField (inst_hex, 12,10) << 3) |
                  (ExtractBitField (inst_hex,  6, 6) << 2) |
                  (ExtractBitField (inst_hex,  5, 5) << 6);

  Word_t  src_val  = m_pe_thread->ReadFReg<Word_t> (src_addr);
  DWord_t base_val = m_pe_thread->ReadGReg<DWord_t> (base_addr);
  Addr_t  mem_addr = m_pe_thread->UExtXlen (base_val + imm);

  MemResult except = m_pe_thread->StoreToBus (mem_addr, src_val);
  if (except == MemResult::MemMisAlign) {
    m_pe_thread->GenerateException (ExceptCode::Except_StoreAddrMisalign, mem_addr);
    return;
  }
  if (except == MemResult::MemTlbError) {
    m_pe_thread->GenerateException (ExceptCode::Except_StorePageFault, mem_addr);
    return;
  }

}


void InstEnv::RISCV_INST_C_SD (InstWord_t inst_hex)
{
  RegAddr_t src_addr  = ExtractRDField_C (inst_hex);
  RegAddr_t base_addr = ExtractR1Field_C (inst_hex);
  DWord_t   imm = (ExtractBitField (inst_hex, 12, 10) << 3) |
                  (ExtractBitField (inst_hex,  6,  5) << 6);

  DWord_t src_val  = m_pe_thread->ReadGReg<DWord_t> (src_addr);
  DWord_t base_val = m_pe_thread->ReadGReg<DWord_t> (base_addr);
  Addr_t  mem_addr = base_val + imm;

  MemResult except = m_pe_thread->StoreToBus (mem_addr, src_val);
  if (except == MemResult::MemMisAlign) {
    m_pe_thread->GenerateException (ExceptCode::Except_StoreAddrMisalign, mem_addr);
    return;
  }
  if (except == MemResult::MemTlbError) {
    m_pe_thread->GenerateException (ExceptCode::Except_StorePageFault, mem_addr);
    return;
  }
}


void InstEnv::RISCV_INST_C_NOP (InstWord_t inst_hex)
{
}


void InstEnv::RISCV_INST_C_ADDI (InstWord_t inst_hex)
{
  RegAddr_t rd_addr = ExtractBitField (inst_hex, 11, 7);
  DWord_t   imm     = ExtendSign ((ExtractBitField (inst_hex, 12,12) << 5) |
                                  (ExtractBitField (inst_hex,  6, 2) << 0), 5);
  DWord_t rs_val = m_pe_thread->ReadGReg<DWord_t> (rd_addr);
  DWord_t res    = rs_val + imm;

  m_pe_thread->WriteGReg<DWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_C_ADDIW (InstWord_t inst_hex)
{
  RegAddr_t rd_addr = ExtractBitField (inst_hex, 11, 7);

  Word_t  rd_val = m_pe_thread->ReadGReg<Word_t> (rd_addr);
  Word_t  imm    = ExtendSign ((ExtractBitField (inst_hex, 12,12) << 5) |
                               (ExtractBitField (inst_hex,  6, 2) << 0), 5);

  Word_t  res    = rd_val + imm;
  m_pe_thread->WriteGReg<DWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_C_JAL (InstWord_t inst_hex)
{
  Addr_t    jal_imm = ExtendSign((ExtractBitField (inst_hex, 12, 12) << 11) |
                                 (ExtractBitField (inst_hex, 11, 11) <<  4) |
                                 (ExtractBitField (inst_hex, 10,  9) <<  8) |
                                 (ExtractBitField (inst_hex,  8,  8) << 10) |
                                 (ExtractBitField (inst_hex,  7,  7) <<  6) |
                                 (ExtractBitField (inst_hex,  6,  6) <<  7) |
                                 (ExtractBitField (inst_hex,  5,  3) <<  1) |
                                 (ExtractBitField (inst_hex,  2,  2) <<  5), 11);

  Addr_t    pc_addr = m_pe_thread->GetPC ();
  Addr_t    res_pc  = pc_addr + jal_imm;

  m_pe_thread->WriteGReg (RS_ADDR_LR, m_pe_thread->SExtXlen(pc_addr + 2));
  m_pe_thread->SetPC (m_pe_thread->UExtXlen(res_pc));
  m_pe_thread->SetJumped (true);

  m_pe_thread->IsBranchTaken (pc_addr);
  m_pe_thread->UpdateBranchPrediction (pc_addr, true);
}


void InstEnv::RISCV_INST_C_LI (InstWord_t inst_hex)
{
  RegAddr_t rd_addr = ExtractBitField (inst_hex, 11, 7);
  DWord_t   imm     = ExtendSign ((ExtractBitField (inst_hex, 12,12) << 5) |
                                  (ExtractBitField (inst_hex,  6, 2) << 0), 5);
  m_pe_thread->WriteGReg<DWord_t> (rd_addr, imm);
}


void InstEnv::RISCV_INST_C_ADDI16SP (InstWord_t inst_hex)
{
  RegAddr_t rd_addr = RS_ADDR_SP;
  DWord_t   imm = ExtendSign ((ExtractBitField (inst_hex, 12,12) << 5) |
                              (ExtractBitField (inst_hex,  4, 3) << 3) |
                              (ExtractBitField (inst_hex,  5, 5) << 2) |
                              (ExtractBitField (inst_hex,  2, 2) << 1) |
                              (ExtractBitField (inst_hex,  6, 6) << 0), 5);

  UDWord_t rs_val = m_pe_thread->ReadGReg<DWord_t> (RS_ADDR_SP);
  UDWord_t res    = rs_val + (imm * 16);

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_C_LUI (InstWord_t inst_hex)
{
  RegAddr_t rd_addr = ExtractBitField (inst_hex, 11, 7);
  UDWord_t  imm     = ExtendSign ((ExtractBitField (inst_hex, 12,12) << 17) |
                                  (ExtractBitField (inst_hex,  6, 2) << 12), 17);

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, imm);
}


void InstEnv::RISCV_INST_C_SRLI (InstWord_t inst_hex)
{
  RegAddr_t rd_addr = ExtractR1Field_C (inst_hex);
  UWord_t   shamt   = (ExtractBitField (inst_hex, 12, 12) << 5) |
                      (ExtractBitField (inst_hex,  6,  2) << 0);

  UDWord_t  rs1_val = m_pe_thread->ReadGReg<UDWord_t> (rd_addr);
  UDWord_t  res     = m_pe_thread->UExtXlen(rs1_val) >> shamt;

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_C_SRLI64 (InstWord_t inst_hex)
{
  RegAddr_t rd_addr = ExtractR1Field_C (inst_hex);
  Word_t    shamt = (ExtractBitField (inst_hex, 12, 12) << 5) | (ExtractBitField (inst_hex, 6, 2) << 0);

  UDWord_t  rs1_val = m_pe_thread->ReadGReg<UDWord_t> (rd_addr);
  UDWord_t  res     = rs1_val >> shamt;

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_C_SRAI (InstWord_t inst_hex)
{
  RegAddr_t rd_addr = ExtractR1Field_C (inst_hex);
  DWord_t   shamt = (ExtractBitField (inst_hex, 12, 12) << 5) | (ExtractBitField (inst_hex, 6, 2) << 0);

  DWord_t rs1_val = m_pe_thread->ReadGReg<DWord_t> (rd_addr);
  DWord_t res     = rs1_val >> shamt;

  m_pe_thread->WriteGReg<DWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_C_SRAI64 (InstWord_t inst_hex)
{
  RegAddr_t rd_addr = ExtractR1Field_C (inst_hex);
  DWord_t   shamt = (ExtractBitField (inst_hex, 12, 12) << 5) | (ExtractBitField (inst_hex, 6, 2) << 0);

  DWord_t rs1_val = m_pe_thread->ReadGReg<DWord_t> (rd_addr);
  DWord_t res     = rs1_val >> shamt;

  m_pe_thread->WriteGReg<DWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_C_ANDI (InstWord_t inst_hex)
{
  RegAddr_t rd_addr = ExtractR1Field_C (inst_hex);
  DWord_t   shamt = ExtendSign((ExtractBitField (inst_hex, 12, 12) << 5) |
                               (ExtractBitField (inst_hex,  6,  2) << 0), 5);

  DWord_t rs1_val = m_pe_thread->ReadGReg<DWord_t> (rd_addr);
  DWord_t res     = rs1_val & shamt;

  m_pe_thread->WriteGReg<DWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_C_SUB (InstWord_t inst_hex)
{
  RegAddr_t rd_addr  = ExtractR1Field_C (inst_hex);
  RegAddr_t rs2_addr = ExtractRDField_C (inst_hex);

  DWord_t rs1_val = m_pe_thread->ReadGReg<DWord_t> (rd_addr);
  DWord_t rs2_val = m_pe_thread->ReadGReg<DWord_t> (rs2_addr);
  DWord_t res     = rs1_val - rs2_val;

  m_pe_thread->WriteGReg<DWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_C_XOR (InstWord_t inst_hex)
{
  RegAddr_t rd_addr  = ExtractR1Field_C (inst_hex);
  RegAddr_t rs2_addr = ExtractRDField_C (inst_hex);

  UDWord_t rs1_val = m_pe_thread->ReadGReg<UDWord_t> (rd_addr);
  UDWord_t rs2_val = m_pe_thread->ReadGReg<UDWord_t> (rs2_addr);
  UDWord_t res     = rs1_val ^ rs2_val;

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_C_OR (InstWord_t inst_hex)
{
  RegAddr_t rd_addr  = ExtractR1Field_C (inst_hex);
  RegAddr_t rs2_addr = ExtractRDField_C (inst_hex);

  UDWord_t rs1_val = m_pe_thread->ReadGReg<UDWord_t> (rd_addr);
  UDWord_t rs2_val = m_pe_thread->ReadGReg<UDWord_t> (rs2_addr);
  UDWord_t res     = rs1_val | rs2_val;

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_C_AND (InstWord_t inst_hex)
{
  RegAddr_t rd_addr  = ExtractR1Field_C (inst_hex);
  RegAddr_t rs2_addr = ExtractRDField_C (inst_hex);

  UDWord_t rs1_val = m_pe_thread->ReadGReg<UDWord_t> (rd_addr);
  UDWord_t rs2_val = m_pe_thread->ReadGReg<UDWord_t> (rs2_addr);
  UDWord_t res     = rs1_val & rs2_val;

  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_C_SUBW (InstWord_t inst_hex)
{
  RegAddr_t rd_addr  = ExtractR1Field_C (inst_hex);
  RegAddr_t rs2_addr = ExtractRDField_C (inst_hex);

  DWord_t rs1_val = m_pe_thread->ReadGReg<Word_t> (rd_addr);
  DWord_t rs2_val = m_pe_thread->ReadGReg<Word_t> (rs2_addr);
  DWord_t res     = rs1_val - rs2_val;

  m_pe_thread->WriteGReg<Word_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_C_ADDW (InstWord_t inst_hex)
{
  RegAddr_t rd_addr  = ExtractR1Field_C (inst_hex);
  RegAddr_t rs2_addr = ExtractRDField_C (inst_hex);

  DWord_t rs1_val = m_pe_thread->ReadGReg<Word_t> (rd_addr);
  DWord_t rs2_val = m_pe_thread->ReadGReg<Word_t> (rs2_addr);
  DWord_t res     = rs1_val + rs2_val;

  m_pe_thread->WriteGReg<Word_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_C_J (InstWord_t inst_hex)
{
  Addr_t    jal_imm = ExtendSign((ExtractBitField (inst_hex, 12, 12) << 11) |
                                 (ExtractBitField (inst_hex, 11, 11) <<  4) |
                                 (ExtractBitField (inst_hex, 10,  9) <<  8) |
                                 (ExtractBitField (inst_hex,  8,  8) << 10) |
                                 (ExtractBitField (inst_hex,  7,  7) <<  6) |
                                 (ExtractBitField (inst_hex,  6,  6) <<  7) |
                                 (ExtractBitField (inst_hex,  5,  3) <<  1) |
                                 (ExtractBitField (inst_hex,  2,  2) <<  5), 11);

  Addr_t    pc_addr = m_pe_thread->GetPC ();
  Addr_t    res_pc  = jal_imm + pc_addr;

  m_pe_thread->SetPC (m_pe_thread->UExtXlen(res_pc));
  m_pe_thread->SetJumped (true);

  m_pe_thread->IsBranchTaken (pc_addr);
  m_pe_thread->UpdateBranchPrediction (pc_addr, true);
}


void InstEnv::RISCV_INST_C_BEQZ (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field_C (inst_hex);
  Addr_t    imm     = ExtendSign ((ExtractBitField (inst_hex, 12, 12) << 8) |
                                  (ExtractBitField (inst_hex, 11, 10) << 3) |
                                  (ExtractBitField (inst_hex,  6,  5) << 6) |
                                  (ExtractBitField (inst_hex,  4,  3) << 1) |
                                  (ExtractBitField (inst_hex,  2,  2) << 5), 8);
  DWord_t   rs1_val    = m_pe_thread->ReadGReg<DWord_t> (rs1_addr);
  Addr_t    current_pc = m_pe_thread->GetPC();

  bool taken = (rs1_val == 0);
  m_pe_thread->IsBranchTaken (current_pc);

  if (taken) {
    Addr_t res_pc = current_pc + imm;
    m_pe_thread->SetPC (m_pe_thread->UExtXlen(res_pc));
    m_pe_thread->SetJumped (true);
  }
  m_pe_thread->UpdateBranchPrediction (current_pc, taken);
}


void InstEnv::RISCV_INST_C_BNEZ (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractR1Field_C (inst_hex);
  Addr_t    imm     = ExtendSign ((ExtractBitField (inst_hex, 12, 12) << 8) |
                                  (ExtractBitField (inst_hex, 11, 10) << 3) |
                                  (ExtractBitField (inst_hex,  6,  5) << 6) |
                                  (ExtractBitField (inst_hex,  4,  3) << 1) |
                                  (ExtractBitField (inst_hex,  2,  2) << 5), 8);
  DWord_t   rs1_val    = m_pe_thread->ReadGReg<DWord_t> (rs1_addr);
  Addr_t    current_pc = m_pe_thread->GetPC();

  bool taken = (rs1_val != 0);
  m_pe_thread->IsBranchTaken (current_pc);

  if (taken) {
    Addr_t res_pc = current_pc + imm;
    m_pe_thread->SetPC (m_pe_thread->UExtXlen(res_pc));
    m_pe_thread->SetJumped (true);
  }
  m_pe_thread->UpdateBranchPrediction (current_pc, taken);
}


void InstEnv::RISCV_INST_C_SLLI (InstWord_t inst_hex)
{
  RegAddr_t rd_addr  = ExtractBitField (inst_hex, 11, 7);
  DWord_t   shamt = ExtendSign((ExtractBitField (inst_hex, 12, 12) << 5) |
                               (ExtractBitField (inst_hex,  6,  2) << 0), 5);

  UDWord_t rs1_val = m_pe_thread->ReadGReg<UDWord_t> (rd_addr);
  UDWord_t res     = rs1_val << shamt;
  m_pe_thread->WriteGReg<UDWord_t> (rd_addr, res);
}


// void InstEnv::RISCV_INST_C_SLLI64 (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_C_FLDSP (InstWord_t inst_hex)
{
  RegAddr_t rd_addr   = ExtractBitField (inst_hex, 11, 7);
  DWord_t   imm = (ExtractBitField (inst_hex, 12,12) << 5) |
                  (ExtractBitField (inst_hex,  6, 4) << 2) |
                  (ExtractBitField (inst_hex,  3, 2) << 6);

  DWord_t base_val = m_pe_thread->ReadGReg<DWord_t> (RS_ADDR_SP);
  Addr_t  mem_addr = base_val + imm * 4;

  Word_t  res_32;
  MemResult except = m_pe_thread->LoadFromBus (mem_addr, &res_32);
  if (except == MemResult::MemMisAlign) {
    m_pe_thread->GenerateException (ExceptCode::Except_StoreAddrMisalign, mem_addr);
    return;
  }
  if (except == MemResult::MemTlbError) {
    m_pe_thread->GenerateException (ExceptCode::Except_LoadPageFault, mem_addr);
    return;
  }

  m_pe_thread->WriteFReg<Word_t> (rd_addr, res_32);
}


void InstEnv::RISCV_INST_C_LWSP (InstWord_t inst_hex)
{
  RegAddr_t rd_addr  = ExtractBitField (inst_hex, 11, 7);
  DWord_t   imm = (ExtractBitField (inst_hex, 12,12) << 5) |
                  (ExtractBitField (inst_hex,  6, 4) << 2) |
                  (ExtractBitField (inst_hex,  3, 2) << 6);

  DWord_t base_val = m_pe_thread->ReadGReg<DWord_t> (RS_ADDR_SP);
  Addr_t  mem_addr = m_pe_thread->UExtXlen (base_val + imm);

  Word_t  res_32;
  MemResult except = m_pe_thread->LoadFromBus (mem_addr, &res_32);
  if (except == MemResult::MemMisAlign) {
    m_pe_thread->GenerateException (ExceptCode::Except_StoreAddrMisalign, mem_addr);
    return;
  }
  if (except == MemResult::MemTlbError) {
    m_pe_thread->GenerateException (ExceptCode::Except_LoadPageFault, mem_addr);
    return;
  }

  m_pe_thread->WriteGReg<Word_t> (rd_addr, res_32);
}


void InstEnv::RISCV_INST_C_FLWSP (InstWord_t inst_hex)
{
  RegAddr_t rd_addr   = ExtractBitField (inst_hex, 11, 7);
  DWord_t   imm = (ExtractBitField (inst_hex, 12,12) << 5) |
                  (ExtractBitField (inst_hex,  6, 4) << 2) |
                  (ExtractBitField (inst_hex,  3, 2) << 6);

  DWord_t base_val = m_pe_thread->ReadGReg<DWord_t> (RS_ADDR_SP);
  Addr_t  mem_addr = m_pe_thread->UExtXlen (base_val + imm);

  Word_t  res_32;
  MemResult except = m_pe_thread->LoadFromBus (mem_addr, &res_32);
  if (except == MemResult::MemMisAlign) {
    m_pe_thread->GenerateException (ExceptCode::Except_StoreAddrMisalign, mem_addr);
    return;
  }
  if (except == MemResult::MemTlbError) {
    m_pe_thread->GenerateException (ExceptCode::Except_LoadPageFault, mem_addr);
    return;
  }

  m_pe_thread->WriteFReg<Word_t> (rd_addr, res_32);
}


void InstEnv::RISCV_INST_C_JR (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractBitField (inst_hex, 11, 7);
  Addr_t    rs1_val  = m_pe_thread->ReadGReg<Addr_t> (rs1_addr);

  m_pe_thread->SetPC (m_pe_thread->UExtXlen(rs1_val));
  m_pe_thread->SetJumped (true);

  m_pe_thread->IsBranchTaken (rs1_val);
  m_pe_thread->UpdateBranchPrediction (rs1_val, true);
}


void InstEnv::RISCV_INST_C_MV (InstWord_t inst_hex)
{
  RegAddr_t rd_addr  = ExtractBitField (inst_hex, 11, 7);
  RegAddr_t rs2_addr = ExtractBitField (inst_hex,  6, 2);

  DWord_t rs2_val = m_pe_thread->ReadGReg<DWord_t> (rs2_addr);
  m_pe_thread->WriteGReg<DWord_t> (rd_addr, rs2_val);
}


void InstEnv::RISCV_INST_C_EBREAK (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_C_JALR (InstWord_t inst_hex)
{
  RegAddr_t rs1_addr = ExtractBitField (inst_hex, 11, 7);
  Addr_t    rs1_val  = m_pe_thread->ReadGReg<Addr_t> (rs1_addr);

  Addr_t    pc_addr = m_pe_thread->GetPC ();
  m_pe_thread->WriteGReg (RS_ADDR_LR, pc_addr + 2);

  m_pe_thread->SetPC (m_pe_thread->UExtXlen(rs1_val));
  m_pe_thread->SetJumped (true);

  m_pe_thread->IsBranchTaken (rs1_val);
  m_pe_thread->UpdateBranchPrediction (pc_addr, true);
}


void InstEnv::RISCV_INST_C_ADD (InstWord_t inst_hex)
{
  RegAddr_t rd_addr = ExtractBitField (inst_hex, 11, 7);
  RegAddr_t rs2_addr  = ExtractBitField (inst_hex,  6, 2);

  DWord_t rs1_val = m_pe_thread->ReadGReg<DWord_t> (rd_addr);
  DWord_t rs2_val = m_pe_thread->ReadGReg<DWord_t> (rs2_addr);
  DWord_t res     = rs1_val + rs2_val;

  m_pe_thread->WriteGReg<DWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_C_FSDSP (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_C_SWSP (InstWord_t inst_hex)
{
  RegAddr_t src_addr  = ExtractBitField (inst_hex, 6, 2);
  DWord_t   imm = (ExtractBitField (inst_hex, 12, 9) << 2) |
                  (ExtractBitField (inst_hex,  8, 7) << 6);

  Word_t  src_val  = m_pe_thread->ReadGReg<Word_t> (src_addr);
  Addr_t base_val = m_pe_thread->ReadGReg<Addr_t> (RS_ADDR_SP);
  Addr_t  mem_addr = m_pe_thread->UExtXlen (base_val + imm);

  MemResult except = m_pe_thread->StoreToBus (mem_addr, src_val);
  if (except == MemResult::MemMisAlign) {
    m_pe_thread->GenerateException (ExceptCode::Except_StoreAddrMisalign, mem_addr);
    return;
  }
  if (except == MemResult::MemTlbError) {
    m_pe_thread->GenerateException (ExceptCode::Except_StorePageFault, mem_addr);
    return;
  }
}


void InstEnv::RISCV_INST_C_FSWSP (InstWord_t inst_hex)
{
  RegAddr_t src_addr  = ExtractBitField (inst_hex, 6, 2);
  DWord_t   imm = (ExtractBitField (inst_hex, 12, 9) << 2) |
                  (ExtractBitField (inst_hex,  8, 7) << 6);

  Word_t src_val  = m_pe_thread->ReadFReg<Word_t> (src_addr);
  Addr_t base_val = m_pe_thread->ReadGReg<Addr_t> (RS_ADDR_SP);
  Addr_t mem_addr = m_pe_thread->UExtXlen (base_val + imm);

  MemResult except = m_pe_thread->StoreToBus (mem_addr, src_val);
  if (except == MemResult::MemMisAlign) {
    m_pe_thread->GenerateException (ExceptCode::Except_StoreAddrMisalign, mem_addr);
    return;
  }
  if (except == MemResult::MemTlbError) {
    m_pe_thread->GenerateException (ExceptCode::Except_StorePageFault, mem_addr);
    return;
  }
}

void InstEnv::RISCV_INST_C_LDSP(InstWord_t inst_hex)
{
  RegAddr_t rd_addr = ExtractBitField (inst_hex, 11, 7);
  DWord_t   imm = (ExtractBitField (inst_hex, 12,12) << 5) |
                  (ExtractBitField (inst_hex,  6, 5) << 3) |
                  (ExtractBitField (inst_hex,  4, 2) << 6);

  DWord_t base_val = m_pe_thread->ReadGReg<DWord_t> (RS_ADDR_SP);
  Addr_t  mem_addr = m_pe_thread->UExtXlen (base_val + imm);

  DWord_t  res;
  MemResult except = m_pe_thread->LoadFromBus (mem_addr, &res);
  if (except == MemResult::MemMisAlign) {
    m_pe_thread->GenerateException (ExceptCode::Except_StoreAddrMisalign, mem_addr);
    return;
  }
  if (except == MemResult::MemTlbError) {
    m_pe_thread->GenerateException (ExceptCode::Except_LoadPageFault, mem_addr);
    return;
  }

  m_pe_thread->WriteGReg<DWord_t> (rd_addr, res);
}


void InstEnv::RISCV_INST_C_SDSP(InstWord_t inst_hex)
{
  RegAddr_t src_addr  = ExtractBitField (inst_hex, 6, 2);
  DWord_t   imm = (ExtractBitField (inst_hex, 12,10) << 3) |
                  (ExtractBitField (inst_hex,  9, 7) << 6);

  DWord_t src_val  = m_pe_thread->ReadGReg<DWord_t> (src_addr);
  Addr_t  base_val = m_pe_thread->ReadGReg<Addr_t> (RS_ADDR_SP);
  Addr_t  mem_addr = m_pe_thread->UExtXlen (base_val + imm);

  MemResult except = m_pe_thread->StoreToBus (mem_addr, src_val);
  if (except == MemResult::MemMisAlign) {
    m_pe_thread->GenerateException (ExceptCode::Except_StoreAddrMisalign, mem_addr);
    return;
  }
  if (except == MemResult::MemTlbError) {
    m_pe_thread->GenerateException (ExceptCode::Except_StorePageFault, mem_addr);
    return;
  }
}

#include "riscv_inst_template.cpp"
