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


#include <stdint.h>
#include "basic.hpp"
#include "riscv_pe_thread.hpp"
#include "riscv_sysreg_impl.hpp"



template <typename Xlen_t>Xlen_t CsrEnv::Riscv_Read_CSR (Addr_t addr, Xlen_t *data, PrivMode mode)
{
  switch (addr) {
    case SYSREG_ADDR_USTATUS : return Read_USTATUS<Xlen_t> (data, mode);
    case SYSREG_ADDR_UIE : return Read_UIE<Xlen_t> (data, mode);
    case SYSREG_ADDR_UTVEC : return Read_UTVEC<Xlen_t> (data, mode);
    case SYSREG_ADDR_USCRATCH : return Read_USCRATCH<Xlen_t> (data, mode);
    case SYSREG_ADDR_UEPC : return Read_UEPC<Xlen_t> (data, mode);
    case SYSREG_ADDR_UCAUSE : return Read_UCAUSE<Xlen_t> (data, mode);
    case SYSREG_ADDR_UBADADDR : return Read_UBADADDR<Xlen_t> (data, mode);
    case SYSREG_ADDR_UIP : return Read_UIP<Xlen_t> (data, mode);
    case SYSREG_ADDR_FFLAGS : return Read_FFLAGS<Xlen_t> (data, mode);
    case SYSREG_ADDR_FRM : return Read_FRM<Xlen_t> (data, mode);
    case SYSREG_ADDR_FCSR : return Read_FCSR<Xlen_t> (data, mode);
    case SYSREG_ADDR_CYCLE : return Read_CYCLE<Xlen_t> (data, mode);
    case SYSREG_ADDR_INSTRET : return Read_INSTRET<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTER3 : return Read_HPMCOUNTER3<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTER4 : return Read_HPMCOUNTER4<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTER5 : return Read_HPMCOUNTER5<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTER6 : return Read_HPMCOUNTER6<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTER7 : return Read_HPMCOUNTER7<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTER8 : return Read_HPMCOUNTER8<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTER9 : return Read_HPMCOUNTER9<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTER10 : return Read_HPMCOUNTER10<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTER11 : return Read_HPMCOUNTER11<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTER12 : return Read_HPMCOUNTER12<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTER13 : return Read_HPMCOUNTER13<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTER14 : return Read_HPMCOUNTER14<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTER15 : return Read_HPMCOUNTER15<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTER16 : return Read_HPMCOUNTER16<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTER17 : return Read_HPMCOUNTER17<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTER18 : return Read_HPMCOUNTER18<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTER19 : return Read_HPMCOUNTER19<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTER20 : return Read_HPMCOUNTER20<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTER21 : return Read_HPMCOUNTER21<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTER22 : return Read_HPMCOUNTER22<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTER23 : return Read_HPMCOUNTER23<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTER24 : return Read_HPMCOUNTER24<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTER25 : return Read_HPMCOUNTER25<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTER26 : return Read_HPMCOUNTER26<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTER27 : return Read_HPMCOUNTER27<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTER28 : return Read_HPMCOUNTER28<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTER29 : return Read_HPMCOUNTER29<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTER30 : return Read_HPMCOUNTER30<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTER31 : return Read_HPMCOUNTER31<Xlen_t> (data, mode);
    case SYSREG_ADDR_CYCLEH : return Read_CYCLEH<Xlen_t> (data, mode);
    case SYSREG_ADDR_TIMEH : return Read_TIMEH<Xlen_t> (data, mode);
    case SYSREG_ADDR_INSTRETH : return Read_INSTRETH<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTERH3 : return Read_HPMCOUNTERH3<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTERH4 : return Read_HPMCOUNTERH4<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTERH5 : return Read_HPMCOUNTERH5<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTERH6 : return Read_HPMCOUNTERH6<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTERH7 : return Read_HPMCOUNTERH7<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTERH8 : return Read_HPMCOUNTERH8<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTERH9 : return Read_HPMCOUNTERH9<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTERH10 : return Read_HPMCOUNTERH10<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTERH11 : return Read_HPMCOUNTERH11<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTERH12 : return Read_HPMCOUNTERH12<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTERH13 : return Read_HPMCOUNTERH13<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTERH14 : return Read_HPMCOUNTERH14<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTERH15 : return Read_HPMCOUNTERH15<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTERH16 : return Read_HPMCOUNTERH16<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTERH17 : return Read_HPMCOUNTERH17<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTERH18 : return Read_HPMCOUNTERH18<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTERH19 : return Read_HPMCOUNTERH19<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTERH20 : return Read_HPMCOUNTERH20<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTERH21 : return Read_HPMCOUNTERH21<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTERH22 : return Read_HPMCOUNTERH22<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTERH23 : return Read_HPMCOUNTERH23<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTERH24 : return Read_HPMCOUNTERH24<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTERH25 : return Read_HPMCOUNTERH25<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTERH26 : return Read_HPMCOUNTERH26<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTERH27 : return Read_HPMCOUNTERH27<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTERH28 : return Read_HPMCOUNTERH28<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTERH29 : return Read_HPMCOUNTERH29<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTERH30 : return Read_HPMCOUNTERH30<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTERH31 : return Read_HPMCOUNTERH31<Xlen_t> (data, mode);
    case SYSREG_ADDR_SSTATUS : return Read_SSTATUS<Xlen_t> (data, mode);
    case SYSREG_ADDR_SEDELEG : return Read_SEDELEG<Xlen_t> (data, mode);
    case SYSREG_ADDR_SIDELEG : return Read_SIDELEG<Xlen_t> (data, mode);
    case SYSREG_ADDR_SIE : return Read_SIE<Xlen_t> (data, mode);
    case SYSREG_ADDR_STVEC : return Read_STVEC<Xlen_t> (data, mode);
    case SYSREG_ADDR_SCOUNTEREN : return Read_SCOUNTEREN<Xlen_t> (data, mode);
    case SYSREG_ADDR_SSCRATCH : return Read_SSCRATCH<Xlen_t> (data, mode);
    case SYSREG_ADDR_SEPC : return Read_SEPC<Xlen_t> (data, mode);
    case SYSREG_ADDR_SCAUSE : return Read_SCAUSE<Xlen_t> (data, mode);
    case SYSREG_ADDR_STVAL : return Read_STVAL<Xlen_t> (data, mode);
    case SYSREG_ADDR_SIP : return Read_SIP<Xlen_t> (data, mode);
    case SYSREG_ADDR_SATP : return Read_SATP<Xlen_t> (data, mode);
    case SYSREG_ADDR_HSTATUS : return Read_HSTATUS<Xlen_t> (data, mode);
    case SYSREG_ADDR_HEDELEG : return Read_HEDELEG<Xlen_t> (data, mode);
    case SYSREG_ADDR_HIDELEG : return Read_HIDELEG<Xlen_t> (data, mode);
    case SYSREG_ADDR_HIE : return Read_HIE<Xlen_t> (data, mode);
    case SYSREG_ADDR_HTVEC : return Read_HTVEC<Xlen_t> (data, mode);
    case SYSREG_ADDR_HSCRATCH : return Read_HSCRATCH<Xlen_t> (data, mode);
    case SYSREG_ADDR_HEPC : return Read_HEPC<Xlen_t> (data, mode);
    case SYSREG_ADDR_HCAUSE : return Read_HCAUSE<Xlen_t> (data, mode);
    case SYSREG_ADDR_HBADADDR : return Read_HBADADDR<Xlen_t> (data, mode);
    case SYSREG_ADDR_HIP : return Read_HIP<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPTBR : return Read_HPTBR<Xlen_t> (data, mode);
    case SYSREG_ADDR_MVENDORID : return Read_MVENDORID<Xlen_t> (data, mode);
    case SYSREG_ADDR_MARCHID : return Read_MARCHID<Xlen_t> (data, mode);
    case SYSREG_ADDR_MIMPID : return Read_MIMPID<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHARTID : return Read_MHARTID<Xlen_t> (data, mode);
    case SYSREG_ADDR_MSTATUS : return Read_MSTATUS<Xlen_t> (data, mode);
    case SYSREG_ADDR_MISA : return Read_MISA<Xlen_t> (data, mode);
    case SYSREG_ADDR_MEDELEG : return Read_MEDELEG<Xlen_t> (data, mode);
    case SYSREG_ADDR_MIDELEG : return Read_MIDELEG<Xlen_t> (data, mode);
    case SYSREG_ADDR_MIE : return Read_MIE<Xlen_t> (data, mode);
    case SYSREG_ADDR_MTVEC : return Read_MTVEC<Xlen_t> (data, mode);
    case SYSREG_ADDR_MCOUNTEREN : return Read_MCOUNTEREN<Xlen_t> (data, mode);
    case SYSREG_ADDR_MSCRATCH : return Read_MSCRATCH<Xlen_t> (data, mode);
    case SYSREG_ADDR_MEPC : return Read_MEPC<Xlen_t> (data, mode);
    case SYSREG_ADDR_MCAUSE : return Read_MCAUSE<Xlen_t> (data, mode);
    case SYSREG_ADDR_MTVAL : return Read_MTVAL<Xlen_t> (data, mode);
    case SYSREG_ADDR_MIP : return Read_MIP<Xlen_t> (data, mode);
    case SYSREG_ADDR_MBASE : return Read_MBASE<Xlen_t> (data, mode);
    case SYSREG_ADDR_MBOUND : return Read_MBOUND<Xlen_t> (data, mode);
    case SYSREG_ADDR_MIBASE : return Read_MIBASE<Xlen_t> (data, mode);
    case SYSREG_ADDR_MIBOUND : return Read_MIBOUND<Xlen_t> (data, mode);
    case SYSREG_ADDR_MDBASE : return Read_MDBASE<Xlen_t> (data, mode);
    case SYSREG_ADDR_MDBOUND : return Read_MDBOUND<Xlen_t> (data, mode);
    case SYSREG_ADDR_MCYCLE : return Read_MCYCLE<Xlen_t> (data, mode);
    case SYSREG_ADDR_MINSTRET : return Read_MINSTRET<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPMCOUNTER3 : return Read_MHPMCOUNTER3<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPMCOUNTER4 : return Read_MHPMCOUNTER4<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPMCOUNTER5 : return Read_MHPMCOUNTER5<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPMCOUNTER6 : return Read_MHPMCOUNTER6<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPMCOUNTER7 : return Read_MHPMCOUNTER7<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPMCOUNTER8 : return Read_MHPMCOUNTER8<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPMCOUNTER9 : return Read_MHPMCOUNTER9<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPMCOUNTER10 : return Read_MHPMCOUNTER10<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPMCOUNTER11 : return Read_MHPMCOUNTER11<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPMCOUNTER12 : return Read_MHPMCOUNTER12<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPMCOUNTER13 : return Read_MHPMCOUNTER13<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPMCOUNTER14 : return Read_MHPMCOUNTER14<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPMCOUNTER15 : return Read_MHPMCOUNTER15<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPMCOUNTER16 : return Read_MHPMCOUNTER16<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPMCOUNTER17 : return Read_MHPMCOUNTER17<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPMCOUNTER18 : return Read_MHPMCOUNTER18<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPMCOUNTER19 : return Read_MHPMCOUNTER19<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPMCOUNTER20 : return Read_MHPMCOUNTER20<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPMCOUNTER21 : return Read_MHPMCOUNTER21<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPMCOUNTER22 : return Read_MHPMCOUNTER22<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPMCOUNTER23 : return Read_MHPMCOUNTER23<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPMCOUNTER24 : return Read_MHPMCOUNTER24<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPMCOUNTER25 : return Read_MHPMCOUNTER25<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPMCOUNTER26 : return Read_MHPMCOUNTER26<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPMCOUNTER27 : return Read_MHPMCOUNTER27<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPMCOUNTER28 : return Read_MHPMCOUNTER28<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPMCOUNTER29 : return Read_MHPMCOUNTER29<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPMCOUNTER30 : return Read_MHPMCOUNTER30<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPMCOUNTER31 : return Read_MHPMCOUNTER31<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPEVENT3 : return Read_MHPEVENT3<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPEVENT4 : return Read_MHPEVENT4<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPEVENT5 : return Read_MHPEVENT5<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPEVENT6 : return Read_MHPEVENT6<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPEVENT7 : return Read_MHPEVENT7<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPEVENT8 : return Read_MHPEVENT8<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPEVENT9 : return Read_MHPEVENT9<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPEVENT10 : return Read_MHPEVENT10<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPEVENT11 : return Read_MHPEVENT11<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPEVENT12 : return Read_MHPEVENT12<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPEVENT13 : return Read_MHPEVENT13<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPEVENT14 : return Read_MHPEVENT14<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPEVENT15 : return Read_MHPEVENT15<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPEVENT16 : return Read_MHPEVENT16<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPEVENT17 : return Read_MHPEVENT17<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPEVENT18 : return Read_MHPEVENT18<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPEVENT19 : return Read_MHPEVENT19<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPEVENT20 : return Read_MHPEVENT20<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPEVENT21 : return Read_MHPEVENT21<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPEVENT22 : return Read_MHPEVENT22<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPEVENT23 : return Read_MHPEVENT23<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPEVENT24 : return Read_MHPEVENT24<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPEVENT25 : return Read_MHPEVENT25<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPEVENT26 : return Read_MHPEVENT26<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPEVENT27 : return Read_MHPEVENT27<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPEVENT28 : return Read_MHPEVENT28<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPEVENT29 : return Read_MHPEVENT29<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPEVENT30 : return Read_MHPEVENT30<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPEVENT31 : return Read_MHPEVENT31<Xlen_t> (data, mode);
    case SYSREG_ADDR_STATS : return Read_STATS<Xlen_t> (data, mode);
    case SYSREG_ADDR_UARCH00 : return Read_UARCH00<Xlen_t> (data, mode);
    case SYSREG_ADDR_UARCH01 : return Read_UARCH01<Xlen_t> (data, mode);
    case SYSREG_ADDR_UARCH02 : return Read_UARCH02<Xlen_t> (data, mode);
    case SYSREG_ADDR_UARCH03 : return Read_UARCH03<Xlen_t> (data, mode);
    case SYSREG_ADDR_UARCH04 : return Read_UARCH04<Xlen_t> (data, mode);
    case SYSREG_ADDR_UARCH05 : return Read_UARCH05<Xlen_t> (data, mode);
    case SYSREG_ADDR_UARCH06 : return Read_UARCH06<Xlen_t> (data, mode);
    case SYSREG_ADDR_UARCH07 : return Read_UARCH07<Xlen_t> (data, mode);
    case SYSREG_ADDR_UARCH08 : return Read_UARCH08<Xlen_t> (data, mode);
    case SYSREG_ADDR_UARCH09 : return Read_UARCH09<Xlen_t> (data, mode);
    case SYSREG_ADDR_UARCH10 : return Read_UARCH10<Xlen_t> (data, mode);
    case SYSREG_ADDR_UARCH11 : return Read_UARCH11<Xlen_t> (data, mode);
    case SYSREG_ADDR_UARCH12 : return Read_UARCH12<Xlen_t> (data, mode);
    case SYSREG_ADDR_UARCH13 : return Read_UARCH13<Xlen_t> (data, mode);
    case SYSREG_ADDR_UARCH14 : return Read_UARCH14<Xlen_t> (data, mode);
    case SYSREG_ADDR_UARCH15 : return Read_UARCH15<Xlen_t> (data, mode);
    default : Error_CSR_Read (addr); *data = 0x0;
  }
  return -1;
}


