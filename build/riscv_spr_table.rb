#!/bin/ruby
#
# Copyright (c) 2015, Masayuki Kimura
# All rights reserved.
#
#   Redistribution and use in source and binary forms, with or without
#   modification, are permitted provided that the following conditions are met:
#   * Redistributions of source code must retain the above copyright
#   notice, this list of conditions and the following disclaimer.
#   * Redistributions in binary form must reproduce the above copyright
#   notice, this list of conditions and the following disclaimer in the
#     documentation and/or other materials provided with the distribution.
#   * Neither the name of the Masayuki Kimura nor the
#     names of its contributors may be used to endorse or promote products
#     derived from this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
#   ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
# DISCLAIMED. IN NO EVENT SHALL MASAYUKI KIMURA BE LIABLE FOR ANY
#   DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
#   (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
#    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
#   ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
#   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
#   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#

$sysreg_table = Array[]  # system register table

module SYSREG
  ADDR   = 0
  PRIV   = 1
  NAME   = 2
  BITFIELD = 3
end


module SYSREG_BITFIELD
  MAX  = 0
  MIN  = 1
  NAME = 2
  RW   = 3
  INIT = 4
end

xlen = 64     ## for 64-bit implemenatation mode
misa_base = 2 ## for 64-bit implemenatation mode

tbl_idx = 0

## start of RISC-V system registers
#            ['Number', 'Privilege', 'Name']

# User Level CSR
$sysreg_table.push(Array[0x000,  'SRW',     'ustatus'      , Array[Array[xlen-1, 0, 'ustatus'       , 'RW', 0]]])
$sysreg_table.push(Array[0x004,  'SRW',     'uie'          , Array[Array[xlen-1, 0, 'uie'           , 'RW', 0]]])
$sysreg_table.push(Array[0x005,  'SRW',     'utvec'        , Array[Array[xlen-1, 0, 'utvec'         , 'RW', 0]]])

$sysreg_table.push(Array[0x040,  'SRW',     'uscratch'     , Array[Array[xlen-1, 0, 'uscratch'      , 'RW', 0]]])
$sysreg_table.push(Array[0x041,  'SRW',     'uepc'         , Array[Array[xlen-1, 0, 'uepc'          , 'RW', 0]]])
$sysreg_table.push(Array[0x042,  'SRO',     'ucause'       , Array[Array[xlen-1, 0, 'ucause'        , 'RW', 0]]])
$sysreg_table.push(Array[0x043,  'SRO',     'ubadaddr'     , Array[Array[xlen-1, 0, 'ubadaddr'      , 'RW', 0]]])
$sysreg_table.push(Array[0x044,  'SRW',     'uip'          , Array[Array[xlen-1, 0, 'uip'           , 'RW', 0]]])

$sysreg_table.push(Array[0x001,  'URW',     'fflags'       , Array[Array[xlen-1, 0, 'fflags'        , 'RW', 0]]])
$sysreg_table.push(Array[0x002,  'URW',     'frm'          , Array[Array[xlen-1, 0, 'frm'           , 'RW', 0]]])
$sysreg_table.push(Array[0x003,  'URW',     'fcsr'         , Array[Array[ 7, 5, 'frm'           , 'RW', 0],
                                                                   Array[ 4, 0, 'fflags'        , 'RW', 0]]])

