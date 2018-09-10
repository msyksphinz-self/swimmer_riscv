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

#include "./basic.hpp"

class InstOps {
private:
  static const HWord_t HALF_STD_SNAN   = 0x7C00;
  static const Word_t  FLOAT_STD_SNAN  = 0x7F800000;
  static const DWord_t DOUBLE_STD_SNAN = 0x7FF0000000000000;

  static const HWord_t HALF_STD_QNAN   = 0x7E00;
  static const Word_t  FLOAT_STD_QNAN  = 0x7FC00000;
  static const DWord_t DOUBLE_STD_QNAN = 0x7FF8000000000000;

  static const HWord_t HALF_INF   = 0x7C00;
  static const Word_t  FLOAT_INF  = 0x7F800000;
  static const DWord_t DOUBLE_INF = 0x7FF0000000000000;

 public:

  static const HWord_t HALF_SIGN_BIT   = 0x8000;
  static const Word_t  FLOAT_SIGN_BIT  = 0x80000000;
  static const DWord_t DOUBLE_SIGN_BIT = 0x8000000000000000;

  static const HWord_t HALF_EXP_BIT   = 0x7C00;
  static const Word_t  FLOAT_EXP_BIT  = 0x7F800000;
  static const DWord_t DOUBLE_EXP_BIT = 0x7FF0000000000000;

  static const HWord_t HALF_SIGNIFICAND_BIT   = 0x03FF;
  static const Word_t  FLOAT_SIGNIFICAND_BIT  = 0x007FFFFF;
  static const DWord_t DOUBLE_SIGNIFICAND_BIT = 0x000FFFFFFFFFFFFF;

  static Word_t  add32 (Word_t  op1, Word_t  op2, Word_t*  carry);
  static DWord_t add64 (DWord_t op1, DWord_t op2, DWord_t* carry);
  static Word_t  sub32 (Word_t  op1, Word_t  op2, Word_t*  carry);
  static DWord_t sub64 (DWord_t op1, DWord_t op2, DWord_t* carry);

  template <class T>
  static T IntAdd (T data1, T data2) {
    return data1 + data2;
  }
  template <class T>
  static T IntSub (T data1, T data2) {
    return data1 - data2;
  }

  template <class T>
  static T IntBitSwap (T data1) {
    T t = ((data1 >> 4) ^ data1) & 0x0f0f0f0f0f0f0f0f;
    t |= t << 4;   data1 ^= t;
    t |= t << 2;   data1 ^= t;
    t |= t << 1;
    data1 ^= t;
    return data1;
  }

  static UWord_t UIntDiv32 (UWord_t data1, UWord_t data2);
  static Word_t IntDiv32 (Word_t data1, Word_t data2);

  inline static UWord_t UIntRem32 (UWord_t data1, UWord_t data2) {
    if (data2 == 0          ) { return 0x80000000;    }
    if (data1 != 0xFFFFFFFFL && data2 == 0xFFFFFFFFL) { return data1;         }
    else                      { return data1 % data2; }
  }
  inline static Word_t IntRem32 (Word_t data1, Word_t data2) {
    if      (data2 ==  0) { return 0x80000000L;   }
    else if (data2 == -1) { return 0;             }
    else                  { return data1 % data2; }
  }

  static UDWord_t UIntDiv64 (UDWord_t data1, UDWord_t data2);
  static DWord_t IntDiv64 (DWord_t data1, DWord_t data2);

  inline static UDWord_t UIntRem64 (UDWord_t data1, UDWord_t data2) {
    if (data2 == 0                    ) { return 0x8000000000000000ULL; }
    if (data1 != 0xFFFFFFFFFFFFFFFFULL && data2 == 0xFFFFFFFFFFFFFFFFULL) { return data1; }
    else                                { return data1 % data2;         }
  }
  inline static DWord_t IntRem64 (DWord_t data1, DWord_t data2) {
    if      (data2 ==  0) { return 0x8000000000000000LL;  }
    else if (data2 == -1) { return 0;                     }
    else                  { return data1 % data2;         }
  }

