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
#include <cfloat>
#include "basic.hpp"
#include "inst_ops.hpp"
#include "inst_sfloat.hpp"
#include "dec_utils_riscv.cpp"

#define LOWORD(dw) (0xFFFFUL & dw)
#define HIWORD(dw) (0xFFFFUL & (dw >> 16))


Word_t InstOps::add32 (Word_t op1, Word_t op2, Word_t* carry)
{
  if (op1 > 0 && op2 > (INT32_MAX - op1)) {
    /* handle overflow */
    *carry = 1;
  } else if (op1 < 0 && op2 < (INT32_MIN - op1)) {
    /* handle underflow */
    *carry = 1;
  }
  return op1 + op2;
}


DWord_t InstOps::add64 (DWord_t op1, DWord_t op2, DWord_t* carry)
{
  std::cerr << "add64::op1 = " << op1 << '\n';
  std::cerr << "add64::op2 = " << op2 << '\n';
  std::cerr << "add64::sub = " << (INT64_MIN - op1) << '\n';
  if (op1 > 0 && op2 > (INT64_MAX - op1)) {
    /* handle overflow */
    *carry = 1;
  } else if (op1 < 0 && op2 < (INT64_MIN - op1)) {
    /* handle underflow */
    *carry = 1;
  }
  return op1 + op2;
}


Word_t InstOps::sub32 (Word_t op1, Word_t op2, Word_t* carry)
{
  Word_t result = op1 - op2;
  if ((result < op1) != (op2 > 0)) {
    *carry = 1;
  }
  return result;
}


DWord_t InstOps::sub64 (DWord_t op1, DWord_t op2, DWord_t* carry)
{
  DWord_t result = op1 - op2;
  if ((result < op1) != (op2 > 0)) {
    *carry = 1;
  }
  return result;
}


Word_t InstOps::BitCount32 (Word_t op1)
{
  op1 = (op1 & 0x55555555) + (op1 >> 1 & 0x55555555);
  op1 = (op1 & 0x33333333) + (op1 >> 2 & 0x33333333);
  op1 = (op1 & 0x0f0f0f0f) + (op1 >> 4 & 0x0f0f0f0f);
  op1 = (op1 & 0x00ff00ff) + (op1 >> 8 & 0x00ff00ff);
  op1 = (op1 & 0x0000ffff) + (op1 >>16 & 0x0000ffff);
  return op1;
}


DWord_t InstOps::BitCount64 (DWord_t op1)
{
  op1 = (op1 & 0x5555555555555555ULL) + (op1 >> 1 & 0x5555555555555555ULL);
  op1 = (op1 & 0x3333333333333333ULL) + (op1 >> 2 & 0x3333333333333333ULL);
  op1 = (op1 & 0x0f0f0f0f0f0f0f0fULL) + (op1 >> 4 & 0x0f0f0f0f0f0f0f0fULL);
  op1 = (op1 & 0x00ff00ff00ff00ffULL) + (op1 >> 8 & 0x00ff00ff00ff00ffULL);
  op1 = (op1 & 0x0000ffff0000ffffULL) + (op1 >>16 & 0x0000ffff0000ffffULL);
  op1 = (op1 & 0x00000000ffffffffULL) + (op1 >>32 & 0x00000000ffffffffULL);
  return op1;
}


Word_t InstOps:: IntDiv32 (Word_t data1, Word_t data2)
{
  if      (data2 == 0x00000000ULL) { return 0xFFFFFFFFL; }
  else if (data2 == -1)            { return -data1;      }
  else              {
    std::div_t dv = std::div (data1, data2);
    return dv.quot;
  }
}

UWord_t InstOps::UIntDiv32 (UWord_t data1, UWord_t data2)
{
  if (data2 == 0x0) { return 0xFFFFFFFFL;   }
  else              { return data1 / data2; }
}


UDWord_t InstOps::UIntDiv64 (UDWord_t data1, UDWord_t data2)
{
  if (data2 == 0x0) { return UINT64_MAX;   }
  return data1 / data2;
}


DWord_t InstOps::IntDiv64 (DWord_t data1, DWord_t data2)
{
  std::lldiv_t dv = std::lldiv (data1, data2);
  return dv.quot;
}


HWord_t InstOps::HalfAdd (HWord_t op1, HWord_t op2, uint8_t round_mode, uint32_t *fflags)
{
  float16_t f_op1, f_op2;
  f_op1.v = op1;
  f_op2.v = op2;

  softfloat_exceptionFlags = 0;
  softfloat_roundingMode = round_mode;
  float16_t f_res = f16_add(f_op1, f_op2);

  HWord_t res = f_res.v;
  *fflags = softfloat_exceptionFlags;

  return res;
}


Word_t InstOps::FloatAdd (Word_t op1, Word_t op2, uint8_t round_mode, uint32_t *fflags)
{
  float32_t f_op1, f_op2;
  f_op1.v = op1;
  f_op2.v = op2;

  softfloat_exceptionFlags = 0;
  softfloat_roundingMode = round_mode;
  float32_t f_res = f32_add(f_op1, f_op2);

  Word_t  res   = f_res.v;
  *fflags = softfloat_exceptionFlags;

  return res;
}


DWord_t InstOps::DoubleAdd (DWord_t op1, DWord_t op2, uint8_t round_mode, uint32_t *fflags)
{
  float64_t f_op1, f_op2;
  f_op1.v = op1;
  f_op2.v = op2;

  softfloat_exceptionFlags = 0;
  softfloat_roundingMode = round_mode;
  float64_t f_res = f64_add(f_op1, f_op2);

  DWord_t   res   = f_res.v;
  *fflags = softfloat_exceptionFlags;

  return res;
}


