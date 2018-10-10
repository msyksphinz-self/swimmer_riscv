#!/usr/bin/ruby
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

require './riscv_spr_table.rb'

##=== displaying headers ===

def gen_header(fp)
  fp.puts("/*")
  fp.puts(" * Copyright (c) 2015, Masayuki Kimura")
  fp.puts(" * All rights reserved.")
  fp.puts(" *")
  fp.puts(" *   Redistribution and use in source and binary forms, with or without")
  fp.puts(" *   modification, are permitted provided that the following conditions are met:")
  fp.puts(" *   * Redistributions of source code must retain the above copyright")
  fp.puts(" *   notice, this list of conditions and the following disclaimer.")
  fp.puts(" *   * Redistributions in binary form must reproduce the above copyright")
  fp.puts(" *   notice, this list of conditions and the following disclaimer in the")
  fp.puts(" *     documentation and/or other materials provided with the distribution.")
  fp.puts(" *   * Neither the name of the Masayuki Kimura nor the")
  fp.puts(" *     names of its contributors may be used to endorse or promote products")
  fp.puts(" *     derived from this software without specific prior written permission.")
  fp.puts(" *")
  fp.puts(" * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS \"AS IS\" AND")
  fp.puts(" *   ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED")
  fp.puts(" * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE")
  fp.puts(" * DISCLAIMED. IN NO EVENT SHALL MASAYUKI KIMURA BE LIABLE FOR ANY")
  fp.puts(" *   DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES")
  fp.puts(" *   (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;")
  fp.puts(" *    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND")
  fp.puts(" *   ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT")
  fp.puts(" *   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS")
  fp.puts(" *   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.")
  fp.puts(" */")
  fp.puts("")
  fp.puts("/* CAUTION! THIS SOURCE CODE IS GENERATED AUTOMATICALLY. DON'T MODIFY BY HAND. */")
  fp.puts("")
  fp.puts("")
end


def gen_csr_module(fp, csr_info)
  fp.printf("module CSR_%s (\n", csr_info[SYSREG::NAME])
  fp.printf("  input wire CPU_CLK,\n")
  fp.printf("  input wire CPU_RESET,\n")
  fp.printf("  input wire CSR_WE,\n")
  fp.printf("  input wire [31: 0] DATA_IN,\n")
  fp.printf("  output wire [31: 0] DATA_OUT);\n\n")

  csr_info[SYSREG::BITFIELD].each {|bitfield|
    bit_max  = bitfield[SYSREG_BITFIELD::MAX]
    bit_min  = bitfield[SYSREG_BITFIELD::MIN]
    bit_name = bitfield[SYSREG_BITFIELD::NAME]
    bit_rw   = bitfield[SYSREG_BITFIELD::RW]
    bit_init = bitfield[SYSREG_BITFIELD::INIT]

    if bit_rw != 'R' then
      fp.printf("  reg [%d:%d] csr_bit_%s;\n", bit_max, bit_min, bit_name)
    else
      fp.printf("  wire [%d:%d] csr_bit_%s = %d'h%x;\n", bit_max, bit_min, bit_name, bit_max-bit_min+1, bit_init)
    end
  }

  fp.printf("\n")

  csr_info[SYSREG::BITFIELD].each {|bitfield|
    bit_rw   = bitfield[SYSREG_BITFIELD::RW]
    bit_max  = bitfield[SYSREG_BITFIELD::MAX]
    bit_min  = bitfield[SYSREG_BITFIELD::MIN]
    bit_name = bitfield[SYSREG_BITFIELD::NAME]
    bit_init = bitfield[SYSREG_BITFIELD::INIT]

    if bit_init == nil then
      printf("Bit_Init<==NUL: %s\n", bit_name)
      exit
    end

    if bit_rw == 'RW' then
      fp.printf("  always @ (posedge CPU_CLK) begin\n")
      fp.printf("    if (CPU_RESET) begin\n")
      fp.printf("      csr_bit_%s <= %d'h%x;\n", bit_name, bit_max - bit_min + 1, bit_init)
      fp.printf("    end else begin\n")
      fp.printf("      csr_bit_%s <= CSR_WE ? DATA_IN[%d:%d] : csr_bit_%s;\n", bit_name, bit_max, bit_min, bit_name)
      fp.printf("    end\n")
      fp.printf("  end\n")
    end
  }

  fp.printf("  assign DATA_OUT = {\n")
  last_lsb = csr_info[SYSREG::BITFIELD][0][SYSREG_BITFIELD::MAX]+1
  csr_info[SYSREG::BITFIELD].each_with_index {|bitfield, index|
    bit_rw   = bitfield[SYSREG_BITFIELD::RW]
    bit_max  = bitfield[SYSREG_BITFIELD::MAX]
    bit_min  = bitfield[SYSREG_BITFIELD::MIN]
    bit_name = bitfield[SYSREG_BITFIELD::NAME]
    if last_lsb != bit_max+1 then
      fp.printf("       %d'h0,\n", last_lsb - bit_max - 1)
    end
    last_lsb = bit_min
    fp.printf("       csr_bit_%s", bit_name)
    if index == csr_info[SYSREG::BITFIELD].length-1 and last_lsb == 0 then
      fp.printf("\n")
    else
      fp.printf(",\n")
    end
  }
  if last_lsb != 0 then
    fp.printf("       %d'h0\n", last_lsb)
  end
  fp.printf("  };\n")

  fp.printf("endmodule\n")
