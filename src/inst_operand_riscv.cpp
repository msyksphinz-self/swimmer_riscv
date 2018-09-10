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
#include "inst_operand_riscv.hpp"


operandList inst_operand[208];


void FormatOperand (void)
{
  // InstId_t::INST_ID_LUI
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LUI)].size = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LUI)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LUI)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LUI)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LUI)].connect[0] = 0;
  // ["r[11:7]", "h[31:12]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LUI)].type_lst[1] = operandType::operandTypeHex;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LUI)].msb_lst[1] = 31;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LUI)].lsb_lst[1] = 12;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LUI)].connect[1] = 0;
  // ["r[11:7]", "h[31:12]"]
  // InstId_t::INST_ID_AUIPC
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AUIPC)].size = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AUIPC)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AUIPC)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AUIPC)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AUIPC)].connect[0] = 0;
  // ["r[11:7]", "h[31:12]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AUIPC)].type_lst[1] = operandType::operandTypeHex;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AUIPC)].msb_lst[1] = 31;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AUIPC)].lsb_lst[1] = 12;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AUIPC)].connect[1] = 0;
  // ["r[11:7]", "h[31:12]"]
  // InstId_t::INST_ID_JAL
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_JAL)].size = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_JAL)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_JAL)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_JAL)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_JAL)].connect[0] = 0;
  // ["r[11:7]", "uj[31:12]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_JAL)].type_lst[1] = operandType::operandTypeUnSignJ;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_JAL)].msb_lst[1] = 31;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_JAL)].lsb_lst[1] = 12;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_JAL)].connect[1] = 0;
  // ["r[11:7]", "uj[31:12]"]
  // InstId_t::INST_ID_JALR
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_JALR)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_JALR)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_JALR)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_JALR)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_JALR)].connect[0] = 0;
  // ["r[11:7]", "r[19:15]", "h[11:0]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_JALR)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_JALR)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_JALR)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_JALR)].connect[1] = 0;
  // ["r[11:7]", "r[19:15]", "h[11:0]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_JALR)].type_lst[2] = operandType::operandTypeHex;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_JALR)].msb_lst[2] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_JALR)].lsb_lst[2] = 0;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_JALR)].connect[2] = 0;
  // ["r[11:7]", "r[19:15]", "h[11:0]"]
  // InstId_t::INST_ID_BEQ
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BEQ)].size = 6;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BEQ)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BEQ)].msb_lst[0] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BEQ)].lsb_lst[0] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BEQ)].connect[0] = 0;
  // ["r[19:15]", "r[24:20]", "u[31:31]|", "u[7:7]|", "u[30:25]|", "u[11:8]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BEQ)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BEQ)].msb_lst[1] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BEQ)].lsb_lst[1] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BEQ)].connect[1] = 0;
  // ["r[19:15]", "r[24:20]", "u[31:31]|", "u[7:7]|", "u[30:25]|", "u[11:8]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BEQ)].type_lst[2] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BEQ)].msb_lst[2] = 31;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BEQ)].lsb_lst[2] = 31;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BEQ)].connect[2] = 1;
  // ["r[19:15]", "r[24:20]", "u[31:31]|", "u[7:7]|", "u[30:25]|", "u[11:8]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BEQ)].type_lst[3] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BEQ)].msb_lst[3] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BEQ)].lsb_lst[3] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BEQ)].connect[3] = 1;
  // ["r[19:15]", "r[24:20]", "u[31:31]|", "u[7:7]|", "u[30:25]|", "u[11:8]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BEQ)].type_lst[4] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BEQ)].msb_lst[4] = 30;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BEQ)].lsb_lst[4] = 25;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BEQ)].connect[4] = 1;
  // ["r[19:15]", "r[24:20]", "u[31:31]|", "u[7:7]|", "u[30:25]|", "u[11:8]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BEQ)].type_lst[5] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BEQ)].msb_lst[5] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BEQ)].lsb_lst[5] = 8;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BEQ)].connect[5] = 0;
  // ["r[19:15]", "r[24:20]", "u[31:31]|", "u[7:7]|", "u[30:25]|", "u[11:8]"]
  // InstId_t::INST_ID_BNE
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BNE)].size = 6;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BNE)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BNE)].msb_lst[0] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BNE)].lsb_lst[0] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BNE)].connect[0] = 0;
  // ["r[19:15]", "r[24:20]", "u[31:31]|", "u[7:7]|", "u[30:25]|", "u[11:8]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BNE)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BNE)].msb_lst[1] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BNE)].lsb_lst[1] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BNE)].connect[1] = 0;
  // ["r[19:15]", "r[24:20]", "u[31:31]|", "u[7:7]|", "u[30:25]|", "u[11:8]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BNE)].type_lst[2] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BNE)].msb_lst[2] = 31;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BNE)].lsb_lst[2] = 31;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BNE)].connect[2] = 1;
  // ["r[19:15]", "r[24:20]", "u[31:31]|", "u[7:7]|", "u[30:25]|", "u[11:8]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BNE)].type_lst[3] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BNE)].msb_lst[3] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BNE)].lsb_lst[3] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BNE)].connect[3] = 1;
  // ["r[19:15]", "r[24:20]", "u[31:31]|", "u[7:7]|", "u[30:25]|", "u[11:8]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BNE)].type_lst[4] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BNE)].msb_lst[4] = 30;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BNE)].lsb_lst[4] = 25;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BNE)].connect[4] = 1;
  // ["r[19:15]", "r[24:20]", "u[31:31]|", "u[7:7]|", "u[30:25]|", "u[11:8]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BNE)].type_lst[5] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BNE)].msb_lst[5] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BNE)].lsb_lst[5] = 8;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BNE)].connect[5] = 0;
  // ["r[19:15]", "r[24:20]", "u[31:31]|", "u[7:7]|", "u[30:25]|", "u[11:8]"]
  // InstId_t::INST_ID_BLT
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BLT)].size = 6;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BLT)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BLT)].msb_lst[0] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BLT)].lsb_lst[0] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BLT)].connect[0] = 0;
  // ["r[19:15]", "r[24:20]", "u[31:31]|", "u[7:7]|", "u[30:25]|", "u[11:8]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BLT)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BLT)].msb_lst[1] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BLT)].lsb_lst[1] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BLT)].connect[1] = 0;
  // ["r[19:15]", "r[24:20]", "u[31:31]|", "u[7:7]|", "u[30:25]|", "u[11:8]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BLT)].type_lst[2] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BLT)].msb_lst[2] = 31;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BLT)].lsb_lst[2] = 31;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BLT)].connect[2] = 1;
  // ["r[19:15]", "r[24:20]", "u[31:31]|", "u[7:7]|", "u[30:25]|", "u[11:8]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BLT)].type_lst[3] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BLT)].msb_lst[3] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BLT)].lsb_lst[3] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BLT)].connect[3] = 1;
  // ["r[19:15]", "r[24:20]", "u[31:31]|", "u[7:7]|", "u[30:25]|", "u[11:8]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BLT)].type_lst[4] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BLT)].msb_lst[4] = 30;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BLT)].lsb_lst[4] = 25;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BLT)].connect[4] = 1;
  // ["r[19:15]", "r[24:20]", "u[31:31]|", "u[7:7]|", "u[30:25]|", "u[11:8]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BLT)].type_lst[5] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BLT)].msb_lst[5] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BLT)].lsb_lst[5] = 8;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BLT)].connect[5] = 0;
  // ["r[19:15]", "r[24:20]", "u[31:31]|", "u[7:7]|", "u[30:25]|", "u[11:8]"]
  // InstId_t::INST_ID_BGE
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BGE)].size = 6;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BGE)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BGE)].msb_lst[0] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BGE)].lsb_lst[0] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BGE)].connect[0] = 0;
  // ["r[19:15]", "r[24:20]", "u[31:31]|", "u[7:7]|", "u[30:25]|", "u[11:8]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BGE)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BGE)].msb_lst[1] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BGE)].lsb_lst[1] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BGE)].connect[1] = 0;
  // ["r[19:15]", "r[24:20]", "u[31:31]|", "u[7:7]|", "u[30:25]|", "u[11:8]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BGE)].type_lst[2] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BGE)].msb_lst[2] = 31;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BGE)].lsb_lst[2] = 31;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BGE)].connect[2] = 1;
  // ["r[19:15]", "r[24:20]", "u[31:31]|", "u[7:7]|", "u[30:25]|", "u[11:8]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BGE)].type_lst[3] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BGE)].msb_lst[3] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BGE)].lsb_lst[3] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BGE)].connect[3] = 1;
  // ["r[19:15]", "r[24:20]", "u[31:31]|", "u[7:7]|", "u[30:25]|", "u[11:8]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BGE)].type_lst[4] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BGE)].msb_lst[4] = 30;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BGE)].lsb_lst[4] = 25;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BGE)].connect[4] = 1;
  // ["r[19:15]", "r[24:20]", "u[31:31]|", "u[7:7]|", "u[30:25]|", "u[11:8]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BGE)].type_lst[5] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BGE)].msb_lst[5] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BGE)].lsb_lst[5] = 8;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BGE)].connect[5] = 0;
  // ["r[19:15]", "r[24:20]", "u[31:31]|", "u[7:7]|", "u[30:25]|", "u[11:8]"]
  // InstId_t::INST_ID_BLTU
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BLTU)].size = 6;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BLTU)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BLTU)].msb_lst[0] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BLTU)].lsb_lst[0] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BLTU)].connect[0] = 0;
  // ["r[19:15]", "r[24:20]", "u[31:31]|", "u[7:7]|", "u[30:25]|", "u[11:8]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BLTU)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BLTU)].msb_lst[1] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BLTU)].lsb_lst[1] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BLTU)].connect[1] = 0;
  // ["r[19:15]", "r[24:20]", "u[31:31]|", "u[7:7]|", "u[30:25]|", "u[11:8]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BLTU)].type_lst[2] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BLTU)].msb_lst[2] = 31;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BLTU)].lsb_lst[2] = 31;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BLTU)].connect[2] = 1;
  // ["r[19:15]", "r[24:20]", "u[31:31]|", "u[7:7]|", "u[30:25]|", "u[11:8]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BLTU)].type_lst[3] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BLTU)].msb_lst[3] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BLTU)].lsb_lst[3] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BLTU)].connect[3] = 1;
  // ["r[19:15]", "r[24:20]", "u[31:31]|", "u[7:7]|", "u[30:25]|", "u[11:8]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BLTU)].type_lst[4] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BLTU)].msb_lst[4] = 30;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BLTU)].lsb_lst[4] = 25;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BLTU)].connect[4] = 1;
  // ["r[19:15]", "r[24:20]", "u[31:31]|", "u[7:7]|", "u[30:25]|", "u[11:8]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BLTU)].type_lst[5] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BLTU)].msb_lst[5] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BLTU)].lsb_lst[5] = 8;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BLTU)].connect[5] = 0;
  // ["r[19:15]", "r[24:20]", "u[31:31]|", "u[7:7]|", "u[30:25]|", "u[11:8]"]
  // InstId_t::INST_ID_BGEU
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BGEU)].size = 6;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BGEU)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BGEU)].msb_lst[0] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BGEU)].lsb_lst[0] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BGEU)].connect[0] = 0;
  // ["r[19:15]", "r[24:20]", "u[31:31]|", "u[7:7]|", "u[30:25]|", "u[11:8]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BGEU)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BGEU)].msb_lst[1] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BGEU)].lsb_lst[1] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BGEU)].connect[1] = 0;
  // ["r[19:15]", "r[24:20]", "u[31:31]|", "u[7:7]|", "u[30:25]|", "u[11:8]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BGEU)].type_lst[2] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BGEU)].msb_lst[2] = 31;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BGEU)].lsb_lst[2] = 31;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BGEU)].connect[2] = 1;
  // ["r[19:15]", "r[24:20]", "u[31:31]|", "u[7:7]|", "u[30:25]|", "u[11:8]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BGEU)].type_lst[3] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BGEU)].msb_lst[3] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BGEU)].lsb_lst[3] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BGEU)].connect[3] = 1;
  // ["r[19:15]", "r[24:20]", "u[31:31]|", "u[7:7]|", "u[30:25]|", "u[11:8]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BGEU)].type_lst[4] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BGEU)].msb_lst[4] = 30;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BGEU)].lsb_lst[4] = 25;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BGEU)].connect[4] = 1;
  // ["r[19:15]", "r[24:20]", "u[31:31]|", "u[7:7]|", "u[30:25]|", "u[11:8]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BGEU)].type_lst[5] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BGEU)].msb_lst[5] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BGEU)].lsb_lst[5] = 8;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_BGEU)].connect[5] = 0;
  // ["r[19:15]", "r[24:20]", "u[31:31]|", "u[7:7]|", "u[30:25]|", "u[11:8]"]
  // InstId_t::INST_ID_LB
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LB)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LB)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LB)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LB)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LB)].connect[0] = 0;
  // ["r[11:7]", "h[31:20]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LB)].type_lst[1] = operandType::operandTypeHex;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LB)].msb_lst[1] = 31;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LB)].lsb_lst[1] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LB)].connect[1] = 0;
  // ["r[11:7]", "h[31:20]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LB)].type_lst[2] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LB)].msb_lst[2] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LB)].lsb_lst[2] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LB)].connect[2] = 0;
  // ["r[11:7]", "h[31:20]", "r[19:15]"]
  // InstId_t::INST_ID_LH
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LH)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LH)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LH)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LH)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LH)].connect[0] = 0;
  // ["r[11:7]", "h[31:20]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LH)].type_lst[1] = operandType::operandTypeHex;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LH)].msb_lst[1] = 31;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LH)].lsb_lst[1] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LH)].connect[1] = 0;
  // ["r[11:7]", "h[31:20]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LH)].type_lst[2] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LH)].msb_lst[2] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LH)].lsb_lst[2] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LH)].connect[2] = 0;
  // ["r[11:7]", "h[31:20]", "r[19:15]"]
  // InstId_t::INST_ID_LW
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LW)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LW)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LW)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LW)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LW)].connect[0] = 0;
  // ["r[11:7]", "h[31:20]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LW)].type_lst[1] = operandType::operandTypeHex;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LW)].msb_lst[1] = 31;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LW)].lsb_lst[1] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LW)].connect[1] = 0;
  // ["r[11:7]", "h[31:20]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LW)].type_lst[2] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LW)].msb_lst[2] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LW)].lsb_lst[2] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LW)].connect[2] = 0;
  // ["r[11:7]", "h[31:20]", "r[19:15]"]
  // InstId_t::INST_ID_LBU
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LBU)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LBU)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LBU)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LBU)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LBU)].connect[0] = 0;
  // ["r[11:7]", "h[31:20]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LBU)].type_lst[1] = operandType::operandTypeHex;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LBU)].msb_lst[1] = 31;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LBU)].lsb_lst[1] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LBU)].connect[1] = 0;
  // ["r[11:7]", "h[31:20]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LBU)].type_lst[2] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LBU)].msb_lst[2] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LBU)].lsb_lst[2] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LBU)].connect[2] = 0;
  // ["r[11:7]", "h[31:20]", "r[19:15]"]
  // InstId_t::INST_ID_LHU
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LHU)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LHU)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LHU)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LHU)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LHU)].connect[0] = 0;
  // ["r[11:7]", "h[31:20]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LHU)].type_lst[1] = operandType::operandTypeHex;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LHU)].msb_lst[1] = 31;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LHU)].lsb_lst[1] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LHU)].connect[1] = 0;
  // ["r[11:7]", "h[31:20]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LHU)].type_lst[2] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LHU)].msb_lst[2] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LHU)].lsb_lst[2] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LHU)].connect[2] = 0;
  // ["r[11:7]", "h[31:20]", "r[19:15]"]
  // InstId_t::INST_ID_SB
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SB)].size = 4;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SB)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SB)].msb_lst[0] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SB)].lsb_lst[0] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SB)].connect[0] = 0;
  // ["r[24:20]", "h[31:25]|", "h[11:7]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SB)].type_lst[1] = operandType::operandTypeHex;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SB)].msb_lst[1] = 31;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SB)].lsb_lst[1] = 25;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SB)].connect[1] = 1;
  // ["r[24:20]", "h[31:25]|", "h[11:7]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SB)].type_lst[2] = operandType::operandTypeHex;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SB)].msb_lst[2] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SB)].lsb_lst[2] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SB)].connect[2] = 0;
  // ["r[24:20]", "h[31:25]|", "h[11:7]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SB)].type_lst[3] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SB)].msb_lst[3] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SB)].lsb_lst[3] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SB)].connect[3] = 0;
  // ["r[24:20]", "h[31:25]|", "h[11:7]", "r[19:15]"]
  // InstId_t::INST_ID_SH
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SH)].size = 4;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SH)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SH)].msb_lst[0] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SH)].lsb_lst[0] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SH)].connect[0] = 0;
  // ["r[24:20]", "h[31:25]|", "h[11:7]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SH)].type_lst[1] = operandType::operandTypeHex;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SH)].msb_lst[1] = 31;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SH)].lsb_lst[1] = 25;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SH)].connect[1] = 1;
  // ["r[24:20]", "h[31:25]|", "h[11:7]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SH)].type_lst[2] = operandType::operandTypeHex;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SH)].msb_lst[2] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SH)].lsb_lst[2] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SH)].connect[2] = 0;
  // ["r[24:20]", "h[31:25]|", "h[11:7]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SH)].type_lst[3] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SH)].msb_lst[3] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SH)].lsb_lst[3] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SH)].connect[3] = 0;
  // ["r[24:20]", "h[31:25]|", "h[11:7]", "r[19:15]"]
  // InstId_t::INST_ID_SW
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SW)].size = 4;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SW)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SW)].msb_lst[0] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SW)].lsb_lst[0] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SW)].connect[0] = 0;
  // ["r[24:20]", "h[31:25]|", "h[11:7]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SW)].type_lst[1] = operandType::operandTypeHex;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SW)].msb_lst[1] = 31;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SW)].lsb_lst[1] = 25;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SW)].connect[1] = 1;
  // ["r[24:20]", "h[31:25]|", "h[11:7]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SW)].type_lst[2] = operandType::operandTypeHex;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SW)].msb_lst[2] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SW)].lsb_lst[2] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SW)].connect[2] = 0;
  // ["r[24:20]", "h[31:25]|", "h[11:7]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SW)].type_lst[3] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SW)].msb_lst[3] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SW)].lsb_lst[3] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SW)].connect[3] = 0;
  // ["r[24:20]", "h[31:25]|", "h[11:7]", "r[19:15]"]
  // InstId_t::INST_ID_ADDI
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ADDI)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ADDI)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ADDI)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ADDI)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ADDI)].connect[0] = 0;
  // ["r[11:7]", "r[19:15]", "h[31:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ADDI)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ADDI)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ADDI)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ADDI)].connect[1] = 0;
  // ["r[11:7]", "r[19:15]", "h[31:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ADDI)].type_lst[2] = operandType::operandTypeHex;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ADDI)].msb_lst[2] = 31;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ADDI)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ADDI)].connect[2] = 0;
  // ["r[11:7]", "r[19:15]", "h[31:20]"]
  // InstId_t::INST_ID_SLTI
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLTI)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLTI)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLTI)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLTI)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLTI)].connect[0] = 0;
  // ["r[11:7]", "r[19:15]", "h[31:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLTI)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLTI)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLTI)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLTI)].connect[1] = 0;
  // ["r[11:7]", "r[19:15]", "h[31:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLTI)].type_lst[2] = operandType::operandTypeHex;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLTI)].msb_lst[2] = 31;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLTI)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLTI)].connect[2] = 0;
  // ["r[11:7]", "r[19:15]", "h[31:20]"]
  // InstId_t::INST_ID_SLTIU
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLTIU)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLTIU)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLTIU)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLTIU)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLTIU)].connect[0] = 0;
  // ["r[11:7]", "r[19:15]", "h[31:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLTIU)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLTIU)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLTIU)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLTIU)].connect[1] = 0;
  // ["r[11:7]", "r[19:15]", "h[31:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLTIU)].type_lst[2] = operandType::operandTypeHex;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLTIU)].msb_lst[2] = 31;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLTIU)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLTIU)].connect[2] = 0;
  // ["r[11:7]", "r[19:15]", "h[31:20]"]
  // InstId_t::INST_ID_XORI
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_XORI)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_XORI)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_XORI)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_XORI)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_XORI)].connect[0] = 0;
  // ["r[11:7]", "r[19:15]", "h[31:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_XORI)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_XORI)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_XORI)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_XORI)].connect[1] = 0;
  // ["r[11:7]", "r[19:15]", "h[31:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_XORI)].type_lst[2] = operandType::operandTypeHex;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_XORI)].msb_lst[2] = 31;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_XORI)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_XORI)].connect[2] = 0;
  // ["r[11:7]", "r[19:15]", "h[31:20]"]
  // InstId_t::INST_ID_ORI
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ORI)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ORI)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ORI)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ORI)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ORI)].connect[0] = 0;
  // ["r[11:7]", "r[19:15]", "h[31:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ORI)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ORI)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ORI)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ORI)].connect[1] = 0;
  // ["r[11:7]", "r[19:15]", "h[31:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ORI)].type_lst[2] = operandType::operandTypeHex;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ORI)].msb_lst[2] = 31;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ORI)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ORI)].connect[2] = 0;
  // ["r[11:7]", "r[19:15]", "h[31:20]"]
  // InstId_t::INST_ID_ANDI
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ANDI)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ANDI)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ANDI)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ANDI)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ANDI)].connect[0] = 0;
  // ["r[11:7]", "r[19:15]", "h[31:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ANDI)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ANDI)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ANDI)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ANDI)].connect[1] = 0;
  // ["r[11:7]", "r[19:15]", "h[31:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ANDI)].type_lst[2] = operandType::operandTypeHex;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ANDI)].msb_lst[2] = 31;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ANDI)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ANDI)].connect[2] = 0;
  // ["r[11:7]", "r[19:15]", "h[31:20]"]
  // InstId_t::INST_ID_SLLI
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLLI)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLLI)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLLI)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLLI)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLLI)].connect[0] = 0;
  // ["r[11:7]", "r[19:15]", "h[25:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLLI)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLLI)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLLI)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLLI)].connect[1] = 0;
  // ["r[11:7]", "r[19:15]", "h[25:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLLI)].type_lst[2] = operandType::operandTypeHex;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLLI)].msb_lst[2] = 25;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLLI)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLLI)].connect[2] = 0;
  // ["r[11:7]", "r[19:15]", "h[25:20]"]
  // InstId_t::INST_ID_SRLI
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRLI)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRLI)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRLI)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRLI)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRLI)].connect[0] = 0;
  // ["r[11:7]", "r[19:15]", "h[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRLI)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRLI)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRLI)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRLI)].connect[1] = 0;
  // ["r[11:7]", "r[19:15]", "h[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRLI)].type_lst[2] = operandType::operandTypeHex;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRLI)].msb_lst[2] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRLI)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRLI)].connect[2] = 0;
  // ["r[11:7]", "r[19:15]", "h[24:20]"]
  // InstId_t::INST_ID_SRAI
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRAI)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRAI)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRAI)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRAI)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRAI)].connect[0] = 0;
  // ["r[11:7]", "r[19:15]", "h[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRAI)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRAI)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRAI)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRAI)].connect[1] = 0;
  // ["r[11:7]", "r[19:15]", "h[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRAI)].type_lst[2] = operandType::operandTypeHex;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRAI)].msb_lst[2] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRAI)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRAI)].connect[2] = 0;
  // ["r[11:7]", "r[19:15]", "h[24:20]"]
  // InstId_t::INST_ID_ADD
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ADD)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ADD)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ADD)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ADD)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ADD)].connect[0] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ADD)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ADD)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ADD)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ADD)].connect[1] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ADD)].type_lst[2] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ADD)].msb_lst[2] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ADD)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ADD)].connect[2] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  // InstId_t::INST_ID_SUB
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SUB)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SUB)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SUB)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SUB)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SUB)].connect[0] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SUB)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SUB)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SUB)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SUB)].connect[1] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SUB)].type_lst[2] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SUB)].msb_lst[2] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SUB)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SUB)].connect[2] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  // InstId_t::INST_ID_SLL
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLL)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLL)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLL)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLL)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLL)].connect[0] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLL)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLL)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLL)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLL)].connect[1] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLL)].type_lst[2] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLL)].msb_lst[2] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLL)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLL)].connect[2] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  // InstId_t::INST_ID_SLT
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLT)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLT)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLT)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLT)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLT)].connect[0] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLT)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLT)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLT)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLT)].connect[1] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLT)].type_lst[2] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLT)].msb_lst[2] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLT)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLT)].connect[2] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  // InstId_t::INST_ID_SLTU
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLTU)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLTU)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLTU)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLTU)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLTU)].connect[0] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLTU)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLTU)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLTU)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLTU)].connect[1] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLTU)].type_lst[2] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLTU)].msb_lst[2] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLTU)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLTU)].connect[2] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  // InstId_t::INST_ID_XOR
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_XOR)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_XOR)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_XOR)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_XOR)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_XOR)].connect[0] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_XOR)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_XOR)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_XOR)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_XOR)].connect[1] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_XOR)].type_lst[2] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_XOR)].msb_lst[2] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_XOR)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_XOR)].connect[2] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  // InstId_t::INST_ID_SRL
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRL)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRL)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRL)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRL)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRL)].connect[0] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRL)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRL)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRL)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRL)].connect[1] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRL)].type_lst[2] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRL)].msb_lst[2] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRL)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRL)].connect[2] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  // InstId_t::INST_ID_SRA
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRA)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRA)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRA)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRA)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRA)].connect[0] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRA)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRA)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRA)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRA)].connect[1] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRA)].type_lst[2] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRA)].msb_lst[2] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRA)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRA)].connect[2] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  // InstId_t::INST_ID_OR
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_OR)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_OR)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_OR)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_OR)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_OR)].connect[0] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_OR)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_OR)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_OR)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_OR)].connect[1] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_OR)].type_lst[2] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_OR)].msb_lst[2] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_OR)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_OR)].connect[2] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  // InstId_t::INST_ID_AND
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AND)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AND)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AND)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AND)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AND)].connect[0] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AND)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AND)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AND)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AND)].connect[1] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AND)].type_lst[2] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AND)].msb_lst[2] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AND)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AND)].connect[2] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  // InstId_t::INST_ID_FENCE
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FENCE)].size = 0;
  // InstId_t::INST_ID_FENCE_I
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FENCE_I)].size = 0;
  // InstId_t::INST_ID_MUL
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_MUL)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_MUL)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_MUL)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_MUL)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_MUL)].connect[0] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_MUL)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_MUL)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_MUL)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_MUL)].connect[1] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_MUL)].type_lst[2] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_MUL)].msb_lst[2] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_MUL)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_MUL)].connect[2] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  // InstId_t::INST_ID_MULH
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_MULH)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_MULH)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_MULH)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_MULH)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_MULH)].connect[0] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_MULH)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_MULH)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_MULH)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_MULH)].connect[1] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_MULH)].type_lst[2] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_MULH)].msb_lst[2] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_MULH)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_MULH)].connect[2] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  // InstId_t::INST_ID_MULHSU
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_MULHSU)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_MULHSU)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_MULHSU)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_MULHSU)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_MULHSU)].connect[0] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_MULHSU)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_MULHSU)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_MULHSU)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_MULHSU)].connect[1] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_MULHSU)].type_lst[2] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_MULHSU)].msb_lst[2] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_MULHSU)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_MULHSU)].connect[2] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  // InstId_t::INST_ID_MULHU
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_MULHU)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_MULHU)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_MULHU)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_MULHU)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_MULHU)].connect[0] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_MULHU)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_MULHU)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_MULHU)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_MULHU)].connect[1] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_MULHU)].type_lst[2] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_MULHU)].msb_lst[2] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_MULHU)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_MULHU)].connect[2] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  // InstId_t::INST_ID_DIV
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_DIV)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_DIV)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_DIV)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_DIV)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_DIV)].connect[0] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_DIV)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_DIV)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_DIV)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_DIV)].connect[1] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_DIV)].type_lst[2] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_DIV)].msb_lst[2] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_DIV)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_DIV)].connect[2] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  // InstId_t::INST_ID_DIVU
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_DIVU)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_DIVU)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_DIVU)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_DIVU)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_DIVU)].connect[0] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_DIVU)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_DIVU)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_DIVU)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_DIVU)].connect[1] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_DIVU)].type_lst[2] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_DIVU)].msb_lst[2] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_DIVU)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_DIVU)].connect[2] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  // InstId_t::INST_ID_REM
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_REM)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_REM)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_REM)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_REM)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_REM)].connect[0] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_REM)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_REM)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_REM)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_REM)].connect[1] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_REM)].type_lst[2] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_REM)].msb_lst[2] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_REM)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_REM)].connect[2] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  // InstId_t::INST_ID_REMU
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_REMU)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_REMU)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_REMU)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_REMU)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_REMU)].connect[0] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_REMU)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_REMU)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_REMU)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_REMU)].connect[1] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_REMU)].type_lst[2] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_REMU)].msb_lst[2] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_REMU)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_REMU)].connect[2] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  // InstId_t::INST_ID_LR_W
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LR_W)].size = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LR_W)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LR_W)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LR_W)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LR_W)].connect[0] = 0;
  // ["r[11:7]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LR_W)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LR_W)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LR_W)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LR_W)].connect[1] = 0;
  // ["r[11:7]", "r[19:15]"]
  // InstId_t::INST_ID_SC_W
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SC_W)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SC_W)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SC_W)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SC_W)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SC_W)].connect[0] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SC_W)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SC_W)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SC_W)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SC_W)].connect[1] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SC_W)].type_lst[2] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SC_W)].msb_lst[2] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SC_W)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SC_W)].connect[2] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  // InstId_t::INST_ID_AMOSWAP_W
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOSWAP_W)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOSWAP_W)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOSWAP_W)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOSWAP_W)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOSWAP_W)].connect[0] = 0;
  // ["r[11:7]", "r[24:20]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOSWAP_W)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOSWAP_W)].msb_lst[1] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOSWAP_W)].lsb_lst[1] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOSWAP_W)].connect[1] = 0;
  // ["r[11:7]", "r[24:20]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOSWAP_W)].type_lst[2] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOSWAP_W)].msb_lst[2] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOSWAP_W)].lsb_lst[2] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOSWAP_W)].connect[2] = 0;
  // ["r[11:7]", "r[24:20]", "r[19:15]"]
  // InstId_t::INST_ID_AMOADD_W
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOADD_W)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOADD_W)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOADD_W)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOADD_W)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOADD_W)].connect[0] = 0;
  // ["r[11:7]", "r[24:20]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOADD_W)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOADD_W)].msb_lst[1] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOADD_W)].lsb_lst[1] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOADD_W)].connect[1] = 0;
  // ["r[11:7]", "r[24:20]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOADD_W)].type_lst[2] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOADD_W)].msb_lst[2] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOADD_W)].lsb_lst[2] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOADD_W)].connect[2] = 0;
  // ["r[11:7]", "r[24:20]", "r[19:15]"]
  // InstId_t::INST_ID_AMOXOR_W
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOXOR_W)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOXOR_W)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOXOR_W)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOXOR_W)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOXOR_W)].connect[0] = 0;
  // ["r[11:7]", "r[24:20]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOXOR_W)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOXOR_W)].msb_lst[1] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOXOR_W)].lsb_lst[1] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOXOR_W)].connect[1] = 0;
  // ["r[11:7]", "r[24:20]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOXOR_W)].type_lst[2] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOXOR_W)].msb_lst[2] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOXOR_W)].lsb_lst[2] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOXOR_W)].connect[2] = 0;
  // ["r[11:7]", "r[24:20]", "r[19:15]"]
  // InstId_t::INST_ID_AMOAND_W
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOAND_W)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOAND_W)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOAND_W)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOAND_W)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOAND_W)].connect[0] = 0;
  // ["r[11:7]", "r[24:20]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOAND_W)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOAND_W)].msb_lst[1] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOAND_W)].lsb_lst[1] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOAND_W)].connect[1] = 0;
  // ["r[11:7]", "r[24:20]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOAND_W)].type_lst[2] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOAND_W)].msb_lst[2] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOAND_W)].lsb_lst[2] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOAND_W)].connect[2] = 0;
  // ["r[11:7]", "r[24:20]", "r[19:15]"]
  // InstId_t::INST_ID_AMOOR_W
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOOR_W)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOOR_W)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOOR_W)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOOR_W)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOOR_W)].connect[0] = 0;
  // ["r[11:7]", "r[24:20]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOOR_W)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOOR_W)].msb_lst[1] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOOR_W)].lsb_lst[1] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOOR_W)].connect[1] = 0;
  // ["r[11:7]", "r[24:20]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOOR_W)].type_lst[2] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOOR_W)].msb_lst[2] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOOR_W)].lsb_lst[2] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOOR_W)].connect[2] = 0;
  // ["r[11:7]", "r[24:20]", "r[19:15]"]
  // InstId_t::INST_ID_AMOMIN_W
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMIN_W)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMIN_W)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMIN_W)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMIN_W)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMIN_W)].connect[0] = 0;
  // ["r[11:7]", "r[24:20]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMIN_W)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMIN_W)].msb_lst[1] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMIN_W)].lsb_lst[1] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMIN_W)].connect[1] = 0;
  // ["r[11:7]", "r[24:20]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMIN_W)].type_lst[2] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMIN_W)].msb_lst[2] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMIN_W)].lsb_lst[2] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMIN_W)].connect[2] = 0;
  // ["r[11:7]", "r[24:20]", "r[19:15]"]
  // InstId_t::INST_ID_AMOMAX_W
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMAX_W)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMAX_W)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMAX_W)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMAX_W)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMAX_W)].connect[0] = 0;
  // ["r[11:7]", "r[24:20]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMAX_W)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMAX_W)].msb_lst[1] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMAX_W)].lsb_lst[1] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMAX_W)].connect[1] = 0;
  // ["r[11:7]", "r[24:20]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMAX_W)].type_lst[2] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMAX_W)].msb_lst[2] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMAX_W)].lsb_lst[2] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMAX_W)].connect[2] = 0;
  // ["r[11:7]", "r[24:20]", "r[19:15]"]
  // InstId_t::INST_ID_AMOMINU_W
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMINU_W)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMINU_W)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMINU_W)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMINU_W)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMINU_W)].connect[0] = 0;
  // ["r[11:7]", "r[24:20]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMINU_W)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMINU_W)].msb_lst[1] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMINU_W)].lsb_lst[1] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMINU_W)].connect[1] = 0;
  // ["r[11:7]", "r[24:20]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMINU_W)].type_lst[2] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMINU_W)].msb_lst[2] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMINU_W)].lsb_lst[2] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMINU_W)].connect[2] = 0;
  // ["r[11:7]", "r[24:20]", "r[19:15]"]
  // InstId_t::INST_ID_AMOMAXU_W
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMAXU_W)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMAXU_W)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMAXU_W)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMAXU_W)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMAXU_W)].connect[0] = 0;
  // ["r[11:7]", "r[24:20]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMAXU_W)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMAXU_W)].msb_lst[1] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMAXU_W)].lsb_lst[1] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMAXU_W)].connect[1] = 0;
  // ["r[11:7]", "r[24:20]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMAXU_W)].type_lst[2] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMAXU_W)].msb_lst[2] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMAXU_W)].lsb_lst[2] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMAXU_W)].connect[2] = 0;
  // ["r[11:7]", "r[24:20]", "r[19:15]"]
  // InstId_t::INST_ID_FLW
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLW)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLW)].type_lst[0] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLW)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLW)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLW)].connect[0] = 0;
  // ["f[11:7]", "h[31:20]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLW)].type_lst[1] = operandType::operandTypeHex;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLW)].msb_lst[1] = 31;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLW)].lsb_lst[1] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLW)].connect[1] = 0;
  // ["f[11:7]", "h[31:20]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLW)].type_lst[2] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLW)].msb_lst[2] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLW)].lsb_lst[2] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLW)].connect[2] = 0;
  // ["f[11:7]", "h[31:20]", "r[19:15]"]
  // InstId_t::INST_ID_FSW
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSW)].size = 4;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSW)].type_lst[0] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSW)].msb_lst[0] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSW)].lsb_lst[0] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSW)].connect[0] = 0;
  // ["f[24:20]", "h[31:25]|", "h[11:7]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSW)].type_lst[1] = operandType::operandTypeHex;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSW)].msb_lst[1] = 31;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSW)].lsb_lst[1] = 25;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSW)].connect[1] = 1;
  // ["f[24:20]", "h[31:25]|", "h[11:7]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSW)].type_lst[2] = operandType::operandTypeHex;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSW)].msb_lst[2] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSW)].lsb_lst[2] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSW)].connect[2] = 0;
  // ["f[24:20]", "h[31:25]|", "h[11:7]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSW)].type_lst[3] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSW)].msb_lst[3] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSW)].lsb_lst[3] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSW)].connect[3] = 0;
  // ["f[24:20]", "h[31:25]|", "h[11:7]", "r[19:15]"]
  // InstId_t::INST_ID_FMADD_S
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMADD_S)].size = 4;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMADD_S)].type_lst[0] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMADD_S)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMADD_S)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMADD_S)].connect[0] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]", "f[31:27]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMADD_S)].type_lst[1] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMADD_S)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMADD_S)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMADD_S)].connect[1] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]", "f[31:27]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMADD_S)].type_lst[2] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMADD_S)].msb_lst[2] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMADD_S)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMADD_S)].connect[2] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]", "f[31:27]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMADD_S)].type_lst[3] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMADD_S)].msb_lst[3] = 31;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMADD_S)].lsb_lst[3] = 27;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMADD_S)].connect[3] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]", "f[31:27]"]
  // InstId_t::INST_ID_FMSUB_S
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMSUB_S)].size = 4;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMSUB_S)].type_lst[0] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMSUB_S)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMSUB_S)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMSUB_S)].connect[0] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]", "f[31:27]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMSUB_S)].type_lst[1] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMSUB_S)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMSUB_S)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMSUB_S)].connect[1] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]", "f[31:27]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMSUB_S)].type_lst[2] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMSUB_S)].msb_lst[2] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMSUB_S)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMSUB_S)].connect[2] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]", "f[31:27]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMSUB_S)].type_lst[3] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMSUB_S)].msb_lst[3] = 31;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMSUB_S)].lsb_lst[3] = 27;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMSUB_S)].connect[3] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]", "f[31:27]"]
  // InstId_t::INST_ID_FNMSUB_S
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FNMSUB_S)].size = 4;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FNMSUB_S)].type_lst[0] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FNMSUB_S)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FNMSUB_S)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FNMSUB_S)].connect[0] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]", "f[31:27]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FNMSUB_S)].type_lst[1] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FNMSUB_S)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FNMSUB_S)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FNMSUB_S)].connect[1] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]", "f[31:27]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FNMSUB_S)].type_lst[2] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FNMSUB_S)].msb_lst[2] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FNMSUB_S)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FNMSUB_S)].connect[2] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]", "f[31:27]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FNMSUB_S)].type_lst[3] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FNMSUB_S)].msb_lst[3] = 31;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FNMSUB_S)].lsb_lst[3] = 27;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FNMSUB_S)].connect[3] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]", "f[31:27]"]
  // InstId_t::INST_ID_FNMADD_S
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FNMADD_S)].size = 4;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FNMADD_S)].type_lst[0] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FNMADD_S)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FNMADD_S)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FNMADD_S)].connect[0] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]", "f[31:27]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FNMADD_S)].type_lst[1] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FNMADD_S)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FNMADD_S)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FNMADD_S)].connect[1] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]", "f[31:27]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FNMADD_S)].type_lst[2] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FNMADD_S)].msb_lst[2] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FNMADD_S)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FNMADD_S)].connect[2] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]", "f[31:27]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FNMADD_S)].type_lst[3] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FNMADD_S)].msb_lst[3] = 31;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FNMADD_S)].lsb_lst[3] = 27;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FNMADD_S)].connect[3] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]", "f[31:27]"]
  // InstId_t::INST_ID_FADD_S
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FADD_S)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FADD_S)].type_lst[0] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FADD_S)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FADD_S)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FADD_S)].connect[0] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FADD_S)].type_lst[1] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FADD_S)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FADD_S)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FADD_S)].connect[1] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FADD_S)].type_lst[2] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FADD_S)].msb_lst[2] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FADD_S)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FADD_S)].connect[2] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]"]
  // InstId_t::INST_ID_FSUB_S
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSUB_S)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSUB_S)].type_lst[0] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSUB_S)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSUB_S)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSUB_S)].connect[0] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSUB_S)].type_lst[1] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSUB_S)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSUB_S)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSUB_S)].connect[1] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSUB_S)].type_lst[2] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSUB_S)].msb_lst[2] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSUB_S)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSUB_S)].connect[2] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]"]
  // InstId_t::INST_ID_FMUL_S
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMUL_S)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMUL_S)].type_lst[0] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMUL_S)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMUL_S)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMUL_S)].connect[0] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMUL_S)].type_lst[1] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMUL_S)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMUL_S)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMUL_S)].connect[1] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMUL_S)].type_lst[2] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMUL_S)].msb_lst[2] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMUL_S)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMUL_S)].connect[2] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]"]
  // InstId_t::INST_ID_FDIV_S
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FDIV_S)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FDIV_S)].type_lst[0] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FDIV_S)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FDIV_S)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FDIV_S)].connect[0] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FDIV_S)].type_lst[1] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FDIV_S)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FDIV_S)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FDIV_S)].connect[1] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FDIV_S)].type_lst[2] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FDIV_S)].msb_lst[2] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FDIV_S)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FDIV_S)].connect[2] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]"]
  // InstId_t::INST_ID_FSQRT_S
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSQRT_S)].size = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSQRT_S)].type_lst[0] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSQRT_S)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSQRT_S)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSQRT_S)].connect[0] = 0;
  // ["f[11:7]", "f[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSQRT_S)].type_lst[1] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSQRT_S)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSQRT_S)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSQRT_S)].connect[1] = 0;
  // ["f[11:7]", "f[19:15]"]
  // InstId_t::INST_ID_FSGNJ_S
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJ_S)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJ_S)].type_lst[0] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJ_S)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJ_S)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJ_S)].connect[0] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJ_S)].type_lst[1] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJ_S)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJ_S)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJ_S)].connect[1] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJ_S)].type_lst[2] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJ_S)].msb_lst[2] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJ_S)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJ_S)].connect[2] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]"]
  // InstId_t::INST_ID_FSGNJN_S
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJN_S)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJN_S)].type_lst[0] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJN_S)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJN_S)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJN_S)].connect[0] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJN_S)].type_lst[1] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJN_S)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJN_S)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJN_S)].connect[1] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJN_S)].type_lst[2] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJN_S)].msb_lst[2] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJN_S)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJN_S)].connect[2] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]"]
  // InstId_t::INST_ID_FSGNJX_S
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJX_S)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJX_S)].type_lst[0] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJX_S)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJX_S)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJX_S)].connect[0] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJX_S)].type_lst[1] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJX_S)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJX_S)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJX_S)].connect[1] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJX_S)].type_lst[2] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJX_S)].msb_lst[2] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJX_S)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJX_S)].connect[2] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]"]
  // InstId_t::INST_ID_FMIN_S
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMIN_S)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMIN_S)].type_lst[0] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMIN_S)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMIN_S)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMIN_S)].connect[0] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMIN_S)].type_lst[1] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMIN_S)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMIN_S)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMIN_S)].connect[1] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMIN_S)].type_lst[2] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMIN_S)].msb_lst[2] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMIN_S)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMIN_S)].connect[2] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]"]
  // InstId_t::INST_ID_FMAX_S
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMAX_S)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMAX_S)].type_lst[0] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMAX_S)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMAX_S)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMAX_S)].connect[0] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMAX_S)].type_lst[1] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMAX_S)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMAX_S)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMAX_S)].connect[1] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMAX_S)].type_lst[2] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMAX_S)].msb_lst[2] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMAX_S)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMAX_S)].connect[2] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]"]
  // InstId_t::INST_ID_FCVT_W_S
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_W_S)].size = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_W_S)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_W_S)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_W_S)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_W_S)].connect[0] = 0;
  // ["r[11:7]", "f[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_W_S)].type_lst[1] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_W_S)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_W_S)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_W_S)].connect[1] = 0;
  // ["r[11:7]", "f[19:15]"]
  // InstId_t::INST_ID_FCVT_WU_S
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_WU_S)].size = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_WU_S)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_WU_S)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_WU_S)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_WU_S)].connect[0] = 0;
  // ["r[11:7]", "f[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_WU_S)].type_lst[1] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_WU_S)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_WU_S)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_WU_S)].connect[1] = 0;
  // ["r[11:7]", "f[19:15]"]
  // InstId_t::INST_ID_FMV_X_W
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMV_X_W)].size = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMV_X_W)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMV_X_W)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMV_X_W)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMV_X_W)].connect[0] = 0;
  // ["r[11:7]", "f[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMV_X_W)].type_lst[1] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMV_X_W)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMV_X_W)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMV_X_W)].connect[1] = 0;
  // ["r[11:7]", "f[19:15]"]
  // InstId_t::INST_ID_FEQ_S
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FEQ_S)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FEQ_S)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FEQ_S)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FEQ_S)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FEQ_S)].connect[0] = 0;
  // ["r[11:7]", "f[19:15]", "f[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FEQ_S)].type_lst[1] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FEQ_S)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FEQ_S)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FEQ_S)].connect[1] = 0;
  // ["r[11:7]", "f[19:15]", "f[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FEQ_S)].type_lst[2] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FEQ_S)].msb_lst[2] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FEQ_S)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FEQ_S)].connect[2] = 0;
  // ["r[11:7]", "f[19:15]", "f[24:20]"]
  // InstId_t::INST_ID_FLT_S
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLT_S)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLT_S)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLT_S)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLT_S)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLT_S)].connect[0] = 0;
  // ["r[11:7]", "f[19:15]", "f[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLT_S)].type_lst[1] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLT_S)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLT_S)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLT_S)].connect[1] = 0;
  // ["r[11:7]", "f[19:15]", "f[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLT_S)].type_lst[2] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLT_S)].msb_lst[2] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLT_S)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLT_S)].connect[2] = 0;
  // ["r[11:7]", "f[19:15]", "f[24:20]"]
  // InstId_t::INST_ID_FLE_S
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLE_S)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLE_S)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLE_S)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLE_S)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLE_S)].connect[0] = 0;
  // ["r[11:7]", "f[19:15]", "f[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLE_S)].type_lst[1] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLE_S)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLE_S)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLE_S)].connect[1] = 0;
  // ["r[11:7]", "f[19:15]", "f[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLE_S)].type_lst[2] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLE_S)].msb_lst[2] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLE_S)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLE_S)].connect[2] = 0;
  // ["r[11:7]", "f[19:15]", "f[24:20]"]
  // InstId_t::INST_ID_FCLASS_S
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCLASS_S)].size = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCLASS_S)].type_lst[0] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCLASS_S)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCLASS_S)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCLASS_S)].connect[0] = 0;
  // ["f[11:7]", "f[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCLASS_S)].type_lst[1] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCLASS_S)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCLASS_S)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCLASS_S)].connect[1] = 0;
  // ["f[11:7]", "f[19:15]"]
  // InstId_t::INST_ID_FCVT_S_W
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_S_W)].size = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_S_W)].type_lst[0] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_S_W)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_S_W)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_S_W)].connect[0] = 0;
  // ["f[11:7]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_S_W)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_S_W)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_S_W)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_S_W)].connect[1] = 0;
  // ["f[11:7]", "r[19:15]"]
  // InstId_t::INST_ID_FCVT_S_WU
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_S_WU)].size = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_S_WU)].type_lst[0] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_S_WU)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_S_WU)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_S_WU)].connect[0] = 0;
  // ["f[11:7]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_S_WU)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_S_WU)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_S_WU)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_S_WU)].connect[1] = 0;
  // ["f[11:7]", "r[19:15]"]
  // InstId_t::INST_ID_FMV_W_X
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMV_W_X)].size = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMV_W_X)].type_lst[0] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMV_W_X)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMV_W_X)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMV_W_X)].connect[0] = 0;
  // ["f[11:7]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMV_W_X)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMV_W_X)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMV_W_X)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMV_W_X)].connect[1] = 0;
  // ["f[11:7]", "r[19:15]"]
  // InstId_t::INST_ID_FLD
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLD)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLD)].type_lst[0] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLD)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLD)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLD)].connect[0] = 0;
  // ["f[11:7]", "r[19:15]", "h[31:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLD)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLD)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLD)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLD)].connect[1] = 0;
  // ["f[11:7]", "r[19:15]", "h[31:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLD)].type_lst[2] = operandType::operandTypeHex;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLD)].msb_lst[2] = 31;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLD)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLD)].connect[2] = 0;
  // ["f[11:7]", "r[19:15]", "h[31:20]"]
  // InstId_t::INST_ID_FSD
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSD)].size = 4;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSD)].type_lst[0] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSD)].msb_lst[0] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSD)].lsb_lst[0] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSD)].connect[0] = 0;
  // ["f[24:20]", "h[31:25]|", "h[11:7]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSD)].type_lst[1] = operandType::operandTypeHex;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSD)].msb_lst[1] = 31;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSD)].lsb_lst[1] = 25;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSD)].connect[1] = 1;
  // ["f[24:20]", "h[31:25]|", "h[11:7]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSD)].type_lst[2] = operandType::operandTypeHex;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSD)].msb_lst[2] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSD)].lsb_lst[2] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSD)].connect[2] = 0;
  // ["f[24:20]", "h[31:25]|", "h[11:7]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSD)].type_lst[3] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSD)].msb_lst[3] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSD)].lsb_lst[3] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSD)].connect[3] = 0;
  // ["f[24:20]", "h[31:25]|", "h[11:7]", "r[19:15]"]
  // InstId_t::INST_ID_FMADD_D
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMADD_D)].size = 4;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMADD_D)].type_lst[0] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMADD_D)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMADD_D)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMADD_D)].connect[0] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]", "f[31:27]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMADD_D)].type_lst[1] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMADD_D)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMADD_D)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMADD_D)].connect[1] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]", "f[31:27]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMADD_D)].type_lst[2] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMADD_D)].msb_lst[2] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMADD_D)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMADD_D)].connect[2] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]", "f[31:27]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMADD_D)].type_lst[3] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMADD_D)].msb_lst[3] = 31;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMADD_D)].lsb_lst[3] = 27;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMADD_D)].connect[3] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]", "f[31:27]"]
  // InstId_t::INST_ID_FMSUB_D
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMSUB_D)].size = 4;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMSUB_D)].type_lst[0] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMSUB_D)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMSUB_D)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMSUB_D)].connect[0] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]", "f[31:27]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMSUB_D)].type_lst[1] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMSUB_D)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMSUB_D)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMSUB_D)].connect[1] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]", "f[31:27]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMSUB_D)].type_lst[2] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMSUB_D)].msb_lst[2] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMSUB_D)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMSUB_D)].connect[2] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]", "f[31:27]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMSUB_D)].type_lst[3] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMSUB_D)].msb_lst[3] = 31;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMSUB_D)].lsb_lst[3] = 27;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMSUB_D)].connect[3] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]", "f[31:27]"]
  // InstId_t::INST_ID_FNMSUB_D
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FNMSUB_D)].size = 4;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FNMSUB_D)].type_lst[0] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FNMSUB_D)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FNMSUB_D)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FNMSUB_D)].connect[0] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]", "f[31:27]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FNMSUB_D)].type_lst[1] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FNMSUB_D)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FNMSUB_D)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FNMSUB_D)].connect[1] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]", "f[31:27]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FNMSUB_D)].type_lst[2] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FNMSUB_D)].msb_lst[2] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FNMSUB_D)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FNMSUB_D)].connect[2] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]", "f[31:27]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FNMSUB_D)].type_lst[3] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FNMSUB_D)].msb_lst[3] = 31;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FNMSUB_D)].lsb_lst[3] = 27;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FNMSUB_D)].connect[3] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]", "f[31:27]"]
  // InstId_t::INST_ID_FNMADD_D
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FNMADD_D)].size = 4;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FNMADD_D)].type_lst[0] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FNMADD_D)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FNMADD_D)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FNMADD_D)].connect[0] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]", "f[31:27]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FNMADD_D)].type_lst[1] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FNMADD_D)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FNMADD_D)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FNMADD_D)].connect[1] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]", "f[31:27]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FNMADD_D)].type_lst[2] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FNMADD_D)].msb_lst[2] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FNMADD_D)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FNMADD_D)].connect[2] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]", "f[31:27]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FNMADD_D)].type_lst[3] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FNMADD_D)].msb_lst[3] = 31;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FNMADD_D)].lsb_lst[3] = 27;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FNMADD_D)].connect[3] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]", "f[31:27]"]
  // InstId_t::INST_ID_FADD_D
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FADD_D)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FADD_D)].type_lst[0] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FADD_D)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FADD_D)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FADD_D)].connect[0] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FADD_D)].type_lst[1] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FADD_D)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FADD_D)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FADD_D)].connect[1] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FADD_D)].type_lst[2] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FADD_D)].msb_lst[2] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FADD_D)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FADD_D)].connect[2] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]"]
  // InstId_t::INST_ID_FSUB_D
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSUB_D)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSUB_D)].type_lst[0] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSUB_D)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSUB_D)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSUB_D)].connect[0] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSUB_D)].type_lst[1] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSUB_D)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSUB_D)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSUB_D)].connect[1] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSUB_D)].type_lst[2] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSUB_D)].msb_lst[2] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSUB_D)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSUB_D)].connect[2] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]"]
  // InstId_t::INST_ID_FMUL_D
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMUL_D)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMUL_D)].type_lst[0] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMUL_D)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMUL_D)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMUL_D)].connect[0] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMUL_D)].type_lst[1] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMUL_D)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMUL_D)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMUL_D)].connect[1] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMUL_D)].type_lst[2] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMUL_D)].msb_lst[2] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMUL_D)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMUL_D)].connect[2] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]"]
  // InstId_t::INST_ID_FDIV_D
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FDIV_D)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FDIV_D)].type_lst[0] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FDIV_D)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FDIV_D)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FDIV_D)].connect[0] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FDIV_D)].type_lst[1] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FDIV_D)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FDIV_D)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FDIV_D)].connect[1] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FDIV_D)].type_lst[2] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FDIV_D)].msb_lst[2] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FDIV_D)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FDIV_D)].connect[2] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]"]
  // InstId_t::INST_ID_FSQRT_D
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSQRT_D)].size = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSQRT_D)].type_lst[0] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSQRT_D)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSQRT_D)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSQRT_D)].connect[0] = 0;
  // ["f[11:7]", "f[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSQRT_D)].type_lst[1] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSQRT_D)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSQRT_D)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSQRT_D)].connect[1] = 0;
  // ["f[11:7]", "f[19:15]"]
  // InstId_t::INST_ID_FSGNJ_D
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJ_D)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJ_D)].type_lst[0] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJ_D)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJ_D)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJ_D)].connect[0] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJ_D)].type_lst[1] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJ_D)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJ_D)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJ_D)].connect[1] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJ_D)].type_lst[2] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJ_D)].msb_lst[2] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJ_D)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJ_D)].connect[2] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]"]
  // InstId_t::INST_ID_FSGNJN_D
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJN_D)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJN_D)].type_lst[0] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJN_D)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJN_D)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJN_D)].connect[0] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJN_D)].type_lst[1] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJN_D)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJN_D)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJN_D)].connect[1] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJN_D)].type_lst[2] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJN_D)].msb_lst[2] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJN_D)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJN_D)].connect[2] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]"]
  // InstId_t::INST_ID_FSGNJX_D
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJX_D)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJX_D)].type_lst[0] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJX_D)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJX_D)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJX_D)].connect[0] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJX_D)].type_lst[1] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJX_D)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJX_D)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJX_D)].connect[1] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJX_D)].type_lst[2] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJX_D)].msb_lst[2] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJX_D)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FSGNJX_D)].connect[2] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]"]
  // InstId_t::INST_ID_FMIN_D
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMIN_D)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMIN_D)].type_lst[0] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMIN_D)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMIN_D)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMIN_D)].connect[0] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMIN_D)].type_lst[1] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMIN_D)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMIN_D)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMIN_D)].connect[1] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMIN_D)].type_lst[2] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMIN_D)].msb_lst[2] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMIN_D)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMIN_D)].connect[2] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]"]
  // InstId_t::INST_ID_FMAX_D
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMAX_D)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMAX_D)].type_lst[0] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMAX_D)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMAX_D)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMAX_D)].connect[0] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMAX_D)].type_lst[1] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMAX_D)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMAX_D)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMAX_D)].connect[1] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMAX_D)].type_lst[2] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMAX_D)].msb_lst[2] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMAX_D)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMAX_D)].connect[2] = 0;
  // ["f[11:7]", "f[19:15]", "f[24:20]"]
  // InstId_t::INST_ID_FCVT_S_D
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_S_D)].size = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_S_D)].type_lst[0] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_S_D)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_S_D)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_S_D)].connect[0] = 0;
  // ["f[11:7]", "f[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_S_D)].type_lst[1] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_S_D)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_S_D)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_S_D)].connect[1] = 0;
  // ["f[11:7]", "f[19:15]"]
  // InstId_t::INST_ID_FCVT_D_S
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_D_S)].size = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_D_S)].type_lst[0] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_D_S)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_D_S)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_D_S)].connect[0] = 0;
  // ["f[11:7]", "f[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_D_S)].type_lst[1] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_D_S)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_D_S)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_D_S)].connect[1] = 0;
  // ["f[11:7]", "f[19:15]"]
  // InstId_t::INST_ID_FEQ_D
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FEQ_D)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FEQ_D)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FEQ_D)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FEQ_D)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FEQ_D)].connect[0] = 0;
  // ["r[11:7]", "f[19:15]", "f[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FEQ_D)].type_lst[1] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FEQ_D)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FEQ_D)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FEQ_D)].connect[1] = 0;
  // ["r[11:7]", "f[19:15]", "f[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FEQ_D)].type_lst[2] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FEQ_D)].msb_lst[2] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FEQ_D)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FEQ_D)].connect[2] = 0;
  // ["r[11:7]", "f[19:15]", "f[24:20]"]
  // InstId_t::INST_ID_FLT_D
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLT_D)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLT_D)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLT_D)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLT_D)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLT_D)].connect[0] = 0;
  // ["r[11:7]", "f[19:15]", "f[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLT_D)].type_lst[1] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLT_D)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLT_D)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLT_D)].connect[1] = 0;
  // ["r[11:7]", "f[19:15]", "f[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLT_D)].type_lst[2] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLT_D)].msb_lst[2] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLT_D)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLT_D)].connect[2] = 0;
  // ["r[11:7]", "f[19:15]", "f[24:20]"]
  // InstId_t::INST_ID_FLE_D
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLE_D)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLE_D)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLE_D)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLE_D)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLE_D)].connect[0] = 0;
  // ["r[11:7]", "f[19:15]", "f[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLE_D)].type_lst[1] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLE_D)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLE_D)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLE_D)].connect[1] = 0;
  // ["r[11:7]", "f[19:15]", "f[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLE_D)].type_lst[2] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLE_D)].msb_lst[2] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLE_D)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FLE_D)].connect[2] = 0;
  // ["r[11:7]", "f[19:15]", "f[24:20]"]
  // InstId_t::INST_ID_FCLASS_D
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCLASS_D)].size = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCLASS_D)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCLASS_D)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCLASS_D)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCLASS_D)].connect[0] = 0;
  // ["r[11:7]", "f[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCLASS_D)].type_lst[1] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCLASS_D)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCLASS_D)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCLASS_D)].connect[1] = 0;
  // ["r[11:7]", "f[19:15]"]
  // InstId_t::INST_ID_FCVT_W_D
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_W_D)].size = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_W_D)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_W_D)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_W_D)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_W_D)].connect[0] = 0;
  // ["r[11:7]", "f[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_W_D)].type_lst[1] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_W_D)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_W_D)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_W_D)].connect[1] = 0;
  // ["r[11:7]", "f[19:15]"]
  // InstId_t::INST_ID_FCVT_WU_D
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_WU_D)].size = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_WU_D)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_WU_D)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_WU_D)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_WU_D)].connect[0] = 0;
  // ["r[11:7]", "f[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_WU_D)].type_lst[1] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_WU_D)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_WU_D)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_WU_D)].connect[1] = 0;
  // ["r[11:7]", "f[19:15]"]
  // InstId_t::INST_ID_FCVT_D_W
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_D_W)].size = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_D_W)].type_lst[0] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_D_W)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_D_W)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_D_W)].connect[0] = 0;
  // ["f[11:7]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_D_W)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_D_W)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_D_W)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_D_W)].connect[1] = 0;
  // ["f[11:7]", "r[19:15]"]
  // InstId_t::INST_ID_FCVT_D_WU
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_D_WU)].size = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_D_WU)].type_lst[0] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_D_WU)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_D_WU)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_D_WU)].connect[0] = 0;
  // ["f[11:7]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_D_WU)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_D_WU)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_D_WU)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_D_WU)].connect[1] = 0;
  // ["f[11:7]", "r[19:15]"]
  // InstId_t::INST_ID_CSRRW
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRW)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRW)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRW)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRW)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRW)].connect[0] = 0;
  // ["r[11:7]", "h[31:20]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRW)].type_lst[1] = operandType::operandTypeHex;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRW)].msb_lst[1] = 31;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRW)].lsb_lst[1] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRW)].connect[1] = 0;
  // ["r[11:7]", "h[31:20]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRW)].type_lst[2] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRW)].msb_lst[2] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRW)].lsb_lst[2] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRW)].connect[2] = 0;
  // ["r[11:7]", "h[31:20]", "r[19:15]"]
  // InstId_t::INST_ID_CSRRS
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRS)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRS)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRS)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRS)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRS)].connect[0] = 0;
  // ["r[11:7]", "h[31:20]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRS)].type_lst[1] = operandType::operandTypeHex;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRS)].msb_lst[1] = 31;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRS)].lsb_lst[1] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRS)].connect[1] = 0;
  // ["r[11:7]", "h[31:20]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRS)].type_lst[2] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRS)].msb_lst[2] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRS)].lsb_lst[2] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRS)].connect[2] = 0;
  // ["r[11:7]", "h[31:20]", "r[19:15]"]
  // InstId_t::INST_ID_CSRRC
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRC)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRC)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRC)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRC)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRC)].connect[0] = 0;
  // ["r[11:7]", "h[31:20]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRC)].type_lst[1] = operandType::operandTypeHex;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRC)].msb_lst[1] = 31;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRC)].lsb_lst[1] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRC)].connect[1] = 0;
  // ["r[11:7]", "h[31:20]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRC)].type_lst[2] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRC)].msb_lst[2] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRC)].lsb_lst[2] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRC)].connect[2] = 0;
  // ["r[11:7]", "h[31:20]", "r[19:15]"]
  // InstId_t::INST_ID_CSRRWI
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRWI)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRWI)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRWI)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRWI)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRWI)].connect[0] = 0;
  // ["r[11:7]", "h[31:20]", "h[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRWI)].type_lst[1] = operandType::operandTypeHex;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRWI)].msb_lst[1] = 31;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRWI)].lsb_lst[1] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRWI)].connect[1] = 0;
  // ["r[11:7]", "h[31:20]", "h[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRWI)].type_lst[2] = operandType::operandTypeHex;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRWI)].msb_lst[2] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRWI)].lsb_lst[2] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRWI)].connect[2] = 0;
  // ["r[11:7]", "h[31:20]", "h[19:15]"]
  // InstId_t::INST_ID_CSRRSI
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRSI)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRSI)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRSI)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRSI)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRSI)].connect[0] = 0;
  // ["r[11:7]", "h[31:20]", "h[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRSI)].type_lst[1] = operandType::operandTypeHex;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRSI)].msb_lst[1] = 31;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRSI)].lsb_lst[1] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRSI)].connect[1] = 0;
  // ["r[11:7]", "h[31:20]", "h[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRSI)].type_lst[2] = operandType::operandTypeHex;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRSI)].msb_lst[2] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRSI)].lsb_lst[2] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRSI)].connect[2] = 0;
  // ["r[11:7]", "h[31:20]", "h[19:15]"]
  // InstId_t::INST_ID_CSRRCI
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRCI)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRCI)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRCI)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRCI)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRCI)].connect[0] = 0;
  // ["r[11:7]", "h[31:20]", "h[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRCI)].type_lst[1] = operandType::operandTypeHex;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRCI)].msb_lst[1] = 31;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRCI)].lsb_lst[1] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRCI)].connect[1] = 0;
  // ["r[11:7]", "h[31:20]", "h[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRCI)].type_lst[2] = operandType::operandTypeHex;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRCI)].msb_lst[2] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRCI)].lsb_lst[2] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_CSRRCI)].connect[2] = 0;
  // ["r[11:7]", "h[31:20]", "h[19:15]"]
  // InstId_t::INST_ID_ECALL
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ECALL)].size = 0;
  // InstId_t::INST_ID_EBREAK
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_EBREAK)].size = 0;
  // InstId_t::INST_ID_URET
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_URET)].size = 0;
  // InstId_t::INST_ID_SRET
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRET)].size = 0;
  // InstId_t::INST_ID_HRET
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_HRET)].size = 0;
  // InstId_t::INST_ID_MRET
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_MRET)].size = 0;
  // InstId_t::INST_ID_MRTS
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_MRTS)].size = 0;
  // InstId_t::INST_ID_MRTH
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_MRTH)].size = 0;
  // InstId_t::INST_ID_WFI
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_WFI)].size = 0;
  // InstId_t::INST_ID_SFENCE_VMA
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SFENCE_VMA)].size = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SFENCE_VMA)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SFENCE_VMA)].msb_lst[0] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SFENCE_VMA)].lsb_lst[0] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SFENCE_VMA)].connect[0] = 0;
  // ["r[19:15]", "r[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SFENCE_VMA)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SFENCE_VMA)].msb_lst[1] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SFENCE_VMA)].lsb_lst[1] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SFENCE_VMA)].connect[1] = 0;
  // ["r[19:15]", "r[24:20]"]
  // InstId_t::INST_ID_LWU
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LWU)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LWU)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LWU)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LWU)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LWU)].connect[0] = 0;
  // ["r[11:7]", "h[31:20]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LWU)].type_lst[1] = operandType::operandTypeHex;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LWU)].msb_lst[1] = 31;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LWU)].lsb_lst[1] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LWU)].connect[1] = 0;
  // ["r[11:7]", "h[31:20]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LWU)].type_lst[2] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LWU)].msb_lst[2] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LWU)].lsb_lst[2] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LWU)].connect[2] = 0;
  // ["r[11:7]", "h[31:20]", "r[19:15]"]
  // InstId_t::INST_ID_LD
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LD)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LD)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LD)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LD)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LD)].connect[0] = 0;
  // ["r[11:7]", "h[31:20]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LD)].type_lst[1] = operandType::operandTypeHex;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LD)].msb_lst[1] = 31;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LD)].lsb_lst[1] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LD)].connect[1] = 0;
  // ["r[11:7]", "h[31:20]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LD)].type_lst[2] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LD)].msb_lst[2] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LD)].lsb_lst[2] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LD)].connect[2] = 0;
  // ["r[11:7]", "h[31:20]", "r[19:15]"]
  // InstId_t::INST_ID_SD
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SD)].size = 4;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SD)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SD)].msb_lst[0] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SD)].lsb_lst[0] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SD)].connect[0] = 0;
  // ["r[24:20]", "h[31:25]|", "h[11:7]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SD)].type_lst[1] = operandType::operandTypeHex;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SD)].msb_lst[1] = 31;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SD)].lsb_lst[1] = 25;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SD)].connect[1] = 1;
  // ["r[24:20]", "h[31:25]|", "h[11:7]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SD)].type_lst[2] = operandType::operandTypeHex;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SD)].msb_lst[2] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SD)].lsb_lst[2] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SD)].connect[2] = 0;
  // ["r[24:20]", "h[31:25]|", "h[11:7]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SD)].type_lst[3] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SD)].msb_lst[3] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SD)].lsb_lst[3] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SD)].connect[3] = 0;
  // ["r[24:20]", "h[31:25]|", "h[11:7]", "r[19:15]"]
  // InstId_t::INST_ID_ADDIW
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ADDIW)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ADDIW)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ADDIW)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ADDIW)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ADDIW)].connect[0] = 0;
  // ["r[11:7]", "r[19:15]", "h[31:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ADDIW)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ADDIW)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ADDIW)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ADDIW)].connect[1] = 0;
  // ["r[11:7]", "r[19:15]", "h[31:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ADDIW)].type_lst[2] = operandType::operandTypeHex;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ADDIW)].msb_lst[2] = 31;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ADDIW)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ADDIW)].connect[2] = 0;
  // ["r[11:7]", "r[19:15]", "h[31:20]"]
  // InstId_t::INST_ID_SLLIW
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLLIW)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLLIW)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLLIW)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLLIW)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLLIW)].connect[0] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLLIW)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLLIW)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLLIW)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLLIW)].connect[1] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLLIW)].type_lst[2] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLLIW)].msb_lst[2] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLLIW)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLLIW)].connect[2] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  // InstId_t::INST_ID_SRLIW
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRLIW)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRLIW)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRLIW)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRLIW)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRLIW)].connect[0] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRLIW)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRLIW)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRLIW)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRLIW)].connect[1] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRLIW)].type_lst[2] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRLIW)].msb_lst[2] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRLIW)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRLIW)].connect[2] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  // InstId_t::INST_ID_SRAIW
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRAIW)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRAIW)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRAIW)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRAIW)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRAIW)].connect[0] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRAIW)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRAIW)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRAIW)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRAIW)].connect[1] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRAIW)].type_lst[2] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRAIW)].msb_lst[2] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRAIW)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRAIW)].connect[2] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  // InstId_t::INST_ID_ADDW
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ADDW)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ADDW)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ADDW)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ADDW)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ADDW)].connect[0] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ADDW)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ADDW)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ADDW)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ADDW)].connect[1] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ADDW)].type_lst[2] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ADDW)].msb_lst[2] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ADDW)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_ADDW)].connect[2] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  // InstId_t::INST_ID_SUBW
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SUBW)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SUBW)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SUBW)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SUBW)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SUBW)].connect[0] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SUBW)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SUBW)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SUBW)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SUBW)].connect[1] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SUBW)].type_lst[2] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SUBW)].msb_lst[2] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SUBW)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SUBW)].connect[2] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  // InstId_t::INST_ID_SLLW
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLLW)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLLW)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLLW)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLLW)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLLW)].connect[0] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLLW)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLLW)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLLW)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLLW)].connect[1] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLLW)].type_lst[2] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLLW)].msb_lst[2] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLLW)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SLLW)].connect[2] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  // InstId_t::INST_ID_SRLW
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRLW)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRLW)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRLW)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRLW)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRLW)].connect[0] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRLW)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRLW)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRLW)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRLW)].connect[1] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRLW)].type_lst[2] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRLW)].msb_lst[2] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRLW)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRLW)].connect[2] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  // InstId_t::INST_ID_SRAW
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRAW)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRAW)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRAW)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRAW)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRAW)].connect[0] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRAW)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRAW)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRAW)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRAW)].connect[1] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRAW)].type_lst[2] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRAW)].msb_lst[2] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRAW)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SRAW)].connect[2] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  // InstId_t::INST_ID_MULW
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_MULW)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_MULW)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_MULW)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_MULW)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_MULW)].connect[0] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_MULW)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_MULW)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_MULW)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_MULW)].connect[1] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_MULW)].type_lst[2] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_MULW)].msb_lst[2] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_MULW)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_MULW)].connect[2] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  // InstId_t::INST_ID_DIVW
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_DIVW)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_DIVW)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_DIVW)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_DIVW)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_DIVW)].connect[0] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_DIVW)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_DIVW)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_DIVW)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_DIVW)].connect[1] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_DIVW)].type_lst[2] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_DIVW)].msb_lst[2] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_DIVW)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_DIVW)].connect[2] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  // InstId_t::INST_ID_DIVUW
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_DIVUW)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_DIVUW)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_DIVUW)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_DIVUW)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_DIVUW)].connect[0] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_DIVUW)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_DIVUW)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_DIVUW)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_DIVUW)].connect[1] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_DIVUW)].type_lst[2] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_DIVUW)].msb_lst[2] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_DIVUW)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_DIVUW)].connect[2] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  // InstId_t::INST_ID_REMW
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_REMW)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_REMW)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_REMW)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_REMW)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_REMW)].connect[0] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_REMW)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_REMW)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_REMW)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_REMW)].connect[1] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_REMW)].type_lst[2] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_REMW)].msb_lst[2] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_REMW)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_REMW)].connect[2] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  // InstId_t::INST_ID_REMUW
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_REMUW)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_REMUW)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_REMUW)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_REMUW)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_REMUW)].connect[0] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_REMUW)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_REMUW)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_REMUW)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_REMUW)].connect[1] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_REMUW)].type_lst[2] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_REMUW)].msb_lst[2] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_REMUW)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_REMUW)].connect[2] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  // InstId_t::INST_ID_LR_D
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LR_D)].size = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LR_D)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LR_D)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LR_D)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LR_D)].connect[0] = 0;
  // ["r[11:7]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LR_D)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LR_D)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LR_D)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_LR_D)].connect[1] = 0;
  // ["r[11:7]", "r[19:15]"]
  // InstId_t::INST_ID_SC_D
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SC_D)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SC_D)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SC_D)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SC_D)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SC_D)].connect[0] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SC_D)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SC_D)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SC_D)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SC_D)].connect[1] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SC_D)].type_lst[2] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SC_D)].msb_lst[2] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SC_D)].lsb_lst[2] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_SC_D)].connect[2] = 0;
  // ["r[11:7]", "r[19:15]", "r[24:20]"]
  // InstId_t::INST_ID_AMOSWAP_D
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOSWAP_D)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOSWAP_D)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOSWAP_D)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOSWAP_D)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOSWAP_D)].connect[0] = 0;
  // ["r[11:7]", "r[24:20]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOSWAP_D)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOSWAP_D)].msb_lst[1] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOSWAP_D)].lsb_lst[1] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOSWAP_D)].connect[1] = 0;
  // ["r[11:7]", "r[24:20]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOSWAP_D)].type_lst[2] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOSWAP_D)].msb_lst[2] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOSWAP_D)].lsb_lst[2] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOSWAP_D)].connect[2] = 0;
  // ["r[11:7]", "r[24:20]", "r[19:15]"]
  // InstId_t::INST_ID_AMOADD_D
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOADD_D)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOADD_D)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOADD_D)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOADD_D)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOADD_D)].connect[0] = 0;
  // ["r[11:7]", "r[24:20]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOADD_D)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOADD_D)].msb_lst[1] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOADD_D)].lsb_lst[1] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOADD_D)].connect[1] = 0;
  // ["r[11:7]", "r[24:20]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOADD_D)].type_lst[2] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOADD_D)].msb_lst[2] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOADD_D)].lsb_lst[2] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOADD_D)].connect[2] = 0;
  // ["r[11:7]", "r[24:20]", "r[19:15]"]
  // InstId_t::INST_ID_AMOXOR_D
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOXOR_D)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOXOR_D)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOXOR_D)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOXOR_D)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOXOR_D)].connect[0] = 0;
  // ["r[11:7]", "r[24:20]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOXOR_D)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOXOR_D)].msb_lst[1] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOXOR_D)].lsb_lst[1] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOXOR_D)].connect[1] = 0;
  // ["r[11:7]", "r[24:20]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOXOR_D)].type_lst[2] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOXOR_D)].msb_lst[2] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOXOR_D)].lsb_lst[2] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOXOR_D)].connect[2] = 0;
  // ["r[11:7]", "r[24:20]", "r[19:15]"]
  // InstId_t::INST_ID_AMOAND_D
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOAND_D)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOAND_D)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOAND_D)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOAND_D)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOAND_D)].connect[0] = 0;
  // ["r[11:7]", "r[24:20]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOAND_D)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOAND_D)].msb_lst[1] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOAND_D)].lsb_lst[1] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOAND_D)].connect[1] = 0;
  // ["r[11:7]", "r[24:20]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOAND_D)].type_lst[2] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOAND_D)].msb_lst[2] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOAND_D)].lsb_lst[2] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOAND_D)].connect[2] = 0;
  // ["r[11:7]", "r[24:20]", "r[19:15]"]
  // InstId_t::INST_ID_AMOOR_D
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOOR_D)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOOR_D)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOOR_D)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOOR_D)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOOR_D)].connect[0] = 0;
  // ["r[11:7]", "r[24:20]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOOR_D)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOOR_D)].msb_lst[1] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOOR_D)].lsb_lst[1] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOOR_D)].connect[1] = 0;
  // ["r[11:7]", "r[24:20]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOOR_D)].type_lst[2] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOOR_D)].msb_lst[2] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOOR_D)].lsb_lst[2] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOOR_D)].connect[2] = 0;
  // ["r[11:7]", "r[24:20]", "r[19:15]"]
  // InstId_t::INST_ID_AMOMIN_D
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMIN_D)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMIN_D)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMIN_D)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMIN_D)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMIN_D)].connect[0] = 0;
  // ["r[11:7]", "r[24:20]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMIN_D)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMIN_D)].msb_lst[1] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMIN_D)].lsb_lst[1] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMIN_D)].connect[1] = 0;
  // ["r[11:7]", "r[24:20]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMIN_D)].type_lst[2] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMIN_D)].msb_lst[2] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMIN_D)].lsb_lst[2] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMIN_D)].connect[2] = 0;
  // ["r[11:7]", "r[24:20]", "r[19:15]"]
  // InstId_t::INST_ID_AMOMAX_D
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMAX_D)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMAX_D)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMAX_D)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMAX_D)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMAX_D)].connect[0] = 0;
  // ["r[11:7]", "r[24:20]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMAX_D)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMAX_D)].msb_lst[1] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMAX_D)].lsb_lst[1] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMAX_D)].connect[1] = 0;
  // ["r[11:7]", "r[24:20]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMAX_D)].type_lst[2] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMAX_D)].msb_lst[2] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMAX_D)].lsb_lst[2] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMAX_D)].connect[2] = 0;
  // ["r[11:7]", "r[24:20]", "r[19:15]"]
  // InstId_t::INST_ID_AMOMINU_D
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMINU_D)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMINU_D)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMINU_D)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMINU_D)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMINU_D)].connect[0] = 0;
  // ["r[11:7]", "r[24:20]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMINU_D)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMINU_D)].msb_lst[1] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMINU_D)].lsb_lst[1] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMINU_D)].connect[1] = 0;
  // ["r[11:7]", "r[24:20]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMINU_D)].type_lst[2] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMINU_D)].msb_lst[2] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMINU_D)].lsb_lst[2] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMINU_D)].connect[2] = 0;
  // ["r[11:7]", "r[24:20]", "r[19:15]"]
  // InstId_t::INST_ID_AMOMAXU_D
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMAXU_D)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMAXU_D)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMAXU_D)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMAXU_D)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMAXU_D)].connect[0] = 0;
  // ["r[11:7]", "r[24:20]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMAXU_D)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMAXU_D)].msb_lst[1] = 24;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMAXU_D)].lsb_lst[1] = 20;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMAXU_D)].connect[1] = 0;
  // ["r[11:7]", "r[24:20]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMAXU_D)].type_lst[2] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMAXU_D)].msb_lst[2] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMAXU_D)].lsb_lst[2] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_AMOMAXU_D)].connect[2] = 0;
  // ["r[11:7]", "r[24:20]", "r[19:15]"]
  // InstId_t::INST_ID_FCVT_L_S
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_L_S)].size = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_L_S)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_L_S)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_L_S)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_L_S)].connect[0] = 0;
  // ["r[11:7]", "f[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_L_S)].type_lst[1] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_L_S)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_L_S)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_L_S)].connect[1] = 0;
  // ["r[11:7]", "f[19:15]"]
  // InstId_t::INST_ID_FCVT_LU_S
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_LU_S)].size = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_LU_S)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_LU_S)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_LU_S)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_LU_S)].connect[0] = 0;
  // ["r[11:7]", "f[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_LU_S)].type_lst[1] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_LU_S)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_LU_S)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_LU_S)].connect[1] = 0;
  // ["r[11:7]", "f[19:15]"]
  // InstId_t::INST_ID_FCVT_S_L
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_S_L)].size = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_S_L)].type_lst[0] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_S_L)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_S_L)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_S_L)].connect[0] = 0;
  // ["f[11:7]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_S_L)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_S_L)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_S_L)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_S_L)].connect[1] = 0;
  // ["f[11:7]", "r[19:15]"]
  // InstId_t::INST_ID_FCVT_S_LU
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_S_LU)].size = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_S_LU)].type_lst[0] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_S_LU)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_S_LU)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_S_LU)].connect[0] = 0;
  // ["f[11:7]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_S_LU)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_S_LU)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_S_LU)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_S_LU)].connect[1] = 0;
  // ["f[11:7]", "r[19:15]"]
  // InstId_t::INST_ID_FCVT_L_D
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_L_D)].size = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_L_D)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_L_D)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_L_D)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_L_D)].connect[0] = 0;
  // ["r[11:7]", "f[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_L_D)].type_lst[1] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_L_D)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_L_D)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_L_D)].connect[1] = 0;
  // ["r[11:7]", "f[19:15]"]
  // InstId_t::INST_ID_FCVT_LU_D
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_LU_D)].size = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_LU_D)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_LU_D)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_LU_D)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_LU_D)].connect[0] = 0;
  // ["r[11:7]", "f[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_LU_D)].type_lst[1] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_LU_D)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_LU_D)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_LU_D)].connect[1] = 0;
  // ["r[11:7]", "f[19:15]"]
  // InstId_t::INST_ID_FMV_X_D
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMV_X_D)].size = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMV_X_D)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMV_X_D)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMV_X_D)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMV_X_D)].connect[0] = 0;
  // ["r[11:7]", "f[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMV_X_D)].type_lst[1] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMV_X_D)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMV_X_D)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMV_X_D)].connect[1] = 0;
  // ["r[11:7]", "f[19:15]"]
  // InstId_t::INST_ID_FCVT_D_L
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_D_L)].size = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_D_L)].type_lst[0] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_D_L)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_D_L)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_D_L)].connect[0] = 0;
  // ["f[11:7]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_D_L)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_D_L)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_D_L)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_D_L)].connect[1] = 0;
  // ["f[11:7]", "r[19:15]"]
  // InstId_t::INST_ID_FCVT_D_LU
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_D_LU)].size = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_D_LU)].type_lst[0] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_D_LU)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_D_LU)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_D_LU)].connect[0] = 0;
  // ["f[11:7]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_D_LU)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_D_LU)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_D_LU)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FCVT_D_LU)].connect[1] = 0;
  // ["f[11:7]", "r[19:15]"]
  // InstId_t::INST_ID_FMV_D_X
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMV_D_X)].size = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMV_D_X)].type_lst[0] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMV_D_X)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMV_D_X)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMV_D_X)].connect[0] = 0;
  // ["f[11:7]", "r[19:15]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMV_D_X)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMV_D_X)].msb_lst[1] = 19;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMV_D_X)].lsb_lst[1] = 15;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_FMV_D_X)].connect[1] = 0;
  // ["f[11:7]", "r[19:15]"]
  // InstId_t::INST_ID_C_ADDI4SPN
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ADDI4SPN)].size = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ADDI4SPN)].type_lst[0] = operandType::operandTypeCompactReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ADDI4SPN)].msb_lst[0] = 4;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ADDI4SPN)].lsb_lst[0] = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ADDI4SPN)].connect[0] = 0;
  // ["cr[4:2]", "u[12:5]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ADDI4SPN)].type_lst[1] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ADDI4SPN)].msb_lst[1] = 12;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ADDI4SPN)].lsb_lst[1] = 5;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ADDI4SPN)].connect[1] = 0;
  // ["cr[4:2]", "u[12:5]"]
  // InstId_t::INST_ID_C_FLD
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FLD)].size = 4;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FLD)].type_lst[0] = operandType::operandTypeCompactFReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FLD)].msb_lst[0] = 4;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FLD)].lsb_lst[0] = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FLD)].connect[0] = 0;
  // ["cf[4:2]", "cr[9:7]", "u[6:5]|", "u[12:10]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FLD)].type_lst[1] = operandType::operandTypeCompactReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FLD)].msb_lst[1] = 9;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FLD)].lsb_lst[1] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FLD)].connect[1] = 0;
  // ["cf[4:2]", "cr[9:7]", "u[6:5]|", "u[12:10]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FLD)].type_lst[2] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FLD)].msb_lst[2] = 6;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FLD)].lsb_lst[2] = 5;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FLD)].connect[2] = 1;
  // ["cf[4:2]", "cr[9:7]", "u[6:5]|", "u[12:10]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FLD)].type_lst[3] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FLD)].msb_lst[3] = 12;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FLD)].lsb_lst[3] = 10;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FLD)].connect[3] = 0;
  // ["cf[4:2]", "cr[9:7]", "u[6:5]|", "u[12:10]"]
  // InstId_t::INST_ID_C_LW
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LW)].size = 5;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LW)].type_lst[0] = operandType::operandTypeCompactReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LW)].msb_lst[0] = 4;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LW)].lsb_lst[0] = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LW)].connect[0] = 0;
  // ["cr[4:2]", "cr[9:7]", "u[5:5]|", "u[12:10]|", "u[6:6]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LW)].type_lst[1] = operandType::operandTypeCompactReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LW)].msb_lst[1] = 9;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LW)].lsb_lst[1] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LW)].connect[1] = 0;
  // ["cr[4:2]", "cr[9:7]", "u[5:5]|", "u[12:10]|", "u[6:6]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LW)].type_lst[2] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LW)].msb_lst[2] = 5;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LW)].lsb_lst[2] = 5;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LW)].connect[2] = 1;
  // ["cr[4:2]", "cr[9:7]", "u[5:5]|", "u[12:10]|", "u[6:6]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LW)].type_lst[3] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LW)].msb_lst[3] = 12;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LW)].lsb_lst[3] = 10;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LW)].connect[3] = 1;
  // ["cr[4:2]", "cr[9:7]", "u[5:5]|", "u[12:10]|", "u[6:6]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LW)].type_lst[4] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LW)].msb_lst[4] = 6;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LW)].lsb_lst[4] = 6;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LW)].connect[4] = 0;
  // ["cr[4:2]", "cr[9:7]", "u[5:5]|", "u[12:10]|", "u[6:6]"]
  // InstId_t::INST_ID_C_FLW
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FLW)].size = 5;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FLW)].type_lst[0] = operandType::operandTypeCompactReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FLW)].msb_lst[0] = 4;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FLW)].lsb_lst[0] = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FLW)].connect[0] = 0;
  // ["cr[4:2]", "cr[9:7]", "u[5:5]|", "u[12:10]|", "u[6:6]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FLW)].type_lst[1] = operandType::operandTypeCompactReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FLW)].msb_lst[1] = 9;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FLW)].lsb_lst[1] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FLW)].connect[1] = 0;
  // ["cr[4:2]", "cr[9:7]", "u[5:5]|", "u[12:10]|", "u[6:6]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FLW)].type_lst[2] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FLW)].msb_lst[2] = 5;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FLW)].lsb_lst[2] = 5;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FLW)].connect[2] = 1;
  // ["cr[4:2]", "cr[9:7]", "u[5:5]|", "u[12:10]|", "u[6:6]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FLW)].type_lst[3] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FLW)].msb_lst[3] = 12;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FLW)].lsb_lst[3] = 10;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FLW)].connect[3] = 1;
  // ["cr[4:2]", "cr[9:7]", "u[5:5]|", "u[12:10]|", "u[6:6]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FLW)].type_lst[4] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FLW)].msb_lst[4] = 6;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FLW)].lsb_lst[4] = 6;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FLW)].connect[4] = 0;
  // ["cr[4:2]", "cr[9:7]", "u[5:5]|", "u[12:10]|", "u[6:6]"]
  // InstId_t::INST_ID_C_LD
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LD)].size = 4;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LD)].type_lst[0] = operandType::operandTypeCompactReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LD)].msb_lst[0] = 4;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LD)].lsb_lst[0] = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LD)].connect[0] = 0;
  // ["cr[4:2]", "cr[9:7]", "u[6:5]|", "u[12:10]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LD)].type_lst[1] = operandType::operandTypeCompactReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LD)].msb_lst[1] = 9;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LD)].lsb_lst[1] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LD)].connect[1] = 0;
  // ["cr[4:2]", "cr[9:7]", "u[6:5]|", "u[12:10]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LD)].type_lst[2] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LD)].msb_lst[2] = 6;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LD)].lsb_lst[2] = 5;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LD)].connect[2] = 1;
  // ["cr[4:2]", "cr[9:7]", "u[6:5]|", "u[12:10]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LD)].type_lst[3] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LD)].msb_lst[3] = 12;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LD)].lsb_lst[3] = 10;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LD)].connect[3] = 0;
  // ["cr[4:2]", "cr[9:7]", "u[6:5]|", "u[12:10]"]
  // InstId_t::INST_ID_C_FSD
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FSD)].size = 4;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FSD)].type_lst[0] = operandType::operandTypeCompactReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FSD)].msb_lst[0] = 4;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FSD)].lsb_lst[0] = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FSD)].connect[0] = 0;
  // ["cr[4:2]", "cr[9:7]", "u[6:5]|", "u[12:10]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FSD)].type_lst[1] = operandType::operandTypeCompactReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FSD)].msb_lst[1] = 9;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FSD)].lsb_lst[1] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FSD)].connect[1] = 0;
  // ["cr[4:2]", "cr[9:7]", "u[6:5]|", "u[12:10]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FSD)].type_lst[2] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FSD)].msb_lst[2] = 6;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FSD)].lsb_lst[2] = 5;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FSD)].connect[2] = 1;
  // ["cr[4:2]", "cr[9:7]", "u[6:5]|", "u[12:10]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FSD)].type_lst[3] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FSD)].msb_lst[3] = 12;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FSD)].lsb_lst[3] = 10;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FSD)].connect[3] = 0;
  // ["cr[4:2]", "cr[9:7]", "u[6:5]|", "u[12:10]"]
  // InstId_t::INST_ID_C_SW
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SW)].size = 5;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SW)].type_lst[0] = operandType::operandTypeCompactReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SW)].msb_lst[0] = 4;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SW)].lsb_lst[0] = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SW)].connect[0] = 0;
  // ["cr[4:2]", "cr[9:7]", "u[5:5]|", "u[12:10]|", "u[6:6]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SW)].type_lst[1] = operandType::operandTypeCompactReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SW)].msb_lst[1] = 9;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SW)].lsb_lst[1] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SW)].connect[1] = 0;
  // ["cr[4:2]", "cr[9:7]", "u[5:5]|", "u[12:10]|", "u[6:6]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SW)].type_lst[2] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SW)].msb_lst[2] = 5;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SW)].lsb_lst[2] = 5;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SW)].connect[2] = 1;
  // ["cr[4:2]", "cr[9:7]", "u[5:5]|", "u[12:10]|", "u[6:6]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SW)].type_lst[3] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SW)].msb_lst[3] = 12;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SW)].lsb_lst[3] = 10;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SW)].connect[3] = 1;
  // ["cr[4:2]", "cr[9:7]", "u[5:5]|", "u[12:10]|", "u[6:6]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SW)].type_lst[4] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SW)].msb_lst[4] = 6;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SW)].lsb_lst[4] = 6;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SW)].connect[4] = 0;
  // ["cr[4:2]", "cr[9:7]", "u[5:5]|", "u[12:10]|", "u[6:6]"]
  // InstId_t::INST_ID_C_FSW
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FSW)].size = 5;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FSW)].type_lst[0] = operandType::operandTypeCompactReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FSW)].msb_lst[0] = 4;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FSW)].lsb_lst[0] = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FSW)].connect[0] = 0;
  // ["cr[4:2]", "cr[9:7]", "u[5:5]|", "u[12:10]|", "u[6:6]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FSW)].type_lst[1] = operandType::operandTypeCompactReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FSW)].msb_lst[1] = 9;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FSW)].lsb_lst[1] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FSW)].connect[1] = 0;
  // ["cr[4:2]", "cr[9:7]", "u[5:5]|", "u[12:10]|", "u[6:6]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FSW)].type_lst[2] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FSW)].msb_lst[2] = 5;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FSW)].lsb_lst[2] = 5;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FSW)].connect[2] = 1;
  // ["cr[4:2]", "cr[9:7]", "u[5:5]|", "u[12:10]|", "u[6:6]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FSW)].type_lst[3] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FSW)].msb_lst[3] = 12;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FSW)].lsb_lst[3] = 10;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FSW)].connect[3] = 1;
  // ["cr[4:2]", "cr[9:7]", "u[5:5]|", "u[12:10]|", "u[6:6]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FSW)].type_lst[4] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FSW)].msb_lst[4] = 6;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FSW)].lsb_lst[4] = 6;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FSW)].connect[4] = 0;
  // ["cr[4:2]", "cr[9:7]", "u[5:5]|", "u[12:10]|", "u[6:6]"]
  // InstId_t::INST_ID_C_SD
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SD)].size = 4;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SD)].type_lst[0] = operandType::operandTypeCompactReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SD)].msb_lst[0] = 4;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SD)].lsb_lst[0] = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SD)].connect[0] = 0;
  // ["cr[4:2]", "cr[9:7]", "u[6:5]|", "u[12:10]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SD)].type_lst[1] = operandType::operandTypeCompactReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SD)].msb_lst[1] = 9;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SD)].lsb_lst[1] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SD)].connect[1] = 0;
  // ["cr[4:2]", "cr[9:7]", "u[6:5]|", "u[12:10]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SD)].type_lst[2] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SD)].msb_lst[2] = 6;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SD)].lsb_lst[2] = 5;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SD)].connect[2] = 1;
  // ["cr[4:2]", "cr[9:7]", "u[6:5]|", "u[12:10]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SD)].type_lst[3] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SD)].msb_lst[3] = 12;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SD)].lsb_lst[3] = 10;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SD)].connect[3] = 0;
  // ["cr[4:2]", "cr[9:7]", "u[6:5]|", "u[12:10]"]
  // InstId_t::INST_ID_C_NOP
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_NOP)].size = 0;
  // InstId_t::INST_ID_C_ADDI
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ADDI)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ADDI)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ADDI)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ADDI)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ADDI)].connect[0] = 0;
  // ["r[11:7]", "u[12:12]|", "u[6:2]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ADDI)].type_lst[1] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ADDI)].msb_lst[1] = 12;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ADDI)].lsb_lst[1] = 12;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ADDI)].connect[1] = 1;
  // ["r[11:7]", "u[12:12]|", "u[6:2]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ADDI)].type_lst[2] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ADDI)].msb_lst[2] = 6;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ADDI)].lsb_lst[2] = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ADDI)].connect[2] = 0;
  // ["r[11:7]", "u[12:12]|", "u[6:2]"]
  // InstId_t::INST_ID_C_JAL
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_JAL)].size = 8;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_JAL)].type_lst[0] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_JAL)].msb_lst[0] = 12;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_JAL)].lsb_lst[0] = 12;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_JAL)].connect[0] = 1;
  // ["u[12:12]|", "u[7:7]|", "u[10:9]|", "u[6:6]|", "u[7:7]|", "u[2:2]|", "u[11:11]|", "u[5:3]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_JAL)].type_lst[1] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_JAL)].msb_lst[1] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_JAL)].lsb_lst[1] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_JAL)].connect[1] = 1;
  // ["u[12:12]|", "u[7:7]|", "u[10:9]|", "u[6:6]|", "u[7:7]|", "u[2:2]|", "u[11:11]|", "u[5:3]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_JAL)].type_lst[2] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_JAL)].msb_lst[2] = 10;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_JAL)].lsb_lst[2] = 9;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_JAL)].connect[2] = 1;
  // ["u[12:12]|", "u[7:7]|", "u[10:9]|", "u[6:6]|", "u[7:7]|", "u[2:2]|", "u[11:11]|", "u[5:3]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_JAL)].type_lst[3] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_JAL)].msb_lst[3] = 6;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_JAL)].lsb_lst[3] = 6;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_JAL)].connect[3] = 1;
  // ["u[12:12]|", "u[7:7]|", "u[10:9]|", "u[6:6]|", "u[7:7]|", "u[2:2]|", "u[11:11]|", "u[5:3]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_JAL)].type_lst[4] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_JAL)].msb_lst[4] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_JAL)].lsb_lst[4] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_JAL)].connect[4] = 1;
  // ["u[12:12]|", "u[7:7]|", "u[10:9]|", "u[6:6]|", "u[7:7]|", "u[2:2]|", "u[11:11]|", "u[5:3]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_JAL)].type_lst[5] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_JAL)].msb_lst[5] = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_JAL)].lsb_lst[5] = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_JAL)].connect[5] = 1;
  // ["u[12:12]|", "u[7:7]|", "u[10:9]|", "u[6:6]|", "u[7:7]|", "u[2:2]|", "u[11:11]|", "u[5:3]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_JAL)].type_lst[6] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_JAL)].msb_lst[6] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_JAL)].lsb_lst[6] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_JAL)].connect[6] = 1;
  // ["u[12:12]|", "u[7:7]|", "u[10:9]|", "u[6:6]|", "u[7:7]|", "u[2:2]|", "u[11:11]|", "u[5:3]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_JAL)].type_lst[7] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_JAL)].msb_lst[7] = 5;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_JAL)].lsb_lst[7] = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_JAL)].connect[7] = 0;
  // ["u[12:12]|", "u[7:7]|", "u[10:9]|", "u[6:6]|", "u[7:7]|", "u[2:2]|", "u[11:11]|", "u[5:3]"]
  // InstId_t::INST_ID_C_ADDIW
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ADDIW)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ADDIW)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ADDIW)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ADDIW)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ADDIW)].connect[0] = 0;
  // ["r[11:7]", "h[12:12]|", "h[6:2]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ADDIW)].type_lst[1] = operandType::operandTypeHex;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ADDIW)].msb_lst[1] = 12;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ADDIW)].lsb_lst[1] = 12;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ADDIW)].connect[1] = 1;
  // ["r[11:7]", "h[12:12]|", "h[6:2]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ADDIW)].type_lst[2] = operandType::operandTypeHex;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ADDIW)].msb_lst[2] = 6;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ADDIW)].lsb_lst[2] = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ADDIW)].connect[2] = 0;
  // ["r[11:7]", "h[12:12]|", "h[6:2]"]
  // InstId_t::INST_ID_C_LI
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LI)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LI)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LI)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LI)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LI)].connect[0] = 0;
  // ["r[11:7]", "u[12:12]|", "h[6:2]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LI)].type_lst[1] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LI)].msb_lst[1] = 12;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LI)].lsb_lst[1] = 12;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LI)].connect[1] = 1;
  // ["r[11:7]", "u[12:12]|", "h[6:2]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LI)].type_lst[2] = operandType::operandTypeHex;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LI)].msb_lst[2] = 6;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LI)].lsb_lst[2] = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LI)].connect[2] = 0;
  // ["r[11:7]", "u[12:12]|", "h[6:2]"]
  // InstId_t::INST_ID_C_ADDI16SP
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ADDI16SP)].size = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ADDI16SP)].type_lst[0] = operandType::operandTypeCompactReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ADDI16SP)].msb_lst[0] = 4;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ADDI16SP)].lsb_lst[0] = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ADDI16SP)].connect[0] = 0;
  // ["cr[4:2]", "u[12:5]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ADDI16SP)].type_lst[1] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ADDI16SP)].msb_lst[1] = 12;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ADDI16SP)].lsb_lst[1] = 5;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ADDI16SP)].connect[1] = 0;
  // ["cr[4:2]", "u[12:5]"]
  // InstId_t::INST_ID_C_LUI
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LUI)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LUI)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LUI)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LUI)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LUI)].connect[0] = 0;
  // ["r[11:7]", "u[12:12]|", "h[6:2]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LUI)].type_lst[1] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LUI)].msb_lst[1] = 12;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LUI)].lsb_lst[1] = 12;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LUI)].connect[1] = 1;
  // ["r[11:7]", "u[12:12]|", "h[6:2]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LUI)].type_lst[2] = operandType::operandTypeHex;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LUI)].msb_lst[2] = 6;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LUI)].lsb_lst[2] = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LUI)].connect[2] = 0;
  // ["r[11:7]", "u[12:12]|", "h[6:2]"]
  // InstId_t::INST_ID_C_SRLI
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SRLI)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SRLI)].type_lst[0] = operandType::operandTypeCompactReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SRLI)].msb_lst[0] = 9;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SRLI)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SRLI)].connect[0] = 0;
  // ["cr[9:7]", "u[12:12]|", "h[6:2]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SRLI)].type_lst[1] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SRLI)].msb_lst[1] = 12;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SRLI)].lsb_lst[1] = 12;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SRLI)].connect[1] = 1;
  // ["cr[9:7]", "u[12:12]|", "h[6:2]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SRLI)].type_lst[2] = operandType::operandTypeHex;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SRLI)].msb_lst[2] = 6;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SRLI)].lsb_lst[2] = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SRLI)].connect[2] = 0;
  // ["cr[9:7]", "u[12:12]|", "h[6:2]"]
  // InstId_t::INST_ID_C_SRLI64
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SRLI64)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SRLI64)].type_lst[0] = operandType::operandTypeCompactReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SRLI64)].msb_lst[0] = 9;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SRLI64)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SRLI64)].connect[0] = 0;
  // ["cr[9:7]", "u[12:12]|", "h[6:2]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SRLI64)].type_lst[1] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SRLI64)].msb_lst[1] = 12;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SRLI64)].lsb_lst[1] = 12;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SRLI64)].connect[1] = 1;
  // ["cr[9:7]", "u[12:12]|", "h[6:2]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SRLI64)].type_lst[2] = operandType::operandTypeHex;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SRLI64)].msb_lst[2] = 6;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SRLI64)].lsb_lst[2] = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SRLI64)].connect[2] = 0;
  // ["cr[9:7]", "u[12:12]|", "h[6:2]"]
  // InstId_t::INST_ID_C_SRAI
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SRAI)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SRAI)].type_lst[0] = operandType::operandTypeCompactReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SRAI)].msb_lst[0] = 9;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SRAI)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SRAI)].connect[0] = 0;
  // ["cr[9:7]", "u[12:12]|", "h[6:2]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SRAI)].type_lst[1] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SRAI)].msb_lst[1] = 12;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SRAI)].lsb_lst[1] = 12;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SRAI)].connect[1] = 1;
  // ["cr[9:7]", "u[12:12]|", "h[6:2]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SRAI)].type_lst[2] = operandType::operandTypeHex;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SRAI)].msb_lst[2] = 6;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SRAI)].lsb_lst[2] = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SRAI)].connect[2] = 0;
  // ["cr[9:7]", "u[12:12]|", "h[6:2]"]
  // InstId_t::INST_ID_C_SRAI64
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SRAI64)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SRAI64)].type_lst[0] = operandType::operandTypeCompactReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SRAI64)].msb_lst[0] = 9;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SRAI64)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SRAI64)].connect[0] = 0;
  // ["cr[9:7]", "u[12:12]|", "h[6:2]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SRAI64)].type_lst[1] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SRAI64)].msb_lst[1] = 12;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SRAI64)].lsb_lst[1] = 12;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SRAI64)].connect[1] = 1;
  // ["cr[9:7]", "u[12:12]|", "h[6:2]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SRAI64)].type_lst[2] = operandType::operandTypeHex;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SRAI64)].msb_lst[2] = 6;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SRAI64)].lsb_lst[2] = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SRAI64)].connect[2] = 0;
  // ["cr[9:7]", "u[12:12]|", "h[6:2]"]
  // InstId_t::INST_ID_C_ANDI
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ANDI)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ANDI)].type_lst[0] = operandType::operandTypeCompactReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ANDI)].msb_lst[0] = 9;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ANDI)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ANDI)].connect[0] = 0;
  // ["cr[9:7]", "u[12:12]|", "h[6:2]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ANDI)].type_lst[1] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ANDI)].msb_lst[1] = 12;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ANDI)].lsb_lst[1] = 12;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ANDI)].connect[1] = 1;
  // ["cr[9:7]", "u[12:12]|", "h[6:2]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ANDI)].type_lst[2] = operandType::operandTypeHex;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ANDI)].msb_lst[2] = 6;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ANDI)].lsb_lst[2] = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ANDI)].connect[2] = 0;
  // ["cr[9:7]", "u[12:12]|", "h[6:2]"]
  // InstId_t::INST_ID_C_SUB
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SUB)].size = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SUB)].type_lst[0] = operandType::operandTypeCompactReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SUB)].msb_lst[0] = 9;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SUB)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SUB)].connect[0] = 0;
  // ["cr[9:7]", "cr[4:2]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SUB)].type_lst[1] = operandType::operandTypeCompactReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SUB)].msb_lst[1] = 4;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SUB)].lsb_lst[1] = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SUB)].connect[1] = 0;
  // ["cr[9:7]", "cr[4:2]"]
  // InstId_t::INST_ID_C_XOR
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_XOR)].size = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_XOR)].type_lst[0] = operandType::operandTypeCompactReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_XOR)].msb_lst[0] = 9;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_XOR)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_XOR)].connect[0] = 0;
  // ["cr[9:7]", "cr[4:2]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_XOR)].type_lst[1] = operandType::operandTypeCompactReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_XOR)].msb_lst[1] = 4;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_XOR)].lsb_lst[1] = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_XOR)].connect[1] = 0;
  // ["cr[9:7]", "cr[4:2]"]
  // InstId_t::INST_ID_C_OR
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_OR)].size = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_OR)].type_lst[0] = operandType::operandTypeCompactReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_OR)].msb_lst[0] = 9;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_OR)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_OR)].connect[0] = 0;
  // ["cr[9:7]", "cr[4:2]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_OR)].type_lst[1] = operandType::operandTypeCompactReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_OR)].msb_lst[1] = 4;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_OR)].lsb_lst[1] = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_OR)].connect[1] = 0;
  // ["cr[9:7]", "cr[4:2]"]
  // InstId_t::INST_ID_C_AND
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_AND)].size = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_AND)].type_lst[0] = operandType::operandTypeCompactReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_AND)].msb_lst[0] = 9;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_AND)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_AND)].connect[0] = 0;
  // ["cr[9:7]", "cr[4:2]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_AND)].type_lst[1] = operandType::operandTypeCompactReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_AND)].msb_lst[1] = 4;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_AND)].lsb_lst[1] = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_AND)].connect[1] = 0;
  // ["cr[9:7]", "cr[4:2]"]
  // InstId_t::INST_ID_C_SUBW
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SUBW)].size = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SUBW)].type_lst[0] = operandType::operandTypeCompactReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SUBW)].msb_lst[0] = 9;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SUBW)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SUBW)].connect[0] = 0;
  // ["cr[9:7]", "r[6:2]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SUBW)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SUBW)].msb_lst[1] = 6;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SUBW)].lsb_lst[1] = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SUBW)].connect[1] = 0;
  // ["cr[9:7]", "r[6:2]"]
  // InstId_t::INST_ID_C_ADDW
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ADDW)].size = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ADDW)].type_lst[0] = operandType::operandTypeCompactReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ADDW)].msb_lst[0] = 9;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ADDW)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ADDW)].connect[0] = 0;
  // ["cr[9:7]", "r[6:2]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ADDW)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ADDW)].msb_lst[1] = 6;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ADDW)].lsb_lst[1] = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ADDW)].connect[1] = 0;
  // ["cr[9:7]", "r[6:2]"]
  // InstId_t::INST_ID_C_J
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_J)].size = 8;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_J)].type_lst[0] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_J)].msb_lst[0] = 12;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_J)].lsb_lst[0] = 12;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_J)].connect[0] = 1;
  // ["u[12:12]|", "u[8:8]|", "u[10:9]|", "u[6:6]|", "u[7:7]|", "u[2:2]|", "u[11:11]|", "u[5:3]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_J)].type_lst[1] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_J)].msb_lst[1] = 8;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_J)].lsb_lst[1] = 8;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_J)].connect[1] = 1;
  // ["u[12:12]|", "u[8:8]|", "u[10:9]|", "u[6:6]|", "u[7:7]|", "u[2:2]|", "u[11:11]|", "u[5:3]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_J)].type_lst[2] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_J)].msb_lst[2] = 10;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_J)].lsb_lst[2] = 9;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_J)].connect[2] = 1;
  // ["u[12:12]|", "u[8:8]|", "u[10:9]|", "u[6:6]|", "u[7:7]|", "u[2:2]|", "u[11:11]|", "u[5:3]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_J)].type_lst[3] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_J)].msb_lst[3] = 6;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_J)].lsb_lst[3] = 6;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_J)].connect[3] = 1;
  // ["u[12:12]|", "u[8:8]|", "u[10:9]|", "u[6:6]|", "u[7:7]|", "u[2:2]|", "u[11:11]|", "u[5:3]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_J)].type_lst[4] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_J)].msb_lst[4] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_J)].lsb_lst[4] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_J)].connect[4] = 1;
  // ["u[12:12]|", "u[8:8]|", "u[10:9]|", "u[6:6]|", "u[7:7]|", "u[2:2]|", "u[11:11]|", "u[5:3]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_J)].type_lst[5] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_J)].msb_lst[5] = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_J)].lsb_lst[5] = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_J)].connect[5] = 1;
  // ["u[12:12]|", "u[8:8]|", "u[10:9]|", "u[6:6]|", "u[7:7]|", "u[2:2]|", "u[11:11]|", "u[5:3]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_J)].type_lst[6] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_J)].msb_lst[6] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_J)].lsb_lst[6] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_J)].connect[6] = 1;
  // ["u[12:12]|", "u[8:8]|", "u[10:9]|", "u[6:6]|", "u[7:7]|", "u[2:2]|", "u[11:11]|", "u[5:3]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_J)].type_lst[7] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_J)].msb_lst[7] = 5;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_J)].lsb_lst[7] = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_J)].connect[7] = 0;
  // ["u[12:12]|", "u[8:8]|", "u[10:9]|", "u[6:6]|", "u[7:7]|", "u[2:2]|", "u[11:11]|", "u[5:3]"]
  // InstId_t::INST_ID_C_BEQZ
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_BEQZ)].size = 6;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_BEQZ)].type_lst[0] = operandType::operandTypeCompactReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_BEQZ)].msb_lst[0] = 9;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_BEQZ)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_BEQZ)].connect[0] = 0;
  // ["cr[9:7]", "u[12:12]|", "u[6:5]|", "u[2:2]|", "u[11:10]|", "u[4:3]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_BEQZ)].type_lst[1] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_BEQZ)].msb_lst[1] = 12;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_BEQZ)].lsb_lst[1] = 12;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_BEQZ)].connect[1] = 1;
  // ["cr[9:7]", "u[12:12]|", "u[6:5]|", "u[2:2]|", "u[11:10]|", "u[4:3]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_BEQZ)].type_lst[2] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_BEQZ)].msb_lst[2] = 6;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_BEQZ)].lsb_lst[2] = 5;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_BEQZ)].connect[2] = 1;
  // ["cr[9:7]", "u[12:12]|", "u[6:5]|", "u[2:2]|", "u[11:10]|", "u[4:3]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_BEQZ)].type_lst[3] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_BEQZ)].msb_lst[3] = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_BEQZ)].lsb_lst[3] = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_BEQZ)].connect[3] = 1;
  // ["cr[9:7]", "u[12:12]|", "u[6:5]|", "u[2:2]|", "u[11:10]|", "u[4:3]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_BEQZ)].type_lst[4] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_BEQZ)].msb_lst[4] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_BEQZ)].lsb_lst[4] = 10;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_BEQZ)].connect[4] = 1;
  // ["cr[9:7]", "u[12:12]|", "u[6:5]|", "u[2:2]|", "u[11:10]|", "u[4:3]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_BEQZ)].type_lst[5] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_BEQZ)].msb_lst[5] = 4;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_BEQZ)].lsb_lst[5] = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_BEQZ)].connect[5] = 0;
  // ["cr[9:7]", "u[12:12]|", "u[6:5]|", "u[2:2]|", "u[11:10]|", "u[4:3]"]
  // InstId_t::INST_ID_C_BNEZ
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_BNEZ)].size = 6;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_BNEZ)].type_lst[0] = operandType::operandTypeCompactReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_BNEZ)].msb_lst[0] = 9;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_BNEZ)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_BNEZ)].connect[0] = 0;
  // ["cr[9:7]", "u[12:12]|", "u[6:5]|", "u[2:2]|", "u[11:10]|", "u[4:3]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_BNEZ)].type_lst[1] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_BNEZ)].msb_lst[1] = 12;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_BNEZ)].lsb_lst[1] = 12;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_BNEZ)].connect[1] = 1;
  // ["cr[9:7]", "u[12:12]|", "u[6:5]|", "u[2:2]|", "u[11:10]|", "u[4:3]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_BNEZ)].type_lst[2] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_BNEZ)].msb_lst[2] = 6;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_BNEZ)].lsb_lst[2] = 5;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_BNEZ)].connect[2] = 1;
  // ["cr[9:7]", "u[12:12]|", "u[6:5]|", "u[2:2]|", "u[11:10]|", "u[4:3]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_BNEZ)].type_lst[3] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_BNEZ)].msb_lst[3] = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_BNEZ)].lsb_lst[3] = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_BNEZ)].connect[3] = 1;
  // ["cr[9:7]", "u[12:12]|", "u[6:5]|", "u[2:2]|", "u[11:10]|", "u[4:3]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_BNEZ)].type_lst[4] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_BNEZ)].msb_lst[4] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_BNEZ)].lsb_lst[4] = 10;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_BNEZ)].connect[4] = 1;
  // ["cr[9:7]", "u[12:12]|", "u[6:5]|", "u[2:2]|", "u[11:10]|", "u[4:3]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_BNEZ)].type_lst[5] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_BNEZ)].msb_lst[5] = 4;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_BNEZ)].lsb_lst[5] = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_BNEZ)].connect[5] = 0;
  // ["cr[9:7]", "u[12:12]|", "u[6:5]|", "u[2:2]|", "u[11:10]|", "u[4:3]"]
  // InstId_t::INST_ID_C_SLLI
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SLLI)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SLLI)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SLLI)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SLLI)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SLLI)].connect[0] = 0;
  // ["r[11:7]", "u[12:12]|", "u[6:2]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SLLI)].type_lst[1] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SLLI)].msb_lst[1] = 12;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SLLI)].lsb_lst[1] = 12;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SLLI)].connect[1] = 1;
  // ["r[11:7]", "u[12:12]|", "u[6:2]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SLLI)].type_lst[2] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SLLI)].msb_lst[2] = 6;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SLLI)].lsb_lst[2] = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SLLI)].connect[2] = 0;
  // ["r[11:7]", "u[12:12]|", "u[6:2]"]
  // InstId_t::INST_ID_C_FLDSP
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FLDSP)].size = 4;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FLDSP)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FLDSP)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FLDSP)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FLDSP)].connect[0] = 0;
  // ["r[11:7]", "u[4:2]|", "u[12:12]|", "u[6:5]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FLDSP)].type_lst[1] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FLDSP)].msb_lst[1] = 4;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FLDSP)].lsb_lst[1] = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FLDSP)].connect[1] = 1;
  // ["r[11:7]", "u[4:2]|", "u[12:12]|", "u[6:5]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FLDSP)].type_lst[2] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FLDSP)].msb_lst[2] = 12;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FLDSP)].lsb_lst[2] = 12;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FLDSP)].connect[2] = 1;
  // ["r[11:7]", "u[4:2]|", "u[12:12]|", "u[6:5]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FLDSP)].type_lst[3] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FLDSP)].msb_lst[3] = 6;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FLDSP)].lsb_lst[3] = 5;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FLDSP)].connect[3] = 0;
  // ["r[11:7]", "u[4:2]|", "u[12:12]|", "u[6:5]"]
  // InstId_t::INST_ID_C_LWSP
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LWSP)].size = 4;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LWSP)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LWSP)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LWSP)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LWSP)].connect[0] = 0;
  // ["r[11:7]", "u[3:2]|", "u[12:12]|", "u[6:4]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LWSP)].type_lst[1] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LWSP)].msb_lst[1] = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LWSP)].lsb_lst[1] = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LWSP)].connect[1] = 1;
  // ["r[11:7]", "u[3:2]|", "u[12:12]|", "u[6:4]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LWSP)].type_lst[2] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LWSP)].msb_lst[2] = 12;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LWSP)].lsb_lst[2] = 12;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LWSP)].connect[2] = 1;
  // ["r[11:7]", "u[3:2]|", "u[12:12]|", "u[6:4]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LWSP)].type_lst[3] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LWSP)].msb_lst[3] = 6;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LWSP)].lsb_lst[3] = 4;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LWSP)].connect[3] = 0;
  // ["r[11:7]", "u[3:2]|", "u[12:12]|", "u[6:4]"]
  // InstId_t::INST_ID_C_FLWSP
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FLWSP)].size = 4;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FLWSP)].type_lst[0] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FLWSP)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FLWSP)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FLWSP)].connect[0] = 0;
  // ["f[11:7]", "u[3:2]|", "u[12:12]|", "u[6:4]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FLWSP)].type_lst[1] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FLWSP)].msb_lst[1] = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FLWSP)].lsb_lst[1] = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FLWSP)].connect[1] = 1;
  // ["f[11:7]", "u[3:2]|", "u[12:12]|", "u[6:4]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FLWSP)].type_lst[2] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FLWSP)].msb_lst[2] = 12;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FLWSP)].lsb_lst[2] = 12;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FLWSP)].connect[2] = 1;
  // ["f[11:7]", "u[3:2]|", "u[12:12]|", "u[6:4]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FLWSP)].type_lst[3] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FLWSP)].msb_lst[3] = 6;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FLWSP)].lsb_lst[3] = 4;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FLWSP)].connect[3] = 0;
  // ["f[11:7]", "u[3:2]|", "u[12:12]|", "u[6:4]"]
  // InstId_t::INST_ID_C_LDSP
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LDSP)].size = 4;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LDSP)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LDSP)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LDSP)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LDSP)].connect[0] = 0;
  // ["r[11:7]", "u[4:2]|", "u[12:12]|", "u[6:5]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LDSP)].type_lst[1] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LDSP)].msb_lst[1] = 4;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LDSP)].lsb_lst[1] = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LDSP)].connect[1] = 1;
  // ["r[11:7]", "u[4:2]|", "u[12:12]|", "u[6:5]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LDSP)].type_lst[2] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LDSP)].msb_lst[2] = 12;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LDSP)].lsb_lst[2] = 12;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LDSP)].connect[2] = 1;
  // ["r[11:7]", "u[4:2]|", "u[12:12]|", "u[6:5]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LDSP)].type_lst[3] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LDSP)].msb_lst[3] = 6;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LDSP)].lsb_lst[3] = 5;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_LDSP)].connect[3] = 0;
  // ["r[11:7]", "u[4:2]|", "u[12:12]|", "u[6:5]"]
  // InstId_t::INST_ID_C_JR
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_JR)].size = 1;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_JR)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_JR)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_JR)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_JR)].connect[0] = 0;
  // ["r[11:7]"]
  // InstId_t::INST_ID_C_MV
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_MV)].size = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_MV)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_MV)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_MV)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_MV)].connect[0] = 0;
  // ["r[11:7]", "r[6:2]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_MV)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_MV)].msb_lst[1] = 6;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_MV)].lsb_lst[1] = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_MV)].connect[1] = 0;
  // ["r[11:7]", "r[6:2]"]
  // InstId_t::INST_ID_C_EBREAK
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_EBREAK)].size = 0;
  // InstId_t::INST_ID_C_JALR
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_JALR)].size = 1;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_JALR)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_JALR)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_JALR)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_JALR)].connect[0] = 0;
  // ["r[11:7]"]
  // InstId_t::INST_ID_C_ADD
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ADD)].size = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ADD)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ADD)].msb_lst[0] = 11;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ADD)].lsb_lst[0] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ADD)].connect[0] = 0;
  // ["r[11:7]", "r[6:2]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ADD)].type_lst[1] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ADD)].msb_lst[1] = 6;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ADD)].lsb_lst[1] = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_ADD)].connect[1] = 0;
  // ["r[11:7]", "r[6:2]"]
  // InstId_t::INST_ID_C_FSDSP
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FSDSP)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FSDSP)].type_lst[0] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FSDSP)].msb_lst[0] = 6;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FSDSP)].lsb_lst[0] = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FSDSP)].connect[0] = 0;
  // ["f[6:2]", "u[9:7]|", "u[12:10]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FSDSP)].type_lst[1] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FSDSP)].msb_lst[1] = 9;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FSDSP)].lsb_lst[1] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FSDSP)].connect[1] = 1;
  // ["f[6:2]", "u[9:7]|", "u[12:10]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FSDSP)].type_lst[2] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FSDSP)].msb_lst[2] = 12;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FSDSP)].lsb_lst[2] = 10;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FSDSP)].connect[2] = 0;
  // ["f[6:2]", "u[9:7]|", "u[12:10]"]
  // InstId_t::INST_ID_C_SWSP
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SWSP)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SWSP)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SWSP)].msb_lst[0] = 6;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SWSP)].lsb_lst[0] = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SWSP)].connect[0] = 0;
  // ["r[6:2]", "u[8:7]|", "u[12:9]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SWSP)].type_lst[1] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SWSP)].msb_lst[1] = 8;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SWSP)].lsb_lst[1] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SWSP)].connect[1] = 1;
  // ["r[6:2]", "u[8:7]|", "u[12:9]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SWSP)].type_lst[2] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SWSP)].msb_lst[2] = 12;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SWSP)].lsb_lst[2] = 9;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SWSP)].connect[2] = 0;
  // ["r[6:2]", "u[8:7]|", "u[12:9]"]
  // InstId_t::INST_ID_C_FSWSP
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FSWSP)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FSWSP)].type_lst[0] = operandType::operandTypeFreg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FSWSP)].msb_lst[0] = 6;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FSWSP)].lsb_lst[0] = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FSWSP)].connect[0] = 0;
  // ["f[6:2]", "u[9:7]|", "u[12:10]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FSWSP)].type_lst[1] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FSWSP)].msb_lst[1] = 9;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FSWSP)].lsb_lst[1] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FSWSP)].connect[1] = 1;
  // ["f[6:2]", "u[9:7]|", "u[12:10]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FSWSP)].type_lst[2] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FSWSP)].msb_lst[2] = 12;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FSWSP)].lsb_lst[2] = 10;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_FSWSP)].connect[2] = 0;
  // ["f[6:2]", "u[9:7]|", "u[12:10]"]
  // InstId_t::INST_ID_C_SDSP
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SDSP)].size = 3;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SDSP)].type_lst[0] = operandType::operandTypeReg;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SDSP)].msb_lst[0] = 6;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SDSP)].lsb_lst[0] = 2;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SDSP)].connect[0] = 0;
  // ["r[6:2]", "u[9:7]|", "u[12:10]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SDSP)].type_lst[1] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SDSP)].msb_lst[1] = 9;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SDSP)].lsb_lst[1] = 7;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SDSP)].connect[1] = 1;
  // ["r[6:2]", "u[9:7]|", "u[12:10]"]
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SDSP)].type_lst[2] = operandType::operandTypeUnSign;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SDSP)].msb_lst[2] = 12;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SDSP)].lsb_lst[2] = 10;
  inst_operand[static_cast<uint32_t>(InstId_t::INST_ID_C_SDSP)].connect[2] = 0;
  // ["r[6:2]", "u[9:7]|", "u[12:10]"]
}
