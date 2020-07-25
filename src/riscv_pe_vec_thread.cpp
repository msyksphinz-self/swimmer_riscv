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

#include <vector>
#include <sstream>
#include <cstring>
#include <memory>
#include <queue>
#include <math.h>

#include <bfd.h>
#include <dis-asm.h>

#include "softfloat.h"

#include "riscv_pe_thread.hpp"
#include "env.hpp"
#include "riscv_sysreg_impl.hpp"
#include "riscv_sysreg_bitdef.hpp"
#include "dec_utils_riscv.hpp"
#include "inst_riscv.hpp"
#include "riscv_page_table.hpp"
#include "riscv_devices.hpp"
#include "module_rom.hpp"
#include "module_ide.hpp"
#include "module_uart.hpp"
#include "module_crt.hpp"

class RiscvDeviceList_t;
class RiscvMMDevice_t;
class InstEnv;
class CsrEnv;
class RiscvPageTable;
class RiscvClint_t;

/*!
 * Read from Vector Register
 * \param reg register address to read
 */
template <class T>
T RiscvPeThread::ReadVReg (RegAddr_t reg_idx, uint32_t elem_idx)
{
  T value = *((reinterpret_cast<T*>(m_vregs.get())) + reg_idx * get_VLENB() + elem_idx);
  return value;
}


/*!
 * Write Data Vector Register
 * \param reg  register address to write
 * \param data write data
 * \param env  RISC-V environment
 */
template <class T>
void RiscvPeThread::WriteVReg (RegAddr_t reg_idx, uint32_t elem_idx, T data)
{
  *((reinterpret_cast<T*>(m_vregs.get())) + reg_idx * get_VLENB() + elem_idx) = data;
}


#define CHECK_MEM_EXCEPTION(cause, addr) \
    if (cause == MemResult::MemMisAlign) { \
      CSRWrite (static_cast<Addr_t>(SYSREG_ADDR_VSTART), i); \
      GenerateException (ExceptCode::Except_LoadAddrMisalign, addr); \
      return; \
    } \
    if (cause == MemResult::MemTlbError) { \
      CSRWrite (static_cast<Addr_t>(SYSREG_ADDR_VSTART), i); \
      GenerateException (ExceptCode::Except_LoadPageFault, addr); \
      return; \
    } \
    if (cause == MemResult::MemNotDefined) { \
      CSRWrite (static_cast<Addr_t>(SYSREG_ADDR_VSTART), i); \
      GenerateException (ExceptCode::Except_LoadAccessFault, addr); \
      return; \
    } \



template <class T>
void RiscvPeThread::MemLoadUnitStride(const Addr_t mem_base_addr, const RegAddr_t vd_addr,
                                      bool vm, T type) {
  const int DWIDTH = sizeof(T) * 8;
  Word_t vl;
  CSRRead (static_cast<Addr_t>(SYSREG_ADDR_VL), &vl);
  Word_t vstart; CSRRead (static_cast<Addr_t>(SYSREG_ADDR_VSTART), &vstart);
  for (int i = vstart; i < vl; i++) {
    // int elem_position_byte = i * sizeof(T) * 8;
    if (vm == 0) {
      const int midx = i / DWIDTH;
      const int mpos = i % DWIDTH;
      bool skip = ((ReadVReg<T>(0, midx) >> mpos) & 0x1) == 0;
      if (skip) {
        continue;
      }
    }

    Addr_t mem_addr = mem_base_addr + i * DWIDTH / 8;
    T  res;
    MemResult except = LoadFromBus (mem_addr, &res);
    CHECK_MEM_EXCEPTION(except, mem_addr);

    WriteVReg<T> (vd_addr, i, res);
  }
}


template <class T>
void RiscvPeThread::MemStoreUnitStride(const Addr_t mem_base_addr, const RegAddr_t vs3_addr,
                                       bool vm, T type) {
  const int DWIDTH = sizeof(T) * 8;
  Word_t vl; CSRRead (static_cast<Addr_t>(SYSREG_ADDR_VL), &vl);
  Word_t vstart; CSRRead (static_cast<Addr_t>(SYSREG_ADDR_VSTART), &vstart);
  for (int i = vstart; i < vl; i++) {
    if (vm == 0) {
      const int midx = i / DWIDTH;
      const int mpos = i % DWIDTH;
      bool skip = ((ReadVReg<T>(0, midx) >> mpos) & 0x1) == 0;
      if (skip) {
        continue;
      }
    }
    T store_data = ReadVReg<T> (vs3_addr, i);
    Addr_t mem_addr = mem_base_addr + i * DWIDTH / 8;

    MemResult except = StoreToBus (mem_addr, store_data);
    CHECK_MEM_EXCEPTION(except, mem_addr);

  }

}


