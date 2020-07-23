#!/bin/ruby
# coding: utf-8
#
# Copyright (c) 2015, msyksphinz
# All rights reserved.
#
#   Redistribution and use in source and binary forms, with or without
#   modification, are permitted provided that the following conditions are met:
#   * Redistributions of source code must retain the above copyright
#   notice, this list of conditions and the following disclaimer.
#   * Redistributions in binary form must reproduce the above copyright
#   notice, this list of conditions and the following disclaimer in the
#     documentation and/or other materials provided with the distribution.
#   * Neither the name of the msyksphinz nor the
#     names of its contributors may be used to endorse or promote products
#     derived from this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
#   ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
# DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY
#   DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
#   (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
#    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
#   ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
#   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
#   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#

def gen_operand_table()

  ##
  ## === Architecture Operand Type Declaration ===
  ##

  operand_type_array = Array[]
  operand_type_array.push(["r",  "operandTypeReg"])
  operand_type_array.push(["x",  "operandTypeXReg"])
  operand_type_array.push(["f",  "operandTypeFreg"])
  operand_type_array.push(["d",  "operandTypeDreg"])
  operand_type_array.push(["v",  "operandTypeVreg"])
  operand_type_array.push(["s",  "operandTypeSign"])
  operand_type_array.push(["b",  "operandTypeBit"])
  operand_type_array.push(["u",  "operandTypeUnSign"])
  operand_type_array.push(["uj", "operandTypeUnSignJ"])
  operand_type_array.push(["sb", "operandTypeSignBit"])
  operand_type_array.push(["s8", "operandTypeSelect8"])
  operand_type_array.push(["xy", "operandTypeXY"])
  operand_type_array.push(["cl", "operandTypeCacheLevel"])
  operand_type_array.push(["sl", "operandTypeSyncLevel"])
  operand_type_array.push(["h",  "operandTypeHex"])
  operand_type_array.push(["mr", "operandTypeRoundMode"])
  operand_type_array.push(["cr", "operandTypeCompactReg"])
  operand_type_array.push(["cf", "operandTypeCompactFReg"])
  operand_type_array.push(["vm", "operandTypeVmask"])

  inst_operand_h_fp = File.open("inst_operand_" + $arch_name + ".hpp", 'w');

  gen_header(inst_operand_h_fp)  # making header

  inst_operand_h_fp.puts("#pragma once")
  inst_operand_h_fp.puts("")
  inst_operand_h_fp.puts("")
  inst_operand_h_fp.puts("#include <stdint.h>")
  inst_operand_h_fp.puts("#include \"inst_list_" + $arch_name + ".hpp\"")
  inst_operand_h_fp.puts("#include \"dec_utils_" + $arch_name + ".hpp\"\n\n\n")

  inst_operand_h_fp.puts("enum class operandType {");
  operand_type_array.each_with_index {|operand_type, index|
  inst_operand_h_fp.printf("    %s = %d", operand_type[1], index)
  if index != operand_type_array.size - 1 then
    inst_operand_h_fp.puts(", ")
  end
  }
  inst_operand_h_fp.puts(" };")

  inst_operand_h_fp.puts("")

  inst_operand_h_fp.puts("#define MAX_OPERANDS 8\n\n")
  inst_operand_h_fp.puts("typedef struct {\n")
  inst_operand_h_fp.puts("  uint32_t size;\n")
  inst_operand_h_fp.puts("  operandType type_lst[MAX_OPERANDS];\n")
  inst_operand_h_fp.puts("  uint32_t msb_lst[MAX_OPERANDS];\n")
  inst_operand_h_fp.puts("  uint32_t lsb_lst[MAX_OPERANDS];\n")
  inst_operand_h_fp.puts("  bool     connect[MAX_OPERANDS];\n")
  inst_operand_h_fp.puts("} operandList;\n")

  inst_operand_h_fp.printf("void FormatOperand (void);\n\n")

  inst_operand_h_fp.close()


  inst_operand_c_fp = File.open("inst_operand_" + $arch_name + ".cpp", 'w');

  gen_header(inst_operand_c_fp)  # making header

  inst_operand_c_fp.puts("#include <stdint.h>")
  inst_operand_c_fp.puts("#include \"inst_list_" + $arch_name + ".hpp\"")
  inst_operand_c_fp.puts("#include \"inst_operand_" + $arch_name + ".hpp\"\n\n\n")

  inst_operand_c_fp.printf("operandList inst_operand[%d];\n\n\n", $arch_table.size)
  inst_operand_c_fp.printf("void FormatOperand (void)\n{\n");



  $arch_table.each_with_index {|inst_info, index|
    operand = inst_info["name"].scan(/\w+\[\d+:\d+\]\|*/)
    inst_name = gen_inst_id($arch_table[index]["name"])
    inst_operand_c_fp.printf("  // %s\n", inst_name)
    inst_operand_c_fp.printf("  inst_operand[static_cast<uint32_t>(%s)].size = %d;\n", inst_name, operand.size)
    operand.each_with_index {|bit_field, op_index|
      msb_lst  = bit_field.match(/(\w+)\[(\d+):(\d+)\]/)
      type_bit = msb_lst[1]
      msb_bit  = msb_lst[2]
      lsb_bit  = msb_lst[3]

      operand_type_str = operand_type_array.find{|operand_type| operand_type[0] == type_bit }
      if operand_type_str == nil then
        print "Error: Operand Type \"" + type_bit + "\" is not found.\n"
        exit
      else
        operand_type_str = operand_type_str[1]
      end

      inst_operand_c_fp.printf("  inst_operand[static_cast<uint32_t>(%s)].type_lst[%d] = operandType::%s;\n", inst_name, op_index, operand_type_str)
      inst_operand_c_fp.printf("  inst_operand[static_cast<uint32_t>(%s)].msb_lst[%d] = %d;\n", inst_name, op_index, msb_bit)
      inst_operand_c_fp.printf("  inst_operand[static_cast<uint32_t>(%s)].lsb_lst[%d] = %d;\n", inst_name, op_index, lsb_bit)

      if bit_field.match(/\w+\[\d+:\d+\]\|/) then
        inst_operand_c_fp.printf("  inst_operand[static_cast<uint32_t>(%s)].connect[%d] = 1;\n", inst_name, op_index)
      else
        inst_operand_c_fp.printf("  inst_operand[static_cast<uint32_t>(%s)].connect[%d] = 0;\n", inst_name, op_index)
      end
      inst_operand_c_fp.printf("  // %s\n", operand)
    }
  }

  inst_operand_c_fp.printf("}\n")

  inst_operand_c_fp.close()

