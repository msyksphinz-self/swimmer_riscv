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


#pragma once

#include <stdint.h>
#include "riscv_pe_thread.hpp"
#include "inst_list_riscv.hpp"
#include "dec_utils_riscv.hpp"

class RiscvPeThread;

class InstEnv {

private:
  RiscvPeThread *m_pe_thread;

public:
  InstEnv (RiscvPeThread *env);

  typedef void (InstEnv::*InstFunc) (InstWord_t inst_hex);
  static const InstFunc m_inst_exec_func[416];

   void RISCV_Inst_Exec (InstId_t index, InstWord_t inst_hex);

   void RISCV_INST_LUI (InstWord_t inst_hex);
   void RISCV_INST_AUIPC (InstWord_t inst_hex);
   void RISCV_INST_JAL (InstWord_t inst_hex);
   void RISCV_INST_JALR (InstWord_t inst_hex);
   void RISCV_INST_BEQ (InstWord_t inst_hex);
   void RISCV_INST_BNE (InstWord_t inst_hex);
   void RISCV_INST_BLT (InstWord_t inst_hex);
   void RISCV_INST_BGE (InstWord_t inst_hex);
   void RISCV_INST_BLTU (InstWord_t inst_hex);
   void RISCV_INST_BGEU (InstWord_t inst_hex);
   void RISCV_INST_LB (InstWord_t inst_hex);
   void RISCV_INST_LH (InstWord_t inst_hex);
   void RISCV_INST_LW (InstWord_t inst_hex);
   void RISCV_INST_LBU (InstWord_t inst_hex);
   void RISCV_INST_LHU (InstWord_t inst_hex);
   void RISCV_INST_SB (InstWord_t inst_hex);
   void RISCV_INST_SH (InstWord_t inst_hex);
   void RISCV_INST_SW (InstWord_t inst_hex);
   void RISCV_INST_ADDI (InstWord_t inst_hex);
   void RISCV_INST_SLTI (InstWord_t inst_hex);
   void RISCV_INST_SLTIU (InstWord_t inst_hex);
   void RISCV_INST_XORI (InstWord_t inst_hex);
   void RISCV_INST_ORI (InstWord_t inst_hex);
   void RISCV_INST_ANDI (InstWord_t inst_hex);
   void RISCV_INST_SLLI (InstWord_t inst_hex);
   void RISCV_INST_SRLI (InstWord_t inst_hex);
   void RISCV_INST_SRAI (InstWord_t inst_hex);
   void RISCV_INST_ADD (InstWord_t inst_hex);
   void RISCV_INST_SUB (InstWord_t inst_hex);
   void RISCV_INST_SLL (InstWord_t inst_hex);
   void RISCV_INST_SLT (InstWord_t inst_hex);
   void RISCV_INST_SLTU (InstWord_t inst_hex);
   void RISCV_INST_XOR (InstWord_t inst_hex);
   void RISCV_INST_SRL (InstWord_t inst_hex);
   void RISCV_INST_SRA (InstWord_t inst_hex);
   void RISCV_INST_OR (InstWord_t inst_hex);
   void RISCV_INST_AND (InstWord_t inst_hex);
   void RISCV_INST_FENCE (InstWord_t inst_hex);
   void RISCV_INST_FENCE_I (InstWord_t inst_hex);
   void RISCV_INST_MUL (InstWord_t inst_hex);
   void RISCV_INST_MULH (InstWord_t inst_hex);
   void RISCV_INST_MULHSU (InstWord_t inst_hex);
   void RISCV_INST_MULHU (InstWord_t inst_hex);
   void RISCV_INST_DIV (InstWord_t inst_hex);
   void RISCV_INST_DIVU (InstWord_t inst_hex);
   void RISCV_INST_REM (InstWord_t inst_hex);
   void RISCV_INST_REMU (InstWord_t inst_hex);
   void RISCV_INST_LR_W (InstWord_t inst_hex);
   void RISCV_INST_SC_W (InstWord_t inst_hex);
   void RISCV_INST_AMOSWAP_W (InstWord_t inst_hex);
   void RISCV_INST_AMOADD_W (InstWord_t inst_hex);
   void RISCV_INST_AMOXOR_W (InstWord_t inst_hex);
   void RISCV_INST_AMOAND_W (InstWord_t inst_hex);
   void RISCV_INST_AMOOR_W (InstWord_t inst_hex);
   void RISCV_INST_AMOMIN_W (InstWord_t inst_hex);
   void RISCV_INST_AMOMAX_W (InstWord_t inst_hex);
   void RISCV_INST_AMOMINU_W (InstWord_t inst_hex);
   void RISCV_INST_AMOMAXU_W (InstWord_t inst_hex);
   void RISCV_INST_FLW (InstWord_t inst_hex);
   void RISCV_INST_FSW (InstWord_t inst_hex);
   void RISCV_INST_FMADD_S (InstWord_t inst_hex);
   void RISCV_INST_FMSUB_S (InstWord_t inst_hex);
   void RISCV_INST_FNMSUB_S (InstWord_t inst_hex);
   void RISCV_INST_FNMADD_S (InstWord_t inst_hex);
   void RISCV_INST_FADD_S (InstWord_t inst_hex);
   void RISCV_INST_FSUB_S (InstWord_t inst_hex);
   void RISCV_INST_FMUL_S (InstWord_t inst_hex);
   void RISCV_INST_FDIV_S (InstWord_t inst_hex);
   void RISCV_INST_FSQRT_S (InstWord_t inst_hex);
   void RISCV_INST_FSGNJ_S (InstWord_t inst_hex);
   void RISCV_INST_FSGNJN_S (InstWord_t inst_hex);
   void RISCV_INST_FSGNJX_S (InstWord_t inst_hex);
   void RISCV_INST_FMIN_S (InstWord_t inst_hex);
   void RISCV_INST_FMAX_S (InstWord_t inst_hex);
   void RISCV_INST_FCVT_W_S (InstWord_t inst_hex);
   void RISCV_INST_FCVT_WU_S (InstWord_t inst_hex);
   void RISCV_INST_FMV_X_W (InstWord_t inst_hex);
   void RISCV_INST_FEQ_S (InstWord_t inst_hex);
   void RISCV_INST_FLT_S (InstWord_t inst_hex);
   void RISCV_INST_FLE_S (InstWord_t inst_hex);
   void RISCV_INST_FCLASS_S (InstWord_t inst_hex);
   void RISCV_INST_FCVT_S_W (InstWord_t inst_hex);
   void RISCV_INST_FCVT_S_WU (InstWord_t inst_hex);
   void RISCV_INST_FMV_W_X (InstWord_t inst_hex);
   void RISCV_INST_FLD (InstWord_t inst_hex);
   void RISCV_INST_FSD (InstWord_t inst_hex);
   void RISCV_INST_FMADD_D (InstWord_t inst_hex);
   void RISCV_INST_FMSUB_D (InstWord_t inst_hex);
   void RISCV_INST_FNMSUB_D (InstWord_t inst_hex);
   void RISCV_INST_FNMADD_D (InstWord_t inst_hex);
   void RISCV_INST_FADD_D (InstWord_t inst_hex);
   void RISCV_INST_FSUB_D (InstWord_t inst_hex);
   void RISCV_INST_FMUL_D (InstWord_t inst_hex);
   void RISCV_INST_FDIV_D (InstWord_t inst_hex);
   void RISCV_INST_FSQRT_D (InstWord_t inst_hex);
   void RISCV_INST_FSGNJ_D (InstWord_t inst_hex);
   void RISCV_INST_FSGNJN_D (InstWord_t inst_hex);
   void RISCV_INST_FSGNJX_D (InstWord_t inst_hex);
   void RISCV_INST_FMIN_D (InstWord_t inst_hex);
   void RISCV_INST_FMAX_D (InstWord_t inst_hex);
   void RISCV_INST_FCVT_S_D (InstWord_t inst_hex);
   void RISCV_INST_FCVT_D_S (InstWord_t inst_hex);
   void RISCV_INST_FEQ_D (InstWord_t inst_hex);
   void RISCV_INST_FLT_D (InstWord_t inst_hex);
   void RISCV_INST_FLE_D (InstWord_t inst_hex);
   void RISCV_INST_FCLASS_D (InstWord_t inst_hex);
   void RISCV_INST_FCVT_W_D (InstWord_t inst_hex);
   void RISCV_INST_FCVT_WU_D (InstWord_t inst_hex);
   void RISCV_INST_FCVT_D_W (InstWord_t inst_hex);
   void RISCV_INST_FCVT_D_WU (InstWord_t inst_hex);
   void RISCV_INST_CSRRW (InstWord_t inst_hex);
   void RISCV_INST_CSRRS (InstWord_t inst_hex);
   void RISCV_INST_CSRRC (InstWord_t inst_hex);
   void RISCV_INST_CSRRWI (InstWord_t inst_hex);
   void RISCV_INST_CSRRSI (InstWord_t inst_hex);
   void RISCV_INST_CSRRCI (InstWord_t inst_hex);
   void RISCV_INST_ECALL (InstWord_t inst_hex);
   void RISCV_INST_EBREAK (InstWord_t inst_hex);
   void RISCV_INST_URET (InstWord_t inst_hex);
   void RISCV_INST_SRET (InstWord_t inst_hex);
   void RISCV_INST_HRET (InstWord_t inst_hex);
   void RISCV_INST_MRET (InstWord_t inst_hex);
   void RISCV_INST_MRTS (InstWord_t inst_hex);
   void RISCV_INST_MRTH (InstWord_t inst_hex);
   void RISCV_INST_WFI (InstWord_t inst_hex);
   void RISCV_INST_SFENCE_VMA (InstWord_t inst_hex);
   void RISCV_INST_LWU (InstWord_t inst_hex);
   void RISCV_INST_LD (InstWord_t inst_hex);
   void RISCV_INST_SD (InstWord_t inst_hex);
   void RISCV_INST_ADDIW (InstWord_t inst_hex);
   void RISCV_INST_SLLIW (InstWord_t inst_hex);
   void RISCV_INST_SRLIW (InstWord_t inst_hex);
   void RISCV_INST_SRAIW (InstWord_t inst_hex);
   void RISCV_INST_ADDW (InstWord_t inst_hex);
   void RISCV_INST_SUBW (InstWord_t inst_hex);
   void RISCV_INST_SLLW (InstWord_t inst_hex);
   void RISCV_INST_SRLW (InstWord_t inst_hex);
   void RISCV_INST_SRAW (InstWord_t inst_hex);
   void RISCV_INST_MULW (InstWord_t inst_hex);
   void RISCV_INST_DIVW (InstWord_t inst_hex);
   void RISCV_INST_DIVUW (InstWord_t inst_hex);
   void RISCV_INST_REMW (InstWord_t inst_hex);
   void RISCV_INST_REMUW (InstWord_t inst_hex);
   void RISCV_INST_LR_D (InstWord_t inst_hex);
   void RISCV_INST_SC_D (InstWord_t inst_hex);
   void RISCV_INST_AMOSWAP_D (InstWord_t inst_hex);
   void RISCV_INST_AMOADD_D (InstWord_t inst_hex);
   void RISCV_INST_AMOXOR_D (InstWord_t inst_hex);
   void RISCV_INST_AMOAND_D (InstWord_t inst_hex);
   void RISCV_INST_AMOOR_D (InstWord_t inst_hex);
   void RISCV_INST_AMOMIN_D (InstWord_t inst_hex);
   void RISCV_INST_AMOMAX_D (InstWord_t inst_hex);
   void RISCV_INST_AMOMINU_D (InstWord_t inst_hex);
   void RISCV_INST_AMOMAXU_D (InstWord_t inst_hex);
   void RISCV_INST_FCVT_L_S (InstWord_t inst_hex);
   void RISCV_INST_FCVT_LU_S (InstWord_t inst_hex);
   void RISCV_INST_FCVT_S_L (InstWord_t inst_hex);
   void RISCV_INST_FCVT_S_LU (InstWord_t inst_hex);
   void RISCV_INST_FCVT_L_D (InstWord_t inst_hex);
   void RISCV_INST_FCVT_LU_D (InstWord_t inst_hex);
   void RISCV_INST_FMV_X_D (InstWord_t inst_hex);
   void RISCV_INST_FCVT_D_L (InstWord_t inst_hex);
   void RISCV_INST_FCVT_D_LU (InstWord_t inst_hex);
   void RISCV_INST_FMV_D_X (InstWord_t inst_hex);
   void RISCV_INST_C_ADDI4SPN (InstWord_t inst_hex);
   void RISCV_INST_C_FLD (InstWord_t inst_hex);
   void RISCV_INST_C_LW (InstWord_t inst_hex);
   void RISCV_INST_C_FLW (InstWord_t inst_hex);
   void RISCV_INST_C_LD (InstWord_t inst_hex);
   void RISCV_INST_C_FSD (InstWord_t inst_hex);
   void RISCV_INST_C_SW (InstWord_t inst_hex);
   void RISCV_INST_C_FSW (InstWord_t inst_hex);
   void RISCV_INST_C_SD (InstWord_t inst_hex);
   void RISCV_INST_C_NOP (InstWord_t inst_hex);
   void RISCV_INST_C_ADDI (InstWord_t inst_hex);
   void RISCV_INST_C_JAL (InstWord_t inst_hex);
   void RISCV_INST_C_ADDIW (InstWord_t inst_hex);
   void RISCV_INST_C_LI (InstWord_t inst_hex);
   void RISCV_INST_C_ADDI16SP (InstWord_t inst_hex);
   void RISCV_INST_C_LUI (InstWord_t inst_hex);
   void RISCV_INST_C_SRLI (InstWord_t inst_hex);
   void RISCV_INST_C_SRLI64 (InstWord_t inst_hex);
   void RISCV_INST_C_SRAI (InstWord_t inst_hex);
   void RISCV_INST_C_SRAI64 (InstWord_t inst_hex);
   void RISCV_INST_C_ANDI (InstWord_t inst_hex);
   void RISCV_INST_C_SUB (InstWord_t inst_hex);
   void RISCV_INST_C_XOR (InstWord_t inst_hex);
   void RISCV_INST_C_OR (InstWord_t inst_hex);
   void RISCV_INST_C_AND (InstWord_t inst_hex);
   void RISCV_INST_C_SUBW (InstWord_t inst_hex);
   void RISCV_INST_C_ADDW (InstWord_t inst_hex);
   void RISCV_INST_C_J (InstWord_t inst_hex);
   void RISCV_INST_C_BEQZ (InstWord_t inst_hex);
   void RISCV_INST_C_BNEZ (InstWord_t inst_hex);
   void RISCV_INST_C_SLLI (InstWord_t inst_hex);
   void RISCV_INST_C_FLDSP (InstWord_t inst_hex);
   void RISCV_INST_C_LWSP (InstWord_t inst_hex);
   void RISCV_INST_C_FLWSP (InstWord_t inst_hex);
   void RISCV_INST_C_LDSP (InstWord_t inst_hex);
   void RISCV_INST_C_JR (InstWord_t inst_hex);
   void RISCV_INST_C_MV (InstWord_t inst_hex);
   void RISCV_INST_C_EBREAK (InstWord_t inst_hex);
   void RISCV_INST_C_JALR (InstWord_t inst_hex);
   void RISCV_INST_C_ADD (InstWord_t inst_hex);
   void RISCV_INST_C_FSDSP (InstWord_t inst_hex);
   void RISCV_INST_C_SWSP (InstWord_t inst_hex);
   void RISCV_INST_C_FSWSP (InstWord_t inst_hex);
   void RISCV_INST_C_SDSP (InstWord_t inst_hex);
};
