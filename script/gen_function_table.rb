#!/bin/ruby
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

##
##=== generate function table ===
##

def gen_function_table_header(arch_name)

  ## generate function of each instructions
  # generate header

  inst_func_fp = File.open("inst_" + arch_name + ".hpp", 'w')
  gen_header(inst_func_fp) # making header

  inst_func_fp.puts("#pragma once\n\n")

  inst_func_fp.puts("#include <stdint.h>")
  inst_func_fp.puts("#include \"" + $arch_name + "_pe_thread.hpp\"\n")
  inst_func_fp.puts("#include \"inst_list_" + $arch_name + ".hpp\"\n")
  inst_func_fp.puts("#include \"dec_utils_" + $arch_name + ".hpp\"\n\n")

  inst_func_fp.printf("class %sPeThread;\n\n", arch_name.capitalize)

  inst_func_fp.printf("class InstEnv {\n")

  inst_func_fp.printf("\nprivate:\n");
  inst_func_fp.printf("  %sPeThread *m_pe_thread;\n", arch_name.capitalize)
  inst_func_fp.printf("\npublic:\n");
  inst_func_fp.printf("  InstEnv (%sPeThread *env);\n\n", arch_name.capitalize)
  inst_func_fp.printf("  typedef void (InstEnv::*InstFunc) (InstWord_t inst_hex);\n");
  inst_func_fp.printf("  static const InstFunc m_inst_exec_func[%d];\n\n", $arch_ins_mod == "" ? $arch_table.size : $arch_table.size * 2);
  inst_func_fp.printf("  %s void %s_Inst_Exec (InstId_t index, InstWord_t inst_hex);\n\n", $arch_inst_mod, arch_name.upcase);

  $arch_table.each {|inst_info|
    inst_func_fp.printf("  %s void %s_INST_%s (InstWord_t inst_hex);\n", $arch_inst_mod, arch_name.upcase, gen_inst_id_code(inst_info[$arch_list_def["NAME"]]))
  }

  inst_func_fp.printf("};\n")
  inst_func_fp.close()


  ## generate initialization of instructions

  inst_func_init_fp = File.open("inst_" + arch_name + "_init.cpp", 'w')
  gen_header(inst_func_init_fp) # making header

  inst_func_init_fp.puts("#include <string>\n")
  inst_func_init_fp.printf("#include \"inst_%s.hpp\"\n", arch_name)
  inst_func_init_fp.puts("const InstEnv::InstFunc InstEnv::m_inst_exec_func[] = {\n");

  # traverse all of instruction table
  # to print all of Instruction Definition

  impl_idx = $arch_list_def["IMPL"]

  $arch_table.each_with_index {|inst_info, index|
    if $arch_inst_mod != "" then
      inst_op_type = "S"
      if not inst_info[impl_idx].empty? then
        inst_op_type = inst_info[impl_idx][0]
      end
      inst_func_init_fp.printf("  &InstEnv::%s_INST_%s<" + InstType("32bit", inst_op_type) + ">,\n", arch_name.upcase, gen_inst_id_code(inst_info[$arch_list_def["NAME"]]))
      inst_func_init_fp.printf("  &InstEnv::%s_INST_%s<" + InstType("64bit", inst_op_type) + "> ", arch_name.upcase, gen_inst_id_code(inst_info[$arch_list_def["NAME"]]))
    else
      inst_func_init_fp.printf("  &InstEnv::%s_INST_%s", arch_name.upcase, gen_inst_id_code(inst_info[$arch_list_def["NAME"]]))
    end
    if (index == $arch_table.size-1) then
      inst_func_init_fp.puts("\n  };");
    else
      inst_func_init_fp.puts(",\n");
    end
  }

  inst_func_init_fp.close()

end # gen_function_table_header