$sysreg_table.push(Array[0xC00,  'URO',     'cycle'        , Array[Array[xlen-1, 0, 'cycle'         , 'RW', 0]]])
# $sysreg_table.push(Array[0xC01,  'URO',     'time'         , Array[Array[xlen-1, 0, 'time'          , 'RW', 0]]])
$sysreg_table.push(Array[0xC02,  'URO',     'instret'      , Array[Array[xlen-1, 0, 'instret'       , 'RW', 0]]])
$sysreg_table.push(Array[0xC03,  'URO',     'hpmcounter3'  , Array[Array[xlen-1, 0, 'hpmcounter3'   , 'RW', 0]]])
$sysreg_table.push(Array[0xC04,  'URO',     'hpmcounter4'  , Array[Array[xlen-1, 0, 'hpmcounter4'   , 'RW', 0]]])
$sysreg_table.push(Array[0xC05,  'URO',     'hpmcounter5'  , Array[Array[xlen-1, 0, 'hpmcounter5'   , 'RW', 0]]])
$sysreg_table.push(Array[0xC06,  'URO',     'hpmcounter6'  , Array[Array[xlen-1, 0, 'hpmcounter6'   , 'RW', 0]]])
$sysreg_table.push(Array[0xC07,  'URO',     'hpmcounter7'  , Array[Array[xlen-1, 0, 'hpmcounter7'   , 'RW', 0]]])
$sysreg_table.push(Array[0xC08,  'URO',     'hpmcounter8'  , Array[Array[xlen-1, 0, 'hpmcounter8'   , 'RW', 0]]])
$sysreg_table.push(Array[0xC09,  'URO',     'hpmcounter9'  , Array[Array[xlen-1, 0, 'hpmcounter9'   , 'RW', 0]]])
$sysreg_table.push(Array[0xC0A,  'URO',     'hpmcounter10' , Array[Array[xlen-1, 0, 'hpmcounter10'  , 'RW', 0]]])
$sysreg_table.push(Array[0xC0B,  'URO',     'hpmcounter11' , Array[Array[xlen-1, 0, 'hpmcounter11'  , 'RW', 0]]])
$sysreg_table.push(Array[0xC0C,  'URO',     'hpmcounter12' , Array[Array[xlen-1, 0, 'hpmcounter12'  , 'RW', 0]]])
$sysreg_table.push(Array[0xC0D,  'URO',     'hpmcounter13' , Array[Array[xlen-1, 0, 'hpmcounter13'  , 'RW', 0]]])
$sysreg_table.push(Array[0xC0E,  'URO',     'hpmcounter14' , Array[Array[xlen-1, 0, 'hpmcounter14'  , 'RW', 0]]])
$sysreg_table.push(Array[0xC0F,  'URO',     'hpmcounter15' , Array[Array[xlen-1, 0, 'hpmcounter15'  , 'RW', 0]]])
$sysreg_table.push(Array[0xC10,  'URO',     'hpmcounter16' , Array[Array[xlen-1, 0, 'hpmcounter16'  , 'RW', 0]]])
$sysreg_table.push(Array[0xC11,  'URO',     'hpmcounter17' , Array[Array[xlen-1, 0, 'hpmcounter17'  , 'RW', 0]]])
$sysreg_table.push(Array[0xC12,  'URO',     'hpmcounter18' , Array[Array[xlen-1, 0, 'hpmcounter18'  , 'RW', 0]]])
$sysreg_table.push(Array[0xC13,  'URO',     'hpmcounter19' , Array[Array[xlen-1, 0, 'hpmcounter19'  , 'RW', 0]]])
$sysreg_table.push(Array[0xC14,  'URO',     'hpmcounter20' , Array[Array[xlen-1, 0, 'hpmcounter20'  , 'RW', 0]]])
$sysreg_table.push(Array[0xC15,  'URO',     'hpmcounter21' , Array[Array[xlen-1, 0, 'hpmcounter21'  , 'RW', 0]]])
$sysreg_table.push(Array[0xC16,  'URO',     'hpmcounter22' , Array[Array[xlen-1, 0, 'hpmcounter22'  , 'RW', 0]]])
$sysreg_table.push(Array[0xC17,  'URO',     'hpmcounter23' , Array[Array[xlen-1, 0, 'hpmcounter23'  , 'RW', 0]]])
$sysreg_table.push(Array[0xC18,  'URO',     'hpmcounter24' , Array[Array[xlen-1, 0, 'hpmcounter24'  , 'RW', 0]]])
$sysreg_table.push(Array[0xC19,  'URO',     'hpmcounter25' , Array[Array[xlen-1, 0, 'hpmcounter25'  , 'RW', 0]]])
$sysreg_table.push(Array[0xC1A,  'URO',     'hpmcounter26' , Array[Array[xlen-1, 0, 'hpmcounter26'  , 'RW', 0]]])
$sysreg_table.push(Array[0xC1B,  'URO',     'hpmcounter27' , Array[Array[xlen-1, 0, 'hpmcounter27'  , 'RW', 0]]])
$sysreg_table.push(Array[0xC1C,  'URO',     'hpmcounter28' , Array[Array[xlen-1, 0, 'hpmcounter28'  , 'RW', 0]]])
$sysreg_table.push(Array[0xC1D,  'URO',     'hpmcounter29' , Array[Array[xlen-1, 0, 'hpmcounter29'  , 'RW', 0]]])
$sysreg_table.push(Array[0xC1E,  'URO',     'hpmcounter30' , Array[Array[xlen-1, 0, 'hpmcounter30'  , 'RW', 0]]])
$sysreg_table.push(Array[0xC1F,  'URO',     'hpmcounter31' , Array[Array[xlen-1, 0, 'hpmcounterx31'  , 'RW', 0]]])

$sysreg_table.push(Array[0xC80,  'URO',     'cycleh'        , Array[Array[xlen-1, 0, 'cycleh'         , 'RW', 0]]])
$sysreg_table.push(Array[0xC81,  'URO',     'timeh'         , Array[Array[xlen-1, 0, 'timeh'          , 'RW', 0]]])
$sysreg_table.push(Array[0xC82,  'URO',     'instreth'      , Array[Array[xlen-1, 0, 'instreth'       , 'RW', 0]]])
$sysreg_table.push(Array[0xC83,  'URO',     'hpmcounterh3'  , Array[Array[xlen-1, 0, 'hpmcounterh3'   , 'RW', 0]]])
$sysreg_table.push(Array[0xC84,  'URO',     'hpmcounterh4'  , Array[Array[xlen-1, 0, 'hpmcounterh4'   , 'RW', 0]]])
$sysreg_table.push(Array[0xC85,  'URO',     'hpmcounterh5'  , Array[Array[xlen-1, 0, 'hpmcounterh5'   , 'RW', 0]]])
$sysreg_table.push(Array[0xC86,  'URO',     'hpmcounterh6'  , Array[Array[xlen-1, 0, 'hpmcounterh6'   , 'RW', 0]]])
$sysreg_table.push(Array[0xC87,  'URO',     'hpmcounterh7'  , Array[Array[xlen-1, 0, 'hpmcounterh7'   , 'RW', 0]]])
$sysreg_table.push(Array[0xC88,  'URO',     'hpmcounterh8'  , Array[Array[xlen-1, 0, 'hpmcounterh8'   , 'RW', 0]]])
$sysreg_table.push(Array[0xC89,  'URO',     'hpmcounterh9'  , Array[Array[xlen-1, 0, 'hpmcounterh9'   , 'RW', 0]]])
$sysreg_table.push(Array[0xC8A,  'URO',     'hpmcounterh10' , Array[Array[xlen-1, 0, 'hpmcounterh10'  , 'RW', 0]]])
$sysreg_table.push(Array[0xC8B,  'URO',     'hpmcounterh11' , Array[Array[xlen-1, 0, 'hpmcounterh11'  , 'RW', 0]]])
$sysreg_table.push(Array[0xC8C,  'URO',     'hpmcounterh12' , Array[Array[xlen-1, 0, 'hpmcounterh12'  , 'RW', 0]]])
$sysreg_table.push(Array[0xC8D,  'URO',     'hpmcounterh13' , Array[Array[xlen-1, 0, 'hpmcounterh13'  , 'RW', 0]]])
$sysreg_table.push(Array[0xC8E,  'URO',     'hpmcounterh14' , Array[Array[xlen-1, 0, 'hpmcounterh14'  , 'RW', 0]]])
$sysreg_table.push(Array[0xC8F,  'URO',     'hpmcounterh15' , Array[Array[xlen-1, 0, 'hpmcounterh15'  , 'RW', 0]]])
$sysreg_table.push(Array[0xC90,  'URO',     'hpmcounterh16' , Array[Array[xlen-1, 0, 'hpmcounterh16'  , 'RW', 0]]])
$sysreg_table.push(Array[0xC91,  'URO',     'hpmcounterh17' , Array[Array[xlen-1, 0, 'hpmcounterh17'  , 'RW', 0]]])
$sysreg_table.push(Array[0xC92,  'URO',     'hpmcounterh18' , Array[Array[xlen-1, 0, 'hpmcounterh18'  , 'RW', 0]]])
$sysreg_table.push(Array[0xC93,  'URO',     'hpmcounterh19' , Array[Array[xlen-1, 0, 'hpmcounterh19'  , 'RW', 0]]])
$sysreg_table.push(Array[0xC94,  'URO',     'hpmcounterh20' , Array[Array[xlen-1, 0, 'hpmcounterh20'  , 'RW', 0]]])
$sysreg_table.push(Array[0xC95,  'URO',     'hpmcounterh21' , Array[Array[xlen-1, 0, 'hpmcounterh21'  , 'RW', 0]]])
$sysreg_table.push(Array[0xC96,  'URO',     'hpmcounterh22' , Array[Array[xlen-1, 0, 'hpmcounterh22'  , 'RW', 0]]])
$sysreg_table.push(Array[0xC97,  'URO',     'hpmcounterh23' , Array[Array[xlen-1, 0, 'hpmcounterh23'  , 'RW', 0]]])
$sysreg_table.push(Array[0xC98,  'URO',     'hpmcounterh24' , Array[Array[xlen-1, 0, 'hpmcounterh24'  , 'RW', 0]]])
$sysreg_table.push(Array[0xC99,  'URO',     'hpmcounterh25' , Array[Array[xlen-1, 0, 'hpmcounterh25'  , 'RW', 0]]])
$sysreg_table.push(Array[0xC9A,  'URO',     'hpmcounterh26' , Array[Array[xlen-1, 0, 'hpmcounterh26'  , 'RW', 0]]])
$sysreg_table.push(Array[0xC9B,  'URO',     'hpmcounterh27' , Array[Array[xlen-1, 0, 'hpmcounterh27'  , 'RW', 0]]])
$sysreg_table.push(Array[0xC9C,  'URO',     'hpmcounterh28' , Array[Array[xlen-1, 0, 'hpmcounterh28'  , 'RW', 0]]])
$sysreg_table.push(Array[0xC9D,  'URO',     'hpmcounterh29' , Array[Array[xlen-1, 0, 'hpmcounterh29'  , 'RW', 0]]])
$sysreg_table.push(Array[0xC9E,  'URO',     'hpmcounterh30' , Array[Array[xlen-1, 0, 'hpmcounterh30'  , 'RW', 0]]])
$sysreg_table.push(Array[0xC9F,  'URO',     'hpmcounterh31' , Array[Array[xlen-1, 0, 'hpmcounterh31'  , 'RW', 0]]])