template <typename Xlen_t>Xlen_t CsrEnv::Riscv_Write_CSR (Addr_t addr, Xlen_t data, PrivMode mode)
{
  switch (addr) {
    case SYSREG_ADDR_USTATUS : return Write_USTATUS<Xlen_t> (data, mode);
    case SYSREG_ADDR_UIE : return Write_UIE<Xlen_t> (data, mode);
    case SYSREG_ADDR_UTVEC : return Write_UTVEC<Xlen_t> (data, mode);
    case SYSREG_ADDR_USCRATCH : return Write_USCRATCH<Xlen_t> (data, mode);
    case SYSREG_ADDR_UEPC : return Write_UEPC<Xlen_t> (data, mode);
    case SYSREG_ADDR_UCAUSE : return Write_UCAUSE<Xlen_t> (data, mode);
    case SYSREG_ADDR_UBADADDR : return Write_UBADADDR<Xlen_t> (data, mode);
    case SYSREG_ADDR_UIP : return Write_UIP<Xlen_t> (data, mode);
    case SYSREG_ADDR_FFLAGS : return Write_FFLAGS<Xlen_t> (data, mode);
    case SYSREG_ADDR_FRM : return Write_FRM<Xlen_t> (data, mode);
    case SYSREG_ADDR_FCSR : return Write_FCSR<Xlen_t> (data, mode);
    case SYSREG_ADDR_CYCLE : return Write_CYCLE<Xlen_t> (data, mode);
    case SYSREG_ADDR_INSTRET : return Write_INSTRET<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTER3 : return Write_HPMCOUNTER3<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTER4 : return Write_HPMCOUNTER4<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTER5 : return Write_HPMCOUNTER5<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTER6 : return Write_HPMCOUNTER6<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTER7 : return Write_HPMCOUNTER7<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTER8 : return Write_HPMCOUNTER8<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTER9 : return Write_HPMCOUNTER9<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTER10 : return Write_HPMCOUNTER10<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTER11 : return Write_HPMCOUNTER11<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTER12 : return Write_HPMCOUNTER12<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTER13 : return Write_HPMCOUNTER13<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTER14 : return Write_HPMCOUNTER14<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTER15 : return Write_HPMCOUNTER15<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTER16 : return Write_HPMCOUNTER16<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTER17 : return Write_HPMCOUNTER17<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTER18 : return Write_HPMCOUNTER18<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTER19 : return Write_HPMCOUNTER19<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTER20 : return Write_HPMCOUNTER20<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTER21 : return Write_HPMCOUNTER21<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTER22 : return Write_HPMCOUNTER22<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTER23 : return Write_HPMCOUNTER23<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTER24 : return Write_HPMCOUNTER24<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTER25 : return Write_HPMCOUNTER25<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTER26 : return Write_HPMCOUNTER26<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTER27 : return Write_HPMCOUNTER27<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTER28 : return Write_HPMCOUNTER28<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTER29 : return Write_HPMCOUNTER29<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTER30 : return Write_HPMCOUNTER30<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTER31 : return Write_HPMCOUNTER31<Xlen_t> (data, mode);
    case SYSREG_ADDR_CYCLEH : return Write_CYCLEH<Xlen_t> (data, mode);
    case SYSREG_ADDR_TIMEH : return Write_TIMEH<Xlen_t> (data, mode);
    case SYSREG_ADDR_INSTRETH : return Write_INSTRETH<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTERH3 : return Write_HPMCOUNTERH3<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTERH4 : return Write_HPMCOUNTERH4<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTERH5 : return Write_HPMCOUNTERH5<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTERH6 : return Write_HPMCOUNTERH6<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTERH7 : return Write_HPMCOUNTERH7<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTERH8 : return Write_HPMCOUNTERH8<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTERH9 : return Write_HPMCOUNTERH9<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTERH10 : return Write_HPMCOUNTERH10<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTERH11 : return Write_HPMCOUNTERH11<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTERH12 : return Write_HPMCOUNTERH12<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTERH13 : return Write_HPMCOUNTERH13<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTERH14 : return Write_HPMCOUNTERH14<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTERH15 : return Write_HPMCOUNTERH15<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTERH16 : return Write_HPMCOUNTERH16<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTERH17 : return Write_HPMCOUNTERH17<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTERH18 : return Write_HPMCOUNTERH18<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTERH19 : return Write_HPMCOUNTERH19<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTERH20 : return Write_HPMCOUNTERH20<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTERH21 : return Write_HPMCOUNTERH21<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTERH22 : return Write_HPMCOUNTERH22<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTERH23 : return Write_HPMCOUNTERH23<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTERH24 : return Write_HPMCOUNTERH24<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTERH25 : return Write_HPMCOUNTERH25<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTERH26 : return Write_HPMCOUNTERH26<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTERH27 : return Write_HPMCOUNTERH27<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTERH28 : return Write_HPMCOUNTERH28<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTERH29 : return Write_HPMCOUNTERH29<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTERH30 : return Write_HPMCOUNTERH30<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPMCOUNTERH31 : return Write_HPMCOUNTERH31<Xlen_t> (data, mode);
    case SYSREG_ADDR_SSTATUS : return Write_SSTATUS<Xlen_t> (data, mode);
    case SYSREG_ADDR_SEDELEG : return Write_SEDELEG<Xlen_t> (data, mode);
    case SYSREG_ADDR_SIDELEG : return Write_SIDELEG<Xlen_t> (data, mode);
    case SYSREG_ADDR_SIE : return Write_SIE<Xlen_t> (data, mode);
    case SYSREG_ADDR_STVEC : return Write_STVEC<Xlen_t> (data, mode);
    case SYSREG_ADDR_SCOUNTEREN : return Write_SCOUNTEREN<Xlen_t> (data, mode);
    case SYSREG_ADDR_SSCRATCH : return Write_SSCRATCH<Xlen_t> (data, mode);
    case SYSREG_ADDR_SEPC : return Write_SEPC<Xlen_t> (data, mode);
    case SYSREG_ADDR_SCAUSE : return Write_SCAUSE<Xlen_t> (data, mode);
    case SYSREG_ADDR_STVAL : return Write_STVAL<Xlen_t> (data, mode);
    case SYSREG_ADDR_SIP : return Write_SIP<Xlen_t> (data, mode);
    case SYSREG_ADDR_SATP : return Write_SATP<Xlen_t> (data, mode);
    case SYSREG_ADDR_HSTATUS : return Write_HSTATUS<Xlen_t> (data, mode);
    case SYSREG_ADDR_HEDELEG : return Write_HEDELEG<Xlen_t> (data, mode);
    case SYSREG_ADDR_HIDELEG : return Write_HIDELEG<Xlen_t> (data, mode);
    case SYSREG_ADDR_HIE : return Write_HIE<Xlen_t> (data, mode);
    case SYSREG_ADDR_HTVEC : return Write_HTVEC<Xlen_t> (data, mode);
    case SYSREG_ADDR_HSCRATCH : return Write_HSCRATCH<Xlen_t> (data, mode);
    case SYSREG_ADDR_HEPC : return Write_HEPC<Xlen_t> (data, mode);
    case SYSREG_ADDR_HCAUSE : return Write_HCAUSE<Xlen_t> (data, mode);
    case SYSREG_ADDR_HBADADDR : return Write_HBADADDR<Xlen_t> (data, mode);
    case SYSREG_ADDR_HIP : return Write_HIP<Xlen_t> (data, mode);
    case SYSREG_ADDR_HPTBR : return Write_HPTBR<Xlen_t> (data, mode);
    case SYSREG_ADDR_MVENDORID : return Write_MVENDORID<Xlen_t> (data, mode);
    case SYSREG_ADDR_MARCHID : return Write_MARCHID<Xlen_t> (data, mode);
    case SYSREG_ADDR_MIMPID : return Write_MIMPID<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHARTID : return Write_MHARTID<Xlen_t> (data, mode);
    case SYSREG_ADDR_MSTATUS : return Write_MSTATUS<Xlen_t> (data, mode);
    case SYSREG_ADDR_MISA : return Write_MISA<Xlen_t> (data, mode);
    case SYSREG_ADDR_MEDELEG : return Write_MEDELEG<Xlen_t> (data, mode);
    case SYSREG_ADDR_MIDELEG : return Write_MIDELEG<Xlen_t> (data, mode);
    case SYSREG_ADDR_MIE : return Write_MIE<Xlen_t> (data, mode);
    case SYSREG_ADDR_MTVEC : return Write_MTVEC<Xlen_t> (data, mode);
    case SYSREG_ADDR_MCOUNTEREN : return Write_MCOUNTEREN<Xlen_t> (data, mode);
    case SYSREG_ADDR_MSCRATCH : return Write_MSCRATCH<Xlen_t> (data, mode);
    case SYSREG_ADDR_MEPC : return Write_MEPC<Xlen_t> (data, mode);
    case SYSREG_ADDR_MCAUSE : return Write_MCAUSE<Xlen_t> (data, mode);
    case SYSREG_ADDR_MTVAL : return Write_MTVAL<Xlen_t> (data, mode);
    case SYSREG_ADDR_MIP : return Write_MIP<Xlen_t> (data, mode);
    case SYSREG_ADDR_MBASE : return Write_MBASE<Xlen_t> (data, mode);
    case SYSREG_ADDR_MBOUND : return Write_MBOUND<Xlen_t> (data, mode);
    case SYSREG_ADDR_MIBASE : return Write_MIBASE<Xlen_t> (data, mode);
    case SYSREG_ADDR_MIBOUND : return Write_MIBOUND<Xlen_t> (data, mode);
    case SYSREG_ADDR_MDBASE : return Write_MDBASE<Xlen_t> (data, mode);
    case SYSREG_ADDR_MDBOUND : return Write_MDBOUND<Xlen_t> (data, mode);
    case SYSREG_ADDR_MCYCLE : return Write_MCYCLE<Xlen_t> (data, mode);
    case SYSREG_ADDR_MINSTRET : return Write_MINSTRET<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPMCOUNTER3 : return Write_MHPMCOUNTER3<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPMCOUNTER4 : return Write_MHPMCOUNTER4<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPMCOUNTER5 : return Write_MHPMCOUNTER5<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPMCOUNTER6 : return Write_MHPMCOUNTER6<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPMCOUNTER7 : return Write_MHPMCOUNTER7<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPMCOUNTER8 : return Write_MHPMCOUNTER8<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPMCOUNTER9 : return Write_MHPMCOUNTER9<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPMCOUNTER10 : return Write_MHPMCOUNTER10<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPMCOUNTER11 : return Write_MHPMCOUNTER11<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPMCOUNTER12 : return Write_MHPMCOUNTER12<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPMCOUNTER13 : return Write_MHPMCOUNTER13<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPMCOUNTER14 : return Write_MHPMCOUNTER14<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPMCOUNTER15 : return Write_MHPMCOUNTER15<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPMCOUNTER16 : return Write_MHPMCOUNTER16<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPMCOUNTER17 : return Write_MHPMCOUNTER17<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPMCOUNTER18 : return Write_MHPMCOUNTER18<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPMCOUNTER19 : return Write_MHPMCOUNTER19<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPMCOUNTER20 : return Write_MHPMCOUNTER20<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPMCOUNTER21 : return Write_MHPMCOUNTER21<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPMCOUNTER22 : return Write_MHPMCOUNTER22<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPMCOUNTER23 : return Write_MHPMCOUNTER23<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPMCOUNTER24 : return Write_MHPMCOUNTER24<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPMCOUNTER25 : return Write_MHPMCOUNTER25<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPMCOUNTER26 : return Write_MHPMCOUNTER26<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPMCOUNTER27 : return Write_MHPMCOUNTER27<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPMCOUNTER28 : return Write_MHPMCOUNTER28<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPMCOUNTER29 : return Write_MHPMCOUNTER29<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPMCOUNTER30 : return Write_MHPMCOUNTER30<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPMCOUNTER31 : return Write_MHPMCOUNTER31<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPEVENT3 : return Write_MHPEVENT3<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPEVENT4 : return Write_MHPEVENT4<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPEVENT5 : return Write_MHPEVENT5<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPEVENT6 : return Write_MHPEVENT6<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPEVENT7 : return Write_MHPEVENT7<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPEVENT8 : return Write_MHPEVENT8<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPEVENT9 : return Write_MHPEVENT9<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPEVENT10 : return Write_MHPEVENT10<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPEVENT11 : return Write_MHPEVENT11<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPEVENT12 : return Write_MHPEVENT12<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPEVENT13 : return Write_MHPEVENT13<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPEVENT14 : return Write_MHPEVENT14<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPEVENT15 : return Write_MHPEVENT15<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPEVENT16 : return Write_MHPEVENT16<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPEVENT17 : return Write_MHPEVENT17<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPEVENT18 : return Write_MHPEVENT18<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPEVENT19 : return Write_MHPEVENT19<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPEVENT20 : return Write_MHPEVENT20<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPEVENT21 : return Write_MHPEVENT21<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPEVENT22 : return Write_MHPEVENT22<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPEVENT23 : return Write_MHPEVENT23<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPEVENT24 : return Write_MHPEVENT24<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPEVENT25 : return Write_MHPEVENT25<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPEVENT26 : return Write_MHPEVENT26<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPEVENT27 : return Write_MHPEVENT27<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPEVENT28 : return Write_MHPEVENT28<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPEVENT29 : return Write_MHPEVENT29<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPEVENT30 : return Write_MHPEVENT30<Xlen_t> (data, mode);
    case SYSREG_ADDR_MHPEVENT31 : return Write_MHPEVENT31<Xlen_t> (data, mode);
    case SYSREG_ADDR_STATS : return Write_STATS<Xlen_t> (data, mode);
    case SYSREG_ADDR_UARCH00 : return Write_UARCH00<Xlen_t> (data, mode);
    case SYSREG_ADDR_UARCH01 : return Write_UARCH01<Xlen_t> (data, mode);
    case SYSREG_ADDR_UARCH02 : return Write_UARCH02<Xlen_t> (data, mode);
    case SYSREG_ADDR_UARCH03 : return Write_UARCH03<Xlen_t> (data, mode);
    case SYSREG_ADDR_UARCH04 : return Write_UARCH04<Xlen_t> (data, mode);
    case SYSREG_ADDR_UARCH05 : return Write_UARCH05<Xlen_t> (data, mode);
    case SYSREG_ADDR_UARCH06 : return Write_UARCH06<Xlen_t> (data, mode);
    case SYSREG_ADDR_UARCH07 : return Write_UARCH07<Xlen_t> (data, mode);
    case SYSREG_ADDR_UARCH08 : return Write_UARCH08<Xlen_t> (data, mode);
    case SYSREG_ADDR_UARCH09 : return Write_UARCH09<Xlen_t> (data, mode);
    case SYSREG_ADDR_UARCH10 : return Write_UARCH10<Xlen_t> (data, mode);
    case SYSREG_ADDR_UARCH11 : return Write_UARCH11<Xlen_t> (data, mode);
    case SYSREG_ADDR_UARCH12 : return Write_UARCH12<Xlen_t> (data, mode);
    case SYSREG_ADDR_UARCH13 : return Write_UARCH13<Xlen_t> (data, mode);
    case SYSREG_ADDR_UARCH14 : return Write_UARCH14<Xlen_t> (data, mode);
    case SYSREG_ADDR_UARCH15 : return Write_UARCH15<Xlen_t> (data, mode);
    default : Error_CSR_Write (addr); break;
  }
  return -1;
}


