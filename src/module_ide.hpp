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

#pragma once

#include "./mem_body.hpp"

class RiscvPeThread;

class ModuleIde
{
 private:
  RiscvPeThread *m_env;
  FILE  *m_debug_fp;

  std::string m_img_filename;
  FILE     *m_img_fp;
  uint32_t  m_read_count;

  uint8_t m_data;       // 0x01f0(RW)
  uint8_t m_err;        // 0x01f1(R)
  uint8_t m_feature;      // 0x01f1(W)
  uint8_t m_sector_count;   // 0x01f2(RW)
  uint8_t m_sector_number;  // 0x01f3(RW)
  uint8_t m_cylinder_low;   // 0x01f4(RW)
  uint8_t m_cylinder_high;  // 0x01f5(RW)
  uint8_t m_device_head;    // 0x01f6(RW)
  uint8_t m_status;       // 0x01f7(R)
  uint8_t m_command;      // 0x01f7(W)
  uint8_t m_alternate_status; // 0x03f6(R)
  uint8_t m_device_control;   // 0x03f6(W)

 public:
  MemResult LoadData (Addr_t addr, Size_t size, Word_t *data);
  MemResult StoreData (Addr_t addr, Size_t size, Word_t data);

  void SetImgFileName (std::string img_filename) { m_img_filename = img_filename; }

  void   OpenImgFile (void);
  void   CloseImgFile (void);
  Word_t ReadImgFile (void);


  ModuleIde (RiscvPeThread *env, FILE *dbgfp);
};
