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


#include <string>
#include <stdint.h>
enum class PrivMode;
class RiscvPeThread;
class CsrEnv {
 private:
  RiscvPeThread *m_pe_thread;


  struct {
    uint64_t ustatus;
  } ustatus;


  struct {
    uint64_t uie;
  } uie;


  struct {
    uint64_t utvec;
  } utvec;


  struct {
    uint64_t uscratch;
  } uscratch;


  struct {
    uint64_t uepc;
  } uepc;


  struct {
    uint64_t ucause;
  } ucause;


  struct {
    uint64_t ubadaddr;
  } ubadaddr;


  struct {
    uint64_t uip;
  } uip;


  struct {
    uint64_t fflags;
  } fflags;


  struct {
    uint64_t frm;
  } frm;

  union {
    struct {
      uint64_t fflags : 5;
      uint64_t frm : 3;
      uint64_t dummy_0 : 56;
    } bit_fcsr;
    uint64_t fcsr;
  } fcsr;


  struct {
    uint64_t cycle;
  } cycle;


  struct {
    uint64_t instret;
  } instret;


  struct {
    uint64_t hpmcounter3;
  } hpmcounter3;


  struct {
    uint64_t hpmcounter4;
  } hpmcounter4;


  struct {
    uint64_t hpmcounter5;
  } hpmcounter5;


  struct {
    uint64_t hpmcounter6;
  } hpmcounter6;


  struct {
    uint64_t hpmcounter7;
  } hpmcounter7;


  struct {
    uint64_t hpmcounter8;
  } hpmcounter8;


  struct {
    uint64_t hpmcounter9;
  } hpmcounter9;


  struct {
    uint64_t hpmcounter10;
  } hpmcounter10;


  struct {
    uint64_t hpmcounter11;
  } hpmcounter11;


  struct {
    uint64_t hpmcounter12;
  } hpmcounter12;


  struct {
    uint64_t hpmcounter13;
  } hpmcounter13;


  struct {
    uint64_t hpmcounter14;
  } hpmcounter14;


  struct {
    uint64_t hpmcounter15;
  } hpmcounter15;


  struct {
    uint64_t hpmcounter16;
  } hpmcounter16;


  struct {
    uint64_t hpmcounter17;
  } hpmcounter17;


  struct {
    uint64_t hpmcounter18;
  } hpmcounter18;


  struct {
    uint64_t hpmcounter19;
  } hpmcounter19;


  struct {
    uint64_t hpmcounter20;
  } hpmcounter20;


  struct {
    uint64_t hpmcounter21;
  } hpmcounter21;


  struct {
    uint64_t hpmcounter22;
  } hpmcounter22;


  struct {
    uint64_t hpmcounter23;
  } hpmcounter23;


  struct {
    uint64_t hpmcounter24;
  } hpmcounter24;


  struct {
    uint64_t hpmcounter25;
  } hpmcounter25;


  struct {
    uint64_t hpmcounter26;
  } hpmcounter26;


  struct {
    uint64_t hpmcounter27;
  } hpmcounter27;


  struct {
    uint64_t hpmcounter28;
  } hpmcounter28;


  struct {
    uint64_t hpmcounter29;
  } hpmcounter29;


  struct {
    uint64_t hpmcounter30;
  } hpmcounter30;


  struct {
    uint64_t hpmcounterx31;
  } hpmcounter31;


  struct {
    uint64_t cycleh;
  } cycleh;


  struct {
    uint64_t timeh;
  } timeh;


  struct {
    uint64_t instreth;
  } instreth;


  struct {
    uint64_t hpmcounterh3;
  } hpmcounterh3;


  struct {
    uint64_t hpmcounterh4;
  } hpmcounterh4;


  struct {
    uint64_t hpmcounterh5;
  } hpmcounterh5;


  struct {
    uint64_t hpmcounterh6;
  } hpmcounterh6;


  struct {
    uint64_t hpmcounterh7;
  } hpmcounterh7;


  struct {
    uint64_t hpmcounterh8;
  } hpmcounterh8;


  struct {
    uint64_t hpmcounterh9;
  } hpmcounterh9;


  struct {
    uint64_t hpmcounterh10;
  } hpmcounterh10;


  struct {
    uint64_t hpmcounterh11;
  } hpmcounterh11;


  struct {
    uint64_t hpmcounterh12;
  } hpmcounterh12;


  struct {
    uint64_t hpmcounterh13;
  } hpmcounterh13;


  struct {
    uint64_t hpmcounterh14;
  } hpmcounterh14;


  struct {
    uint64_t hpmcounterh15;
  } hpmcounterh15;


  struct {
    uint64_t hpmcounterh16;
  } hpmcounterh16;


  struct {
    uint64_t hpmcounterh17;
  } hpmcounterh17;


  struct {
    uint64_t hpmcounterh18;
  } hpmcounterh18;


  struct {
    uint64_t hpmcounterh19;
  } hpmcounterh19;


  struct {
    uint64_t hpmcounterh20;
  } hpmcounterh20;


  struct {
    uint64_t hpmcounterh21;
  } hpmcounterh21;


  struct {
    uint64_t hpmcounterh22;
  } hpmcounterh22;


  struct {
    uint64_t hpmcounterh23;
  } hpmcounterh23;


  struct {
    uint64_t hpmcounterh24;
  } hpmcounterh24;


  struct {
    uint64_t hpmcounterh25;
  } hpmcounterh25;


  struct {
    uint64_t hpmcounterh26;
  } hpmcounterh26;


  struct {
    uint64_t hpmcounterh27;
  } hpmcounterh27;


