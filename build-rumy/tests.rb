#!/usr/bin/ruby

load "rumy-test.rb"

target   = "./swimmer_riscv"
opts     = "--init_pc 0x80000000 --debug --stop-host --max 50000"
bit_mode = 32

add_test :rv32ui_p_simple, "#{target} #{opts} --arch rv#{bit_mode}imafdc --binfile /home/masayuki/work/riscv/riscv-tools/riscv-tests/isa/rv32ui-p-simple"
