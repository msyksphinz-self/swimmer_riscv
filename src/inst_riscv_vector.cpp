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

#include "inst_riscv.hpp"
#include "dec_utils_riscv.hpp"

#define REQUIRE_VEC \
  if (!m_pe_thread->IsVECAvailable ()) { \
    m_pe_thread->GenerateException (ExceptCode::Except_IllegalInst, 0); \
    return; \
  }


#define VI_VV_LOOP(op)                          \
  REQUIRE_VEC; \
\
  RegAddr_t vs1_addr = ExtractR1Field (inst_hex); \
  RegAddr_t vs2_addr = ExtractR2Field (inst_hex); \
  RegAddr_t vd_addr  = ExtractRDField (inst_hex); \
                                                  \
  bool vm = ExtractBitField(inst_hex, 25, 25);    \
                                                  \
  int vtype;                                                            \
  m_pe_thread->CSRRead (static_cast<Addr_t>(SYSREG_ADDR_VTYPE), &vtype); \
  RvvSEW sew = static_cast<RvvSEW>((vtype >> 2) & 0x7);                 \
                                                                        \
  switch(sew) {                                                         \
    case RvvSEW::SEW_8BIT:                                              \
      m_pe_thread->VecExecInt2Op<Byte_t, Byte_t> (vm, vs1_addr, vs2_addr, \
                                                  vd_addr,                \
                                                  [](Byte_t op1, Byte_t op2) { return op; }); \
      break; \
    case RvvSEW::SEW_16BIT: \
      m_pe_thread->VecExecInt2Op<HWord_t, HWord_t> (vm, vs1_addr, vs2_addr, \
                                                    vd_addr, \
                                                    [](HWord_t op1, HWord_t op2) { return op; }); \
      break; \
    case RvvSEW::SEW_32BIT: \
      m_pe_thread->VecExecInt2Op<Word_t, Word_t> (vm, vs1_addr, vs2_addr, \
                                                  vd_addr, \
                                                  [](Word_t op1, Word_t op2) { return op; }); \
      break; \
    case RvvSEW::SEW_64BIT: \
      m_pe_thread->VecExecInt2Op<HWord_t, HWord_t> (vm, vs1_addr, vs2_addr, \
                                                    vd_addr, \
                                                    [](Word_t op1, Word_t op2) { return op; }); \
      break; \
    default: \
      m_pe_thread->DebugPrint("Unsupported SEW."); \
      m_pe_thread->GenerateException (ExceptCode::Except_IllegalInst, 0); \
      return; \
  } \
                                                \
  return;



void InstEnv::RISCV_INST_VSETVLI (InstWord_t inst_hex)
{
  REQUIRE_VEC;

  RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  RegAddr_t rd_addr  = ExtractRDField (inst_hex);

  DWord_t rs1_val = m_pe_thread->ReadGReg<DWord_t> (rs1_addr);

  DWord_t new_vtype = ExtractBitField (inst_hex, 30, 20);
  m_pe_thread->CSRWrite (static_cast<Addr_t>(SYSREG_ADDR_VTYPE), new_vtype);
  int vsew_idx = ExtractBitField(new_vtype, 4, 2);
  int vsew = 1 << (vsew_idx + 3);
  int vlmax = m_pe_thread->get_VLEN() / vsew;

  DWord_t old_vl;
  m_pe_thread->CSRRead (static_cast<DWord_t>(SYSREG_ADDR_VL), &old_vl);
  DWord_t new_vl;
  if (rs1_addr == 0 && rd_addr == 0) {
    new_vl = old_vl > vlmax ? vlmax : old_vl;
  } else if (rs1_addr == 0 && rd_addr != 0) {
    new_vl = vlmax;
  } else {
    new_vl = rs1_val > vlmax ? vlmax : rs1_val;
  }

  m_pe_thread->CSRWrite (static_cast<DWord_t>(SYSREG_ADDR_VL), new_vl);
  m_pe_thread->WriteGReg<DWord_t>(rd_addr, new_vl);
}