  struct {
    uint64_t hpmcounterh28;
  } hpmcounterh28;


  struct {
    uint64_t hpmcounterh29;
  } hpmcounterh29;


  struct {
    uint64_t hpmcounterh30;
  } hpmcounterh30;


  struct {
    uint64_t hpmcounterh31;
  } hpmcounterh31;

  union {
    struct {
      uint64_t UIE : 1;
      uint64_t SIE : 1;
      uint64_t dummy_5 : 2;
      uint64_t UPIE : 1;
      uint64_t SPIE : 1;
      uint64_t dummy_4 : 2;
      uint64_t SPP : 1;
      uint64_t dummy_3 : 4;
      uint64_t FS : 2;
      uint64_t XS : 2;
      uint64_t dummy_2 : 1;
      uint64_t SUM : 1;
      uint64_t MXR : 1;
      uint64_t dummy_1 : 12;
      uint64_t UXL : 2;
      uint64_t dummy_0 : 29;
      uint64_t SD : 1;
    } bit_sstatus;
    uint64_t sstatus;
  } sstatus;


  struct {
    uint64_t sedeleg;
  } sedeleg;


  struct {
    uint64_t sideleg;
  } sideleg;


  struct {
    uint64_t sie;
  } sie;


  struct {
    uint64_t stvec;
  } stvec;

  union {
    struct {
      uint64_t CY : 1;
      uint64_t TM : 1;
      uint64_t IR : 1;
      uint64_t HPM3 : 1;
      uint64_t HPM4 : 1;
      uint64_t HPM5 : 1;
      uint64_t HPM6 : 1;
      uint64_t HPM7 : 1;
      uint64_t HPM8 : 1;
      uint64_t HPM9 : 1;
      uint64_t HPM10 : 1;
      uint64_t HPM11 : 1;
      uint64_t HPM12 : 1;
      uint64_t HPM13 : 1;
      uint64_t HPM14 : 1;
      uint64_t HPM15 : 1;
      uint64_t HPM16 : 1;
      uint64_t HPM17 : 1;
      uint64_t HPM18 : 1;
      uint64_t HPM19 : 1;
      uint64_t HPM20 : 1;
      uint64_t HPM21 : 1;
      uint64_t HPM22 : 1;
      uint64_t HPM23 : 1;
      uint64_t HPM24 : 1;
      uint64_t HPM25 : 1;
      uint64_t HPM26 : 1;
      uint64_t HPM27 : 1;
      uint64_t HPM28 : 1;
      uint64_t HPM29 : 1;
      uint64_t HPM30 : 1;
      uint64_t HPM31 : 1;
      uint64_t dummy_0 : 32;
    } bit_scounteren;
    uint64_t scounteren;
  } scounteren;


  struct {
    uint64_t sscratch;
  } sscratch;


  struct {
    uint64_t sepc;
  } sepc;


  struct {
    uint64_t scause;
  } scause;


  struct {
    uint64_t stval;
  } stval;


  struct {
    uint64_t sip;
  } sip;

  union {
    struct {
      uint64_t PPN : 22;
      uint64_t ASID : 38;
      uint64_t MODE : 4;
    } bit_satp;
    uint64_t satp;
  } satp;


  struct {
    uint64_t hstatus;
  } hstatus;


  struct {
    uint64_t hedeleg;
  } hedeleg;


  struct {
    uint64_t hideleg;
  } hideleg;


  struct {
    uint64_t hie;
  } hie;


  struct {
    uint64_t htvec;
  } htvec;


  struct {
    uint64_t hscratch;
  } hscratch;


  struct {
    uint64_t hepc;
  } hepc;


  struct {
    uint64_t hcause;
  } hcause;


  struct {
    uint64_t hbadaddr;
  } hbadaddr;


  struct {
    uint64_t hip;
  } hip;


  struct {
    uint64_t hptbr;
  } hptbr;


  struct {
    uint64_t MVendorID;
  } mvendorid;


  struct {
    uint64_t MArchID;
  } marchid;

  union {
    struct {
      uint64_t Source : 16;
      uint64_t Implementation : 48;
    } bit_mimpid;
    uint64_t mimpid;
  } mimpid;


  struct {
    uint64_t Hart_ID;
  } mhartid;

  union {
    struct {
      uint64_t UIE : 1;
      uint64_t SIE : 1;
      uint64_t dummy_4 : 1;
      uint64_t MIE : 1;
      uint64_t UPIE : 1;
      uint64_t SPIE : 1;
      uint64_t dummy_3 : 1;
      uint64_t MPIE : 1;
      uint64_t SPP : 1;
      uint64_t dummy_2 : 2;
      uint64_t MPP : 2;
      uint64_t FS : 2;
      uint64_t XS : 2;
      uint64_t MPRV : 1;
      uint64_t SUM : 1;
      uint64_t MXR : 1;
      uint64_t TVM : 1;
      uint64_t TW : 1;
      uint64_t TSR : 1;
      uint64_t dummy_1 : 9;
      uint64_t UXL : 2;
      uint64_t SXL : 2;
      uint64_t dummy_0 : 27;
      uint64_t SD : 1;
    } bit_mstatus;
    uint64_t mstatus;
  } mstatus;

  union {
    struct {
      uint64_t Extensions : 26;
      uint64_t dummy_0 : 36;
      uint64_t MXL : 2;
    } bit_misa;
    uint64_t misa;
  } misa;


  struct {
    uint64_t medeleg;
  } medeleg;


  struct {
    uint64_t mideleg;
  } mideleg;