template <class T>
void RiscvPeThread::MemLoadStrided(const Addr_t mem_base_addr, const DWord_t rs2_val,
                                   const RegAddr_t vd_addr,
                                   bool vm, T type) {
  const int DWIDTH = sizeof(T) * 8;
  Word_t vl; CSRRead (static_cast<Addr_t>(SYSREG_ADDR_VL), &vl);
  Word_t vstart; CSRRead (static_cast<Addr_t>(SYSREG_ADDR_VSTART), &vstart);
  for (int i = vstart; i < vl; i++) {
    if (vm == 0) {
      const int midx = i / DWIDTH;
      const int mpos = i % DWIDTH;
      bool skip = ((ReadVReg<T>(0, midx) >> mpos) & 0x1) == 0;
      if (skip) {
        continue;
      }
    }

    Addr_t mem_addr = mem_base_addr + (i * rs2_val);
    T  res;
    MemResult except = LoadFromBus (mem_addr, &res);
    CHECK_MEM_EXCEPTION(except, mem_addr);

    WriteVReg<T> (vd_addr, i, res);
  }
}


template <class T>
void RiscvPeThread::MemStoreStrided(const Addr_t mem_base_addr, const DWord_t rs2_val,
                                    const RegAddr_t vs3_addr,
                                    bool vm, T type) {
  const int DWIDTH = sizeof(T) * 8;
  Word_t vl;
  CSRRead (static_cast<Addr_t>(SYSREG_ADDR_VL), &vl);
  Word_t vstart; CSRRead (static_cast<Addr_t>(SYSREG_ADDR_VSTART), &vstart);
  for (int i = vstart; i < vl; i++) {
    if (vm == 0) {
      const int midx = i / DWIDTH;
      const int mpos = i % DWIDTH;
      bool skip = ((ReadVReg<T>(0, midx) >> mpos) & 0x1) == 0;
      if (skip) {
        continue;
      }
    }
    T store_data = ReadVReg<T> (vs3_addr, i);
    Addr_t mem_addr = mem_base_addr + (i * rs2_val);

    MemResult except = StoreToBus (mem_addr, store_data);
    CHECK_MEM_EXCEPTION(except, mem_addr);

  }

}


template <class T>
void RiscvPeThread::MemLoadIndexStrided(const Addr_t mem_base_addr,
                                        const RegAddr_t vs2_addr, const RegAddr_t vd_addr,
                                        bool vm, T type) {
  const int DWIDTH = sizeof(T) * 8;
  Word_t vl; CSRRead (static_cast<Addr_t>(SYSREG_ADDR_VL), &vl);
  Word_t vstart; CSRRead (static_cast<Addr_t>(SYSREG_ADDR_VSTART), &vstart);
  for (int i = vstart; i < vl; i++) {
    if (vm == 0) {
      const int midx = i / DWIDTH;
      const int mpos = i % DWIDTH;
      bool skip = ((ReadVReg<T>(0, midx) >> mpos) & 0x1) == 0;
      if (skip) {
        continue;
      }
    }

    T index = ReadVReg<T> (vs2_addr, i);
    Addr_t mem_addr = mem_base_addr + index;
    T  res;
    MemResult except = LoadFromBus (mem_addr, &res);
    CHECK_MEM_EXCEPTION(except, mem_addr);

    WriteVReg<T> (vd_addr, i, res);
  }
}


template <class T>
void RiscvPeThread::MemStoreIndexStrided(const Addr_t mem_base_addr,
                                         const RegAddr_t vs2_addr, const RegAddr_t vs3_addr,
                                         bool vm, T type) {
  const int DWIDTH = sizeof(T) * 8;
  Word_t vl;
  CSRRead (static_cast<Addr_t>(SYSREG_ADDR_VL), &vl);
  Word_t vstart; CSRRead (static_cast<Addr_t>(SYSREG_ADDR_VSTART), &vstart);
  for (int i = vstart; i < vl; i++) {
    if (vm == 0) {
      const int midx = i / DWIDTH;
      const int mpos = i % DWIDTH;
      bool skip = ((ReadVReg<T>(0, midx) >> mpos) & 0x1) == 0;
      if (skip) {
        continue;
      }
    }
    T store_data = ReadVReg<T> (vs3_addr, i);
    T index = ReadVReg<T> (vs2_addr, i);
    Addr_t mem_addr = mem_base_addr + index;

    MemResult except = StoreToBus (mem_addr, store_data);
    CHECK_MEM_EXCEPTION(except, mem_addr);

  }
}


