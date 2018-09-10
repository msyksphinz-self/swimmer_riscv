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
#include "inst_list_riscv.hpp"
#include "inst_category_riscv.hpp"
#include "dec_utils_riscv.hpp"
#include "riscv_pe_thread.hpp"


class RiscvDec {
public:
static InstCategory GetInstCategory (InstId_t inst_id);
public:
static InstSuffix GetInstSuffix (InstId_t inst_id);
public:
static uint32_t GetInstLength (InstId_t inst_id);
public:
static uint32_t GetInstHexTemplate (InstId_t inst_id);

public:
static uint32_t GetDataLength (InstId_t inst_id);

public:
  InstId_t DecodeInst (InstWord_t inst);
private:
  InstId_t DecodeInst_LD_11 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_11000 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_00000 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_01000 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_00100 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_00100_F3_101 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_01100 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_01100_R3_00000 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_01100_R3_00000_F2_00 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_01100_R3_00000_F2_01 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_01100_R3_01000 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_01100_R3_01000_F2_00 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_00011 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_00011_R1_00000 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_01011 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_01011_R3_00010 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_01011_R3_00010_R2_00000 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_01011_R3_00011 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_01011_R3_00001 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_01011_R3_00000 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_01011_R3_00100 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_01011_R3_01100 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_01011_R3_01000 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_01011_R3_10000 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_01011_R3_10100 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_01011_R3_11000 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_01011_R3_11100 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_00001 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_01001 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_10000 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_10001 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_10010 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_10011 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_10100 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_10100_R3_00000 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_10100_R3_00001 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_10100_R3_00010 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_10100_R3_00011 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_10100_R3_01011 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_10100_R3_00100 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_10100_R3_00100_F2_00 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_10100_R3_00100_F2_01 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_10100_R3_00101 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_10100_R3_00101_F2_00 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_10100_R3_00101_F2_01 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_10100_R3_11000 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_10100_R3_11000_F2_00 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_10100_R3_11000_F2_01 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_10100_R3_11100 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_10100_R3_11100_F2_00 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_10100_R3_11100_F2_00_R2_00000 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_10100_R3_11100_F2_01 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_10100_R3_11100_F2_01_R2_00000 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_10100_R3_10100 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_10100_R3_10100_F2_00 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_10100_R3_10100_F2_01 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_10100_R3_11010 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_10100_R3_11010_F2_00 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_10100_R3_11010_F2_01 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_10100_R3_11110 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_10100_R3_01000 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_11100 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_11100_F3_000 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_11100_F3_000_R3_00000 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_11100_F3_000_R3_00000_F2_00 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_11100_F3_000_R3_00010 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_11100_F3_000_R3_00010_F2_00 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_11100_F3_000_R3_00100 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_11100_F3_000_R3_00100_F2_00 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_11100_F3_000_R3_00110 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_11100_F3_000_R3_00110_F2_00 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_00110 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_00110_F3_101 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_01110 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_01110_R3_00000 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_01110_R3_00000_F2_00 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_01110_R3_00000_F2_01 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_01110_R3_01000 (InstWord_t inst);
  InstId_t DecodeInst_LD_11_OP_01110_R3_01000_F2_00 (InstWord_t inst);
  InstId_t DecodeInst_LD_00 (InstWord_t inst);
  InstId_t DecodeInst_LD_00_R3_00000 (InstWord_t inst);
  InstId_t DecodeInst_LD_00_R3_00000_F2_00 (InstWord_t inst);
  InstId_t DecodeInst_LD_00_R3_00000_F2_00_R2_00000 (InstWord_t inst);
  InstId_t DecodeInst_LD_00_R3_00000_F2_00_R2_00000_R1_00000 (InstWord_t inst);
  InstId_t DecodeInst_LD_00_R3_00000_F2_00_R2_00000_R1_00000_F3_110 (InstWord_t inst);
  InstId_t DecodeInst_LD_00_R3_00000_F2_00_R2_00000_R1_00000_F3_110_RD_00000 (InstWord_t inst);
  InstId_t DecodeInst_LD_00_R3_00000_F2_00_R2_00000_R1_00001 (InstWord_t inst);
  InstId_t DecodeInst_LD_00_R3_00000_F2_00_R2_00000_R1_00001_F3_110 (InstWord_t inst);
  InstId_t DecodeInst_LD_00_R3_00000_F2_00_R2_00000_R1_00001_F3_110_RD_00000 (InstWord_t inst);
  InstId_t DecodeInst_LD_01 (InstWord_t inst);
  InstId_t DecodeInst_LD_01_F3_000 (InstWord_t inst);
  InstId_t DecodeInst_LD_01_F3_000_RD_00000 (InstWord_t inst);
  InstId_t DecodeInst_LD_01_F3_000_RD_00000_OP_00000 (InstWord_t inst);
  InstId_t DecodeInst_LD_01_F3_000_RD_00000_OP_00000_R3_00000 (InstWord_t inst);
  InstId_t DecodeInst_LD_01_F3_000_RD_00000_OP_00000_R3_00000_F2_00 (InstWord_t inst);
  InstId_t DecodeInst_LD_01_F3_000_RD_00000_OP_00000_R3_00000_F2_00_R2_00000 (InstWord_t inst);
  InstId_t DecodeInst_LD_01_F3_000_RD_00001 (InstWord_t inst);
  InstId_t DecodeInst_LD_01_F3_000_RD_00001_R3_00000 (InstWord_t inst);
  InstId_t DecodeInst_LD_01_F3_000_RD_00001_R3_00000_F2_00 (InstWord_t inst);
  InstId_t DecodeInst_LD_01_F3_000_RD_00001_R3_00000_F2_00_R2_00000 (InstWord_t inst);
  InstId_t DecodeInst_LD_01_F3_000_RD_01000 (InstWord_t inst);
  InstId_t DecodeInst_LD_01_F3_000_RD_01000_R3_00000 (InstWord_t inst);
  InstId_t DecodeInst_LD_01_F3_000_RD_01000_R3_00000_F2_00 (InstWord_t inst);
  InstId_t DecodeInst_LD_01_F3_000_RD_01000_R3_00000_F2_00_R2_00000 (InstWord_t inst);
  InstId_t DecodeInst_LD_01_F3_000_RD_10000 (InstWord_t inst);
  InstId_t DecodeInst_LD_01_F3_000_RD_10000_R3_00000 (InstWord_t inst);
  InstId_t DecodeInst_LD_01_F3_000_RD_10000_R3_00000_F2_00 (InstWord_t inst);
  InstId_t DecodeInst_LD_01_F3_000_RD_10000_R3_00000_F2_00_R2_00000 (InstWord_t inst);
  InstId_t DecodeInst_LD_01_F3_000_RD_11000 (InstWord_t inst);
  InstId_t DecodeInst_LD_01_F3_000_RD_11000_R3_00000 (InstWord_t inst);
  InstId_t DecodeInst_LD_01_F3_000_RD_11000_R3_00000_F2_00 (InstWord_t inst);
  InstId_t DecodeInst_LD_01_F3_000_RD_11000_R3_00000_F2_00_R2_00000 (InstWord_t inst);
  InstId_t DecodeInst_LD_01_F3_000_RD_11000_R3_00000_F2_00_R2_00000_R1_00001 (InstWord_t inst);
  InstId_t DecodeInst_LD_01_F3_001 (InstWord_t inst);
  InstId_t DecodeInst_LD_01_F3_001_R3_00000 (InstWord_t inst);
  InstId_t DecodeInst_LD_01_F3_001_R3_00000_F2_00 (InstWord_t inst);
  InstId_t DecodeInst_LD_01_F3_001_R3_00000_F2_00_R2_00000 (InstWord_t inst);
  InstId_t DecodeInst_LD_01_F3_001_R3_00000_F2_00_R2_00000_R1_00001 (InstWord_t inst);
  InstId_t DecodeInst_LD_01_F3_001_R3_00000_F2_00_R2_00000_R1_00001_RD_11000 (InstWord_t inst);
  InstId_t DecodeInst_LD_01_F3_010 (InstWord_t inst);
  InstId_t DecodeInst_LD_01_F3_010_R3_00000 (InstWord_t inst);
  InstId_t DecodeInst_LD_01_F3_010_R3_00000_F2_00 (InstWord_t inst);
  InstId_t DecodeInst_LD_01_F3_010_R3_00000_F2_00_R2_00000 (InstWord_t inst);
  InstId_t DecodeInst_LD_01_F3_010_R3_00000_F2_00_R2_00000_R1_00000 (InstWord_t inst);
  InstId_t DecodeInst_LD_01_F3_010_R3_00000_F2_00_R2_00000_R1_00000_RD_00000 (InstWord_t inst);
  InstId_t DecodeInst_LD_01_F3_100 (InstWord_t inst);
  InstId_t DecodeInst_LD_01_F3_100_R3_00000 (InstWord_t inst);
  InstId_t DecodeInst_LD_01_F3_100_R3_00000_F2_00 (InstWord_t inst);
  InstId_t DecodeInst_LD_01_F3_100_R3_00000_F2_00_R2_00000 (InstWord_t inst);
  InstId_t DecodeInst_LD_01_F3_110 (InstWord_t inst);
  InstId_t DecodeInst_LD_01_F3_110_RD_00010 (InstWord_t inst);
  InstId_t DecodeInst_LD_01_F3_110_RD_00010_R3_00000 (InstWord_t inst);
  InstId_t DecodeInst_LD_01_F3_110_RD_00010_R3_00000_F2_00 (InstWord_t inst);
  InstId_t DecodeInst_LD_01_F3_110_RD_00010_R3_00000_F2_00_R2_00000 (InstWord_t inst);
  InstId_t DecodeInst_LD_01_F3_110_RD_00000 (InstWord_t inst);
  InstId_t DecodeInst_LD_01_F3_110_RD_00000_R3_00000 (InstWord_t inst);
  InstId_t DecodeInst_LD_01_F3_110_RD_00000_R3_00000_F2_00 (InstWord_t inst);
  InstId_t DecodeInst_LD_01_F3_110_RD_00000_R3_00000_F2_00_R2_00000 (InstWord_t inst);
  InstId_t DecodeInst_LD_10 (InstWord_t inst);
  InstId_t DecodeInst_LD_10_F3_000 (InstWord_t inst);
  InstId_t DecodeInst_LD_10_F3_000_OP_00000 (InstWord_t inst);
  InstId_t DecodeInst_LD_10_F3_000_OP_00000_R3_00000 (InstWord_t inst);
  InstId_t DecodeInst_LD_10_F3_000_OP_00000_R3_00000_F2_00 (InstWord_t inst);
  InstId_t DecodeInst_LD_10_F3_000_OP_00000_R3_00000_F2_00_R2_00000 (InstWord_t inst);
  InstId_t DecodeInst_LD_10_F3_000_OP_00001 (InstWord_t inst);
  InstId_t DecodeInst_LD_10_F3_000_OP_00001_R3_00000 (InstWord_t inst);
  InstId_t DecodeInst_LD_10_F3_000_OP_00001_R3_00000_F2_00 (InstWord_t inst);
  InstId_t DecodeInst_LD_10_F3_000_OP_00001_R3_00000_F2_00_R2_00000 (InstWord_t inst);
  InstId_t DecodeInst_LD_10_F3_001 (InstWord_t inst);
  InstId_t DecodeInst_LD_10_F3_001_OP_00000 (InstWord_t inst);
  InstId_t DecodeInst_LD_10_F3_001_OP_00000_RD_00001 (InstWord_t inst);
  InstId_t DecodeInst_LD_10_F3_001_OP_00000_RD_00001_R3_00000 (InstWord_t inst);
  InstId_t DecodeInst_LD_10_F3_001_OP_00000_RD_00001_R3_00000_F2_00 (InstWord_t inst);
  InstId_t DecodeInst_LD_10_F3_001_OP_00000_RD_00001_R3_00000_F2_00_R2_00000 (InstWord_t inst);
  InstId_t DecodeInst_LD_10_F3_001_OP_00001 (InstWord_t inst);
  InstId_t DecodeInst_LD_10_F3_001_OP_00001_R3_00000 (InstWord_t inst);
  InstId_t DecodeInst_LD_10_F3_001_OP_00001_R3_00000_F2_00 (InstWord_t inst);
  InstId_t DecodeInst_LD_10_F3_001_OP_00001_R3_00000_F2_00_R2_00000 (InstWord_t inst);
  InstId_t DecodeInst_LD_10_F3_010 (InstWord_t inst);
  InstId_t DecodeInst_LD_10_F3_010_R3_00000 (InstWord_t inst);
  InstId_t DecodeInst_LD_10_F3_010_R3_00000_F2_00 (InstWord_t inst);
  InstId_t DecodeInst_LD_10_F3_010_R3_00000_F2_00_R2_00000 (InstWord_t inst);
  InstId_t DecodeInst_LD_10_F3_100 (InstWord_t inst);
  InstId_t DecodeInst_LD_10_F3_100_R3_00000 (InstWord_t inst);
  InstId_t DecodeInst_LD_10_F3_100_R3_00000_F2_00 (InstWord_t inst);
  InstId_t DecodeInst_LD_10_F3_100_R3_00000_F2_00_R2_00000 (InstWord_t inst);
  InstId_t DecodeInst_LD_10_F3_110 (InstWord_t inst);
  InstId_t DecodeInst_LD_10_F3_110_R3_00000 (InstWord_t inst);
  InstId_t DecodeInst_LD_10_F3_110_R3_00000_F2_00 (InstWord_t inst);
  InstId_t DecodeInst_LD_10_F3_110_R3_00000_F2_00_R2_00000 (InstWord_t inst);
  InstId_t DecodeInst_LD_10_F3_110_R3_00000_F2_00_R2_00000_R1_00000 (InstWord_t inst);
  InstId_t DecodeInst_LD_10_F3_110_R3_00000_F2_00_R2_00000_R1_00000_RD_00001 (InstWord_t inst);
  InstId_t DecodeInst_LD_10_F3_110_R3_00000_F2_00_R2_00000_R1_00001 (InstWord_t inst);
  InstId_t DecodeInst_LD_10_F3_110_R3_00000_F2_00_R2_00000_R1_00001_RD_00000 (InstWord_t inst);
#include "extra_dec_utils_riscv.hpp"


};