  union {
    struct {
      uint64_t USIE : 1;
      uint64_t SSIE : 1;
      uint64_t dummy_3 : 1;
      uint64_t MSIE : 1;
      uint64_t UTIE : 1;
      uint64_t STIE : 1;
      uint64_t dummy_2 : 1;
      uint64_t MTIE : 1;
      uint64_t UEIE : 1;
      uint64_t SEIE : 1;
      uint64_t dummy_1 : 1;
      uint64_t MEIE : 1;
      uint64_t dummy_0 : 52;
    } bit_mie;
    uint64_t mie;
  } mie;

  union {
    struct {
      uint64_t dummy_0 : 2;
      uint64_t Trap_Vector_Base_Address : 62;
    } bit_mtvec;
    uint64_t mtvec;
  } mtvec;

  union {
    struct {
      uint64_t CY : 1;
      uint64_t TM : 1;
      uint64_t IR : 1;
      uint64_t HPM3 : 1;
      uint64_t HPM4 : 1;
      uint64_t HPM5 : 1;
      uint64_t HPM6 : 1;
      uint64_t HPM7 : 1;
      uint64_t HPM8 : 1;
      uint64_t HPM9 : 1;
      uint64_t HPM10 : 1;
      uint64_t HPM11 : 1;
      uint64_t HPM12 : 1;
      uint64_t HPM13 : 1;
      uint64_t HPM14 : 1;
      uint64_t HPM15 : 1;
      uint64_t HPM16 : 1;
      uint64_t HPM17 : 1;
      uint64_t HPM18 : 1;
      uint64_t HPM19 : 1;
      uint64_t HPM20 : 1;
      uint64_t HPM21 : 1;
      uint64_t HPM22 : 1;
      uint64_t HPM23 : 1;
      uint64_t HPM24 : 1;
      uint64_t HPM25 : 1;
      uint64_t HPM26 : 1;
      uint64_t HPM27 : 1;
      uint64_t HPM28 : 1;
      uint64_t HPM29 : 1;
      uint64_t HPM30 : 1;
      uint64_t HPM31 : 1;
      uint64_t dummy_0 : 32;
    } bit_mcounteren;
    uint64_t mcounteren;
  } mcounteren;


  struct {
    uint64_t mscratch;
  } mscratch;


  struct {
    uint64_t mepc;
  } mepc;

  union {
    struct {
      uint64_t Exception_Code : 4;
      uint64_t dummy_0 : 59;
      uint64_t Interrupt : 1;
    } bit_mcause;
    uint64_t mcause;
  } mcause;


  struct {
    uint64_t mtval;
  } mtval;

  union {
    struct {
      uint64_t USIP : 1;
      uint64_t SSIP : 1;
      uint64_t dummy_3 : 1;
      uint64_t MSIP : 1;
      uint64_t UTIP : 1;
      uint64_t STIP : 1;
      uint64_t dummy_2 : 1;
      uint64_t MTIP : 1;
      uint64_t UEIP : 1;
      uint64_t SEIP : 1;
      uint64_t dummy_1 : 1;
      uint64_t MEIP : 1;
      uint64_t dummy_0 : 52;
    } bit_mip;
    uint64_t mip;
  } mip;


  struct {
    uint64_t mbase;
  } mbase;


  struct {
    uint64_t mbound;
  } mbound;


  struct {
    uint64_t mibase;
  } mibase;


  struct {
    uint64_t mibound;
  } mibound;


  struct {
    uint64_t mdbase;
  } mdbase;


  struct {
    uint64_t mdbound;
  } mdbound;


  struct {
    uint64_t mcycle;
  } mcycle;


  struct {
    uint64_t minstret;
  } minstret;


  struct {
    uint64_t mhpmcounter3;
  } mhpmcounter3;


  struct {
    uint64_t mhpmcounter4;
  } mhpmcounter4;


  struct {
    uint64_t mhpmcounter5;
  } mhpmcounter5;


  struct {
    uint64_t mhpmcounter6;
  } mhpmcounter6;


  struct {
    uint64_t mhpmcounter7;
  } mhpmcounter7;


  struct {
    uint64_t mhpmcounter8;
  } mhpmcounter8;


  struct {
    uint64_t mhpmcounter9;
  } mhpmcounter9;


  struct {
    uint64_t mhpmcounter10;
  } mhpmcounter10;


  struct {
    uint64_t mhpmcounter11;
  } mhpmcounter11;


  struct {
    uint64_t mhpmcounter12;
  } mhpmcounter12;


  struct {
    uint64_t mhpmcounter13;
  } mhpmcounter13;


  struct {
    uint64_t mhpmcounter14;
  } mhpmcounter14;


  struct {
    uint64_t mhpmcounter15;
  } mhpmcounter15;


  struct {
    uint64_t mhpmcounter16;
  } mhpmcounter16;


  struct {
    uint64_t mhpmcounter17;
  } mhpmcounter17;


  struct {
    uint64_t mhpmcounter18;
  } mhpmcounter18;


  struct {
    uint64_t mhpmcounter19;
  } mhpmcounter19;


  struct {
    uint64_t mhpmcounter20;
  } mhpmcounter20;


  struct {
    uint64_t mhpmcounter21;
  } mhpmcounter21;


  struct {
    uint64_t mhpmcounter22;
  } mhpmcounter22;


  struct {
    uint64_t mhpmcounter23;
  } mhpmcounter23;


  struct {
    uint64_t mhpmcounter24;
  } mhpmcounter24;


  struct {
    uint64_t mhpmcounter25;
  } mhpmcounter25;