HWord_t InstOps::HalfSub (HWord_t op1, HWord_t op2, uint8_t round_mode, uint32_t *fflags)
{
  float16_t f_op1, f_op2;
  f_op1.v = op1;
  f_op2.v = op2;

  softfloat_exceptionFlags = 0;
  softfloat_roundingMode = round_mode;
  float16_t f_res = f16_sub(f_op1, f_op2);

  HWord_t res = f_res.v;
  *fflags = softfloat_exceptionFlags;

  return res;
}


Word_t InstOps::FloatSub (Word_t op1, Word_t op2, uint8_t round_mode, uint32_t *fflags)
{
  float32_t f_op1, f_op2;
  f_op1.v = op1;
  f_op2.v = op2;

  softfloat_exceptionFlags = 0;
  softfloat_roundingMode = round_mode;
  float32_t f_res = f32_sub(f_op1, f_op2);

  Word_t  res   = f_res.v;
  *fflags = softfloat_exceptionFlags;

  return res;
}


DWord_t InstOps::DoubleSub (DWord_t op1, DWord_t op2, uint8_t round_mode, uint32_t *fflags)
{
  float64_t f_op1, f_op2;
  f_op1.v = op1;
  f_op2.v = op2;

  softfloat_exceptionFlags = 0;
  softfloat_roundingMode = round_mode;
  float64_t f_res = f64_sub(f_op1, f_op2);

  DWord_t  res   = f_res.v;
  *fflags = softfloat_exceptionFlags;

  return res;
}


HWord_t InstOps::HalfMul (HWord_t op1, HWord_t op2, uint8_t round_mode, uint32_t *fflags)
{
  float16_t f_op1, f_op2;
  f_op1.v = op1;
  f_op2.v = op2;

  softfloat_exceptionFlags = 0;
  softfloat_roundingMode = round_mode;
  float16_t f_res = f16_mul(f_op1, f_op2);

  HWord_t  res   = f_res.v;
  *fflags = softfloat_exceptionFlags;

  return res;
}


Word_t InstOps::FloatMul (Word_t op1, Word_t op2, uint8_t round_mode, uint32_t *fflags)
{
  float32_t f_op1, f_op2;
  f_op1.v = op1;
  f_op2.v = op2;

  softfloat_exceptionFlags = 0;
  softfloat_roundingMode = round_mode;
  float32_t f_res = f32_mul(f_op1, f_op2);

  Word_t  res   = f_res.v;
  *fflags = softfloat_exceptionFlags;

  return res;
}


DWord_t InstOps::DoubleMul (DWord_t op1, DWord_t op2, uint8_t round_mode, uint32_t *fflags)
{
  float64_t f_op1, f_op2;

  f_op1.v = op1;
  f_op2.v = op2;

  softfloat_exceptionFlags = 0;
  softfloat_roundingMode = round_mode;
  float64_t f_res = f64_mul(f_op1, f_op2);

  DWord_t res = f_res.v;

  *fflags = softfloat_exceptionFlags;
  return res;
}



HWord_t InstOps::HalfDiv (HWord_t op1, HWord_t op2, uint8_t round_mode, uint32_t *fflags)
{
  float16_t f_op1, f_op2;
  f_op1.v = op1;
  f_op2.v = op2;

  softfloat_exceptionFlags = 0;
  softfloat_roundingMode = round_mode;
  float16_t f_res = f16_div(f_op1, f_op2);

  HWord_t  res   = f_res.v;
  *fflags = softfloat_exceptionFlags;

  return res;
}


Word_t InstOps::FloatDiv (Word_t op1, Word_t op2, uint8_t round_mode, uint32_t *fflags)
{
  float32_t f_op1, f_op2;
  f_op1.v = op1;
  f_op2.v = op2;

  softfloat_exceptionFlags = 0;
  softfloat_roundingMode = round_mode;
  float32_t f_res = f32_div(f_op1, f_op2);

  Word_t  res   = f_res.v;
  *fflags = softfloat_exceptionFlags;

  return res;
}


DWord_t InstOps::DoubleDiv (DWord_t op1, DWord_t op2, uint8_t round_mode, uint32_t *fflags)
{
  float64_t f_op1, f_op2;
  f_op1.v = op1;
  f_op2.v = op2;

  softfloat_exceptionFlags = 0;
  softfloat_roundingMode = round_mode;
  float64_t f_res = f64_div(f_op1, f_op2);

  DWord_t  res   = f_res.v;
  *fflags = softfloat_exceptionFlags;

  return res;
}


Word_t InstOps::FloatRem (Word_t op1, Word_t op2, uint8_t round_mode, uint32_t *fflags)
{
  float32_t f_op1, f_op2;
  f_op1.v = op1;
  f_op2.v = op2;

  softfloat_exceptionFlags = 0;
  softfloat_roundingMode = round_mode;
  float32_t f_res = f32_rem(f_op1, f_op2);

  Word_t  res   = f_res.v;
  *fflags = softfloat_exceptionFlags;

  return res;
}


