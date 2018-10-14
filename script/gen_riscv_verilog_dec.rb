#!/usr/bin/ruby
#
# Copyright (c) 2015, Masayuki Kimura
# All rights reserved.
#
#     Redistribution and use in source and binary forms, with or without
#     modification, are permitted provided that the following conditions are met:
#     * Redistributions of source code must retain the above copyright
#     notice, this list of conditions and the following disclaimer.
#     * Redistributions in binary form must reproduce the above copyright
#     notice, this list of conditions and the following disclaimer in the
#       documentation and/or other materials provided with the distribution.
#     * Neither the name of the Masayuki Kimura nor the
#       names of its contributors may be used to endorse or promote products
#       derived from this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
#     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
# DISCLAIMED. IN NO EVENT SHALL MASAYUKI KIMURA BE LIABLE FOR ANY
#     DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
#     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
#      LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
#     ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
#     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
#     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#

require '../build/riscv_arch_table.rb'

##=== displaying headers ===

def gen_header(fp)
  fp.puts("/*")
  fp.puts(" * Copyright (c) 2015, Masayuki Kimura")
  fp.puts(" * All rights reserved.")
  fp.puts(" *")
  fp.puts(" *     Redistribution and use in source and binary forms, with or without")
  fp.puts(" *     modification, are permitted provided that the following conditions are met:")
  fp.puts(" *     * Redistributions of source code must retain the above copyright")
  fp.puts(" *     notice, this list of conditions and the following disclaimer.")
  fp.puts(" *     * Redistributions in binary form must reproduce the above copyright")
  fp.puts(" *     notice, this list of conditions and the following disclaimer in the")
  fp.puts(" *       documentation and/or other materials provided with the distribution.")
  fp.puts(" *     * Neither the name of the Masayuki Kimura nor the")
  fp.puts(" *       names of its contributors may be used to endorse or promote products")
  fp.puts(" *       derived from this software without specific prior written permission.")
  fp.puts(" *")
  fp.puts(" * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS \"AS IS\" AND")
  fp.puts(" *     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED")
  fp.puts(" * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE")
  fp.puts(" * DISCLAIMED. IN NO EVENT SHALL MASAYUKI KIMURA BE LIABLE FOR ANY")
  fp.puts(" *     DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES")
  fp.puts(" *     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;")
  fp.puts(" *      LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND")
  fp.puts(" *     ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT")
  fp.puts(" *     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS")
  fp.puts(" *     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.")
  fp.puts(" */")
  fp.puts("")
  fp.puts("/* CAUTION! THIS SOURCE CODE IS GENERATED AUTOMATICALLY. DON'T MODIFY BY HAND. */")
  fp.puts("")
  fp.puts("")
end


module DEC
  FUNC_STR = $arch_list_def["TAIL"]
  CURR_DEC = $arch_list_def["TAIL"] + 1
  INST_NAME = $arch_list_def["TAIL"] + 2
end

func_str = "Dec_RISCV"
inst_name = Array[]
temp_arch_table = Array[]


##
## === Architecture Operand Type Declaration ===
##

operand_type_array = Array[]
operand_type_array[0] = ["h",  "operandTypeHex"]
operand_type_array[1] = ["d",  "operandTypeDec"]
operand_type_array[2] = ["sb", "operandTypeSB"]
operand_type_array[3] = ["uj", "operandTypeUJ"]


##
##=== making instruction define list ===
##

inst_define_fp = File.open('riscv_dec.vh', 'w')

gen_header(inst_define_fp) # making header

# generate instruction list
$arch_table.each_with_index {|inst_info, index|
  mnemonic = "INST_RISCV_%s"%([inst_info["name"].split(" ")[0].gsub(/\./,'_').upcase])
  $arch_table[index][DEC::INST_NAME] = mnemonic
  $arch_table[index][DEC::FUNC_STR] = "RISCV_DEC"
  mne_str = "`define %s\t\t%d"%([mnemonic, index])
  inst_define_fp.puts(mne_str)
}
inst_define_fp.printf("\n`define INST_MAX\t\t%d\n", $arch_table.size)


##
##=== making decoder ===
##

inst_decoder_fp = File.open('riscv_dec.v', 'w')

gen_header(inst_decoder_fp) # making header

mnemonic = \
"`default_nettype none

`include \"./riscv_dec.vh\"
`include \"./basic.vh\"

