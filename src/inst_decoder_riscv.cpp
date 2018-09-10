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
#include "inst_list_riscv.hpp"
#include "inst_decoder_riscv.hpp"
#include "dec_utils_riscv.hpp"


#include "extra_dec_utils_riscv.cpp"


InstId_t RiscvDec::DecodeInst (InstWord_t inst) {
  InstWord_t field_LD = ExtractLDField (inst);
  switch (field_LD) {
    case 0x03 : 
    // Remaining Instruction is 164
    // lui        r[11:7],h[31:12]
    // auipc      r[11:7],h[31:12]
    // jal        r[11:7],uj[31:12]
    // jalr       r[11:7],r[19:15],h[11:0]
    // beq        r[19:15],r[24:20],u[31:31]|u[7:7]|u[30:25]|u[11:8]<<1
    // bne        r[19:15],r[24:20],u[31:31]|u[7:7]|u[30:25]|u[11:8]<<1
    // blt        r[19:15],r[24:20],u[31:31]|u[7:7]|u[30:25]|u[11:8]<<1
    // bge        r[19:15],r[24:20],u[31:31]|u[7:7]|u[30:25]|u[11:8]<<1
    // bltu       r[19:15],r[24:20],u[31:31]|u[7:7]|u[30:25]|u[11:8]<<1
    // bgeu       r[19:15],r[24:20],u[31:31]|u[7:7]|u[30:25]|u[11:8]<<1
    // lb         r[11:7],h[31:20](r[19:15])
    // lh         r[11:7],h[31:20](r[19:15])
    // lw         r[11:7],h[31:20](r[19:15])
    // lbu        r[11:7],h[31:20](r[19:15])
    // lhu        r[11:7],h[31:20](r[19:15])
    // sb         r[24:20],h[31:25]|h[11:7](r[19:15])
    // sh         r[24:20],h[31:25]|h[11:7](r[19:15])
    // sw         r[24:20],h[31:25]|h[11:7](r[19:15])
    // addi       r[11:7],r[19:15],h[31:20]
    // slti       r[11:7],r[19:15],h[31:20]
    // sltiu      r[11:7],r[19:15],h[31:20]
    // xori       r[11:7],r[19:15],h[31:20]
    // ori        r[11:7],r[19:15],h[31:20]
    // andi       r[11:7],r[19:15],h[31:20]
    // slli       r[11:7],r[19:15],h[25:20]
    // srli       r[11:7],r[19:15],h[24:20]
    // srai       r[11:7],r[19:15],h[24:20]
    // add        r[11:7],r[19:15],r[24:20]
    // sub        r[11:7],r[19:15],r[24:20]
    // sll        r[11:7],r[19:15],r[24:20]
    // slt        r[11:7],r[19:15],r[24:20]
    // sltu       r[11:7],r[19:15],r[24:20]
    // xor        r[11:7],r[19:15],r[24:20]
    // srl        r[11:7],r[19:15],r[24:20]
    // sra        r[11:7],r[19:15],r[24:20]
    // or         r[11:7],r[19:15],r[24:20]
    // and        r[11:7],r[19:15],r[24:20]
    // fence
    // fence.i
    // mul        r[11:7],r[19:15],r[24:20]
    // mulh       r[11:7],r[19:15],r[24:20]
    // mulhsu     r[11:7],r[19:15],r[24:20]
    // mulhu      r[11:7],r[19:15],r[24:20]
    // div        r[11:7],r[19:15],r[24:20]
    // divu       r[11:7],r[19:15],r[24:20]
    // rem        r[11:7],r[19:15],r[24:20]
    // remu       r[11:7],r[19:15],r[24:20]
    // lr.w       r[11:7],r[19:15]
    // sc.w       r[11:7],r[19:15],r[24:20]
    // amoswap.w  r[11:7],r[24:20],(r[19:15])
    // amoadd.w   r[11:7],r[24:20],(r[19:15])
    // amoxor.w   r[11:7],r[24:20],(r[19:15])
    // amoand.w   r[11:7],r[24:20],(r[19:15])
    // amoor.w    r[11:7],r[24:20],(r[19:15])
    // amomin.w   r[11:7],r[24:20],(r[19:15])
    // amomax.w   r[11:7],r[24:20],(r[19:15])
    // amominu.w  r[11:7],r[24:20],(r[19:15])
    // amomaxu.w  r[11:7],r[24:20],(r[19:15])
    // flw        f[11:7],h[31:20](r[19:15])
    // fsw        f[24:20],h[31:25]|h[11:7](r[19:15])
    // fmadd.s    f[11:7],f[19:15],f[24:20],f[31:27]
    // fmsub.s    f[11:7],f[19:15],f[24:20],f[31:27]
    // fnmsub.s   f[11:7],f[19:15],f[24:20],f[31:27]
    // fnmadd.s   f[11:7],f[19:15],f[24:20],f[31:27]
    // fadd.s     f[11:7],f[19:15],f[24:20]
    // fsub.s     f[11:7],f[19:15],f[24:20]
    // fmul.s     f[11:7],f[19:15],f[24:20]
    // fdiv.s     f[11:7],f[19:15],f[24:20]
    // fsqrt.s    f[11:7],f[19:15]
    // fsgnj.s    f[11:7],f[19:15],f[24:20]
    // fsgnjn.s   f[11:7],f[19:15],f[24:20]
    // fsgnjx.s   f[11:7],f[19:15],f[24:20]
    // fmin.s     f[11:7],f[19:15],f[24:20]
    // fmax.s     f[11:7],f[19:15],f[24:20]
    // fcvt.w.s   r[11:7],f[19:15]
    // fcvt.wu.s  r[11:7],f[19:15]
    // fmv.x.w    r[11:7],f[19:15]
    // feq.s      r[11:7],f[19:15],f[24:20]
    // flt.s      r[11:7],f[19:15],f[24:20]
    // fle.s      r[11:7],f[19:15],f[24:20]
    // fclass.s   f[11:7],f[19:15]
    // fcvt.s.w   f[11:7],r[19:15]
    // fcvt.s.wu  f[11:7],r[19:15]
    // fmv.w.x    f[11:7],r[19:15]
    // fld        f[11:7],r[19:15],h[31:20]
    // fsd        f[24:20],h[31:25]|h[11:7](r[19:15])
    // fmadd.d    f[11:7],f[19:15],f[24:20],f[31:27]
    // fmsub.d    f[11:7],f[19:15],f[24:20],f[31:27]
    // fnmsub.d   f[11:7],f[19:15],f[24:20],f[31:27]
    // fnmadd.d   f[11:7],f[19:15],f[24:20],f[31:27]
    // fadd.d     f[11:7],f[19:15],f[24:20]
    // fsub.d     f[11:7],f[19:15],f[24:20]
    // fmul.d     f[11:7],f[19:15],f[24:20]
    // fdiv.d     f[11:7],f[19:15],f[24:20]
    // fsqrt.d    f[11:7],f[19:15]
    // fsgnj.d    f[11:7],f[19:15],f[24:20]
    // fsgnjn.d   f[11:7],f[19:15],f[24:20]
    // fsgnjx.d   f[11:7],f[19:15],f[24:20]
    // fmin.d     f[11:7],f[19:15],f[24:20]
    // fmax.d     f[11:7],f[19:15],f[24:20]
    // fcvt.s.d   f[11:7],f[19:15]
    // fcvt.d.s   f[11:7],f[19:15]
    // feq.d      r[11:7],f[19:15],f[24:20]
    // flt.d      r[11:7],f[19:15],f[24:20]
    // fle.d      r[11:7],f[19:15],f[24:20]
    // fclass.d   r[11:7],f[19:15]
    // fcvt.w.d   r[11:7],f[19:15]
    // fcvt.wu.d  r[11:7],f[19:15]
    // fcvt.d.w   f[11:7],r[19:15]
    // fcvt.d.wu  f[11:7],r[19:15]
    // csrrw      r[11:7],h[31:20],r[19:15]
    // csrrs      r[11:7],h[31:20],r[19:15]
    // csrrc      r[11:7],h[31:20],r[19:15]
    // csrrwi     r[11:7],h[31:20],h[19:15]
    // csrrsi     r[11:7],h[31:20],h[19:15]
    // csrrci     r[11:7],h[31:20],h[19:15]
    // ecall
    // ebreak
    // uret
    // sret
    // hret
    // mret
    // mrts
    // mrth
    // wfi
    // sfence.vma r[19:15],r[24:20]
    // lwu        r[11:7],h[31:20](r[19:15])
    // ld         r[11:7],h[31:20](r[19:15])
    // sd         r[24:20],h[31:25]|h[11:7](r[19:15])
    // addiw      r[11:7],r[19:15],h[31:20]
    // slliw      r[11:7],r[19:15],r[24:20]
    // srliw      r[11:7],r[19:15],r[24:20]
    // sraiw      r[11:7],r[19:15],r[24:20]
    // addw       r[11:7],r[19:15],r[24:20]
    // subw       r[11:7],r[19:15],r[24:20]
    // sllw       r[11:7],r[19:15],r[24:20]
    // srlw       r[11:7],r[19:15],r[24:20]
    // sraw       r[11:7],r[19:15],r[24:20]
    // mulw       r[11:7],r[19:15],r[24:20]
    // divw       r[11:7],r[19:15],r[24:20]
    // divuw      r[11:7],r[19:15],r[24:20]
    // remw       r[11:7],r[19:15],r[24:20]
    // remuw      r[11:7],r[19:15],r[24:20]
    // lr.d       r[11:7],r[19:15]
    // sc.d       r[11:7],r[19:15],r[24:20]
    // amoswap.d  r[11:7],r[24:20],(r[19:15])
    // amoadd.d   r[11:7],r[24:20],(r[19:15])
    // amoxor.d   r[11:7],r[24:20],(r[19:15])
    // amoand.d   r[11:7],r[24:20],(r[19:15])
    // amoor.d    r[11:7],r[24:20],(r[19:15])
    // amomin.d   r[11:7],r[24:20],(r[19:15])
    // amomax.d   r[11:7],r[24:20],(r[19:15])
    // amominu.d  r[11:7],r[24:20],(r[19:15])
    // amomaxu.d  r[11:7],r[24:20],(r[19:15])
    // fcvt.l.s   r[11:7],f[19:15]
    // fcvt.lu.s  r[11:7],f[19:15]
    // fcvt.s.l   f[11:7],r[19:15]
    // fcvt.s.lu  f[11:7],r[19:15]
    // fcvt.l.d   r[11:7],f[19:15]
    // fcvt.lu.d  r[11:7],f[19:15]
    // fmv.x.d    r[11:7],f[19:15]
    // fcvt.d.l   f[11:7],r[19:15]
    // fcvt.d.lu  f[11:7],r[19:15]
    // fmv.d.x    f[11:7],r[19:15]
      return DecodeInst_LD_11 (inst); break;
    case 0x00 : 
    // Remaining Instruction is 9
    // c.addi4spn cr[4:2],u[12:5]
    // c.fld      cf[4:2],cr[9:7],u[6:5]|u[12:10]<<3
    // c.lw       cr[4:2],cr[9:7],u[5:5]|u[12:10]|u[6:6]<<2
    // c.flw      cr[4:2],cr[9:7],u[5:5]|u[12:10]|u[6:6]<<2
    // c.ld       cr[4:2],cr[9:7],u[6:5]|u[12:10]<<3
    // c.fsd      cr[4:2],cr[9:7],u[6:5]|u[12:10]<<3
    // c.sw       cr[4:2],cr[9:7],u[5:5]|u[12:10]|u[6:6]<<2
    // c.fsw      cr[4:2],cr[9:7],u[5:5]|u[12:10]|u[6:6]<<2
    // c.sd       cr[4:2],cr[9:7],u[6:5]|u[12:10]<<3
      return DecodeInst_LD_00 (inst); break;
    case 0x01 : 
    // Remaining Instruction is 21
    // c.nop     
    // c.addi     r[11:7],u[12:12]|u[6:2]
    // c.jal      u[12:12]|u[7:7]|u[10:9]|u[6:6]|u[7:7]|u[2:2]|u[11:11]|u[5:3]<<1
    // c.addiw    r[11:7],h[12:12]|h[6:2]
    // c.li       r[11:7],u[12:12]|h[6:2]
    // c.addi16sp cr[4:2],u[12:5]
    // c.lui      r[11:7],u[12:12]|h[6:2]
    // c.srli     cr[9:7],u[12:12]|h[6:2]
    // c.srli64   cr[9:7],u[12:12]|h[6:2]
    // c.srai     cr[9:7],u[12:12]|h[6:2]
    // c.srai64   cr[9:7],u[12:12]|h[6:2]
    // c.andi     cr[9:7],u[12:12]|h[6:2]
    // c.sub      cr[9:7],cr[4:2]
    // c.xor      cr[9:7],cr[4:2]
    // c.or       cr[9:7],cr[4:2]
    // c.and      cr[9:7],cr[4:2]
    // c.subw     cr[9:7],r[6:2]
    // c.addw     cr[9:7],r[6:2]
    // c.j        u[12:12]|u[8:8]|u[10:9]|u[6:6]|u[7:7]|u[2:2]|u[11:11]|u[5:3]<<1
    // c.beqz     cr[9:7],u[12:12]|u[6:5]|u[2:2]|u[11:10]|u[4:3]<<1
    // c.bnez     cr[9:7],u[12:12]|u[6:5]|u[2:2]|u[11:10]|u[4:3]<<1
      return DecodeInst_LD_01 (inst); break;
    case 0x02 : 
    // Remaining Instruction is 14
    // c.slli     r[11:7],u[12:12]|u[6:2]
    // c.fldsp    r[11:7],u[4:2]|u[12:12]|u[6:5]<<3 
    // c.lwsp     r[11:7],u[3:2]|u[12:12]|u[6:4]<<2
    // c.flwsp    f[11:7],u[3:2]|u[12:12]|u[6:4]<<2
    // c.ldsp     r[11:7],u[4:2]|u[12:12]|u[6:5]<<3
    // c.jr       r[11:7]
    // c.mv       r[11:7],r[6:2]
    // c.ebreak  
    // c.jalr     r[11:7]
    // c.add      r[11:7],r[6:2]
    // c.fsdsp    f[6:2],u[9:7]|u[12:10]<<3
    // c.swsp     r[6:2],u[8:7]|u[12:9]<<2
    // c.fswsp    f[6:2],u[9:7]|u[12:10]<<3
    // c.sdsp     r[6:2],u[9:7]|u[12:10]<<3
      return DecodeInst_LD_10 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11 (InstWord_t inst) {
  InstWord_t field_OP = ExtractOPField (inst);
  switch (field_OP) {
    case 0x0d : 
      return InstId_t::INST_ID_LUI;
    case 0x05 : 
      return InstId_t::INST_ID_AUIPC;
    case 0x1b : 
      return InstId_t::INST_ID_JAL;
    case 0x19 : 
      return InstId_t::INST_ID_JALR;
    case 0x18 : 
    // Remaining Instruction is 6
    // beq        r[19:15],r[24:20],u[31:31]|u[7:7]|u[30:25]|u[11:8]<<1
    // bne        r[19:15],r[24:20],u[31:31]|u[7:7]|u[30:25]|u[11:8]<<1
    // blt        r[19:15],r[24:20],u[31:31]|u[7:7]|u[30:25]|u[11:8]<<1
    // bge        r[19:15],r[24:20],u[31:31]|u[7:7]|u[30:25]|u[11:8]<<1
    // bltu       r[19:15],r[24:20],u[31:31]|u[7:7]|u[30:25]|u[11:8]<<1
    // bgeu       r[19:15],r[24:20],u[31:31]|u[7:7]|u[30:25]|u[11:8]<<1
      return DecodeInst_LD_11_OP_11000 (inst); break;
    case 0x00 : 
    // Remaining Instruction is 7
    // lb         r[11:7],h[31:20](r[19:15])
    // lh         r[11:7],h[31:20](r[19:15])
    // lw         r[11:7],h[31:20](r[19:15])
    // lbu        r[11:7],h[31:20](r[19:15])
    // lhu        r[11:7],h[31:20](r[19:15])
    // lwu        r[11:7],h[31:20](r[19:15])
    // ld         r[11:7],h[31:20](r[19:15])
      return DecodeInst_LD_11_OP_00000 (inst); break;
    case 0x08 : 
    // Remaining Instruction is 4
    // sb         r[24:20],h[31:25]|h[11:7](r[19:15])
    // sh         r[24:20],h[31:25]|h[11:7](r[19:15])
    // sw         r[24:20],h[31:25]|h[11:7](r[19:15])
    // sd         r[24:20],h[31:25]|h[11:7](r[19:15])
      return DecodeInst_LD_11_OP_01000 (inst); break;
    case 0x04 : 
    // Remaining Instruction is 9
    // addi       r[11:7],r[19:15],h[31:20]
    // slti       r[11:7],r[19:15],h[31:20]
    // sltiu      r[11:7],r[19:15],h[31:20]
    // xori       r[11:7],r[19:15],h[31:20]
    // ori        r[11:7],r[19:15],h[31:20]
    // andi       r[11:7],r[19:15],h[31:20]
    // slli       r[11:7],r[19:15],h[25:20]
    // srli       r[11:7],r[19:15],h[24:20]
    // srai       r[11:7],r[19:15],h[24:20]
      return DecodeInst_LD_11_OP_00100 (inst); break;
    case 0x0c : 
    // Remaining Instruction is 18
    // add        r[11:7],r[19:15],r[24:20]
    // sub        r[11:7],r[19:15],r[24:20]
    // sll        r[11:7],r[19:15],r[24:20]
    // slt        r[11:7],r[19:15],r[24:20]
    // sltu       r[11:7],r[19:15],r[24:20]
    // xor        r[11:7],r[19:15],r[24:20]
    // srl        r[11:7],r[19:15],r[24:20]
    // sra        r[11:7],r[19:15],r[24:20]
    // or         r[11:7],r[19:15],r[24:20]
    // and        r[11:7],r[19:15],r[24:20]
    // mul        r[11:7],r[19:15],r[24:20]
    // mulh       r[11:7],r[19:15],r[24:20]
    // mulhsu     r[11:7],r[19:15],r[24:20]
    // mulhu      r[11:7],r[19:15],r[24:20]
    // div        r[11:7],r[19:15],r[24:20]
    // divu       r[11:7],r[19:15],r[24:20]
    // rem        r[11:7],r[19:15],r[24:20]
    // remu       r[11:7],r[19:15],r[24:20]
      return DecodeInst_LD_11_OP_01100 (inst); break;
    case 0x03 : 
    // Remaining Instruction is 2
    // fence
    // fence.i
      return DecodeInst_LD_11_OP_00011 (inst); break;
    case 0x0b : 
    // Remaining Instruction is 22
    // lr.w       r[11:7],r[19:15]
    // sc.w       r[11:7],r[19:15],r[24:20]
    // amoswap.w  r[11:7],r[24:20],(r[19:15])
    // amoadd.w   r[11:7],r[24:20],(r[19:15])
    // amoxor.w   r[11:7],r[24:20],(r[19:15])
    // amoand.w   r[11:7],r[24:20],(r[19:15])
    // amoor.w    r[11:7],r[24:20],(r[19:15])
    // amomin.w   r[11:7],r[24:20],(r[19:15])
    // amomax.w   r[11:7],r[24:20],(r[19:15])
    // amominu.w  r[11:7],r[24:20],(r[19:15])
    // amomaxu.w  r[11:7],r[24:20],(r[19:15])
    // lr.d       r[11:7],r[19:15]
    // sc.d       r[11:7],r[19:15],r[24:20]
    // amoswap.d  r[11:7],r[24:20],(r[19:15])
    // amoadd.d   r[11:7],r[24:20],(r[19:15])
    // amoxor.d   r[11:7],r[24:20],(r[19:15])
    // amoand.d   r[11:7],r[24:20],(r[19:15])
    // amoor.d    r[11:7],r[24:20],(r[19:15])
    // amomin.d   r[11:7],r[24:20],(r[19:15])
    // amomax.d   r[11:7],r[24:20],(r[19:15])
    // amominu.d  r[11:7],r[24:20],(r[19:15])
    // amomaxu.d  r[11:7],r[24:20],(r[19:15])
      return DecodeInst_LD_11_OP_01011 (inst); break;
    case 0x01 : 
    // Remaining Instruction is 2
    // flw        f[11:7],h[31:20](r[19:15])
    // fld        f[11:7],r[19:15],h[31:20]
      return DecodeInst_LD_11_OP_00001 (inst); break;
    case 0x09 : 
    // Remaining Instruction is 2
    // fsw        f[24:20],h[31:25]|h[11:7](r[19:15])
    // fsd        f[24:20],h[31:25]|h[11:7](r[19:15])
      return DecodeInst_LD_11_OP_01001 (inst); break;
    case 0x10 : 
    // Remaining Instruction is 2
    // fmadd.s    f[11:7],f[19:15],f[24:20],f[31:27]
    // fmadd.d    f[11:7],f[19:15],f[24:20],f[31:27]
      return DecodeInst_LD_11_OP_10000 (inst); break;
    case 0x11 : 
    // Remaining Instruction is 2
    // fmsub.s    f[11:7],f[19:15],f[24:20],f[31:27]
    // fmsub.d    f[11:7],f[19:15],f[24:20],f[31:27]
      return DecodeInst_LD_11_OP_10001 (inst); break;
    case 0x12 : 
    // Remaining Instruction is 2
    // fnmsub.s   f[11:7],f[19:15],f[24:20],f[31:27]
    // fnmsub.d   f[11:7],f[19:15],f[24:20],f[31:27]
      return DecodeInst_LD_11_OP_10010 (inst); break;
    case 0x13 : 
    // Remaining Instruction is 2
    // fnmadd.s   f[11:7],f[19:15],f[24:20],f[31:27]
    // fnmadd.d   f[11:7],f[19:15],f[24:20],f[31:27]
      return DecodeInst_LD_11_OP_10011 (inst); break;
    case 0x14 : 
    // Remaining Instruction is 50
    // fadd.s     f[11:7],f[19:15],f[24:20]
    // fsub.s     f[11:7],f[19:15],f[24:20]
    // fmul.s     f[11:7],f[19:15],f[24:20]
    // fdiv.s     f[11:7],f[19:15],f[24:20]
    // fsqrt.s    f[11:7],f[19:15]
    // fsgnj.s    f[11:7],f[19:15],f[24:20]
    // fsgnjn.s   f[11:7],f[19:15],f[24:20]
    // fsgnjx.s   f[11:7],f[19:15],f[24:20]
    // fmin.s     f[11:7],f[19:15],f[24:20]
    // fmax.s     f[11:7],f[19:15],f[24:20]
    // fcvt.w.s   r[11:7],f[19:15]
    // fcvt.wu.s  r[11:7],f[19:15]
    // fmv.x.w    r[11:7],f[19:15]
    // feq.s      r[11:7],f[19:15],f[24:20]
    // flt.s      r[11:7],f[19:15],f[24:20]
    // fle.s      r[11:7],f[19:15],f[24:20]
    // fclass.s   f[11:7],f[19:15]
    // fcvt.s.w   f[11:7],r[19:15]
    // fcvt.s.wu  f[11:7],r[19:15]
    // fmv.w.x    f[11:7],r[19:15]
    // fadd.d     f[11:7],f[19:15],f[24:20]
    // fsub.d     f[11:7],f[19:15],f[24:20]
    // fmul.d     f[11:7],f[19:15],f[24:20]
    // fdiv.d     f[11:7],f[19:15],f[24:20]
    // fsqrt.d    f[11:7],f[19:15]
    // fsgnj.d    f[11:7],f[19:15],f[24:20]
    // fsgnjn.d   f[11:7],f[19:15],f[24:20]
    // fsgnjx.d   f[11:7],f[19:15],f[24:20]
    // fmin.d     f[11:7],f[19:15],f[24:20]
    // fmax.d     f[11:7],f[19:15],f[24:20]
    // fcvt.s.d   f[11:7],f[19:15]
    // fcvt.d.s   f[11:7],f[19:15]
    // feq.d      r[11:7],f[19:15],f[24:20]
    // flt.d      r[11:7],f[19:15],f[24:20]
    // fle.d      r[11:7],f[19:15],f[24:20]
    // fclass.d   r[11:7],f[19:15]
    // fcvt.w.d   r[11:7],f[19:15]
    // fcvt.wu.d  r[11:7],f[19:15]
    // fcvt.d.w   f[11:7],r[19:15]
    // fcvt.d.wu  f[11:7],r[19:15]
    // fcvt.l.s   r[11:7],f[19:15]
    // fcvt.lu.s  r[11:7],f[19:15]
    // fcvt.s.l   f[11:7],r[19:15]
    // fcvt.s.lu  f[11:7],r[19:15]
    // fcvt.l.d   r[11:7],f[19:15]
    // fcvt.lu.d  r[11:7],f[19:15]
    // fmv.x.d    r[11:7],f[19:15]
    // fcvt.d.l   f[11:7],r[19:15]
    // fcvt.d.lu  f[11:7],r[19:15]
    // fmv.d.x    f[11:7],r[19:15]
      return DecodeInst_LD_11_OP_10100 (inst); break;
    case 0x1c : 
    // Remaining Instruction is 16
    // csrrw      r[11:7],h[31:20],r[19:15]
    // csrrs      r[11:7],h[31:20],r[19:15]
    // csrrc      r[11:7],h[31:20],r[19:15]
    // csrrwi     r[11:7],h[31:20],h[19:15]
    // csrrsi     r[11:7],h[31:20],h[19:15]
    // csrrci     r[11:7],h[31:20],h[19:15]
    // ecall
    // ebreak
    // uret
    // sret
    // hret
    // mret
    // mrts
    // mrth
    // wfi
    // sfence.vma r[19:15],r[24:20]
      return DecodeInst_LD_11_OP_11100 (inst); break;
    case 0x06 : 
    // Remaining Instruction is 4
    // addiw      r[11:7],r[19:15],h[31:20]
    // slliw      r[11:7],r[19:15],r[24:20]
    // srliw      r[11:7],r[19:15],r[24:20]
    // sraiw      r[11:7],r[19:15],r[24:20]
      return DecodeInst_LD_11_OP_00110 (inst); break;
    case 0x0e : 
    // Remaining Instruction is 10
    // addw       r[11:7],r[19:15],r[24:20]
    // subw       r[11:7],r[19:15],r[24:20]
    // sllw       r[11:7],r[19:15],r[24:20]
    // srlw       r[11:7],r[19:15],r[24:20]
    // sraw       r[11:7],r[19:15],r[24:20]
    // mulw       r[11:7],r[19:15],r[24:20]
    // divw       r[11:7],r[19:15],r[24:20]
    // divuw      r[11:7],r[19:15],r[24:20]
    // remw       r[11:7],r[19:15],r[24:20]
    // remuw      r[11:7],r[19:15],r[24:20]
      return DecodeInst_LD_11_OP_01110 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_11000 (InstWord_t inst) {
  InstWord_t field_F3 = ExtractF3Field (inst);
  switch (field_F3) {
    case 0x00 : 
      return InstId_t::INST_ID_BEQ;
    case 0x01 : 
      return InstId_t::INST_ID_BNE;
    case 0x04 : 
      return InstId_t::INST_ID_BLT;
    case 0x05 : 
      return InstId_t::INST_ID_BGE;
    case 0x06 : 
      return InstId_t::INST_ID_BLTU;
    case 0x07 : 
      return InstId_t::INST_ID_BGEU;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_00000 (InstWord_t inst) {
  InstWord_t field_F3 = ExtractF3Field (inst);
  switch (field_F3) {
    case 0x00 : 
      return InstId_t::INST_ID_LB;
    case 0x01 : 
      return InstId_t::INST_ID_LH;
    case 0x02 : 
      return InstId_t::INST_ID_LW;
    case 0x04 : 
      return InstId_t::INST_ID_LBU;
    case 0x05 : 
      return InstId_t::INST_ID_LHU;
    case 0x06 : 
      return InstId_t::INST_ID_LWU;
    case 0x03 : 
      return InstId_t::INST_ID_LD;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_01000 (InstWord_t inst) {
  InstWord_t field_F3 = ExtractF3Field (inst);
  switch (field_F3) {
    case 0x00 : 
      return InstId_t::INST_ID_SB;
    case 0x01 : 
      return InstId_t::INST_ID_SH;
    case 0x02 : 
      return InstId_t::INST_ID_SW;
    case 0x03 : 
      return InstId_t::INST_ID_SD;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_00100 (InstWord_t inst) {
  InstWord_t field_F3 = ExtractF3Field (inst);
  switch (field_F3) {
    case 0x00 : 
      return InstId_t::INST_ID_ADDI;
    case 0x02 : 
      return InstId_t::INST_ID_SLTI;
    case 0x03 : 
      return InstId_t::INST_ID_SLTIU;
    case 0x04 : 
      return InstId_t::INST_ID_XORI;
    case 0x06 : 
      return InstId_t::INST_ID_ORI;
    case 0x07 : 
      return InstId_t::INST_ID_ANDI;
    case 0x01 : 
      return InstId_t::INST_ID_SLLI;
    case 0x05 : 
    // Remaining Instruction is 2
    // srli       r[11:7],r[19:15],h[24:20]
    // srai       r[11:7],r[19:15],h[24:20]
      return DecodeInst_LD_11_OP_00100_F3_101 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_00100_F3_101 (InstWord_t inst) {
  InstWord_t field_R3 = ExtractR3Field (inst);
  switch (field_R3) {
    case 0x00 : 
      return InstId_t::INST_ID_SRLI;
    case 0x08 : 
      return InstId_t::INST_ID_SRAI;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_01100 (InstWord_t inst) {
  InstWord_t field_R3 = ExtractR3Field (inst);
  switch (field_R3) {
    case 0x00 : 
    // Remaining Instruction is 16
    // add        r[11:7],r[19:15],r[24:20]
    // sll        r[11:7],r[19:15],r[24:20]
    // slt        r[11:7],r[19:15],r[24:20]
    // sltu       r[11:7],r[19:15],r[24:20]
    // xor        r[11:7],r[19:15],r[24:20]
    // srl        r[11:7],r[19:15],r[24:20]
    // or         r[11:7],r[19:15],r[24:20]
    // and        r[11:7],r[19:15],r[24:20]
    // mul        r[11:7],r[19:15],r[24:20]
    // mulh       r[11:7],r[19:15],r[24:20]
    // mulhsu     r[11:7],r[19:15],r[24:20]
    // mulhu      r[11:7],r[19:15],r[24:20]
    // div        r[11:7],r[19:15],r[24:20]
    // divu       r[11:7],r[19:15],r[24:20]
    // rem        r[11:7],r[19:15],r[24:20]
    // remu       r[11:7],r[19:15],r[24:20]
      return DecodeInst_LD_11_OP_01100_R3_00000 (inst); break;
    case 0x08 : 
    // Remaining Instruction is 2
    // sub        r[11:7],r[19:15],r[24:20]
    // sra        r[11:7],r[19:15],r[24:20]
      return DecodeInst_LD_11_OP_01100_R3_01000 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_01100_R3_00000 (InstWord_t inst) {
  InstWord_t field_F2 = ExtractF2Field (inst);
  switch (field_F2) {
    case 0x00 : 
    // Remaining Instruction is 8
    // add        r[11:7],r[19:15],r[24:20]
    // sll        r[11:7],r[19:15],r[24:20]
    // slt        r[11:7],r[19:15],r[24:20]
    // sltu       r[11:7],r[19:15],r[24:20]
    // xor        r[11:7],r[19:15],r[24:20]
    // srl        r[11:7],r[19:15],r[24:20]
    // or         r[11:7],r[19:15],r[24:20]
    // and        r[11:7],r[19:15],r[24:20]
      return DecodeInst_LD_11_OP_01100_R3_00000_F2_00 (inst); break;
    case 0x01 : 
    // Remaining Instruction is 8
    // mul        r[11:7],r[19:15],r[24:20]
    // mulh       r[11:7],r[19:15],r[24:20]
    // mulhsu     r[11:7],r[19:15],r[24:20]
    // mulhu      r[11:7],r[19:15],r[24:20]
    // div        r[11:7],r[19:15],r[24:20]
    // divu       r[11:7],r[19:15],r[24:20]
    // rem        r[11:7],r[19:15],r[24:20]
    // remu       r[11:7],r[19:15],r[24:20]
      return DecodeInst_LD_11_OP_01100_R3_00000_F2_01 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_01100_R3_00000_F2_00 (InstWord_t inst) {
  InstWord_t field_F3 = ExtractF3Field (inst);
  switch (field_F3) {
    case 0x00 : 
      return InstId_t::INST_ID_ADD;
    case 0x01 : 
      return InstId_t::INST_ID_SLL;
    case 0x02 : 
      return InstId_t::INST_ID_SLT;
    case 0x03 : 
      return InstId_t::INST_ID_SLTU;
    case 0x04 : 
      return InstId_t::INST_ID_XOR;
    case 0x05 : 
      return InstId_t::INST_ID_SRL;
    case 0x06 : 
      return InstId_t::INST_ID_OR;
    case 0x07 : 
      return InstId_t::INST_ID_AND;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_01100_R3_00000_F2_01 (InstWord_t inst) {
  InstWord_t field_F3 = ExtractF3Field (inst);
  switch (field_F3) {
    case 0x00 : 
      return InstId_t::INST_ID_MUL;
    case 0x01 : 
      return InstId_t::INST_ID_MULH;
    case 0x02 : 
      return InstId_t::INST_ID_MULHSU;
    case 0x03 : 
      return InstId_t::INST_ID_MULHU;
    case 0x04 : 
      return InstId_t::INST_ID_DIV;
    case 0x05 : 
      return InstId_t::INST_ID_DIVU;
    case 0x06 : 
      return InstId_t::INST_ID_REM;
    case 0x07 : 
      return InstId_t::INST_ID_REMU;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_01100_R3_01000 (InstWord_t inst) {
  InstWord_t field_F2 = ExtractF2Field (inst);
  switch (field_F2) {
    case 0x00 : 
    // Remaining Instruction is 2
    // sub        r[11:7],r[19:15],r[24:20]
    // sra        r[11:7],r[19:15],r[24:20]
      return DecodeInst_LD_11_OP_01100_R3_01000_F2_00 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_01100_R3_01000_F2_00 (InstWord_t inst) {
  InstWord_t field_F3 = ExtractF3Field (inst);
  switch (field_F3) {
    case 0x00 : 
      return InstId_t::INST_ID_SUB;
    case 0x05 : 
      return InstId_t::INST_ID_SRA;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_00011 (InstWord_t inst) {
  InstWord_t field_R1 = ExtractR1Field (inst);
  switch (field_R1) {
    case 0x00 : 
    // Remaining Instruction is 2
    // fence
    // fence.i
      return DecodeInst_LD_11_OP_00011_R1_00000 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_00011_R1_00000 (InstWord_t inst) {
  InstWord_t field_F3 = ExtractF3Field (inst);
  switch (field_F3) {
    case 0x00 : 
      return InstId_t::INST_ID_FENCE;
    case 0x01 : 
      return InstId_t::INST_ID_FENCE_I;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_01011 (InstWord_t inst) {
  InstWord_t field_R3 = ExtractR3Field (inst);
  switch (field_R3) {
    case 0x02 : 
    // Remaining Instruction is 2
    // lr.w       r[11:7],r[19:15]
    // lr.d       r[11:7],r[19:15]
      return DecodeInst_LD_11_OP_01011_R3_00010 (inst); break;
    case 0x03 : 
    // Remaining Instruction is 2
    // sc.w       r[11:7],r[19:15],r[24:20]
    // sc.d       r[11:7],r[19:15],r[24:20]
      return DecodeInst_LD_11_OP_01011_R3_00011 (inst); break;
    case 0x01 : 
    // Remaining Instruction is 2
    // amoswap.w  r[11:7],r[24:20],(r[19:15])
    // amoswap.d  r[11:7],r[24:20],(r[19:15])
      return DecodeInst_LD_11_OP_01011_R3_00001 (inst); break;
    case 0x00 : 
    // Remaining Instruction is 2
    // amoadd.w   r[11:7],r[24:20],(r[19:15])
    // amoadd.d   r[11:7],r[24:20],(r[19:15])
      return DecodeInst_LD_11_OP_01011_R3_00000 (inst); break;
    case 0x04 : 
    // Remaining Instruction is 2
    // amoxor.w   r[11:7],r[24:20],(r[19:15])
    // amoxor.d   r[11:7],r[24:20],(r[19:15])
      return DecodeInst_LD_11_OP_01011_R3_00100 (inst); break;
    case 0x0c : 
    // Remaining Instruction is 2
    // amoand.w   r[11:7],r[24:20],(r[19:15])
    // amoand.d   r[11:7],r[24:20],(r[19:15])
      return DecodeInst_LD_11_OP_01011_R3_01100 (inst); break;
    case 0x08 : 
    // Remaining Instruction is 2
    // amoor.w    r[11:7],r[24:20],(r[19:15])
    // amoor.d    r[11:7],r[24:20],(r[19:15])
      return DecodeInst_LD_11_OP_01011_R3_01000 (inst); break;
    case 0x10 : 
    // Remaining Instruction is 2
    // amomin.w   r[11:7],r[24:20],(r[19:15])
    // amomin.d   r[11:7],r[24:20],(r[19:15])
      return DecodeInst_LD_11_OP_01011_R3_10000 (inst); break;
    case 0x14 : 
    // Remaining Instruction is 2
    // amomax.w   r[11:7],r[24:20],(r[19:15])
    // amomax.d   r[11:7],r[24:20],(r[19:15])
      return DecodeInst_LD_11_OP_01011_R3_10100 (inst); break;
    case 0x18 : 
    // Remaining Instruction is 2
    // amominu.w  r[11:7],r[24:20],(r[19:15])
    // amominu.d  r[11:7],r[24:20],(r[19:15])
      return DecodeInst_LD_11_OP_01011_R3_11000 (inst); break;
    case 0x1c : 
    // Remaining Instruction is 2
    // amomaxu.w  r[11:7],r[24:20],(r[19:15])
    // amomaxu.d  r[11:7],r[24:20],(r[19:15])
      return DecodeInst_LD_11_OP_01011_R3_11100 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_01011_R3_00010 (InstWord_t inst) {
  InstWord_t field_R2 = ExtractR2Field (inst);
  switch (field_R2) {
    case 0x00 : 
    // Remaining Instruction is 2
    // lr.w       r[11:7],r[19:15]
    // lr.d       r[11:7],r[19:15]
      return DecodeInst_LD_11_OP_01011_R3_00010_R2_00000 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_01011_R3_00010_R2_00000 (InstWord_t inst) {
  InstWord_t field_F3 = ExtractF3Field (inst);
  switch (field_F3) {
    case 0x02 : 
      return InstId_t::INST_ID_LR_W;
    case 0x03 : 
      return InstId_t::INST_ID_LR_D;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_01011_R3_00011 (InstWord_t inst) {
  InstWord_t field_F3 = ExtractF3Field (inst);
  switch (field_F3) {
    case 0x02 : 
      return InstId_t::INST_ID_SC_W;
    case 0x03 : 
      return InstId_t::INST_ID_SC_D;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_01011_R3_00001 (InstWord_t inst) {
  InstWord_t field_F3 = ExtractF3Field (inst);
  switch (field_F3) {
    case 0x02 : 
      return InstId_t::INST_ID_AMOSWAP_W;
    case 0x03 : 
      return InstId_t::INST_ID_AMOSWAP_D;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_01011_R3_00000 (InstWord_t inst) {
  InstWord_t field_F3 = ExtractF3Field (inst);
  switch (field_F3) {
    case 0x02 : 
      return InstId_t::INST_ID_AMOADD_W;
    case 0x03 : 
      return InstId_t::INST_ID_AMOADD_D;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_01011_R3_00100 (InstWord_t inst) {
  InstWord_t field_F3 = ExtractF3Field (inst);
  switch (field_F3) {
    case 0x02 : 
      return InstId_t::INST_ID_AMOXOR_W;
    case 0x03 : 
      return InstId_t::INST_ID_AMOXOR_D;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_01011_R3_01100 (InstWord_t inst) {
  InstWord_t field_F3 = ExtractF3Field (inst);
  switch (field_F3) {
    case 0x02 : 
      return InstId_t::INST_ID_AMOAND_W;
    case 0x03 : 
      return InstId_t::INST_ID_AMOAND_D;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_01011_R3_01000 (InstWord_t inst) {
  InstWord_t field_F3 = ExtractF3Field (inst);
  switch (field_F3) {
    case 0x02 : 
      return InstId_t::INST_ID_AMOOR_W;
    case 0x03 : 
      return InstId_t::INST_ID_AMOOR_D;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_01011_R3_10000 (InstWord_t inst) {
  InstWord_t field_F3 = ExtractF3Field (inst);
  switch (field_F3) {
    case 0x02 : 
      return InstId_t::INST_ID_AMOMIN_W;
    case 0x03 : 
      return InstId_t::INST_ID_AMOMIN_D;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_01011_R3_10100 (InstWord_t inst) {
  InstWord_t field_F3 = ExtractF3Field (inst);
  switch (field_F3) {
    case 0x02 : 
      return InstId_t::INST_ID_AMOMAX_W;
    case 0x03 : 
      return InstId_t::INST_ID_AMOMAX_D;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_01011_R3_11000 (InstWord_t inst) {
  InstWord_t field_F3 = ExtractF3Field (inst);
  switch (field_F3) {
    case 0x02 : 
      return InstId_t::INST_ID_AMOMINU_W;
    case 0x03 : 
      return InstId_t::INST_ID_AMOMINU_D;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_01011_R3_11100 (InstWord_t inst) {
  InstWord_t field_F3 = ExtractF3Field (inst);
  switch (field_F3) {
    case 0x02 : 
      return InstId_t::INST_ID_AMOMAXU_W;
    case 0x03 : 
      return InstId_t::INST_ID_AMOMAXU_D;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_00001 (InstWord_t inst) {
  InstWord_t field_F3 = ExtractF3Field (inst);
  switch (field_F3) {
    case 0x02 : 
      return InstId_t::INST_ID_FLW;
    case 0x03 : 
      return InstId_t::INST_ID_FLD;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_01001 (InstWord_t inst) {
  InstWord_t field_F3 = ExtractF3Field (inst);
  switch (field_F3) {
    case 0x02 : 
      return InstId_t::INST_ID_FSW;
    case 0x03 : 
      return InstId_t::INST_ID_FSD;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_10000 (InstWord_t inst) {
  InstWord_t field_F2 = ExtractF2Field (inst);
  switch (field_F2) {
    case 0x00 : 
      return InstId_t::INST_ID_FMADD_S;
    case 0x01 : 
      return InstId_t::INST_ID_FMADD_D;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_10001 (InstWord_t inst) {
  InstWord_t field_F2 = ExtractF2Field (inst);
  switch (field_F2) {
    case 0x00 : 
      return InstId_t::INST_ID_FMSUB_S;
    case 0x01 : 
      return InstId_t::INST_ID_FMSUB_D;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_10010 (InstWord_t inst) {
  InstWord_t field_F2 = ExtractF2Field (inst);
  switch (field_F2) {
    case 0x00 : 
      return InstId_t::INST_ID_FNMSUB_S;
    case 0x01 : 
      return InstId_t::INST_ID_FNMSUB_D;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_10011 (InstWord_t inst) {
  InstWord_t field_F2 = ExtractF2Field (inst);
  switch (field_F2) {
    case 0x00 : 
      return InstId_t::INST_ID_FNMADD_S;
    case 0x01 : 
      return InstId_t::INST_ID_FNMADD_D;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_10100 (InstWord_t inst) {
  InstWord_t field_R3 = ExtractR3Field (inst);
  switch (field_R3) {
    case 0x00 : 
    // Remaining Instruction is 2
    // fadd.s     f[11:7],f[19:15],f[24:20]
    // fadd.d     f[11:7],f[19:15],f[24:20]
      return DecodeInst_LD_11_OP_10100_R3_00000 (inst); break;
    case 0x01 : 
    // Remaining Instruction is 2
    // fsub.s     f[11:7],f[19:15],f[24:20]
    // fsub.d     f[11:7],f[19:15],f[24:20]
      return DecodeInst_LD_11_OP_10100_R3_00001 (inst); break;
    case 0x02 : 
    // Remaining Instruction is 2
    // fmul.s     f[11:7],f[19:15],f[24:20]
    // fmul.d     f[11:7],f[19:15],f[24:20]
      return DecodeInst_LD_11_OP_10100_R3_00010 (inst); break;
    case 0x03 : 
    // Remaining Instruction is 2
    // fdiv.s     f[11:7],f[19:15],f[24:20]
    // fdiv.d     f[11:7],f[19:15],f[24:20]
      return DecodeInst_LD_11_OP_10100_R3_00011 (inst); break;
    case 0x0b : 
    // Remaining Instruction is 2
    // fsqrt.s    f[11:7],f[19:15]
    // fsqrt.d    f[11:7],f[19:15]
      return DecodeInst_LD_11_OP_10100_R3_01011 (inst); break;
    case 0x04 : 
    // Remaining Instruction is 6
    // fsgnj.s    f[11:7],f[19:15],f[24:20]
    // fsgnjn.s   f[11:7],f[19:15],f[24:20]
    // fsgnjx.s   f[11:7],f[19:15],f[24:20]
    // fsgnj.d    f[11:7],f[19:15],f[24:20]
    // fsgnjn.d   f[11:7],f[19:15],f[24:20]
    // fsgnjx.d   f[11:7],f[19:15],f[24:20]
      return DecodeInst_LD_11_OP_10100_R3_00100 (inst); break;
    case 0x05 : 
    // Remaining Instruction is 4
    // fmin.s     f[11:7],f[19:15],f[24:20]
    // fmax.s     f[11:7],f[19:15],f[24:20]
    // fmin.d     f[11:7],f[19:15],f[24:20]
    // fmax.d     f[11:7],f[19:15],f[24:20]
      return DecodeInst_LD_11_OP_10100_R3_00101 (inst); break;
    case 0x18 : 
    // Remaining Instruction is 8
    // fcvt.w.s   r[11:7],f[19:15]
    // fcvt.wu.s  r[11:7],f[19:15]
    // fcvt.w.d   r[11:7],f[19:15]
    // fcvt.wu.d  r[11:7],f[19:15]
    // fcvt.l.s   r[11:7],f[19:15]
    // fcvt.lu.s  r[11:7],f[19:15]
    // fcvt.l.d   r[11:7],f[19:15]
    // fcvt.lu.d  r[11:7],f[19:15]
      return DecodeInst_LD_11_OP_10100_R3_11000 (inst); break;
    case 0x1c : 
    // Remaining Instruction is 4
    // fmv.x.w    r[11:7],f[19:15]
    // fclass.s   f[11:7],f[19:15]
    // fclass.d   r[11:7],f[19:15]
    // fmv.x.d    r[11:7],f[19:15]
      return DecodeInst_LD_11_OP_10100_R3_11100 (inst); break;
    case 0x14 : 
    // Remaining Instruction is 6
    // feq.s      r[11:7],f[19:15],f[24:20]
    // flt.s      r[11:7],f[19:15],f[24:20]
    // fle.s      r[11:7],f[19:15],f[24:20]
    // feq.d      r[11:7],f[19:15],f[24:20]
    // flt.d      r[11:7],f[19:15],f[24:20]
    // fle.d      r[11:7],f[19:15],f[24:20]
      return DecodeInst_LD_11_OP_10100_R3_10100 (inst); break;
    case 0x1a : 
    // Remaining Instruction is 8
    // fcvt.s.w   f[11:7],r[19:15]
    // fcvt.s.wu  f[11:7],r[19:15]
    // fcvt.d.w   f[11:7],r[19:15]
    // fcvt.d.wu  f[11:7],r[19:15]
    // fcvt.s.l   f[11:7],r[19:15]
    // fcvt.s.lu  f[11:7],r[19:15]
    // fcvt.d.l   f[11:7],r[19:15]
    // fcvt.d.lu  f[11:7],r[19:15]
      return DecodeInst_LD_11_OP_10100_R3_11010 (inst); break;
    case 0x1e : 
    // Remaining Instruction is 2
    // fmv.w.x    f[11:7],r[19:15]
    // fmv.d.x    f[11:7],r[19:15]
      return DecodeInst_LD_11_OP_10100_R3_11110 (inst); break;
    case 0x08 : 
    // Remaining Instruction is 2
    // fcvt.s.d   f[11:7],f[19:15]
    // fcvt.d.s   f[11:7],f[19:15]
      return DecodeInst_LD_11_OP_10100_R3_01000 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_10100_R3_00000 (InstWord_t inst) {
  InstWord_t field_F2 = ExtractF2Field (inst);
  switch (field_F2) {
    case 0x00 : 
      return InstId_t::INST_ID_FADD_S;
    case 0x01 : 
      return InstId_t::INST_ID_FADD_D;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_10100_R3_00001 (InstWord_t inst) {
  InstWord_t field_F2 = ExtractF2Field (inst);
  switch (field_F2) {
    case 0x00 : 
      return InstId_t::INST_ID_FSUB_S;
    case 0x01 : 
      return InstId_t::INST_ID_FSUB_D;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_10100_R3_00010 (InstWord_t inst) {
  InstWord_t field_F2 = ExtractF2Field (inst);
  switch (field_F2) {
    case 0x00 : 
      return InstId_t::INST_ID_FMUL_S;
    case 0x01 : 
      return InstId_t::INST_ID_FMUL_D;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_10100_R3_00011 (InstWord_t inst) {
  InstWord_t field_F2 = ExtractF2Field (inst);
  switch (field_F2) {
    case 0x00 : 
      return InstId_t::INST_ID_FDIV_S;
    case 0x01 : 
      return InstId_t::INST_ID_FDIV_D;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_10100_R3_01011 (InstWord_t inst) {
  InstWord_t field_F2 = ExtractF2Field (inst);
  switch (field_F2) {
    case 0x00 : 
      return InstId_t::INST_ID_FSQRT_S;
    case 0x01 : 
      return InstId_t::INST_ID_FSQRT_D;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_10100_R3_00100 (InstWord_t inst) {
  InstWord_t field_F2 = ExtractF2Field (inst);
  switch (field_F2) {
    case 0x00 : 
    // Remaining Instruction is 3
    // fsgnj.s    f[11:7],f[19:15],f[24:20]
    // fsgnjn.s   f[11:7],f[19:15],f[24:20]
    // fsgnjx.s   f[11:7],f[19:15],f[24:20]
      return DecodeInst_LD_11_OP_10100_R3_00100_F2_00 (inst); break;
    case 0x01 : 
    // Remaining Instruction is 3
    // fsgnj.d    f[11:7],f[19:15],f[24:20]
    // fsgnjn.d   f[11:7],f[19:15],f[24:20]
    // fsgnjx.d   f[11:7],f[19:15],f[24:20]
      return DecodeInst_LD_11_OP_10100_R3_00100_F2_01 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_10100_R3_00100_F2_00 (InstWord_t inst) {
  InstWord_t field_F3 = ExtractF3Field (inst);
  switch (field_F3) {
    case 0x00 : 
      return InstId_t::INST_ID_FSGNJ_S;
    case 0x01 : 
      return InstId_t::INST_ID_FSGNJN_S;
    case 0x02 : 
      return InstId_t::INST_ID_FSGNJX_S;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_10100_R3_00100_F2_01 (InstWord_t inst) {
  InstWord_t field_F3 = ExtractF3Field (inst);
  switch (field_F3) {
    case 0x00 : 
      return InstId_t::INST_ID_FSGNJ_D;
    case 0x01 : 
      return InstId_t::INST_ID_FSGNJN_D;
    case 0x02 : 
      return InstId_t::INST_ID_FSGNJX_D;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_10100_R3_00101 (InstWord_t inst) {
  InstWord_t field_F2 = ExtractF2Field (inst);
  switch (field_F2) {
    case 0x00 : 
    // Remaining Instruction is 2
    // fmin.s     f[11:7],f[19:15],f[24:20]
    // fmax.s     f[11:7],f[19:15],f[24:20]
      return DecodeInst_LD_11_OP_10100_R3_00101_F2_00 (inst); break;
    case 0x01 : 
    // Remaining Instruction is 2
    // fmin.d     f[11:7],f[19:15],f[24:20]
    // fmax.d     f[11:7],f[19:15],f[24:20]
      return DecodeInst_LD_11_OP_10100_R3_00101_F2_01 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_10100_R3_00101_F2_00 (InstWord_t inst) {
  InstWord_t field_F3 = ExtractF3Field (inst);
  switch (field_F3) {
    case 0x00 : 
      return InstId_t::INST_ID_FMIN_S;
    case 0x01 : 
      return InstId_t::INST_ID_FMAX_S;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_10100_R3_00101_F2_01 (InstWord_t inst) {
  InstWord_t field_F3 = ExtractF3Field (inst);
  switch (field_F3) {
    case 0x00 : 
      return InstId_t::INST_ID_FMIN_D;
    case 0x01 : 
      return InstId_t::INST_ID_FMAX_D;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_10100_R3_11000 (InstWord_t inst) {
  InstWord_t field_F2 = ExtractF2Field (inst);
  switch (field_F2) {
    case 0x00 : 
    // Remaining Instruction is 4
    // fcvt.w.s   r[11:7],f[19:15]
    // fcvt.wu.s  r[11:7],f[19:15]
    // fcvt.l.s   r[11:7],f[19:15]
    // fcvt.lu.s  r[11:7],f[19:15]
      return DecodeInst_LD_11_OP_10100_R3_11000_F2_00 (inst); break;
    case 0x01 : 
    // Remaining Instruction is 4
    // fcvt.w.d   r[11:7],f[19:15]
    // fcvt.wu.d  r[11:7],f[19:15]
    // fcvt.l.d   r[11:7],f[19:15]
    // fcvt.lu.d  r[11:7],f[19:15]
      return DecodeInst_LD_11_OP_10100_R3_11000_F2_01 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_10100_R3_11000_F2_00 (InstWord_t inst) {
  InstWord_t field_R2 = ExtractR2Field (inst);
  switch (field_R2) {
    case 0x00 : 
      return InstId_t::INST_ID_FCVT_W_S;
    case 0x01 : 
      return InstId_t::INST_ID_FCVT_WU_S;
    case 0x02 : 
      return InstId_t::INST_ID_FCVT_L_S;
    case 0x03 : 
      return InstId_t::INST_ID_FCVT_LU_S;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_10100_R3_11000_F2_01 (InstWord_t inst) {
  InstWord_t field_R2 = ExtractR2Field (inst);
  switch (field_R2) {
    case 0x00 : 
      return InstId_t::INST_ID_FCVT_W_D;
    case 0x01 : 
      return InstId_t::INST_ID_FCVT_WU_D;
    case 0x02 : 
      return InstId_t::INST_ID_FCVT_L_D;
    case 0x03 : 
      return InstId_t::INST_ID_FCVT_LU_D;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_10100_R3_11100 (InstWord_t inst) {
  InstWord_t field_F2 = ExtractF2Field (inst);
  switch (field_F2) {
    case 0x00 : 
    // Remaining Instruction is 2
    // fmv.x.w    r[11:7],f[19:15]
    // fclass.s   f[11:7],f[19:15]
      return DecodeInst_LD_11_OP_10100_R3_11100_F2_00 (inst); break;
    case 0x01 : 
    // Remaining Instruction is 2
    // fclass.d   r[11:7],f[19:15]
    // fmv.x.d    r[11:7],f[19:15]
      return DecodeInst_LD_11_OP_10100_R3_11100_F2_01 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_10100_R3_11100_F2_00 (InstWord_t inst) {
  InstWord_t field_R2 = ExtractR2Field (inst);
  switch (field_R2) {
    case 0x00 : 
    // Remaining Instruction is 2
    // fmv.x.w    r[11:7],f[19:15]
    // fclass.s   f[11:7],f[19:15]
      return DecodeInst_LD_11_OP_10100_R3_11100_F2_00_R2_00000 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_10100_R3_11100_F2_00_R2_00000 (InstWord_t inst) {
  InstWord_t field_F3 = ExtractF3Field (inst);
  switch (field_F3) {
    case 0x00 : 
      return InstId_t::INST_ID_FMV_X_W;
    case 0x01 : 
      return InstId_t::INST_ID_FCLASS_S;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_10100_R3_11100_F2_01 (InstWord_t inst) {
  InstWord_t field_R2 = ExtractR2Field (inst);
  switch (field_R2) {
    case 0x00 : 
    // Remaining Instruction is 2
    // fclass.d   r[11:7],f[19:15]
    // fmv.x.d    r[11:7],f[19:15]
      return DecodeInst_LD_11_OP_10100_R3_11100_F2_01_R2_00000 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_10100_R3_11100_F2_01_R2_00000 (InstWord_t inst) {
  InstWord_t field_F3 = ExtractF3Field (inst);
  switch (field_F3) {
    case 0x01 : 
      return InstId_t::INST_ID_FCLASS_D;
    case 0x00 : 
      return InstId_t::INST_ID_FMV_X_D;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_10100_R3_10100 (InstWord_t inst) {
  InstWord_t field_F2 = ExtractF2Field (inst);
  switch (field_F2) {
    case 0x00 : 
    // Remaining Instruction is 3
    // feq.s      r[11:7],f[19:15],f[24:20]
    // flt.s      r[11:7],f[19:15],f[24:20]
    // fle.s      r[11:7],f[19:15],f[24:20]
      return DecodeInst_LD_11_OP_10100_R3_10100_F2_00 (inst); break;
    case 0x01 : 
    // Remaining Instruction is 3
    // feq.d      r[11:7],f[19:15],f[24:20]
    // flt.d      r[11:7],f[19:15],f[24:20]
    // fle.d      r[11:7],f[19:15],f[24:20]
      return DecodeInst_LD_11_OP_10100_R3_10100_F2_01 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_10100_R3_10100_F2_00 (InstWord_t inst) {
  InstWord_t field_F3 = ExtractF3Field (inst);
  switch (field_F3) {
    case 0x02 : 
      return InstId_t::INST_ID_FEQ_S;
    case 0x01 : 
      return InstId_t::INST_ID_FLT_S;
    case 0x00 : 
      return InstId_t::INST_ID_FLE_S;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_10100_R3_10100_F2_01 (InstWord_t inst) {
  InstWord_t field_F3 = ExtractF3Field (inst);
  switch (field_F3) {
    case 0x02 : 
      return InstId_t::INST_ID_FEQ_D;
    case 0x01 : 
      return InstId_t::INST_ID_FLT_D;
    case 0x00 : 
      return InstId_t::INST_ID_FLE_D;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_10100_R3_11010 (InstWord_t inst) {
  InstWord_t field_F2 = ExtractF2Field (inst);
  switch (field_F2) {
    case 0x00 : 
    // Remaining Instruction is 4
    // fcvt.s.w   f[11:7],r[19:15]
    // fcvt.s.wu  f[11:7],r[19:15]
    // fcvt.s.l   f[11:7],r[19:15]
    // fcvt.s.lu  f[11:7],r[19:15]
      return DecodeInst_LD_11_OP_10100_R3_11010_F2_00 (inst); break;
    case 0x01 : 
    // Remaining Instruction is 4
    // fcvt.d.w   f[11:7],r[19:15]
    // fcvt.d.wu  f[11:7],r[19:15]
    // fcvt.d.l   f[11:7],r[19:15]
    // fcvt.d.lu  f[11:7],r[19:15]
      return DecodeInst_LD_11_OP_10100_R3_11010_F2_01 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_10100_R3_11010_F2_00 (InstWord_t inst) {
  InstWord_t field_R2 = ExtractR2Field (inst);
  switch (field_R2) {
    case 0x00 : 
      return InstId_t::INST_ID_FCVT_S_W;
    case 0x01 : 
      return InstId_t::INST_ID_FCVT_S_WU;
    case 0x02 : 
      return InstId_t::INST_ID_FCVT_S_L;
    case 0x03 : 
      return InstId_t::INST_ID_FCVT_S_LU;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_10100_R3_11010_F2_01 (InstWord_t inst) {
  InstWord_t field_R2 = ExtractR2Field (inst);
  switch (field_R2) {
    case 0x00 : 
      return InstId_t::INST_ID_FCVT_D_W;
    case 0x01 : 
      return InstId_t::INST_ID_FCVT_D_WU;
    case 0x02 : 
      return InstId_t::INST_ID_FCVT_D_L;
    case 0x03 : 
      return InstId_t::INST_ID_FCVT_D_LU;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_10100_R3_11110 (InstWord_t inst) {
  InstWord_t field_F2 = ExtractF2Field (inst);
  switch (field_F2) {
    case 0x00 : 
      return InstId_t::INST_ID_FMV_W_X;
    case 0x01 : 
      return InstId_t::INST_ID_FMV_D_X;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_10100_R3_01000 (InstWord_t inst) {
  InstWord_t field_F2 = ExtractF2Field (inst);
  switch (field_F2) {
    case 0x00 : 
      return InstId_t::INST_ID_FCVT_S_D;
    case 0x01 : 
      return InstId_t::INST_ID_FCVT_D_S;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_11100 (InstWord_t inst) {
  InstWord_t field_F3 = ExtractF3Field (inst);
  switch (field_F3) {
    case 0x01 : 
      return InstId_t::INST_ID_CSRRW;
    case 0x02 : 
      return InstId_t::INST_ID_CSRRS;
    case 0x03 : 
      return InstId_t::INST_ID_CSRRC;
    case 0x05 : 
      return InstId_t::INST_ID_CSRRWI;
    case 0x06 : 
      return InstId_t::INST_ID_CSRRSI;
    case 0x07 : 
      return InstId_t::INST_ID_CSRRCI;
    case 0x00 : 
    // Remaining Instruction is 10
    // ecall
    // ebreak
    // uret
    // sret
    // hret
    // mret
    // mrts
    // mrth
    // wfi
    // sfence.vma r[19:15],r[24:20]
      return DecodeInst_LD_11_OP_11100_F3_000 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_11100_F3_000 (InstWord_t inst) {
  InstWord_t field_R3 = ExtractR3Field (inst);
  switch (field_R3) {
    case 0x00 : 
    // Remaining Instruction is 3
    // ecall
    // ebreak
    // uret
      return DecodeInst_LD_11_OP_11100_F3_000_R3_00000 (inst); break;
    case 0x02 : 
    // Remaining Instruction is 3
    // sret
    // wfi
    // sfence.vma r[19:15],r[24:20]
      return DecodeInst_LD_11_OP_11100_F3_000_R3_00010 (inst); break;
    case 0x04 : 
    // Remaining Instruction is 2
    // hret
    // mrth
      return DecodeInst_LD_11_OP_11100_F3_000_R3_00100 (inst); break;
    case 0x06 : 
    // Remaining Instruction is 2
    // mret
    // mrts
      return DecodeInst_LD_11_OP_11100_F3_000_R3_00110 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_11100_F3_000_R3_00000 (InstWord_t inst) {
  InstWord_t field_F2 = ExtractF2Field (inst);
  switch (field_F2) {
    case 0x00 : 
    // Remaining Instruction is 3
    // ecall
    // ebreak
    // uret
      return DecodeInst_LD_11_OP_11100_F3_000_R3_00000_F2_00 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_11100_F3_000_R3_00000_F2_00 (InstWord_t inst) {
  InstWord_t field_R2 = ExtractR2Field (inst);
  switch (field_R2) {
    case 0x00 : 
      return InstId_t::INST_ID_ECALL;
    case 0x01 : 
      return InstId_t::INST_ID_EBREAK;
    case 0x02 : 
      return InstId_t::INST_ID_URET;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_11100_F3_000_R3_00010 (InstWord_t inst) {
  InstWord_t field_F2 = ExtractF2Field (inst);
  switch (field_F2) {
    case 0x00 : 
    // Remaining Instruction is 2
    // sret
    // wfi
      return DecodeInst_LD_11_OP_11100_F3_000_R3_00010_F2_00 (inst); break;
    case 0x01 : 
      return InstId_t::INST_ID_SFENCE_VMA;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_11100_F3_000_R3_00010_F2_00 (InstWord_t inst) {
  InstWord_t field_R2 = ExtractR2Field (inst);
  switch (field_R2) {
    case 0x02 : 
      return InstId_t::INST_ID_SRET;
    case 0x05 : 
      return InstId_t::INST_ID_WFI;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_11100_F3_000_R3_00100 (InstWord_t inst) {
  InstWord_t field_F2 = ExtractF2Field (inst);
  switch (field_F2) {
    case 0x00 : 
    // Remaining Instruction is 2
    // hret
    // mrth
      return DecodeInst_LD_11_OP_11100_F3_000_R3_00100_F2_00 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_11100_F3_000_R3_00100_F2_00 (InstWord_t inst) {
  InstWord_t field_R2 = ExtractR2Field (inst);
  switch (field_R2) {
    case 0x02 : 
      return InstId_t::INST_ID_HRET;
    case 0x06 : 
      return InstId_t::INST_ID_MRTH;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_11100_F3_000_R3_00110 (InstWord_t inst) {
  InstWord_t field_F2 = ExtractF2Field (inst);
  switch (field_F2) {
    case 0x00 : 
    // Remaining Instruction is 2
    // mret
    // mrts
      return DecodeInst_LD_11_OP_11100_F3_000_R3_00110_F2_00 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_11100_F3_000_R3_00110_F2_00 (InstWord_t inst) {
  InstWord_t field_R2 = ExtractR2Field (inst);
  switch (field_R2) {
    case 0x02 : 
      return InstId_t::INST_ID_MRET;
    case 0x05 : 
      return InstId_t::INST_ID_MRTS;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_00110 (InstWord_t inst) {
  InstWord_t field_F3 = ExtractF3Field (inst);
  switch (field_F3) {
    case 0x00 : 
      return InstId_t::INST_ID_ADDIW;
    case 0x01 : 
      return InstId_t::INST_ID_SLLIW;
    case 0x05 : 
    // Remaining Instruction is 2
    // srliw      r[11:7],r[19:15],r[24:20]
    // sraiw      r[11:7],r[19:15],r[24:20]
      return DecodeInst_LD_11_OP_00110_F3_101 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_00110_F3_101 (InstWord_t inst) {
  InstWord_t field_R3 = ExtractR3Field (inst);
  switch (field_R3) {
    case 0x00 : 
      return InstId_t::INST_ID_SRLIW;
    case 0x08 : 
      return InstId_t::INST_ID_SRAIW;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_01110 (InstWord_t inst) {
  InstWord_t field_R3 = ExtractR3Field (inst);
  switch (field_R3) {
    case 0x00 : 
    // Remaining Instruction is 8
    // addw       r[11:7],r[19:15],r[24:20]
    // sllw       r[11:7],r[19:15],r[24:20]
    // srlw       r[11:7],r[19:15],r[24:20]
    // mulw       r[11:7],r[19:15],r[24:20]
    // divw       r[11:7],r[19:15],r[24:20]
    // divuw      r[11:7],r[19:15],r[24:20]
    // remw       r[11:7],r[19:15],r[24:20]
    // remuw      r[11:7],r[19:15],r[24:20]
      return DecodeInst_LD_11_OP_01110_R3_00000 (inst); break;
    case 0x08 : 
    // Remaining Instruction is 2
    // subw       r[11:7],r[19:15],r[24:20]
    // sraw       r[11:7],r[19:15],r[24:20]
      return DecodeInst_LD_11_OP_01110_R3_01000 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_01110_R3_00000 (InstWord_t inst) {
  InstWord_t field_F2 = ExtractF2Field (inst);
  switch (field_F2) {
    case 0x00 : 
    // Remaining Instruction is 3
    // addw       r[11:7],r[19:15],r[24:20]
    // sllw       r[11:7],r[19:15],r[24:20]
    // srlw       r[11:7],r[19:15],r[24:20]
      return DecodeInst_LD_11_OP_01110_R3_00000_F2_00 (inst); break;
    case 0x01 : 
    // Remaining Instruction is 5
    // mulw       r[11:7],r[19:15],r[24:20]
    // divw       r[11:7],r[19:15],r[24:20]
    // divuw      r[11:7],r[19:15],r[24:20]
    // remw       r[11:7],r[19:15],r[24:20]
    // remuw      r[11:7],r[19:15],r[24:20]
      return DecodeInst_LD_11_OP_01110_R3_00000_F2_01 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_01110_R3_00000_F2_00 (InstWord_t inst) {
  InstWord_t field_F3 = ExtractF3Field (inst);
  switch (field_F3) {
    case 0x00 : 
      return InstId_t::INST_ID_ADDW;
    case 0x01 : 
      return InstId_t::INST_ID_SLLW;
    case 0x05 : 
      return InstId_t::INST_ID_SRLW;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_01110_R3_00000_F2_01 (InstWord_t inst) {
  InstWord_t field_F3 = ExtractF3Field (inst);
  switch (field_F3) {
    case 0x00 : 
      return InstId_t::INST_ID_MULW;
    case 0x04 : 
      return InstId_t::INST_ID_DIVW;
    case 0x05 : 
      return InstId_t::INST_ID_DIVUW;
    case 0x06 : 
      return InstId_t::INST_ID_REMW;
    case 0x07 : 
      return InstId_t::INST_ID_REMUW;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_01110_R3_01000 (InstWord_t inst) {
  InstWord_t field_F2 = ExtractF2Field (inst);
  switch (field_F2) {
    case 0x00 : 
    // Remaining Instruction is 2
    // subw       r[11:7],r[19:15],r[24:20]
    // sraw       r[11:7],r[19:15],r[24:20]
      return DecodeInst_LD_11_OP_01110_R3_01000_F2_00 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_11_OP_01110_R3_01000_F2_00 (InstWord_t inst) {
  InstWord_t field_F3 = ExtractF3Field (inst);
  switch (field_F3) {
    case 0x00 : 
      return InstId_t::INST_ID_SUBW;
    case 0x05 : 
      return InstId_t::INST_ID_SRAW;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_00 (InstWord_t inst) {
  InstWord_t field_R3 = ExtractR3Field (inst);
  switch (field_R3) {
    case 0x00 : 
    case 0x01 : 
    case 0x02 : 
    case 0x03 : 
    case 0x04 : 
    case 0x05 : 
    case 0x06 : 
    case 0x07 : 
    case 0x08 : 
    case 0x09 : 
    case 0x0a : 
    case 0x0b : 
    case 0x0c : 
    case 0x0d : 
    case 0x0e : 
    case 0x0f : 
    case 0x10 : 
    case 0x11 : 
    case 0x12 : 
    case 0x13 : 
    case 0x14 : 
    case 0x15 : 
    case 0x16 : 
    case 0x17 : 
    case 0x18 : 
    case 0x19 : 
    case 0x1a : 
    case 0x1b : 
    case 0x1c : 
    case 0x1d : 
    case 0x1e : 
    case 0x1f : 
    // Remaining Instruction is 9
    // c.addi4spn cr[4:2],u[12:5]
    // c.fld      cf[4:2],cr[9:7],u[6:5]|u[12:10]<<3
    // c.lw       cr[4:2],cr[9:7],u[5:5]|u[12:10]|u[6:6]<<2
    // c.flw      cr[4:2],cr[9:7],u[5:5]|u[12:10]|u[6:6]<<2
    // c.ld       cr[4:2],cr[9:7],u[6:5]|u[12:10]<<3
    // c.fsd      cr[4:2],cr[9:7],u[6:5]|u[12:10]<<3
    // c.sw       cr[4:2],cr[9:7],u[5:5]|u[12:10]|u[6:6]<<2
    // c.fsw      cr[4:2],cr[9:7],u[5:5]|u[12:10]|u[6:6]<<2
    // c.sd       cr[4:2],cr[9:7],u[6:5]|u[12:10]<<3
      return DecodeInst_LD_00_R3_00000 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_00_R3_00000 (InstWord_t inst) {
  InstWord_t field_F2 = ExtractF2Field (inst);
  switch (field_F2) {
    case 0x00 : 
    case 0x01 : 
    case 0x02 : 
    case 0x03 : 
    // Remaining Instruction is 9
    // c.addi4spn cr[4:2],u[12:5]
    // c.fld      cf[4:2],cr[9:7],u[6:5]|u[12:10]<<3
    // c.lw       cr[4:2],cr[9:7],u[5:5]|u[12:10]|u[6:6]<<2
    // c.flw      cr[4:2],cr[9:7],u[5:5]|u[12:10]|u[6:6]<<2
    // c.ld       cr[4:2],cr[9:7],u[6:5]|u[12:10]<<3
    // c.fsd      cr[4:2],cr[9:7],u[6:5]|u[12:10]<<3
    // c.sw       cr[4:2],cr[9:7],u[5:5]|u[12:10]|u[6:6]<<2
    // c.fsw      cr[4:2],cr[9:7],u[5:5]|u[12:10]|u[6:6]<<2
    // c.sd       cr[4:2],cr[9:7],u[6:5]|u[12:10]<<3
      return DecodeInst_LD_00_R3_00000_F2_00 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_00_R3_00000_F2_00 (InstWord_t inst) {
  InstWord_t field_R2 = ExtractR2Field (inst);
  switch (field_R2) {
    case 0x00 : 
    case 0x01 : 
    case 0x02 : 
    case 0x03 : 
    case 0x04 : 
    case 0x05 : 
    case 0x06 : 
    case 0x07 : 
    case 0x08 : 
    case 0x09 : 
    case 0x0a : 
    case 0x0b : 
    case 0x0c : 
    case 0x0d : 
    case 0x0e : 
    case 0x0f : 
    case 0x10 : 
    case 0x11 : 
    case 0x12 : 
    case 0x13 : 
    case 0x14 : 
    case 0x15 : 
    case 0x16 : 
    case 0x17 : 
    case 0x18 : 
    case 0x19 : 
    case 0x1a : 
    case 0x1b : 
    case 0x1c : 
    case 0x1d : 
    case 0x1e : 
    case 0x1f : 
    // Remaining Instruction is 9
    // c.addi4spn cr[4:2],u[12:5]
    // c.fld      cf[4:2],cr[9:7],u[6:5]|u[12:10]<<3
    // c.lw       cr[4:2],cr[9:7],u[5:5]|u[12:10]|u[6:6]<<2
    // c.flw      cr[4:2],cr[9:7],u[5:5]|u[12:10]|u[6:6]<<2
    // c.ld       cr[4:2],cr[9:7],u[6:5]|u[12:10]<<3
    // c.fsd      cr[4:2],cr[9:7],u[6:5]|u[12:10]<<3
    // c.sw       cr[4:2],cr[9:7],u[5:5]|u[12:10]|u[6:6]<<2
    // c.fsw      cr[4:2],cr[9:7],u[5:5]|u[12:10]|u[6:6]<<2
    // c.sd       cr[4:2],cr[9:7],u[6:5]|u[12:10]<<3
      return DecodeInst_LD_00_R3_00000_F2_00_R2_00000 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_00_R3_00000_F2_00_R2_00000 (InstWord_t inst) {
  InstWord_t field_R1 = ExtractR1Field (inst);
  switch (field_R1) {
    case 0x00 : 
    case 0x02 : 
    case 0x04 : 
    case 0x06 : 
    case 0x08 : 
    case 0x0a : 
    case 0x0c : 
    case 0x0e : 
    case 0x10 : 
    case 0x12 : 
    case 0x14 : 
    case 0x16 : 
    case 0x18 : 
    case 0x1a : 
    case 0x1c : 
    case 0x1e : 
    // Remaining Instruction is 5
    // c.addi4spn cr[4:2],u[12:5]
    // c.fld      cf[4:2],cr[9:7],u[6:5]|u[12:10]<<3
    // c.lw       cr[4:2],cr[9:7],u[5:5]|u[12:10]|u[6:6]<<2
    // c.flw      cr[4:2],cr[9:7],u[5:5]|u[12:10]|u[6:6]<<2
    // c.ld       cr[4:2],cr[9:7],u[6:5]|u[12:10]<<3
      return DecodeInst_LD_00_R3_00000_F2_00_R2_00000_R1_00000 (inst); break;
    case 0x01 : 
    case 0x03 : 
    case 0x05 : 
    case 0x07 : 
    case 0x09 : 
    case 0x0b : 
    case 0x0d : 
    case 0x0f : 
    case 0x11 : 
    case 0x13 : 
    case 0x15 : 
    case 0x17 : 
    case 0x19 : 
    case 0x1b : 
    case 0x1d : 
    case 0x1f : 
    // Remaining Instruction is 4
    // c.fsd      cr[4:2],cr[9:7],u[6:5]|u[12:10]<<3
    // c.sw       cr[4:2],cr[9:7],u[5:5]|u[12:10]|u[6:6]<<2
    // c.fsw      cr[4:2],cr[9:7],u[5:5]|u[12:10]|u[6:6]<<2
    // c.sd       cr[4:2],cr[9:7],u[6:5]|u[12:10]<<3
      return DecodeInst_LD_00_R3_00000_F2_00_R2_00000_R1_00001 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_00_R3_00000_F2_00_R2_00000_R1_00000 (InstWord_t inst) {
  InstWord_t field_F3 = ExtractF3Field (inst);
  switch (field_F3) {
    case 0x00 : 
    case 0x01 : 
      return InstId_t::INST_ID_C_ADDI4SPN;
    case 0x02 : 
    case 0x03 : 
      return InstId_t::INST_ID_C_FLD;
    case 0x04 : 
    case 0x05 : 
      return InstId_t::INST_ID_C_LW;
    case 0x06 : 
    case 0x07 : 
    // Remaining Instruction is 2
    // c.flw      cr[4:2],cr[9:7],u[5:5]|u[12:10]|u[6:6]<<2
    // c.ld       cr[4:2],cr[9:7],u[6:5]|u[12:10]<<3
      return DecodeInst_LD_00_R3_00000_F2_00_R2_00000_R1_00000_F3_110 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_00_R3_00000_F2_00_R2_00000_R1_00000_F3_110 (InstWord_t inst) {
  InstWord_t field_RD = ExtractRDField (inst);
  switch (field_RD) {
    case 0x00 : 
    case 0x01 : 
    case 0x02 : 
    case 0x03 : 
    case 0x04 : 
    case 0x05 : 
    case 0x06 : 
    case 0x07 : 
    case 0x08 : 
    case 0x09 : 
    case 0x0a : 
    case 0x0b : 
    case 0x0c : 
    case 0x0d : 
    case 0x0e : 
    case 0x0f : 
    case 0x10 : 
    case 0x11 : 
    case 0x12 : 
    case 0x13 : 
    case 0x14 : 
    case 0x15 : 
    case 0x16 : 
    case 0x17 : 
    case 0x18 : 
    case 0x19 : 
    case 0x1a : 
    case 0x1b : 
    case 0x1c : 
    case 0x1d : 
    case 0x1e : 
    case 0x1f : 
    // Remaining Instruction is 2
    // c.flw      cr[4:2],cr[9:7],u[5:5]|u[12:10]|u[6:6]<<2
    // c.ld       cr[4:2],cr[9:7],u[6:5]|u[12:10]<<3
      return DecodeInst_LD_00_R3_00000_F2_00_R2_00000_R1_00000_F3_110_RD_00000 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_00_R3_00000_F2_00_R2_00000_R1_00000_F3_110_RD_00000 (InstWord_t inst) {
  InstWord_t field_OP = ExtractOPField (inst);
  switch (field_OP) {
    case 0x00 : 
    case 0x01 : 
    case 0x02 : 
    case 0x03 : 
    case 0x04 : 
    case 0x05 : 
    case 0x06 : 
    case 0x07 : 
    case 0x08 : 
    case 0x09 : 
    case 0x0a : 
    case 0x0b : 
    case 0x0c : 
    case 0x0d : 
    case 0x0e : 
    case 0x0f : 
    case 0x10 : 
    case 0x11 : 
    case 0x12 : 
    case 0x13 : 
    case 0x14 : 
    case 0x15 : 
    case 0x16 : 
    case 0x17 : 
    case 0x18 : 
    case 0x19 : 
    case 0x1a : 
    case 0x1b : 
    case 0x1c : 
    case 0x1d : 
    case 0x1e : 
    case 0x1f : 
    // Remaining Instruction is 2
    // c.flw      cr[4:2],cr[9:7],u[5:5]|u[12:10]|u[6:6]<<2
    // c.ld       cr[4:2],cr[9:7],u[6:5]|u[12:10]<<3
      return DecodeInst_LD_00_R3_00000_F2_00_R2_00000_R1_00000_F3_110_RD_00000_OP_00000 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_00_R3_00000_F2_00_R2_00000_R1_00001 (InstWord_t inst) {
  InstWord_t field_F3 = ExtractF3Field (inst);
  switch (field_F3) {
    case 0x02 : 
    case 0x03 : 
      return InstId_t::INST_ID_C_FSD;
    case 0x04 : 
    case 0x05 : 
      return InstId_t::INST_ID_C_SW;
    case 0x06 : 
    case 0x07 : 
    // Remaining Instruction is 2
    // c.fsw      cr[4:2],cr[9:7],u[5:5]|u[12:10]|u[6:6]<<2
    // c.sd       cr[4:2],cr[9:7],u[6:5]|u[12:10]<<3
      return DecodeInst_LD_00_R3_00000_F2_00_R2_00000_R1_00001_F3_110 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_00_R3_00000_F2_00_R2_00000_R1_00001_F3_110 (InstWord_t inst) {
  InstWord_t field_RD = ExtractRDField (inst);
  switch (field_RD) {
    case 0x00 : 
    case 0x01 : 
    case 0x02 : 
    case 0x03 : 
    case 0x04 : 
    case 0x05 : 
    case 0x06 : 
    case 0x07 : 
    case 0x08 : 
    case 0x09 : 
    case 0x0a : 
    case 0x0b : 
    case 0x0c : 
    case 0x0d : 
    case 0x0e : 
    case 0x0f : 
    case 0x10 : 
    case 0x11 : 
    case 0x12 : 
    case 0x13 : 
    case 0x14 : 
    case 0x15 : 
    case 0x16 : 
    case 0x17 : 
    case 0x18 : 
    case 0x19 : 
    case 0x1a : 
    case 0x1b : 
    case 0x1c : 
    case 0x1d : 
    case 0x1e : 
    case 0x1f : 
    // Remaining Instruction is 2
    // c.fsw      cr[4:2],cr[9:7],u[5:5]|u[12:10]|u[6:6]<<2
    // c.sd       cr[4:2],cr[9:7],u[6:5]|u[12:10]<<3
      return DecodeInst_LD_00_R3_00000_F2_00_R2_00000_R1_00001_F3_110_RD_00000 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_00_R3_00000_F2_00_R2_00000_R1_00001_F3_110_RD_00000 (InstWord_t inst) {
  InstWord_t field_OP = ExtractOPField (inst);
  switch (field_OP) {
    case 0x00 : 
    case 0x01 : 
    case 0x02 : 
    case 0x03 : 
    case 0x04 : 
    case 0x05 : 
    case 0x06 : 
    case 0x07 : 
    case 0x08 : 
    case 0x09 : 
    case 0x0a : 
    case 0x0b : 
    case 0x0c : 
    case 0x0d : 
    case 0x0e : 
    case 0x0f : 
    case 0x10 : 
    case 0x11 : 
    case 0x12 : 
    case 0x13 : 
    case 0x14 : 
    case 0x15 : 
    case 0x16 : 
    case 0x17 : 
    case 0x18 : 
    case 0x19 : 
    case 0x1a : 
    case 0x1b : 
    case 0x1c : 
    case 0x1d : 
    case 0x1e : 
    case 0x1f : 
    // Remaining Instruction is 2
    // c.fsw      cr[4:2],cr[9:7],u[5:5]|u[12:10]|u[6:6]<<2
    // c.sd       cr[4:2],cr[9:7],u[6:5]|u[12:10]<<3
      return DecodeInst_LD_00_R3_00000_F2_00_R2_00000_R1_00001_F3_110_RD_00000_OP_00000 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_01 (InstWord_t inst) {
  InstWord_t field_F3 = ExtractF3Field (inst);
  switch (field_F3) {
    case 0x00 : 
    // Remaining Instruction is 9
    // c.nop     
    // c.addi     r[11:7],u[12:12]|u[6:2]
    // c.srli     cr[9:7],u[12:12]|h[6:2]
    // c.srai     cr[9:7],u[12:12]|h[6:2]
    // c.andi     cr[9:7],u[12:12]|h[6:2]
    // c.sub      cr[9:7],cr[4:2]
    // c.xor      cr[9:7],cr[4:2]
    // c.or       cr[9:7],cr[4:2]
    // c.and      cr[9:7],cr[4:2]
      return DecodeInst_LD_01_F3_000 (inst); break;
    case 0x01 : 
    // Remaining Instruction is 6
    // c.addi     r[11:7],u[12:12]|u[6:2]
    // c.srli64   cr[9:7],u[12:12]|h[6:2]
    // c.srai64   cr[9:7],u[12:12]|h[6:2]
    // c.andi     cr[9:7],u[12:12]|h[6:2]
    // c.subw     cr[9:7],r[6:2]
    // c.addw     cr[9:7],r[6:2]
      return DecodeInst_LD_01_F3_001 (inst); break;
    case 0x02 : 
    case 0x03 : 
    // Remaining Instruction is 3
    // c.jal      u[12:12]|u[7:7]|u[10:9]|u[6:6]|u[7:7]|u[2:2]|u[11:11]|u[5:3]<<1
    // c.addiw    r[11:7],h[12:12]|h[6:2]
    // c.j        u[12:12]|u[8:8]|u[10:9]|u[6:6]|u[7:7]|u[2:2]|u[11:11]|u[5:3]<<1
      return DecodeInst_LD_01_F3_010 (inst); break;
    case 0x04 : 
    case 0x05 : 
    // Remaining Instruction is 2
    // c.li       r[11:7],u[12:12]|h[6:2]
    // c.beqz     cr[9:7],u[12:12]|u[6:5]|u[2:2]|u[11:10]|u[4:3]<<1
      return DecodeInst_LD_01_F3_100 (inst); break;
    case 0x06 : 
    case 0x07 : 
    // Remaining Instruction is 3
    // c.addi16sp cr[4:2],u[12:5]
    // c.lui      r[11:7],u[12:12]|h[6:2]
    // c.bnez     cr[9:7],u[12:12]|u[6:5]|u[2:2]|u[11:10]|u[4:3]<<1
      return DecodeInst_LD_01_F3_110 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_01_F3_000 (InstWord_t inst) {
  InstWord_t field_RD = ExtractRDField (inst);
  switch (field_RD) {
    case 0x00 : 
    // Remaining Instruction is 2
    // c.nop     
    // c.srli     cr[9:7],u[12:12]|h[6:2]
      return DecodeInst_LD_01_F3_000_RD_00000 (inst); break;
    case 0x01 : 
    case 0x02 : 
    case 0x03 : 
    case 0x04 : 
    case 0x05 : 
    case 0x06 : 
    case 0x07 : 
    // Remaining Instruction is 2
    // c.addi     r[11:7],u[12:12]|u[6:2]
    // c.srli     cr[9:7],u[12:12]|h[6:2]
      return DecodeInst_LD_01_F3_000_RD_00001 (inst); break;
    case 0x08 : 
    case 0x09 : 
    case 0x0a : 
    case 0x0b : 
    case 0x0c : 
    case 0x0d : 
    case 0x0e : 
    case 0x0f : 
    // Remaining Instruction is 2
    // c.addi     r[11:7],u[12:12]|u[6:2]
    // c.srai     cr[9:7],u[12:12]|h[6:2]
      return DecodeInst_LD_01_F3_000_RD_01000 (inst); break;
    case 0x10 : 
    case 0x11 : 
    case 0x12 : 
    case 0x13 : 
    case 0x14 : 
    case 0x15 : 
    case 0x16 : 
    case 0x17 : 
    // Remaining Instruction is 2
    // c.addi     r[11:7],u[12:12]|u[6:2]
    // c.andi     cr[9:7],u[12:12]|h[6:2]
      return DecodeInst_LD_01_F3_000_RD_10000 (inst); break;
    case 0x18 : 
    case 0x19 : 
    case 0x1a : 
    case 0x1b : 
    case 0x1c : 
    case 0x1d : 
    case 0x1e : 
    case 0x1f : 
    // Remaining Instruction is 5
    // c.addi     r[11:7],u[12:12]|u[6:2]
    // c.sub      cr[9:7],cr[4:2]
    // c.xor      cr[9:7],cr[4:2]
    // c.or       cr[9:7],cr[4:2]
    // c.and      cr[9:7],cr[4:2]
      return DecodeInst_LD_01_F3_000_RD_11000 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_01_F3_000_RD_00000 (InstWord_t inst) {
  InstWord_t field_OP = ExtractOPField (inst);
  switch (field_OP) {
    case 0x00 : 
    // Remaining Instruction is 2
    // c.nop     
    // c.srli     cr[9:7],u[12:12]|h[6:2]
      return DecodeInst_LD_01_F3_000_RD_00000_OP_00000 (inst); break;
    case 0x01 : 
    case 0x02 : 
    case 0x03 : 
    case 0x04 : 
    case 0x05 : 
    case 0x06 : 
    case 0x07 : 
    case 0x08 : 
    case 0x09 : 
    case 0x0a : 
    case 0x0b : 
    case 0x0c : 
    case 0x0d : 
    case 0x0e : 
    case 0x0f : 
    case 0x10 : 
    case 0x11 : 
    case 0x12 : 
    case 0x13 : 
    case 0x14 : 
    case 0x15 : 
    case 0x16 : 
    case 0x17 : 
    case 0x18 : 
    case 0x19 : 
    case 0x1a : 
    case 0x1b : 
    case 0x1c : 
    case 0x1d : 
    case 0x1e : 
    case 0x1f : 
      return InstId_t::INST_ID_C_SRLI;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_01_F3_000_RD_00000_OP_00000 (InstWord_t inst) {
  InstWord_t field_R3 = ExtractR3Field (inst);
  switch (field_R3) {
    case 0x00 : 
    case 0x01 : 
    case 0x02 : 
    case 0x03 : 
    case 0x04 : 
    case 0x05 : 
    case 0x06 : 
    case 0x07 : 
    case 0x08 : 
    case 0x09 : 
    case 0x0a : 
    case 0x0b : 
    case 0x0c : 
    case 0x0d : 
    case 0x0e : 
    case 0x0f : 
    case 0x10 : 
    case 0x11 : 
    case 0x12 : 
    case 0x13 : 
    case 0x14 : 
    case 0x15 : 
    case 0x16 : 
    case 0x17 : 
    case 0x18 : 
    case 0x19 : 
    case 0x1a : 
    case 0x1b : 
    case 0x1c : 
    case 0x1d : 
    case 0x1e : 
    case 0x1f : 
    // Remaining Instruction is 2
    // c.nop     
    // c.srli     cr[9:7],u[12:12]|h[6:2]
      return DecodeInst_LD_01_F3_000_RD_00000_OP_00000_R3_00000 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_01_F3_000_RD_00000_OP_00000_R3_00000 (InstWord_t inst) {
  InstWord_t field_F2 = ExtractF2Field (inst);
  switch (field_F2) {
    case 0x00 : 
    case 0x01 : 
    case 0x02 : 
    case 0x03 : 
    // Remaining Instruction is 2
    // c.nop     
    // c.srli     cr[9:7],u[12:12]|h[6:2]
      return DecodeInst_LD_01_F3_000_RD_00000_OP_00000_R3_00000_F2_00 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_01_F3_000_RD_00000_OP_00000_R3_00000_F2_00 (InstWord_t inst) {
  InstWord_t field_R2 = ExtractR2Field (inst);
  switch (field_R2) {
    case 0x00 : 
    case 0x01 : 
    case 0x02 : 
    case 0x03 : 
    case 0x04 : 
    case 0x05 : 
    case 0x06 : 
    case 0x07 : 
    case 0x08 : 
    case 0x09 : 
    case 0x0a : 
    case 0x0b : 
    case 0x0c : 
    case 0x0d : 
    case 0x0e : 
    case 0x0f : 
    case 0x10 : 
    case 0x11 : 
    case 0x12 : 
    case 0x13 : 
    case 0x14 : 
    case 0x15 : 
    case 0x16 : 
    case 0x17 : 
    case 0x18 : 
    case 0x19 : 
    case 0x1a : 
    case 0x1b : 
    case 0x1c : 
    case 0x1d : 
    case 0x1e : 
    case 0x1f : 
    // Remaining Instruction is 2
    // c.nop     
    // c.srli     cr[9:7],u[12:12]|h[6:2]
      return DecodeInst_LD_01_F3_000_RD_00000_OP_00000_R3_00000_F2_00_R2_00000 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_01_F3_000_RD_00000_OP_00000_R3_00000_F2_00_R2_00000 (InstWord_t inst) {
  InstWord_t field_R1 = ExtractR1Field (inst);
  switch (field_R1) {
    case 0x00 : 
    case 0x02 : 
    case 0x04 : 
    case 0x06 : 
    case 0x08 : 
    case 0x0a : 
    case 0x0c : 
    case 0x0e : 
    case 0x10 : 
    case 0x12 : 
    case 0x14 : 
    case 0x16 : 
    case 0x18 : 
    case 0x1a : 
    case 0x1c : 
    case 0x1e : 
      return InstId_t::INST_ID_C_NOP;
    case 0x01 : 
    case 0x03 : 
    case 0x05 : 
    case 0x07 : 
    case 0x09 : 
    case 0x0b : 
    case 0x0d : 
    case 0x0f : 
    case 0x11 : 
    case 0x13 : 
    case 0x15 : 
    case 0x17 : 
    case 0x19 : 
    case 0x1b : 
    case 0x1d : 
    case 0x1f : 
      return InstId_t::INST_ID_C_SRLI;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_01_F3_000_RD_00001 (InstWord_t inst) {
  InstWord_t field_R3 = ExtractR3Field (inst);
  switch (field_R3) {
    case 0x00 : 
    case 0x01 : 
    case 0x02 : 
    case 0x03 : 
    case 0x04 : 
    case 0x05 : 
    case 0x06 : 
    case 0x07 : 
    case 0x08 : 
    case 0x09 : 
    case 0x0a : 
    case 0x0b : 
    case 0x0c : 
    case 0x0d : 
    case 0x0e : 
    case 0x0f : 
    case 0x10 : 
    case 0x11 : 
    case 0x12 : 
    case 0x13 : 
    case 0x14 : 
    case 0x15 : 
    case 0x16 : 
    case 0x17 : 
    case 0x18 : 
    case 0x19 : 
    case 0x1a : 
    case 0x1b : 
    case 0x1c : 
    case 0x1d : 
    case 0x1e : 
    case 0x1f : 
    // Remaining Instruction is 2
    // c.addi     r[11:7],u[12:12]|u[6:2]
    // c.srli     cr[9:7],u[12:12]|h[6:2]
      return DecodeInst_LD_01_F3_000_RD_00001_R3_00000 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_01_F3_000_RD_00001_R3_00000 (InstWord_t inst) {
  InstWord_t field_F2 = ExtractF2Field (inst);
  switch (field_F2) {
    case 0x00 : 
    case 0x01 : 
    case 0x02 : 
    case 0x03 : 
    // Remaining Instruction is 2
    // c.addi     r[11:7],u[12:12]|u[6:2]
    // c.srli     cr[9:7],u[12:12]|h[6:2]
      return DecodeInst_LD_01_F3_000_RD_00001_R3_00000_F2_00 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_01_F3_000_RD_00001_R3_00000_F2_00 (InstWord_t inst) {
  InstWord_t field_R2 = ExtractR2Field (inst);
  switch (field_R2) {
    case 0x00 : 
    case 0x01 : 
    case 0x02 : 
    case 0x03 : 
    case 0x04 : 
    case 0x05 : 
    case 0x06 : 
    case 0x07 : 
    case 0x08 : 
    case 0x09 : 
    case 0x0a : 
    case 0x0b : 
    case 0x0c : 
    case 0x0d : 
    case 0x0e : 
    case 0x0f : 
    case 0x10 : 
    case 0x11 : 
    case 0x12 : 
    case 0x13 : 
    case 0x14 : 
    case 0x15 : 
    case 0x16 : 
    case 0x17 : 
    case 0x18 : 
    case 0x19 : 
    case 0x1a : 
    case 0x1b : 
    case 0x1c : 
    case 0x1d : 
    case 0x1e : 
    case 0x1f : 
    // Remaining Instruction is 2
    // c.addi     r[11:7],u[12:12]|u[6:2]
    // c.srli     cr[9:7],u[12:12]|h[6:2]
      return DecodeInst_LD_01_F3_000_RD_00001_R3_00000_F2_00_R2_00000 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_01_F3_000_RD_00001_R3_00000_F2_00_R2_00000 (InstWord_t inst) {
  InstWord_t field_R1 = ExtractR1Field (inst);
  switch (field_R1) {
    case 0x00 : 
    case 0x02 : 
    case 0x04 : 
    case 0x06 : 
    case 0x08 : 
    case 0x0a : 
    case 0x0c : 
    case 0x0e : 
    case 0x10 : 
    case 0x12 : 
    case 0x14 : 
    case 0x16 : 
    case 0x18 : 
    case 0x1a : 
    case 0x1c : 
    case 0x1e : 
      return InstId_t::INST_ID_C_ADDI;
    case 0x01 : 
    case 0x03 : 
    case 0x05 : 
    case 0x07 : 
    case 0x09 : 
    case 0x0b : 
    case 0x0d : 
    case 0x0f : 
    case 0x11 : 
    case 0x13 : 
    case 0x15 : 
    case 0x17 : 
    case 0x19 : 
    case 0x1b : 
    case 0x1d : 
    case 0x1f : 
      return InstId_t::INST_ID_C_SRLI;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_01_F3_000_RD_01000 (InstWord_t inst) {
  InstWord_t field_R3 = ExtractR3Field (inst);
  switch (field_R3) {
    case 0x00 : 
    case 0x01 : 
    case 0x02 : 
    case 0x03 : 
    case 0x04 : 
    case 0x05 : 
    case 0x06 : 
    case 0x07 : 
    case 0x08 : 
    case 0x09 : 
    case 0x0a : 
    case 0x0b : 
    case 0x0c : 
    case 0x0d : 
    case 0x0e : 
    case 0x0f : 
    case 0x10 : 
    case 0x11 : 
    case 0x12 : 
    case 0x13 : 
    case 0x14 : 
    case 0x15 : 
    case 0x16 : 
    case 0x17 : 
    case 0x18 : 
    case 0x19 : 
    case 0x1a : 
    case 0x1b : 
    case 0x1c : 
    case 0x1d : 
    case 0x1e : 
    case 0x1f : 
    // Remaining Instruction is 2
    // c.addi     r[11:7],u[12:12]|u[6:2]
    // c.srai     cr[9:7],u[12:12]|h[6:2]
      return DecodeInst_LD_01_F3_000_RD_01000_R3_00000 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_01_F3_000_RD_01000_R3_00000 (InstWord_t inst) {
  InstWord_t field_F2 = ExtractF2Field (inst);
  switch (field_F2) {
    case 0x00 : 
    case 0x01 : 
    case 0x02 : 
    case 0x03 : 
    // Remaining Instruction is 2
    // c.addi     r[11:7],u[12:12]|u[6:2]
    // c.srai     cr[9:7],u[12:12]|h[6:2]
      return DecodeInst_LD_01_F3_000_RD_01000_R3_00000_F2_00 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_01_F3_000_RD_01000_R3_00000_F2_00 (InstWord_t inst) {
  InstWord_t field_R2 = ExtractR2Field (inst);
  switch (field_R2) {
    case 0x00 : 
    case 0x01 : 
    case 0x02 : 
    case 0x03 : 
    case 0x04 : 
    case 0x05 : 
    case 0x06 : 
    case 0x07 : 
    case 0x08 : 
    case 0x09 : 
    case 0x0a : 
    case 0x0b : 
    case 0x0c : 
    case 0x0d : 
    case 0x0e : 
    case 0x0f : 
    case 0x10 : 
    case 0x11 : 
    case 0x12 : 
    case 0x13 : 
    case 0x14 : 
    case 0x15 : 
    case 0x16 : 
    case 0x17 : 
    case 0x18 : 
    case 0x19 : 
    case 0x1a : 
    case 0x1b : 
    case 0x1c : 
    case 0x1d : 
    case 0x1e : 
    case 0x1f : 
    // Remaining Instruction is 2
    // c.addi     r[11:7],u[12:12]|u[6:2]
    // c.srai     cr[9:7],u[12:12]|h[6:2]
      return DecodeInst_LD_01_F3_000_RD_01000_R3_00000_F2_00_R2_00000 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_01_F3_000_RD_01000_R3_00000_F2_00_R2_00000 (InstWord_t inst) {
  InstWord_t field_R1 = ExtractR1Field (inst);
  switch (field_R1) {
    case 0x00 : 
    case 0x02 : 
    case 0x04 : 
    case 0x06 : 
    case 0x08 : 
    case 0x0a : 
    case 0x0c : 
    case 0x0e : 
    case 0x10 : 
    case 0x12 : 
    case 0x14 : 
    case 0x16 : 
    case 0x18 : 
    case 0x1a : 
    case 0x1c : 
    case 0x1e : 
      return InstId_t::INST_ID_C_ADDI;
    case 0x01 : 
    case 0x03 : 
    case 0x05 : 
    case 0x07 : 
    case 0x09 : 
    case 0x0b : 
    case 0x0d : 
    case 0x0f : 
    case 0x11 : 
    case 0x13 : 
    case 0x15 : 
    case 0x17 : 
    case 0x19 : 
    case 0x1b : 
    case 0x1d : 
    case 0x1f : 
      return InstId_t::INST_ID_C_SRAI;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_01_F3_000_RD_10000 (InstWord_t inst) {
  InstWord_t field_R3 = ExtractR3Field (inst);
  switch (field_R3) {
    case 0x00 : 
    case 0x01 : 
    case 0x02 : 
    case 0x03 : 
    case 0x04 : 
    case 0x05 : 
    case 0x06 : 
    case 0x07 : 
    case 0x08 : 
    case 0x09 : 
    case 0x0a : 
    case 0x0b : 
    case 0x0c : 
    case 0x0d : 
    case 0x0e : 
    case 0x0f : 
    case 0x10 : 
    case 0x11 : 
    case 0x12 : 
    case 0x13 : 
    case 0x14 : 
    case 0x15 : 
    case 0x16 : 
    case 0x17 : 
    case 0x18 : 
    case 0x19 : 
    case 0x1a : 
    case 0x1b : 
    case 0x1c : 
    case 0x1d : 
    case 0x1e : 
    case 0x1f : 
    // Remaining Instruction is 2
    // c.addi     r[11:7],u[12:12]|u[6:2]
    // c.andi     cr[9:7],u[12:12]|h[6:2]
      return DecodeInst_LD_01_F3_000_RD_10000_R3_00000 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_01_F3_000_RD_10000_R3_00000 (InstWord_t inst) {
  InstWord_t field_F2 = ExtractF2Field (inst);
  switch (field_F2) {
    case 0x00 : 
    case 0x01 : 
    case 0x02 : 
    case 0x03 : 
    // Remaining Instruction is 2
    // c.addi     r[11:7],u[12:12]|u[6:2]
    // c.andi     cr[9:7],u[12:12]|h[6:2]
      return DecodeInst_LD_01_F3_000_RD_10000_R3_00000_F2_00 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_01_F3_000_RD_10000_R3_00000_F2_00 (InstWord_t inst) {
  InstWord_t field_R2 = ExtractR2Field (inst);
  switch (field_R2) {
    case 0x00 : 
    case 0x01 : 
    case 0x02 : 
    case 0x03 : 
    case 0x04 : 
    case 0x05 : 
    case 0x06 : 
    case 0x07 : 
    case 0x08 : 
    case 0x09 : 
    case 0x0a : 
    case 0x0b : 
    case 0x0c : 
    case 0x0d : 
    case 0x0e : 
    case 0x0f : 
    case 0x10 : 
    case 0x11 : 
    case 0x12 : 
    case 0x13 : 
    case 0x14 : 
    case 0x15 : 
    case 0x16 : 
    case 0x17 : 
    case 0x18 : 
    case 0x19 : 
    case 0x1a : 
    case 0x1b : 
    case 0x1c : 
    case 0x1d : 
    case 0x1e : 
    case 0x1f : 
    // Remaining Instruction is 2
    // c.addi     r[11:7],u[12:12]|u[6:2]
    // c.andi     cr[9:7],u[12:12]|h[6:2]
      return DecodeInst_LD_01_F3_000_RD_10000_R3_00000_F2_00_R2_00000 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_01_F3_000_RD_10000_R3_00000_F2_00_R2_00000 (InstWord_t inst) {
  InstWord_t field_R1 = ExtractR1Field (inst);
  switch (field_R1) {
    case 0x00 : 
    case 0x02 : 
    case 0x04 : 
    case 0x06 : 
    case 0x08 : 
    case 0x0a : 
    case 0x0c : 
    case 0x0e : 
    case 0x10 : 
    case 0x12 : 
    case 0x14 : 
    case 0x16 : 
    case 0x18 : 
    case 0x1a : 
    case 0x1c : 
    case 0x1e : 
      return InstId_t::INST_ID_C_ADDI;
    case 0x01 : 
    case 0x03 : 
    case 0x05 : 
    case 0x07 : 
    case 0x09 : 
    case 0x0b : 
    case 0x0d : 
    case 0x0f : 
    case 0x11 : 
    case 0x13 : 
    case 0x15 : 
    case 0x17 : 
    case 0x19 : 
    case 0x1b : 
    case 0x1d : 
    case 0x1f : 
      return InstId_t::INST_ID_C_ANDI;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_01_F3_000_RD_11000 (InstWord_t inst) {
  InstWord_t field_R3 = ExtractR3Field (inst);
  switch (field_R3) {
    case 0x00 : 
    case 0x01 : 
    case 0x02 : 
    case 0x03 : 
    case 0x04 : 
    case 0x05 : 
    case 0x06 : 
    case 0x07 : 
    case 0x08 : 
    case 0x09 : 
    case 0x0a : 
    case 0x0b : 
    case 0x0c : 
    case 0x0d : 
    case 0x0e : 
    case 0x0f : 
    case 0x10 : 
    case 0x11 : 
    case 0x12 : 
    case 0x13 : 
    case 0x14 : 
    case 0x15 : 
    case 0x16 : 
    case 0x17 : 
    case 0x18 : 
    case 0x19 : 
    case 0x1a : 
    case 0x1b : 
    case 0x1c : 
    case 0x1d : 
    case 0x1e : 
    case 0x1f : 
    // Remaining Instruction is 5
    // c.addi     r[11:7],u[12:12]|u[6:2]
    // c.sub      cr[9:7],cr[4:2]
    // c.xor      cr[9:7],cr[4:2]
    // c.or       cr[9:7],cr[4:2]
    // c.and      cr[9:7],cr[4:2]
      return DecodeInst_LD_01_F3_000_RD_11000_R3_00000 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_01_F3_000_RD_11000_R3_00000 (InstWord_t inst) {
  InstWord_t field_F2 = ExtractF2Field (inst);
  switch (field_F2) {
    case 0x00 : 
    case 0x01 : 
    case 0x02 : 
    case 0x03 : 
    // Remaining Instruction is 5
    // c.addi     r[11:7],u[12:12]|u[6:2]
    // c.sub      cr[9:7],cr[4:2]
    // c.xor      cr[9:7],cr[4:2]
    // c.or       cr[9:7],cr[4:2]
    // c.and      cr[9:7],cr[4:2]
      return DecodeInst_LD_01_F3_000_RD_11000_R3_00000_F2_00 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_01_F3_000_RD_11000_R3_00000_F2_00 (InstWord_t inst) {
  InstWord_t field_R2 = ExtractR2Field (inst);
  switch (field_R2) {
    case 0x00 : 
    case 0x01 : 
    case 0x02 : 
    case 0x03 : 
    case 0x04 : 
    case 0x05 : 
    case 0x06 : 
    case 0x07 : 
    case 0x08 : 
    case 0x09 : 
    case 0x0a : 
    case 0x0b : 
    case 0x0c : 
    case 0x0d : 
    case 0x0e : 
    case 0x0f : 
    case 0x10 : 
    case 0x11 : 
    case 0x12 : 
    case 0x13 : 
    case 0x14 : 
    case 0x15 : 
    case 0x16 : 
    case 0x17 : 
    case 0x18 : 
    case 0x19 : 
    case 0x1a : 
    case 0x1b : 
    case 0x1c : 
    case 0x1d : 
    case 0x1e : 
    case 0x1f : 
    // Remaining Instruction is 5
    // c.addi     r[11:7],u[12:12]|u[6:2]
    // c.sub      cr[9:7],cr[4:2]
    // c.xor      cr[9:7],cr[4:2]
    // c.or       cr[9:7],cr[4:2]
    // c.and      cr[9:7],cr[4:2]
      return DecodeInst_LD_01_F3_000_RD_11000_R3_00000_F2_00_R2_00000 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_01_F3_000_RD_11000_R3_00000_F2_00_R2_00000 (InstWord_t inst) {
  InstWord_t field_R1 = ExtractR1Field (inst);
  switch (field_R1) {
    case 0x00 : 
    case 0x02 : 
    case 0x04 : 
    case 0x06 : 
    case 0x08 : 
    case 0x0a : 
    case 0x0c : 
    case 0x0e : 
    case 0x10 : 
    case 0x12 : 
    case 0x14 : 
    case 0x16 : 
    case 0x18 : 
    case 0x1a : 
    case 0x1c : 
    case 0x1e : 
      return InstId_t::INST_ID_C_ADDI;
    case 0x01 : 
    case 0x03 : 
    case 0x05 : 
    case 0x07 : 
    case 0x09 : 
    case 0x0b : 
    case 0x0d : 
    case 0x0f : 
    case 0x11 : 
    case 0x13 : 
    case 0x15 : 
    case 0x17 : 
    case 0x19 : 
    case 0x1b : 
    case 0x1d : 
    case 0x1f : 
    // Remaining Instruction is 4
    // c.sub      cr[9:7],cr[4:2]
    // c.xor      cr[9:7],cr[4:2]
    // c.or       cr[9:7],cr[4:2]
    // c.and      cr[9:7],cr[4:2]
      return DecodeInst_LD_01_F3_000_RD_11000_R3_00000_F2_00_R2_00000_R1_00001 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_01_F3_000_RD_11000_R3_00000_F2_00_R2_00000_R1_00001 (InstWord_t inst) {
  InstWord_t field_OP = ExtractOPField (inst);
  switch (field_OP) {
    case 0x00 : 
    case 0x01 : 
    case 0x02 : 
    case 0x03 : 
    case 0x04 : 
    case 0x05 : 
    case 0x06 : 
    case 0x07 : 
      return InstId_t::INST_ID_C_SUB;
    case 0x08 : 
    case 0x09 : 
    case 0x0a : 
    case 0x0b : 
    case 0x0c : 
    case 0x0d : 
    case 0x0e : 
    case 0x0f : 
      return InstId_t::INST_ID_C_XOR;
    case 0x10 : 
    case 0x11 : 
    case 0x12 : 
    case 0x13 : 
    case 0x14 : 
    case 0x15 : 
    case 0x16 : 
    case 0x17 : 
      return InstId_t::INST_ID_C_OR;
    case 0x18 : 
    case 0x19 : 
    case 0x1a : 
    case 0x1b : 
    case 0x1c : 
    case 0x1d : 
    case 0x1e : 
    case 0x1f : 
      return InstId_t::INST_ID_C_AND;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_01_F3_001 (InstWord_t inst) {
  InstWord_t field_R3 = ExtractR3Field (inst);
  switch (field_R3) {
    case 0x00 : 
    case 0x01 : 
    case 0x02 : 
    case 0x03 : 
    case 0x04 : 
    case 0x05 : 
    case 0x06 : 
    case 0x07 : 
    case 0x08 : 
    case 0x09 : 
    case 0x0a : 
    case 0x0b : 
    case 0x0c : 
    case 0x0d : 
    case 0x0e : 
    case 0x0f : 
    case 0x10 : 
    case 0x11 : 
    case 0x12 : 
    case 0x13 : 
    case 0x14 : 
    case 0x15 : 
    case 0x16 : 
    case 0x17 : 
    case 0x18 : 
    case 0x19 : 
    case 0x1a : 
    case 0x1b : 
    case 0x1c : 
    case 0x1d : 
    case 0x1e : 
    case 0x1f : 
    // Remaining Instruction is 6
    // c.addi     r[11:7],u[12:12]|u[6:2]
    // c.srli64   cr[9:7],u[12:12]|h[6:2]
    // c.srai64   cr[9:7],u[12:12]|h[6:2]
    // c.andi     cr[9:7],u[12:12]|h[6:2]
    // c.subw     cr[9:7],r[6:2]
    // c.addw     cr[9:7],r[6:2]
      return DecodeInst_LD_01_F3_001_R3_00000 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_01_F3_001_R3_00000 (InstWord_t inst) {
  InstWord_t field_F2 = ExtractF2Field (inst);
  switch (field_F2) {
    case 0x00 : 
    case 0x01 : 
    case 0x02 : 
    case 0x03 : 
    // Remaining Instruction is 6
    // c.addi     r[11:7],u[12:12]|u[6:2]
    // c.srli64   cr[9:7],u[12:12]|h[6:2]
    // c.srai64   cr[9:7],u[12:12]|h[6:2]
    // c.andi     cr[9:7],u[12:12]|h[6:2]
    // c.subw     cr[9:7],r[6:2]
    // c.addw     cr[9:7],r[6:2]
      return DecodeInst_LD_01_F3_001_R3_00000_F2_00 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_01_F3_001_R3_00000_F2_00 (InstWord_t inst) {
  InstWord_t field_R2 = ExtractR2Field (inst);
  switch (field_R2) {
    case 0x00 : 
    case 0x01 : 
    case 0x02 : 
    case 0x03 : 
    case 0x04 : 
    case 0x05 : 
    case 0x06 : 
    case 0x07 : 
    case 0x08 : 
    case 0x09 : 
    case 0x0a : 
    case 0x0b : 
    case 0x0c : 
    case 0x0d : 
    case 0x0e : 
    case 0x0f : 
    case 0x10 : 
    case 0x11 : 
    case 0x12 : 
    case 0x13 : 
    case 0x14 : 
    case 0x15 : 
    case 0x16 : 
    case 0x17 : 
    case 0x18 : 
    case 0x19 : 
    case 0x1a : 
    case 0x1b : 
    case 0x1c : 
    case 0x1d : 
    case 0x1e : 
    case 0x1f : 
    // Remaining Instruction is 6
    // c.addi     r[11:7],u[12:12]|u[6:2]
    // c.srli64   cr[9:7],u[12:12]|h[6:2]
    // c.srai64   cr[9:7],u[12:12]|h[6:2]
    // c.andi     cr[9:7],u[12:12]|h[6:2]
    // c.subw     cr[9:7],r[6:2]
    // c.addw     cr[9:7],r[6:2]
      return DecodeInst_LD_01_F3_001_R3_00000_F2_00_R2_00000 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_01_F3_001_R3_00000_F2_00_R2_00000 (InstWord_t inst) {
  InstWord_t field_R1 = ExtractR1Field (inst);
  switch (field_R1) {
    case 0x00 : 
    case 0x02 : 
    case 0x04 : 
    case 0x06 : 
    case 0x08 : 
    case 0x0a : 
    case 0x0c : 
    case 0x0e : 
    case 0x10 : 
    case 0x12 : 
    case 0x14 : 
    case 0x16 : 
    case 0x18 : 
    case 0x1a : 
    case 0x1c : 
    case 0x1e : 
      return InstId_t::INST_ID_C_ADDI;
    case 0x01 : 
    case 0x03 : 
    case 0x05 : 
    case 0x07 : 
    case 0x09 : 
    case 0x0b : 
    case 0x0d : 
    case 0x0f : 
    case 0x11 : 
    case 0x13 : 
    case 0x15 : 
    case 0x17 : 
    case 0x19 : 
    case 0x1b : 
    case 0x1d : 
    case 0x1f : 
    // Remaining Instruction is 5
    // c.srli64   cr[9:7],u[12:12]|h[6:2]
    // c.srai64   cr[9:7],u[12:12]|h[6:2]
    // c.andi     cr[9:7],u[12:12]|h[6:2]
    // c.subw     cr[9:7],r[6:2]
    // c.addw     cr[9:7],r[6:2]
      return DecodeInst_LD_01_F3_001_R3_00000_F2_00_R2_00000_R1_00001 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_01_F3_001_R3_00000_F2_00_R2_00000_R1_00001 (InstWord_t inst) {
  InstWord_t field_RD = ExtractRDField (inst);
  switch (field_RD) {
    case 0x00 : 
    case 0x01 : 
    case 0x02 : 
    case 0x03 : 
    case 0x04 : 
    case 0x05 : 
    case 0x06 : 
    case 0x07 : 
      return InstId_t::INST_ID_C_SRLI64;
    case 0x08 : 
    case 0x09 : 
    case 0x0a : 
    case 0x0b : 
    case 0x0c : 
    case 0x0d : 
    case 0x0e : 
    case 0x0f : 
      return InstId_t::INST_ID_C_SRAI64;
    case 0x10 : 
    case 0x11 : 
    case 0x12 : 
    case 0x13 : 
    case 0x14 : 
    case 0x15 : 
    case 0x16 : 
    case 0x17 : 
      return InstId_t::INST_ID_C_ANDI;
    case 0x18 : 
    case 0x19 : 
    case 0x1a : 
    case 0x1b : 
    case 0x1c : 
    case 0x1d : 
    case 0x1e : 
    case 0x1f : 
    // Remaining Instruction is 2
    // c.subw     cr[9:7],r[6:2]
    // c.addw     cr[9:7],r[6:2]
      return DecodeInst_LD_01_F3_001_R3_00000_F2_00_R2_00000_R1_00001_RD_11000 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_01_F3_001_R3_00000_F2_00_R2_00000_R1_00001_RD_11000 (InstWord_t inst) {
  InstWord_t field_OP = ExtractOPField (inst);
  switch (field_OP) {
    case 0x00 : 
    case 0x01 : 
    case 0x02 : 
    case 0x03 : 
    case 0x04 : 
    case 0x05 : 
    case 0x06 : 
    case 0x07 : 
      return InstId_t::INST_ID_C_SUBW;
    case 0x08 : 
    case 0x09 : 
    case 0x0a : 
    case 0x0b : 
    case 0x0c : 
    case 0x0d : 
    case 0x0e : 
    case 0x0f : 
      return InstId_t::INST_ID_C_ADDW;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_01_F3_010 (InstWord_t inst) {
  InstWord_t field_R3 = ExtractR3Field (inst);
  switch (field_R3) {
    case 0x00 : 
    case 0x01 : 
    case 0x02 : 
    case 0x03 : 
    case 0x04 : 
    case 0x05 : 
    case 0x06 : 
    case 0x07 : 
    case 0x08 : 
    case 0x09 : 
    case 0x0a : 
    case 0x0b : 
    case 0x0c : 
    case 0x0d : 
    case 0x0e : 
    case 0x0f : 
    case 0x10 : 
    case 0x11 : 
    case 0x12 : 
    case 0x13 : 
    case 0x14 : 
    case 0x15 : 
    case 0x16 : 
    case 0x17 : 
    case 0x18 : 
    case 0x19 : 
    case 0x1a : 
    case 0x1b : 
    case 0x1c : 
    case 0x1d : 
    case 0x1e : 
    case 0x1f : 
    // Remaining Instruction is 3
    // c.jal      u[12:12]|u[7:7]|u[10:9]|u[6:6]|u[7:7]|u[2:2]|u[11:11]|u[5:3]<<1
    // c.addiw    r[11:7],h[12:12]|h[6:2]
    // c.j        u[12:12]|u[8:8]|u[10:9]|u[6:6]|u[7:7]|u[2:2]|u[11:11]|u[5:3]<<1
      return DecodeInst_LD_01_F3_010_R3_00000 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_01_F3_010_R3_00000 (InstWord_t inst) {
  InstWord_t field_F2 = ExtractF2Field (inst);
  switch (field_F2) {
    case 0x00 : 
    case 0x01 : 
    case 0x02 : 
    case 0x03 : 
    // Remaining Instruction is 3
    // c.jal      u[12:12]|u[7:7]|u[10:9]|u[6:6]|u[7:7]|u[2:2]|u[11:11]|u[5:3]<<1
    // c.addiw    r[11:7],h[12:12]|h[6:2]
    // c.j        u[12:12]|u[8:8]|u[10:9]|u[6:6]|u[7:7]|u[2:2]|u[11:11]|u[5:3]<<1
      return DecodeInst_LD_01_F3_010_R3_00000_F2_00 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_01_F3_010_R3_00000_F2_00 (InstWord_t inst) {
  InstWord_t field_R2 = ExtractR2Field (inst);
  switch (field_R2) {
    case 0x00 : 
    case 0x01 : 
    case 0x02 : 
    case 0x03 : 
    case 0x04 : 
    case 0x05 : 
    case 0x06 : 
    case 0x07 : 
    case 0x08 : 
    case 0x09 : 
    case 0x0a : 
    case 0x0b : 
    case 0x0c : 
    case 0x0d : 
    case 0x0e : 
    case 0x0f : 
    case 0x10 : 
    case 0x11 : 
    case 0x12 : 
    case 0x13 : 
    case 0x14 : 
    case 0x15 : 
    case 0x16 : 
    case 0x17 : 
    case 0x18 : 
    case 0x19 : 
    case 0x1a : 
    case 0x1b : 
    case 0x1c : 
    case 0x1d : 
    case 0x1e : 
    case 0x1f : 
    // Remaining Instruction is 3
    // c.jal      u[12:12]|u[7:7]|u[10:9]|u[6:6]|u[7:7]|u[2:2]|u[11:11]|u[5:3]<<1
    // c.addiw    r[11:7],h[12:12]|h[6:2]
    // c.j        u[12:12]|u[8:8]|u[10:9]|u[6:6]|u[7:7]|u[2:2]|u[11:11]|u[5:3]<<1
      return DecodeInst_LD_01_F3_010_R3_00000_F2_00_R2_00000 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_01_F3_010_R3_00000_F2_00_R2_00000 (InstWord_t inst) {
  InstWord_t field_R1 = ExtractR1Field (inst);
  switch (field_R1) {
    case 0x00 : 
    case 0x02 : 
    case 0x04 : 
    case 0x06 : 
    case 0x08 : 
    case 0x0a : 
    case 0x0c : 
    case 0x0e : 
    case 0x10 : 
    case 0x12 : 
    case 0x14 : 
    case 0x16 : 
    case 0x18 : 
    case 0x1a : 
    case 0x1c : 
    case 0x1e : 
    // Remaining Instruction is 2
    // c.jal      u[12:12]|u[7:7]|u[10:9]|u[6:6]|u[7:7]|u[2:2]|u[11:11]|u[5:3]<<1
    // c.addiw    r[11:7],h[12:12]|h[6:2]
      return DecodeInst_LD_01_F3_010_R3_00000_F2_00_R2_00000_R1_00000 (inst); break;
    case 0x01 : 
    case 0x03 : 
    case 0x05 : 
    case 0x07 : 
    case 0x09 : 
    case 0x0b : 
    case 0x0d : 
    case 0x0f : 
    case 0x11 : 
    case 0x13 : 
    case 0x15 : 
    case 0x17 : 
    case 0x19 : 
    case 0x1b : 
    case 0x1d : 
    case 0x1f : 
      return InstId_t::INST_ID_C_J;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_01_F3_010_R3_00000_F2_00_R2_00000_R1_00000 (InstWord_t inst) {
  InstWord_t field_RD = ExtractRDField (inst);
  switch (field_RD) {
    case 0x00 : 
    case 0x01 : 
    case 0x02 : 
    case 0x03 : 
    case 0x04 : 
    case 0x05 : 
    case 0x06 : 
    case 0x07 : 
    case 0x08 : 
    case 0x09 : 
    case 0x0a : 
    case 0x0b : 
    case 0x0c : 
    case 0x0d : 
    case 0x0e : 
    case 0x0f : 
    case 0x10 : 
    case 0x11 : 
    case 0x12 : 
    case 0x13 : 
    case 0x14 : 
    case 0x15 : 
    case 0x16 : 
    case 0x17 : 
    case 0x18 : 
    case 0x19 : 
    case 0x1a : 
    case 0x1b : 
    case 0x1c : 
    case 0x1d : 
    case 0x1e : 
    case 0x1f : 
    // Remaining Instruction is 2
    // c.jal      u[12:12]|u[7:7]|u[10:9]|u[6:6]|u[7:7]|u[2:2]|u[11:11]|u[5:3]<<1
    // c.addiw    r[11:7],h[12:12]|h[6:2]
      return DecodeInst_LD_01_F3_010_R3_00000_F2_00_R2_00000_R1_00000_RD_00000 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_01_F3_010_R3_00000_F2_00_R2_00000_R1_00000_RD_00000 (InstWord_t inst) {
  InstWord_t field_OP = ExtractOPField (inst);
  switch (field_OP) {
    case 0x00 : 
    case 0x01 : 
    case 0x02 : 
    case 0x03 : 
    case 0x04 : 
    case 0x05 : 
    case 0x06 : 
    case 0x07 : 
    case 0x08 : 
    case 0x09 : 
    case 0x0a : 
    case 0x0b : 
    case 0x0c : 
    case 0x0d : 
    case 0x0e : 
    case 0x0f : 
    case 0x10 : 
    case 0x11 : 
    case 0x12 : 
    case 0x13 : 
    case 0x14 : 
    case 0x15 : 
    case 0x16 : 
    case 0x17 : 
    case 0x18 : 
    case 0x19 : 
    case 0x1a : 
    case 0x1b : 
    case 0x1c : 
    case 0x1d : 
    case 0x1e : 
    case 0x1f : 
    // Remaining Instruction is 2
    // c.jal      u[12:12]|u[7:7]|u[10:9]|u[6:6]|u[7:7]|u[2:2]|u[11:11]|u[5:3]<<1
    // c.addiw    r[11:7],h[12:12]|h[6:2]
      return DecodeInst_LD_01_F3_010_R3_00000_F2_00_R2_00000_R1_00000_RD_00000_OP_00000 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_01_F3_100 (InstWord_t inst) {
  InstWord_t field_R3 = ExtractR3Field (inst);
  switch (field_R3) {
    case 0x00 : 
    case 0x01 : 
    case 0x02 : 
    case 0x03 : 
    case 0x04 : 
    case 0x05 : 
    case 0x06 : 
    case 0x07 : 
    case 0x08 : 
    case 0x09 : 
    case 0x0a : 
    case 0x0b : 
    case 0x0c : 
    case 0x0d : 
    case 0x0e : 
    case 0x0f : 
    case 0x10 : 
    case 0x11 : 
    case 0x12 : 
    case 0x13 : 
    case 0x14 : 
    case 0x15 : 
    case 0x16 : 
    case 0x17 : 
    case 0x18 : 
    case 0x19 : 
    case 0x1a : 
    case 0x1b : 
    case 0x1c : 
    case 0x1d : 
    case 0x1e : 
    case 0x1f : 
    // Remaining Instruction is 2
    // c.li       r[11:7],u[12:12]|h[6:2]
    // c.beqz     cr[9:7],u[12:12]|u[6:5]|u[2:2]|u[11:10]|u[4:3]<<1
      return DecodeInst_LD_01_F3_100_R3_00000 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_01_F3_100_R3_00000 (InstWord_t inst) {
  InstWord_t field_F2 = ExtractF2Field (inst);
  switch (field_F2) {
    case 0x00 : 
    case 0x01 : 
    case 0x02 : 
    case 0x03 : 
    // Remaining Instruction is 2
    // c.li       r[11:7],u[12:12]|h[6:2]
    // c.beqz     cr[9:7],u[12:12]|u[6:5]|u[2:2]|u[11:10]|u[4:3]<<1
      return DecodeInst_LD_01_F3_100_R3_00000_F2_00 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_01_F3_100_R3_00000_F2_00 (InstWord_t inst) {
  InstWord_t field_R2 = ExtractR2Field (inst);
  switch (field_R2) {
    case 0x00 : 
    case 0x01 : 
    case 0x02 : 
    case 0x03 : 
    case 0x04 : 
    case 0x05 : 
    case 0x06 : 
    case 0x07 : 
    case 0x08 : 
    case 0x09 : 
    case 0x0a : 
    case 0x0b : 
    case 0x0c : 
    case 0x0d : 
    case 0x0e : 
    case 0x0f : 
    case 0x10 : 
    case 0x11 : 
    case 0x12 : 
    case 0x13 : 
    case 0x14 : 
    case 0x15 : 
    case 0x16 : 
    case 0x17 : 
    case 0x18 : 
    case 0x19 : 
    case 0x1a : 
    case 0x1b : 
    case 0x1c : 
    case 0x1d : 
    case 0x1e : 
    case 0x1f : 
    // Remaining Instruction is 2
    // c.li       r[11:7],u[12:12]|h[6:2]
    // c.beqz     cr[9:7],u[12:12]|u[6:5]|u[2:2]|u[11:10]|u[4:3]<<1
      return DecodeInst_LD_01_F3_100_R3_00000_F2_00_R2_00000 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_01_F3_100_R3_00000_F2_00_R2_00000 (InstWord_t inst) {
  InstWord_t field_R1 = ExtractR1Field (inst);
  switch (field_R1) {
    case 0x00 : 
    case 0x02 : 
    case 0x04 : 
    case 0x06 : 
    case 0x08 : 
    case 0x0a : 
    case 0x0c : 
    case 0x0e : 
    case 0x10 : 
    case 0x12 : 
    case 0x14 : 
    case 0x16 : 
    case 0x18 : 
    case 0x1a : 
    case 0x1c : 
    case 0x1e : 
      return InstId_t::INST_ID_C_LI;
    case 0x01 : 
    case 0x03 : 
    case 0x05 : 
    case 0x07 : 
    case 0x09 : 
    case 0x0b : 
    case 0x0d : 
    case 0x0f : 
    case 0x11 : 
    case 0x13 : 
    case 0x15 : 
    case 0x17 : 
    case 0x19 : 
    case 0x1b : 
    case 0x1d : 
    case 0x1f : 
      return InstId_t::INST_ID_C_BEQZ;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_01_F3_110 (InstWord_t inst) {
  InstWord_t field_RD = ExtractRDField (inst);
  switch (field_RD) {
    case 0x02 : 
    // Remaining Instruction is 2
    // c.addi16sp cr[4:2],u[12:5]
    // c.bnez     cr[9:7],u[12:12]|u[6:5]|u[2:2]|u[11:10]|u[4:3]<<1
      return DecodeInst_LD_01_F3_110_RD_00010 (inst); break;
    case 0x00 : 
    case 0x01 : 
    case 0x03 : 
    case 0x04 : 
    case 0x05 : 
    case 0x06 : 
    case 0x07 : 
    case 0x08 : 
    case 0x09 : 
    case 0x0a : 
    case 0x0b : 
    case 0x0c : 
    case 0x0d : 
    case 0x0e : 
    case 0x0f : 
    case 0x10 : 
    case 0x11 : 
    case 0x12 : 
    case 0x13 : 
    case 0x14 : 
    case 0x15 : 
    case 0x16 : 
    case 0x17 : 
    case 0x18 : 
    case 0x19 : 
    case 0x1a : 
    case 0x1b : 
    case 0x1c : 
    case 0x1d : 
    case 0x1e : 
    case 0x1f : 
    // Remaining Instruction is 2
    // c.lui      r[11:7],u[12:12]|h[6:2]
    // c.bnez     cr[9:7],u[12:12]|u[6:5]|u[2:2]|u[11:10]|u[4:3]<<1
      return DecodeInst_LD_01_F3_110_RD_00000 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_01_F3_110_RD_00010 (InstWord_t inst) {
  InstWord_t field_R3 = ExtractR3Field (inst);
  switch (field_R3) {
    case 0x00 : 
    case 0x01 : 
    case 0x02 : 
    case 0x03 : 
    case 0x04 : 
    case 0x05 : 
    case 0x06 : 
    case 0x07 : 
    case 0x08 : 
    case 0x09 : 
    case 0x0a : 
    case 0x0b : 
    case 0x0c : 
    case 0x0d : 
    case 0x0e : 
    case 0x0f : 
    case 0x10 : 
    case 0x11 : 
    case 0x12 : 
    case 0x13 : 
    case 0x14 : 
    case 0x15 : 
    case 0x16 : 
    case 0x17 : 
    case 0x18 : 
    case 0x19 : 
    case 0x1a : 
    case 0x1b : 
    case 0x1c : 
    case 0x1d : 
    case 0x1e : 
    case 0x1f : 
    // Remaining Instruction is 2
    // c.addi16sp cr[4:2],u[12:5]
    // c.bnez     cr[9:7],u[12:12]|u[6:5]|u[2:2]|u[11:10]|u[4:3]<<1
      return DecodeInst_LD_01_F3_110_RD_00010_R3_00000 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_01_F3_110_RD_00010_R3_00000 (InstWord_t inst) {
  InstWord_t field_F2 = ExtractF2Field (inst);
  switch (field_F2) {
    case 0x00 : 
    case 0x01 : 
    case 0x02 : 
    case 0x03 : 
    // Remaining Instruction is 2
    // c.addi16sp cr[4:2],u[12:5]
    // c.bnez     cr[9:7],u[12:12]|u[6:5]|u[2:2]|u[11:10]|u[4:3]<<1
      return DecodeInst_LD_01_F3_110_RD_00010_R3_00000_F2_00 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_01_F3_110_RD_00010_R3_00000_F2_00 (InstWord_t inst) {
  InstWord_t field_R2 = ExtractR2Field (inst);
  switch (field_R2) {
    case 0x00 : 
    case 0x01 : 
    case 0x02 : 
    case 0x03 : 
    case 0x04 : 
    case 0x05 : 
    case 0x06 : 
    case 0x07 : 
    case 0x08 : 
    case 0x09 : 
    case 0x0a : 
    case 0x0b : 
    case 0x0c : 
    case 0x0d : 
    case 0x0e : 
    case 0x0f : 
    case 0x10 : 
    case 0x11 : 
    case 0x12 : 
    case 0x13 : 
    case 0x14 : 
    case 0x15 : 
    case 0x16 : 
    case 0x17 : 
    case 0x18 : 
    case 0x19 : 
    case 0x1a : 
    case 0x1b : 
    case 0x1c : 
    case 0x1d : 
    case 0x1e : 
    case 0x1f : 
    // Remaining Instruction is 2
    // c.addi16sp cr[4:2],u[12:5]
    // c.bnez     cr[9:7],u[12:12]|u[6:5]|u[2:2]|u[11:10]|u[4:3]<<1
      return DecodeInst_LD_01_F3_110_RD_00010_R3_00000_F2_00_R2_00000 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_01_F3_110_RD_00010_R3_00000_F2_00_R2_00000 (InstWord_t inst) {
  InstWord_t field_R1 = ExtractR1Field (inst);
  switch (field_R1) {
    case 0x00 : 
    case 0x02 : 
    case 0x04 : 
    case 0x06 : 
    case 0x08 : 
    case 0x0a : 
    case 0x0c : 
    case 0x0e : 
    case 0x10 : 
    case 0x12 : 
    case 0x14 : 
    case 0x16 : 
    case 0x18 : 
    case 0x1a : 
    case 0x1c : 
    case 0x1e : 
      return InstId_t::INST_ID_C_ADDI16SP;
    case 0x01 : 
    case 0x03 : 
    case 0x05 : 
    case 0x07 : 
    case 0x09 : 
    case 0x0b : 
    case 0x0d : 
    case 0x0f : 
    case 0x11 : 
    case 0x13 : 
    case 0x15 : 
    case 0x17 : 
    case 0x19 : 
    case 0x1b : 
    case 0x1d : 
    case 0x1f : 
      return InstId_t::INST_ID_C_BNEZ;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_01_F3_110_RD_00000 (InstWord_t inst) {
  InstWord_t field_R3 = ExtractR3Field (inst);
  switch (field_R3) {
    case 0x00 : 
    case 0x01 : 
    case 0x02 : 
    case 0x03 : 
    case 0x04 : 
    case 0x05 : 
    case 0x06 : 
    case 0x07 : 
    case 0x08 : 
    case 0x09 : 
    case 0x0a : 
    case 0x0b : 
    case 0x0c : 
    case 0x0d : 
    case 0x0e : 
    case 0x0f : 
    case 0x10 : 
    case 0x11 : 
    case 0x12 : 
    case 0x13 : 
    case 0x14 : 
    case 0x15 : 
    case 0x16 : 
    case 0x17 : 
    case 0x18 : 
    case 0x19 : 
    case 0x1a : 
    case 0x1b : 
    case 0x1c : 
    case 0x1d : 
    case 0x1e : 
    case 0x1f : 
    // Remaining Instruction is 2
    // c.lui      r[11:7],u[12:12]|h[6:2]
    // c.bnez     cr[9:7],u[12:12]|u[6:5]|u[2:2]|u[11:10]|u[4:3]<<1
      return DecodeInst_LD_01_F3_110_RD_00000_R3_00000 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_01_F3_110_RD_00000_R3_00000 (InstWord_t inst) {
  InstWord_t field_F2 = ExtractF2Field (inst);
  switch (field_F2) {
    case 0x00 : 
    case 0x01 : 
    case 0x02 : 
    case 0x03 : 
    // Remaining Instruction is 2
    // c.lui      r[11:7],u[12:12]|h[6:2]
    // c.bnez     cr[9:7],u[12:12]|u[6:5]|u[2:2]|u[11:10]|u[4:3]<<1
      return DecodeInst_LD_01_F3_110_RD_00000_R3_00000_F2_00 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_01_F3_110_RD_00000_R3_00000_F2_00 (InstWord_t inst) {
  InstWord_t field_R2 = ExtractR2Field (inst);
  switch (field_R2) {
    case 0x00 : 
    case 0x01 : 
    case 0x02 : 
    case 0x03 : 
    case 0x04 : 
    case 0x05 : 
    case 0x06 : 
    case 0x07 : 
    case 0x08 : 
    case 0x09 : 
    case 0x0a : 
    case 0x0b : 
    case 0x0c : 
    case 0x0d : 
    case 0x0e : 
    case 0x0f : 
    case 0x10 : 
    case 0x11 : 
    case 0x12 : 
    case 0x13 : 
    case 0x14 : 
    case 0x15 : 
    case 0x16 : 
    case 0x17 : 
    case 0x18 : 
    case 0x19 : 
    case 0x1a : 
    case 0x1b : 
    case 0x1c : 
    case 0x1d : 
    case 0x1e : 
    case 0x1f : 
    // Remaining Instruction is 2
    // c.lui      r[11:7],u[12:12]|h[6:2]
    // c.bnez     cr[9:7],u[12:12]|u[6:5]|u[2:2]|u[11:10]|u[4:3]<<1
      return DecodeInst_LD_01_F3_110_RD_00000_R3_00000_F2_00_R2_00000 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_01_F3_110_RD_00000_R3_00000_F2_00_R2_00000 (InstWord_t inst) {
  InstWord_t field_R1 = ExtractR1Field (inst);
  switch (field_R1) {
    case 0x00 : 
    case 0x02 : 
    case 0x04 : 
    case 0x06 : 
    case 0x08 : 
    case 0x0a : 
    case 0x0c : 
    case 0x0e : 
    case 0x10 : 
    case 0x12 : 
    case 0x14 : 
    case 0x16 : 
    case 0x18 : 
    case 0x1a : 
    case 0x1c : 
    case 0x1e : 
      return InstId_t::INST_ID_C_LUI;
    case 0x01 : 
    case 0x03 : 
    case 0x05 : 
    case 0x07 : 
    case 0x09 : 
    case 0x0b : 
    case 0x0d : 
    case 0x0f : 
    case 0x11 : 
    case 0x13 : 
    case 0x15 : 
    case 0x17 : 
    case 0x19 : 
    case 0x1b : 
    case 0x1d : 
    case 0x1f : 
      return InstId_t::INST_ID_C_BNEZ;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_10 (InstWord_t inst) {
  InstWord_t field_F3 = ExtractF3Field (inst);
  switch (field_F3) {
    case 0x00 : 
    // Remaining Instruction is 3
    // c.slli     r[11:7],u[12:12]|u[6:2]
    // c.jr       r[11:7]
    // c.mv       r[11:7],r[6:2]
      return DecodeInst_LD_10_F3_000 (inst); break;
    case 0x01 : 
    // Remaining Instruction is 4
    // c.slli     r[11:7],u[12:12]|u[6:2]
    // c.ebreak  
    // c.jalr     r[11:7]
    // c.add      r[11:7],r[6:2]
      return DecodeInst_LD_10_F3_001 (inst); break;
    case 0x02 : 
    case 0x03 : 
    // Remaining Instruction is 2
    // c.fldsp    r[11:7],u[4:2]|u[12:12]|u[6:5]<<3 
    // c.fsdsp    f[6:2],u[9:7]|u[12:10]<<3
      return DecodeInst_LD_10_F3_010 (inst); break;
    case 0x04 : 
    case 0x05 : 
    // Remaining Instruction is 2
    // c.lwsp     r[11:7],u[3:2]|u[12:12]|u[6:4]<<2
    // c.swsp     r[6:2],u[8:7]|u[12:9]<<2
      return DecodeInst_LD_10_F3_100 (inst); break;
    case 0x06 : 
    case 0x07 : 
    // Remaining Instruction is 4
    // c.flwsp    f[11:7],u[3:2]|u[12:12]|u[6:4]<<2
    // c.ldsp     r[11:7],u[4:2]|u[12:12]|u[6:5]<<3
    // c.fswsp    f[6:2],u[9:7]|u[12:10]<<3
    // c.sdsp     r[6:2],u[9:7]|u[12:10]<<3
      return DecodeInst_LD_10_F3_110 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_10_F3_000 (InstWord_t inst) {
  InstWord_t field_OP = ExtractOPField (inst);
  switch (field_OP) {
    case 0x00 : 
    // Remaining Instruction is 2
    // c.slli     r[11:7],u[12:12]|u[6:2]
    // c.jr       r[11:7]
      return DecodeInst_LD_10_F3_000_OP_00000 (inst); break;
    case 0x01 : 
    case 0x02 : 
    case 0x03 : 
    case 0x04 : 
    case 0x05 : 
    case 0x06 : 
    case 0x07 : 
    case 0x08 : 
    case 0x09 : 
    case 0x0a : 
    case 0x0b : 
    case 0x0c : 
    case 0x0d : 
    case 0x0e : 
    case 0x0f : 
    case 0x10 : 
    case 0x11 : 
    case 0x12 : 
    case 0x13 : 
    case 0x14 : 
    case 0x15 : 
    case 0x16 : 
    case 0x17 : 
    case 0x18 : 
    case 0x19 : 
    case 0x1a : 
    case 0x1b : 
    case 0x1c : 
    case 0x1d : 
    case 0x1e : 
    case 0x1f : 
    // Remaining Instruction is 2
    // c.slli     r[11:7],u[12:12]|u[6:2]
    // c.mv       r[11:7],r[6:2]
      return DecodeInst_LD_10_F3_000_OP_00001 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_10_F3_000_OP_00000 (InstWord_t inst) {
  InstWord_t field_R3 = ExtractR3Field (inst);
  switch (field_R3) {
    case 0x00 : 
    case 0x01 : 
    case 0x02 : 
    case 0x03 : 
    case 0x04 : 
    case 0x05 : 
    case 0x06 : 
    case 0x07 : 
    case 0x08 : 
    case 0x09 : 
    case 0x0a : 
    case 0x0b : 
    case 0x0c : 
    case 0x0d : 
    case 0x0e : 
    case 0x0f : 
    case 0x10 : 
    case 0x11 : 
    case 0x12 : 
    case 0x13 : 
    case 0x14 : 
    case 0x15 : 
    case 0x16 : 
    case 0x17 : 
    case 0x18 : 
    case 0x19 : 
    case 0x1a : 
    case 0x1b : 
    case 0x1c : 
    case 0x1d : 
    case 0x1e : 
    case 0x1f : 
    // Remaining Instruction is 2
    // c.slli     r[11:7],u[12:12]|u[6:2]
    // c.jr       r[11:7]
      return DecodeInst_LD_10_F3_000_OP_00000_R3_00000 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_10_F3_000_OP_00000_R3_00000 (InstWord_t inst) {
  InstWord_t field_F2 = ExtractF2Field (inst);
  switch (field_F2) {
    case 0x00 : 
    case 0x01 : 
    case 0x02 : 
    case 0x03 : 
    // Remaining Instruction is 2
    // c.slli     r[11:7],u[12:12]|u[6:2]
    // c.jr       r[11:7]
      return DecodeInst_LD_10_F3_000_OP_00000_R3_00000_F2_00 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_10_F3_000_OP_00000_R3_00000_F2_00 (InstWord_t inst) {
  InstWord_t field_R2 = ExtractR2Field (inst);
  switch (field_R2) {
    case 0x00 : 
    case 0x01 : 
    case 0x02 : 
    case 0x03 : 
    case 0x04 : 
    case 0x05 : 
    case 0x06 : 
    case 0x07 : 
    case 0x08 : 
    case 0x09 : 
    case 0x0a : 
    case 0x0b : 
    case 0x0c : 
    case 0x0d : 
    case 0x0e : 
    case 0x0f : 
    case 0x10 : 
    case 0x11 : 
    case 0x12 : 
    case 0x13 : 
    case 0x14 : 
    case 0x15 : 
    case 0x16 : 
    case 0x17 : 
    case 0x18 : 
    case 0x19 : 
    case 0x1a : 
    case 0x1b : 
    case 0x1c : 
    case 0x1d : 
    case 0x1e : 
    case 0x1f : 
    // Remaining Instruction is 2
    // c.slli     r[11:7],u[12:12]|u[6:2]
    // c.jr       r[11:7]
      return DecodeInst_LD_10_F3_000_OP_00000_R3_00000_F2_00_R2_00000 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_10_F3_000_OP_00000_R3_00000_F2_00_R2_00000 (InstWord_t inst) {
  InstWord_t field_R1 = ExtractR1Field (inst);
  switch (field_R1) {
    case 0x00 : 
    case 0x02 : 
    case 0x04 : 
    case 0x06 : 
    case 0x08 : 
    case 0x0a : 
    case 0x0c : 
    case 0x0e : 
    case 0x10 : 
    case 0x12 : 
    case 0x14 : 
    case 0x16 : 
    case 0x18 : 
    case 0x1a : 
    case 0x1c : 
    case 0x1e : 
      return InstId_t::INST_ID_C_SLLI;
    case 0x01 : 
    case 0x03 : 
    case 0x05 : 
    case 0x07 : 
    case 0x09 : 
    case 0x0b : 
    case 0x0d : 
    case 0x0f : 
    case 0x11 : 
    case 0x13 : 
    case 0x15 : 
    case 0x17 : 
    case 0x19 : 
    case 0x1b : 
    case 0x1d : 
    case 0x1f : 
      return InstId_t::INST_ID_C_JR;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_10_F3_000_OP_00001 (InstWord_t inst) {
  InstWord_t field_R3 = ExtractR3Field (inst);
  switch (field_R3) {
    case 0x00 : 
    case 0x01 : 
    case 0x02 : 
    case 0x03 : 
    case 0x04 : 
    case 0x05 : 
    case 0x06 : 
    case 0x07 : 
    case 0x08 : 
    case 0x09 : 
    case 0x0a : 
    case 0x0b : 
    case 0x0c : 
    case 0x0d : 
    case 0x0e : 
    case 0x0f : 
    case 0x10 : 
    case 0x11 : 
    case 0x12 : 
    case 0x13 : 
    case 0x14 : 
    case 0x15 : 
    case 0x16 : 
    case 0x17 : 
    case 0x18 : 
    case 0x19 : 
    case 0x1a : 
    case 0x1b : 
    case 0x1c : 
    case 0x1d : 
    case 0x1e : 
    case 0x1f : 
    // Remaining Instruction is 2
    // c.slli     r[11:7],u[12:12]|u[6:2]
    // c.mv       r[11:7],r[6:2]
      return DecodeInst_LD_10_F3_000_OP_00001_R3_00000 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_10_F3_000_OP_00001_R3_00000 (InstWord_t inst) {
  InstWord_t field_F2 = ExtractF2Field (inst);
  switch (field_F2) {
    case 0x00 : 
    case 0x01 : 
    case 0x02 : 
    case 0x03 : 
    // Remaining Instruction is 2
    // c.slli     r[11:7],u[12:12]|u[6:2]
    // c.mv       r[11:7],r[6:2]
      return DecodeInst_LD_10_F3_000_OP_00001_R3_00000_F2_00 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_10_F3_000_OP_00001_R3_00000_F2_00 (InstWord_t inst) {
  InstWord_t field_R2 = ExtractR2Field (inst);
  switch (field_R2) {
    case 0x00 : 
    case 0x01 : 
    case 0x02 : 
    case 0x03 : 
    case 0x04 : 
    case 0x05 : 
    case 0x06 : 
    case 0x07 : 
    case 0x08 : 
    case 0x09 : 
    case 0x0a : 
    case 0x0b : 
    case 0x0c : 
    case 0x0d : 
    case 0x0e : 
    case 0x0f : 
    case 0x10 : 
    case 0x11 : 
    case 0x12 : 
    case 0x13 : 
    case 0x14 : 
    case 0x15 : 
    case 0x16 : 
    case 0x17 : 
    case 0x18 : 
    case 0x19 : 
    case 0x1a : 
    case 0x1b : 
    case 0x1c : 
    case 0x1d : 
    case 0x1e : 
    case 0x1f : 
    // Remaining Instruction is 2
    // c.slli     r[11:7],u[12:12]|u[6:2]
    // c.mv       r[11:7],r[6:2]
      return DecodeInst_LD_10_F3_000_OP_00001_R3_00000_F2_00_R2_00000 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_10_F3_000_OP_00001_R3_00000_F2_00_R2_00000 (InstWord_t inst) {
  InstWord_t field_R1 = ExtractR1Field (inst);
  switch (field_R1) {
    case 0x00 : 
    case 0x02 : 
    case 0x04 : 
    case 0x06 : 
    case 0x08 : 
    case 0x0a : 
    case 0x0c : 
    case 0x0e : 
    case 0x10 : 
    case 0x12 : 
    case 0x14 : 
    case 0x16 : 
    case 0x18 : 
    case 0x1a : 
    case 0x1c : 
    case 0x1e : 
      return InstId_t::INST_ID_C_SLLI;
    case 0x01 : 
    case 0x03 : 
    case 0x05 : 
    case 0x07 : 
    case 0x09 : 
    case 0x0b : 
    case 0x0d : 
    case 0x0f : 
    case 0x11 : 
    case 0x13 : 
    case 0x15 : 
    case 0x17 : 
    case 0x19 : 
    case 0x1b : 
    case 0x1d : 
    case 0x1f : 
      return InstId_t::INST_ID_C_MV;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_10_F3_001 (InstWord_t inst) {
  InstWord_t field_OP = ExtractOPField (inst);
  switch (field_OP) {
    case 0x00 : 
    // Remaining Instruction is 3
    // c.slli     r[11:7],u[12:12]|u[6:2]
    // c.ebreak  
    // c.jalr     r[11:7]
      return DecodeInst_LD_10_F3_001_OP_00000 (inst); break;
    case 0x01 : 
    case 0x02 : 
    case 0x03 : 
    case 0x04 : 
    case 0x05 : 
    case 0x06 : 
    case 0x07 : 
    case 0x08 : 
    case 0x09 : 
    case 0x0a : 
    case 0x0b : 
    case 0x0c : 
    case 0x0d : 
    case 0x0e : 
    case 0x0f : 
    case 0x10 : 
    case 0x11 : 
    case 0x12 : 
    case 0x13 : 
    case 0x14 : 
    case 0x15 : 
    case 0x16 : 
    case 0x17 : 
    case 0x18 : 
    case 0x19 : 
    case 0x1a : 
    case 0x1b : 
    case 0x1c : 
    case 0x1d : 
    case 0x1e : 
    case 0x1f : 
    // Remaining Instruction is 2
    // c.slli     r[11:7],u[12:12]|u[6:2]
    // c.add      r[11:7],r[6:2]
      return DecodeInst_LD_10_F3_001_OP_00001 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_10_F3_001_OP_00000 (InstWord_t inst) {
  InstWord_t field_RD = ExtractRDField (inst);
  switch (field_RD) {
    case 0x01 : 
    case 0x02 : 
    case 0x03 : 
    case 0x04 : 
    case 0x05 : 
    case 0x06 : 
    case 0x07 : 
    case 0x08 : 
    case 0x09 : 
    case 0x0a : 
    case 0x0b : 
    case 0x0c : 
    case 0x0d : 
    case 0x0e : 
    case 0x0f : 
    case 0x10 : 
    case 0x11 : 
    case 0x12 : 
    case 0x13 : 
    case 0x14 : 
    case 0x15 : 
    case 0x16 : 
    case 0x17 : 
    case 0x18 : 
    case 0x19 : 
    case 0x1a : 
    case 0x1b : 
    case 0x1c : 
    case 0x1d : 
    case 0x1e : 
    case 0x1f : 
    // Remaining Instruction is 2
    // c.slli     r[11:7],u[12:12]|u[6:2]
    // c.jalr     r[11:7]
      return DecodeInst_LD_10_F3_001_OP_00000_RD_00001 (inst); break;
    case 0x00 : 
      return InstId_t::INST_ID_C_EBREAK;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_10_F3_001_OP_00000_RD_00001 (InstWord_t inst) {
  InstWord_t field_R3 = ExtractR3Field (inst);
  switch (field_R3) {
    case 0x00 : 
    case 0x01 : 
    case 0x02 : 
    case 0x03 : 
    case 0x04 : 
    case 0x05 : 
    case 0x06 : 
    case 0x07 : 
    case 0x08 : 
    case 0x09 : 
    case 0x0a : 
    case 0x0b : 
    case 0x0c : 
    case 0x0d : 
    case 0x0e : 
    case 0x0f : 
    case 0x10 : 
    case 0x11 : 
    case 0x12 : 
    case 0x13 : 
    case 0x14 : 
    case 0x15 : 
    case 0x16 : 
    case 0x17 : 
    case 0x18 : 
    case 0x19 : 
    case 0x1a : 
    case 0x1b : 
    case 0x1c : 
    case 0x1d : 
    case 0x1e : 
    case 0x1f : 
    // Remaining Instruction is 2
    // c.slli     r[11:7],u[12:12]|u[6:2]
    // c.jalr     r[11:7]
      return DecodeInst_LD_10_F3_001_OP_00000_RD_00001_R3_00000 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_10_F3_001_OP_00000_RD_00001_R3_00000 (InstWord_t inst) {
  InstWord_t field_F2 = ExtractF2Field (inst);
  switch (field_F2) {
    case 0x00 : 
    case 0x01 : 
    case 0x02 : 
    case 0x03 : 
    // Remaining Instruction is 2
    // c.slli     r[11:7],u[12:12]|u[6:2]
    // c.jalr     r[11:7]
      return DecodeInst_LD_10_F3_001_OP_00000_RD_00001_R3_00000_F2_00 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_10_F3_001_OP_00000_RD_00001_R3_00000_F2_00 (InstWord_t inst) {
  InstWord_t field_R2 = ExtractR2Field (inst);
  switch (field_R2) {
    case 0x00 : 
    case 0x01 : 
    case 0x02 : 
    case 0x03 : 
    case 0x04 : 
    case 0x05 : 
    case 0x06 : 
    case 0x07 : 
    case 0x08 : 
    case 0x09 : 
    case 0x0a : 
    case 0x0b : 
    case 0x0c : 
    case 0x0d : 
    case 0x0e : 
    case 0x0f : 
    case 0x10 : 
    case 0x11 : 
    case 0x12 : 
    case 0x13 : 
    case 0x14 : 
    case 0x15 : 
    case 0x16 : 
    case 0x17 : 
    case 0x18 : 
    case 0x19 : 
    case 0x1a : 
    case 0x1b : 
    case 0x1c : 
    case 0x1d : 
    case 0x1e : 
    case 0x1f : 
    // Remaining Instruction is 2
    // c.slli     r[11:7],u[12:12]|u[6:2]
    // c.jalr     r[11:7]
      return DecodeInst_LD_10_F3_001_OP_00000_RD_00001_R3_00000_F2_00_R2_00000 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_10_F3_001_OP_00000_RD_00001_R3_00000_F2_00_R2_00000 (InstWord_t inst) {
  InstWord_t field_R1 = ExtractR1Field (inst);
  switch (field_R1) {
    case 0x00 : 
    case 0x02 : 
    case 0x04 : 
    case 0x06 : 
    case 0x08 : 
    case 0x0a : 
    case 0x0c : 
    case 0x0e : 
    case 0x10 : 
    case 0x12 : 
    case 0x14 : 
    case 0x16 : 
    case 0x18 : 
    case 0x1a : 
    case 0x1c : 
    case 0x1e : 
      return InstId_t::INST_ID_C_SLLI;
    case 0x01 : 
    case 0x03 : 
    case 0x05 : 
    case 0x07 : 
    case 0x09 : 
    case 0x0b : 
    case 0x0d : 
    case 0x0f : 
    case 0x11 : 
    case 0x13 : 
    case 0x15 : 
    case 0x17 : 
    case 0x19 : 
    case 0x1b : 
    case 0x1d : 
    case 0x1f : 
      return InstId_t::INST_ID_C_JALR;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_10_F3_001_OP_00001 (InstWord_t inst) {
  InstWord_t field_R3 = ExtractR3Field (inst);
  switch (field_R3) {
    case 0x00 : 
    case 0x01 : 
    case 0x02 : 
    case 0x03 : 
    case 0x04 : 
    case 0x05 : 
    case 0x06 : 
    case 0x07 : 
    case 0x08 : 
    case 0x09 : 
    case 0x0a : 
    case 0x0b : 
    case 0x0c : 
    case 0x0d : 
    case 0x0e : 
    case 0x0f : 
    case 0x10 : 
    case 0x11 : 
    case 0x12 : 
    case 0x13 : 
    case 0x14 : 
    case 0x15 : 
    case 0x16 : 
    case 0x17 : 
    case 0x18 : 
    case 0x19 : 
    case 0x1a : 
    case 0x1b : 
    case 0x1c : 
    case 0x1d : 
    case 0x1e : 
    case 0x1f : 
    // Remaining Instruction is 2
    // c.slli     r[11:7],u[12:12]|u[6:2]
    // c.add      r[11:7],r[6:2]
      return DecodeInst_LD_10_F3_001_OP_00001_R3_00000 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_10_F3_001_OP_00001_R3_00000 (InstWord_t inst) {
  InstWord_t field_F2 = ExtractF2Field (inst);
  switch (field_F2) {
    case 0x00 : 
    case 0x01 : 
    case 0x02 : 
    case 0x03 : 
    // Remaining Instruction is 2
    // c.slli     r[11:7],u[12:12]|u[6:2]
    // c.add      r[11:7],r[6:2]
      return DecodeInst_LD_10_F3_001_OP_00001_R3_00000_F2_00 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_10_F3_001_OP_00001_R3_00000_F2_00 (InstWord_t inst) {
  InstWord_t field_R2 = ExtractR2Field (inst);
  switch (field_R2) {
    case 0x00 : 
    case 0x01 : 
    case 0x02 : 
    case 0x03 : 
    case 0x04 : 
    case 0x05 : 
    case 0x06 : 
    case 0x07 : 
    case 0x08 : 
    case 0x09 : 
    case 0x0a : 
    case 0x0b : 
    case 0x0c : 
    case 0x0d : 
    case 0x0e : 
    case 0x0f : 
    case 0x10 : 
    case 0x11 : 
    case 0x12 : 
    case 0x13 : 
    case 0x14 : 
    case 0x15 : 
    case 0x16 : 
    case 0x17 : 
    case 0x18 : 
    case 0x19 : 
    case 0x1a : 
    case 0x1b : 
    case 0x1c : 
    case 0x1d : 
    case 0x1e : 
    case 0x1f : 
    // Remaining Instruction is 2
    // c.slli     r[11:7],u[12:12]|u[6:2]
    // c.add      r[11:7],r[6:2]
      return DecodeInst_LD_10_F3_001_OP_00001_R3_00000_F2_00_R2_00000 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_10_F3_001_OP_00001_R3_00000_F2_00_R2_00000 (InstWord_t inst) {
  InstWord_t field_R1 = ExtractR1Field (inst);
  switch (field_R1) {
    case 0x00 : 
    case 0x02 : 
    case 0x04 : 
    case 0x06 : 
    case 0x08 : 
    case 0x0a : 
    case 0x0c : 
    case 0x0e : 
    case 0x10 : 
    case 0x12 : 
    case 0x14 : 
    case 0x16 : 
    case 0x18 : 
    case 0x1a : 
    case 0x1c : 
    case 0x1e : 
      return InstId_t::INST_ID_C_SLLI;
    case 0x01 : 
    case 0x03 : 
    case 0x05 : 
    case 0x07 : 
    case 0x09 : 
    case 0x0b : 
    case 0x0d : 
    case 0x0f : 
    case 0x11 : 
    case 0x13 : 
    case 0x15 : 
    case 0x17 : 
    case 0x19 : 
    case 0x1b : 
    case 0x1d : 
    case 0x1f : 
      return InstId_t::INST_ID_C_ADD;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_10_F3_010 (InstWord_t inst) {
  InstWord_t field_R3 = ExtractR3Field (inst);
  switch (field_R3) {
    case 0x00 : 
    case 0x01 : 
    case 0x02 : 
    case 0x03 : 
    case 0x04 : 
    case 0x05 : 
    case 0x06 : 
    case 0x07 : 
    case 0x08 : 
    case 0x09 : 
    case 0x0a : 
    case 0x0b : 
    case 0x0c : 
    case 0x0d : 
    case 0x0e : 
    case 0x0f : 
    case 0x10 : 
    case 0x11 : 
    case 0x12 : 
    case 0x13 : 
    case 0x14 : 
    case 0x15 : 
    case 0x16 : 
    case 0x17 : 
    case 0x18 : 
    case 0x19 : 
    case 0x1a : 
    case 0x1b : 
    case 0x1c : 
    case 0x1d : 
    case 0x1e : 
    case 0x1f : 
    // Remaining Instruction is 2
    // c.fldsp    r[11:7],u[4:2]|u[12:12]|u[6:5]<<3 
    // c.fsdsp    f[6:2],u[9:7]|u[12:10]<<3
      return DecodeInst_LD_10_F3_010_R3_00000 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_10_F3_010_R3_00000 (InstWord_t inst) {
  InstWord_t field_F2 = ExtractF2Field (inst);
  switch (field_F2) {
    case 0x00 : 
    case 0x01 : 
    case 0x02 : 
    case 0x03 : 
    // Remaining Instruction is 2
    // c.fldsp    r[11:7],u[4:2]|u[12:12]|u[6:5]<<3 
    // c.fsdsp    f[6:2],u[9:7]|u[12:10]<<3
      return DecodeInst_LD_10_F3_010_R3_00000_F2_00 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_10_F3_010_R3_00000_F2_00 (InstWord_t inst) {
  InstWord_t field_R2 = ExtractR2Field (inst);
  switch (field_R2) {
    case 0x00 : 
    case 0x01 : 
    case 0x02 : 
    case 0x03 : 
    case 0x04 : 
    case 0x05 : 
    case 0x06 : 
    case 0x07 : 
    case 0x08 : 
    case 0x09 : 
    case 0x0a : 
    case 0x0b : 
    case 0x0c : 
    case 0x0d : 
    case 0x0e : 
    case 0x0f : 
    case 0x10 : 
    case 0x11 : 
    case 0x12 : 
    case 0x13 : 
    case 0x14 : 
    case 0x15 : 
    case 0x16 : 
    case 0x17 : 
    case 0x18 : 
    case 0x19 : 
    case 0x1a : 
    case 0x1b : 
    case 0x1c : 
    case 0x1d : 
    case 0x1e : 
    case 0x1f : 
    // Remaining Instruction is 2
    // c.fldsp    r[11:7],u[4:2]|u[12:12]|u[6:5]<<3 
    // c.fsdsp    f[6:2],u[9:7]|u[12:10]<<3
      return DecodeInst_LD_10_F3_010_R3_00000_F2_00_R2_00000 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_10_F3_010_R3_00000_F2_00_R2_00000 (InstWord_t inst) {
  InstWord_t field_R1 = ExtractR1Field (inst);
  switch (field_R1) {
    case 0x00 : 
    case 0x02 : 
    case 0x04 : 
    case 0x06 : 
    case 0x08 : 
    case 0x0a : 
    case 0x0c : 
    case 0x0e : 
    case 0x10 : 
    case 0x12 : 
    case 0x14 : 
    case 0x16 : 
    case 0x18 : 
    case 0x1a : 
    case 0x1c : 
    case 0x1e : 
      return InstId_t::INST_ID_C_FLDSP;
    case 0x01 : 
    case 0x03 : 
    case 0x05 : 
    case 0x07 : 
    case 0x09 : 
    case 0x0b : 
    case 0x0d : 
    case 0x0f : 
    case 0x11 : 
    case 0x13 : 
    case 0x15 : 
    case 0x17 : 
    case 0x19 : 
    case 0x1b : 
    case 0x1d : 
    case 0x1f : 
      return InstId_t::INST_ID_C_FSDSP;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_10_F3_100 (InstWord_t inst) {
  InstWord_t field_R3 = ExtractR3Field (inst);
  switch (field_R3) {
    case 0x00 : 
    case 0x01 : 
    case 0x02 : 
    case 0x03 : 
    case 0x04 : 
    case 0x05 : 
    case 0x06 : 
    case 0x07 : 
    case 0x08 : 
    case 0x09 : 
    case 0x0a : 
    case 0x0b : 
    case 0x0c : 
    case 0x0d : 
    case 0x0e : 
    case 0x0f : 
    case 0x10 : 
    case 0x11 : 
    case 0x12 : 
    case 0x13 : 
    case 0x14 : 
    case 0x15 : 
    case 0x16 : 
    case 0x17 : 
    case 0x18 : 
    case 0x19 : 
    case 0x1a : 
    case 0x1b : 
    case 0x1c : 
    case 0x1d : 
    case 0x1e : 
    case 0x1f : 
    // Remaining Instruction is 2
    // c.lwsp     r[11:7],u[3:2]|u[12:12]|u[6:4]<<2
    // c.swsp     r[6:2],u[8:7]|u[12:9]<<2
      return DecodeInst_LD_10_F3_100_R3_00000 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_10_F3_100_R3_00000 (InstWord_t inst) {
  InstWord_t field_F2 = ExtractF2Field (inst);
  switch (field_F2) {
    case 0x00 : 
    case 0x01 : 
    case 0x02 : 
    case 0x03 : 
    // Remaining Instruction is 2
    // c.lwsp     r[11:7],u[3:2]|u[12:12]|u[6:4]<<2
    // c.swsp     r[6:2],u[8:7]|u[12:9]<<2
      return DecodeInst_LD_10_F3_100_R3_00000_F2_00 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_10_F3_100_R3_00000_F2_00 (InstWord_t inst) {
  InstWord_t field_R2 = ExtractR2Field (inst);
  switch (field_R2) {
    case 0x00 : 
    case 0x01 : 
    case 0x02 : 
    case 0x03 : 
    case 0x04 : 
    case 0x05 : 
    case 0x06 : 
    case 0x07 : 
    case 0x08 : 
    case 0x09 : 
    case 0x0a : 
    case 0x0b : 
    case 0x0c : 
    case 0x0d : 
    case 0x0e : 
    case 0x0f : 
    case 0x10 : 
    case 0x11 : 
    case 0x12 : 
    case 0x13 : 
    case 0x14 : 
    case 0x15 : 
    case 0x16 : 
    case 0x17 : 
    case 0x18 : 
    case 0x19 : 
    case 0x1a : 
    case 0x1b : 
    case 0x1c : 
    case 0x1d : 
    case 0x1e : 
    case 0x1f : 
    // Remaining Instruction is 2
    // c.lwsp     r[11:7],u[3:2]|u[12:12]|u[6:4]<<2
    // c.swsp     r[6:2],u[8:7]|u[12:9]<<2
      return DecodeInst_LD_10_F3_100_R3_00000_F2_00_R2_00000 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_10_F3_100_R3_00000_F2_00_R2_00000 (InstWord_t inst) {
  InstWord_t field_R1 = ExtractR1Field (inst);
  switch (field_R1) {
    case 0x00 : 
    case 0x02 : 
    case 0x04 : 
    case 0x06 : 
    case 0x08 : 
    case 0x0a : 
    case 0x0c : 
    case 0x0e : 
    case 0x10 : 
    case 0x12 : 
    case 0x14 : 
    case 0x16 : 
    case 0x18 : 
    case 0x1a : 
    case 0x1c : 
    case 0x1e : 
      return InstId_t::INST_ID_C_LWSP;
    case 0x01 : 
    case 0x03 : 
    case 0x05 : 
    case 0x07 : 
    case 0x09 : 
    case 0x0b : 
    case 0x0d : 
    case 0x0f : 
    case 0x11 : 
    case 0x13 : 
    case 0x15 : 
    case 0x17 : 
    case 0x19 : 
    case 0x1b : 
    case 0x1d : 
    case 0x1f : 
      return InstId_t::INST_ID_C_SWSP;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_10_F3_110 (InstWord_t inst) {
  InstWord_t field_R3 = ExtractR3Field (inst);
  switch (field_R3) {
    case 0x00 : 
    case 0x01 : 
    case 0x02 : 
    case 0x03 : 
    case 0x04 : 
    case 0x05 : 
    case 0x06 : 
    case 0x07 : 
    case 0x08 : 
    case 0x09 : 
    case 0x0a : 
    case 0x0b : 
    case 0x0c : 
    case 0x0d : 
    case 0x0e : 
    case 0x0f : 
    case 0x10 : 
    case 0x11 : 
    case 0x12 : 
    case 0x13 : 
    case 0x14 : 
    case 0x15 : 
    case 0x16 : 
    case 0x17 : 
    case 0x18 : 
    case 0x19 : 
    case 0x1a : 
    case 0x1b : 
    case 0x1c : 
    case 0x1d : 
    case 0x1e : 
    case 0x1f : 
    // Remaining Instruction is 4
    // c.flwsp    f[11:7],u[3:2]|u[12:12]|u[6:4]<<2
    // c.ldsp     r[11:7],u[4:2]|u[12:12]|u[6:5]<<3
    // c.fswsp    f[6:2],u[9:7]|u[12:10]<<3
    // c.sdsp     r[6:2],u[9:7]|u[12:10]<<3
      return DecodeInst_LD_10_F3_110_R3_00000 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_10_F3_110_R3_00000 (InstWord_t inst) {
  InstWord_t field_F2 = ExtractF2Field (inst);
  switch (field_F2) {
    case 0x00 : 
    case 0x01 : 
    case 0x02 : 
    case 0x03 : 
    // Remaining Instruction is 4
    // c.flwsp    f[11:7],u[3:2]|u[12:12]|u[6:4]<<2
    // c.ldsp     r[11:7],u[4:2]|u[12:12]|u[6:5]<<3
    // c.fswsp    f[6:2],u[9:7]|u[12:10]<<3
    // c.sdsp     r[6:2],u[9:7]|u[12:10]<<3
      return DecodeInst_LD_10_F3_110_R3_00000_F2_00 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_10_F3_110_R3_00000_F2_00 (InstWord_t inst) {
  InstWord_t field_R2 = ExtractR2Field (inst);
  switch (field_R2) {
    case 0x00 : 
    case 0x01 : 
    case 0x02 : 
    case 0x03 : 
    case 0x04 : 
    case 0x05 : 
    case 0x06 : 
    case 0x07 : 
    case 0x08 : 
    case 0x09 : 
    case 0x0a : 
    case 0x0b : 
    case 0x0c : 
    case 0x0d : 
    case 0x0e : 
    case 0x0f : 
    case 0x10 : 
    case 0x11 : 
    case 0x12 : 
    case 0x13 : 
    case 0x14 : 
    case 0x15 : 
    case 0x16 : 
    case 0x17 : 
    case 0x18 : 
    case 0x19 : 
    case 0x1a : 
    case 0x1b : 
    case 0x1c : 
    case 0x1d : 
    case 0x1e : 
    case 0x1f : 
    // Remaining Instruction is 4
    // c.flwsp    f[11:7],u[3:2]|u[12:12]|u[6:4]<<2
    // c.ldsp     r[11:7],u[4:2]|u[12:12]|u[6:5]<<3
    // c.fswsp    f[6:2],u[9:7]|u[12:10]<<3
    // c.sdsp     r[6:2],u[9:7]|u[12:10]<<3
      return DecodeInst_LD_10_F3_110_R3_00000_F2_00_R2_00000 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_10_F3_110_R3_00000_F2_00_R2_00000 (InstWord_t inst) {
  InstWord_t field_R1 = ExtractR1Field (inst);
  switch (field_R1) {
    case 0x00 : 
    case 0x02 : 
    case 0x04 : 
    case 0x06 : 
    case 0x08 : 
    case 0x0a : 
    case 0x0c : 
    case 0x0e : 
    case 0x10 : 
    case 0x12 : 
    case 0x14 : 
    case 0x16 : 
    case 0x18 : 
    case 0x1a : 
    case 0x1c : 
    case 0x1e : 
    // Remaining Instruction is 2
    // c.flwsp    f[11:7],u[3:2]|u[12:12]|u[6:4]<<2
    // c.ldsp     r[11:7],u[4:2]|u[12:12]|u[6:5]<<3
      return DecodeInst_LD_10_F3_110_R3_00000_F2_00_R2_00000_R1_00000 (inst); break;
    case 0x01 : 
    case 0x03 : 
    case 0x05 : 
    case 0x07 : 
    case 0x09 : 
    case 0x0b : 
    case 0x0d : 
    case 0x0f : 
    case 0x11 : 
    case 0x13 : 
    case 0x15 : 
    case 0x17 : 
    case 0x19 : 
    case 0x1b : 
    case 0x1d : 
    case 0x1f : 
    // Remaining Instruction is 2
    // c.fswsp    f[6:2],u[9:7]|u[12:10]<<3
    // c.sdsp     r[6:2],u[9:7]|u[12:10]<<3
      return DecodeInst_LD_10_F3_110_R3_00000_F2_00_R2_00000_R1_00001 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_10_F3_110_R3_00000_F2_00_R2_00000_R1_00000 (InstWord_t inst) {
  InstWord_t field_RD = ExtractRDField (inst);
  switch (field_RD) {
    case 0x00 : 
      return InstId_t::INST_ID_C_FLWSP;
    case 0x01 : 
    case 0x02 : 
    case 0x03 : 
    case 0x04 : 
    case 0x05 : 
    case 0x06 : 
    case 0x07 : 
    case 0x08 : 
    case 0x09 : 
    case 0x0a : 
    case 0x0b : 
    case 0x0c : 
    case 0x0d : 
    case 0x0e : 
    case 0x0f : 
    case 0x10 : 
    case 0x11 : 
    case 0x12 : 
    case 0x13 : 
    case 0x14 : 
    case 0x15 : 
    case 0x16 : 
    case 0x17 : 
    case 0x18 : 
    case 0x19 : 
    case 0x1a : 
    case 0x1b : 
    case 0x1c : 
    case 0x1d : 
    case 0x1e : 
    case 0x1f : 
    // Remaining Instruction is 2
    // c.flwsp    f[11:7],u[3:2]|u[12:12]|u[6:4]<<2
    // c.ldsp     r[11:7],u[4:2]|u[12:12]|u[6:5]<<3
      return DecodeInst_LD_10_F3_110_R3_00000_F2_00_R2_00000_R1_00000_RD_00001 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_10_F3_110_R3_00000_F2_00_R2_00000_R1_00000_RD_00001 (InstWord_t inst) {
  InstWord_t field_OP = ExtractOPField (inst);
  switch (field_OP) {
    case 0x00 : 
    case 0x01 : 
    case 0x02 : 
    case 0x03 : 
    case 0x04 : 
    case 0x05 : 
    case 0x06 : 
    case 0x07 : 
    case 0x08 : 
    case 0x09 : 
    case 0x0a : 
    case 0x0b : 
    case 0x0c : 
    case 0x0d : 
    case 0x0e : 
    case 0x0f : 
    case 0x10 : 
    case 0x11 : 
    case 0x12 : 
    case 0x13 : 
    case 0x14 : 
    case 0x15 : 
    case 0x16 : 
    case 0x17 : 
    case 0x18 : 
    case 0x19 : 
    case 0x1a : 
    case 0x1b : 
    case 0x1c : 
    case 0x1d : 
    case 0x1e : 
    case 0x1f : 
    // Remaining Instruction is 2
    // c.flwsp    f[11:7],u[3:2]|u[12:12]|u[6:4]<<2
    // c.ldsp     r[11:7],u[4:2]|u[12:12]|u[6:5]<<3
      return DecodeInst_LD_10_F3_110_R3_00000_F2_00_R2_00000_R1_00000_RD_00001_OP_00000 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_10_F3_110_R3_00000_F2_00_R2_00000_R1_00001 (InstWord_t inst) {
  InstWord_t field_RD = ExtractRDField (inst);
  switch (field_RD) {
    case 0x00 : 
    case 0x01 : 
    case 0x02 : 
    case 0x03 : 
    case 0x04 : 
    case 0x05 : 
    case 0x06 : 
    case 0x07 : 
    case 0x08 : 
    case 0x09 : 
    case 0x0a : 
    case 0x0b : 
    case 0x0c : 
    case 0x0d : 
    case 0x0e : 
    case 0x0f : 
    case 0x10 : 
    case 0x11 : 
    case 0x12 : 
    case 0x13 : 
    case 0x14 : 
    case 0x15 : 
    case 0x16 : 
    case 0x17 : 
    case 0x18 : 
    case 0x19 : 
    case 0x1a : 
    case 0x1b : 
    case 0x1c : 
    case 0x1d : 
    case 0x1e : 
    case 0x1f : 
    // Remaining Instruction is 2
    // c.fswsp    f[6:2],u[9:7]|u[12:10]<<3
    // c.sdsp     r[6:2],u[9:7]|u[12:10]<<3
      return DecodeInst_LD_10_F3_110_R3_00000_F2_00_R2_00000_R1_00001_RD_00000 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
InstId_t RiscvDec::DecodeInst_LD_10_F3_110_R3_00000_F2_00_R2_00000_R1_00001_RD_00000 (InstWord_t inst) {
  InstWord_t field_OP = ExtractOPField (inst);
  switch (field_OP) {
    case 0x00 : 
    case 0x01 : 
    case 0x02 : 
    case 0x03 : 
    case 0x04 : 
    case 0x05 : 
    case 0x06 : 
    case 0x07 : 
    case 0x08 : 
    case 0x09 : 
    case 0x0a : 
    case 0x0b : 
    case 0x0c : 
    case 0x0d : 
    case 0x0e : 
    case 0x0f : 
    case 0x10 : 
    case 0x11 : 
    case 0x12 : 
    case 0x13 : 
    case 0x14 : 
    case 0x15 : 
    case 0x16 : 
    case 0x17 : 
    case 0x18 : 
    case 0x19 : 
    case 0x1a : 
    case 0x1b : 
    case 0x1c : 
    case 0x1d : 
    case 0x1e : 
    case 0x1f : 
    // Remaining Instruction is 2
    // c.fswsp    f[6:2],u[9:7]|u[12:10]<<3
    // c.sdsp     r[6:2],u[9:7]|u[12:10]<<3
      return DecodeInst_LD_10_F3_110_R3_00000_F2_00_R2_00000_R1_00001_RD_00000_OP_00000 (inst); break;
    default : return InstId_t::INST_ID_SENTINEL_MAX;
  }
  return InstId_t::INST_ID_SENTINEL_MAX;
}
