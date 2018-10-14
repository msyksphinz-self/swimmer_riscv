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

def gen_inst_mnemonic()

  inst_mnemonic_c_fp = File.open("inst_mnemonic_" + $arch_name + ".cpp", 'w')

  gen_header(inst_mnemonic_c_fp) # making header

  inst_mnemonic_c_fp.puts("#include <string>\n")
  inst_mnemonic_c_fp.puts("#include \"inst_list_" + $arch_name + ".hpp\"")
  inst_mnemonic_c_fp.puts("#include \"dec_utils_" + $arch_name + ".hpp\"\n\n\n")

  inst_mnemonic_c_fp.printf("const char *inst_strings[%d] = {\n", $arch_table.size + 1);  # Last+1 is for Sentinel
  $arch_table.each_with_index {|inst_info, index|
    inst_string = inst_info["name"].gsub(/\w+\[\d+:\d+\]/, "@")
    inst_string = inst_string.gsub(/@(\|@)+/, "@")
    inst_mnemonic_c_fp.printf("  \"%s\"", inst_string)
    inst_mnemonic_c_fp.puts(",\n")
  }
  inst_mnemonic_c_fp.puts("\"<Unknown Inst>\"\n")
  inst_mnemonic_c_fp.puts("};\n")

  inst_mnemonic_c_fp.close()

end  # gen_inst_mnemonic