module riscv_dec (
    input  wire [31: 0] IC_INST,
    output wire [`INST_MAX-1: 0] IC_INST_DEC
);";
inst_decoder_fp.puts(mnemonic)

# generate instruction list
$arch_table.each_with_index {|inst_info, index|
  is_generate_and = false

  mne = "INST_RISCV_%s"%([inst_info["name"].split(" ")[0].gsub(/\./,'_').upcase])
  mnemonic = "    assign IC_INST_DEC[`" + mne + "] = "

  $decode_field_list.each{|decode_field|
    if not inst_info[decode_field.field_idx].include?("X") then
      if is_generate_and == true then
        mnemonic = mnemonic + " & ";
      end
      mnemonic = mnemonic + "(IC_INST[" + decode_field.field_msb.to_s + ":" + decode_field.field_lsb.to_s + "] == " + (decode_field.field_msb - decode_field.field_lsb + 1).to_s + "'b"
      mnemonic = mnemonic + inst_info[decode_field.field_idx] + ")"
      is_generate_and = true
    end
  }

  mnemonic = mnemonic + ";\n"
  inst_decoder_fp.puts(mnemonic)
}

mnemonic = "endmodule\n
`default_nettype wire\n"

inst_decoder_fp.puts(mnemonic)



##
##=== Making Controll signal ===
##

inst_ctrl_fp = File.open('riscv_ctrl.v', 'w')

gen_header(inst_ctrl_fp) # making header

mnemonic = \
"`default_nettype none

`include \"./riscv_dec.vh\"
`include \"./riscv_ctrl.vh\"
`include \"./riscv_core.vh\"
`include \"./basic.vh\"

module riscv_ctrl (
    input wire  [`INST_MAX-1: 0]    IC_INST_DEC,
    input wire  [31: 0]             IC_INST,
    output reg  [`INST_TYPE_W-1: 0] ID_INST_TYPE,
    output reg  [`INST_CTRL_W-1: 0] ID_INST_CTRL,
    output reg  [`REGADDR_W-1: 0]   ID_DST_ADDR,
    output reg  [`REGADDR_W-1: 0]   ID_R1_ADDR,
    output reg  [`REGADDR_W-1: 0]   ID_R2_ADDR,
    output reg  [`WORD_B]           ID_IMM,
    output reg  [`CSRADDR_W-1: 0]   ID_CSR_ADDR
);\n\n";

# generate instruction list
inst_dec_name = Array[]
inst_dec_type = Array[]
$arch_table.each_with_index {|inst_info, index|
  inst_string = inst_info["name"].gsub(/\w+\[\d+:\d+\]/, "@")
  inst_dec_name.push(inst_string)

  # count-up instruction type
  if not inst_dec_type.include?(inst_info["category"]) then
    inst_dec_type.push(inst_info["category"])
  end
}


##
##=== Making all of signals for each kinds of Instruction
##
ctrl_table = Hash.new()

inst_ctrl_h_fp = File.open("riscv_ctrl.vh", 'w')

## max bitwidth is saved
max_ctrl_bitwidth = 0

gen_header(inst_ctrl_h_fp) # making header
ctrl_remain_bitwidth = Hash.new()

inst_dec_type.each {|inst_type|

  ctrl_signals = Hash.new()

  $arch_table.each_with_index {|inst_info, index|
    if inst_type != inst_info["category"] then
      next
    end

    inst_ctrls = inst_info["inst_ctrl"];
    if inst_ctrls == nil then
      print "Not Found INST CTRL FIELD\n"
      print inst_info
    end

    inst_ctrls.each {|each_inst_ctrl|
      key = 0
      found = false
      head = each_inst_ctrl.split("_")[0]
      if ctrl_signals.key?(head) then
        ctrl_signals[head].each {|each_signal|
          each_signal_name = each_signal[0]
          each_signal_key  = each_signal[1]
          if each_signal_name.split("_")[0] == each_inst_ctrl.split("_")[0] then
            if each_signal_name != each_inst_ctrl then
              key = key + 1
            else
              found = true
              break
            end
          end
        }
        if found == false then
          new_pair = Array[]
          new_pair[0] = each_inst_ctrl
          new_pair[1] = key
          ctrl_signals[head].push(new_pair)
        end
      else
        new_pair = Array[]
        new_pair[0] = each_inst_ctrl
        new_pair[1] = key
        ctrl_signals[head] = Array[]
        ctrl_signals[head][0] = new_pair
      end
    }
  }


  printf("Ctrl_signals of inst_type = %s :\n", inst_type)
  ctrl_bit_lsb = 0
  ctrl_signals.each {|key, signals|
    if signals.size == 1 then
      ctrl_bitwidth = 1
    else
      ctrl_bitwidth = (Math::log(signals.size)/Math::log(2) + 1).to_i
    end
    inst_ctrl_h_fp.printf("// CTRL_%s_%s\n", inst_type, key)
    inst_ctrl_h_fp.printf("`define CTRL_%s_%s_B\t\t%d:%d\n", inst_type, key, ctrl_bitwidth + ctrl_bit_lsb - 1, ctrl_bit_lsb)
    ctrl_bit_lsb += ctrl_bitwidth

    printf("    %s[%d]\n", key, ctrl_bitwidth)
    signals.each_with_index {|pair, index|
      inst_ctrl_h_fp.printf("`define CTRL_%s_%s\t\t%d'b%0*b\n", inst_type, pair[0], ctrl_bitwidth, ctrl_bitwidth, index + 1)
      printf("        %s=%d\n", pair[0], pair[1])
    }
    if max_ctrl_bitwidth < ctrl_bit_lsb then
      max_ctrl_bitwidth = ctrl_bit_lsb
    end
    ctrl_remain_bitwidth[inst_type] = max_ctrl_bitwidth - ctrl_bit_lsb
  }
  printf("\n")

  # insert signals table into hash
  ctrl_table[inst_type] = ctrl_signals;
}

