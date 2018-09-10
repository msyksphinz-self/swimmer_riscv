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


#include <stdint.h>
#include "inst_list_riscv.hpp"
#include "inst_decoder_riscv.hpp"
uint32_t RiscvDec::GetDataLength (InstId_t inst_id)
{
  switch (inst_id) {
    case InstId_t::INST_ID_LUI : return 32;
    case InstId_t::INST_ID_AUIPC : return 32;
    case InstId_t::INST_ID_JAL : return 32;
    case InstId_t::INST_ID_JALR : return 32;
    case InstId_t::INST_ID_BEQ : return 32;
    case InstId_t::INST_ID_BNE : return 32;
    case InstId_t::INST_ID_BLT : return 32;
    case InstId_t::INST_ID_BGE : return 32;
    case InstId_t::INST_ID_BLTU : return 32;
    case InstId_t::INST_ID_BGEU : return 32;
    case InstId_t::INST_ID_LB : return 32;
    case InstId_t::INST_ID_LH : return 32;
    case InstId_t::INST_ID_LW : return 32;
    case InstId_t::INST_ID_LBU : return 32;
    case InstId_t::INST_ID_LHU : return 32;
    case InstId_t::INST_ID_SB : return 32;
    case InstId_t::INST_ID_SH : return 32;
    case InstId_t::INST_ID_SW : return 32;
    case InstId_t::INST_ID_ADDI : return 32;
    case InstId_t::INST_ID_SLTI : return 32;
    case InstId_t::INST_ID_SLTIU : return 32;
    case InstId_t::INST_ID_XORI : return 32;
    case InstId_t::INST_ID_ORI : return 32;
    case InstId_t::INST_ID_ANDI : return 32;
    case InstId_t::INST_ID_SLLI : return 32;
    case InstId_t::INST_ID_SRLI : return 32;
    case InstId_t::INST_ID_SRAI : return 32;
    case InstId_t::INST_ID_ADD : return 32;
    case InstId_t::INST_ID_SUB : return 32;
    case InstId_t::INST_ID_SLL : return 32;
    case InstId_t::INST_ID_SLT : return 32;
    case InstId_t::INST_ID_SLTU : return 32;
    case InstId_t::INST_ID_XOR : return 32;
    case InstId_t::INST_ID_SRL : return 32;
    case InstId_t::INST_ID_SRA : return 32;
    case InstId_t::INST_ID_OR : return 32;
    case InstId_t::INST_ID_AND : return 32;
    case InstId_t::INST_ID_FENCE : return 32;
    case InstId_t::INST_ID_FENCE_I : return 32;
    case InstId_t::INST_ID_MUL : return 32;
    case InstId_t::INST_ID_MULH : return 32;
    case InstId_t::INST_ID_MULHSU : return 32;
    case InstId_t::INST_ID_MULHU : return 32;
    case InstId_t::INST_ID_DIV : return 32;
    case InstId_t::INST_ID_DIVU : return 32;
    case InstId_t::INST_ID_REM : return 32;
    case InstId_t::INST_ID_REMU : return 32;
    case InstId_t::INST_ID_LR_W : return 32;
    case InstId_t::INST_ID_SC_W : return 32;
    case InstId_t::INST_ID_AMOSWAP_W : return 32;
    case InstId_t::INST_ID_AMOADD_W : return 32;
    case InstId_t::INST_ID_AMOXOR_W : return 32;
    case InstId_t::INST_ID_AMOAND_W : return 32;
    case InstId_t::INST_ID_AMOOR_W : return 32;
    case InstId_t::INST_ID_AMOMIN_W : return 32;
    case InstId_t::INST_ID_AMOMAX_W : return 32;
    case InstId_t::INST_ID_AMOMINU_W : return 32;
    case InstId_t::INST_ID_AMOMAXU_W : return 32;
    case InstId_t::INST_ID_FLW : return 32;
    case InstId_t::INST_ID_FSW : return 32;
    case InstId_t::INST_ID_FMADD_S : return 32;
    case InstId_t::INST_ID_FMSUB_S : return 32;
    case InstId_t::INST_ID_FNMSUB_S : return 32;
    case InstId_t::INST_ID_FNMADD_S : return 32;
    case InstId_t::INST_ID_FADD_S : return 32;
    case InstId_t::INST_ID_FSUB_S : return 32;
    case InstId_t::INST_ID_FMUL_S : return 32;
    case InstId_t::INST_ID_FDIV_S : return 32;
    case InstId_t::INST_ID_FSQRT_S : return 32;
    case InstId_t::INST_ID_FSGNJ_S : return 32;
    case InstId_t::INST_ID_FSGNJN_S : return 32;
    case InstId_t::INST_ID_FSGNJX_S : return 32;
    case InstId_t::INST_ID_FMIN_S : return 32;
    case InstId_t::INST_ID_FMAX_S : return 32;
    case InstId_t::INST_ID_FCVT_W_S : return 32;
    case InstId_t::INST_ID_FCVT_WU_S : return 32;
    case InstId_t::INST_ID_FMV_X_W : return 32;
    case InstId_t::INST_ID_FEQ_S : return 32;
    case InstId_t::INST_ID_FLT_S : return 32;
    case InstId_t::INST_ID_FLE_S : return 32;
    case InstId_t::INST_ID_FCLASS_S : return 32;
    case InstId_t::INST_ID_FCVT_S_W : return 32;
    case InstId_t::INST_ID_FCVT_S_WU : return 32;
    case InstId_t::INST_ID_FMV_W_X : return 32;
    case InstId_t::INST_ID_FLD : return 32;
    case InstId_t::INST_ID_FSD : return 32;
    case InstId_t::INST_ID_FMADD_D : return 32;
    case InstId_t::INST_ID_FMSUB_D : return 32;
    case InstId_t::INST_ID_FNMSUB_D : return 32;
    case InstId_t::INST_ID_FNMADD_D : return 32;
    case InstId_t::INST_ID_FADD_D : return 32;
    case InstId_t::INST_ID_FSUB_D : return 32;
    case InstId_t::INST_ID_FMUL_D : return 32;
    case InstId_t::INST_ID_FDIV_D : return 32;
    case InstId_t::INST_ID_FSQRT_D : return 32;
    case InstId_t::INST_ID_FSGNJ_D : return 32;
    case InstId_t::INST_ID_FSGNJN_D : return 32;
    case InstId_t::INST_ID_FSGNJX_D : return 32;
    case InstId_t::INST_ID_FMIN_D : return 32;
    case InstId_t::INST_ID_FMAX_D : return 32;
    case InstId_t::INST_ID_FCVT_S_D : return 32;
    case InstId_t::INST_ID_FCVT_D_S : return 32;
    case InstId_t::INST_ID_FEQ_D : return 32;
    case InstId_t::INST_ID_FLT_D : return 32;
    case InstId_t::INST_ID_FLE_D : return 32;
    case InstId_t::INST_ID_FCLASS_D : return 32;
    case InstId_t::INST_ID_FCVT_W_D : return 32;
    case InstId_t::INST_ID_FCVT_WU_D : return 32;
    case InstId_t::INST_ID_FCVT_D_W : return 32;
    case InstId_t::INST_ID_FCVT_D_WU : return 32;
    case InstId_t::INST_ID_CSRRW : return 32;
    case InstId_t::INST_ID_CSRRS : return 32;
    case InstId_t::INST_ID_CSRRC : return 32;
    case InstId_t::INST_ID_CSRRWI : return 32;
    case InstId_t::INST_ID_CSRRSI : return 32;
    case InstId_t::INST_ID_CSRRCI : return 32;
    case InstId_t::INST_ID_ECALL : return 32;
    case InstId_t::INST_ID_EBREAK : return 32;
    case InstId_t::INST_ID_URET : return 32;
    case InstId_t::INST_ID_SRET : return 32;
    case InstId_t::INST_ID_HRET : return 32;
    case InstId_t::INST_ID_MRET : return 32;
    case InstId_t::INST_ID_MRTS : return 32;
    case InstId_t::INST_ID_MRTH : return 32;
    case InstId_t::INST_ID_WFI : return 32;
    case InstId_t::INST_ID_SFENCE_VMA : return 32;
    case InstId_t::INST_ID_LWU : return 32;
    case InstId_t::INST_ID_LD : return 32;
    case InstId_t::INST_ID_SD : return 32;
    case InstId_t::INST_ID_ADDIW : return 32;
    case InstId_t::INST_ID_SLLIW : return 32;
    case InstId_t::INST_ID_SRLIW : return 32;
    case InstId_t::INST_ID_SRAIW : return 32;
    case InstId_t::INST_ID_ADDW : return 32;
    case InstId_t::INST_ID_SUBW : return 32;
    case InstId_t::INST_ID_SLLW : return 32;
    case InstId_t::INST_ID_SRLW : return 32;
    case InstId_t::INST_ID_SRAW : return 32;
    case InstId_t::INST_ID_MULW : return 32;
    case InstId_t::INST_ID_DIVW : return 32;
    case InstId_t::INST_ID_DIVUW : return 32;
    case InstId_t::INST_ID_REMW : return 32;
    case InstId_t::INST_ID_REMUW : return 32;
    case InstId_t::INST_ID_LR_D : return 32;
    case InstId_t::INST_ID_SC_D : return 32;
    case InstId_t::INST_ID_AMOSWAP_D : return 32;
    case InstId_t::INST_ID_AMOADD_D : return 32;
    case InstId_t::INST_ID_AMOXOR_D : return 32;
    case InstId_t::INST_ID_AMOAND_D : return 32;
    case InstId_t::INST_ID_AMOOR_D : return 32;
    case InstId_t::INST_ID_AMOMIN_D : return 32;
    case InstId_t::INST_ID_AMOMAX_D : return 32;
    case InstId_t::INST_ID_AMOMINU_D : return 32;
    case InstId_t::INST_ID_AMOMAXU_D : return 32;
    case InstId_t::INST_ID_FCVT_L_S : return 32;
    case InstId_t::INST_ID_FCVT_LU_S : return 32;
    case InstId_t::INST_ID_FCVT_S_L : return 32;
    case InstId_t::INST_ID_FCVT_S_LU : return 32;
    case InstId_t::INST_ID_FCVT_L_D : return 32;
    case InstId_t::INST_ID_FCVT_LU_D : return 32;
    case InstId_t::INST_ID_FMV_X_D : return 32;
    case InstId_t::INST_ID_FCVT_D_L : return 32;
    case InstId_t::INST_ID_FCVT_D_LU : return 32;
    case InstId_t::INST_ID_FMV_D_X : return 32;
    case InstId_t::INST_ID_C_ADDI4SPN : return 32;
    case InstId_t::INST_ID_C_FLD : return 32;
    case InstId_t::INST_ID_C_LW : return 32;
    case InstId_t::INST_ID_C_FLW : return 32;
    case InstId_t::INST_ID_C_LD : return 32;
    case InstId_t::INST_ID_C_FSD : return 32;
    case InstId_t::INST_ID_C_SW : return 32;
    case InstId_t::INST_ID_C_FSW : return 32;
    case InstId_t::INST_ID_C_SD : return 32;
    case InstId_t::INST_ID_C_NOP : return 32;
    case InstId_t::INST_ID_C_ADDI : return 32;
    case InstId_t::INST_ID_C_JAL : return 32;
    case InstId_t::INST_ID_C_ADDIW : return 32;
    case InstId_t::INST_ID_C_LI : return 32;
    case InstId_t::INST_ID_C_ADDI16SP : return 32;
    case InstId_t::INST_ID_C_LUI : return 32;
    case InstId_t::INST_ID_C_SRLI : return 32;
    case InstId_t::INST_ID_C_SRLI64 : return 32;
    case InstId_t::INST_ID_C_SRAI : return 32;
    case InstId_t::INST_ID_C_SRAI64 : return 32;
    case InstId_t::INST_ID_C_ANDI : return 32;
    case InstId_t::INST_ID_C_SUB : return 32;
    case InstId_t::INST_ID_C_XOR : return 32;
    case InstId_t::INST_ID_C_OR : return 32;
    case InstId_t::INST_ID_C_AND : return 32;
    case InstId_t::INST_ID_C_SUBW : return 32;
    case InstId_t::INST_ID_C_ADDW : return 32;
    case InstId_t::INST_ID_C_J : return 32;
    case InstId_t::INST_ID_C_BEQZ : return 32;
    case InstId_t::INST_ID_C_BNEZ : return 32;
    case InstId_t::INST_ID_C_SLLI : return 32;
    case InstId_t::INST_ID_C_FLDSP : return 32;
    case InstId_t::INST_ID_C_LWSP : return 32;
    case InstId_t::INST_ID_C_FLWSP : return 32;
    case InstId_t::INST_ID_C_LDSP : return 32;
    case InstId_t::INST_ID_C_JR : return 32;
    case InstId_t::INST_ID_C_MV : return 32;
    case InstId_t::INST_ID_C_EBREAK : return 32;
    case InstId_t::INST_ID_C_JALR : return 32;
    case InstId_t::INST_ID_C_ADD : return 32;
    case InstId_t::INST_ID_C_FSDSP : return 32;
    case InstId_t::INST_ID_C_SWSP : return 32;
    case InstId_t::INST_ID_C_FSWSP : return 32;
    case InstId_t::INST_ID_C_SDSP : return 32;
    default: fprintf(stderr, "<Internal Error. Can't get DLength of InstId=%d. Exit.>\n", static_cast<uint32_t>(inst_id)); exit(EXIT_FAILURE);
  }
}