def TypeFromA(a)
  if    a == "RS"   then return 'Word_t'
  elsif a == "RU"   then return 'UWord_t'
  elsif a == "RH"   then return 'HWord_t'
  elsif a == "RUH"  then return 'UHWord_t'
  elsif a == "RB"   then return 'Byte_t'
  elsif a == "RUB"  then return 'UByte_t'
  elsif a == "XU"   then return 'UDWord_t'
  elsif a == "XS"   then return 'DWord_t'
  elsif a == "FH"   then return 'UWord_t'
  elsif a == "F"    then return 'UWord_t'
  elsif a == "D"    then return 'UDWord_t'
  elsif a == "V2D"  then return 'DWord_t'
  elsif a == "V2F"  then return 'UWord_t'
  elsif a == "V4H"  then return 'HWord_t'
  elsif a == "V4F"  then return 'UWord_t'
  elsif a == "V8H"  then return 'HWord_t'
  end
end


def RegFromA(a)
  if    a == "SV" then return a
  elsif a[0] == 'R' or a[0] == 'X' then return 'R'
  elsif a   == 'IS' then return 'I'
  elsif a   == 'IU' then return 'U'
  elsif a[0] == 'S' then return 'S'
  elsif a[0] == 'D' then return 'F'
  else                   return a
  end
end

def InstType(size, a)
  if size == "32bit" then
    if a[1] == 'U' then return "UWord_t"
    else                return "Word_t"
    end
  elsif size == "64bit" then
    if a[1] == 'U' then return "UDWord_t"
    else                return "DWord_t"
    end
  end
end


def gen_template_table()
  template_fp = File.open("inst_" + $arch_name + "_template_list.cpp", 'w')
  gen_header(template_fp)

  impl_idx = $arch_list_def["IMPL"]

  impl_idx = $arch_list_def["IMPL"]
  $arch_table.each {|inst_info|
    inst_op_type = "S"
    if not inst_info[impl_idx].empty? then
      inst_op_type = inst_info[impl_idx][0]
    end
    template_fp.printf("template void InstEnv::" + $arch_name.upcase + "_INST_" + gen_inst_id_code(inst_info[$arch_list_def["NAME"]]) + "<" + InstType("32bit", inst_op_type) + ">  (InstWord_t inst_hex);\n")
    template_fp.printf("template void InstEnv::" + $arch_name.upcase + "_INST_" + gen_inst_id_code(inst_info[$arch_list_def["NAME"]]) + "<" + InstType("64bit", inst_op_type) + "> (InstWord_t inst_hex);\n")
  }
  template_fp.close
end

