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

#include "inst_list_riscv.hpp"
#include "inst_decoder_riscv.hpp"
#include "dec_utils_riscv.hpp"
#include "riscv_pe_thread.hpp"

InstId_t RiscvDec::DecodeInst_LD_10_F3_110_R3_00000_F2_00_R2_00000_R1_00000_RD_00001_OP_00000 (InstWord_t inst_hex)
{
  if (m_pe_thread->GetBitMode() == RiscvBitMode_t::Bit32) {
    return InstId_t::INST_ID_C_FLWSP;
  } else if (m_pe_thread->GetBitMode() == RiscvBitMode_t::Bit64) {
    return InstId_t::INST_ID_C_LDSP;
  } else {
    return InstId_t::INST_ID_SENTINEL_MAX;
  }
}


InstId_t RiscvDec::DecodeInst_LD_10_F3_110_R3_00000_F2_00_R2_00000_R1_00001_RD_00000_OP_00000 (InstWord_t inst_hex)
{
  if (m_pe_thread->GetBitMode() == RiscvBitMode_t::Bit32) {
    return InstId_t::INST_ID_C_FSWSP;
  } else if (m_pe_thread->GetBitMode() == RiscvBitMode_t::Bit64) {
    return InstId_t::INST_ID_C_SDSP;
  } else {
    return InstId_t::INST_ID_SENTINEL_MAX;
  }
}


InstId_t RiscvDec::DecodeInst_LD_00_R3_00000_F2_00_R2_00000_R1_00000_F3_110_RD_00000_OP_00000 (InstWord_t inst_hex)
{
  if (m_pe_thread->GetBitMode() == RiscvBitMode_t::Bit32) {
    return InstId_t::INST_ID_C_FLW;
  } else if (m_pe_thread->GetBitMode() == RiscvBitMode_t::Bit64) {
    return InstId_t::INST_ID_C_LD;
  } else {
    return InstId_t::INST_ID_SENTINEL_MAX;
  }
}


InstId_t RiscvDec::DecodeInst_LD_00_R3_00000_F2_00_R2_00000_R1_00001_F3_110_RD_00000_OP_00000 (InstWord_t inst_hex)
{
  if (m_pe_thread->GetBitMode() == RiscvBitMode_t::Bit32) {
    return InstId_t::INST_ID_C_FSW;
  } else if (m_pe_thread->GetBitMode() == RiscvBitMode_t::Bit64) {
    return InstId_t::INST_ID_C_SD;
  } else {
    return InstId_t::INST_ID_SENTINEL_MAX;
  }
}


InstId_t RiscvDec::DecodeInst_LD_01_F3_010_R3_00000_F2_00_R2_00000_R1_00000_RD_00000_OP_00000 (InstWord_t insnt_hex)
{
  if (m_pe_thread->GetBitMode() == RiscvBitMode_t::Bit32) {
    return InstId_t::INST_ID_C_JAL;
  } else if (m_pe_thread->GetBitMode() == RiscvBitMode_t::Bit64) {
    return InstId_t::INST_ID_C_ADDIW;
  } else {
    return InstId_t::INST_ID_SENTINEL_MAX;
  }
}