DWord_t InstOps::DoubleRem (DWord_t op1, DWord_t op2, uint8_t round_mode, uint32_t *fflags)
{
  float64_t f_op1, f_op2;
  f_op1.v = op1;
  f_op2.v = op2;

  softfloat_exceptionFlags = 0;
  softfloat_roundingMode = round_mode;
  float64_t f_res = f64_rem(f_op1, f_op2);

  DWord_t  res   = f_res.v;
  *fflags = softfloat_exceptionFlags;

  return res;
}


HWord_t InstOps::HalfMadd (HWord_t op1, HWord_t op2, HWord_t op3, uint32_t *fflags)
{
  float16_t f_op1, f_op2;
  f_op1.v = op1;
  f_op2.v = op2;

  softfloat_exceptionFlags = 0;
  softfloat_roundingMode = softfloat_round_near_even;
  float16_t f_res = f16_mul(f_op1, f_op2);
  HWord_t res = HalfAdd (f_res.v, op3, softfloat_roundingMode, fflags);

  return res;
}


Word_t InstOps::FloatMadd (Word_t op1, Word_t op2, Word_t op3, uint32_t *fflags)
{
  float32_t f_op1, f_op2, f_op3;
  f_op1.v = op1;
  f_op2.v = op2;
  f_op3.v = op3;

  if (isFloatNaN (op1) || isFloatNaN (op2) || isFloatNaN (op3)) {
    *fflags = softfloat_flag_invalid;
    return InstOps::FLOAT_STD_QNAN;
  }

  softfloat_exceptionFlags = 0;
  softfloat_roundingMode = softfloat_round_near_even;
  float32_t f_res = f32_add(f32_mul(f_op1, f_op2), f_op3);

  f_res.v = isFloatNaN(f_res.v) ? FLOAT_STD_QNAN : f_res.v;

  Word_t  res   = f_res.v;
  *fflags = softfloat_exceptionFlags;

  return res;
}


DWord_t InstOps::DoubleMadd (DWord_t op1, DWord_t op2, DWord_t op3, uint32_t *fflags)
{
  float64_t f_op1, f_op2, f_op3;
  f_op1.v = op1;
  f_op2.v = op2;
  f_op3.v = op3;

  softfloat_exceptionFlags = 0;
  softfloat_roundingMode = softfloat_round_near_even;

  float64_t f_res = f64_mulAdd(f_op1, f_op2, f_op3);

  DWord_t   res   = f_res.v;
  *fflags = softfloat_exceptionFlags;
  return res;
}


Word_t InstOps::FloatMsub (Word_t op1, Word_t op2, Word_t op3, uint32_t *fflags)
{
  softfloat_roundingMode = softfloat_round_near_even;
  Word_t res0 = FloatMul(op1,  op2, softfloat_roundingMode, fflags);
  Word_t res  = FloatSub(res0, op3, softfloat_roundingMode, fflags);
  return res;
}


HWord_t InstOps::HalfMsub (HWord_t op1, HWord_t op2, HWord_t op3, uint32_t *fflags)
{
  float16_t f_op1, f_op2, f_op3;
  f_op1.v = op1;
  f_op2.v = op2;
  f_op3.v = HalfNeg (op3);

  if (isHalfNaN (op1)) {
    *fflags = softfloat_flag_invalid;
    return op1 | 0x0200;
  }
  if (isHalfNaN (op2)) {
    *fflags = softfloat_flag_invalid;
    return op2 | 0x0200;
  }
  if (isHalfNaN (op3)) {
    *fflags = softfloat_flag_invalid;
    return op3 | 0x0200;
  }

  softfloat_exceptionFlags = 0;
  softfloat_roundingMode = softfloat_round_near_even;
  float16_t f_res = f16_add(f16_mul(f_op1, f_op2), f_op3);

  f_res.v = isHalfNaN(f_res.v) ? HALF_STD_QNAN : f_res.v;

  HWord_t  res = f_res.v;
  *fflags = softfloat_exceptionFlags;

  return res;
}


DWord_t InstOps::DoubleMsub (DWord_t op1, DWord_t op2, DWord_t op3, uint32_t *fflags)
{
  float64_t f_op1, f_op2;
  f_op1.v = op1;
  f_op2.v = op2;

  if (isDoubleNaN (op1)) {
    *fflags = softfloat_flag_invalid;
    return op1 | (~DOUBLE_EXP_BIT & (DOUBLE_EXP_BIT >> 1));
  }
  if (isDoubleNaN (op2)) {
    *fflags = softfloat_flag_invalid;
    return op2 | (~DOUBLE_EXP_BIT & (DOUBLE_EXP_BIT >> 1));
  }
  if (isDoubleNaN (op3)) {
    *fflags = softfloat_flag_invalid;
    return op3 | (~DOUBLE_EXP_BIT & (DOUBLE_EXP_BIT >> 1));
  }
  if (isDoubleSubnormal(op3)) {
    return 0x0;
  }

  softfloat_roundingMode = softfloat_round_near_even;
  float64_t f_res;

  softfloat_exceptionFlags = 0;
  f_res = f64_mul(f_op1, f_op2);
  f_res.v = isDoubleNaN(f_res.v) ? DOUBLE_STD_QNAN :
      ((softfloat_exceptionFlags & softfloat_flag_underflow) != 0) ? 0x00 :
      f_res.v;

  softfloat_exceptionFlags = 0;
  DWord_t res = DoubleSub(f_res.v, op3, softfloat_roundingMode, fflags);

  return res;
}