  static HWord_t HalfAdd    (HWord_t op1, HWord_t op2, uint8_t round_mode, UWord_t *fflags);
  static Word_t  FloatAdd   (Word_t op1,  Word_t op2,  uint8_t round_mode, UWord_t *fflags);
  static DWord_t DoubleAdd  (DWord_t op1, DWord_t op2, uint8_t round_mode, UWord_t *fflags);

  static HWord_t HalfSub    (HWord_t op1, HWord_t op2, uint8_t round_mode, UWord_t *fflags);
  static Word_t  FloatSub   (Word_t op1,  Word_t op2,  uint8_t round_mode, UWord_t *fflags);
  static DWord_t DoubleSub  (DWord_t op1, DWord_t op2, uint8_t round_mode, UWord_t *fflags);
  static HWord_t HalfMul    (HWord_t op1, HWord_t op2, uint8_t round_mode, UWord_t *fflags);
  static Word_t  FloatMul   (Word_t op1,  Word_t op2,  uint8_t round_mode, UWord_t *fflags);
  static DWord_t DoubleMul  (DWord_t op1, DWord_t op2, uint8_t round_mode, UWord_t *fflags);
  static HWord_t HalfDiv    (HWord_t op1, HWord_t op2, uint8_t round_mode, UWord_t *fflags);
  static Word_t  FloatDiv   (Word_t op1,  Word_t op2,  uint8_t round_mode, UWord_t *fflags);
  static DWord_t DoubleDiv  (DWord_t op1, DWord_t op2, uint8_t round_mode, UWord_t *fflags);
  static Word_t  FloatRem   (Word_t op1,  Word_t op2,  uint8_t round_mode, UWord_t *fflags);
  static DWord_t DoubleRem  (DWord_t op1, DWord_t op2, uint8_t round_mode, UWord_t *fflags);

  static HWord_t HalfMadd   (HWord_t op1, HWord_t op2, HWord_t op3, UWord_t *fflags);
  static Word_t  FloatMadd  (Word_t op1,  Word_t op2,  Word_t  op3, UWord_t *fflags);
  static DWord_t DoubleMadd (DWord_t op1, DWord_t op2, DWord_t op3, UWord_t *fflags);

  static HWord_t HalfNMadd  (HWord_t op1, HWord_t op2, HWord_t op3, UWord_t *fflags);
  static Word_t  FloatNMadd (Word_t op1,  Word_t op2,  Word_t  op3, UWord_t *fflags);
  static DWord_t DoubleNMadd(DWord_t op1, DWord_t op2, DWord_t op3, UWord_t *fflags);

  static HWord_t HalfMsub   (HWord_t op1, HWord_t op2, HWord_t op3, UWord_t *fflags);
  static Word_t  FloatMsub  (Word_t op1,  Word_t op2,  Word_t  op3, UWord_t *fflags);
  static DWord_t DoubleMsub (DWord_t op1, DWord_t op2, DWord_t op3, UWord_t *fflags);

  static HWord_t HalfNMsub  (HWord_t op1, HWord_t op2, HWord_t op3, UWord_t *fflags);
  static Word_t  FloatNMsub (Word_t op1,  Word_t op2,  Word_t  op3, UWord_t *fflags);
  static DWord_t DoubleNMsub(DWord_t op1, DWord_t op2, DWord_t op3, UWord_t *fflags);

  static HWord_t HalfSqrt   (HWord_t op1, uint8_t round_mode, UWord_t *fflags);
  static Word_t  FloatSqrt  (Word_t  op1, uint8_t round_mode, UWord_t *fflags);
  static DWord_t DoubleSqrt (DWord_t op1, uint8_t round_mode, UWord_t *fflags);

  static HWord_t HalfRsqrt   (HWord_t op1, uint8_t round_mode, UWord_t *fflags);
  static Word_t  FloatRsqrt  (Word_t  op1, uint8_t round_mode, UWord_t *fflags);
  static DWord_t DoubleRsqrt (DWord_t op1, uint8_t round_mode, UWord_t *fflags);

  static Word_t  FloatRsqrtFast  (Word_t  op1, uint8_t round_mode, UWord_t *fflags);
  static DWord_t DoubleRsqrtFast (DWord_t op1, uint8_t round_mode, UWord_t *fflags);

  static HWord_t HalfNeg   (HWord_t op1);
  static Word_t  FloatNeg  (Word_t  op1);
  static DWord_t DoubleNeg (DWord_t op1);

