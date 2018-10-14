#!/bin/ruby
# -*- coding: utf-8 -*-
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

def gen_decode_table()

  temp_arch_table = Array[]


  ##
  ##=== generate decode table ===
  ##

  inst_decoder_c_fp = File.open("inst_decoder_" + $arch_name + ".cpp", 'w')
  inst_decoder_h_fp = File.open("inst_decoder_" + $arch_name + ".hpp", 'w')

  gen_header(inst_decoder_c_fp) # making header
  gen_header(inst_decoder_h_fp) # making header

  inst_decoder_c_fp.puts("#include <stdint.h>")
  inst_decoder_c_fp.puts("#include \"inst_list_" + $arch_name + ".hpp\"")
  inst_decoder_c_fp.puts("#include \"inst_decoder_" + $arch_name + ".hpp\"")
  inst_decoder_c_fp.puts("#include \"dec_utils_" + $arch_name + ".hpp\"\n\n\n")
  inst_decoder_c_fp.puts("#include \"extra_dec_utils_" + $arch_name + ".cpp\"\n\n\n")

  inst_decoder_h_fp.puts("#pragma once")
  inst_decoder_h_fp.puts("#include <stdint.h>")
  inst_decoder_h_fp.puts("#include \"inst_list_" + $arch_name + ".hpp\"")
  inst_decoder_h_fp.puts("#include \"inst_category_" + $arch_name + ".hpp\"")
  inst_decoder_h_fp.puts("#include \"dec_utils_" + $arch_name + ".hpp\"")
  inst_decoder_h_fp.puts("#include \"" + $arch_name + "_pe_thread.hpp\"\n\n\n")
  inst_decoder_h_fp.puts("class " + $arch_name.capitalize + "Dec {\n");
  inst_decoder_h_fp.puts("public:\n" + "static InstCategory GetInstCategory (InstId_t inst_id);\n");
  inst_decoder_h_fp.puts("public:\n" + "static InstSuffix GetInstSuffix (InstId_t inst_id);\n");
  inst_decoder_h_fp.puts("public:\n" + "static uint32_t GetInstLength (InstId_t inst_id);\n");
  inst_decoder_h_fp.puts("public:\n" + "static uint32_t GetInstHexTemplate (InstId_t inst_id);\n\n");
  inst_decoder_h_fp.puts("public:\n" + "static uint32_t GetDataLength (InstId_t inst_id);\n\n");

  $arch_table.each {|inst_info| temp_arch_table.push(inst_info) }

  # 基本的な方針について考える。
  # 6つのフィールドで、どのフィールドを使うと、デコードテーブルを明確に分割できるかを考える。
  # 一発でデコードできることが出来ればそれで問題なし。なるべく最後までXXXXXが含まれるように探していく。
  # グループが最後の1つになれば終了。その時点でデコードテーブルが決定される。

  decode_wfs($decode_field_list, $arch_table, "", inst_decoder_c_fp, inst_decoder_h_fp)

  inst_decoder_h_fp.puts("#include \"extra_dec_utils_" + $arch_name + ".hpp\"\n\n\n")
  inst_decoder_h_fp.puts("};");

  inst_decoder_c_fp.close
  inst_decoder_h_fp.close

end


def mask_bitfield (bit, mask)
  mask_masked = mask.gsub('<>.*', '').gsub('0', '1').gsub('X', '0').to_i(2)

  if mask.include?("<>") then
    if not bit.include?('X') then
      return true
    else
      return mask.split("<>")[1].to_i(10) != bit.to_i(2)
    end
  else
    return ((bit.gsub('X', '0').to_i(2) & mask_masked) == (mask.gsub('X', '0').to_i(2) & mask_masked))
  end
end


