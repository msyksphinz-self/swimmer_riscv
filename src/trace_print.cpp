/*
 * Copyright (c) 2016, msyksphinz
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

#include <iostream>
#include <iomanip>
#include "env.hpp"
#include "trace.hpp"
#include "sc3_pe_thread.hpp"

void Sc3PeThread::PrintOperandV8H (std::stringstream *operand_str, UDWord_t v0, UDWord_t v1)
{
  V8h_t v8_val;
  v8_val.Set64(1, v0);
  v8_val.Set64(0, v1);
  (*operand_str) << "(";
  for (int way=7; way >=0; way--) {
    F_W_t f_w;
    f_w.w = InstOps::Convert_HtoS (v8_val.GetElem(way));
    (*operand_str) << std::showpoint << f_w.f;
    if (way != 0) { (*operand_str) << ','; }
  }
  (*operand_str) << ")";
  return;
}


void Sc3PeThread::PrintOperandV4F (std::stringstream *operand_str, UDWord_t v1, UDWord_t v0)
{
  V4f_t v4_val;
  v4_val.Set64(0, v0);
  v4_val.Set64(1, v1);
  (*operand_str) << "(";
  for (int way=3; way >=0; way--) {
    F_W_t f_w;
    f_w.w = v4_val.GetElem(way);
    (*operand_str) << std::showpoint << f_w.f;
    if (way != 0) { (*operand_str) << ','; }
  }
  (*operand_str) << ")";
  return;
}


void Sc3PeThread::PrintOperandV2D (std::stringstream *operand_str, UDWord_t v1, UDWord_t v0)
{
  D_W_t d_w[2]; d_w[0].w = v0; d_w[1].w = v1;
  (*operand_str) << "(" << std::showpoint << d_w[1].d << "," << d_w[0].d << ")";
  return;
}


void Sc3PeThread::PrintOperandF(std::stringstream *operand_str, Word_t v)
{
  F_W_t f_w; f_w.w = v;
  (*operand_str) << std::showpoint << f_w.f;
  return;
}


void Sc3PeThread::PrintOperandD(std::stringstream *operand_str, DWord_t v)
{
  D_W_t d_w; d_w.w = v;
  (*operand_str) << std::showpoint << d_w.d;
  return;
}


void Sc3PeThread::PrintOperandD4H (std::stringstream *operand_str, UDWord_t v0)
{
  (*operand_str) << "(";
  for (int way=3; way >=0; way--) {
    F_W_t f_w;
    f_w.w = InstOps::Convert_HtoS ((v0 >> (way * 16)) & 0xffff);
    (*operand_str) << std::showpoint << f_w.f;
    if (way != 0) { (*operand_str) << ','; }
  }
  (*operand_str) << ")";
  return;
}


void Sc3PeThread::PrintOperandD2F (std::stringstream *operand_str, UDWord_t v0)
{
  (*operand_str) << "(";
  for (int way=1; way >=0; way--) {
    F_W_t f_w;
    f_w.w = (v0 >> (way * 32)) & 0xffffffff;
    (*operand_str) << std::showpoint << f_w.f;
    if (way != 0) { (*operand_str) << ','; }
  }
  (*operand_str) << ")";
  return;
}