  static HWord_t HalfAbs   (HWord_t  op1);
  static Word_t  FloatAbs  (Word_t  op1);
  static DWord_t DoubleAbs (DWord_t op1);

  static HWord_t HalfMax   (HWord_t op1, HWord_t op2, UWord_t *fflags);
  static Word_t  FloatMax  (Word_t  op1, Word_t  op2, UWord_t *fflags);
  static DWord_t DoubleMax (DWord_t op1, DWord_t op2, UWord_t *fflags);

  static HWord_t HalfMin   (HWord_t op1, HWord_t op2, UWord_t *fflags);
  static Word_t  FloatMin  (Word_t  op1, Word_t  op2, UWord_t *fflags);
  static DWord_t DoubleMin (DWord_t op1, DWord_t op2, UWord_t *fflags);

  static HWord_t HalfLt   (HWord_t op1, HWord_t op2, uint8_t round_mode, UWord_t *fflags);
  static Word_t  FloatLt  (Word_t  op1, Word_t  op2, uint8_t round_mode, UWord_t *fflags);
  static DWord_t DoubleLt (DWord_t op1, DWord_t op2, uint8_t round_mode, UWord_t *fflags);
  static DWord_t DoubleLtSub (DWord_t op1, DWord_t op2, uint8_t round_mode, UWord_t *fflags);

  static HWord_t HalfLe   (HWord_t op1, HWord_t op2, uint8_t round_mode, UWord_t *fflags);
  static Word_t  FloatLe  (Word_t  op1, Word_t  op2, uint8_t round_mode, UWord_t *fflags);
  static DWord_t DoubleLe (DWord_t op1, DWord_t op2, uint8_t round_mode, UWord_t *fflags);

  static HWord_t HalfGe   (HWord_t op1, HWord_t op2, uint8_t round_mode, UWord_t *fflags);
  static Word_t  FloatGe  (Word_t  op1, Word_t  op2, uint8_t round_mode, UWord_t *fflags);
  static DWord_t DoubleGe (DWord_t op1, DWord_t op2, uint8_t round_mode, UWord_t *fflags);

  static HWord_t HalfGt   (HWord_t op1, HWord_t op2, uint8_t round_mode, UWord_t *fflags);
  static Word_t  FloatGt  (Word_t  op1, Word_t  op2, uint8_t round_mode, UWord_t *fflags);
  static DWord_t DoubleGt (DWord_t op1, DWord_t op2, uint8_t round_mode, UWord_t *fflags);
  static DWord_t DoubleGtSub (DWord_t op1, DWord_t op2, uint8_t round_mode, UWord_t *fflags);

  static HWord_t HalfEq   (HWord_t op1, HWord_t op2, uint8_t round_mode, UWord_t *fflags);
  static Word_t  FloatEq  (Word_t  op1, Word_t  op2, uint8_t round_mode, UWord_t *fflags);
  static DWord_t DoubleEq (DWord_t op1, DWord_t op2, uint8_t round_mode, UWord_t *fflags);

  static HWord_t HalfNe   (HWord_t op1, HWord_t op2, uint8_t round_mode, UWord_t *fflags);
  static Word_t  FloatNe  (Word_t  op1, Word_t  op2, uint8_t round_mode, UWord_t *fflags);
  static DWord_t DoubleNe (DWord_t op1, DWord_t op2, uint8_t round_mode, UWord_t *fflags);

  static DWord_t Convert_StoD  (Word_t   op1, uint8_t round_mode, UWord_t *fflags);
  static DWord_t Convert_WtoD  (Word_t   op1, uint8_t round_mode, UWord_t *fflags);
  static DWord_t Convert_WUtoD (UWord_t  op1, uint8_t round_mode, UWord_t *fflags);
  static DWord_t Convert_LtoD  (DWord_t  op1, uint8_t round_mode, UWord_t *fflags);
  static DWord_t Convert_LUtoD (UDWord_t op1, uint8_t round_mode, UWord_t *fflags);