// template <typename T, typename Func>
// void RiscvPeThread::VecExecInt2Op(bool vm,
//                                   RegAddr_t vs1_addr, RegAddr_t vs2_addr, RegAddr_t vd_addr,
//                                   Func func)
// {
//   const int DWIDTH = sizeof(T) * 8;
//   Word_t vl;
//   CSRRead (static_cast<Addr_t>(SYSREG_ADDR_VL), &vl);
//   Word_t vstart; CSRRead (static_cast<Addr_t>(SYSREG_ADDR_VSTART), &vstart);
//   for (int i = vstart; i < vl; i++) {
//     if (vm == 0) {
//       const int midx = i / DWIDTH;
//       const int mpos = i % DWIDTH;
//       bool skip = ((ReadVReg<T>(0, midx) >> mpos) & 0x1) == 0;
//       if (skip) {
//         continue;
//       }
//     }
//     T vs1_val = ReadVReg<T> (vs1_addr, i);
//     T vs2_val = ReadVReg<T> (vs2_addr, i);
//
//     // T res = func(vs1_val, vs2_val);
//     T res = vs1_val + vs2_val;
//
//     WriteVReg<T> (vd_addr, i, res);
//   }
// }


template Byte_t   RiscvPeThread::ReadVReg (RegAddr_t reg_idx, uint32_t elem_idx);
template UByte_t  RiscvPeThread::ReadVReg (RegAddr_t reg_idx, uint32_t elem_idx);
template HWord_t  RiscvPeThread::ReadVReg (RegAddr_t reg_idx, uint32_t elem_idx);
template UHWord_t RiscvPeThread::ReadVReg (RegAddr_t reg_idx, uint32_t elem_idx);
template Word_t   RiscvPeThread::ReadVReg (RegAddr_t reg_idx, uint32_t elem_idx);
template UWord_t  RiscvPeThread::ReadVReg (RegAddr_t reg_idx, uint32_t elem_idx);
template DWord_t  RiscvPeThread::ReadVReg (RegAddr_t reg_idx, uint32_t elem_idx);
template UDWord_t RiscvPeThread::ReadVReg (RegAddr_t reg_idx, uint32_t elem_idx);

template void RiscvPeThread::WriteVReg (RegAddr_t reg_idx, uint32_t elem_idx, Byte_t   data);
template void RiscvPeThread::WriteVReg (RegAddr_t reg_idx, uint32_t elem_idx, UByte_t  data);
template void RiscvPeThread::WriteVReg (RegAddr_t reg_idx, uint32_t elem_idx, HWord_t  data);
template void RiscvPeThread::WriteVReg (RegAddr_t reg_idx, uint32_t elem_idx, UHWord_t data);
template void RiscvPeThread::WriteVReg (RegAddr_t reg_idx, uint32_t elem_idx, Word_t   data);
template void RiscvPeThread::WriteVReg (RegAddr_t reg_idx, uint32_t elem_idx, UWord_t  data);
template void RiscvPeThread::WriteVReg (RegAddr_t reg_idx, uint32_t elem_idx, DWord_t  data);
template void RiscvPeThread::WriteVReg (RegAddr_t reg_idx, uint32_t elem_idx, UDWord_t data);

template void RiscvPeThread::MemLoadUnitStride(const Addr_t mem_base_addr, const RegAddr_t vd_addr, bool vm, Byte_t  type);
template void RiscvPeThread::MemLoadUnitStride(const Addr_t mem_base_addr, const RegAddr_t vd_addr, bool vm, HWord_t type);
template void RiscvPeThread::MemLoadUnitStride(const Addr_t mem_base_addr, const RegAddr_t vd_addr, bool vm, Word_t  type);
template void RiscvPeThread::MemLoadUnitStride(const Addr_t mem_base_addr, const RegAddr_t vd_addr, bool vm, DWord_t type);