HWord_t InstOps::HalfSqrt (HWord_t op1, uint8_t round_mode, uint32_t *fflags)
{
  float16_t f_op1;
  f_op1.v = op1;

  softfloat_exceptionFlags = 0;
  softfloat_roundingMode = round_mode;
  float16_t f_res = f16_sqrt(f_op1);

  f_res.v = isFloatNaN(f_res.v) ? FLOAT_STD_QNAN : f_res.v;

  HWord_t  res   = f_res.v;
  *fflags = softfloat_exceptionFlags;

  return res;
}


Word_t InstOps::FloatSqrt (Word_t op1, uint8_t round_mode, uint32_t *fflags)
{
  float32_t f_op1;
  f_op1.v = op1;

  softfloat_exceptionFlags = 0;
  softfloat_roundingMode = round_mode;
  float32_t f_res = f32_sqrt(f_op1);

  f_res.v = isFloatNaN(f_res.v) ? FLOAT_STD_QNAN : f_res.v;

  Word_t  res   = f_res.v;
  *fflags = softfloat_exceptionFlags;

  return res;
}


DWord_t InstOps::DoubleSqrt (DWord_t op1, uint8_t round_mode, uint32_t *fflags)
{
  float64_t f_op1;
  f_op1.v = op1;

  softfloat_exceptionFlags = 0;
  softfloat_roundingMode = round_mode;
  float64_t f_res = f64_sqrt(f_op1);

  f_res.v = isDoubleNaN(f_res.v) ? DOUBLE_STD_QNAN : f_res.v;

  *fflags = softfloat_exceptionFlags;
  DWord_t  res   = f_res.v;

  return res;
}


HWord_t InstOps::HalfNeg (HWord_t op1)
{
  Word_t res = op1 ^ HALF_SIGN_BIT;
  return res;
}


Word_t InstOps::FloatNeg (Word_t op1)
{
  if (isFloatNaN (op1)) { return op1; }
  Word_t res = op1 ^ FLOAT_SIGN_BIT;
  return res;
}


DWord_t InstOps::DoubleNeg (DWord_t op1)
{
  DWord_t res = op1 ^ DOUBLE_SIGN_BIT;
  return res;
}


HWord_t InstOps::HalfAbs (HWord_t op1)
{
  // if (isHalfNaN (op1)) { return op1; }
  // if (isHalfInf (op1)) { return op1; }
  Word_t res = op1 & ~HALF_SIGN_BIT;
  return res;
}


Word_t InstOps::FloatAbs (Word_t op1)
{
  // if (isFloatNaN (op1)) { return op1; }
  // if (isFloatInf (op1)) { return op1; }
  Word_t res = op1 & ~FLOAT_SIGN_BIT;
  return res;
}


DWord_t InstOps::DoubleAbs (DWord_t op1)
{
  // if (isDoubleNaN (op1)) { return op1; }
  // if (isDoubleInf (op1)) { return op1; }
  DWord_t res = op1 & ~DOUBLE_SIGN_BIT;
  return res;
}


HWord_t InstOps::HalfMax (HWord_t op1, HWord_t op2, UWord_t *fflags)
{
  HWord_t res;
  res = HalfLt (op1, op2, 0, fflags) ? op2 : op1;
  return res;
}


Word_t InstOps::FloatMax (Word_t op1, Word_t op2, UWord_t *fflags)
{
  float32_t f_op1, f_op2;
  Word_t res;

  f_op1.v = op1;
  f_op2.v = op2;

  softfloat_exceptionFlags = 0;
  res = (isFloatNaN (op1) && isFloatNaN (op2)) ? FLOAT_STD_QNAN :
        (f32_lt_quiet (f_op2, f_op1) || isFloatNaN (op2) || (f32_eq(f_op1, f_op2) && (op2 & FLOAT_SIGN_BIT))) ? op1 :
        op2;
  *fflags = softfloat_exceptionFlags;

  return res;
}


DWord_t InstOps::DoubleMax (DWord_t op1, DWord_t op2, UWord_t *fflags)
{
  float64_t f_op1, f_op2;
  DWord_t res;
  f_op1.v = op1;
  f_op2.v = op2;

  softfloat_exceptionFlags = 0;
  res = (isDoubleNaN (op1) && isDoubleNaN (op2)) ? DOUBLE_STD_QNAN :
        (f64_lt_quiet (f_op2, f_op1) || isDoubleNaN(op2) || (f64_eq(f_op1, f_op2) && (op2 & DOUBLE_SIGN_BIT))) ? op1 :
        op2;
  *fflags = softfloat_exceptionFlags;
  return res;
}


HWord_t InstOps::HalfMin (HWord_t op1, HWord_t op2, UWord_t *fflags)
{
  HWord_t res;

  res = HalfLe (op1, op2, 0, fflags) ? op1 : op2;
  return res;
}


Word_t InstOps::FloatMin (Word_t op1, Word_t op2, UWord_t *fflags)
{
  float32_t f_op1, f_op2;
  Word_t res;

  f_op1.v = op1;
  f_op2.v = op2;

  softfloat_exceptionFlags = 0;
  res = (isFloatNaN (op1) && isFloatNaN (op2)) ? FLOAT_STD_QNAN :
        (f32_lt_quiet (f_op1, f_op2) || isFloatNaN (op2) || (f32_eq(f_op1, f_op2) && (op1 & FLOAT_SIGN_BIT))) ? op1 :
        op2;
  *fflags = softfloat_exceptionFlags;

  return res;
}