def gen_inst_impl()

  fp_hash = Hash.new()

  impl_idx = $arch_list_def["IMPL"]

  $arch_table.each {|inst_info|
    if not inst_info[impl_idx].empty? then
      impl_code_list = inst_info[impl_idx]

      inst_category = inst_info[$arch_list_def["CATEGORY"]]
      type_category = ""

      category_hash_idx = type_category + inst_category

      if fp_hash[category_hash_idx] == nil then
        fp_hash[category_hash_idx] = File.open("inst_" + $arch_name + "_" + type_category + "_" + inst_category + ".cpp", 'w')
        gen_header(fp_hash[category_hash_idx]) # making header
        fp_hash[category_hash_idx].puts ("#include \"inst_" + $arch_name + ".hpp\"\n");
        fp_hash[category_hash_idx].puts ("#include \"dec_utils_" + $arch_name + ".hpp\"\n\n");
      end

      fp = fp_hash[category_hash_idx]

      fp.puts($arch_inst_mod)
      fp.puts("void InstEnv::" + $arch_name.upcase + "_INST_" + gen_inst_id_code(inst_info[$arch_list_def["NAME"]]) +
              "(InstWord_t inst_hex)")
      fp.puts("{")
      if impl_code_list[0][0] == 'S' then
        # System Register Control
        fp.printf("  m_pe_thread->Func_" + RegFromA(impl_code_list[0]) + "_" + RegFromA(impl_code_list[1]) + RegFromA(impl_code_list[2]))

        if inst_info[$arch_list_def["FUNC_SUFFIX"]] != "" then
          fp.printf("_" + inst_info[$arch_list_def["FUNC_SUFFIX"]])
        end

        # 1-Dest, 2-Operand, 1-Function
        str_lambda_declaration = "[]"
        if impl_code_list[3].include?("m_pe_thread->") then
          str_lambda_declaration = "[&]"
        end
        fp.printf("<%s> (inst_hex, %s(%s op1, %s op2, uint32_t round_mode) { %s; });",
                  TypeFromA(impl_code_list[1]),
                  str_lambda_declaration,
                  TypeFromA(impl_code_list[1]), TypeFromA(impl_code_list[1]),
                  impl_code_list[3])
      elsif impl_code_list.size == 3 then
        # 2-Reg Implementation
        fp.printf("  m_pe_thread->Func_" + RegFromA(impl_code_list[0]) + "_" + RegFromA(impl_code_list[1]))

        if inst_info[$arch_list_def["FUNC_SUFFIX"]] != "" then
          fp.printf("_" + inst_info[$arch_list_def["FUNC_SUFFIX"]])
        end

        str_lambda_declaration = "[]"
        if impl_code_list[2].include?("m_pe_thread->") then
          str_lambda_declaration = "[&]"
        end
        if impl_code_list[1] == "LD" then
          # Load Instruction
          fp.printf("<%s> (inst_hex, %s(%s op1, uint32_t round_mode) { %s; });",
                    str_lambda_declaration,
                    TypeFromA(impl_code_list[0]), TypeFromA(impl_code_list[0]),
                    impl_code_list[2])
        else
          fp.printf("<%s, %s> (inst_hex, %s(%s op1, uint32_t round_mode) { %s; });",
                    TypeFromA(impl_code_list[0]), TypeFromA(impl_code_list[1]),
                    str_lambda_declaration,
                    TypeFromA(impl_code_list[1]),
                    impl_code_list[2])
        end
      elsif impl_code_list.size == 5 then
        # 3-Reg Implementation
        fp.printf("  m_pe_thread->Func_" + RegFromA(impl_code_list[0]) + "_" + RegFromA(impl_code_list[1]) + RegFromA(impl_code_list[2]) + RegFromA(impl_code_list[3]))

        if inst_info[$arch_list_def["FUNC_SUFFIX"]] != "" then
          fp.printf("_" + inst_info[$arch_list_def["FUNC_SUFFIX"]])
        end
        fp.printf("<%s> (inst_hex, [](%s op1, %s op2, %s op3, UWord_t *fflags) { %s; });",
                  TypeFromA(impl_code_list[0]),
                  TypeFromA(impl_code_list[1]), TypeFromA(impl_code_list[2]), TypeFromA(impl_code_list[3]),
                  impl_code_list[4])
      else
        # Normal Operation
        fp.printf("  m_pe_thread->Func_" + RegFromA(impl_code_list[0]) + "_" + RegFromA(impl_code_list[1]) + RegFromA(impl_code_list[2]))

        if inst_info[$arch_list_def["FUNC_SUFFIX"]] != "" then
          fp.printf("_" + inst_info[$arch_list_def["FUNC_SUFFIX"]])
        end

        str_lambda_declaration = "[]"
        if impl_code_list[3].include?("m_pe_thread->") then
          str_lambda_declaration = "[&]"
        end
        fp.printf("<%s, %s> (inst_hex, %s(%s op1, %s op2, uint32_t round_mode, UWord_t *fflags) { %s; });",
                  TypeFromA(impl_code_list[0]), TypeFromA(impl_code_list[1]),
                  str_lambda_declaration,
                  TypeFromA(impl_code_list[0]), TypeFromA(impl_code_list[1]),
                  impl_code_list[3])
      end
      fp.puts("\n}\n\n\n")
    end
  }

  fp_hash.each_value{|fp| fp.close }

end # gen_inst_impl
