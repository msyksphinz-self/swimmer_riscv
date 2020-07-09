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
  T value = *((reinterpret_cast<T*>(m_vregs)) + reg_idx * get_VLENB() + elem_idx);
  // if (IsDebugTrace() == true) {
  //   GetTrace()->RecordTrace (TraceType::VRegRead, reg_idx, elem_idx, value);
  // }
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
  // if (IsDebugTrace() == true) {
  //   GetTrace()->RecordTrace (TraceType::VRegWrite, reg, data);
  // }
  *((reinterpret_cast<T*>(m_vregs)) + reg_idx * get_VLENB() + elem_idx) = data;
}


template Byte_t   RiscvPeThread::ReadVReg (RegAddr_t reg_idx, uint32_t elem_idx);
template HWord_t  RiscvPeThread::ReadVReg (RegAddr_t reg_idx, uint32_t elem_idx);
template Word_t   RiscvPeThread::ReadVReg (RegAddr_t reg_idx, uint32_t elem_idx);
template UWord_t  RiscvPeThread::ReadVReg (RegAddr_t reg_idx, uint32_t elem_idx);
template DWord_t  RiscvPeThread::ReadVReg (RegAddr_t reg_idx, uint32_t elem_idx);
template UDWord_t RiscvPeThread::ReadVReg (RegAddr_t reg_idx, uint32_t elem_idx);

template void RiscvPeThread::WriteVReg (RegAddr_t reg_idx, uint32_t elem_idx, Byte_t   data);
template void RiscvPeThread::WriteVReg (RegAddr_t reg_idx, uint32_t elem_idx, HWord_t  data);
template void RiscvPeThread::WriteVReg (RegAddr_t reg_idx, uint32_t elem_idx, Word_t   data);
template void RiscvPeThread::WriteVReg (RegAddr_t reg_idx, uint32_t elem_idx, UWord_t  data);
template void RiscvPeThread::WriteVReg (RegAddr_t reg_idx, uint32_t elem_idx, DWord_t  data);
template void RiscvPeThread::WriteVReg (RegAddr_t reg_idx, uint32_t elem_idx, UDWord_t data);