# Supervisor-Level CSR
$sysreg_table.push(Array[0x100,  'SRW',     'sstatus'   , Array[Array[xlen-1,xlen-1, 'SD', 'RW', 0],
                                                                Array[33,32, 'UXL',  'R',  0],
                                                                Array[19,19, 'MXR',  'RW', 0],
                                                                Array[18,18, 'SUM',  'R',  0],
                                                                Array[16,15, 'XS',   'RW', 0],
                                                                Array[14,13, 'FS',   'RW', 0],
                                                                Array[ 8, 8, 'SPP',  'RW', 0],
                                                                Array[ 5, 5, 'SPIE', 'RW', 0], Array[ 4, 4, 'UPIE', 'RW', 0],
                                                                Array[ 1, 1, 'SIE',  'RW', 0], Array[ 0, 0, 'UIE',  'RW', 0]]])
$sysreg_table.push(Array[0x102,  'SRW',     'sedeleg'   , Array[Array[xlen-1, 0, 'sedeleg'  , 'RW', 0]]])
$sysreg_table.push(Array[0x103,  'SRW',     'sideleg'   , Array[Array[xlen-1, 0, 'sideleg'  , 'RW', 0]]])
$sysreg_table.push(Array[0x104,  'SRW',     'sie'       , Array[Array[xlen-1, 0, 'sie'      , 'RW', 0]]])
$sysreg_table.push(Array[0x105,  'SRW',     'stvec'     , Array[Array[xlen-1, 0, 'stvec'    , 'RW', 0]]])
$sysreg_table.push(Array[0x106,  'MRW',    'scounteren', Array[Array[31, 31, 'HPM31', 'RW', 0], Array[30, 30, 'HPM30', 'RW', 0], Array[29, 29, 'HPM29', 'RW', 0], Array[28, 28, 'HPM28', 'RW', 0],
                                                               Array[27, 27, 'HPM27', 'RW', 0], Array[26, 26, 'HPM26', 'RW', 0], Array[25, 25, 'HPM25', 'RW', 0], Array[24, 24, 'HPM24', 'RW', 0],
                                                               Array[23, 23, 'HPM23', 'RW', 0], Array[22, 22, 'HPM22', 'RW', 0], Array[21, 21, 'HPM21', 'RW', 0], Array[20, 20, 'HPM20', 'RW', 0],
                                                               Array[19, 19, 'HPM19', 'RW', 0], Array[18, 18, 'HPM18', 'RW', 0], Array[17, 17, 'HPM17', 'RW', 0], Array[16, 16, 'HPM16', 'RW', 0],
                                                               Array[15, 15, 'HPM15', 'RW', 0], Array[14, 14, 'HPM14', 'RW', 0], Array[13, 13, 'HPM13', 'RW', 0], Array[12, 12, 'HPM12', 'RW', 0],
                                                               Array[11, 11, 'HPM11', 'RW', 0], Array[10, 10, 'HPM10', 'RW', 0], Array[ 9,  9, 'HPM9',  'RW', 0], Array[ 8,  8, 'HPM8',  'RW', 0],
                                                               Array[ 7,  7, 'HPM7',  'RW', 0], Array[ 6,  6, 'HPM6',  'RW', 0], Array[ 5,  5, 'HPM5',  'RW', 0], Array[ 4,  4, 'HPM4',  'RW', 0],
                                                               Array[ 3,  3, 'HPM3',  'RW', 0], Array[ 2,  2, 'IR',    'RW', 0], Array[ 1,  1, 'TM',    'RW', 0], Array[ 0,  0, 'CY',    'RW', 0]]])
