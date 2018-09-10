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

#pragma once

#include <stdint.h>
#include <stddef.h>
#include <string>
#include "basic.hpp"

/*!
 * sign extension
 */
inline uint64_t ExtendSign (uint64_t data, uint32_t msb)
{
  uint64_t mask = 0x0UL;
  if (((data >> msb) & 0x01) == 0x01) {
    mask = 0x0FFFFFFFFFFFFFFFFULL & (~((1 << msb) - 1));
    return data | mask;
  } else {
    mask = (1 << msb) - 1;
    return data & mask;
  }
}


inline uint64_t ExtractBitField (uint64_t hex, uint32_t left, uint32_t right)
{
  uint64_t mask = (static_cast<uint64_t>(1) << (left - right + 1)) - 1;
  return (hex >> right) & mask;
}


inline UDWord_t SetBitField (uint64_t hex, uint64_t val, uint32_t left, uint32_t right)
{
  uint64_t mask = (static_cast<uint64_t>(1) << (left - right + 1)) - 1;
  return (hex & ~(mask << right)) | (val << right);
}


// inline uint64_t ExtendSign (uint64_t, uint32_t);
// inline uint64_t ExtractBitField (uint64_t, uint32_t, uint32_t);
// inline UDWord_t SetBitField (uint64_t hex, uint64_t val, uint32_t left, uint32_t right);

bool IsSameIncludeX (uint32_t field0, std::string field1, const int length);

/*!
 * RISC-V decoder bit field extraction
 */
#define ExtractR3Field(hex) (ExtractBitField(hex,31,27))
#define ExtractF2Field(hex) (ExtractBitField(hex,26,25))
#define ExtractR2Field(hex) (ExtractBitField(hex,24,20))
#define ExtractR1Field(hex) (ExtractBitField(hex,19,15))
#define ExtractF3Field(hex) (ExtractBitField(hex,14,12))
#define ExtractRDField(hex) (ExtractBitField(hex,11, 7))
#define ExtractOPField(hex) (ExtractBitField(hex, 6, 2))
#define ExtractLDField(hex) (ExtractBitField(hex, 1, 0))


/*!
 * RISC-V decoder bit field for RVC
 */
#define RS_ADDR_SP (2)
#define RS_ADDR_LR (1)
#define ExtractRDField_C(hex) (ExtractBitField(hex, 4, 2) + 8)
#define ExtractR1Field_C(hex) (ExtractBitField(hex, 9, 7) + 8)

Size_t GetWordSize(Size_t size);

/*!
 * === RISC-V Utilities
 */
DWord_t ExtractIField (uint32_t);
DWord_t ExtractSIField (uint32_t);
DWord_t ExtractSBField (uint32_t);
DWord_t ExtractUIField (uint32_t);
DWord_t ExtractUJField (uint32_t);
DWord_t ExtractSField  (uint32_t);

#define IsValueLtZero_32B(hex) ((hex >> 31) & 0x01)
#define IsValueEqZero_32B(hex) (hex == 0x0)
#define IsValueNeZero_32B(hex) (hex != 0x0)
#define IsValueLeZero_32B(hex) (IsValueLtZero_32B(hex) || IsValueEqZero_32B(hex))
#define IsValueGeZero_32B(hex) ((!(hex >> 31) & 0x01))
#define IsValueGtZero_32B(hex) (IsValueGeZero_32B(hex) && !IsValueEqZero_32B(hex))

bool IsNaNBoxed (DWord_t hex);
DWord_t ConvertNaNBoxing (DWord_t hex);

DWord_t SExtXlen (DWord_t hex);
UDWord_t UExtXlen (UDWord_t hex);

// #define BOXED_NAN_64 (0xffffffff7fc00000ULL)
#define BOXED_NAN_64 (0x07fc00000ULL)
