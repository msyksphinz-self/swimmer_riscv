/*
 * Copyright (c) 2017, msyksphinz
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

#include "riscv_pe_thread.hpp"

// Destination R, Source R
template <typename Dst_t, typename Src_t, typename Func>
void RiscvPeThread::Func_R_R (InstWord_t inst_hex, Func func)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  Src_t rs1_val;
  rs1_val = ReadGReg<Src_t> (rs1_addr);

  Dst_t res = func(rs1_val, 0);
  WriteGReg<Dst_t> (rd_addr, res);
}


// Destination R, Source RR
template <typename Dst_t, typename Src_t, typename Func>
void RiscvPeThread::Func_R_RR (InstWord_t inst_hex, Func func)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  Src_t rs1_val = ReadGReg<Src_t> (rs1_addr);
  Src_t rs2_val = ReadGReg<Src_t> (rs2_addr);

  UWord_t fflags_dummy;
  Dst_t res     = func(rs1_val, rs2_val, 0, &fflags_dummy);

  WriteGReg<Dst_t> (rd_addr, res);
}


// Destination R, Source RI
template <typename Dst_t, typename Src_t, typename Func>
void RiscvPeThread::Func_R_RI (InstWord_t inst_hex, Func func)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);
  Src_t     imm      = ExtractIField  (inst_hex);

  UWord_t fflags_dummy;
  Src_t rs1_val = ReadGReg<Src_t> (rs1_addr);
  Dst_t res     = func(rs1_val, imm, 0, &fflags_dummy);

  WriteGReg<Dst_t> (rd_addr, res);
}


// Destination R, Source RU
template <typename Dst_t, typename Src_t, typename Func>
void RiscvPeThread::Func_R_RU (InstWord_t inst_hex, Func func)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);
  Src_t     imm      = ExtractIField  (inst_hex);

  UWord_t fflags_dummy;
  Src_t rs1_val = ReadGReg<Src_t> (rs1_addr);
  Dst_t res     = func(rs1_val, imm, 0, &fflags_dummy);

  WriteGReg<Dst_t> (rd_addr, res);
}


// Destination F, Source FF
template <typename Dst_t, typename Src_t, typename Func>
void RiscvPeThread::Func_F_FF (InstWord_t inst_hex, Func func)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);
  uint8_t   round_mode = EncodeRMField(ExtractF3Field (inst_hex));

  Src_t rs1_val  = ReadFReg<Src_t> (rs1_addr);
  Src_t rs2_val  = ReadFReg<Src_t> (rs2_addr);

  UWord_t fflags = 0;
  Dst_t res = func (rs1_val, rs2_val, round_mode, &fflags);

  WriteFReg<Dst_t> (rd_addr, res);
  CSRWrite (static_cast<Addr_t>(SYSREG_ADDR_FFLAGS), fflags);
}


// Destination F, Source FFF
template <typename Src_t, typename Func>
void RiscvPeThread::Func_F_FFF (InstWord_t inst_hex, Func func)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rs3_addr = ExtractR3Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  Src_t rs1_val  = ReadFReg<Src_t> (rs1_addr);
  Src_t rs2_val  = ReadFReg<Src_t> (rs2_addr);
  Src_t rs3_val  = ReadFReg<Src_t> (rs3_addr);

  UWord_t fflags = 0;
  Src_t res = func (rs1_val, rs2_val, rs3_val, &fflags);

  WriteFReg<Src_t> (rd_addr, res);
  CSRWrite (static_cast<Addr_t>(SYSREG_ADDR_FFLAGS), fflags);
}


// Destination F, Source FF
template <typename Dst_t, typename Src_t, typename Func>
void RiscvPeThread::Func_R_FF (InstWord_t inst_hex, Func func)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);
  uint8_t   round_mode = EncodeRMField(ExtractF3Field (inst_hex));

  Src_t rs1_val  = ReadFReg<Src_t> (rs1_addr);
  Src_t rs2_val  = ReadFReg<Src_t> (rs2_addr);

  UWord_t fflags = 0;
  Dst_t res = func (rs1_val, rs2_val, round_mode, &fflags);

  WriteGReg<Dst_t> (rd_addr, res);
  CSRWrite (static_cast<Addr_t>(SYSREG_ADDR_FFLAGS), fflags);
}


// Destination F, Source F
template <typename Dst_t, typename Src_t, typename Func>
void RiscvPeThread::Func_F_F (InstWord_t inst_hex, Func func)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);
  uint8_t   round_mode = EncodeRMField(ExtractF3Field (inst_hex));

  Src_t rs1_val  = ReadFReg<Src_t> (rs1_addr);

  UWord_t fflags = 0;
  Dst_t res = func (rs1_val, round_mode, &fflags);

  WriteFReg<Dst_t> (rd_addr, res);
  CSRWrite (static_cast<Addr_t>(SYSREG_ADDR_FFLAGS), fflags);
}


// Destination F, Source R
template <typename Dst_t, typename Src_t, typename Func>
void RiscvPeThread::Func_F_R (InstWord_t inst_hex, Func func)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);
  uint8_t   round_mode = EncodeRMField(ExtractF3Field (inst_hex));

  Src_t rs1_val  = ReadGReg<Src_t> (rs1_addr);

  UWord_t fflags = 0;
  Dst_t res = func (rs1_val, round_mode, &fflags);

  WriteFReg<Dst_t> (rd_addr, res);
  CSRWrite (static_cast<Addr_t>(SYSREG_ADDR_FFLAGS), fflags);
}


// Destination R, Source F
template <typename Dst_t, typename Src_t, typename Func>
void RiscvPeThread::Func_R_F (InstWord_t inst_hex, Func func)
{
  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);
  uint8_t   round_mode = EncodeRMField(ExtractF3Field (inst_hex));

  Src_t rs1_val  = ReadFReg<Src_t> (rs1_addr);

  UWord_t fflags = 0;
  Dst_t res = func (rs1_val, round_mode, &fflags);

  WriteGReg<Dst_t> (rd_addr, res);
  CSRWrite (static_cast<Addr_t>(SYSREG_ADDR_FFLAGS), fflags);
}


template <typename Dst_t, typename Src_t, typename Func>
void RiscvPeThread::VecExecInt2Op(bool vm,
                                  RegAddr_t vs1_addr, RegAddr_t vs2_addr, RegAddr_t vd_addr,
                                  Func func)
{
  const int DWIDTH = sizeof(DWord_t) * 8;
  Word_t vl;
  CSRRead (static_cast<Addr_t>(SYSREG_ADDR_VL), &vl);
  Word_t vstart; CSRRead (static_cast<Addr_t>(SYSREG_ADDR_VSTART), &vstart);
  for (int i = vstart; i < vl; i++) {
    if (vm == 0) {
      const int midx = i / DWIDTH;
      const int mpos = i % DWIDTH;
      bool skip = ((ReadVReg<DWord_t>(0, midx) >> mpos) & 0x1) == 0;
      if (skip) {
        continue;
      }
    }
    Src_t vs1_val = ReadVReg<Src_t> (vs1_addr, i);
    Src_t vs2_val = ReadVReg<Src_t> (vs2_addr, i);

    Dst_t res = func(vs1_val, vs2_val);

    WriteVReg<Dst_t> (vd_addr, i, res);
  }
}