DWord_t InstOps::DoubleMin (DWord_t op1, DWord_t op2, UWord_t *fflags)
{
  float64_t f_op1, f_op2;
  DWord_t res;
  f_op1.v = op1;
  f_op2.v = op2;

  softfloat_exceptionFlags = 0;
  res = (isDoubleNaN (op1) && isDoubleNaN (op2)) ? DOUBLE_STD_QNAN :
        (f64_lt_quiet (f_op1, f_op2) || isDoubleNaN (op2) || (f64_eq(f_op1, f_op2) && (op1 & DOUBLE_SIGN_BIT))) ? op1 :
        op2;
  *fflags = softfloat_exceptionFlags;

  return res;
}


HWord_t InstOps::HalfLt (HWord_t op1, HWord_t op2, uint8_t round_mode, uint32_t *fflags)
{
  float16_t f_op1, f_op2;
  f_op1.v = PreProcHalfCmp (op1);
  f_op2.v = PreProcHalfCmp (op2);

  softfloat_exceptionFlags = 0;
  Word_t res = f16_le (f_op1, f_op2);
  *fflags = softfloat_exceptionFlags;

  return res;
}


Word_t  InstOps::FloatLt (Word_t  op1, Word_t  op2, uint8_t round_mode, uint32_t *fflags)
{
  float32_t f_op1, f_op2;
  f_op1.v = op1;
  f_op2.v = op2;

  softfloat_exceptionFlags = 0;
  Word_t res = f32_lt (f_op1, f_op2);
  *fflags = softfloat_exceptionFlags;

  return res;
}


DWord_t InstOps::DoubleLt (DWord_t op1, DWord_t op2, uint8_t round_mode, uint32_t *fflags)
{
  float64_t f_op1, f_op2;
  f_op1.v = op1;
  f_op2.v = op2;

  softfloat_exceptionFlags = 0;
  DWord_t res = f64_lt (f_op1, f_op2);
  *fflags = softfloat_exceptionFlags;

  return res;
}


HWord_t InstOps::HalfGt (HWord_t op1, HWord_t op2, uint8_t round_mode, uint32_t *fflags)
{
  float16_t f_op1, f_op2;
  f_op1.v = PreProcHalfCmp (op1);
  f_op2.v = PreProcHalfCmp (op2);

  softfloat_exceptionFlags = 0;
  Word_t res_lt = f16_lt (f_op1, f_op2);
  Word_t res_eq = f16_eq (f_op1, f_op2);
  *fflags = softfloat_exceptionFlags;

  return !(res_lt | res_eq);
}


Word_t  InstOps::FloatGt (Word_t  op1, Word_t  op2, uint8_t round_mode, uint32_t *fflags)
{
  float32_t f_op1, f_op2;
  f_op1.v = op1;
  f_op2.v = op2;

  softfloat_exceptionFlags = 0;
  Word_t res_lt = f32_lt (f_op1, f_op2);
  Word_t res_eq = f32_eq (f_op1, f_op2);
  *fflags = softfloat_exceptionFlags;

  return !(res_lt | res_eq);
}


DWord_t InstOps::DoubleGt (DWord_t op1, DWord_t op2, uint8_t round_mode, uint32_t *fflags)
{
  float64_t f_op1, f_op2;
  f_op1.v = op1;
  f_op2.v = op2;

  softfloat_exceptionFlags = 0;
  DWord_t res_lt = f64_lt (f_op1, f_op2);
  DWord_t res_eq = f64_eq (f_op1, f_op2);
  *fflags = softfloat_exceptionFlags;

  return !(res_lt | res_eq);
}


HWord_t InstOps::HalfGe (HWord_t op1, HWord_t op2, uint8_t round_mode, uint32_t *fflags)
{
  float16_t f_op1, f_op2;
  f_op1.v = PreProcHalfCmp (op1);
  f_op2.v = PreProcHalfCmp (op2);

  softfloat_exceptionFlags = 0;
  Word_t res_lt = f16_lt (f_op1, f_op2);
  *fflags = softfloat_exceptionFlags;

  return !res_lt;
}


Word_t  InstOps::FloatGe (Word_t  op1, Word_t  op2, uint8_t round_mode, uint32_t *fflags)
{
  float32_t f_op1, f_op2;
  f_op1.v = op1;
  f_op2.v = op2;

  softfloat_exceptionFlags = 0;
  Word_t res_lt = f32_lt (f_op1, f_op2);
  *fflags = softfloat_exceptionFlags;

  return !res_lt;
}


DWord_t InstOps::DoubleGe (DWord_t op1, DWord_t op2, uint8_t round_mode, uint32_t *fflags)
{
  float64_t f_op1, f_op2;
  f_op1.v = op1;
  f_op2.v = op2;

  softfloat_exceptionFlags = 0;
  DWord_t res_lt = f64_lt (f_op1, f_op2);
  *fflags = softfloat_exceptionFlags;

  return !res_lt;
}


HWord_t InstOps::HalfLe (HWord_t op1, HWord_t op2, uint8_t round_mode, uint32_t *fflags)
{
  float16_t f_op1, f_op2;
  f_op1.v = PreProcHalfCmp (op1);
  f_op2.v = PreProcHalfCmp (op2);

  softfloat_exceptionFlags = 0;
  Word_t res_lt = f16_lt (f_op1, f_op2);
  Word_t res_eq = f16_eq (f_op1, f_op2);
  *fflags = softfloat_exceptionFlags;

  return (res_lt | res_eq);
}