def decode_wfs (decode_field_list, arch_table, prefix, c_fp, h_fp)
  if decode_field_list.empty? == true then
    return
  end

  # 'X' を含むフィールドが最も少ないフィールドを探す。
  # 'X'を含むフィールドが最小のフィールドをキーとして、次のキーを作る。
  smallest_decode_field = decode_field_list.min {|dec_x, dec_y|
    count_x_field(arch_table, dec_x.field_idx) <=> count_x_field(arch_table, dec_y.field_idx)
  }
  count_x_smallest = count_x_field(arch_table, smallest_decode_field.field_idx)

  # それぞれのフィールドにリストを分解し、再度デコードテーブル探索を行う。
  arch_arrays = Array[]
  arch_table.each {|inst_info|
    # 一度でコード可能な領域を展開して、配列にする
    extended_result = Array.new
    if inst_info["field"][smallest_decode_field.field_idx].include?('X') then
      target_inst_info_field = inst_info["field"][smallest_decode_field.field_idx].gsub(/\<\>.+/,'')
      extend_bit_array = [0,1].to_a.repeated_permutation(target_inst_info_field.count('X')).to_a.map{|array| array.join}
      extend_inst_info = Array.new(extend_bit_array.size).fill(target_inst_info_field)
      # c_fp.puts("concatinating " + extend_inst_info + " and " + extend_bit_array)
      # extend_inst_info.zip(extend_bit_array){|a, b| extended_result.push(a.gsub(/[X]+/, b))}
      extend_inst_info.zip(extend_bit_array){|a, b|
        join_bit = ""
        b_bit_idx = 0
        a.each_char{|a_bit|
          if a_bit == 'X' then
            join_bit << b[b_bit_idx]
            b_bit_idx = b_bit_idx + 1
          else
            join_bit << a_bit
          end
        }
        extended_result.push(join_bit)
      }
      # c_fp.printf("// Permutation is ")
      # c_fp.print extended_result
      # c_fp.printf("\n")
      # <>が入っていると例外があるので、それを除去する
      if inst_info["field"][smallest_decode_field.field_idx].include?("<>") then
        extended_result.select! {|item| item.to_i(2) != inst_info["field"][smallest_decode_field.field_idx].split("<>")[1].to_i(10)}
      end
    else
      extended_result.push(inst_info["field"][smallest_decode_field.field_idx])
    end
    extended_result.each{|item|
      arch = arch_arrays.find {|arch| arch.field_name.to_i(2) == item.to_i(2)}
      if arch != nil then
        arch.info_arrays.push(inst_info)
      else
        arch_arrays.push(FieldArchInfo.new(item, inst_info))
      end
    }
  }

  # arch_arrays.each {|arch|
  #   c_fp.printf("// ")
  #   c_fp.printf("%s,", arch.field_name)
  #   arch.info_arrays.each{|info|
  #     c_fp.printf("%s,", gen_inst_id(info[0]))
  #   }
  #   c_fp.printf("\n")
  # }

  # デコード結果の命令が全て同じグループは、1つのグループにまとめる。

  # new_arch_arrays = arch_arrays.uniq{|item| item.info_arrays}
  new_arch_arrays = arch_arrays.clone
  uniqued_arch_arrays = Array[]
  arch_arrays.each {|item|
    match_uarch = uniqued_arch_arrays.find {|uitem| item.info_arrays == uitem.info_arrays }
    if match_uarch != nil then
      match_uarch.push_field_name(item.field_name)
    else
      uniqued_arch_arrays.push(MultiFieldArchInfo.new(item.field_name, item.info_arrays))
    end
  }

  c_fp.printf("InstId_t %sDec::DecodeInst%s (InstWord_t inst) {\n", $arch_name.capitalize, prefix);

  if prefix.empty? then
    h_fp.puts("public:")
  end
  h_fp.printf("  InstId_t DecodeInst%s (InstWord_t inst);\n" , prefix);
  if prefix.empty? then
    h_fp.puts("private:")
  end

  c_fp.printf("  InstWord_t field_%s = Extract%sField (inst);\n", smallest_decode_field.field_name, smallest_decode_field.field_name)

  c_fp.printf("  switch (field_%s) {\n", smallest_decode_field.field_name);
  uniqued_arch_arrays.each{|arch|
    arch.field_name.each{|field_name|
      c_fp.printf("    case 0x%02x : \n", field_name.to_i(2))
    }
    if arch.info_arrays.size() != 1 then
      c_fp.printf("    // Remaining Instruction is %d\n", arch.info_arrays().size())
      arch.info_arrays().each{|inst_info|
        c_fp.printf("    // %s\n", inst_info["name"])
      }
      c_fp.printf("      return DecodeInst%s_%s_%s (inst); break;\n",
                  prefix, smallest_decode_field.field_name, arch.field_name[0])
    else
      c_fp.printf("      return %s;\n", gen_inst_id(arch.info_arrays[0]["name"]))
    end
  }
  c_fp.printf("    default : return InstId_t::INST_ID_SENTINEL_MAX;\n");
  c_fp.printf("  }\n")

  c_fp.printf("  return InstId_t::INST_ID_SENTINEL_MAX;\n");
  c_fp.printf("}\n")

  c_fp.flush


  # フィールド分類して、要素数が1のものは命令を1つに特定できる。
  # このような命令は、ここでデコードを終了する。
  uniqued_arch_arrays.delete_if{|arch| arch.info_arrays().size() == 1 }

  copied_decode_field_list = decode_field_list.clone
  copied_decode_field_list.delete(smallest_decode_field)

  uniqued_arch_arrays.each{|arch|
    if arch.info_arrays().size() != 1 then
      new_func_str = sprintf("%s_%s_%s", prefix ,smallest_decode_field.field_name, arch.field_name[0].gsub("\<\>",""))
      # c_fp.printf("    // New Decode Function is %s %d\n", new_func_str, copied_decode_field_list.size())
      decode_wfs(copied_decode_field_list, arch.info_arrays, new_func_str, c_fp, h_fp)
    end
  }

end


#
# Count number of field that includes "X"
#
def count_x_field (arch_table_list, field_idx)
  return arch_table_list.count {|arch_table| arch_table["field"][field_idx].include?('X') }
end