inst_ctrl_h_fp.printf("\n")
inst_ctrl_h_fp.printf("`define INST_CTRL_W\t\t%d\n", max_ctrl_bitwidth)
inst_ctrl_h_fp.printf("`define INST_CTRL_B\t\t%d: 0\n", max_ctrl_bitwidth-1)

if ctrl_table.size == 1 then
  ctrl_bitwidth = 1
else
  ctrl_bitwidth = (Math::log(ctrl_table.size)/Math::log(2) + 1).to_i
end

inst_ctrl_h_fp.printf("\n\n`define INST_TYPE_W\t\t%d\n", ctrl_bitwidth)
inst_ctrl_h_fp.printf("`define INST_TYPE_B\t\t%d: 0\n", ctrl_bitwidth-1)

ctrl_table.each_with_index{|(type, ctrl), index|
  inst_ctrl_h_fp.printf("`define INST_TYPE_%s\t\t%d'b%0*b\n", type, ctrl_bitwidth, ctrl_bitwidth, index)
}

inst_ctrl_h_fp.close()

##
## generate control signals
##


inst_ctrl_fp.printf(mnemonic, max_ctrl_bitwidth)

inst_ctrl_fp.printf("    always @ (*) begin\n")

inst_ctrl_fp.printf("        case (1'b1)\n")