end


def gen_inst_category_table()

  inst_category_h_fp = File.open("inst_category_" + $arch_name + ".hpp", 'w')
  gen_header(inst_category_h_fp)  # making header
  inst_category_h_fp.puts("#pragma once")

  inst_category_c_fp = File.open("inst_category_" + $arch_name + ".cpp", 'w')
  gen_header(inst_category_c_fp)  # making header
  inst_category_c_fp.puts("#include <stdint.h>")
  inst_category_c_fp.puts("#include <execinfo.h>")
  inst_category_c_fp.puts("#include \"inst_list_" + $arch_name + ".hpp\"")
  inst_category_c_fp.puts("#include \"inst_decoder_" + $arch_name + ".hpp\"")
  inst_category_c_fp.puts("#include \"inst_category_" + $arch_name + ".hpp\"\n\n")
  inst_category_c_fp.puts("void gen_backtrace ();\n\n")

  # Gather Category
  inst_category_list = Array[]
  $arch_table.each{|inst_info|
    inst_category = inst_info["category"]
    if not inst_category_list.include?(inst_category) then
      inst_category_list.push(inst_category)
    end
  }

  # Gather Suffix
  inst_suffix_list = Array[]
  $arch_table.each{|inst_info|
    inst_suffix = inst_info["func_suffix"] == "" ? "None" : inst_info["func_suffix"]
    if not inst_suffix_list.include?(inst_suffix) then
      inst_suffix_list.push(inst_suffix)
    end
  }

  ##
  ## Generate Header
  ##
  # Generate Category
  inst_category_h_fp.puts("enum class InstCategory {");
  inst_category_list.each_with_index {|inst_category, index|
    inst_category_h_fp.printf(" %s = %d", inst_category, index)
    if index != (inst_category_list.size-1) then
      inst_category_h_fp.puts(",")
    end
  }
  inst_category_h_fp.puts("};\n")

  # Generate Suffix
  inst_category_h_fp.puts("enum class InstSuffix {");
  inst_suffix_list.each_with_index {|inst_suffix, index|
    inst_category_h_fp.printf(" %s = %d", inst_suffix, index)
    if index != (inst_suffix_list.size-1) then
      inst_category_h_fp.puts(",")
    end
  }
  inst_category_h_fp.puts("};\n")

  inst_category_h_fp.close()

  ##
  ## Generate Controller
  ##
  gen_inst_category_func(inst_category_c_fp)
  gen_inst_suffix_func(inst_category_c_fp)
  gen_inst_length_func(inst_category_c_fp)
  gen_inst_template_hex(inst_category_c_fp)

  gen_backtrace(inst_category_c_fp);

  inst_category_c_fp.close