$sysreg_table.push(Array[0x140,  'SRW',     'sscratch'  , Array[Array[xlen-1, 0, 'sscratch' , 'RW', 0]]])
$sysreg_table.push(Array[0x141,  'SRW',     'sepc'      , Array[Array[xlen-1, 0, 'sepc'     , 'RW', 0]]])
$sysreg_table.push(Array[0x142,  'SRO',     'scause'    , Array[Array[xlen-1, 0, 'scause'   , 'RW', 0]]])
$sysreg_table.push(Array[0x143,  'SRO',     'stval'     , Array[Array[xlen-1, 0, 'stval'    , 'RW', 0]]])
$sysreg_table.push(Array[0x144,  'SRW',     'sip'       , Array[Array[xlen-1, 0, 'sip'      , 'RW', 0]]])
$sysreg_table.push(Array[0x180,  'SRW',     'satp'      , Array[Array[xlen-1,xlen-4, 'MODE'    , 'RW', 0],
                                                                Array[xlen-5,22,     'ASID'    , 'RW', 0],
                                                                Array[    21, 0,     'PPN'     , 'RW', 0]]])

# Hypervisor-Level CSR
$sysreg_table.push(Array[0x200,  'HRW',     'hstatus'   , Array[Array[xlen-1, 0, 'hstatus'  , 'RW', 0]]])
$sysreg_table.push(Array[0x202,  'HRW',     'hedeleg'   , Array[Array[xlen-1, 0, 'hedeleg'  , 'RW', 0]]])
$sysreg_table.push(Array[0x203,  'HRW',     'hideleg'   , Array[Array[xlen-1, 0, 'hideleg'  , 'RW', 0]]])
$sysreg_table.push(Array[0x204,  'HRW',     'hie'       , Array[Array[xlen-1, 0, 'hie'      , 'RW', 0]]])
$sysreg_table.push(Array[0x205,  'HRW',     'htvec'     , Array[Array[xlen-1, 0, 'htvec'    , 'RW', 0]]])
$sysreg_table.push(Array[0x240,  'HRW',     'hscratch'  , Array[Array[xlen-1, 0, 'hscratch' , 'RW', 0]]])
$sysreg_table.push(Array[0x241,  'HRW',     'hepc'      , Array[Array[xlen-1, 0, 'hepc'     , 'RW', 0]]])
$sysreg_table.push(Array[0x242,  'HRO',     'hcause'    , Array[Array[xlen-1, 0, 'hcause'   , 'RW', 0]]])
$sysreg_table.push(Array[0x243,  'HRO',     'hbadaddr'  , Array[Array[xlen-1, 0, 'hbadaddr' , 'RW', 0]]])
$sysreg_table.push(Array[0x244,  'HRW',     'hip'       , Array[Array[xlen-1, 0, 'hip'      , 'RW', 0]]])
$sysreg_table.push(Array[0x280,  'HRW',     'hptbr'     , Array[Array[xlen-1, 0, 'hptbr'    , 'RW', 0]]])

# Machine-Level CSR
$sysreg_table.push(Array[0xF11,  'MRO',     'mvendorid', Array[Array[xlen-1, 0, 'MVendorID', 'R', 0]]])
$sysreg_table.push(Array[0xF12,  'MRO',     'marchid'  , Array[Array[xlen-1, 0, 'MArchID',   'R', 0]]])
$sysreg_table.push(Array[0xF13,  'MRO',     'mimpid'   , Array[Array[xlen-1,16, 'Implementation', 'R', 0], Array[15, 0, 'Source', 'R', 0]]])
$sysreg_table.push(Array[0xF14,  'MRO',     'mhartid'  , Array[Array[xlen-1, 0, 'Hart_ID', 'R', 0]]])
$sysreg_table.push(Array[0x300,  'MRW',     'mstatus'  , Array[Array[xlen-1,xlen-1, 'SD', 'RW', 0],
                                                               Array[35,34, 'SXL',  'R',  0],
                                                               Array[33,32, 'UXL',  'R',  0],
                                                               Array[22,22, 'TSR',  'RW', 0],
                                                               Array[21,21, 'TW',   'RW', 0],
                                                               Array[20,20, 'TVM',  'RW', 0],
                                                               Array[19,19, 'MXR',  'RW', 0],
                                                               Array[18,18, 'SUM',  'R',  0],
                                                               Array[17,17, 'MPRV', 'RW', 0],
                                                               Array[16,15, 'XS',   'RW', 0],
                                                               Array[14,13, 'FS',   'RW', 0],
                                                               Array[12,11, 'MPP',  'RW', 0], Array[ 8, 8, 'SPP',  'RW', 0],
                                                               Array[ 7, 7, 'MPIE', 'RW', 0], Array[ 5, 5, 'SPIE', 'RW', 0], Array[ 4, 4, 'UPIE', 'RW', 0],
                                                               Array[ 3, 3, 'MIE',  'RW', 0], Array[ 1, 1, 'SIE',  'RW', 0], Array[ 0, 0, 'UIE',  'RW', 0]]])
$sysreg_table.push(Array[0x301,  'MRW',     'misa'     , Array[Array[xlen-1, xlen-2, 'MXL'       , 'R', misa_base],
                                                               Array[    25,      0, 'Extensions' , 'RW', 0]]])
$sysreg_table.push(Array[0x302,  'MRW',     'medeleg'  , Array[Array[xlen-1, 0, 'medeleg'  , 'RW', 0]]])
$sysreg_table.push(Array[0x303,  'MRW',     'mideleg'  , Array[Array[xlen-1, 0, 'mideleg'  , 'RW', 0]]])
$sysreg_table.push(Array[0x304,  'MRW',     'mie'      , Array[Array[11,11, 'MEIE', 'RW', 0],
                                                               Array[ 9, 9, 'SEIE', 'RW', 0],
                                                               Array[ 8, 8, 'UEIE', 'RW', 0],
                                                               Array[ 7, 7, 'MTIE', 'RW', 0],
                                                               Array[ 5, 5, 'STIE', 'RW', 0],
                                                               Array[ 4, 4, 'UTIE', 'RW', 0],
                                                               Array[ 3, 3, 'MSIE', 'RW', 0],
                                                               Array[ 1, 1, 'SSIE', 'RW', 0],
                                                               Array[ 0, 0, 'USIE', 'RW', 0]]])