void CsrEnv::Error_CSR_Read (Addr_t addr)
{
  m_pe_thread->DebugPrint ("<Error: CSR Read Address %03x is invalid.>\n", addr);
}


void CsrEnv::Error_CSR_Write (Addr_t addr)
{
  m_pe_thread->DebugPrint ("<Error: CSR Write Address %03x is invalid.>\n", addr);
}
template Word_t CsrEnv::Riscv_Read_CSR  (Addr_t addr, Word_t *data, PrivMode mode);
template Word_t CsrEnv::Riscv_Write_CSR (Addr_t addr, Word_t data,  PrivMode mode);
template DWord_t CsrEnv::Riscv_Read_CSR  (Addr_t addr, DWord_t *data, PrivMode mode);
template DWord_t CsrEnv::Riscv_Write_CSR (Addr_t addr, DWord_t data,  PrivMode mode);
template UWord_t CsrEnv::Riscv_Read_CSR  (Addr_t addr, UWord_t *data, PrivMode mode);
template UWord_t CsrEnv::Riscv_Write_CSR (Addr_t addr, UWord_t data,  PrivMode mode);
template UDWord_t CsrEnv::Riscv_Read_CSR  (Addr_t addr, UDWord_t *data, PrivMode mode);
template UDWord_t CsrEnv::Riscv_Write_CSR (Addr_t addr, UDWord_t data,  PrivMode mode);
