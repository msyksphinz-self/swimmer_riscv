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
#include <iostream>

using DWord_t  = int64_t;
using UDWord_t = uint64_t;
using Word_t   = int32_t;
using UWord_t  = uint32_t;
using HWord_t  = int16_t;
using UHWord_t = uint16_t;
using Byte_t   = int8_t;
using UByte_t  = uint8_t;
#ifdef  ARCH_RISCV
using Addr_t = uint64_t;
const int Addr_bitwidth = 64;
#else  // ARCH_RISCV
#ifdef  ARCH_MIPS64
using Addr_t = uint64_t;
const int Addr_bitwidth = 64;
#else  // ARCH_MIPS64
using Addr_t = uint64_t;
const int Addr_bitwidth = 32;
#endif // ARCH_MIPS64
#endif // ARCH_RISCV
using RegAddr_t = uint8_t;
using Size_t    = uint8_t;
using Cycle_t   = uint64_t;

using PeId_t = uint32_t;
using ThId_t = uint32_t;

using InstWord_t = uint32_t;

#define Size_Byte  (static_cast<Size_t>(0))
#define Size_HWord (static_cast<Size_t>(1))
#define Size_Word  (static_cast<Size_t>(2))
#define Size_DWord (static_cast<Size_t>(3))


class v2f_class {
 private:
  uint32_t m_f[2];
 public:
  v2f_class (DWord_t value) {
    m_f[0] = value & 0x0ffffffffUL;
    m_f[1] = (value >> 32) & 0x0ffffffffUL;
  }
  v2f_class () {}
  void SetElem(int idx, Word_t f) { m_f[idx] = f; }
  Word_t GetElem(int idx) { return m_f[idx]; }
  v2f_class& operator=(DWord_t value) {
    m_f[0] = value & 0x0ffffffffUL;
    m_f[1] = (value >> 32) & 0x0ffffffffUL;
    return *this;
  }
  operator DWord_t() {
    return (static_cast<DWord_t>(m_f[1]) << 32) | m_f[0];
  }
};
using V2f_t = v2f_class;

// V2D Data-Type
class v2d_class {
 private:
  UDWord_t m_f[2];
 public:
  void SetElem(int idx, UDWord_t f) { m_f[idx] = f; }
  UDWord_t GetElem(int idx) { return m_f[idx]; }
  inline void Set64(int idx, UDWord_t f) { m_f[idx] = f; }
  inline UDWord_t Get64(int idx) { return m_f[idx]; }
};
using V2d_t = v2d_class;


// V4F Data-Type
class v4f_class {
 private:
  UWord_t m_f[4];
 public:
  void SetElem(int idx, UWord_t f) { m_f[idx] = f; }
  UWord_t GetElem(int idx) { return m_f[idx]; }
  inline void Set64(int idx, UDWord_t f) {
    for (int i = 0; i < 2; i++) {
      m_f[idx*2+i] = (f >> (i * 32));
    }
  }
  inline UDWord_t Get64(int idx) {
    UDWord_t ret = 0;
    for (int i = 1; i >=0; i--) {
      ret = (ret << 32) | static_cast<UDWord_t>(m_f[idx*2+i]);
    }
    return ret;
  }
};
using V4f_t = v4f_class;


// V8H Data-Type
class v8h_class {
 private:
  UHWord_t m_f[8];
 public:
  void SetElem(int idx, HWord_t f) { m_f[idx] = f; }
  UHWord_t GetElem(int idx) { return m_f[idx]; }
  inline void Set64(int idx, DWord_t f) {
    for (int i = 0; i < 4; i++) {
      m_f[idx*4+i] = (f >> (i * 16)) & 0xffff;
    }
  }
  inline DWord_t Get64(int idx) {
    DWord_t ret = 0;
    for (int i = 3; i >=0; i--) {
      ret = (ret << 16) | static_cast<UDWord_t>(m_f[idx*4+i]);
    }
    return ret;
  }
};
using V8h_t = v8h_class;


// V4H Data-Type
class v4h_class {
 private:
  UHWord_t m_f[4];
 public:
  v4h_class () { };
  v4h_class (DWord_t value) {
    Set64 (value);
  }
  void SetElem(int idx, HWord_t f) { m_f[idx] = f; }
  UHWord_t GetElem(int idx) { return m_f[idx]; }
  v4h_class& operator=(DWord_t value) {
    Set64(value);
    return *this;
  }
  inline void Set64(DWord_t f) {
    for (int i = 0; i < 4; i++) {
      m_f[i] = (f >> (i * 16)) & 0xffff;
    }
  }
  inline DWord_t Get64() {
    DWord_t ret = 0;
    for (int i = 3; i >=0; i--) {
      ret = (ret << 16) | static_cast<UDWord_t>(m_f[i]);
    }
    return ret;
  }
  operator DWord_t() {
    return (static_cast<DWord_t>(m_f[3]) << 48) |
           (static_cast<DWord_t>(m_f[2]) << 32) |
           (static_cast<DWord_t>(m_f[1]) << 16) |
           (static_cast<DWord_t>(m_f[0]) <<  0);
  }
};
using V4h_t = v4h_class;

typedef union {
  float   f;
  UWord_t w;
} F_W_t;

typedef union {
  double   d;
  UDWord_t w;
} D_W_t;

#define HEAD(obj) (obj->head)
#define TAIL(obj) (obj->tail)
#define NEXT(obj) (obj->next)
