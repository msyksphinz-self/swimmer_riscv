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

#include <iostream>
#include <stdint.h>
#include "dec_utils_riscv.hpp"
#include "inst_ops.hpp"


Size_t GetWordSize(Size_t size) {
  switch (size) {
    case Size_Byte  : return 1;
    case Size_HWord : return 2;
    case Size_Word  : return 4;
    case Size_DWord : return 8;
    default         : return static_cast<Size_t>(-1);
  }
}


DWord_t ExtractIField (uint32_t hex)
{
  uint32_t uimm32 = ExtractBitField (hex, 31, 20);
  return ExtendSign (uimm32, 11);
}


DWord_t ExtractUIField (uint32_t hex)
{
  uint32_t u_imm16 = ExtractBitField (hex, 31, 20);
  return u_imm16;
}


DWord_t ExtractSIField (uint32_t hex)
{
  uint32_t u_imm16 = ExtractBitField (hex, 31, 20);
  return ExtendSign (u_imm16, 15);
}


DWord_t ExtractSBField (uint32_t hex)
{
  uint32_t i07_07 = ExtractBitField (hex,  7,  7) & 0x01UL;
  uint32_t i11_08 = ExtractBitField (hex, 11,  8) & 0x0fUL;
  uint32_t i30_25 = ExtractBitField (hex, 30, 25) & 0x03fUL;
  uint32_t i31_31 = ExtractBitField (hex, 31, 31) & 0x01UL;

  uint32_t u_res = (i31_31 << 12) |
           (i07_07 << 11) |
           (i30_25 <<  5) |
           (i11_08 <<  1);
  return ExtendSign (u_res, 12);
}


DWord_t ExtractUJField (uint32_t hex)
{
  uint32_t i24_21 = ExtractBitField (hex, 24, 21) & 0x0fUL;
  uint32_t i30_25 = ExtractBitField (hex, 30, 25) & 0x03fUL;
  uint32_t i20_20 = ExtractBitField (hex, 20, 20) & 0x01UL;
  uint32_t i19_12 = ExtractBitField (hex, 19, 12) & 0x0ffUL;
  uint32_t i31_31 = ExtractBitField (hex, 31, 31) & 0x01UL;

  uint32_t u_res = (i31_31 << 20) |
           (i19_12 << 12) |
           (i20_20 << 11) |
           (i30_25 <<  5) |
           (i24_21 <<  1);
  return ExtendSign (u_res, 20);
}


DWord_t ExtractSField (uint32_t hex)
{
  uint32_t i11_07 = ExtractBitField (hex, 11,  7) & 0x01fUL;
  uint32_t i31_25 = ExtractBitField (hex, 31, 25) & 0x07fUL;

  uint32_t u_res = (i31_25 << 5) |
           (i11_07 << 0);

  return ExtendSign (u_res, 11);
}


/*!
 * Check bitfield with X (X position is ignored)
 */
bool IsSameIncludeX (uint32_t field0, std::string field1, const int length)
{
  for (int i = 0; i < length; i++) {
    if (field1[length-i-1] == 'X') {
      continue;
    }
    uint32_t field0_val = (field0 >> i) & 0x01;
    uint32_t field1_val = field1[length-i-1]-'0';
    if (field0_val != field1_val) {
      return false;
    }
  }
  return true;
}


uint32_t htoi (uint8_t h)
{
  if (h >= '0' && h <= '9') {
    return h - '0';  // number
  } else if (h >= 'A' && h <= 'F') {
    return h - 'A' + 10; // 0xA - 0xF
  } else if (h >= 'a' && h <= 'f') {
    return h - 'a' + 10;
  } else {
    return -1;
  }
}


bool IsNaNBoxed (DWord_t hex)
{
  if (((hex >> 32) & UINT32_MAX) == UINT32_MAX) {
    return true;
  } else {
    return false;
  }
}


DWord_t ConvertNaNBoxing (DWord_t hex)
{
  if (((hex >> 32) & UINT32_MAX) == UINT32_MAX) {
    return hex;
  } else {
    return BOXED_NAN_64;
  }
}
