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
#include "dec_utils_riscv.hpp"


enum class operandType {
    operandTypeReg = 0, 
    operandTypeXReg = 1, 
    operandTypeFreg = 2, 
    operandTypeDreg = 3, 
    operandTypeVreg = 4, 
    operandTypeSign = 5, 
    operandTypeBit = 6, 
    operandTypeUnSign = 7, 
    operandTypeUnSignJ = 8, 
    operandTypeSignBit = 9, 
    operandTypeSelect8 = 10, 
    operandTypeXY = 11, 
    operandTypeCacheLevel = 12, 
    operandTypeSyncLevel = 13, 
    operandTypeHex = 14, 
    operandTypeRoundMode = 15, 
    operandTypeCompactReg = 16, 
    operandTypeCompactFReg = 17 };

#define MAX_OPERANDS 8

typedef struct {
  uint32_t size;
  operandType type_lst[MAX_OPERANDS];
  uint32_t msb_lst[MAX_OPERANDS];
  uint32_t lsb_lst[MAX_OPERANDS];
  bool     connect[MAX_OPERANDS];
} operandList;
void FormatOperand (void);