  static Word_t Convert_DtoS  (DWord_t  op1, uint8_t round_mode, UWord_t *fflags);
  static Word_t Convert_WtoS  (Word_t   op1, uint8_t round_mode, UWord_t *fflags);
  static Word_t Convert_WUtoS (UWord_t  op1, uint8_t round_mode, UWord_t *fflags);
  static Word_t Convert_LtoS  (DWord_t  op1, uint8_t round_mode, UWord_t *fflags);
  static Word_t Convert_LUtoS (UDWord_t op1, uint8_t round_mode, UWord_t *fflags);

  static Word_t  Convert_StoW (Word_t  op1, uint8_t round_mode, UWord_t *fflags);
  static Word_t  Convert_DtoW (DWord_t op1, uint8_t round_mode, UWord_t *fflags);

  static DWord_t Convert_StoL (Word_t  op1, uint8_t round_mode, UWord_t *fflags);
  static DWord_t Convert_DtoL (DWord_t op1, uint8_t round_mode, UWord_t *fflags);

  static UDWord_t Convert_StoLU (Word_t op1,  uint8_t round_mode, UWord_t *fflags);
  static UDWord_t Convert_DtoLU (DWord_t op1, uint8_t round_mode, UWord_t *fflags);

  static UWord_t Convert_StoWU (Word_t  op1, uint8_t round_mode, UWord_t *fflags);
  static UWord_t Convert_DtoWU (DWord_t op1, uint8_t round_mode, UWord_t *fflags);

  static Word_t  Convert_HtoS (HWord_t op1);
  static HWord_t Convert_StoH (Word_t op1,  uint8_t round_mode, UWord_t *fflags);

  static UWord_t Round_FtoW (Word_t op1, uint8_t round_mode, UWord_t *fflags);
  static DWord_t Round_DtoL (DWord_t op1, uint8_t round_mode, UWord_t *fflags);

  static Word_t  FloatMod  (Word_t op1,  uint8_t round_mode, UWord_t *fflags);
  static DWord_t DoubleMod (DWord_t op1, uint8_t round_mode, UWord_t *fflags);

  static UHWord_t HalfLinAprox   (UHWord_t op1, Word_t magic_val);
  static UWord_t  FloatLinAprox  (UWord_t  op1, Word_t magic_val);
  static UDWord_t DoubleLinAprox (UDWord_t op1, Word_t magic_val);

  inline static bool isHalfNaN (HWord_t op) {
    return ((op & HALF_EXP_BIT) == HALF_EXP_BIT) && (op & HALF_SIGNIFICAND_BIT);
  }

  inline static bool isFloatPlusNaN (Word_t op) {
    return ((op & FLOAT_EXP_BIT) == FLOAT_EXP_BIT) &&
           (op & FLOAT_SIGNIFICAND_BIT) &&
           !(op & FLOAT_SIGN_BIT); }

  inline static bool isFloatMinusNaN (Word_t op) {
    return ((op & FLOAT_EXP_BIT) == FLOAT_EXP_BIT) &&
           (op & FLOAT_SIGNIFICAND_BIT) &&
           (op & FLOAT_SIGN_BIT); }

  inline static bool isFloatNaN (Word_t op)
  {
    return isFloatPlusNaN(op) || isFloatMinusNaN(op);
  }

  inline static bool isDoublePlusNaN (DWord_t op) {
    return ((op & DOUBLE_EXP_BIT) == DOUBLE_EXP_BIT) &&
           (op & DOUBLE_SIGNIFICAND_BIT) &&
           !(op & DOUBLE_SIGN_BIT); }

  inline static bool isDoubleMinusNaN (DWord_t op) {
    return ((op & DOUBLE_EXP_BIT) == DOUBLE_EXP_BIT) &&
           (op & DOUBLE_SIGNIFICAND_BIT) &&
           (op & DOUBLE_SIGN_BIT); }

  inline static bool isDoubleNaN (DWord_t op)
  {
    return isDoublePlusNaN(op) || isDoubleMinusNaN(op);
  }

  inline static bool isHalfPlusInf (HWord_t op)
  {
    return (((op & 0xfc00) == 0x7c00) && !(op & 0x03ff));
  }

  inline static bool isHalfMinusInf (HWord_t op)
  {
    return (((op & 0xfc00) == 0xfc00) && !(op & 0x03ff));
  }

  inline static bool isHalfInf (HWord_t op)
  {
    return isHalfPlusInf (op) | isHalfMinusInf (op);
  }


