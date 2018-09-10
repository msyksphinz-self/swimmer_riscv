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

/* CAUTION! THIS SOURCE CODE IS GENERATED AUTOMATICALLY. DON'T MODIFY BY HAND. */


#include "inst_riscv.hpp"


void InstEnv::RISCV_INST_ADDI(InstWord_t inst_hex)
{
  m_pe_thread->Func_R_RI<DWord_t, DWord_t> (inst_hex, [&](DWord_t op1, DWord_t op2, uint32_t round_mode) { return m_pe_thread->SExtXlen(op1 +  op2); });
}



void InstEnv::RISCV_INST_SLTI(InstWord_t inst_hex)
{
  m_pe_thread->Func_R_RU<DWord_t, DWord_t> (inst_hex, [&](DWord_t op1, DWord_t op2, uint32_t round_mode) { return m_pe_thread->SExtXlen(op1 <  op2); });
}



void InstEnv::RISCV_INST_SLTIU(InstWord_t inst_hex)
{
  m_pe_thread->Func_R_RU<UDWord_t, UDWord_t> (inst_hex, [&](UDWord_t op1, UDWord_t op2, uint32_t round_mode) { return m_pe_thread->SExtXlen(op1 <  op2); });
}



void InstEnv::RISCV_INST_XORI(InstWord_t inst_hex)
{
  m_pe_thread->Func_R_RI<DWord_t, DWord_t> (inst_hex, [&](DWord_t op1, DWord_t op2, uint32_t round_mode) { return m_pe_thread->SExtXlen(op1 ^  op2); });
}



void InstEnv::RISCV_INST_ORI(InstWord_t inst_hex)
{
  m_pe_thread->Func_R_RI<DWord_t, DWord_t> (inst_hex, [&](DWord_t op1, DWord_t op2, uint32_t round_mode) { return m_pe_thread->SExtXlen(op1 |  op2); });
}



void InstEnv::RISCV_INST_ANDI(InstWord_t inst_hex)
{
  m_pe_thread->Func_R_RI<DWord_t, DWord_t> (inst_hex, [&](DWord_t op1, DWord_t op2, uint32_t round_mode) { return m_pe_thread->SExtXlen(op1 &  op2); });
}



void InstEnv::RISCV_INST_ADD(InstWord_t inst_hex)
{
  m_pe_thread->Func_R_RR<DWord_t, DWord_t> (inst_hex, [&](DWord_t op1, DWord_t op2, uint32_t round_mode) { return m_pe_thread->SExtXlen(op1 +  op2); });
}



void InstEnv::RISCV_INST_SUB(InstWord_t inst_hex)
{
  m_pe_thread->Func_R_RR<DWord_t, DWord_t> (inst_hex, [&](DWord_t op1, DWord_t op2, uint32_t round_mode) { return m_pe_thread->SExtXlen(op1 -  op2); });
}



void InstEnv::RISCV_INST_SLL(InstWord_t inst_hex)
{
  m_pe_thread->Func_R_RR<DWord_t, DWord_t> (inst_hex, [&](DWord_t op1, DWord_t op2, uint32_t round_mode) { return m_pe_thread->SExtXlen(op1 << op2); });
}



void InstEnv::RISCV_INST_SLT(InstWord_t inst_hex)
{
  m_pe_thread->Func_R_RR<DWord_t, DWord_t> (inst_hex, [&](DWord_t op1, DWord_t op2, uint32_t round_mode) { return m_pe_thread->SExtXlen(op1 <  op2); });
}



void InstEnv::RISCV_INST_SLTU(InstWord_t inst_hex)
{
  m_pe_thread->Func_R_RR<UDWord_t, UDWord_t> (inst_hex, [&](UDWord_t op1, UDWord_t op2, uint32_t round_mode) { return m_pe_thread->SExtXlen(op1 <  op2); });
}



void InstEnv::RISCV_INST_XOR(InstWord_t inst_hex)
{
  m_pe_thread->Func_R_RR<DWord_t, DWord_t> (inst_hex, [&](DWord_t op1, DWord_t op2, uint32_t round_mode) { return m_pe_thread->SExtXlen(op1 ^  op2); });
}



void InstEnv::RISCV_INST_SRL(InstWord_t inst_hex)
{
  m_pe_thread->Func_R_RR<UDWord_t, UDWord_t> (inst_hex, [&](UDWord_t op1, UDWord_t op2, uint32_t round_mode) { return m_pe_thread->SExtXlen(m_pe_thread->UExtXlen(op1) >> op2); });
}



void InstEnv::RISCV_INST_SRA(InstWord_t inst_hex)
{
  m_pe_thread->Func_R_RR<DWord_t, DWord_t> (inst_hex, [&](DWord_t op1, DWord_t op2, uint32_t round_mode) { return m_pe_thread->SExtXlen(op1 >> op2); });
}



void InstEnv::RISCV_INST_OR(InstWord_t inst_hex)
{
  m_pe_thread->Func_R_RR<UDWord_t, UDWord_t> (inst_hex, [](UDWord_t op1, UDWord_t op2, uint32_t round_mode) { return          op1 |  op2 ; });
}



void InstEnv::RISCV_INST_AND(InstWord_t inst_hex)
{
  m_pe_thread->Func_R_RR<UDWord_t, UDWord_t> (inst_hex, [](UDWord_t op1, UDWord_t op2, uint32_t round_mode) { return          op1 &  op2 ; });
}



void InstEnv::RISCV_INST_ADDW(InstWord_t inst_hex)
{
  m_pe_thread->Func_R_RR<Word_t, Word_t> (inst_hex, [&](Word_t op1, Word_t op2, uint32_t round_mode) { return m_pe_thread->SExtXlen(op1 +  op2); });
}



void InstEnv::RISCV_INST_SUBW(InstWord_t inst_hex)
{
  m_pe_thread->Func_R_RR<Word_t, Word_t> (inst_hex, [&](Word_t op1, Word_t op2, uint32_t round_mode) { return m_pe_thread->SExtXlen(op1 -  op2); });
}


