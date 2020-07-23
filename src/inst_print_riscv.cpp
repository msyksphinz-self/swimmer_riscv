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

#include <string>
#include <stdint.h>
#include <stdlib.h>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <string.h>
#include "riscv_pe_thread.hpp"
#include "inst_operand_riscv.hpp"

extern char *inst_strings [];
extern operandList inst_operand[];

void RiscvPeThread::PrintInst (uint32_t inst_hex, InstId_t inst_idx,
                               char *str_out, const uint32_t length)
{
  char *str_head = str_out;
  uint32_t i_inst_id = static_cast<uint32_t>(inst_idx);
  char *inst_str = inst_strings[i_inst_id];
  uint32_t replace_idx = 0;
  while (inst_str[0] != '\0') {
    if (replace_idx > inst_operand[i_inst_id].size) {
      DebugPrint ("<Internal Error: instruction format index exceeded: %d >= %d\n", replace_idx, inst_operand[i_inst_id].size);
      // exit (EXIT_FAILURE);
    }
    if (inst_str[0] == '@') {
      uint32_t length_field = 0;
      operandType type;
      uint32_t operand_bit = 0;
      do {
        uint32_t msb_bit = inst_operand[i_inst_id].msb_lst[replace_idx];
        uint32_t lsb_bit = inst_operand[i_inst_id].lsb_lst[replace_idx];
        type = inst_operand[i_inst_id].type_lst[replace_idx];
        length_field = length_field + (msb_bit - lsb_bit + 1);
        operand_bit = (operand_bit << (msb_bit - lsb_bit + 1)) | ExtractBitField (inst_hex, msb_bit, lsb_bit);
        replace_idx++;
      } while ((replace_idx <= inst_operand[i_inst_id].size) &&
               (inst_operand[i_inst_id].connect[replace_idx-1] != 0));
      if (type != operandType::operandTypeBit) {  // if Binary expression, length is not changed
        length_field = length_field % 4 == 0 ? (length_field / 4) : (length_field / 4 + 1);
      }

      if (type == operandType::operandTypeCompactReg ||
          type == operandType::operandTypeCompactFReg) {
        operand_bit = operand_bit + 8;
        length_field +=1;
      }

      // Step Next
      if (!strncmp(&inst_str[1], "<<", 2)) {
        inst_str+=3;
        int shift_val = 0;
        while(isdigit(inst_str[0])) {
          shift_val <<= 10;
          shift_val += (inst_str[0] - 0x30);
          inst_str++;
        }
        operand_bit <<= shift_val;
      } else {
        inst_str++;
      }

      uint8_t disp_array[10];
      uint32_t divide_base;
      switch (type) {
        case operandType::operandTypeReg        : divide_base = 10; break;
        case operandType::operandTypeCompactReg : divide_base = 10; break;
        case operandType::operandTypeCompactFReg: divide_base = 10; break;
        case operandType::operandTypeXReg       : divide_base = 10; break;
        case operandType::operandTypeBit        : divide_base = 2;  break;
        case operandType::operandTypeHex        : divide_base = 16; break;
        case operandType::operandTypeSign       : divide_base = 16; break;
        case operandType::operandTypeUnSign     : divide_base = 16; break;
        case operandType::operandTypeFreg       : divide_base = 10; break;
        case operandType::operandTypeVreg       : divide_base = 10; break;
        case operandType::operandTypeVmask      : divide_base = 10; break;
        default                                 : divide_base = 10; break;
      }
      for (uint32_t i = 0, tmp_operand_bit = operand_bit; i < length_field; i++) {
        disp_array[i] = tmp_operand_bit % divide_base;
        tmp_operand_bit = tmp_operand_bit / divide_base;
      }
      switch (type) {
        case operandType::operandTypeReg         : sprintf (str_head, "x");  str_head +=1; break;
        case operandType::operandTypeCompactReg  : sprintf (str_head, "x");  str_head +=1; break;
        case operandType::operandTypeCompactFReg : sprintf (str_head, "f");  str_head +=1; break;
        case operandType::operandTypeXReg        : sprintf (str_head, "x");  str_head +=1; break;
        case operandType::operandTypeBit         :                                         break;
        case operandType::operandTypeHex         : sprintf (str_head, "0x"); str_head +=2; break;
        case operandType::operandTypeSign        : sprintf (str_head, "0x"); str_head +=2; break;
        case operandType::operandTypeUnSign      : sprintf (str_head, "0x"); str_head +=2; break;
        case operandType::operandTypeFreg        : sprintf (str_head, "f");  str_head +=1; break;
        case operandType::operandTypeVreg        : sprintf (str_head, "v");  str_head +=1; break;
        case operandType::operandTypeVmask       :
          if (operand_bit == 0) {
            sprintf (str_head, ",v0.t");  str_head +=5;
          }
          break;
        default                                  : break;
      }

      if (type != operandType::operandTypeVmask) {
        for (int i = length_field - 1; i >= 0; i--) {
          if (divide_base == 16) {
            str_head[0] = (disp_array[i] < 10) ? disp_array[i] + 0x30 : disp_array[i] + 0x57;
          } else if (divide_base <= 10) {
            str_head[0] = disp_array[i] + 0x30;
          }
          str_head ++;
        }
      }
    } else {
      str_head[0] = inst_str[0];
      str_head++;
      inst_str++;
    }
  }
  str_head[0] = '\0'; str_head ++;
}
