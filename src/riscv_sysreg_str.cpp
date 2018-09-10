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


#include <string>
#include "basic.hpp"

#include "riscv_sysreg_impl.hpp"

std::string csr_name[196] = {
  "ustatus",
  "uie",
  "utvec",
  "uscratch",
  "uepc",
  "ucause",
  "ubadaddr",
  "uip",
  "fflags",
  "frm",
  "fcsr",
  "cycle",
  "instret",
  "hpmcounter3",
  "hpmcounter4",
  "hpmcounter5",
  "hpmcounter6",
  "hpmcounter7",
  "hpmcounter8",
  "hpmcounter9",
  "hpmcounter10",
  "hpmcounter11",
  "hpmcounter12",
  "hpmcounter13",
  "hpmcounter14",
  "hpmcounter15",
  "hpmcounter16",
  "hpmcounter17",
  "hpmcounter18",
  "hpmcounter19",
  "hpmcounter20",
  "hpmcounter21",
  "hpmcounter22",
  "hpmcounter23",
  "hpmcounter24",
  "hpmcounter25",
  "hpmcounter26",
  "hpmcounter27",
  "hpmcounter28",
  "hpmcounter29",
  "hpmcounter30",
  "hpmcounter31",
  "cycleh",
  "timeh",
  "instreth",
  "hpmcounterh3",
  "hpmcounterh4",
  "hpmcounterh5",
  "hpmcounterh6",
  "hpmcounterh7",
  "hpmcounterh8",
  "hpmcounterh9",
  "hpmcounterh10",
  "hpmcounterh11",
  "hpmcounterh12",
  "hpmcounterh13",
  "hpmcounterh14",
  "hpmcounterh15",
  "hpmcounterh16",
  "hpmcounterh17",
  "hpmcounterh18",
  "hpmcounterh19",
  "hpmcounterh20",
  "hpmcounterh21",
  "hpmcounterh22",
  "hpmcounterh23",
  "hpmcounterh24",
  "hpmcounterh25",
  "hpmcounterh26",
  "hpmcounterh27",
  "hpmcounterh28",
  "hpmcounterh29",
  "hpmcounterh30",
  "hpmcounterh31",
  "sstatus",
  "sedeleg",
  "sideleg",
  "sie",
  "stvec",
  "scounteren",
  "sscratch",
  "sepc",
  "scause",
  "stval",
  "sip",
  "satp",
  "hstatus",
  "hedeleg",
  "hideleg",
  "hie",
  "htvec",
  "hscratch",
  "hepc",
  "hcause",
  "hbadaddr",
  "hip",
  "hptbr",
  "mvendorid",
  "marchid",
  "mimpid",
  "mhartid",
  "mstatus",
  "misa",
  "medeleg",
  "mideleg",
  "mie",
  "mtvec",
  "mcounteren",
  "mscratch",
  "mepc",
  "mcause",
  "mtval",
  "mip",
  "mbase",
  "mbound",
  "mibase",
  "mibound",
  "mdbase",
  "mdbound",
  "mcycle",
  "minstret",
  "mhpmcounter3",
  "mhpmcounter4",
  "mhpmcounter5",
  "mhpmcounter6",
  "mhpmcounter7",
  "mhpmcounter8",
  "mhpmcounter9",
  "mhpmcounter10",
  "mhpmcounter11",
  "mhpmcounter12",
  "mhpmcounter13",
  "mhpmcounter14",
  "mhpmcounter15",
  "mhpmcounter16",
  "mhpmcounter17",
  "mhpmcounter18",
  "mhpmcounter19",
  "mhpmcounter20",
  "mhpmcounter21",
  "mhpmcounter22",
  "mhpmcounter23",
  "mhpmcounter24",
  "mhpmcounter25",
  "mhpmcounter26",
  "mhpmcounter27",
  "mhpmcounter28",
  "mhpmcounter29",
  "mhpmcounter30",
  "mhpmcounter31",
  "mhpevent3",
  "mhpevent4",
  "mhpevent5",
  "mhpevent6",
  "mhpevent7",
  "mhpevent8",
  "mhpevent9",
  "mhpevent10",
  "mhpevent11",
  "mhpevent12",
  "mhpevent13",
  "mhpevent14",
  "mhpevent15",
  "mhpevent16",
  "mhpevent17",
  "mhpevent18",
  "mhpevent19",
  "mhpevent20",
  "mhpevent21",
  "mhpevent22",
  "mhpevent23",
  "mhpevent24",
  "mhpevent25",
  "mhpevent26",
  "mhpevent27",
  "mhpevent28",
  "mhpevent29",
  "mhpevent30",
  "mhpevent31",
  "stats",
  "uarch00",
  "uarch01",
  "uarch02",
  "uarch03",
  "uarch04",
  "uarch05",
  "uarch06",
  "uarch07",
  "uarch08",
  "uarch09",
  "uarch10",
  "uarch11",
  "uarch12",
  "uarch13",
  "uarch14",
  "uarch15"
};
std::string CsrEnv::GetCSRName (Addr_t addr)
{
  switch (addr) {
    case SYSREG_ADDR_USTATUS : return csr_name[0];
    case SYSREG_ADDR_UIE : return csr_name[1];
    case SYSREG_ADDR_UTVEC : return csr_name[2];
    case SYSREG_ADDR_USCRATCH : return csr_name[3];
    case SYSREG_ADDR_UEPC : return csr_name[4];
    case SYSREG_ADDR_UCAUSE : return csr_name[5];
    case SYSREG_ADDR_UBADADDR : return csr_name[6];
    case SYSREG_ADDR_UIP : return csr_name[7];
    case SYSREG_ADDR_FFLAGS : return csr_name[8];
    case SYSREG_ADDR_FRM : return csr_name[9];
    case SYSREG_ADDR_FCSR : return csr_name[10];
    case SYSREG_ADDR_CYCLE : return csr_name[11];
    case SYSREG_ADDR_INSTRET : return csr_name[12];
    case SYSREG_ADDR_HPMCOUNTER3 : return csr_name[13];
    case SYSREG_ADDR_HPMCOUNTER4 : return csr_name[14];
    case SYSREG_ADDR_HPMCOUNTER5 : return csr_name[15];
    case SYSREG_ADDR_HPMCOUNTER6 : return csr_name[16];
    case SYSREG_ADDR_HPMCOUNTER7 : return csr_name[17];
    case SYSREG_ADDR_HPMCOUNTER8 : return csr_name[18];
    case SYSREG_ADDR_HPMCOUNTER9 : return csr_name[19];
    case SYSREG_ADDR_HPMCOUNTER10 : return csr_name[20];
    case SYSREG_ADDR_HPMCOUNTER11 : return csr_name[21];
    case SYSREG_ADDR_HPMCOUNTER12 : return csr_name[22];
    case SYSREG_ADDR_HPMCOUNTER13 : return csr_name[23];
    case SYSREG_ADDR_HPMCOUNTER14 : return csr_name[24];
    case SYSREG_ADDR_HPMCOUNTER15 : return csr_name[25];
    case SYSREG_ADDR_HPMCOUNTER16 : return csr_name[26];
    case SYSREG_ADDR_HPMCOUNTER17 : return csr_name[27];
    case SYSREG_ADDR_HPMCOUNTER18 : return csr_name[28];
    case SYSREG_ADDR_HPMCOUNTER19 : return csr_name[29];
    case SYSREG_ADDR_HPMCOUNTER20 : return csr_name[30];
    case SYSREG_ADDR_HPMCOUNTER21 : return csr_name[31];
    case SYSREG_ADDR_HPMCOUNTER22 : return csr_name[32];
    case SYSREG_ADDR_HPMCOUNTER23 : return csr_name[33];
    case SYSREG_ADDR_HPMCOUNTER24 : return csr_name[34];
    case SYSREG_ADDR_HPMCOUNTER25 : return csr_name[35];
    case SYSREG_ADDR_HPMCOUNTER26 : return csr_name[36];
    case SYSREG_ADDR_HPMCOUNTER27 : return csr_name[37];
    case SYSREG_ADDR_HPMCOUNTER28 : return csr_name[38];
    case SYSREG_ADDR_HPMCOUNTER29 : return csr_name[39];
    case SYSREG_ADDR_HPMCOUNTER30 : return csr_name[40];
    case SYSREG_ADDR_HPMCOUNTER31 : return csr_name[41];
    case SYSREG_ADDR_CYCLEH : return csr_name[42];
    case SYSREG_ADDR_TIMEH : return csr_name[43];
    case SYSREG_ADDR_INSTRETH : return csr_name[44];
    case SYSREG_ADDR_HPMCOUNTERH3 : return csr_name[45];
    case SYSREG_ADDR_HPMCOUNTERH4 : return csr_name[46];
    case SYSREG_ADDR_HPMCOUNTERH5 : return csr_name[47];
    case SYSREG_ADDR_HPMCOUNTERH6 : return csr_name[48];
    case SYSREG_ADDR_HPMCOUNTERH7 : return csr_name[49];
    case SYSREG_ADDR_HPMCOUNTERH8 : return csr_name[50];
    case SYSREG_ADDR_HPMCOUNTERH9 : return csr_name[51];
    case SYSREG_ADDR_HPMCOUNTERH10 : return csr_name[52];
    case SYSREG_ADDR_HPMCOUNTERH11 : return csr_name[53];
    case SYSREG_ADDR_HPMCOUNTERH12 : return csr_name[54];
    case SYSREG_ADDR_HPMCOUNTERH13 : return csr_name[55];
    case SYSREG_ADDR_HPMCOUNTERH14 : return csr_name[56];
    case SYSREG_ADDR_HPMCOUNTERH15 : return csr_name[57];
    case SYSREG_ADDR_HPMCOUNTERH16 : return csr_name[58];
    case SYSREG_ADDR_HPMCOUNTERH17 : return csr_name[59];
    case SYSREG_ADDR_HPMCOUNTERH18 : return csr_name[60];
    case SYSREG_ADDR_HPMCOUNTERH19 : return csr_name[61];
    case SYSREG_ADDR_HPMCOUNTERH20 : return csr_name[62];
    case SYSREG_ADDR_HPMCOUNTERH21 : return csr_name[63];
    case SYSREG_ADDR_HPMCOUNTERH22 : return csr_name[64];
    case SYSREG_ADDR_HPMCOUNTERH23 : return csr_name[65];
    case SYSREG_ADDR_HPMCOUNTERH24 : return csr_name[66];
    case SYSREG_ADDR_HPMCOUNTERH25 : return csr_name[67];
    case SYSREG_ADDR_HPMCOUNTERH26 : return csr_name[68];
    case SYSREG_ADDR_HPMCOUNTERH27 : return csr_name[69];
    case SYSREG_ADDR_HPMCOUNTERH28 : return csr_name[70];
    case SYSREG_ADDR_HPMCOUNTERH29 : return csr_name[71];
    case SYSREG_ADDR_HPMCOUNTERH30 : return csr_name[72];
    case SYSREG_ADDR_HPMCOUNTERH31 : return csr_name[73];
    case SYSREG_ADDR_SSTATUS : return csr_name[74];
    case SYSREG_ADDR_SEDELEG : return csr_name[75];
    case SYSREG_ADDR_SIDELEG : return csr_name[76];
    case SYSREG_ADDR_SIE : return csr_name[77];
    case SYSREG_ADDR_STVEC : return csr_name[78];
    case SYSREG_ADDR_SCOUNTEREN : return csr_name[79];
    case SYSREG_ADDR_SSCRATCH : return csr_name[80];
    case SYSREG_ADDR_SEPC : return csr_name[81];
    case SYSREG_ADDR_SCAUSE : return csr_name[82];
    case SYSREG_ADDR_STVAL : return csr_name[83];
    case SYSREG_ADDR_SIP : return csr_name[84];
    case SYSREG_ADDR_SATP : return csr_name[85];
    case SYSREG_ADDR_HSTATUS : return csr_name[86];
    case SYSREG_ADDR_HEDELEG : return csr_name[87];
    case SYSREG_ADDR_HIDELEG : return csr_name[88];
    case SYSREG_ADDR_HIE : return csr_name[89];
    case SYSREG_ADDR_HTVEC : return csr_name[90];
    case SYSREG_ADDR_HSCRATCH : return csr_name[91];
    case SYSREG_ADDR_HEPC : return csr_name[92];
    case SYSREG_ADDR_HCAUSE : return csr_name[93];
    case SYSREG_ADDR_HBADADDR : return csr_name[94];
    case SYSREG_ADDR_HIP : return csr_name[95];
    case SYSREG_ADDR_HPTBR : return csr_name[96];
    case SYSREG_ADDR_MVENDORID : return csr_name[97];
    case SYSREG_ADDR_MARCHID : return csr_name[98];
    case SYSREG_ADDR_MIMPID : return csr_name[99];
    case SYSREG_ADDR_MHARTID : return csr_name[100];
    case SYSREG_ADDR_MSTATUS : return csr_name[101];
    case SYSREG_ADDR_MISA : return csr_name[102];
    case SYSREG_ADDR_MEDELEG : return csr_name[103];
    case SYSREG_ADDR_MIDELEG : return csr_name[104];
    case SYSREG_ADDR_MIE : return csr_name[105];
    case SYSREG_ADDR_MTVEC : return csr_name[106];
    case SYSREG_ADDR_MCOUNTEREN : return csr_name[107];
    case SYSREG_ADDR_MSCRATCH : return csr_name[108];
    case SYSREG_ADDR_MEPC : return csr_name[109];
    case SYSREG_ADDR_MCAUSE : return csr_name[110];
    case SYSREG_ADDR_MTVAL : return csr_name[111];
    case SYSREG_ADDR_MIP : return csr_name[112];
    case SYSREG_ADDR_MBASE : return csr_name[113];
    case SYSREG_ADDR_MBOUND : return csr_name[114];
    case SYSREG_ADDR_MIBASE : return csr_name[115];
    case SYSREG_ADDR_MIBOUND : return csr_name[116];
    case SYSREG_ADDR_MDBASE : return csr_name[117];
    case SYSREG_ADDR_MDBOUND : return csr_name[118];
    case SYSREG_ADDR_MCYCLE : return csr_name[119];
    case SYSREG_ADDR_MINSTRET : return csr_name[120];
    case SYSREG_ADDR_MHPMCOUNTER3 : return csr_name[121];
    case SYSREG_ADDR_MHPMCOUNTER4 : return csr_name[122];
    case SYSREG_ADDR_MHPMCOUNTER5 : return csr_name[123];
    case SYSREG_ADDR_MHPMCOUNTER6 : return csr_name[124];
    case SYSREG_ADDR_MHPMCOUNTER7 : return csr_name[125];
    case SYSREG_ADDR_MHPMCOUNTER8 : return csr_name[126];
    case SYSREG_ADDR_MHPMCOUNTER9 : return csr_name[127];
    case SYSREG_ADDR_MHPMCOUNTER10 : return csr_name[128];
    case SYSREG_ADDR_MHPMCOUNTER11 : return csr_name[129];
    case SYSREG_ADDR_MHPMCOUNTER12 : return csr_name[130];
    case SYSREG_ADDR_MHPMCOUNTER13 : return csr_name[131];
    case SYSREG_ADDR_MHPMCOUNTER14 : return csr_name[132];
    case SYSREG_ADDR_MHPMCOUNTER15 : return csr_name[133];
    case SYSREG_ADDR_MHPMCOUNTER16 : return csr_name[134];
    case SYSREG_ADDR_MHPMCOUNTER17 : return csr_name[135];
    case SYSREG_ADDR_MHPMCOUNTER18 : return csr_name[136];
    case SYSREG_ADDR_MHPMCOUNTER19 : return csr_name[137];
    case SYSREG_ADDR_MHPMCOUNTER20 : return csr_name[138];
    case SYSREG_ADDR_MHPMCOUNTER21 : return csr_name[139];
    case SYSREG_ADDR_MHPMCOUNTER22 : return csr_name[140];
    case SYSREG_ADDR_MHPMCOUNTER23 : return csr_name[141];
    case SYSREG_ADDR_MHPMCOUNTER24 : return csr_name[142];
    case SYSREG_ADDR_MHPMCOUNTER25 : return csr_name[143];
    case SYSREG_ADDR_MHPMCOUNTER26 : return csr_name[144];
    case SYSREG_ADDR_MHPMCOUNTER27 : return csr_name[145];
    case SYSREG_ADDR_MHPMCOUNTER28 : return csr_name[146];
    case SYSREG_ADDR_MHPMCOUNTER29 : return csr_name[147];
    case SYSREG_ADDR_MHPMCOUNTER30 : return csr_name[148];
    case SYSREG_ADDR_MHPMCOUNTER31 : return csr_name[149];
    case SYSREG_ADDR_MHPEVENT3 : return csr_name[150];
    case SYSREG_ADDR_MHPEVENT4 : return csr_name[151];
    case SYSREG_ADDR_MHPEVENT5 : return csr_name[152];
    case SYSREG_ADDR_MHPEVENT6 : return csr_name[153];
    case SYSREG_ADDR_MHPEVENT7 : return csr_name[154];
    case SYSREG_ADDR_MHPEVENT8 : return csr_name[155];
    case SYSREG_ADDR_MHPEVENT9 : return csr_name[156];
    case SYSREG_ADDR_MHPEVENT10 : return csr_name[157];
    case SYSREG_ADDR_MHPEVENT11 : return csr_name[158];
    case SYSREG_ADDR_MHPEVENT12 : return csr_name[159];
    case SYSREG_ADDR_MHPEVENT13 : return csr_name[160];
    case SYSREG_ADDR_MHPEVENT14 : return csr_name[161];
    case SYSREG_ADDR_MHPEVENT15 : return csr_name[162];
    case SYSREG_ADDR_MHPEVENT16 : return csr_name[163];
    case SYSREG_ADDR_MHPEVENT17 : return csr_name[164];
    case SYSREG_ADDR_MHPEVENT18 : return csr_name[165];
    case SYSREG_ADDR_MHPEVENT19 : return csr_name[166];
    case SYSREG_ADDR_MHPEVENT20 : return csr_name[167];
    case SYSREG_ADDR_MHPEVENT21 : return csr_name[168];
    case SYSREG_ADDR_MHPEVENT22 : return csr_name[169];
    case SYSREG_ADDR_MHPEVENT23 : return csr_name[170];
    case SYSREG_ADDR_MHPEVENT24 : return csr_name[171];
    case SYSREG_ADDR_MHPEVENT25 : return csr_name[172];
    case SYSREG_ADDR_MHPEVENT26 : return csr_name[173];
    case SYSREG_ADDR_MHPEVENT27 : return csr_name[174];
    case SYSREG_ADDR_MHPEVENT28 : return csr_name[175];
    case SYSREG_ADDR_MHPEVENT29 : return csr_name[176];
    case SYSREG_ADDR_MHPEVENT30 : return csr_name[177];
    case SYSREG_ADDR_MHPEVENT31 : return csr_name[178];
    case SYSREG_ADDR_STATS : return csr_name[179];
    case SYSREG_ADDR_UARCH00 : return csr_name[180];
    case SYSREG_ADDR_UARCH01 : return csr_name[181];
    case SYSREG_ADDR_UARCH02 : return csr_name[182];
    case SYSREG_ADDR_UARCH03 : return csr_name[183];
    case SYSREG_ADDR_UARCH04 : return csr_name[184];
    case SYSREG_ADDR_UARCH05 : return csr_name[185];
    case SYSREG_ADDR_UARCH06 : return csr_name[186];
    case SYSREG_ADDR_UARCH07 : return csr_name[187];
    case SYSREG_ADDR_UARCH08 : return csr_name[188];
    case SYSREG_ADDR_UARCH09 : return csr_name[189];
    case SYSREG_ADDR_UARCH10 : return csr_name[190];
    case SYSREG_ADDR_UARCH11 : return csr_name[191];
    case SYSREG_ADDR_UARCH12 : return csr_name[192];
    case SYSREG_ADDR_UARCH13 : return csr_name[193];
    case SYSREG_ADDR_UARCH14 : return csr_name[194];
    case SYSREG_ADDR_UARCH15 : return csr_name[195];
    default : return "INVLD_CSR";
  }
  return NULL;
}