$sysreg_table.push(Array[0x305,  'MRW',     'mtvec'    , Array[Array[xlen-1, 2, 'Trap_Vector_Base_Address', 'RW', 0]]])
$sysreg_table.push(Array[0x306,  'MRW',    'mcounteren', Array[Array[31, 31, 'HPM31', 'RW', 0], Array[30, 30, 'HPM30', 'RW', 0], Array[29, 29, 'HPM29', 'RW', 0], Array[28, 28, 'HPM28', 'RW', 0],
                                                               Array[27, 27, 'HPM27', 'RW', 0], Array[26, 26, 'HPM26', 'RW', 0], Array[25, 25, 'HPM25', 'RW', 0], Array[24, 24, 'HPM24', 'RW', 0],
                                                               Array[23, 23, 'HPM23', 'RW', 0], Array[22, 22, 'HPM22', 'RW', 0], Array[21, 21, 'HPM21', 'RW', 0], Array[20, 20, 'HPM20', 'RW', 0],
                                                               Array[19, 19, 'HPM19', 'RW', 0], Array[18, 18, 'HPM18', 'RW', 0], Array[17, 17, 'HPM17', 'RW', 0], Array[16, 16, 'HPM16', 'RW', 0],
                                                               Array[15, 15, 'HPM15', 'RW', 0], Array[14, 14, 'HPM14', 'RW', 0], Array[13, 13, 'HPM13', 'RW', 0], Array[12, 12, 'HPM12', 'RW', 0],
                                                               Array[11, 11, 'HPM11', 'RW', 0], Array[10, 10, 'HPM10', 'RW', 0], Array[ 9,  9, 'HPM9',  'RW', 0], Array[ 8,  8, 'HPM8',  'RW', 0],
                                                               Array[ 7,  7, 'HPM7',  'RW', 0], Array[ 6,  6, 'HPM6',  'RW', 0], Array[ 5,  5, 'HPM5',  'RW', 0], Array[ 4,  4, 'HPM4',  'RW', 0],
                                                               Array[ 3,  3, 'HPM3',  'RW', 0], Array[ 2,  2, 'IR',    'RW', 0], Array[ 1,  1, 'TM',    'RW', 0], Array[ 0,  0, 'CY',    'RW', 0]]])

$sysreg_table.push(Array[0x340,  'MRW',     'mscratch' , Array[Array[xlen-1, 0, 'mscratch',  'RW', 0]]])
$sysreg_table.push(Array[0x341,  'MRW',     'mepc'     , Array[Array[xlen-1, 0, 'mepc',      'RW', 0]]])
$sysreg_table.push(Array[0x342,  'MRW',     'mcause'   , Array[Array[xlen-1,xlen-1, 'Interrupt', 'RW', 0], Array[ 3, 0, 'Exception_Code', 'RW', 0]]])
$sysreg_table.push(Array[0x343,  'MRW',     'mtval'    , Array[Array[xlen-1, 0, 'mtval',  'RW', 0]]])
$sysreg_table.push(Array[0x344,  'MRW',     'mip'      , Array[Array[11,11, 'MEIP', 'RW', 0],
                                                               Array[ 9, 9, 'SEIP', 'RW', 0],
                                                               Array[ 8, 8, 'UEIP', 'RW', 0],
                                                               Array[ 7, 7, 'MTIP', 'RW', 0],
                                                               Array[ 5, 5, 'STIP', 'RW', 0],
                                                               Array[ 4, 4, 'UTIP', 'RW', 0],
                                                               Array[ 3, 3, 'MSIP', 'RW', 0],
                                                               Array[ 1, 1, 'SSIP', 'RW', 0],
                                                               Array[ 0, 0, 'USIP', 'RW', 0]]])
$sysreg_table.push(Array[0x380,  'MRW',     'mbase'    , Array[Array[xlen-1, 0, 'mbase'    , 'RW', 0]]])
$sysreg_table.push(Array[0x381,  'MRW',     'mbound'   , Array[Array[xlen-1, 0, 'mbound'   , 'RW', 0]]])
$sysreg_table.push(Array[0x382,  'MRW',     'mibase'   , Array[Array[xlen-1, 0, 'mibase'   , 'RW', 0]]])
$sysreg_table.push(Array[0x383,  'MRW',     'mibound'  , Array[Array[xlen-1, 0, 'mibound'  , 'RW', 0]]])
$sysreg_table.push(Array[0x384,  'MRW',     'mdbase'   , Array[Array[xlen-1, 0, 'mdbase'   , 'RW', 0]]])
$sysreg_table.push(Array[0x385,  'MRW',     'mdbound'  , Array[Array[xlen-1, 0, 'mdbound'  , 'RW', 0]]])