Word_t  InstOps::FloatLe (Word_t  op1, Word_t  op2, uint8_t round_mode, uint32_t *fflags)
{
  float32_t f_op1, f_op2;
  f_op1.v = op1;
  f_op2.v = op2;

  softfloat_exceptionFlags = 0;
  Word_t res_eq = f32_eq (f_op1, f_op2);
  Word_t res_lt = f32_lt (f_op1, f_op2);
  *fflags = softfloat_exceptionFlags;

  return (res_lt | res_eq);
}


DWord_t InstOps::DoubleLe (DWord_t op1, DWord_t op2, uint8_t round_mode, uint32_t *fflags)
{
  float64_t f_op1, f_op2;
  f_op1.v = op1;
  f_op2.v = op2;

  softfloat_exceptionFlags = 0;
  DWord_t res_eq = f64_eq (f_op1, f_op2);
  *fflags = softfloat_exceptionFlags;

  softfloat_exceptionFlags = 0;
  DWord_t res_lt = f64_lt (f_op1, f_op2);
  *fflags |= softfloat_exceptionFlags;

  return (res_lt | res_eq);
}


HWord_t InstOps::HalfEq (HWord_t op1, HWord_t op2, uint8_t round_mode, uint32_t *fflags)
{
  float16_t f_op1, f_op2;
  f_op1.v = PreProcHalfCmp (op1);
  f_op2.v = PreProcHalfCmp (op2);

  softfloat_exceptionFlags = 0;
  Word_t res = f16_eq (f_op1, f_op2);
  *fflags = softfloat_exceptionFlags;

  return res;
}


Word_t  InstOps::FloatEq (Word_t  op1, Word_t  op2, uint8_t round_mode, uint32_t *fflags)
{
  float32_t f_op1, f_op2;
  f_op1.v = op1;
  f_op2.v = op2;

  softfloat_exceptionFlags = 0;
  Word_t res = f32_eq (f_op1, f_op2);
  *fflags = softfloat_exceptionFlags;

  return res;
}


DWord_t InstOps::DoubleEq (DWord_t op1, DWord_t op2, uint8_t round_mode, uint32_t *fflags)
{
  float64_t f_op1, f_op2;
  f_op1.v = op1;
  f_op2.v = op2;

  softfloat_exceptionFlags = 0;
  DWord_t res = f64_eq (f_op1, f_op2);
  *fflags = softfloat_exceptionFlags;

  return res;
}


DWord_t InstOps::Convert_StoD (Word_t op1, uint8_t round_mode, UWord_t *fflags)
{
  float32_t f_op1;
  f_op1.v = op1;

  softfloat_roundingMode = round_mode;
  softfloat_exceptionFlags = 0;

  float64_t f_res = f32_to_f64(f_op1);
  DWord_t   res   = f_res.v;
  *fflags = softfloat_exceptionFlags;

  return res;
}


DWord_t InstOps::Convert_WtoD (Word_t op1, uint8_t round_mode, UWord_t *fflags)
{
  softfloat_exceptionFlags = 0;
  softfloat_roundingMode = round_mode;
  float64_t f_res = i32_to_f64 (op1);
  DWord_t   res   = f_res.v;
  *fflags = softfloat_exceptionFlags;

  return res;
}


DWord_t InstOps::Convert_WUtoD (UWord_t op1, uint8_t round_mode, UWord_t *fflags)
{
  softfloat_exceptionFlags = 0;
  softfloat_roundingMode = round_mode;
  float64_t f_res = ui32_to_f64 (op1);
  DWord_t   res   = f_res.v;
  *fflags = softfloat_exceptionFlags;

  return res;
}


DWord_t InstOps::Convert_LtoD (DWord_t op1, uint8_t round_mode, UWord_t *fflags)
{
  softfloat_exceptionFlags = 0;
  softfloat_roundingMode = round_mode;
  float64_t f_res = i64_to_f64(op1);
  DWord_t   res   = f_res.v;
  *fflags = softfloat_exceptionFlags;

  return res;
}


Word_t InstOps::Convert_DtoS (DWord_t op1, uint8_t round_mode, UWord_t *fflags)
{
  float64_t f_op1;
  f_op1.v = op1;

  softfloat_roundingMode = round_mode;
  softfloat_exceptionFlags = 0;

  float32_t f_res = f64_to_f32(f_op1);
  Word_t  res   = f_res.v;
  *fflags = softfloat_exceptionFlags;

  return res;
}


HWord_t InstOps::Convert_StoH (Word_t op1, uint8_t round_mode, UWord_t *fflags)
{
  float32_t f_op1;
  f_op1.v = op1;

  if (isFloatNaN (op1)) {
    *fflags = softfloat_flag_invalid;
    return InstOps::HALF_STD_QNAN | 0x8000U;
  }

  softfloat_exceptionFlags = 0;
  softfloat_roundingMode = round_mode;
  float16_t f_res = f32_to_f16(f_op1);
  HWord_t   res   = f_res.v;
  *fflags = softfloat_exceptionFlags;

  return res;
}


Word_t InstOps::Convert_WtoS (Word_t op1, uint8_t round_mode, UWord_t *fflags)
{
  softfloat_exceptionFlags = 0;
  softfloat_roundingMode = round_mode;
  float32_t f_res = i32_to_f32 (op1);
  Word_t  res   = f_res.v;
  *fflags = softfloat_exceptionFlags;

  return res;
}