void InstEnv::RISCV_INST_VSETVL (InstWord_t inst_hex)
{
  REQUIRE_VEC;

  RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  // RegAddr_t rs1_addr = ExtractR1Field (inst_hex);

  DWord_t rs2_val = m_pe_thread->ReadGReg<DWord_t> (rs2_addr);

  m_pe_thread->CSRWrite (static_cast<Addr_t>(SYSREG_ADDR_VTYPE), rs2_val);
}


void InstEnv::RISCV_INST_VADD_VV(InstWord_t inst_hex)  { VI_VV_LOOP(op1 + op2); }
void InstEnv::RISCV_INST_VSUB_VV(InstWord_t inst_hex)  { VI_VV_LOOP(op1 - op2); }
void InstEnv::RISCV_INST_VMINU_VV(InstWord_t inst_hex) { VI_VV_LOOP(op1 < op2 ? op1 : op2); }
void InstEnv::RISCV_INST_VMIN_VV(InstWord_t inst_hex)  { VI_VV_LOOP(op1 < op2 ? op1 : op2); }
void InstEnv::RISCV_INST_VMAXU_VV(InstWord_t inst_hex) { VI_VV_LOOP(op1 > op2 ? op1 : op2); }
void InstEnv::RISCV_INST_VMAX_VV(InstWord_t inst_hex)  { VI_VV_LOOP(op1 > op2 ? op1 : op2); }
void InstEnv::RISCV_INST_VAND_VV(InstWord_t inst_hex)  { VI_VV_LOOP(op1 & op2); }
void InstEnv::RISCV_INST_VOR_VV(InstWord_t inst_hex)   { VI_VV_LOOP(op1 | op2); }
void InstEnv::RISCV_INST_VXOR_VV(InstWord_t inst_hex)  { VI_VV_LOOP(op1 ^ op2); }
void InstEnv::RISCV_INST_VRGATHER_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VADC_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VMADC_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VSBC_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VMSBC_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VMERGE_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VMSEQ_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VMSNE_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VMSLTU_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VMSLT_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VMSLEU_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VMSLE_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VSADDU_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VSADD_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VSSUBU_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VSSUB_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VSLL_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VSMUL_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VSRL_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VSRA_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VSSRL_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VSSRA_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VNSRL_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VNSRA_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VNCLIPU_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VNCLIP_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VWREDSUMU_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VWREDSUM_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VDOTU_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VDOT_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VQMACCU_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VQMACC_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VQMACCUS_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VQMACCSU_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VADD_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VSUB_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VRSUB_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VMINU_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VMIN_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VMAXU_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VMAX_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VAND_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VOR_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VXOR_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VRGATHER_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VSLIDEUP_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VSLIDEDOWN_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VADC_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VMADC_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VSBC_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VMSBC_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VMERGE_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VMSEQ_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VMSNE_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VMSLTU_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VMSLT_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VMSLEU_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VMSLE_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VMSGTU_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VMSGT_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VSADDU_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VSADD_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VSSUBU_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VSSUB_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VSLL_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VSMUL_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VSRL_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VSRA_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VSSRL_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VSSRA_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VNSRL_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VNSRA_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VNCLIPU_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VNCLIP_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VWREDSUMU_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VWREDSUM_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VDOTU_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VDOT_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VQMACCU_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VQMACC_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VQMACCUS_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VQMACCSU_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VADD_VI(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VRSUB_VI(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VAND_VI(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VOR_VI(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VXOR_VI(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VRGATHER_VI(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VSLIDEUP_VI(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VSLIDEDOWN_VI(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VADC_VI(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VMADC_VI(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VMV_VI(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VMSEQ_VI(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VMSNE_VI(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VMSLEU_VI(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VMSLE_VI(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VMSGTU_VI(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VMSGT_VI(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VSADDU_VI(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VSADD_VI(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VSLL_VI(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VSRL_VI(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VSRA_VI(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VSSRL_VI(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VSSRA_VI(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VNSRL_VI(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VNSRA_VI(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VNCLIPU_VI(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VNCLIP_VI(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VREDSUM_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VREDAND_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VREDOR_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VREDXOR_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VREDMINU_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VREDMIN_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VREDMAXU_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VREDMAX_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VAADDU_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VAADD_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VASUBU_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VASUB_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VWXUNARY0_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VMUNARY0_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VCOMPRESS_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VMANDNOT_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VMAND_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VMOR_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VMXOR_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VMORNOT_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VMNAND_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VMNOR_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VMXNOR_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VDIVU_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VDIV_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VREMU_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VREM_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VMULHU_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VMUL_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VMULHSU_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VMULH_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VMADD_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VNMSUB_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VMACC_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VNMSAC_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VWADDU_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VWADD_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VWSUBU_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VWSUB_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VWADDU_W_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VWADD_W_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VWSUBU_W_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VWSUB_W_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VWMULU_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VWMULSU_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VWMUL_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VWMACCU_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VWMACC_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VWMACCUS_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VWMACCSU_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VAADDU_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VAADD_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VASUBU_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VASUB_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VSLIDE1UP_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VSLIDE1DOWN_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VRXUNARY0_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VDIVU_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VDIV_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VREMU_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VREM_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VMULHU_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VMUL_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VMULHSU_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VMULH_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VMADD_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VNMSUB_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VMACC_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VNMSAC_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VWADDU_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VWADD_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VWSUBU_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VWSUB_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VWADDU_W_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VWADD_W_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VWSUBU_W_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VWSUB_W_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VWMULU_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VWMULSU_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VWMUL_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VWMACCU_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VWMACC_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VWMACCUS_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VWMACCSU_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VFADD_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VFREDSUM_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VFSUB_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VFREDOSUM_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VFMIN_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VFREDMIN_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VFMAX_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VFREDMAX_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VFSGNJ_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VFSGNJN_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VFSGNJX_VV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VWFUNARY0_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VMFEQ_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VMFLE_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VMFLT_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VMFNE_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VFDIV_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VFUNARY0_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VFUNARY1_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VFMUL_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VFRSUB_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VFMADD_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VFNMADD_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VFMSUB_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VFNMSUB_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VFMACC_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VFNMACC_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VFMSAC_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VFNMSAC_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VFWADD_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VFWREDSUM_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VFWSUB_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VFWREDOSUM_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VFWADD_WV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VFWSUB_WV(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VFWMUL_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VFDOT_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VFWMACC_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VFWNMACC_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VFWMSAC_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VFWNMSAC_VX(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VFADD_VF(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VFREDSUM_VF(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VFSUB_VF(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VFREDOSUM_VF(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VFMIN_VF(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VFREDMIN_VF(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VFMAX_VF(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VFREDMAX_VF(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VFSGNJ_VF(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VFSGNJN_VF(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VFSGNJX_VF(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VFMV_VF(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VMFEQ_VF(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VMFLE_VF(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VMFLT_VF(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VMFNE_VF(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VMFGT_VF(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VMFGE_VF(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VFDIV_VF(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VFRDIV_VF(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VFMUL_VF(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VFRSUB_VF(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VFMADD_VF(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VFNMADD_VF(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VFMSUB_VF(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VFNMSUB_VF(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VFMACC_VF(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VFNMACC_VF(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VFMSAC_VF(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VFNMSAC_VF(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VFWADD_VF(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VFWREDSUM_VF(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VFWSUB_VF(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VFWREDOSUM_VF(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VFWADD_WF(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VFWSUB_WF(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VFWMUL_VF(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VFDOT_VF(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VFWMACC_VF(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VFWNMACC_VF(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VFWMSAC_VF(InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_VFWNMSAC_VF(InstWord_t inst_hex) {}

void InstEnv::RISCV_INST_VLE8_V(InstWord_t inst_hex)
{
  REQUIRE_VEC;

  const RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  const RegAddr_t vd_addr  = ExtractRDField (inst_hex);
  bool vm = ExtractBitField(inst_hex, 25, 25);
  Addr_t mem_base_addr  = m_pe_thread->ReadGReg<DWord_t> (rs1_addr);

  m_pe_thread->MemLoadUnitStride<Byte_t>(mem_base_addr, vd_addr, vm, static_cast<Byte_t>(0));
}


void InstEnv::RISCV_INST_VLE16_V(InstWord_t inst_hex)
{
  REQUIRE_VEC;

  const RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  const RegAddr_t vd_addr  = ExtractRDField (inst_hex);
  bool vm = ExtractBitField(inst_hex, 25, 25);
  Addr_t mem_base_addr  = m_pe_thread->ReadGReg<DWord_t> (rs1_addr);

  m_pe_thread->MemLoadUnitStride<HWord_t>(mem_base_addr, vd_addr, vm, static_cast<HWord_t>(0));
}


void InstEnv::RISCV_INST_VLE32_V(InstWord_t inst_hex)
{
  REQUIRE_VEC;

  const RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  const RegAddr_t vd_addr  = ExtractRDField (inst_hex);
  bool vm = ExtractBitField(inst_hex, 25, 25);
  Addr_t mem_base_addr  = m_pe_thread->ReadGReg<DWord_t> (rs1_addr);

  m_pe_thread->MemLoadUnitStride<Word_t>(mem_base_addr, vd_addr, vm, static_cast<Word_t>(0));
}


void InstEnv::RISCV_INST_VLE64_V(InstWord_t inst_hex)
{
  REQUIRE_VEC;

  const RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  const RegAddr_t vd_addr  = ExtractRDField (inst_hex);
  bool vm = ExtractBitField(inst_hex, 25, 25);
  Addr_t mem_base_addr  = m_pe_thread->ReadGReg<DWord_t> (rs1_addr);

  m_pe_thread->MemLoadUnitStride<DWord_t>(mem_base_addr, vd_addr, vm, static_cast<DWord_t>(0));
}


void InstEnv::RISCV_INST_VSE8_V(InstWord_t inst_hex)
{
  REQUIRE_VEC;

  const RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  const RegAddr_t vs3_addr = ExtractRDField (inst_hex);
  bool vm = ExtractBitField(inst_hex, 25, 25);
  Addr_t mem_base_addr  = m_pe_thread->ReadGReg<DWord_t> (rs1_addr);
  m_pe_thread->MemStoreUnitStride<Byte_t>(mem_base_addr, vs3_addr, vm, static_cast<Byte_t>(0));
}


void InstEnv::RISCV_INST_VSE16_V(InstWord_t inst_hex)
{
  REQUIRE_VEC;

  const RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  const RegAddr_t vs3_addr = ExtractRDField (inst_hex);
  bool vm = ExtractBitField(inst_hex, 25, 25);
  Addr_t mem_base_addr  = m_pe_thread->ReadGReg<DWord_t> (rs1_addr);
  m_pe_thread->MemStoreUnitStride<HWord_t>(mem_base_addr, vs3_addr, vm, static_cast<HWord_t>(0));
}


void InstEnv::RISCV_INST_VSE32_V(InstWord_t inst_hex)
{
  REQUIRE_VEC;

  const RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  const RegAddr_t vs3_addr = ExtractRDField (inst_hex);
  bool vm = ExtractBitField(inst_hex, 25, 25);
  Addr_t mem_base_addr  = m_pe_thread->ReadGReg<DWord_t> (rs1_addr);
  m_pe_thread->MemStoreUnitStride<Word_t>(mem_base_addr, vs3_addr, vm, static_cast<Word_t>(0));
}


void InstEnv::RISCV_INST_VSE64_V(InstWord_t inst_hex)
{
  REQUIRE_VEC;

  const RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  const RegAddr_t vs3_addr = ExtractRDField (inst_hex);
  bool vm = ExtractBitField(inst_hex, 25, 25);
  Addr_t mem_base_addr  = m_pe_thread->ReadGReg<DWord_t> (rs1_addr);
  m_pe_thread->MemStoreUnitStride<DWord_t>(mem_base_addr, vs3_addr, vm, static_cast<DWord_t>(0));
}


void InstEnv::RISCV_INST_VLSE8_V(InstWord_t inst_hex)
{
  REQUIRE_VEC;

  const RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  const RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  const RegAddr_t vd_addr  = ExtractRDField (inst_hex);
  bool vm = ExtractBitField(inst_hex, 25, 25);
  Addr_t mem_base_addr = m_pe_thread->ReadGReg<Addr_t> (rs1_addr);
  DWord_t rs2_val      = m_pe_thread->ReadGReg<DWord_t> (rs2_addr);

  m_pe_thread->MemLoadStrided<Byte_t>(mem_base_addr, rs2_val, vd_addr, vm, static_cast<Byte_t>(0));
}


void InstEnv::RISCV_INST_VLSE16_V(InstWord_t inst_hex)
{
  REQUIRE_VEC;

  const RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  const RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  const RegAddr_t vd_addr  = ExtractRDField (inst_hex);
  bool vm = ExtractBitField(inst_hex, 25, 25);
  Addr_t mem_base_addr = m_pe_thread->ReadGReg<Addr_t> (rs1_addr);
  DWord_t rs2_val      = m_pe_thread->ReadGReg<DWord_t> (rs2_addr);

  m_pe_thread->MemLoadStrided<HWord_t>(mem_base_addr, rs2_val, vd_addr, vm, static_cast<HWord_t>(0));
}


void InstEnv::RISCV_INST_VLSE32_V(InstWord_t inst_hex)
{
  REQUIRE_VEC;

  const RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  const RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  const RegAddr_t vd_addr  = ExtractRDField (inst_hex);
  bool vm = ExtractBitField(inst_hex, 25, 25);
  Addr_t mem_base_addr = m_pe_thread->ReadGReg<Addr_t> (rs1_addr);
  DWord_t rs2_val      = m_pe_thread->ReadGReg<DWord_t> (rs2_addr);

  m_pe_thread->MemLoadStrided<Word_t>(mem_base_addr, rs2_val, vd_addr, vm, static_cast<Word_t>(0));
}


void InstEnv::RISCV_INST_VLSE64_V(InstWord_t inst_hex)
{
  REQUIRE_VEC;

  const RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  const RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  const RegAddr_t vd_addr  = ExtractRDField (inst_hex);
  bool vm = ExtractBitField(inst_hex, 25, 25);
  Addr_t mem_base_addr = m_pe_thread->ReadGReg<Addr_t> (rs1_addr);
  DWord_t rs2_val      = m_pe_thread->ReadGReg<DWord_t> (rs2_addr);

  m_pe_thread->MemLoadStrided<DWord_t>(mem_base_addr, rs2_val, vd_addr, vm, static_cast<DWord_t>(0));
}


void InstEnv::RISCV_INST_VSSE8_V(InstWord_t inst_hex)
{
  REQUIRE_VEC;

  const RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  const RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  const RegAddr_t vs3_addr = ExtractRDField (inst_hex);
  bool vm = ExtractBitField(inst_hex, 25, 25);
  Addr_t mem_base_addr  = m_pe_thread->ReadGReg<DWord_t> (rs1_addr);
  DWord_t rs2_val      = m_pe_thread->ReadGReg<DWord_t> (rs2_addr);

  m_pe_thread->MemStoreStrided<Byte_t>(mem_base_addr, rs2_val, vs3_addr, vm, static_cast<Byte_t>(0));
}


void InstEnv::RISCV_INST_VSSE16_V(InstWord_t inst_hex)
{
  REQUIRE_VEC;

  const RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  const RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  const RegAddr_t vs3_addr = ExtractRDField (inst_hex);
  bool vm = ExtractBitField(inst_hex, 25, 25);
  Addr_t mem_base_addr  = m_pe_thread->ReadGReg<DWord_t> (rs1_addr);
  DWord_t rs2_val      = m_pe_thread->ReadGReg<DWord_t> (rs2_addr);

  m_pe_thread->MemStoreStrided<HWord_t>(mem_base_addr, rs2_val, vs3_addr, vm, static_cast<HWord_t>(0));
}


void InstEnv::RISCV_INST_VSSE32_V(InstWord_t inst_hex)
{
  REQUIRE_VEC;

  const RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  const RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  const RegAddr_t vs3_addr = ExtractRDField (inst_hex);
  bool vm = ExtractBitField(inst_hex, 25, 25);
  Addr_t mem_base_addr  = m_pe_thread->ReadGReg<DWord_t> (rs1_addr);
  DWord_t rs2_val      = m_pe_thread->ReadGReg<DWord_t> (rs2_addr);

  m_pe_thread->MemStoreStrided<Word_t>(mem_base_addr, rs2_val, vs3_addr, vm, static_cast<Word_t>(0));
}


void InstEnv::RISCV_INST_VSSE64_V(InstWord_t inst_hex)
{
  REQUIRE_VEC;

  const RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  const RegAddr_t rs2_addr = ExtractR2Field (inst_hex);
  const RegAddr_t vs3_addr = ExtractRDField (inst_hex);
  bool vm = ExtractBitField(inst_hex, 25, 25);
  Addr_t mem_base_addr  = m_pe_thread->ReadGReg<DWord_t> (rs1_addr);
  DWord_t rs2_val      = m_pe_thread->ReadGReg<DWord_t> (rs2_addr);

  m_pe_thread->MemStoreStrided<DWord_t>(mem_base_addr, rs2_val, vs3_addr, vm, static_cast<DWord_t>(0));
}


void InstEnv::RISCV_INST_VLXEI8_V(InstWord_t inst_hex)
{
  REQUIRE_VEC;

  const RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  const RegAddr_t vs2_addr = ExtractR2Field (inst_hex);
  const RegAddr_t vd_addr  = ExtractRDField (inst_hex);
  bool vm = ExtractBitField(inst_hex, 25, 25);
  Addr_t mem_base_addr = m_pe_thread->ReadGReg<Addr_t> (rs1_addr);

  m_pe_thread->MemLoadIndexStrided<Byte_t>(mem_base_addr, vs2_addr, vd_addr, vm, static_cast<Byte_t>(0));
}


void InstEnv::RISCV_INST_VLXEI16_V(InstWord_t inst_hex)
{
  REQUIRE_VEC;

  const RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  const RegAddr_t vs2_addr = ExtractR2Field (inst_hex);
  const RegAddr_t vd_addr  = ExtractRDField (inst_hex);
  bool vm = ExtractBitField(inst_hex, 25, 25);
  Addr_t mem_base_addr = m_pe_thread->ReadGReg<Addr_t> (rs1_addr);

  m_pe_thread->MemLoadIndexStrided<HWord_t>(mem_base_addr, vs2_addr, vd_addr, vm, static_cast<HWord_t>(0));
}


void InstEnv::RISCV_INST_VLXEI32_V(InstWord_t inst_hex)
{
  REQUIRE_VEC;

  const RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  const RegAddr_t vs2_addr = ExtractR2Field (inst_hex);
  const RegAddr_t vd_addr  = ExtractRDField (inst_hex);
  bool vm = ExtractBitField(inst_hex, 25, 25);
  Addr_t mem_base_addr = m_pe_thread->ReadGReg<Addr_t> (rs1_addr);

  m_pe_thread->MemLoadIndexStrided<Word_t>(mem_base_addr, vs2_addr, vd_addr, vm, static_cast<Word_t>(0));
}


void InstEnv::RISCV_INST_VLXEI64_V(InstWord_t inst_hex)
{
  REQUIRE_VEC;

  const RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  const RegAddr_t vs2_addr = ExtractR2Field (inst_hex);
  const RegAddr_t vd_addr  = ExtractRDField (inst_hex);
  bool vm = ExtractBitField(inst_hex, 25, 25);
  Addr_t mem_base_addr = m_pe_thread->ReadGReg<Addr_t> (rs1_addr);

  m_pe_thread->MemLoadIndexStrided<DWord_t>(mem_base_addr, vs2_addr, vd_addr, vm, static_cast<DWord_t>(0));
}


void InstEnv::RISCV_INST_VSXEI8_V(InstWord_t inst_hex)
{
  REQUIRE_VEC;

  const RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  const RegAddr_t vs2_addr = ExtractR2Field (inst_hex);
  const RegAddr_t vs3_addr = ExtractRDField (inst_hex);
  bool vm = ExtractBitField(inst_hex, 25, 25);
  Addr_t mem_base_addr  = m_pe_thread->ReadGReg<DWord_t> (rs1_addr);

  m_pe_thread->MemStoreIndexStrided<Byte_t>(mem_base_addr, vs2_addr, vs3_addr, vm, static_cast<Byte_t>(0));
}


void InstEnv::RISCV_INST_VSXEI16_V(InstWord_t inst_hex)
{
  REQUIRE_VEC;

  const RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  const RegAddr_t vs2_addr = ExtractR2Field (inst_hex);
  const RegAddr_t vs3_addr = ExtractRDField (inst_hex);
  bool vm = ExtractBitField(inst_hex, 25, 25);
  Addr_t mem_base_addr  = m_pe_thread->ReadGReg<DWord_t> (rs1_addr);

  m_pe_thread->MemStoreIndexStrided<HWord_t>(mem_base_addr, vs2_addr, vs3_addr, vm, static_cast<HWord_t>(0));
}


void InstEnv::RISCV_INST_VSXEI32_V(InstWord_t inst_hex)
{
  REQUIRE_VEC;

  const RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  const RegAddr_t vs2_addr = ExtractR2Field (inst_hex);
  const RegAddr_t vs3_addr = ExtractRDField (inst_hex);
  bool vm = ExtractBitField(inst_hex, 25, 25);
  Addr_t mem_base_addr  = m_pe_thread->ReadGReg<DWord_t> (rs1_addr);

  m_pe_thread->MemStoreIndexStrided<Word_t>(mem_base_addr, vs2_addr, vs3_addr, vm, static_cast<Word_t>(0));
}


void InstEnv::RISCV_INST_VSXEI64_V(InstWord_t inst_hex)
{
  REQUIRE_VEC;

  const RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  const RegAddr_t vs2_addr = ExtractR2Field (inst_hex);
  const RegAddr_t vs3_addr = ExtractRDField (inst_hex);
  bool vm = ExtractBitField(inst_hex, 25, 25);
  Addr_t mem_base_addr  = m_pe_thread->ReadGReg<DWord_t> (rs1_addr);

  m_pe_thread->MemStoreIndexStrided<DWord_t>(mem_base_addr, vs2_addr, vs3_addr, vm, static_cast<DWord_t>(0));
}


void InstEnv::RISCV_INST_VSUXEI8_V(InstWord_t inst_hex)
{
  REQUIRE_VEC;

  const RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  const RegAddr_t vs2_addr = ExtractR2Field (inst_hex);
  const RegAddr_t vs3_addr = ExtractRDField (inst_hex);
  bool vm = ExtractBitField(inst_hex, 25, 25);
  Addr_t mem_base_addr  = m_pe_thread->ReadGReg<DWord_t> (rs1_addr);

  m_pe_thread->MemStoreIndexStrided<Byte_t>(mem_base_addr, vs2_addr, vs3_addr, vm, static_cast<Byte_t>(0));
}


void InstEnv::RISCV_INST_VSUXEI16_V(InstWord_t inst_hex)
{
  REQUIRE_VEC;

  const RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  const RegAddr_t vs2_addr = ExtractR2Field (inst_hex);
  const RegAddr_t vs3_addr = ExtractRDField (inst_hex);
  bool vm = ExtractBitField(inst_hex, 25, 25);
  Addr_t mem_base_addr  = m_pe_thread->ReadGReg<DWord_t> (rs1_addr);

  m_pe_thread->MemStoreIndexStrided<HWord_t>(mem_base_addr, vs2_addr, vs3_addr, vm, static_cast<HWord_t>(0));
}


void InstEnv::RISCV_INST_VSUXEI32_V(InstWord_t inst_hex)
{
  REQUIRE_VEC;

  const RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  const RegAddr_t vs2_addr = ExtractR2Field (inst_hex);
  const RegAddr_t vs3_addr = ExtractRDField (inst_hex);
  bool vm = ExtractBitField(inst_hex, 25, 25);
  Addr_t mem_base_addr  = m_pe_thread->ReadGReg<DWord_t> (rs1_addr);

  m_pe_thread->MemStoreIndexStrided<Word_t>(mem_base_addr, vs2_addr, vs3_addr, vm, static_cast<Word_t>(0));
}


void InstEnv::RISCV_INST_VSUXEI64_V(InstWord_t inst_hex)
{
  REQUIRE_VEC;

  const RegAddr_t rs1_addr = ExtractR1Field (inst_hex);
  const RegAddr_t vs2_addr = ExtractR2Field (inst_hex);
  const RegAddr_t vs3_addr = ExtractRDField (inst_hex);
  bool vm = ExtractBitField(inst_hex, 25, 25);
  Addr_t mem_base_addr  = m_pe_thread->ReadGReg<DWord_t> (rs1_addr);

  m_pe_thread->MemStoreIndexStrided<DWord_t>(mem_base_addr, vs2_addr, vs3_addr, vm, static_cast<DWord_t>(0));
}
