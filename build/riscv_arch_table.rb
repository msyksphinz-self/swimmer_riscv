#!/bin/ruby
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


require "../script/decode_table.rb"

$arch_name = "riscv"
$arch_inst_mod = ""

$arch_list_def = Hash.new()


$arch_list_def["R3"]          = 0
$arch_list_def["F2"]          = 1
$arch_list_def["R2"]          = 2
$arch_list_def["R1"]          = 3
$arch_list_def["F3"]          = 4
$arch_list_def["RD"]          = 5
$arch_list_def["OP"]          = 6
$arch_list_def["LD"]          = 7

$decode_field_list = Array[DecodeFieldInfo.new("R3", $arch_list_def["R3"], 31, 27),
                           DecodeFieldInfo.new("F2", $arch_list_def["F2"], 26, 25),
                           DecodeFieldInfo.new("R2", $arch_list_def["R2"], 24, 20),
                           DecodeFieldInfo.new("R1", $arch_list_def["R1"], 19, 15),
                           DecodeFieldInfo.new("F3", $arch_list_def["F3"], 14, 12),
                           DecodeFieldInfo.new("RD", $arch_list_def["RD"], 11,  7),
                           DecodeFieldInfo.new("OP", $arch_list_def["OP"],  6,  2),
                           DecodeFieldInfo.new("LD", $arch_list_def["LD"],  1,  0)]