Word_t InstOps::Convert_WUtoS (UWord_t op1, uint8_t round_mode, UWord_t *fflags)
{
  softfloat_exceptionFlags = 0;
  softfloat_roundingMode = round_mode;
  float32_t f_res = ui32_to_f32 (op1);
  Word_t  res   = f_res.v;
  *fflags = softfloat_exceptionFlags;

  return res;
}


Word_t InstOps::Convert_LtoS (DWord_t op1, uint8_t round_mode, UWord_t *fflags)
{
  softfloat_exceptionFlags = 0;
  float32_t f_res = i64_to_f32 (op1);
  Word_t  res   = f_res.v;
  *fflags = softfloat_exceptionFlags;

  return res;
}


Word_t  InstOps::Convert_StoW (Word_t  op1, uint8_t round_mode, UWord_t *fflags)
{
  float32_t f_op1;
  f_op1.v = op1;

  softfloat_exceptionFlags = 0;
  softfloat_roundingMode = round_mode;
  Word_t res = f32_to_i32(f_op1, round_mode, true);

  *fflags = softfloat_exceptionFlags;
  return res;
}


Word_t  InstOps::Convert_DtoW (DWord_t op1, uint8_t round_mode, UWord_t *fflags)
{
  float64_t f_op1;
  f_op1.v = op1;

  softfloat_exceptionFlags = 0;
  softfloat_roundingMode = round_mode;
  Word_t res = f64_to_i32(f_op1, round_mode, true);
  *fflags = softfloat_exceptionFlags;

  return res;
}


DWord_t InstOps::Convert_StoL (Word_t  op1, uint8_t round_mode, UWord_t *fflags)
{
  float32_t f_op1;
  f_op1.v = op1;

  softfloat_exceptionFlags = 0;
  DWord_t res = f32_to_i64 (f_op1, round_mode, true);
  *fflags = softfloat_exceptionFlags;
  return res;
}


DWord_t InstOps::Convert_DtoL (DWord_t op1, uint8_t round_mode, UWord_t *fflags)
{
  float64_t f_op1;
  f_op1.v = op1;

  softfloat_exceptionFlags = 0;
  DWord_t res = f64_to_i64 (f_op1, round_mode, true);
  *fflags = softfloat_exceptionFlags;
  return res;
}


UDWord_t InstOps::Convert_StoLU (Word_t op1, uint8_t round_mode, UWord_t *fflags)
{
  float32_t f_op1;
  f_op1.v = op1;

  if (isFloatNaN (op1)) {
    *fflags = softfloat_flag_invalid;
    return UINT64_MAX;
  }
  if (isFloatPlusInf (op1)) {
    softfloat_exceptionFlags = softfloat_flag_infinite;
    return UINT64_MAX;
  }
  if (isFloatMinusInf (op1)) {
    softfloat_exceptionFlags = softfloat_flag_infinite;
    return 0;
  }

  softfloat_exceptionFlags = 0;
  UDWord_t res = f32_to_ui64 (f_op1, round_mode, true);
  *fflags = softfloat_exceptionFlags;

  if ((softfloat_exceptionFlags & softfloat_flag_invalid) != 0) {
    res = 0;
  }

  return res;
}


Word_t InstOps::Convert_LUtoS (UDWord_t op1, uint8_t round_mode, UWord_t *fflags)
{
  softfloat_exceptionFlags = 0;
  softfloat_roundingMode = round_mode;
  float32_t f_res = ui64_to_f32 (op1);
  *fflags = softfloat_exceptionFlags;
  Word_t  res   = f_res.v;

  return res;
}


UDWord_t InstOps::Convert_DtoLU (DWord_t op1, uint8_t round_mode, UWord_t *fflags)
{
  float64_t f_op1;
  f_op1.v = op1;

  if (isDoubleNaN (op1)) {
    *fflags = softfloat_flag_invalid;
    return UINT64_MAX;
  }
  if (isDoublePlusInf (op1)) {
    softfloat_exceptionFlags = softfloat_flag_infinite;
    return UINT64_MAX;
  }
  if (isDoubleMinusInf (op1)) {
    softfloat_exceptionFlags = softfloat_flag_infinite;
    return 0;
  }

  softfloat_exceptionFlags = 0;
  softfloat_roundingMode = round_mode;
  UDWord_t res = f64_to_ui64 (f_op1, round_mode, true);
  *fflags = softfloat_exceptionFlags;

  if ((softfloat_exceptionFlags & softfloat_flag_invalid) != 0) {
    res = 0;
  }

  return res;
}


DWord_t InstOps::Convert_LUtoD (UDWord_t op1, uint8_t round_mode, UWord_t *fflags)
{
  softfloat_exceptionFlags = 0;
  softfloat_roundingMode = round_mode;
  float64_t f_res = ui64_to_f64(op1);
  *fflags = softfloat_exceptionFlags;
  DWord_t   res   = f_res.v;

  return res;
}


UWord_t  InstOps::Convert_StoWU (Word_t op1, uint8_t round_mode, UWord_t *fflags)
{
  float32_t f_op1;
  f_op1.v = op1;

  if (isFloatNaN (op1)) {
    *fflags = softfloat_flag_invalid;
    return UINT32_MAX;
  }
  if (isFloatPlusInf (op1)) {
    softfloat_exceptionFlags = softfloat_flag_infinite;
    return UINT32_MAX;
  }
  if (isFloatMinusInf (op1)) {
    softfloat_exceptionFlags = softfloat_flag_infinite;
    return 0;
  }

  softfloat_exceptionFlags = 0;
  UWord_t res = f32_to_ui32(f_op1, round_mode, true);
  *fflags = softfloat_exceptionFlags;

  if ((softfloat_exceptionFlags & softfloat_flag_invalid) != 0) {
    res = 0;
  }
  return res;
}