template void RiscvPeThread::MemStoreUnitStride(const Addr_t mem_base_addr, const RegAddr_t vs3_addr, bool vm, Byte_t  type);
template void RiscvPeThread::MemStoreUnitStride(const Addr_t mem_base_addr, const RegAddr_t vs3_addr, bool vm, HWord_t type);
template void RiscvPeThread::MemStoreUnitStride(const Addr_t mem_base_addr, const RegAddr_t vs3_addr, bool vm, Word_t  type);
template void RiscvPeThread::MemStoreUnitStride(const Addr_t mem_base_addr, const RegAddr_t vs3_addr, bool vm, DWord_t type);

template void RiscvPeThread::MemLoadStrided(const Addr_t mem_base_addr, const DWord_t rs2_val, const RegAddr_t vd_addr, bool vm, Byte_t  type);
template void RiscvPeThread::MemLoadStrided(const Addr_t mem_base_addr, const DWord_t rs2_val, const RegAddr_t vd_addr, bool vm, HWord_t type);
template void RiscvPeThread::MemLoadStrided(const Addr_t mem_base_addr, const DWord_t rs2_val, const RegAddr_t vd_addr, bool vm, Word_t  type);
template void RiscvPeThread::MemLoadStrided(const Addr_t mem_base_addr, const DWord_t rs2_val, const RegAddr_t vd_addr, bool vm, DWord_t type);

template void RiscvPeThread::MemStoreStrided(const Addr_t mem_base_addr, const DWord_t rs2_val, const RegAddr_t vs3_addr, bool vm, Byte_t  type);
template void RiscvPeThread::MemStoreStrided(const Addr_t mem_base_addr, const DWord_t rs2_val, const RegAddr_t vs3_addr, bool vm, HWord_t type);
template void RiscvPeThread::MemStoreStrided(const Addr_t mem_base_addr, const DWord_t rs2_val, const RegAddr_t vs3_addr, bool vm, Word_t  type);
template void RiscvPeThread::MemStoreStrided(const Addr_t mem_base_addr, const DWord_t rs2_val, const RegAddr_t vs3_addr, bool vm, DWord_t type);

template void RiscvPeThread::MemLoadIndexStrided(const Addr_t mem_base_addr, const RegAddr_t vs2_addr, const RegAddr_t vd_addr, bool vm, Byte_t  type);
template void RiscvPeThread::MemLoadIndexStrided(const Addr_t mem_base_addr, const RegAddr_t vs2_addr, const RegAddr_t vd_addr, bool vm, HWord_t type);
template void RiscvPeThread::MemLoadIndexStrided(const Addr_t mem_base_addr, const RegAddr_t vs2_addr, const RegAddr_t vd_addr, bool vm, Word_t  type);
template void RiscvPeThread::MemLoadIndexStrided(const Addr_t mem_base_addr, const RegAddr_t vs2_addr, const RegAddr_t vd_addr, bool vm, DWord_t type);

template void RiscvPeThread::MemStoreIndexStrided(const Addr_t mem_base_addr, const RegAddr_t vs2_addr, const RegAddr_t vs3_addr, bool vm, Byte_t  type);
template void RiscvPeThread::MemStoreIndexStrided(const Addr_t mem_base_addr, const RegAddr_t vs2_addr, const RegAddr_t vs3_addr, bool vm, HWord_t type);
template void RiscvPeThread::MemStoreIndexStrided(const Addr_t mem_base_addr, const RegAddr_t vs2_addr, const RegAddr_t vs3_addr, bool vm, Word_t  type);
template void RiscvPeThread::MemStoreIndexStrided(const Addr_t mem_base_addr, const RegAddr_t vs2_addr, const RegAddr_t vs3_addr, bool vm, DWord_t type);

// template <typename Func>void RiscvPeThread::VecExecInt2Op<Byte_t> (bool vm, RegAddr_t vs1_addr, RegAddr_t vs2_addr, RegAddr_t vd_addr, Func func);
// template <typename Func>void RiscvPeThread::VecExecInt2Op<HWord_t>(bool vm, RegAddr_t vs1_addr, RegAddr_t vs2_addr, RegAddr_t vd_addr, Func func);
// template <typename Func>void RiscvPeThread::VecExecInt2Op<Word_t> (bool vm, RegAddr_t vs1_addr, RegAddr_t vs2_addr, RegAddr_t vd_addr, Func func);
// template <typename Func>void RiscvPeThread::VecExecInt2Op<DWord_t>(bool vm, RegAddr_t vs1_addr, RegAddr_t vs2_addr, RegAddr_t vd_addr, Func func);
