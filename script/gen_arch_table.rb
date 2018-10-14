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

if ARGV.size != 1 then
  print("Usage: gen_arch_table.rb <arch>\n")
  exit
end

require '../build/riscv_arch_table.rb'

require "json"

##=== displaying headers ===

def gen_header(fp)
  fp.puts("/*")
  fp.puts(" * Copyright (c) 2015, msyksphinz")
  fp.puts(" * All rights reserved.")
  fp.puts(" *")
  fp.puts(" *   Redistribution and use in source and binary forms, with or without")
  fp.puts(" *   modification, are permitted provided that the following conditions are met:")
  fp.puts(" *   * Redistributions of source code must retain the above copyright")
  fp.puts(" *   notice, this list of conditions and the following disclaimer.")
  fp.puts(" *   * Redistributions in binary form must reproduce the above copyright")
  fp.puts(" *   notice, this list of conditions and the following disclaimer in the")
  fp.puts(" *     documentation and/or other materials provided with the distribution.")
  fp.puts(" *   * Neither the name of the msyksphinz nor the")
  fp.puts(" *     names of its contributors may be used to endorse or promote products")
  fp.puts(" *     derived from this software without specific prior written permission.")
  fp.puts(" *")
  fp.puts(" * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS \"AS IS\" AND")
  fp.puts(" *   ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED")
  fp.puts(" * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE")
  fp.puts(" * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY")
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


def get_key_idx(key)
  if $arch_list_def.key?(key) then
    return $arch_list_def[key]
  else
    printf("ERROR: can't find key %s\n", key)
    return -1
  end
end

module DEC
  FUNC_STR  = get_key_idx("TAIL")
  CURR_DEC  = get_key_idx("TAIL") + 1
  INST_NAME = get_key_idx("TAIL") + 2
end

binary_list = Hash[]

File.open("../build/riscv_arch_table.json") do |file|
  $arch_table = JSON.load(file)
end

require "gen_inst_list.rb"
require "gen_decode_table.rb"
require "gen_function_table.rb"
require "gen_inst_mnemonic.rb"
require "gen_operand_table.rb"


## generate instruction define list
gen_inst_list()

## generate decode table
gen_decode_table()

## generate function table
gen_function_table_header($arch_name)
gen_inst_impl()

## generate instruction mnemonic table
gen_inst_mnemonic()

## generate operand table
gen_operand_table()

## Generate Instruction Category
gen_inst_category_table()

## Generate Instruction Operate DataLength Category
gen_datalength_func()

## Generate Insntruction Template
gen_template_table