end

def gen_inst_category_func(fp)

  fp.puts("InstCategory " + $arch_name.capitalize + "Dec::GetInstCategory (InstId_t inst_id)")
  fp.puts("{")
  fp.puts("  switch (inst_id) {")

  $arch_table.each_with_index {|inst_info, index|
    mnemonic = "INST_ID_%s"%([inst_info["name"].split(" ")[0].gsub(/[\.:\[\]]/,'_').upcase])
    fp.puts("    case InstId_t::" + mnemonic + " : return InstCategory::" + inst_info["category"] + ";\n")
  }
  fp.puts("    default: fprintf(stderr, \"<Internal Error. Can't get Catgory of InstId=%d. Exit.>\\n\", static_cast<uint32_t>(inst_id)); gen_backtrace(); exit(EXIT_FAILURE);")
  fp.puts("  }")
  fp.puts("}")
  fp.puts("")

end


def gen_inst_suffix_func(fp)

  fp.puts("InstSuffix " + $arch_name.capitalize + "Dec::GetInstSuffix (InstId_t inst_id)")
  fp.puts("{")
  fp.puts("  switch (inst_id) {")

  $arch_table.each_with_index {|inst_info, index|
    mnemonic = "INST_ID_%s"%([inst_info["name"].split(" ")[0].gsub(/[\.:\[\]]/,'_').upcase])
    if inst_info["func_suffix"] == "" then
      fp.puts("    case InstId_t::" + mnemonic + " : return InstSuffix::None;\n")
    else
      fp.puts("    case InstId_t::" + mnemonic + " : return InstSuffix::" + inst_info["func_suffix"] + ";\n")
    end
  }
  fp.puts("    default: fprintf(stderr, \"<Internal Error. Can't get Suffix of InstId=%d. Exit.>\\n\", static_cast<uint32_t>(inst_id)); gen_backtrace(); exit(EXIT_FAILURE);")
  fp.puts("  }")
  fp.puts("}")
  fp.puts("")

end


def gen_inst_length_func(fp)

  fp.puts("uint32_t " + $arch_name.capitalize + "Dec::GetInstLength (InstId_t inst_id)")
  fp.puts("{")
  fp.puts("  switch (inst_id) {")

  $arch_table.each_with_index {|inst_info, index|
    mnemonic = "INST_ID_%s"%([inst_info["name"].split(" ")[0].gsub(/[\.:\[\]]/,'_').upcase])
    fp.puts("    case InstId_t::" + mnemonic + " : return " + inst_info["length"] + ";\n")
  }
  fp.puts("    default: fprintf(stderr, \"<Internal Error. Can't get Length of InstId=%d. Exit.>\\n\", static_cast<uint32_t>(inst_id)); gen_backtrace(); exit(EXIT_FAILURE);")
  fp.puts("  }")
  fp.puts("}")
  fp.puts("")

end