  struct {
    uint64_t mhpmcounter26;
  } mhpmcounter26;


  struct {
    uint64_t mhpmcounter27;
  } mhpmcounter27;


  struct {
    uint64_t mhpmcounter28;
  } mhpmcounter28;


  struct {
    uint64_t mhpmcounter29;
  } mhpmcounter29;


  struct {
    uint64_t mhpmcounter30;
  } mhpmcounter30;


  struct {
    uint64_t mhpmcounter31;
  } mhpmcounter31;


  struct {
    uint64_t mhpevent3;
  } mhpevent3;


  struct {
    uint64_t mhpevent4;
  } mhpevent4;


  struct {
    uint64_t mhpevent5;
  } mhpevent5;


  struct {
    uint64_t mhpevent6;
  } mhpevent6;


  struct {
    uint64_t mhpevent7;
  } mhpevent7;


  struct {
    uint64_t mhpevent8;
  } mhpevent8;


  struct {
    uint64_t mhpevent9;
  } mhpevent9;


  struct {
    uint64_t mhpevent10;
  } mhpevent10;


  struct {
    uint64_t mhpevent11;
  } mhpevent11;


  struct {
    uint64_t mhpevent12;
  } mhpevent12;


  struct {
    uint64_t mhpevent13;
  } mhpevent13;


  struct {
    uint64_t mhpevent14;
  } mhpevent14;


  struct {
    uint64_t mhpevent15;
  } mhpevent15;


  struct {
    uint64_t mhpevent16;
  } mhpevent16;


  struct {
    uint64_t mhpevent17;
  } mhpevent17;


  struct {
    uint64_t mhpevent18;
  } mhpevent18;


  struct {
    uint64_t mhpevent19;
  } mhpevent19;


  struct {
    uint64_t mhpevent20;
  } mhpevent20;


  struct {
    uint64_t mhpevent21;
  } mhpevent21;


  struct {
    uint64_t mhpevent22;
  } mhpevent22;


  struct {
    uint64_t mhpevent23;
  } mhpevent23;


  struct {
    uint64_t mhpevent24;
  } mhpevent24;


  struct {
    uint64_t mhpevent25;
  } mhpevent25;


  struct {
    uint64_t mhpevent26;
  } mhpevent26;


  struct {
    uint64_t mhpevent27;
  } mhpevent27;


  struct {
    uint64_t mhpevent28;
  } mhpevent28;


  struct {
    uint64_t mhpevent29;
  } mhpevent29;


  struct {
    uint64_t mhpevent30;
  } mhpevent30;


  struct {
    uint64_t mhpevent31;
  } mhpevent31;


  struct {
    uint64_t stats;
  } stats;


  struct {
    uint64_t uarch00;
  } uarch00;


  struct {
    uint64_t uarch01;
  } uarch01;


  struct {
    uint64_t uarch02;
  } uarch02;


  struct {
    uint64_t uarch03;
  } uarch03;


  struct {
    uint64_t uarch04;
  } uarch04;


  struct {
    uint64_t uarch05;
  } uarch05;


  struct {
    uint64_t uarch06;
  } uarch06;


  struct {
    uint64_t uarch07;
  } uarch07;


  struct {
    uint64_t uarch08;
  } uarch08;


  struct {
    uint64_t uarch09;
  } uarch09;


  struct {
    uint64_t uarch10;
  } uarch10;


  struct {
    uint64_t uarch11;
  } uarch11;


  struct {
    uint64_t uarch12;
  } uarch12;


  struct {
    uint64_t uarch13;
  } uarch13;


  struct {
    uint64_t uarch14;
  } uarch14;