$arch_table.each_with_index {|target_inst, index|
  target_signals = target_inst["inst_ctrl"];
  target_type    = target_inst["category"];

  mne = "`INST_RISCV_%s"%([target_inst["name"].split(" ")[0].gsub(/\./,'_').upcase])

  inst_ctrl_fp.printf("          IC_INST_DEC[%-15s] : begin  //%s\n", mne, target_type)
  inst_ctrl_fp.printf("              ID_INST_TYPE <= `INST_TYPE_%s;\n", target_type)

  # DST_ADDR
  if target_signals.include?("RD_R3") then
    inst_ctrl_fp.printf("              ID_DST_ADDR  <= IC_INST[`FORMAT_R3_B];\n")
  else
    inst_ctrl_fp.printf("              ID_DST_ADDR  <= `REGADDR_W'h0;\n")
  end

  # R1_ADDR
  if target_signals.include?("R1_R1") then
    inst_ctrl_fp.printf("              ID_R1_ADDR   <= IC_INST[`FORMAT_R1_B];\n")
  else
    inst_ctrl_fp.printf("              ID_R1_ADDR   <= `REGADDR_W'h0;\n")
  end

  # R2_ADDR
  if target_signals.include?("R2_R2") then
    inst_ctrl_fp.printf("              ID_R2_ADDR   <= IC_INST[`FORMAT_R2_B];\n")
  else
    inst_ctrl_fp.printf("              ID_R2_ADDR   <= `REGADDR_W'h0;\n")
  end

  # IMMEDIATE
  if target_signals.include?("IMM_I") then
    inst_ctrl_fp.printf("              ID_IMM       <= {{20{IC_INST[31]}}, IC_INST[31:20]};\n")
  elsif target_signals.include?("IMM_S") then
    inst_ctrl_fp.printf("              ID_IMM       <= {{20{IC_INST[31]}}, IC_INST[31:25], IC_INST[11: 7]};\n")
  elsif target_signals.include?("IMM_SB") then
    inst_ctrl_fp.printf("              ID_IMM       <= {{20{IC_INST[31]}}, IC_INST[7], IC_INST[30:25], IC_INST[11: 8], 1'b0};\n")
  elsif target_signals.include?("IMM_U") then
    inst_ctrl_fp.printf("              ID_IMM       <= {IC_INST[31:12], 12'h000};\n")
  elsif target_signals.include?("IMM_UJ") then
    inst_ctrl_fp.printf("              ID_IMM       <= {{12{IC_INST[31]}}, IC_INST[31], IC_INST[19:12], IC_INST[20], IC_INST[30:21], 1'b0};\n")
  else
    inst_ctrl_fp.printf("              ID_IMM       <= `WORD_W'hxxxx_xxxx;\n")
  end

  # R2_ADDR
  if target_signals.include? ("CSR_RW") then
    inst_ctrl_fp.printf("              ID_CSR_ADDR  <= IC_INST[31:20];\n")
  else
    inst_ctrl_fp.printf("              ID_CSR_ADDR  <= 12'h000;\n")
  end


  inst_ctrl_fp.printf("              ID_INST_CTRL <= {")

  # insert dummy signal
  if ctrl_remain_bitwidth[target_type] != 0 then
    inst_ctrl_fp.printf("%d'b%0*b, ", ctrl_remain_bitwidth[target_type], ctrl_remain_bitwidth[target_type], 0)
  end

  # traverse all of control signals in the inst-type
  ctrl_table[target_type].each_with_index.reverse_each {|(key, ctrl_list), index|
    ctrl_bitwidth = (Math::log(ctrl_list.size+1)/Math::log(2)).ceil

    # traverse all of control signals in the inst-type
    found = false
    ctrl_list.each_with_index {|ctrl_pair, ctrl_index|
      ctrl_name = ctrl_pair[0]
      if target_signals.include?(ctrl_name) then
        inst_ctrl_fp.printf("`CTRL_%s_%s", target_type, ctrl_name)
        found = true
      end
    }
    if found == false then
      inst_ctrl_fp.printf("%d'b%0*b", ctrl_bitwidth, ctrl_bitwidth, 0)
    end
    if index != 0 then
      inst_ctrl_fp.print(", ")
    end
  }
  inst_ctrl_fp.printf("};\n")
  inst_ctrl_fp.printf("          end\n")
}

inst_ctrl_fp.printf("          default : begin\n")
inst_ctrl_fp.printf("                    ID_INST_TYPE <= `INST_TYPE_W'h0;\n")
inst_ctrl_fp.printf("                    ID_INST_CTRL <= `INST_CTRL_W'h0;\n")
inst_ctrl_fp.printf("                    ID_DST_ADDR  <= `REGADDR_W'h0;\n")
inst_ctrl_fp.printf("                    ID_R1_ADDR   <= `REGADDR_W'h0;\n")
inst_ctrl_fp.printf("                    ID_R2_ADDR   <= `REGADDR_W'h0;\n")
inst_ctrl_fp.printf("                    ID_IMM       <= `WORD_W'hxxxx_xxxx;\n")
inst_ctrl_fp.printf("          end\n")
inst_ctrl_fp.printf("        endcase\n")
inst_ctrl_fp.printf("    end\n")
inst_ctrl_fp.printf("endmodule\n")
inst_ctrl_fp.close


##
##=== making instruction print ===
##

inst_print_fp = File.open('riscv_inst_print.vh', 'w')

gen_header(inst_print_fp) # making header

mnemonic = \
"task riscv_inst_print;
  input [31: 0] INST;
  begin
";

inst_print_fp.puts(mnemonic)