UWord_t  InstOps::Convert_DtoWU (DWord_t op1, uint8_t round_mode, UWord_t *fflags)
{
  float64_t f_op1;
  f_op1.v = op1;

  softfloat_exceptionFlags = 0;
  UWord_t res = f64_to_ui32(f_op1, round_mode, true);
  *fflags = softfloat_exceptionFlags;

  return res;
}

Word_t InstOps::Convert_HtoS (HWord_t op1)
{
  float16_t f_op1;
  f_op1.v = op1;

  if (isHalfNaN (op1)) {
    return InstOps::FLOAT_STD_QNAN | 0x80000000ULL;
  }

  softfloat_exceptionFlags = 0;
  float32_t f_res = f16_to_f32(f_op1);
  Word_t  res   = f_res.v;

  return res;
}


UWord_t InstOps::Round_FtoW (Word_t op1, uint8_t round_mode, UWord_t *fflags)
{
  float32_t f_op1;
  f_op1.v = op1;

  softfloat_exceptionFlags = 0;
  float32_t res = f32_roundToInt (f_op1, round_mode, true);
  *fflags = softfloat_exceptionFlags;

  if ((softfloat_exceptionFlags & softfloat_flag_invalid) != 0) {
    res.v = 0;
  }
  return res.v;
}


DWord_t InstOps::Round_DtoL (DWord_t op1, uint8_t round_mode, UWord_t *fflags)
{
  float64_t f_op1;
  f_op1.v = op1;

  softfloat_exceptionFlags = 0;
  float64_t res = f64_roundToInt (f_op1, round_mode, true);
  *fflags = softfloat_exceptionFlags;

  if ((softfloat_exceptionFlags & softfloat_flag_invalid) != 0) {
    res.v = 0;
  }
  return res.v;
}


Word_t InstOps::FloatMod (Word_t op1, uint8_t round_mode, UWord_t *fflags)
{
  if (isFloatNaN (op1)) {
    *fflags = softfloat_flag_invalid;
    return op1 | (~FLOAT_EXP_BIT & (FLOAT_EXP_BIT >> 1));
  }
  if (isFloatMinusZero(op1)) { return op1; }
  // if (isFloatSubnormal(op1)) { return 0x3f7fffff; }

  softfloat_exceptionFlags = 0;
  UWord_t res = Round_FtoW (op1, softfloat_round_minMag, fflags);
  res = InstOps::FloatSub (op1, res, softfloat_round_minMag, fflags);

  if ((softfloat_exceptionFlags & softfloat_flag_invalid) != 0) {
    res = 0;
  }
  return res;
}


DWord_t InstOps::DoubleMod (DWord_t op1, uint8_t round_mode, UWord_t *fflags)
{
  if (isDoubleNaN (op1)) {
    *fflags = softfloat_flag_invalid;
    return op1 | (~DOUBLE_EXP_BIT & (DOUBLE_EXP_BIT >> 1));
  }
  if (isDoubleMinusZero(op1)) {
    return op1;
  }

  softfloat_exceptionFlags = 0;

  DWord_t int_val = Round_DtoL (op1, softfloat_round_minMag, fflags);
  DWord_t res = InstOps::DoubleSub (op1, int_val, round_mode, fflags);

  if ((softfloat_exceptionFlags & softfloat_flag_invalid) != 0) {
    res = 0;
  }
  return res;
}


UHWord_t InstOps::HalfLinAprox  (UHWord_t op1, Word_t magic_val)
{
  Word_t  shift_f, res;

  if (ExtractBitField (magic_val, 24, 24)) {
    shift_f = (op1 >> 1);
  } else {
    shift_f = op1;
  }
  if (ExtractBitField (magic_val, 25, 25)) {
    res = ((magic_val & 0x00ffffff) >> 8) - shift_f;
  } else {
    res = ((magic_val & 0x00ffffff) >> 8) + shift_f;
  }
  return res;
}


UWord_t InstOps::FloatLinAprox (UWord_t op1, Word_t magic_val)
{
  Word_t  shift_f, res;

  if (ExtractBitField (magic_val, 24, 24)) {
    shift_f = (op1 >> 1) & 0xffffff00;
  } else {
    shift_f = op1 & 0xffffff00;
  }
  if (ExtractBitField (magic_val, 25, 25)) {
    res = ((magic_val & 0x00ffffff) << 8) - shift_f;
  } else {
    res = ((magic_val & 0x00ffffff) << 8) + shift_f;
  }
  return res;
}


UDWord_t InstOps::DoubleLinAprox (UDWord_t op1, Word_t magic_val)
{
  UDWord_t shift_f, res;

  if (ExtractBitField (magic_val, 24, 24)) {
    shift_f = (op1 >> 1) & 0xffffff0000000000ULL;
  } else {
    shift_f = op1 & 0xffffff0000000000ULL;
  }
  std::cerr << "shift_f = " << std::hex << shift_f << '\n';
  if (ExtractBitField (magic_val, 25, 25)) {
    res = (static_cast<UDWord_t>(magic_val & 0x00ffffff) << 40) - shift_f;
  } else {
    res = (static_cast<UDWord_t>(magic_val & 0x00ffffff) << 40) + shift_f;
  }
  return res;
}