##======================================================
## Generate Instruction Hex Code w/o Operand/Immedeiate
##======================================================
def gen_inst_template_hex(fp)
  fp.puts("uint32_t " + $arch_name.capitalize + "Dec::GetInstHexTemplate (InstId_t inst_id)")
  fp.puts("{")
  fp.puts("  switch (inst_id) {")

  $arch_table.each_with_index {|inst_info, index|
    mnemonic = "INST_ID_%s"%([inst_info["name"].split(" ")[0].gsub(/[\.:\[\]]/,'_').upcase])
    fp.printf("    case InstId_t::" + mnemonic + " : return ")
    inst_hex = 0
    $decode_field_list.each{|decode_field|
      raw_decode_field = inst_info["field"][decode_field.field_idx].gsub('<>.*','')
      inst_hex = inst_hex | (raw_decode_field.gsub('X', '0').to_i(2) << decode_field.field_lsb)
    }
    fp.printf("0x%08x;\n", inst_hex)
  }
  fp.puts("    default: fprintf(stderr, \"<Internal Error. Can't get Length of InstId=%d. Exit.>\\n\", static_cast<uint32_t>(inst_id)); gen_backtrace(); exit(EXIT_FAILURE);")
  fp.puts("  }")
  fp.puts("}")
  fp.puts("")
end


##================================================================
## DataLength Function is Unit of Data Operation for Instructions
##================================================================

def gen_datalength_func()

  dlength_c_fp = File.open("dlength_" + $arch_name + ".cpp", 'w')
  gen_header(dlength_c_fp)  # making header
  dlength_c_fp.puts("#include <stdint.h>")
  dlength_c_fp.puts("#include \"inst_list_" + $arch_name + ".hpp\"")
  dlength_c_fp.puts("#include \"inst_decoder_" + $arch_name + ".hpp\"")

  dlength_c_fp.puts("uint32_t " + $arch_name.capitalize + "Dec::GetDataLength (InstId_t inst_id)")
  dlength_c_fp.puts("{")
  dlength_c_fp.puts("  switch (inst_id) {")

  $arch_table.each_with_index {|inst_info, index|
    mnemonic = "INST_ID_%s"%([inst_info["name"].split(" ")[0].gsub(/[\.:\[\]]/,'_').upcase])
    dlength_c_fp.puts("    case InstId_t::" + mnemonic + " : return " + inst_info["dlength"].to_s + ";\n")
  }
  dlength_c_fp.puts("    default: fprintf(stderr, \"<Internal Error. Can't get DLength of InstId=%d. Exit.>\\n\", static_cast<uint32_t>(inst_id)); exit(EXIT_FAILURE);")
  dlength_c_fp.puts("  }")
  dlength_c_fp.puts("}")
  dlength_c_fp.puts("")

  dlength_c_fp.close
end


def gen_backtrace(fp)
  fp.puts("void gen_backtrace () {\n")
  fp.puts("  int j, nptrs;\n")
  fp.puts("#define SIZE 100\n")
  fp.puts("  void *buffer[100];\n")
  fp.puts("  char **strings;\n")
  fp.puts("\n")
  fp.puts("  nptrs = backtrace(buffer, SIZE);\n")
  fp.puts("  printf(\"backtrace() returned %d addresses\\n\", nptrs);\n")
  fp.puts("\n")
  fp.puts("  /* backtrace_symbols_fd(buffer, nptrs, STDOUT_FILENO) を\n")
  fp.puts("     呼び出しても、以下と同様の出力が得られる。 */\n")
  fp.puts("\n")
  fp.puts("  strings = backtrace_symbols(buffer, nptrs);\n")
  fp.puts("  if (strings == NULL) {\n")
  fp.puts("    perror(\"backtrace_symbols\");\n")
  fp.puts("    exit(EXIT_FAILURE);\n")
  fp.puts("  }\n")
  fp.puts("\n")
  fp.puts("  for (j = 0; j < nptrs; j++)\n")
  fp.puts("    printf(\"%s\\n\", strings[j]);\n")
  fp.puts("\n")
  fp.puts("  free(strings);\n")
  fp.puts("}\n")
end