# generate instruction list
$arch_table.each_with_index {|inst_info, index|
  is_generate_and = false

  mne = "INST_RISCV_%s"%([inst_info["name"].split(" ")[0].gsub(/\./,'_').upcase])
  mnemonic = "    if ("
  if not inst_info["field"][$arch_list_def["R3"]].include?("X") then
    mnemonic = mnemonic + "(INST[31:27] == 6'b"
    mnemonic = mnemonic + inst_info["field"][$arch_list_def["R3"]] + ")"
    is_generate_and = true
  end

  if not inst_info["field"][$arch_list_def["F2"]].include?("X") then
    if is_generate_and == true then
      mnemonic = mnemonic + " & ";
    end
    mnemonic = mnemonic + "(INST[26:25] == 2'b"
    mnemonic = mnemonic + inst_info["field"][$arch_list_def["F2"]] + ")"
    is_generate_and = true
  end

  if not inst_info["field"][$arch_list_def["R2"]].include?("X") then
    if is_generate_and == true then
      mnemonic = mnemonic + " & ";
    end
    mnemonic = mnemonic + "(INST[24:20] == 5'b"
    mnemonic = mnemonic + inst_info["field"][$arch_list_def["R2"]] + ")"
    is_generate_and = true
  end

  if not inst_info["field"][$arch_list_def["R1"]].include?("X") then
    if is_generate_and == true then
      mnemonic = mnemonic + " & ";
    end
    mnemonic = mnemonic + "(INST[19:15] == 5'b"
    mnemonic = mnemonic + inst_info["field"][$arch_list_def["R1"]] + ")"
    is_generate_and = true
  end

  if not inst_info["field"][$arch_list_def["F3"]].include?("X") then
    if is_generate_and == true then
      mnemonic = mnemonic + " & ";
    end
    mnemonic = mnemonic + "(INST[14:12] == 3'b"
    mnemonic = mnemonic + inst_info["field"][$arch_list_def["F3"]] + ")"
    is_generate_and = true
  end

  if not inst_info["field"][$arch_list_def["RD"]].include?("X") then
    if is_generate_and == true then
      mnemonic = mnemonic + " & ";
    end
    mnemonic = mnemonic + "(INST[11: 7] == 6'b"
    mnemonic = mnemonic + inst_info["field"][$arch_list_def["RD"]] + ")"
    is_generate_and = true
  end

  if not inst_info["field"][$arch_list_def["OP"]].include?("X") then
    if is_generate_and == true then
      mnemonic = mnemonic + " & ";
    end
    mnemonic = mnemonic + "(INST[ 6: 0] == 7'b"
    mnemonic = mnemonic + inst_info["field"][$arch_list_def["OP"]] + ")"
    is_generate_and = true
  end

  mnemonic = mnemonic + ") begin\n"
  inst_print_fp.puts(mnemonic)

  # Print Instructions
  operands = inst_info["name"].split(" ")[1]
  opcode   = inst_info["name"].split(" ")[0]

  inst_print_fp.printf("      $fwrite (F_HANDLE, \"%-10s", opcode.upcase)
  total_bit = 0
  if operands != nil then
    operand_array = operands.split(/[,\(\)]/)
    operand_array.each_with_index {|operands_bar, index|
      operands = operands_bar.split("|")
      byte_length = 0
      type = 0
      operands.each {|operand|
        if operand =~ /(\w+)\[(\d+):(\d+)\]/ then
          type  = $1
          upper = $2.to_i
          lower = $3.to_i
          # byte_length += ((upper - lower + 1) / 4.0).ceil
          byte_length += (upper - lower + 1)
        end
      }
      byte_length = (byte_length / 4.0).ceil
      case (type)
      when 'd' then
        inst_print_fp.printf("r%%0%dd", byte_length)
        total_bit = total_bit + 1 + byte_length
      when 'h' then
        inst_print_fp.printf("0x%%0%dx", byte_length)
        total_bit = total_bit + 2 + byte_length
      when 'uj' then
        inst_print_fp.printf("0x%%0%dx", byte_length)
        total_bit = total_bit + 2 + byte_length
      when 'sb' then
        inst_print_fp.printf("0x%%0%dx", byte_length)
        total_bit = total_bit + 2 + byte_length
      end
      if index != operand_array.size - 1 then
        inst_print_fp.printf(",")
        total_bit = total_bit + 1
      end
    }
    # inst_print_fp.printf("Length=%d\n", total_bit)
  end

  (20-total_bit).times{
    inst_print_fp.printf(" ")
  }

  inst_print_fp.printf("\", ")

  if operands != nil then
    # Print Operands
    operand_array.each_with_index {|operands_bar, index|
      operands = operands_bar.split("|")
      byte_length = 0
      type = 0
      inst_print_fp.print("{")
      operands.each_with_index {|operand, operand_index|
        if operand =~ /(\w+)\[(\d+):(\d+)\]/ then
          upper = $2.to_i
          lower = $3.to_i
          byte_length = ((upper - lower + 1) / 4.0).ceil
          inst_print_fp.printf("INST[%d:%d]", upper, lower)
        end
        if operand_index != operands.size - 1 then
          inst_print_fp.printf(",")
        end
      }
      inst_print_fp.print("}")
      if index != operand_array.size - 1 then
        inst_print_fp.printf(",")
      end
    }
  end

  inst_print_fp.printf(");\n    end")
  inst_print_fp.puts()
}

inst_print_fp.puts("  end\n")
inst_print_fp.puts("endtask\n")

inst_print_fp.close()
