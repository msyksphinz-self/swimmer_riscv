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


#include <stdint.h>
#include "riscv_pe_thread.hpp"
#include "riscv_sysreg_impl.hpp"

template <typename Xlen_t>
CsrAccResult CsrEnv::Read_USTATUS (Xlen_t *data, PrivMode mode)
{
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_UIE (Xlen_t *data, PrivMode mode)
{
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_UTVEC (Xlen_t *data, PrivMode mode)
{
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_VSTART (Xlen_t *data, PrivMode mode)
{
  *data = vstart.vstart;
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_VXSAT (Xlen_t *data, PrivMode mode)
{
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_VXRM (Xlen_t *data, PrivMode mode)
{
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_USCRATCH (Xlen_t *data, PrivMode mode)
{
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_UEPC (Xlen_t *data, PrivMode mode)
{
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_UCAUSE (Xlen_t *data, PrivMode mode)
{
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_UBADADDR (Xlen_t *data, PrivMode mode)
{
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_UIP (Xlen_t *data, PrivMode mode)
{
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_HPMCOUNTER3 (Xlen_t *data, PrivMode mode)
{
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_HPMCOUNTER4 (Xlen_t *data, PrivMode mode)
{
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_HPMCOUNTER5 (Xlen_t *data, PrivMode mode)
{
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_HPMCOUNTER6 (Xlen_t *data, PrivMode mode)
{
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_HPMCOUNTER7 (Xlen_t *data, PrivMode mode)
{
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_HPMCOUNTER8 (Xlen_t *data, PrivMode mode)
{
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_HPMCOUNTER9 (Xlen_t *data, PrivMode mode)
{
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_HPMCOUNTER10 (Xlen_t *data, PrivMode mode)
{
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_HPMCOUNTER11 (Xlen_t *data, PrivMode mode)
{
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_HPMCOUNTER12 (Xlen_t *data, PrivMode mode)
{
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_HPMCOUNTER13 (Xlen_t *data, PrivMode mode)
{
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_HPMCOUNTER14 (Xlen_t *data, PrivMode mode)
{
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_HPMCOUNTER15 (Xlen_t *data, PrivMode mode)
{
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_HPMCOUNTER16 (Xlen_t *data, PrivMode mode)
{
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_HPMCOUNTER17 (Xlen_t *data, PrivMode mode)
{
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_HPMCOUNTER18 (Xlen_t *data, PrivMode mode)
{
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_HPMCOUNTER19 (Xlen_t *data, PrivMode mode)
{
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_HPMCOUNTER20 (Xlen_t *data, PrivMode mode)
{
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_HPMCOUNTER21 (Xlen_t *data, PrivMode mode)
{
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_HPMCOUNTER22 (Xlen_t *data, PrivMode mode)
{
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_HPMCOUNTER23 (Xlen_t *data, PrivMode mode)
{
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_HPMCOUNTER24 (Xlen_t *data, PrivMode mode)
{
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_HPMCOUNTER25 (Xlen_t *data, PrivMode mode)
{
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_HPMCOUNTER26 (Xlen_t *data, PrivMode mode)
{
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_HPMCOUNTER27 (Xlen_t *data, PrivMode mode)
{
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_HPMCOUNTER28 (Xlen_t *data, PrivMode mode)
{
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_HPMCOUNTER29 (Xlen_t *data, PrivMode mode)
{
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_HPMCOUNTER30 (Xlen_t *data, PrivMode mode)
{
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_HPMCOUNTER31 (Xlen_t *data, PrivMode mode)
{
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_FFLAGS (Xlen_t *data, PrivMode mode)
{
  *data = fcsr.bit_fcsr.fflags;
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_FRM (Xlen_t *data, PrivMode mode)
{
  *data = fcsr.bit_fcsr.frm;
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_FCSR (Xlen_t *data, PrivMode mode)
{
  *data = fcsr.fcsr;
  return CsrAccResult::Normal;
}


/*
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_TIME (Xlen_t *data, PrivMode mode)
{
  *data = time.time;
  return CsrAccResult::Normal;
}
*/


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_INSTRET (Xlen_t *data, PrivMode mode)
{
  *data = instret.instret;
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_HPMCOUNTERH3 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_HPMCOUNTERH4 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_HPMCOUNTERH5 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_HPMCOUNTERH6 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_HPMCOUNTERH7 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_HPMCOUNTERH8 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_HPMCOUNTERH9 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_HPMCOUNTERH10 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_HPMCOUNTERH11 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_HPMCOUNTERH12 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_HPMCOUNTERH13 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_HPMCOUNTERH14 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_HPMCOUNTERH15 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_HPMCOUNTERH16 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_HPMCOUNTERH17 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_HPMCOUNTERH18 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_HPMCOUNTERH19 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_HPMCOUNTERH20 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_HPMCOUNTERH21 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_HPMCOUNTERH22 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_HPMCOUNTERH23 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_HPMCOUNTERH24 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_HPMCOUNTERH25 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_HPMCOUNTERH26 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_HPMCOUNTERH27 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_HPMCOUNTERH28 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_HPMCOUNTERH29 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_HPMCOUNTERH30 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_HPMCOUNTERH31 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_SSTATUS (Xlen_t *data, PrivMode mode)
{
#define SSTATUS_UIE         0x00000001
#define SSTATUS_SIE         0x00000002
#define SSTATUS_UPIE        0x00000010
#define SSTATUS_SPIE        0x00000020
#define SSTATUS_SPP         0x00000100
#define SSTATUS_FS          0x00006000
#define SSTATUS_XS          0x00018000
#define SSTATUS_SUM         0x00040000
#define SSTATUS_MXR         0x00080000
#define SSTATUS32_SD        0x80000000
#define SSTATUS_UXL         0x0000000300000000
#define SSTATUS64_SD        0x8000000000000000

  if (mode >= PrivMode::PrivSupervisor) {
    UDWord_t mask = SSTATUS_SIE | SSTATUS_SPIE | SSTATUS_SPP | SSTATUS_FS
        | SSTATUS_XS | SSTATUS_SUM | SSTATUS_UXL;
    *data = mstatus.mstatus & mask;
    if ((*data & SSTATUS_FS) == SSTATUS_FS ||
        (*data & SSTATUS_XS) == SSTATUS_XS)
      *data |= SSTATUS64_SD;
    return CsrAccResult::Normal;
  } else {
    m_pe_thread->DebugPrint ("<Error: SSTATUS is prohibited to read lower than Supervisor Mode %d>\n", m_pe_thread->GetPrivMode());
    return CsrAccResult::PrivError;
  }
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_STVEC (Xlen_t *data, PrivMode mode)
{
  if (mode >= PrivMode::PrivSupervisor) {
    *data = stvec.stvec;
    return CsrAccResult::Normal;
  } else {
    m_pe_thread->DebugPrint ("<Error: STVEC is prohibited to read lower than Supervisor Mode>\n");
    return CsrAccResult::PrivError;
  }
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_SCOUNTEREN (Xlen_t *data, PrivMode mode)
{
  if (mode >= PrivMode::PrivSupervisor) {
    *data = scounteren.scounteren;
    return CsrAccResult::Normal;
  } else {
    m_pe_thread->DebugPrint ("<Error: STVEC is prohibited to read lower than Supervisor Mode>\n");
    return CsrAccResult::PrivError;
  }
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_SIE (Xlen_t *data, PrivMode mode)
{
  if (mode >= PrivMode::PrivSupervisor) {
    *data = mie.mie & mideleg.mideleg;
    return CsrAccResult::Normal;
  } else {
    m_pe_thread->DebugPrint ("<Error: SIE is prohibited to read lower than Supervisor Mode>\n");
    return CsrAccResult::PrivError;
  }
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_SSCRATCH (Xlen_t *data, PrivMode mode)
{
  if (mode >= PrivMode::PrivSupervisor) {
    *data = sscratch.sscratch;
    return CsrAccResult::Normal;
  } else {
    m_pe_thread->DebugPrint ("<Error: SSCRATCH is prohibited to read lower than Supervisor Mode>\n");
    return CsrAccResult::PrivError;
  }
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_SEPC (Xlen_t *data, PrivMode mode)
{
  if (mode >= PrivMode::PrivSupervisor) {
    *data = sepc.sepc;
    return CsrAccResult::Normal;
  } else {
    m_pe_thread->DebugPrint ("<Error: SEPC is prohibited to read lower than Supervisor Mode>\n");
    return CsrAccResult::PrivError;
  }
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_SCAUSE (Xlen_t *data, PrivMode mode)
{
  if (mode >= PrivMode::PrivSupervisor) {
    *data = scause.scause;
    return CsrAccResult::Normal;
  } else {
    m_pe_thread->DebugPrint ("<Error: SCAUSE is prohibited to read lower than Supervisor Mode>\n");
    return CsrAccResult::PrivError;
  }
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_STVAL (Xlen_t *data, PrivMode mode)
{
  if (mode >= PrivMode::PrivSupervisor) {
    *data = stval.stval;
    return CsrAccResult::Normal;
  } else {
    m_pe_thread->DebugPrint ("<Error: SBADADDR is prohibited to read lower than Supervisor Mode>\n");
    return CsrAccResult::PrivError;
  }
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_SIP (Xlen_t *data, PrivMode mode)
{
  if (mode >= PrivMode::PrivSupervisor) {
    *data = mip.mip & mideleg.mideleg;
    return CsrAccResult::Normal;
  } else {
    m_pe_thread->DebugPrint ("<Error: SIP is prohibited to read lower than Supervisor Mode>\n");
    return CsrAccResult::PrivError;
  }
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_SATP (Xlen_t *data, PrivMode mode)
{
  // if (mode >= PrivMode::PrivSupervisor) {
  *data = satp.satp;
  return CsrAccResult::Normal;
  // } else {
  //   m_pe_thread->DebugPrint ("<Error: SPTBR is prohibited to read lower than Supervisor Mode>\n");
  //   return CsrAccResult::PrivError;
  // }
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_CYCLE (Xlen_t *data, PrivMode mode)
{
  if (mode >= PrivMode::PrivSupervisor) {
    *data = cycle.cycle;
    return CsrAccResult::Normal;
  } else {
    m_pe_thread->DebugPrint ("<Error: CYCLE is prohibited to read lower than Supervisor Mode>\n");
    return CsrAccResult::PrivError;
  }
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_CYCLEH (Xlen_t *data, PrivMode mode)
{
  if (mode >= PrivMode::PrivSupervisor) {
    *data = cycleh.cycleh;
    return CsrAccResult::Normal;
  } else {
    m_pe_thread->DebugPrint ("<Error: CYCLEH is prohibited to read lower than Supervisor Mode>\n");
    return CsrAccResult::PrivError;
  }
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_TIMEH (Xlen_t *data, PrivMode mode)
{
  if (mode >= PrivMode::PrivSupervisor) {
    *data = timeh.timeh;
    return CsrAccResult::Normal;
  } else {
    m_pe_thread->DebugPrint ("<Error: TIMEH is prohibited to read lower than Supervisor Mode>\n");
    return CsrAccResult::PrivError;
  }
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_INSTRETH (Xlen_t *data, PrivMode mode)
{
  if (mode >= PrivMode::PrivSupervisor) {
    *data = instreth.instreth;
    return CsrAccResult::Normal;
  } else {
    m_pe_thread->DebugPrint ("<Error: INSTRETH is prohibited to read lower than Supervisor Mode>\n");
    return CsrAccResult::PrivError;
  }
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_HSTATUS (Xlen_t *data, PrivMode mode)
{
  if (mode >= PrivMode::PrivHypervisor) {
    *data = hstatus.hstatus;
    return CsrAccResult::Normal;
  } else {
    m_pe_thread->DebugPrint ("<Error: HSTATUS is prohibited to read lower than Supervisor Mode>\n");
    return CsrAccResult::PrivError;
  }
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_HTVEC (Xlen_t *data, PrivMode mode)
{
  if (mode >= PrivMode::PrivHypervisor) {
    *data = htvec.htvec;
    return CsrAccResult::Normal;
  } else {
    m_pe_thread->DebugPrint ("<Error: HTVEC is prohibited to read lower than Supervisor Mode>\n");
    return CsrAccResult::PrivError;
  }
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_HSCRATCH (Xlen_t *data, PrivMode mode)
{
  if (mode >= PrivMode::PrivHypervisor) {
    *data = hscratch.hscratch;
    return CsrAccResult::Normal;
  } else {
    m_pe_thread->DebugPrint ("<Error: HSCRATCH is prohibited to read lower than Supervisor Mode>\n");
    return CsrAccResult::PrivError;
  }
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_HEPC (Xlen_t *data, PrivMode mode)
{
  if (mode >= PrivMode::PrivHypervisor) {
    *data = hepc.hepc;
    return CsrAccResult::Normal;
  } else {
    m_pe_thread->DebugPrint ("<Error: HEPC is prohibited to read lower than Supervisor Mode>\n");
    return CsrAccResult::PrivError;
  }
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_HCAUSE (Xlen_t *data, PrivMode mode)
{
  if (mode >= PrivMode::PrivHypervisor) {
    *data = hcause.hcause;
    return CsrAccResult::Normal;
  } else {
    m_pe_thread->DebugPrint ("<Error: HCAUSE is prohibited to read lower than Supervisor Mode>\n");
    return CsrAccResult::PrivError;
  }
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_HBADADDR (Xlen_t *data, PrivMode mode)
{
  if (mode >= PrivMode::PrivHypervisor) {
    *data = hbadaddr.hbadaddr;
    return CsrAccResult::Normal;
  } else {
    m_pe_thread->DebugPrint ("<Error: HBADADDR is prohibited to read lower than Supervisor Mode>\n");
    return CsrAccResult::PrivError;
  }
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MIMPID (Xlen_t *data, PrivMode mode)
{
  if (mode >= PrivMode::PrivMachine) {
    *data = mimpid.mimpid;
    return CsrAccResult::Normal;
  } else {
    m_pe_thread->DebugPrint ("<Error: MIMPID is prohibited to read lower than Supervisor Mode>\n");
    return CsrAccResult::PrivError;
  }
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MHARTID (Xlen_t *data, PrivMode mode)
{
  if (mode >= PrivMode::PrivMachine) {
    *data = mhartid.Hart_ID;
    return CsrAccResult::Normal;
  } else {
    m_pe_thread->DebugPrint ("<Error: MHARTID is prohibited to read lower than Supervisor Mode>\n");
    return CsrAccResult::PrivError;
  }
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MSTATUS (Xlen_t *data, PrivMode mode)
{
  if (mode >= PrivMode::PrivMachine) {
    *data = mstatus.mstatus;
    return CsrAccResult::Normal;
  } else {
    m_pe_thread->DebugPrint ("<Error: MSTATUS is prohibited to read lower than Supervisor Mode>\n");
    return CsrAccResult::PrivError;
  }
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MTVEC (Xlen_t *data, PrivMode mode)
{
  if (mode >= PrivMode::PrivMachine) {
    *data = mtvec.mtvec;
    return CsrAccResult::Normal;
  } else {
    m_pe_thread->DebugPrint ("<Error: MTVEC is prohibited to read lower than Supervisor Mode>\n");
    return CsrAccResult::PrivError;
  }
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MCOUNTEREN (Xlen_t *data, PrivMode mode)
{
  if (mode >= PrivMode::PrivMachine) {
    *data = mcounteren.mcounteren;
    return CsrAccResult::Normal;
  } else {
    m_pe_thread->DebugPrint ("<Error: MTVEC is prohibited to read lower than Supervisor Mode>\n");
    return CsrAccResult::PrivError;
  }
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MIE (Xlen_t *data, PrivMode mode)
{
  if (mode >= PrivMode::PrivMachine) {
    *data = mie.mie;
    return CsrAccResult::Normal;
  } else {
    m_pe_thread->DebugPrint ("<Error: MIE is prohibited to read lower than Supervisor Mode>\n");
    return CsrAccResult::PrivError;
  }
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MSCRATCH (Xlen_t *data, PrivMode mode)
{
  if (mode >= PrivMode::PrivMachine) {
    *data = mscratch.mscratch;
    return CsrAccResult::Normal;
  } else {
    m_pe_thread->DebugPrint ("<Error: MSCRATCH is prohibited to read lower than Supervisor Mode>\n");
    return CsrAccResult::PrivError;
  }
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MEPC (Xlen_t *data, PrivMode mode)
{
  if (mode >= PrivMode::PrivMachine) {
    *data = mepc.mepc;
    return CsrAccResult::Normal;
  } else {
    m_pe_thread->DebugPrint ("<Error: MEPC is prohibited to read lower than Supervisor Mode>\n");
    return CsrAccResult::PrivError;
  }
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MCAUSE (Xlen_t *data, PrivMode mode)
{
  if (mode >= PrivMode::PrivMachine) {
    *data = mcause.mcause;
    return CsrAccResult::Normal;
  } else {
    m_pe_thread->DebugPrint ("<Error: MCAUSE is prohibited to read lower than Supervisor Mode>\n");
    return CsrAccResult::PrivError;
  }
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MTVAL (Xlen_t *data, PrivMode mode)
{
  if (mode >= PrivMode::PrivMachine) {
    *data = mtval.mtval;
    return CsrAccResult::Normal;
  } else {
    m_pe_thread->DebugPrint ("<Error: MTVAL is prohibited to read lower than Supervisor Mode>\n");
    return CsrAccResult::PrivError;
  }
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MIP (Xlen_t *data, PrivMode mode)
{
  if (mode >= PrivMode::PrivMachine) {
    *data = mip.mip;
    return CsrAccResult::Normal;
  } else {
    m_pe_thread->DebugPrint ("<Error: MIP is prohibited to read lower than Supervisor Mode>\n");
    return CsrAccResult::PrivError;
  }
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MBASE (Xlen_t *data, PrivMode mode)
{
  if (mode >= PrivMode::PrivMachine) {
    *data = mbase.mbase;
    return CsrAccResult::Normal;
  } else {
    m_pe_thread->DebugPrint ("<Error: MBASE is prohibited to read lower than Supervisor Mode>\n");
    return CsrAccResult::PrivError;
  }
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MBOUND (Xlen_t *data, PrivMode mode)
{
  if (mode >= PrivMode::PrivMachine) {
    *data = mbound.mbound;
    return CsrAccResult::Normal;
  } else {
    m_pe_thread->DebugPrint ("<Error: MBOUND is prohibited to read lower than Supervisor Mode>\n");
    return CsrAccResult::PrivError;
  }
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MIBASE (Xlen_t *data, PrivMode mode)
{
  if (mode >= PrivMode::PrivMachine) {
    *data = mibase.mibase;
    return CsrAccResult::Normal;
  } else {
    m_pe_thread->DebugPrint ("<Error: MIBASE is prohibited to read lower than Supervisor Mode>\n");
    return CsrAccResult::PrivError;
  }
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MIBOUND (Xlen_t *data, PrivMode mode)
{
  if (mode >= PrivMode::PrivMachine) {
    *data = mibound.mibound;
    return CsrAccResult::Normal;
  } else {
    m_pe_thread->DebugPrint ("<Error: MIBOUND is prohibited to read lower than Supervisor Mode>\n");
    return CsrAccResult::PrivError;
  }
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MDBASE (Xlen_t *data, PrivMode mode)
{
  if (mode >= PrivMode::PrivMachine) {
    *data = mdbase.mdbase;
    return CsrAccResult::Normal;
  } else {
    m_pe_thread->DebugPrint ("<Error: MDBASE is prohibited to read lower than Supervisor Mode>\n");
    return CsrAccResult::PrivError;
  }
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MDBOUND (Xlen_t *data, PrivMode mode)
{
  if (mode >= PrivMode::PrivMachine) {
    *data = mdbound.mdbound;
    return CsrAccResult::Normal;
  } else {
    m_pe_thread->DebugPrint ("<Error: MDBOUND is prohibited to read lower than Supervisor Mode>\n");
    return CsrAccResult::PrivError;
  }
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MHPMCOUNTER3 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MHPMCOUNTER4 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MHPMCOUNTER5 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MHPMCOUNTER6 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MHPMCOUNTER7 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MHPMCOUNTER8 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MHPMCOUNTER9 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MHPMCOUNTER10 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MHPMCOUNTER11 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MHPMCOUNTER12 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MHPMCOUNTER13 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MHPMCOUNTER14 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MHPMCOUNTER15 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MHPMCOUNTER16 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MHPMCOUNTER17 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MHPMCOUNTER18 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MHPMCOUNTER19 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MHPMCOUNTER20 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MHPMCOUNTER21 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MHPMCOUNTER22 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MHPMCOUNTER23 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MHPMCOUNTER24 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MHPMCOUNTER25 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MHPMCOUNTER26 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MHPMCOUNTER27 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MHPMCOUNTER28 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MHPMCOUNTER29 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MHPMCOUNTER30 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MHPMCOUNTER31 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MHPEVENT3 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MHPEVENT4 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MHPEVENT5 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MHPEVENT6 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MHPEVENT7 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MHPEVENT8 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MHPEVENT9 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MHPEVENT10 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MHPEVENT11 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MHPEVENT12 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MHPEVENT13 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MHPEVENT14 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MHPEVENT15 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MHPEVENT16 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MHPEVENT17 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MHPEVENT18 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MHPEVENT19 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MHPEVENT20 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MHPEVENT21 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MHPEVENT22 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MHPEVENT23 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MHPEVENT24 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MHPEVENT25 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MHPEVENT26 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MHPEVENT27 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MHPEVENT28 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MHPEVENT29 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MHPEVENT30 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MHPEVENT31 (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }

template <typename Xlen_t>
CsrAccResult CsrEnv::Read_HIE (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_SEDELEG (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_HIP (Xlen_t *data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MISA (Xlen_t *data, PrivMode mode)
{
  if (mode >= PrivMode::PrivMachine) {
    *data = misa.misa;
    return CsrAccResult::Normal;
  } else {
    m_pe_thread->DebugPrint ("<Error: MISA is prohibited to read lower than Supervisor Mode>\n");
    return CsrAccResult::PrivError;
  }
  return CsrAccResult::Normal;
}
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MARCHID (Xlen_t *data, PrivMode mode) { *data = 0x0; return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MVENDORID (Xlen_t *data, PrivMode mode) { *data = 0x0; return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_HPTBR (Xlen_t *data, PrivMode mode) { *data = 0x0; return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_HIDELEG (Xlen_t *data, PrivMode mode) { *data = 0x0; return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MCYCLE (Xlen_t *data, PrivMode mode) { *data = 0x0; return CsrAccResult::Normal; }

template <typename Xlen_t>
CsrAccResult CsrEnv::Read_SIDELEG (Xlen_t *data, PrivMode mode)
{
  *data = sideleg.sideleg;
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MEDELEG (Xlen_t *data, PrivMode mode)
{
  *data = medeleg.medeleg;
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MIDELEG (Xlen_t *data, PrivMode mode)
{
  *data = mideleg.mideleg;
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_MINSTRET (Xlen_t *data, PrivMode mode)
{
  *data = minstret.minstret;
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_HEDELEG (Xlen_t *data, PrivMode mode)
{
  *data = hedeleg.hedeleg;
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_PMPCFG0   (Xlen_t *data, PrivMode mode) { *data = pmpcfg0  .pmpcfg0  ; return CsrAccResult::Normal; };
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_PMPCFG1   (Xlen_t *data, PrivMode mode) { *data = pmpcfg1  .pmpcfg1  ; return CsrAccResult::Normal; };
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_PMPCFG2   (Xlen_t *data, PrivMode mode) { *data = pmpcfg2  .pmpcfg2  ; return CsrAccResult::Normal; };
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_PMPCFG3   (Xlen_t *data, PrivMode mode) { *data = pmpcfg3  .pmpcfg3  ; return CsrAccResult::Normal; };
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_PMPADDR0  (Xlen_t *data, PrivMode mode) { *data = pmpaddr0 .pmpaddr0 ; return CsrAccResult::Normal; };
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_PMPADDR1  (Xlen_t *data, PrivMode mode) { *data = pmpaddr1 .pmpaddr1 ; return CsrAccResult::Normal; };
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_PMPADDR2  (Xlen_t *data, PrivMode mode) { *data = pmpaddr2 .pmpaddr2 ; return CsrAccResult::Normal; };
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_PMPADDR3  (Xlen_t *data, PrivMode mode) { *data = pmpaddr3 .pmpaddr3 ; return CsrAccResult::Normal; };
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_PMPADDR4  (Xlen_t *data, PrivMode mode) { *data = pmpaddr4 .pmpaddr4 ; return CsrAccResult::Normal; };
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_PMPADDR5  (Xlen_t *data, PrivMode mode) { *data = pmpaddr5 .pmpaddr5 ; return CsrAccResult::Normal; };
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_PMPADDR6  (Xlen_t *data, PrivMode mode) { *data = pmpaddr6 .pmpaddr6 ; return CsrAccResult::Normal; };
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_PMPADDR7  (Xlen_t *data, PrivMode mode) { *data = pmpaddr7 .pmpaddr7 ; return CsrAccResult::Normal; };
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_PMPADDR8  (Xlen_t *data, PrivMode mode) { *data = pmpaddr8 .pmpaddr8 ; return CsrAccResult::Normal; };
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_PMPADDR9  (Xlen_t *data, PrivMode mode) { *data = pmpaddr9 .pmpaddr9 ; return CsrAccResult::Normal; };
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_PMPADDR10 (Xlen_t *data, PrivMode mode) { *data = pmpaddr10.pmpaddr10; return CsrAccResult::Normal; };
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_PMPADDR11 (Xlen_t *data, PrivMode mode) { *data = pmpaddr11.pmpaddr11; return CsrAccResult::Normal; };
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_PMPADDR12 (Xlen_t *data, PrivMode mode) { *data = pmpaddr12.pmpaddr12; return CsrAccResult::Normal; };
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_PMPADDR13 (Xlen_t *data, PrivMode mode) { *data = pmpaddr13.pmpaddr13; return CsrAccResult::Normal; };
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_PMPADDR14 (Xlen_t *data, PrivMode mode) { *data = pmpaddr14.pmpaddr14; return CsrAccResult::Normal; };
template <typename Xlen_t>
CsrAccResult CsrEnv::Read_PMPADDR15 (Xlen_t *data, PrivMode mode) { *data = pmpaddr15.pmpaddr15; return CsrAccResult::Normal; };

template <typename Xlen_t>
CsrAccResult CsrEnv::Read_STATS (Xlen_t *data, PrivMode mode)
{
  *data = stats.stats;
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_UARCH00 (Xlen_t *data, PrivMode mode)
{
  *data = uarch00.uarch00;
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_UARCH01 (Xlen_t *data, PrivMode mode)
{
  *data = uarch01.uarch01;
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_UARCH02 (Xlen_t *data, PrivMode mode)
{
  *data = uarch02.uarch02;
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_UARCH03 (Xlen_t *data, PrivMode mode)
{
  *data = uarch03.uarch03;
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_UARCH04 (Xlen_t *data, PrivMode mode)
{
  *data = uarch04.uarch04;
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_UARCH05 (Xlen_t *data, PrivMode mode)
{
  *data = uarch05.uarch05;
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_UARCH06 (Xlen_t *data, PrivMode mode)
{
  *data = uarch06.uarch06;
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_UARCH07 (Xlen_t *data, PrivMode mode)
{
  *data = uarch07.uarch07;
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_UARCH08 (Xlen_t *data, PrivMode mode)
{
  *data = uarch08.uarch08;
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_UARCH09 (Xlen_t *data, PrivMode mode)
{
  *data = uarch09.uarch09;
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_UARCH10 (Xlen_t *data, PrivMode mode)
{
  *data = uarch10.uarch10;
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_UARCH11 (Xlen_t *data, PrivMode mode)
{
  *data = uarch11.uarch11;
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_UARCH12 (Xlen_t *data, PrivMode mode)
{
  *data = uarch12.uarch12;
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_UARCH13 (Xlen_t *data, PrivMode mode)
{
  *data = uarch13.uarch13;
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_UARCH14 (Xlen_t *data, PrivMode mode)
{
  *data = uarch14.uarch14;
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_UARCH15 (Xlen_t *data, PrivMode mode)
{
  *data = uarch15.uarch15;
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_TSELECT (Xlen_t *data, PrivMode mode)
{
  *data = tselect.tselect;
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_TDATA1 (Xlen_t *data, PrivMode mode)
{
  *data = tdata1.tdata1;
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_TDATA2 (Xlen_t *data, PrivMode mode)
{
  *data = tdata2.tdata2;
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_TDATA3 (Xlen_t *data, PrivMode mode)
{
  *data = tdata3.tdata3;
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_VL (Xlen_t *data, PrivMode mode)
{
  *data = vl.vl;
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_VTYPE (Xlen_t *data, PrivMode mode)
{
  *data = vtype.vtype;
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Read_VLENB (Xlen_t *data, PrivMode mode)
{
  *data = m_pe_thread->get_VLEN() / 8;
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_FFLAGS (Xlen_t data, PrivMode mode)
{
  // m_pe_thread->InfoPrint ("<Info: update Write_FFLAGS>\n");
  m_pe_thread->DirtyFS ();
  mstatus.bit_mstatus.SD  = 1;
  fcsr.bit_fcsr.fflags = ExtractBitField(data, 4, 0);
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_FRM (Xlen_t data, PrivMode mode)
{
  // m_pe_thread->InfoPrint ("<Info: update Write_FRM>\n");
  m_pe_thread->DirtyFS ();
  mstatus.bit_mstatus.SD  = 1;
  fcsr.bit_fcsr.frm = ExtractBitField(data, 2, 0);
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_FCSR (Xlen_t data, PrivMode mode)
{
  // m_pe_thread->InfoPrint ("<Info: update Write_FCSR>\n");
  m_pe_thread->DirtyFS ();
  mstatus.bit_mstatus.SD  = 1;
  fcsr.bit_fcsr.fflags = ExtractBitField (data, 4, 0);
  fcsr.bit_fcsr.frm  = ExtractBitField (data, 7, 5);
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_VSTART (Xlen_t data, PrivMode mode)
{
  vstart.vstart = data;
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_VXSAT (Xlen_t data, PrivMode mode)
{
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_VXRM (Xlen_t data, PrivMode mode)
{
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_CYCLE (Xlen_t data, PrivMode mode)
{
  m_pe_thread->DebugPrint ("<Error: CSR CYCLE is not writable>\n");
  return CsrAccResult::PrivError;
}


/*
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_TIME (Xlen_t data, PrivMode mode)
{
  m_pe_thread->DebugPrint ("<Error: CSR TIME is not writable>\n");
  // time.time = data;
  return CsrAccResult::PrivError;
}
*/


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_INSTRET (Xlen_t data, PrivMode mode)
{
  m_pe_thread->DebugPrint ("<Error: CSR INSTRET is not writable>\n");
  // instret.instret = data;
  return CsrAccResult::PrivError;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_CYCLEH (Xlen_t data, PrivMode mode)
{
  m_pe_thread->DebugPrint ("<Error: CSR CYCLEH is not writable>\n");
  // cycleh.cycleh = data;
  return CsrAccResult::PrivError;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_TIMEH (Xlen_t data, PrivMode mode)
{
  m_pe_thread->DebugPrint ("<Error: CSR TIMEH is not writable>\n");
  // timeh.timeh = data;
  return CsrAccResult::PrivError;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_INSTRETH (Xlen_t data, PrivMode mode)
{
  m_pe_thread->DebugPrint ("<Error: CSR CYCLE is not writable>\n");
  // instreth.instreth = data;
  return CsrAccResult::PrivError;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_SSTATUS (Xlen_t data, PrivMode mode)
{
  if (mode >= PrivMode::PrivSupervisor) {

    if ((mstatus.bit_mstatus.SUM  != ExtractBitField (data, SYSREG_MSTATUS_SUM_MSB, SYSREG_MSTATUS_SUM_LSB)) ||
        (mstatus.bit_mstatus.MXR  != ExtractBitField (data, SYSREG_MSTATUS_MXR_MSB, SYSREG_MSTATUS_MXR_LSB))) {
      m_pe_thread->FlushTlb();
    }

 // mstatus.bit_mstatus.SD   = ExtractBitField (data, SYSREG_SSTATUS_SD_MSB,   SYSREG_SSTATUS_SD_LSB  );
 // mstatus.bit_mstatus.SXL  = ExtractBitField (data, SYSREG_SSTATUS_SXL_MSB,  SYSREG_SSTATUS_SXL_LSB );
 // mstatus.bit_mstatus.UXL  = ExtractBitField (data, SYSREG_SSTATUS_UXL_MSB,  SYSREG_SSTATUS_UXL_LSB );
 // mstatus.bit_mstatus.TSR  = ExtractBitField (data, SYSREG_SSTATUS_TSR_MSB,  SYSREG_SSTATUS_TSR_LSB );
 // mstatus.bit_mstatus.TW   = ExtractBitField (data, SYSREG_SSTATUS_TW_MSB,   SYSREG_SSTATUS_TW _LSB );
 // mstatus.bit_mstatus.TVM  = ExtractBitField (data, SYSREG_SSTATUS_TVM_MSB,  SYSREG_SSTATUS_TVM_LSB );
    mstatus.bit_mstatus.MXR  = ExtractBitField (data, SYSREG_SSTATUS_MXR_MSB,  SYSREG_SSTATUS_MXR_LSB );
    mstatus.bit_mstatus.SUM  = ExtractBitField (data, SYSREG_SSTATUS_SUM_MSB,  SYSREG_SSTATUS_SUM_LSB );
 // mstatus.bit_mstatus.MPRV = ExtractBitField (data, SYSREG_SSTATUS_MPRV_MSB, SYSREG_SSTATUS_MPRV_LSB);
    mstatus.bit_mstatus.XS   = ExtractBitField (data, SYSREG_SSTATUS_XS_MSB,   SYSREG_SSTATUS_XS_LSB  );
    mstatus.bit_mstatus.FS   = ExtractBitField (data, SYSREG_SSTATUS_FS_MSB,   SYSREG_SSTATUS_FS_LSB  );
 // mstatus.bit_mstatus.MPP  = ExtractBitField (data, SYSREG_SSTATUS_MPP_MSB,  SYSREG_SSTATUS_MPP_LSB );
    mstatus.bit_mstatus.SPP  = ExtractBitField (data, SYSREG_SSTATUS_SPP_MSB,  SYSREG_SSTATUS_SPP_LSB );
 // mstatus.bit_mstatus.MPIE = ExtractBitField (data, SYSREG_SSTATUS_MPIE_MSB, SYSREG_SSTATUS_MPIE_LSB);
    mstatus.bit_mstatus.SPIE = ExtractBitField (data, SYSREG_SSTATUS_SPIE_MSB, SYSREG_SSTATUS_SPIE_LSB);
 // mstatus.bit_mstatus.UPIE = ExtractBitField (data, SYSREG_SSTATUS_UPIE_MSB, SYSREG_SSTATUS_UPIE_LSB);
 // mstatus.bit_mstatus.MIE  = ExtractBitField (data, SYSREG_SSTATUS_MIE_MSB,  SYSREG_SSTATUS_MIE_LSB );
    mstatus.bit_mstatus.SIE  = ExtractBitField (data, SYSREG_SSTATUS_SIE_MSB,  SYSREG_SSTATUS_SIE_LSB );
 // mstatus.bit_mstatus.UIE  = ExtractBitField (data, SYSREG_SSTATUS_UIE_MSB,  SYSREG_SSTATUS_UIE_LSB );
    return CsrAccResult::Normal;
  } else {
    m_pe_thread->DebugPrint ("<Error: SSTATUS is not writable lower than Supervisor Mode>\n");
    return CsrAccResult::PrivError;
  }
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_STVEC (Xlen_t data, PrivMode mode)
{
  stvec.stvec = data;
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_SCOUNTEREN (Xlen_t data, PrivMode mode)
{
  scounteren.scounteren = data;
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_SIE (Xlen_t data, PrivMode mode)
{
  mie.mie = (mie.mie & ~mideleg.mideleg) | (data & mideleg.mideleg);
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_SSCRATCH (Xlen_t data, PrivMode mode)
{
  sscratch.sscratch = data;
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_SEPC (Xlen_t data, PrivMode mode)
{
  sepc.sepc = data;
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_SCAUSE (Xlen_t data, PrivMode mode)
{
  scause.scause = data;
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_STVAL (Xlen_t data, PrivMode mode)
{
  stval.stval = data;
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_SIP (Xlen_t data, PrivMode mode)
{
  Xlen_t mask = (1 << static_cast<Xlen_t>(IntCode::SuperSoftware)) & mideleg.mideleg;
  mip.mip = (mip.mip & ~mask) | (data & mask);
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_SATP (Xlen_t data, PrivMode mode)
{
  satp.satp = data;
  m_pe_thread->FlushTlb();
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_HSTATUS (Xlen_t data, PrivMode mode)
{
  hstatus.hstatus = data;
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_HTVEC (Xlen_t data, PrivMode mode)
{
  htvec.htvec = data;
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_HSCRATCH (Xlen_t data, PrivMode mode)
{
  hscratch.hscratch = data;
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_HEPC (Xlen_t data, PrivMode mode)
{
  hepc.hepc = data;
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_HCAUSE (Xlen_t data, PrivMode mode)
{
  hcause.hcause = data;
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_HBADADDR (Xlen_t data, PrivMode mode)
{
  hbadaddr.hbadaddr = data;
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MIMPID (Xlen_t data, PrivMode mode)
{
  mimpid.mimpid = data;
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MHARTID (Xlen_t data, PrivMode mode)
{
  mhartid.Hart_ID = data;
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MSTATUS (Xlen_t data, PrivMode mode)
{
  // m_pe_thread->InfoPrint ("<Info: Before update Write_MSTATUS %016lx>\n", mstatus.mstatus);

  if ((mstatus.bit_mstatus.MPP  != ExtractBitField (data, SYSREG_MSTATUS_MPP_MSB,  SYSREG_MSTATUS_MPP_LSB)) ||
      (mstatus.bit_mstatus.MPRV != ExtractBitField (data, SYSREG_MSTATUS_MPRV_MSB, SYSREG_MSTATUS_MPRV_LSB)) ||
      (mstatus.bit_mstatus.SUM  != ExtractBitField (data, SYSREG_MSTATUS_SUM_MSB,  SYSREG_MSTATUS_SUM_LSB)) ||
      (mstatus.bit_mstatus.MXR  != ExtractBitField (data, SYSREG_MSTATUS_MXR_MSB,  SYSREG_MSTATUS_MXR_LSB))) {
    m_pe_thread->FlushTlb();
  }

//mstatus.bit_mstatus.SD   = ExtractBitField (data, SYSREG_MSTATUS_SD_MSB,   SYSREG_MSTATUS_SD_LSB  );
//mstatus.bit_mstatus.SXL  = ExtractBitField (data, SYSREG_MSTATUS_SXL_MSB,  SYSREG_MSTATUS_SXL_LSB );
//mstatus.bit_mstatus.UXL  = ExtractBitField (data, SYSREG_MSTATUS_UXL_MSB,  SYSREG_MSTATUS_UXL_LSB );
  mstatus.bit_mstatus.TSR  = ExtractBitField (data, SYSREG_MSTATUS_TSR_MSB,  SYSREG_MSTATUS_TSR_LSB );
  mstatus.bit_mstatus.TW   = ExtractBitField (data, SYSREG_MSTATUS_TW_MSB,   SYSREG_MSTATUS_TW_LSB  );
  mstatus.bit_mstatus.TVM  = ExtractBitField (data, SYSREG_MSTATUS_TVM_MSB,  SYSREG_MSTATUS_TVM_LSB );
  mstatus.bit_mstatus.MXR  = ExtractBitField (data, SYSREG_MSTATUS_MXR_MSB,  SYSREG_MSTATUS_MXR_LSB );
//mstatus.bit_mstatus.SUM  = ExtractBitField (data, SYSREG_MSTATUS_SUM_MSB,  SYSREG_MSTATUS_SUM_LSB );
  mstatus.bit_mstatus.MPRV = ExtractBitField (data, SYSREG_MSTATUS_MPRV_MSB, SYSREG_MSTATUS_MPRV_LSB);

  // This Implementation XS is not supported.
  // mstatus.bit_mstatus.XS   = ExtractBitField (data, SYSREG_MSTATUS_XS_MSB,   SYSREG_MSTATUS_XS_LSB  );

  mstatus.bit_mstatus.FS   = ExtractBitField (data, SYSREG_MSTATUS_FS_MSB,   SYSREG_MSTATUS_FS_LSB  );
  mstatus.bit_mstatus.MPP  = ExtractBitField (data, SYSREG_MSTATUS_MPP_MSB,  SYSREG_MSTATUS_MPP_LSB );
  mstatus.bit_mstatus.SPP  = ExtractBitField (data, SYSREG_MSTATUS_SPP_MSB,  SYSREG_MSTATUS_SPP_LSB );
  mstatus.bit_mstatus.MPIE = ExtractBitField (data, SYSREG_MSTATUS_MPIE_MSB, SYSREG_MSTATUS_MPIE_LSB);
  mstatus.bit_mstatus.SPIE = ExtractBitField (data, SYSREG_MSTATUS_SPIE_MSB, SYSREG_MSTATUS_SPIE_LSB);
  mstatus.bit_mstatus.UPIE = ExtractBitField (data, SYSREG_MSTATUS_UPIE_MSB, SYSREG_MSTATUS_UPIE_LSB);
  mstatus.bit_mstatus.MIE  = ExtractBitField (data, SYSREG_MSTATUS_MIE_MSB,  SYSREG_MSTATUS_MIE_LSB );
  mstatus.bit_mstatus.SIE  = ExtractBitField (data, SYSREG_MSTATUS_SIE_MSB,  SYSREG_MSTATUS_SIE_LSB );
  mstatus.bit_mstatus.UIE  = ExtractBitField (data, SYSREG_MSTATUS_UIE_MSB,  SYSREG_MSTATUS_UIE_LSB );

  if (mstatus.bit_mstatus.FS == 0x3) {
    mstatus.bit_mstatus.SD = 0x1;
  } else {
    mstatus.bit_mstatus.SD = 0x0;
  }

  // m_pe_thread->InfoPrint ("<Info: After  update Write_MSTATUS %016lx>\n", mstatus.mstatus);

  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MTVEC (Xlen_t data, PrivMode mode)
{
  mtvec.mtvec = data;
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MCOUNTEREN (Xlen_t data, PrivMode mode)
{
  mcounteren.mcounteren = data;
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MIE (Xlen_t data, PrivMode mode)
{
  mie.mie = data;
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MSCRATCH (Xlen_t data, PrivMode mode)
{
  mscratch.mscratch = data;
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MEPC (Xlen_t data, PrivMode mode)
{
  mepc.mepc = data;
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MCAUSE (Xlen_t data, PrivMode mode)
{
  mcause.mcause = data;
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MTVAL (Xlen_t data, PrivMode mode)
{
  mtval.mtval = data;
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MIP (Xlen_t data, PrivMode mode)
{
  mip.mip = data;
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MBASE (Xlen_t data, PrivMode mode)
{
  mbase.mbase = data;
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MBOUND (Xlen_t data, PrivMode mode)
{
  mbound.mbound = data;
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MIBASE (Xlen_t data, PrivMode mode)
{
  mibase.mibase = data;
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MIBOUND (Xlen_t data, PrivMode mode)
{
  mibound.mibound = data;
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MDBASE (Xlen_t data, PrivMode mode)
{
  mdbase.mdbase = data;
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MDBOUND (Xlen_t data, PrivMode mode)
{
  mdbound.mdbound = data;
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_STATS (Xlen_t data, PrivMode mode)
{
  stats.stats = data;
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_HPMCOUNTER12(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_HIE(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_HPMCOUNTERH30(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MHPMCOUNTER19(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_HPMCOUNTERH5(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MHPEVENT11(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_HPMCOUNTER9(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MHPMCOUNTER16(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MHPEVENT8(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_HPMCOUNTERH27(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_SEDELEG(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_HPMCOUNTER24(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_HPMCOUNTERH17(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MHPMCOUNTER6(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MHPEVENT23(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MHPMCOUNTER31(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_HIP(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_HPMCOUNTER18(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_UEPC(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MHPMCOUNTER25(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MHPEVENT17(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_HPMCOUNTERH11(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MHPMCOUNTER22(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_HPMCOUNTER30(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MHPEVENT29(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_HPMCOUNTER15(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MHPMCOUNTER12(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_UIE(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MHPEVENT4(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_HPMCOUNTERH23(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_HPMCOUNTER5(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MHPMCOUNTER9(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MISA(Xlen_t data, PrivMode mode)
{
  if (mode == PrivMode::PrivMachine) {
    if (!(m_pe_thread->IsMisaWritable())) {
      m_pe_thread->DebugPrint ("<Warning: MISA is not writable by --protect-misa.>\n");
      return CsrAccResult::IgnoreWrite;
    }
    if (!(data & 0x04) && ((m_pe_thread->GetPC() & 0x02) == 0x02)) {
      // if disabling C and next instruction fetch is misaligned,
      // C mode cannot be disabled.
      return CsrAccResult::Normal;
    } else {
      misa.misa = data;
      return CsrAccResult::Normal;
    }
  } else {
    m_pe_thread->DebugPrint ("<Error: MISA is not writable lower than Machine Mode>\n");
    return CsrAccResult::PrivError;
  }
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_HPMCOUNTERH20(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MHPMCOUNTER28(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_HPMCOUNTERH8(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_HPMCOUNTER21(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_HPMCOUNTERH14(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MHPMCOUNTER3(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MHPEVENT26(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_HPMCOUNTER27(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_UIP(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MHPEVENT14(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MHPEVENT20(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_HPMCOUNTERH4(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_HPMCOUNTER3(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MHPMCOUNTER18(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_HPMCOUNTER4(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MARCHID(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MVENDORID(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MHPMCOUNTER21(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_HPMCOUNTERH25(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_HPMCOUNTERH26(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_HPMCOUNTERH24(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MHPEVENT3(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MHPMCOUNTER14(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MHPMCOUNTER15(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MHPMCOUNTER13(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_HPMCOUNTER14(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_HPMCOUNTER7(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_HPMCOUNTER8(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_HPMCOUNTER6(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_HPMCOUNTERH22(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MHPEVENT31(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MHPEVENT30(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_HPMCOUNTER29(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MHPEVENT6(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MHPEVENT7(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MHPEVENT5(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MHPMCOUNTER30(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_HPTBR(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MHPMCOUNTER8(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MHPEVENT10(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_HPMCOUNTER17(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_HPMCOUNTER19(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_HPMCOUNTERH7(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MHPMCOUNTER17(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MHPEVENT9(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_HPMCOUNTERH3(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_HPMCOUNTER10(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_HPMCOUNTERH29(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_HPMCOUNTERH31(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_HIDELEG(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MCYCLE(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_HPMCOUNTERH13(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_USTATUS(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_USCRATCH(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_UCAUSE(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_HPMCOUNTER26(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_HPMCOUNTER11(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MHPEVENT25(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MHPMCOUNTER24(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MHPMCOUNTER26(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_HPMCOUNTERH19(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MHPEVENT16(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MHPEVENT18(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MHPEVENT13(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_UTVEC(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MHPMCOUNTER23(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MHPMCOUNTER29(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_SIDELEG(Xlen_t data, PrivMode mode)
{
  if (PrivMode::PrivSupervisor <= mode) {
    sideleg.sideleg = data;
    return CsrAccResult::Normal;
  } else {
    m_pe_thread->DebugPrint("<Error:SIDELEG is not allowed to write in %d mode.>\n", mode);
    return CsrAccResult::PrivError;
  }
}
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MEDELEG(Xlen_t data, PrivMode mode)
{
  if (PrivMode::PrivSupervisor <= mode) {
    medeleg.medeleg = data;
    return CsrAccResult::Normal;
  } else {
    m_pe_thread->DebugPrint("<Error:MEDELEG is not allowed to write in %d mode.>\n", mode);
    return CsrAccResult::PrivError;
  }
}
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_HPMCOUNTER16(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_HPMCOUNTER22(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MHPMCOUNTER20(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_HPMCOUNTERH10(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_HPMCOUNTERH12(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_HPMCOUNTER20(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_HPMCOUNTER31(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_HPMCOUNTER23(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_HPMCOUNTER25(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_HPMCOUNTERH16(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_HPMCOUNTERH18(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_HPMCOUNTER28(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MIDELEG(Xlen_t data, PrivMode mode)
{
  if (PrivMode::PrivSupervisor <= mode) {
    mideleg.mideleg = data;
    return CsrAccResult::Normal;
  } else {
    m_pe_thread->DebugPrint("<Error:MIDELEG is not allowed to write in %d mode.>\n", mode);
    return CsrAccResult::PrivError;
  }
}

template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MHPEVENT19(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_HPMCOUNTERH21(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MHPMCOUNTER4(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MHPEVENT15(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MHPEVENT21(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MHPEVENT27(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MHPMCOUNTER5(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MHPMCOUNTER7(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MHPMCOUNTER10(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MHPEVENT22(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MHPEVENT24(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MINSTRET(Xlen_t data, PrivMode mode)
{
  if (PrivMode::PrivSupervisor <= mode) {
    minstret.minstret = data;
    return CsrAccResult::Normal;
  } else {
    m_pe_thread->DebugPrint("<Error:MINSTRET is not allowed to write in %d mode.>\n", mode);
    return CsrAccResult::PrivError;
  }
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_HPMCOUNTER13(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MHPEVENT28(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MHPMCOUNTER11(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MHPEVENT12(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_UBADADDR(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_HPMCOUNTERH28(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_HEDELEG(Xlen_t data, PrivMode mode)
{
  if (PrivMode::PrivSupervisor <= mode) {
    hideleg.hideleg = data;
    return CsrAccResult::Normal;
  } else {
    m_pe_thread->DebugPrint("<Error:MIDELEG is not allowed to write in %d mode.>\n", mode);
    return CsrAccResult::PrivError;
  }
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_HPMCOUNTERH9(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_HPMCOUNTERH15(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_HPMCOUNTERH6(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_MHPMCOUNTER27(Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; }


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_PMPCFG0   (Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; };
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_PMPCFG1   (Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; };
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_PMPCFG2   (Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; };
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_PMPCFG3   (Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; };
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_PMPADDR0  (Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; };
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_PMPADDR1  (Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; };
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_PMPADDR2  (Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; };
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_PMPADDR3  (Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; };
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_PMPADDR4  (Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; };
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_PMPADDR5  (Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; };
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_PMPADDR6  (Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; };
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_PMPADDR7  (Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; };
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_PMPADDR8  (Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; };
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_PMPADDR9  (Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; };
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_PMPADDR10 (Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; };
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_PMPADDR11 (Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; };
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_PMPADDR12 (Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; };
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_PMPADDR13 (Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; };
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_PMPADDR14 (Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; };
template <typename Xlen_t>
CsrAccResult CsrEnv::Write_PMPADDR15 (Xlen_t data, PrivMode mode) { return CsrAccResult::Normal; };

template <typename Xlen_t>
CsrAccResult CsrEnv::Write_UARCH00 (Xlen_t data, PrivMode mode)
{
  m_pe_thread->DebugPrint ("<Error: CSR UARCH00 is not writable>\n");
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_UARCH01 (Xlen_t data, PrivMode mode)
{
  m_pe_thread->DebugPrint ("<Error: CSR UARCH01 is not writable>\n");
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_UARCH02 (Xlen_t data, PrivMode mode)
{
  m_pe_thread->DebugPrint ("<Error: CSR UARCH02 is not writable>\n");
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_UARCH03 (Xlen_t data, PrivMode mode)
{
  m_pe_thread->DebugPrint ("<Error: CSR UARCH03 is not writable>\n");
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_UARCH04 (Xlen_t data, PrivMode mode)
{
  m_pe_thread->DebugPrint ("<Error: CSR UARCH04 is not writable>\n");
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_UARCH05 (Xlen_t data, PrivMode mode)
{
  m_pe_thread->DebugPrint ("<Error: CSR UARCH05 is not writable>\n");
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_UARCH06 (Xlen_t data, PrivMode mode)
{
  m_pe_thread->DebugPrint ("<Error: CSR UARCH06 is not writable>\n");
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_UARCH07 (Xlen_t data, PrivMode mode)
{
  m_pe_thread->DebugPrint ("<Error: CSR UARCH07 is not writable>\n");
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_UARCH08 (Xlen_t data, PrivMode mode)
{
  m_pe_thread->DebugPrint ("<Error: CSR UARCH08 is not writable>\n");
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_UARCH09 (Xlen_t data, PrivMode mode)
{
  m_pe_thread->DebugPrint ("<Error: CSR UARCH09 is not writable>\n");
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_UARCH10 (Xlen_t data, PrivMode mode)
{
  m_pe_thread->DebugPrint ("<Error: CSR UARCH10 is not writable>\n");
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_UARCH11 (Xlen_t data, PrivMode mode)
{
  m_pe_thread->DebugPrint ("<Error: CSR UARCH11 is not writable>\n");
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_UARCH12 (Xlen_t data, PrivMode mode)
{
  m_pe_thread->DebugPrint ("<Error: CSR UARCH12 is not writable>\n");
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_UARCH13 (Xlen_t data, PrivMode mode)
{
  m_pe_thread->DebugPrint ("<Error: CSR UARCH13 is not writable>\n");
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_UARCH14 (Xlen_t data, PrivMode mode)
{
  m_pe_thread->DebugPrint ("<Error: CSR UARCH14 is not writable>\n");
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_UARCH15 (Xlen_t data, PrivMode mode)
{
  m_pe_thread->DebugPrint ("<Error: CSR UARCH15 is not writable>\n");
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_TSELECT (Xlen_t data, PrivMode mode)
{
  tselect.tselect = data;
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_TDATA1 (Xlen_t data, PrivMode mode)
{
  uint32_t xlen_w = 64;

  tdata1.bit_tdata1.hmode   = ExtractBitField (data, xlen_w-5, xlen_w-5);
  // tdata1.bit_tdata1.maskmax = ExtractBitField (data, xlen_w-6, xlen_w-11);
  tdata1.bit_tdata1.select  = ExtractBitField (data, 19, 19);
  tdata1.bit_tdata1.timing  = ExtractBitField (data, 18, 18);
  tdata1.bit_tdata1.action  = ExtractBitField (data, 17, 12);
  tdata1.bit_tdata1.chain   = ExtractBitField (data, 11, 11);
  tdata1.bit_tdata1.match   = ExtractBitField (data, 10,  7);
  tdata1.bit_tdata1.m       = ExtractBitField (data,  6,  6);
  tdata1.bit_tdata1.h       = ExtractBitField (data,  5,  5);
  tdata1.bit_tdata1.s       = ExtractBitField (data,  4,  4);
  tdata1.bit_tdata1.u       = ExtractBitField (data,  3,  3);
  tdata1.bit_tdata1.execute = ExtractBitField (data,  2,  2);
  tdata1.bit_tdata1.store   = ExtractBitField (data,  1,  1);
  tdata1.bit_tdata1.load    = ExtractBitField (data,  0,  0);

  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_TDATA2 (Xlen_t data, PrivMode mode)
{
  tdata2.tdata2 = data;
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_TDATA3 (Xlen_t data, PrivMode mode)
{
  tdata3.tdata3 = data;
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_VL (Xlen_t data, PrivMode mode)
{
  vl.vl = data;
  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_VTYPE (Xlen_t data, PrivMode mode)
{
  vtype.vtype = data;
  DWord_t vl = m_pe_thread->get_VLEN() * (1 << vtype.bit_vtype.vlmul) / (1 << (vtype.bit_vtype.vsew+3));
  Write_VL (vl, mode);

  return CsrAccResult::Normal;
}


template <typename Xlen_t>
CsrAccResult CsrEnv::Write_VLENB (Xlen_t data, PrivMode mode)
{
  return CsrAccResult::Normal;
}


CsrEnv::CsrEnv (RiscvPeThread *env) : m_pe_thread (env)
{
  misa.bit_misa.MXL   = 2;   // XLEN
  misa.bit_misa.Extensions = 0x14112d; // Extension

  fflags.fflags       = 0;
  frm.frm             = 0;
  fcsr.fcsr           = 0;
  cycle.cycle         = 0;
  instret.instret     = 0;
  cycleh.cycleh       = 0;
  instreth.instreth   = 0;
  sstatus.sstatus     = 0;
  // sstatus.bit_sstatus.SUM = 0;
  stvec.stvec         = 0;
  sie.sie             = 0;
  sscratch.sscratch   = 0;
  sepc.sepc           = 0;
  scause.scause       = 0;
  stval.stval         = 0;
  sip.sip             = 0;
  satp.satp           = 0;
  cycle.cycle         = 0;
  hstatus.hstatus     = 0;
  htvec.htvec         = 0;
  hscratch.hscratch   = 0;
  hepc.hepc           = 0;
  hcause.hcause       = 0;
  hbadaddr.hbadaddr   = 0;
  mimpid.mimpid       = 0;
  mhartid.Hart_ID     = 0;

  mstatus.mstatus     = 0;
  mstatus.bit_mstatus.SD  = 0;  // Difficult?
  mstatus.bit_mstatus.SXL = 2;  // XLEN
  mstatus.bit_mstatus.UXL = 2;  // XLEN
  mstatus.bit_mstatus.SUM = 0;

  mtvec.mtvec         = 0;
  mie.mie             = 0;
  mscratch.mscratch   = 0;
  mepc.mepc           = 0;
  mcause.mcause       = 0;
  mtval.mtval         = 0;
  mip.mip             = 0;
  mbase.mbase         = 0;
  mbound.mbound       = 0;
  mibase.mibase       = 0;
  mibound.mibound     = 0;
  mdbase.mdbase       = 0;
  mdbound.mdbound     = 0;
  stats.stats         = 0;
  uarch00.uarch00     = 0;
  uarch01.uarch01     = 0;
  uarch02.uarch02     = 0;
  uarch03.uarch03     = 0;
  uarch04.uarch04     = 0;
  uarch05.uarch05     = 0;
  uarch06.uarch06     = 0;
  uarch07.uarch07     = 0;
  uarch08.uarch08     = 0;
  uarch09.uarch09     = 0;
  uarch10.uarch10     = 0;
  uarch11.uarch11     = 0;
  uarch12.uarch12     = 0;
  uarch13.uarch13     = 0;
  uarch14.uarch14     = 0;
  uarch15.uarch15     = 0;

  tselect.tselect     = 0;

  tdata1.tdata1             = 0;  // All format
  tdata1.bit_tdata1.type    = 2;
  tdata1.bit_tdata1.hmode   = 0;
  tdata1.bit_tdata1.maskmax = 0x4;

  tdata2.tdata2       = 0;
  tdata3.tdata3       = 0;

  vstart.vstart = 0;
}


#include "riscv_sysreg_template_list.hpp"