$sysreg_table.push(Array[0xB00,  'MRW',     'mcycle'        , Array[Array[xlen-1, 0, 'mcycle'         , 'RW', 0]]])
$sysreg_table.push(Array[0xB02,  'MRW',     'minstret'      , Array[Array[xlen-1, 0, 'minstret'       , 'RW', 0]]])
$sysreg_table.push(Array[0xB03,  'MRW',     'mhpmcounter3'  , Array[Array[xlen-1, 0, 'mhpmcounter3'   , 'RW', 0]]])
$sysreg_table.push(Array[0xB04,  'MRW',     'mhpmcounter4'  , Array[Array[xlen-1, 0, 'mhpmcounter4'   , 'RW', 0]]])
$sysreg_table.push(Array[0xB05,  'MRW',     'mhpmcounter5'  , Array[Array[xlen-1, 0, 'mhpmcounter5'   , 'RW', 0]]])
$sysreg_table.push(Array[0xB06,  'MRW',     'mhpmcounter6'  , Array[Array[xlen-1, 0, 'mhpmcounter6'   , 'RW', 0]]])
$sysreg_table.push(Array[0xB07,  'MRW',     'mhpmcounter7'  , Array[Array[xlen-1, 0, 'mhpmcounter7'   , 'RW', 0]]])
$sysreg_table.push(Array[0xB08,  'MRW',     'mhpmcounter8'  , Array[Array[xlen-1, 0, 'mhpmcounter8'   , 'RW', 0]]])
$sysreg_table.push(Array[0xB09,  'MRW',     'mhpmcounter9'  , Array[Array[xlen-1, 0, 'mhpmcounter9'   , 'RW', 0]]])
$sysreg_table.push(Array[0xB0A,  'MRW',     'mhpmcounter10' , Array[Array[xlen-1, 0, 'mhpmcounter10'  , 'RW', 0]]])
$sysreg_table.push(Array[0xB0B,  'MRW',     'mhpmcounter11' , Array[Array[xlen-1, 0, 'mhpmcounter11'  , 'RW', 0]]])
$sysreg_table.push(Array[0xB0C,  'MRW',     'mhpmcounter12' , Array[Array[xlen-1, 0, 'mhpmcounter12'  , 'RW', 0]]])
$sysreg_table.push(Array[0xB0D,  'MRW',     'mhpmcounter13' , Array[Array[xlen-1, 0, 'mhpmcounter13'  , 'RW', 0]]])
$sysreg_table.push(Array[0xB0E,  'MRW',     'mhpmcounter14' , Array[Array[xlen-1, 0, 'mhpmcounter14'  , 'RW', 0]]])
$sysreg_table.push(Array[0xB0F,  'MRW',     'mhpmcounter15' , Array[Array[xlen-1, 0, 'mhpmcounter15'  , 'RW', 0]]])
$sysreg_table.push(Array[0xB10,  'MRW',     'mhpmcounter16' , Array[Array[xlen-1, 0, 'mhpmcounter16'  , 'RW', 0]]])
$sysreg_table.push(Array[0xB11,  'MRW',     'mhpmcounter17' , Array[Array[xlen-1, 0, 'mhpmcounter17'  , 'RW', 0]]])
$sysreg_table.push(Array[0xB12,  'MRW',     'mhpmcounter18' , Array[Array[xlen-1, 0, 'mhpmcounter18'  , 'RW', 0]]])
$sysreg_table.push(Array[0xB13,  'MRW',     'mhpmcounter19' , Array[Array[xlen-1, 0, 'mhpmcounter19'  , 'RW', 0]]])
$sysreg_table.push(Array[0xB14,  'MRW',     'mhpmcounter20' , Array[Array[xlen-1, 0, 'mhpmcounter20'  , 'RW', 0]]])
$sysreg_table.push(Array[0xB15,  'MRW',     'mhpmcounter21' , Array[Array[xlen-1, 0, 'mhpmcounter21'  , 'RW', 0]]])
$sysreg_table.push(Array[0xB16,  'MRW',     'mhpmcounter22' , Array[Array[xlen-1, 0, 'mhpmcounter22'  , 'RW', 0]]])
$sysreg_table.push(Array[0xB17,  'MRW',     'mhpmcounter23' , Array[Array[xlen-1, 0, 'mhpmcounter23'  , 'RW', 0]]])
$sysreg_table.push(Array[0xB18,  'MRW',     'mhpmcounter24' , Array[Array[xlen-1, 0, 'mhpmcounter24'  , 'RW', 0]]])
$sysreg_table.push(Array[0xB19,  'MRW',     'mhpmcounter25' , Array[Array[xlen-1, 0, 'mhpmcounter25'  , 'RW', 0]]])
$sysreg_table.push(Array[0xB1A,  'MRW',     'mhpmcounter26' , Array[Array[xlen-1, 0, 'mhpmcounter26'  , 'RW', 0]]])
$sysreg_table.push(Array[0xB1B,  'MRW',     'mhpmcounter27' , Array[Array[xlen-1, 0, 'mhpmcounter27'  , 'RW', 0]]])
$sysreg_table.push(Array[0xB1C,  'MRW',     'mhpmcounter28' , Array[Array[xlen-1, 0, 'mhpmcounter28'  , 'RW', 0]]])
$sysreg_table.push(Array[0xB1D,  'MRW',     'mhpmcounter29' , Array[Array[xlen-1, 0, 'mhpmcounter29'  , 'RW', 0]]])
$sysreg_table.push(Array[0xB1E,  'MRW',     'mhpmcounter30' , Array[Array[xlen-1, 0, 'mhpmcounter30'  , 'RW', 0]]])
$sysreg_table.push(Array[0xB1F,  'MRW',     'mhpmcounter31' , Array[Array[xlen-1, 0, 'mhpmcounter31'  , 'RW', 0]]])