end


arch_name = 'RISCV'

##
##=== making CSR Module ===
##

csr_define_fp = File.open('riscv_csr_dec.vh', 'w')

gen_header(csr_define_fp) # making header

$sysreg_table.each {|sysreg_info|
  gen_csr_module(csr_define_fp, sysreg_info)
  csr_define_fp.printf("\n\n")
}

csr_define_fp.close()


##
##=== making CSR Decode Module ===
##

way = 4

csr_decode_fp = File.open('csu_main.v', 'w')

gen_header(csr_decode_fp) # making header

csr_decode_fp.printf("`include \"./riscv_csr_dec.vh\"\n")
csr_decode_fp.printf("module csu_main (\n")
csr_decode_fp.printf("  input wire CPU_CLK,\n")
csr_decode_fp.printf("  input wire CPU_RESET,\n")
way.times{|index|
  csr_decode_fp.printf("  output wire [31: 0] CSR_DATA_OUT_%d,\n", index)
}
way.times{|index|
  csr_decode_fp.printf("  input wire [11: 0] CSR_ADDR_%d,\n", index)
}
csr_decode_fp.printf("  input wire CSR_WE,\n")
csr_decode_fp.printf("  input wire [31: 0] CSR_DATA_IN,\n")
csr_decode_fp.printf("  input wire [11: 0] CSR_WE_ADDR);\n\n")


$sysreg_table.each {|sysreg_info|
  csr_decode_fp.printf("  wire [31: 0] csr_%s_data;\n", sysreg_info[SYSREG::NAME]);
}

$sysreg_table.each {|sysreg_info|
  csr_decode_fp.printf("  wire csr_we_match_%-10s = (CSR_WE_ADDR == 12'h%03x);\n", sysreg_info[SYSREG::NAME], sysreg_info[SYSREG::ADDR])
  csr_decode_fp.printf("  wire csr_we_%-13s = CSR_WE & csr_we_match_%s;\n", sysreg_info[SYSREG::NAME], sysreg_info[SYSREG::NAME])
}

way.times{|index|
  $sysreg_table.each {|sysreg_info|
    csr_decode_fp.printf("  wire csr_match_%s_%d = (CSR_ADDR_%d == 12'h%03x);\n", sysreg_info[SYSREG::NAME], index, index, sysreg_info[SYSREG::ADDR])
  }
}

$sysreg_table.each {|sysreg_info|
  csr_decode_fp.printf("  CSR_%-10s u_csr_%-10s (.CPU_CLK (CPU_CLK), .CPU_RESET (CPU_RESET), .CSR_WE (csr_we_%-10s), .DATA_IN (CSR_DATA_IN), .DATA_OUT (csr_%s_data));\n",
                       sysreg_info[SYSREG::NAME], sysreg_info[SYSREG::NAME], sysreg_info[SYSREG::NAME], sysreg_info[SYSREG::NAME]);
}


way.times{|index|
  csr_decode_fp.printf("  assign CSR_DATA_OUT_%d = ", index)
  $sysreg_table.each {|sysreg_info|
    csr_decode_fp.printf("  {32{csr_match_%s_%d}} & csr_%s_data |\n",
                         sysreg_info[SYSREG::NAME], index, sysreg_info[SYSREG::NAME]);
  }

  # way.times {|way_index|
  #   csr_decode_fp.printf("  assign CSR_AVAIL_%d = ", way_index)
  #   $sysreg_table.each {|sysreg_info|
  #     csr_decode_fp.printf("  csr_match_%s_%d & csr_%s_avail |\n",
  #                          sysreg_info[SYSREG::NAME], way_index, sysreg_info[SYSREG::NAME]);
  #   }
  # }
  csr_decode_fp.printf("  32'h0;\n")
}

csr_decode_fp.printf("endmodule\n")

csr_decode_fp.close