  struct {
    uint64_t uarch15;
  } uarch15;
  template <typename Xlen_t> Xlen_t Read_USTATUS (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_UIE (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_UTVEC (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_USCRATCH (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_UEPC (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_UCAUSE (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_UBADADDR (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_UIP (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_FFLAGS (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_FRM (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_FCSR (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_CYCLE (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_INSTRET (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_HPMCOUNTER3 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_HPMCOUNTER4 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_HPMCOUNTER5 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_HPMCOUNTER6 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_HPMCOUNTER7 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_HPMCOUNTER8 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_HPMCOUNTER9 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_HPMCOUNTER10 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_HPMCOUNTER11 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_HPMCOUNTER12 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_HPMCOUNTER13 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_HPMCOUNTER14 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_HPMCOUNTER15 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_HPMCOUNTER16 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_HPMCOUNTER17 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_HPMCOUNTER18 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_HPMCOUNTER19 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_HPMCOUNTER20 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_HPMCOUNTER21 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_HPMCOUNTER22 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_HPMCOUNTER23 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_HPMCOUNTER24 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_HPMCOUNTER25 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_HPMCOUNTER26 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_HPMCOUNTER27 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_HPMCOUNTER28 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_HPMCOUNTER29 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_HPMCOUNTER30 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_HPMCOUNTER31 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_CYCLEH (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_TIMEH (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_INSTRETH (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_HPMCOUNTERH3 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_HPMCOUNTERH4 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_HPMCOUNTERH5 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_HPMCOUNTERH6 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_HPMCOUNTERH7 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_HPMCOUNTERH8 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_HPMCOUNTERH9 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_HPMCOUNTERH10 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_HPMCOUNTERH11 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_HPMCOUNTERH12 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_HPMCOUNTERH13 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_HPMCOUNTERH14 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_HPMCOUNTERH15 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_HPMCOUNTERH16 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_HPMCOUNTERH17 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_HPMCOUNTERH18 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_HPMCOUNTERH19 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_HPMCOUNTERH20 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_HPMCOUNTERH21 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_HPMCOUNTERH22 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_HPMCOUNTERH23 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_HPMCOUNTERH24 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_HPMCOUNTERH25 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_HPMCOUNTERH26 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_HPMCOUNTERH27 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_HPMCOUNTERH28 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_HPMCOUNTERH29 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_HPMCOUNTERH30 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_HPMCOUNTERH31 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_SSTATUS (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_SEDELEG (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_SIDELEG (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_SIE (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_STVEC (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_SCOUNTEREN (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_SSCRATCH (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_SEPC (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_SCAUSE (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_STVAL (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_SIP (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_SATP (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_HSTATUS (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_HEDELEG (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_HIDELEG (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_HIE (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_HTVEC (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_HSCRATCH (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_HEPC (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_HCAUSE (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_HBADADDR (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_HIP (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_HPTBR (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MVENDORID (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MARCHID (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MIMPID (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MHARTID (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MSTATUS (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MISA (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MEDELEG (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MIDELEG (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MIE (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MTVEC (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MCOUNTEREN (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MSCRATCH (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MEPC (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MCAUSE (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MTVAL (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MIP (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MBASE (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MBOUND (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MIBASE (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MIBOUND (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MDBASE (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MDBOUND (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MCYCLE (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MINSTRET (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MHPMCOUNTER3 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MHPMCOUNTER4 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MHPMCOUNTER5 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MHPMCOUNTER6 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MHPMCOUNTER7 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MHPMCOUNTER8 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MHPMCOUNTER9 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MHPMCOUNTER10 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MHPMCOUNTER11 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MHPMCOUNTER12 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MHPMCOUNTER13 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MHPMCOUNTER14 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MHPMCOUNTER15 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MHPMCOUNTER16 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MHPMCOUNTER17 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MHPMCOUNTER18 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MHPMCOUNTER19 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MHPMCOUNTER20 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MHPMCOUNTER21 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MHPMCOUNTER22 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MHPMCOUNTER23 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MHPMCOUNTER24 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MHPMCOUNTER25 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MHPMCOUNTER26 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MHPMCOUNTER27 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MHPMCOUNTER28 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MHPMCOUNTER29 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MHPMCOUNTER30 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MHPMCOUNTER31 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MHPEVENT3 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MHPEVENT4 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MHPEVENT5 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MHPEVENT6 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MHPEVENT7 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MHPEVENT8 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MHPEVENT9 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MHPEVENT10 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MHPEVENT11 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MHPEVENT12 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MHPEVENT13 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MHPEVENT14 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MHPEVENT15 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MHPEVENT16 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MHPEVENT17 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MHPEVENT18 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MHPEVENT19 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MHPEVENT20 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MHPEVENT21 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MHPEVENT22 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MHPEVENT23 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MHPEVENT24 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MHPEVENT25 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MHPEVENT26 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MHPEVENT27 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MHPEVENT28 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MHPEVENT29 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MHPEVENT30 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_MHPEVENT31 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_STATS (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_UARCH00 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_UARCH01 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_UARCH02 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_UARCH03 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_UARCH04 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_UARCH05 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_UARCH06 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_UARCH07 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_UARCH08 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_UARCH09 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_UARCH10 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_UARCH11 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_UARCH12 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_UARCH13 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_UARCH14 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Read_UARCH15 (Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_USTATUS (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_UIE (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_UTVEC (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_USCRATCH (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_UEPC (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_UCAUSE (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_UBADADDR (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_UIP (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_FFLAGS (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_FRM (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_FCSR (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_CYCLE (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_INSTRET (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_HPMCOUNTER3 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_HPMCOUNTER4 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_HPMCOUNTER5 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_HPMCOUNTER6 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_HPMCOUNTER7 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_HPMCOUNTER8 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_HPMCOUNTER9 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_HPMCOUNTER10 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_HPMCOUNTER11 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_HPMCOUNTER12 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_HPMCOUNTER13 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_HPMCOUNTER14 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_HPMCOUNTER15 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_HPMCOUNTER16 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_HPMCOUNTER17 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_HPMCOUNTER18 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_HPMCOUNTER19 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_HPMCOUNTER20 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_HPMCOUNTER21 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_HPMCOUNTER22 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_HPMCOUNTER23 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_HPMCOUNTER24 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_HPMCOUNTER25 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_HPMCOUNTER26 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_HPMCOUNTER27 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_HPMCOUNTER28 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_HPMCOUNTER29 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_HPMCOUNTER30 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_HPMCOUNTER31 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_CYCLEH (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_TIMEH (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_INSTRETH (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_HPMCOUNTERH3 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_HPMCOUNTERH4 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_HPMCOUNTERH5 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_HPMCOUNTERH6 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_HPMCOUNTERH7 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_HPMCOUNTERH8 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_HPMCOUNTERH9 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_HPMCOUNTERH10 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_HPMCOUNTERH11 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_HPMCOUNTERH12 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_HPMCOUNTERH13 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_HPMCOUNTERH14 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_HPMCOUNTERH15 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_HPMCOUNTERH16 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_HPMCOUNTERH17 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_HPMCOUNTERH18 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_HPMCOUNTERH19 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_HPMCOUNTERH20 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_HPMCOUNTERH21 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_HPMCOUNTERH22 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_HPMCOUNTERH23 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_HPMCOUNTERH24 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_HPMCOUNTERH25 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_HPMCOUNTERH26 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_HPMCOUNTERH27 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_HPMCOUNTERH28 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_HPMCOUNTERH29 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_HPMCOUNTERH30 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_HPMCOUNTERH31 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_SSTATUS (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_SEDELEG (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_SIDELEG (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_SIE (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_STVEC (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_SCOUNTEREN (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_SSCRATCH (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_SEPC (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_SCAUSE (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_STVAL (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_SIP (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_SATP (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_HSTATUS (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_HEDELEG (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_HIDELEG (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_HIE (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_HTVEC (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_HSCRATCH (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_HEPC (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_HCAUSE (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_HBADADDR (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_HIP (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_HPTBR (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MVENDORID (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MARCHID (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MIMPID (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MHARTID (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MSTATUS (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MISA (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MEDELEG (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MIDELEG (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MIE (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MTVEC (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MCOUNTEREN (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MSCRATCH (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MEPC (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MCAUSE (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MTVAL (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MIP (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MBASE (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MBOUND (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MIBASE (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MIBOUND (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MDBASE (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MDBOUND (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MCYCLE (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MINSTRET (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MHPMCOUNTER3 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MHPMCOUNTER4 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MHPMCOUNTER5 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MHPMCOUNTER6 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MHPMCOUNTER7 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MHPMCOUNTER8 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MHPMCOUNTER9 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MHPMCOUNTER10 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MHPMCOUNTER11 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MHPMCOUNTER12 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MHPMCOUNTER13 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MHPMCOUNTER14 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MHPMCOUNTER15 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MHPMCOUNTER16 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MHPMCOUNTER17 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MHPMCOUNTER18 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MHPMCOUNTER19 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MHPMCOUNTER20 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MHPMCOUNTER21 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MHPMCOUNTER22 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MHPMCOUNTER23 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MHPMCOUNTER24 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MHPMCOUNTER25 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MHPMCOUNTER26 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MHPMCOUNTER27 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MHPMCOUNTER28 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MHPMCOUNTER29 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MHPMCOUNTER30 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MHPMCOUNTER31 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MHPEVENT3 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MHPEVENT4 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MHPEVENT5 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MHPEVENT6 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MHPEVENT7 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MHPEVENT8 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MHPEVENT9 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MHPEVENT10 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MHPEVENT11 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MHPEVENT12 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MHPEVENT13 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MHPEVENT14 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MHPEVENT15 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MHPEVENT16 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MHPEVENT17 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MHPEVENT18 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MHPEVENT19 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MHPEVENT20 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MHPEVENT21 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MHPEVENT22 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MHPEVENT23 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MHPEVENT24 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MHPEVENT25 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MHPEVENT26 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MHPEVENT27 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MHPEVENT28 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MHPEVENT29 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MHPEVENT30 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_MHPEVENT31 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_STATS (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_UARCH00 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_UARCH01 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_UARCH02 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_UARCH03 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_UARCH04 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_UARCH05 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_UARCH06 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_UARCH07 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_UARCH08 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_UARCH09 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_UARCH10 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_UARCH11 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_UARCH12 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_UARCH13 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_UARCH14 (Xlen_t data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Write_UARCH15 (Xlen_t data, PrivMode mode);
public:

  CsrEnv (RiscvPeThread *env);
  std::string GetCSRName (Addr_t addr);
  template <typename Xlen_t> Xlen_t Riscv_Read_CSR  (Addr_t addr, Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t Riscv_Write_CSR (Addr_t addr, Xlen_t data,  PrivMode mode);
  void Error_CSR_Read (Addr_t addr);
  void Error_CSR_Write (Addr_t addr);
};
#define SYSREG_ADDR_USTATUS 0x000
#define SYSREG_ADDR_UIE 0x004
#define SYSREG_ADDR_UTVEC 0x005
#define SYSREG_ADDR_USCRATCH 0x040
#define SYSREG_ADDR_UEPC 0x041
#define SYSREG_ADDR_UCAUSE 0x042
#define SYSREG_ADDR_UBADADDR 0x043
#define SYSREG_ADDR_UIP 0x044
#define SYSREG_ADDR_FFLAGS 0x001
#define SYSREG_ADDR_FRM 0x002
#define SYSREG_ADDR_FCSR 0x003
#define SYSREG_ADDR_CYCLE 0xc00
#define SYSREG_ADDR_INSTRET 0xc02
#define SYSREG_ADDR_HPMCOUNTER3 0xc03
#define SYSREG_ADDR_HPMCOUNTER4 0xc04
#define SYSREG_ADDR_HPMCOUNTER5 0xc05
#define SYSREG_ADDR_HPMCOUNTER6 0xc06
#define SYSREG_ADDR_HPMCOUNTER7 0xc07
#define SYSREG_ADDR_HPMCOUNTER8 0xc08
#define SYSREG_ADDR_HPMCOUNTER9 0xc09
#define SYSREG_ADDR_HPMCOUNTER10 0xc0a
#define SYSREG_ADDR_HPMCOUNTER11 0xc0b
#define SYSREG_ADDR_HPMCOUNTER12 0xc0c
#define SYSREG_ADDR_HPMCOUNTER13 0xc0d
#define SYSREG_ADDR_HPMCOUNTER14 0xc0e
#define SYSREG_ADDR_HPMCOUNTER15 0xc0f
#define SYSREG_ADDR_HPMCOUNTER16 0xc10
#define SYSREG_ADDR_HPMCOUNTER17 0xc11
#define SYSREG_ADDR_HPMCOUNTER18 0xc12
#define SYSREG_ADDR_HPMCOUNTER19 0xc13
#define SYSREG_ADDR_HPMCOUNTER20 0xc14
#define SYSREG_ADDR_HPMCOUNTER21 0xc15
#define SYSREG_ADDR_HPMCOUNTER22 0xc16
#define SYSREG_ADDR_HPMCOUNTER23 0xc17
#define SYSREG_ADDR_HPMCOUNTER24 0xc18
#define SYSREG_ADDR_HPMCOUNTER25 0xc19
#define SYSREG_ADDR_HPMCOUNTER26 0xc1a
#define SYSREG_ADDR_HPMCOUNTER27 0xc1b
#define SYSREG_ADDR_HPMCOUNTER28 0xc1c
#define SYSREG_ADDR_HPMCOUNTER29 0xc1d
#define SYSREG_ADDR_HPMCOUNTER30 0xc1e
#define SYSREG_ADDR_HPMCOUNTER31 0xc1f
#define SYSREG_ADDR_CYCLEH 0xc80
#define SYSREG_ADDR_TIMEH 0xc81
#define SYSREG_ADDR_INSTRETH 0xc82
#define SYSREG_ADDR_HPMCOUNTERH3 0xc83
#define SYSREG_ADDR_HPMCOUNTERH4 0xc84
#define SYSREG_ADDR_HPMCOUNTERH5 0xc85
#define SYSREG_ADDR_HPMCOUNTERH6 0xc86
#define SYSREG_ADDR_HPMCOUNTERH7 0xc87
#define SYSREG_ADDR_HPMCOUNTERH8 0xc88
#define SYSREG_ADDR_HPMCOUNTERH9 0xc89
#define SYSREG_ADDR_HPMCOUNTERH10 0xc8a
#define SYSREG_ADDR_HPMCOUNTERH11 0xc8b
#define SYSREG_ADDR_HPMCOUNTERH12 0xc8c
#define SYSREG_ADDR_HPMCOUNTERH13 0xc8d
#define SYSREG_ADDR_HPMCOUNTERH14 0xc8e
#define SYSREG_ADDR_HPMCOUNTERH15 0xc8f
#define SYSREG_ADDR_HPMCOUNTERH16 0xc90
#define SYSREG_ADDR_HPMCOUNTERH17 0xc91
#define SYSREG_ADDR_HPMCOUNTERH18 0xc92
#define SYSREG_ADDR_HPMCOUNTERH19 0xc93
#define SYSREG_ADDR_HPMCOUNTERH20 0xc94
#define SYSREG_ADDR_HPMCOUNTERH21 0xc95
#define SYSREG_ADDR_HPMCOUNTERH22 0xc96
#define SYSREG_ADDR_HPMCOUNTERH23 0xc97
#define SYSREG_ADDR_HPMCOUNTERH24 0xc98
#define SYSREG_ADDR_HPMCOUNTERH25 0xc99
#define SYSREG_ADDR_HPMCOUNTERH26 0xc9a
#define SYSREG_ADDR_HPMCOUNTERH27 0xc9b
#define SYSREG_ADDR_HPMCOUNTERH28 0xc9c
#define SYSREG_ADDR_HPMCOUNTERH29 0xc9d
#define SYSREG_ADDR_HPMCOUNTERH30 0xc9e
#define SYSREG_ADDR_HPMCOUNTERH31 0xc9f
#define SYSREG_ADDR_SSTATUS 0x100
#define SYSREG_ADDR_SEDELEG 0x102
#define SYSREG_ADDR_SIDELEG 0x103
#define SYSREG_ADDR_SIE 0x104
#define SYSREG_ADDR_STVEC 0x105
#define SYSREG_ADDR_SCOUNTEREN 0x106
#define SYSREG_ADDR_SSCRATCH 0x140
#define SYSREG_ADDR_SEPC 0x141
#define SYSREG_ADDR_SCAUSE 0x142
#define SYSREG_ADDR_STVAL 0x143
#define SYSREG_ADDR_SIP 0x144
#define SYSREG_ADDR_SATP 0x180
#define SYSREG_ADDR_HSTATUS 0x200
#define SYSREG_ADDR_HEDELEG 0x202
#define SYSREG_ADDR_HIDELEG 0x203
#define SYSREG_ADDR_HIE 0x204
#define SYSREG_ADDR_HTVEC 0x205
#define SYSREG_ADDR_HSCRATCH 0x240
#define SYSREG_ADDR_HEPC 0x241
#define SYSREG_ADDR_HCAUSE 0x242
#define SYSREG_ADDR_HBADADDR 0x243
#define SYSREG_ADDR_HIP 0x244
#define SYSREG_ADDR_HPTBR 0x280
#define SYSREG_ADDR_MVENDORID 0xf11
#define SYSREG_ADDR_MARCHID 0xf12
#define SYSREG_ADDR_MIMPID 0xf13
#define SYSREG_ADDR_MHARTID 0xf14
#define SYSREG_ADDR_MSTATUS 0x300
#define SYSREG_ADDR_MISA 0x301
#define SYSREG_ADDR_MEDELEG 0x302
#define SYSREG_ADDR_MIDELEG 0x303
#define SYSREG_ADDR_MIE 0x304
#define SYSREG_ADDR_MTVEC 0x305
#define SYSREG_ADDR_MCOUNTEREN 0x306
#define SYSREG_ADDR_MSCRATCH 0x340
#define SYSREG_ADDR_MEPC 0x341
#define SYSREG_ADDR_MCAUSE 0x342
#define SYSREG_ADDR_MTVAL 0x343
#define SYSREG_ADDR_MIP 0x344
#define SYSREG_ADDR_MBASE 0x380
#define SYSREG_ADDR_MBOUND 0x381
#define SYSREG_ADDR_MIBASE 0x382
#define SYSREG_ADDR_MIBOUND 0x383
#define SYSREG_ADDR_MDBASE 0x384
#define SYSREG_ADDR_MDBOUND 0x385
#define SYSREG_ADDR_MCYCLE 0xb00
#define SYSREG_ADDR_MINSTRET 0xb02
#define SYSREG_ADDR_MHPMCOUNTER3 0xb03
#define SYSREG_ADDR_MHPMCOUNTER4 0xb04
#define SYSREG_ADDR_MHPMCOUNTER5 0xb05
#define SYSREG_ADDR_MHPMCOUNTER6 0xb06
#define SYSREG_ADDR_MHPMCOUNTER7 0xb07
#define SYSREG_ADDR_MHPMCOUNTER8 0xb08
#define SYSREG_ADDR_MHPMCOUNTER9 0xb09
#define SYSREG_ADDR_MHPMCOUNTER10 0xb0a
#define SYSREG_ADDR_MHPMCOUNTER11 0xb0b
#define SYSREG_ADDR_MHPMCOUNTER12 0xb0c
#define SYSREG_ADDR_MHPMCOUNTER13 0xb0d
#define SYSREG_ADDR_MHPMCOUNTER14 0xb0e
#define SYSREG_ADDR_MHPMCOUNTER15 0xb0f
#define SYSREG_ADDR_MHPMCOUNTER16 0xb10
#define SYSREG_ADDR_MHPMCOUNTER17 0xb11
#define SYSREG_ADDR_MHPMCOUNTER18 0xb12
#define SYSREG_ADDR_MHPMCOUNTER19 0xb13
#define SYSREG_ADDR_MHPMCOUNTER20 0xb14
#define SYSREG_ADDR_MHPMCOUNTER21 0xb15
#define SYSREG_ADDR_MHPMCOUNTER22 0xb16
#define SYSREG_ADDR_MHPMCOUNTER23 0xb17
#define SYSREG_ADDR_MHPMCOUNTER24 0xb18
#define SYSREG_ADDR_MHPMCOUNTER25 0xb19
#define SYSREG_ADDR_MHPMCOUNTER26 0xb1a
#define SYSREG_ADDR_MHPMCOUNTER27 0xb1b
#define SYSREG_ADDR_MHPMCOUNTER28 0xb1c
#define SYSREG_ADDR_MHPMCOUNTER29 0xb1d
#define SYSREG_ADDR_MHPMCOUNTER30 0xb1e
#define SYSREG_ADDR_MHPMCOUNTER31 0xb1f
#define SYSREG_ADDR_MHPEVENT3 0x323
#define SYSREG_ADDR_MHPEVENT4 0x324
#define SYSREG_ADDR_MHPEVENT5 0x325
#define SYSREG_ADDR_MHPEVENT6 0x326
#define SYSREG_ADDR_MHPEVENT7 0x327
#define SYSREG_ADDR_MHPEVENT8 0x328
#define SYSREG_ADDR_MHPEVENT9 0x329
#define SYSREG_ADDR_MHPEVENT10 0x32a
#define SYSREG_ADDR_MHPEVENT11 0x32b
#define SYSREG_ADDR_MHPEVENT12 0x32c
#define SYSREG_ADDR_MHPEVENT13 0x32d
#define SYSREG_ADDR_MHPEVENT14 0x32e
#define SYSREG_ADDR_MHPEVENT15 0x32f
#define SYSREG_ADDR_MHPEVENT16 0x330
#define SYSREG_ADDR_MHPEVENT17 0x331
#define SYSREG_ADDR_MHPEVENT18 0x332
#define SYSREG_ADDR_MHPEVENT19 0x333
#define SYSREG_ADDR_MHPEVENT20 0x334
#define SYSREG_ADDR_MHPEVENT21 0x335
#define SYSREG_ADDR_MHPEVENT22 0x336
#define SYSREG_ADDR_MHPEVENT23 0x337
#define SYSREG_ADDR_MHPEVENT24 0x338
#define SYSREG_ADDR_MHPEVENT25 0x339
#define SYSREG_ADDR_MHPEVENT26 0x33a
#define SYSREG_ADDR_MHPEVENT27 0x33b
#define SYSREG_ADDR_MHPEVENT28 0x33c
#define SYSREG_ADDR_MHPEVENT29 0x33d
#define SYSREG_ADDR_MHPEVENT30 0x33e
#define SYSREG_ADDR_MHPEVENT31 0x33f
#define SYSREG_ADDR_STATS 0x0c0
#define SYSREG_ADDR_UARCH00 0xcc0
#define SYSREG_ADDR_UARCH01 0xcc1
#define SYSREG_ADDR_UARCH02 0xcc2
#define SYSREG_ADDR_UARCH03 0xcc3
#define SYSREG_ADDR_UARCH04 0xcc4
#define SYSREG_ADDR_UARCH05 0xcc5
#define SYSREG_ADDR_UARCH06 0xcc6
#define SYSREG_ADDR_UARCH07 0xcc7
#define SYSREG_ADDR_UARCH08 0xcc8
#define SYSREG_ADDR_UARCH09 0xcc9
#define SYSREG_ADDR_UARCH10 0xcca
#define SYSREG_ADDR_UARCH11 0xccb
#define SYSREG_ADDR_UARCH12 0xccc
#define SYSREG_ADDR_UARCH13 0xccd
#define SYSREG_ADDR_UARCH14 0xcce
#define SYSREG_ADDR_UARCH15 0xccf