$sysreg_table.push(Array[0x323,  'MRW',     'mhpevent3'     , Array[Array[xlen-1, 0, 'mhpevent3'      , 'RW', 0]]])
$sysreg_table.push(Array[0x324,  'MRW',     'mhpevent4'     , Array[Array[xlen-1, 0, 'mhpevent4'      , 'RW', 0]]])
$sysreg_table.push(Array[0x325,  'MRW',     'mhpevent5'     , Array[Array[xlen-1, 0, 'mhpevent5'      , 'RW', 0]]])
$sysreg_table.push(Array[0x326,  'MRW',     'mhpevent6'     , Array[Array[xlen-1, 0, 'mhpevent6'      , 'RW', 0]]])
$sysreg_table.push(Array[0x327,  'MRW',     'mhpevent7'     , Array[Array[xlen-1, 0, 'mhpevent7'      , 'RW', 0]]])
$sysreg_table.push(Array[0x328,  'MRW',     'mhpevent8'     , Array[Array[xlen-1, 0, 'mhpevent8'      , 'RW', 0]]])
$sysreg_table.push(Array[0x329,  'MRW',     'mhpevent9'     , Array[Array[xlen-1, 0, 'mhpevent9'      , 'RW', 0]]])
$sysreg_table.push(Array[0x32A,  'MRW',     'mhpevent10'    , Array[Array[xlen-1, 0, 'mhpevent10'     , 'RW', 0]]])
$sysreg_table.push(Array[0x32B,  'MRW',     'mhpevent11'    , Array[Array[xlen-1, 0, 'mhpevent11'     , 'RW', 0]]])
$sysreg_table.push(Array[0x32C,  'MRW',     'mhpevent12'    , Array[Array[xlen-1, 0, 'mhpevent12'     , 'RW', 0]]])
$sysreg_table.push(Array[0x32D,  'MRW',     'mhpevent13'    , Array[Array[xlen-1, 0, 'mhpevent13'     , 'RW', 0]]])
$sysreg_table.push(Array[0x32E,  'MRW',     'mhpevent14'    , Array[Array[xlen-1, 0, 'mhpevent14'     , 'RW', 0]]])
$sysreg_table.push(Array[0x32F,  'MRW',     'mhpevent15'    , Array[Array[xlen-1, 0, 'mhpevent15'     , 'RW', 0]]])
$sysreg_table.push(Array[0x330,  'MRW',     'mhpevent16'    , Array[Array[xlen-1, 0, 'mhpevent16'     , 'RW', 0]]])
$sysreg_table.push(Array[0x331,  'MRW',     'mhpevent17'    , Array[Array[xlen-1, 0, 'mhpevent17'     , 'RW', 0]]])
$sysreg_table.push(Array[0x332,  'MRW',     'mhpevent18'    , Array[Array[xlen-1, 0, 'mhpevent18'     , 'RW', 0]]])
$sysreg_table.push(Array[0x333,  'MRW',     'mhpevent19'    , Array[Array[xlen-1, 0, 'mhpevent19'     , 'RW', 0]]])
$sysreg_table.push(Array[0x334,  'MRW',     'mhpevent20'    , Array[Array[xlen-1, 0, 'mhpevent20'     , 'RW', 0]]])
$sysreg_table.push(Array[0x335,  'MRW',     'mhpevent21'    , Array[Array[xlen-1, 0, 'mhpevent21'     , 'RW', 0]]])
$sysreg_table.push(Array[0x336,  'MRW',     'mhpevent22'    , Array[Array[xlen-1, 0, 'mhpevent22'     , 'RW', 0]]])
$sysreg_table.push(Array[0x337,  'MRW',     'mhpevent23'    , Array[Array[xlen-1, 0, 'mhpevent23'     , 'RW', 0]]])
$sysreg_table.push(Array[0x338,  'MRW',     'mhpevent24'    , Array[Array[xlen-1, 0, 'mhpevent24'     , 'RW', 0]]])
$sysreg_table.push(Array[0x339,  'MRW',     'mhpevent25'    , Array[Array[xlen-1, 0, 'mhpevent25'     , 'RW', 0]]])
$sysreg_table.push(Array[0x33A,  'MRW',     'mhpevent26'    , Array[Array[xlen-1, 0, 'mhpevent26'     , 'RW', 0]]])
$sysreg_table.push(Array[0x33B,  'MRW',     'mhpevent27'    , Array[Array[xlen-1, 0, 'mhpevent27'     , 'RW', 0]]])
$sysreg_table.push(Array[0x33C,  'MRW',     'mhpevent28'    , Array[Array[xlen-1, 0, 'mhpevent28'     , 'RW', 0]]])
$sysreg_table.push(Array[0x33D,  'MRW',     'mhpevent29'    , Array[Array[xlen-1, 0, 'mhpevent29'     , 'RW', 0]]])
$sysreg_table.push(Array[0x33E,  'MRW',     'mhpevent30'    , Array[Array[xlen-1, 0, 'mhpevent30'     , 'RW', 0]]])
$sysreg_table.push(Array[0x33F,  'MRW',     'mhpevent31'    , Array[Array[xlen-1, 0, 'mhpevent31'     , 'RW', 0]]])

## Machine Protection and Transalation
# $sysreg_table.push(Array[0x3A0,  'MRW',     'pmpcfg0'       , Array[Array[31,24, 'pmpcfg3',  'RW', 0],
#                                                                     Array[23,16, 'pmpcfg2',  'RW', 0],
#                                                                     Array[15, 8, 'pmpcfg1',  'RW', 0],
#                                                                     Array[ 7, 0, 'pmpcfg0',  'RW', 0]]])
# $sysreg_table.push(Array[0x3A1,  'MRW',     'pmpcfg1'       , Array[Array[31,24, 'pmpcfg7',  'RW', 0],
#                                                                     Array[23,16, 'pmpcfg6',  'RW', 0],
#                                                                     Array[15, 8, 'pmpcfg5',  'RW', 0],
#                                                                     Array[ 7, 0, 'pmpcfg4',  'RW', 0]]])
# $sysreg_table.push(Array[0x3A2,  'MRW',     'pmpcfg2'       , Array[Array[31,24, 'pmpcfg11', 'RW', 0],
#                                                                     Array[23,16, 'pmpcfg10', 'RW', 0],
#                                                                     Array[15, 8, 'pmpcfg9',  'RW', 0],
#                                                                     Array[ 7, 0, 'pmpcfg8',  'RW', 0]]])
# $sysreg_table.push(Array[0x3A3,  'MRW',     'pmpcfg3'       , Array[Array[31,24, 'pmpcfg15', 'RW', 0],
#                                                                     Array[23,16, 'pmpcfg14', 'RW', 0],
#                                                                     Array[15, 8, 'pmpcfg13', 'RW', 0],
#                                                                     Array[ 7, 0, 'pmpcfg12', 'RW', 0]]])

