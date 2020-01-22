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
#include <gmpxx.h>
#include <iostream>
#include <iomanip>
#include "inst_list_riscv.hpp"
#include "dec_utils_riscv.hpp"
#include "softfloat.h"
#include "riscv_pe_thread.hpp"
#include "inst_riscv.hpp"
#include "riscv_sysreg_impl.hpp"
#include "inst_ops.hpp"
#include "riscv_sysreg_bitdef.hpp"

void InstEnv::RISCV_INST_ANDN (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_ORN (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_XNOR (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_SLO (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_SRO (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_ROL (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_ROR (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_SH1ADD (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_SH2ADD (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_SH3ADD (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_SBCLR (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_SBSET (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_SBINV (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_SBEXT (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_GORC (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_GREV (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_SLOI (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_SROI (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_RORI (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_SBCLRI (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_SBSETI (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_SBINVI (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_SBEXTI (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_GORCI (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_GREVI (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_CMIX (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_CMOV (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_FSL (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_FSR (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_FSRI (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_CLZ (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_CTZ (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_PCNT (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_BMATFLIP (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_SEXT_B (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_SEXT_H (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_CRC32_B (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_CRC32_H (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_CRC32_W (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_CRC32_D (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_CRC32C_B (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_CRC32C_H (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_CRC32C_W (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_CRC32C_D (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_CLMUL (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_CLMULR (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_CLMULH (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_MIN (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_MAX (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_MINU (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_MAXU (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_SHFL (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_UNSHFL (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_BDEP (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_BEXT (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_PACK (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_PACKU (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_BMATOR (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_BMATXOR (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_PACKH (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_BFP (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_SHFLI (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_UNSHFLI (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_ADDIWU (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_ADDWU (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_SUBWU (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_ADDU_W (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_SUBU_W (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_SLOW (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_SROW (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_ROLW (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_RORW (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_SH1ADDU_W (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_SH2ADDU_W (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_SH3ADDU_W (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_SBCLRW (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_SBSETW (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_SBINVW (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_SBEXTW (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_GORCW (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_GREVW (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_SLOIW (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_SROIW (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_RORIW (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_SBCLRIW (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_SBSETIW (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_SBINVIW (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_GORCIW (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_GREVIW (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_FSLW (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_FSRW (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_FSRIW (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_CLZW (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_CTZW (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_PCNTW (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_CLMULW (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_CLMULRW (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_CLMULHW (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_SHFLW (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_UNSHFLW (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_BDEPW (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_BEXTW (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_PACKW (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_PACKUW (InstWord_t inst_hex) {}
void InstEnv::RISCV_INST_BFPW (InstWord_t inst_hex) {}