  inline static bool isFloatPlusInf (Word_t op)
  {
    return (((op & 0xff800000) == 0x7f800000) &&
            !(op & 0x007fffff));
  }

  inline static bool isFloatMinusInf (Word_t op)
  {
    return (((op & 0xff800000) == 0xff800000) &&
            !(op & 0x007fffff));
  }

  inline static bool isFloatInf (Word_t op)
  {
    return isFloatPlusInf (op) | isFloatMinusInf (op);
  }

  inline static bool isDoublePlusInf (DWord_t op)
  {
    return (((op & UINT64_C( 0xfff0000000000000 )) == UINT64_C( 0x7ff0000000000000 )) &&
            !(op & UINT64_C( 0x000fffffffffffff )));
  }

  inline static bool isDoubleMinusInf (DWord_t op)
  {
    return (((op & UINT64_C( 0xfff0000000000000 )) == UINT64_C( 0xfff0000000000000 )) &&
            !(op & UINT64_C( 0x000fffffffffffff )));
  }

  inline static bool isDoubleInf (DWord_t op)
  {
    return isDoublePlusInf (op) | isDoubleMinusInf (op);
  }

  inline static bool isHalfMinusZero   (HWord_t  val) { return (val == INT16_MIN); }
  inline static bool isHalfPlusZero    (HWord_t  val) { return (val == 0); }
  inline static bool isHalfZero        (HWord_t  val) { return isHalfPlusZero(val) | isHalfMinusZero(val); }

  inline static bool isFloatMinusZero  (Word_t  val) { return (val == INT32_MIN); }
  inline static bool isFloatPlusZero   (Word_t  val) { return (val == 0); }
  inline static bool isFloatZero       (Word_t  val) { return isFloatPlusZero(val) | isFloatMinusZero(val); }

  inline static bool isDoubleMinusZero (DWord_t val) { return (val == INT64_MIN); }
  inline static bool isDoublePlusZero  (DWord_t val) { return (val == 0); }
  inline static bool isDoubleZero      (DWord_t val) { return isDoublePlusZero(val) | isDoubleMinusZero(val); }

  inline static bool isFloatMinus (Word_t val) {
    return (val & 0x80000000) != 0x0;
  }
  inline static bool isDoubleMinus (DWord_t val) {
    return (val & 0x8000000000000000ULL) != 0x0;
  }

  inline static bool isHalfSubnormal (HWord_t val) {
    return ((val & 0x7c00) == 0x0) & ((val & 0x03ff) != 0x0);

  }
  inline static bool isFloatSubnormal (Word_t val) {
    return ((val & 0x7f800000) == 0x0) & ((val & 0x00efffff) != 0x0);

  }
  inline static bool isDoubleSubnormal (DWord_t val) {
    return ((val & DOUBLE_EXP_BIT) == 0x0) && ((val & DOUBLE_SIGNIFICAND_BIT) != 0x0);
  }


  inline static HWord_t PreProcHalfCmp (HWord_t val) {
    if (isHalfSubnormal (val)) { val = (val & HALF_SIGN_BIT) | (HALF_SIGNIFICAND_BIT + 1); }
    if (isHalfNaN       (val)) { val = (val & HALF_SIGN_BIT) | HALF_INF;     }
    return val;
  }

  inline static HWord_t PreProcHalfOp (HWord_t val) {
    if (isHalfSubnormal (val)) { val = (val & HALF_SIGN_BIT); }
    return val;
  }

  inline static DWord_t PreProcDoubleOp (DWord_t val) {
    if (isDoubleSubnormal (val)) { val = (val & DOUBLE_SIGN_BIT); }
    return val;
  }

  inline static DWord_t PostProcDoubleOp (DWord_t val) {
    if (isDoubleSubnormal (val)) { val = (val & DOUBLE_SIGN_BIT); }
    if (isDoubleNaN       (val)) { val = DOUBLE_STD_QNAN | DOUBLE_SIGN_BIT; }
    return val;
  }


  inline static bool IsInexactFlag (uint32_t flags) {
    return flags & 0x01;
  }

  static Word_t  BitCount32 (Word_t op1);
  static DWord_t BitCount64 (DWord_t op1);

};