# $sysreg_table.push(Array[0x3B0,  'MRW',     'pmpaddr0'      , Array[Array[xlen-1,0, 'pmpaddr0',  'RW', 0]]])
# $sysreg_table.push(Array[0x3B1,  'MRW',     'pmpaddr1'      , Array[Array[xlen-1,0, 'pmpaddr1',  'RW', 0]]])
# $sysreg_table.push(Array[0x3B2,  'MRW',     'pmpaddr2'      , Array[Array[xlen-1,0, 'pmpaddr2',  'RW', 0]]])
# $sysreg_table.push(Array[0x3B3,  'MRW',     'pmpaddr3'      , Array[Array[xlen-1,0, 'pmpaddr3',  'RW', 0]]])
# $sysreg_table.push(Array[0x3B4,  'MRW',     'pmpaddr4'      , Array[Array[xlen-1,0, 'pmpaddr4',  'RW', 0]]])
# $sysreg_table.push(Array[0x3B5,  'MRW',     'pmpaddr5'      , Array[Array[xlen-1,0, 'pmpaddr5',  'RW', 0]]])
# $sysreg_table.push(Array[0x3B6,  'MRW',     'pmpaddr6'      , Array[Array[xlen-1,0, 'pmpaddr6',  'RW', 0]]])
# $sysreg_table.push(Array[0x3B7,  'MRW',     'pmpaddr7'      , Array[Array[xlen-1,0, 'pmpaddr7',  'RW', 0]]])
# $sysreg_table.push(Array[0x3B8,  'MRW',     'pmpaddr8'      , Array[Array[xlen-1,0, 'pmpaddr8',  'RW', 0]]])
# $sysreg_table.push(Array[0x3B9,  'MRW',     'pmpaddr9'      , Array[Array[xlen-1,0, 'pmpaddr9',  'RW', 0]]])
# $sysreg_table.push(Array[0x3BA,  'MRW',     'pmpaddr10'     , Array[Array[xlen-1,0, 'pmpaddr10', 'RW', 0]]])
# $sysreg_table.push(Array[0x3BB,  'MRW',     'pmpaddr11'     , Array[Array[xlen-1,0, 'pmpaddr11', 'RW', 0]]])
# $sysreg_table.push(Array[0x3BC,  'MRW',     'pmpaddr12'     , Array[Array[xlen-1,0, 'pmpaddr12', 'RW', 0]]])
# $sysreg_table.push(Array[0x3BD,  'MRW',     'pmpaddr13'     , Array[Array[xlen-1,0, 'pmpaddr13', 'RW', 0]]])
# $sysreg_table.push(Array[0x3BE,  'MRW',     'pmpaddr14'     , Array[Array[xlen-1,0, 'pmpaddr14', 'RW', 0]]])
# $sysreg_table.push(Array[0x3BF,  'MRW',     'pmpaddr15'     , Array[Array[xlen-1,0, 'pmpaddr15', 'RW', 0]]])

# HW Implementation
$sysreg_table.push(Array[0x0c0,  'URW',     'stats'  , Array[Array[xlen-1, 0, 'stats'  , 'RW', 0]]])
$sysreg_table.push(Array[0xcc0,  'UR' ,     'uarch00', Array[Array[xlen-1, 0, 'uarch00', 'R',  0]]])
$sysreg_table.push(Array[0xcc1,  'UR' ,     'uarch01', Array[Array[xlen-1, 0, 'uarch01', 'R',  0]]])
$sysreg_table.push(Array[0xcc2,  'UR' ,     'uarch02', Array[Array[xlen-1, 0, 'uarch02', 'R',  0]]])
$sysreg_table.push(Array[0xcc3,  'UR' ,     'uarch03', Array[Array[xlen-1, 0, 'uarch03', 'R',  0]]])
$sysreg_table.push(Array[0xcc4,  'UR' ,     'uarch04', Array[Array[xlen-1, 0, 'uarch04', 'R',  0]]])
$sysreg_table.push(Array[0xcc5,  'UR' ,     'uarch05', Array[Array[xlen-1, 0, 'uarch05', 'R',  0]]])
$sysreg_table.push(Array[0xcc6,  'UR' ,     'uarch06', Array[Array[xlen-1, 0, 'uarch06', 'R',  0]]])
$sysreg_table.push(Array[0xcc7,  'UR' ,     'uarch07', Array[Array[xlen-1, 0, 'uarch07', 'R',  0]]])
$sysreg_table.push(Array[0xcc8,  'UR' ,     'uarch08', Array[Array[xlen-1, 0, 'uarch08', 'R',  0]]])
$sysreg_table.push(Array[0xcc9,  'UR' ,     'uarch09', Array[Array[xlen-1, 0, 'uarch09', 'R',  0]]])
$sysreg_table.push(Array[0xcca,  'UR' ,     'uarch10', Array[Array[xlen-1, 0, 'uarch10', 'R',  0]]])
$sysreg_table.push(Array[0xccb,  'UR' ,     'uarch11', Array[Array[xlen-1, 0, 'uarch11', 'R',  0]]])
$sysreg_table.push(Array[0xccc,  'UR' ,     'uarch12', Array[Array[xlen-1, 0, 'uarch12', 'R',  0]]])
$sysreg_table.push(Array[0xccd,  'UR' ,     'uarch13', Array[Array[xlen-1, 0, 'uarch13', 'R',  0]]])
$sysreg_table.push(Array[0xcce,  'UR' ,     'uarch14', Array[Array[xlen-1, 0, 'uarch14', 'R',  0]]])
$sysreg_table.push(Array[0xccf,  'UR' ,     'uarch15', Array[Array[xlen-1, 0, 'uarch15', 'R',  0]]])

# $sysreg_table.push(Array[0x7b0,  'MRW',     'dcsr'      , Array[Array[xlen-1, 0, 'dcsr'      , 'RW', 0]]])
# $sysreg_table.push(Array[0x7b1,  'MRW',     'dpc'       , Array[Array[xlen-1, 0, 'dpc'       , 'RW', 0]]])
# $sysreg_table.push(Array[0x7b2,  'MRW',     'dscratch0' , Array[Array[xlen-1, 0, 'dscratch0' , 'RW', 0]]])
# $sysreg_table.push(Array[0x7b3,  'MRW',     'dscratch1' , Array[Array[xlen-1, 0, 'dscratch1' , 'RW', 0]]])
