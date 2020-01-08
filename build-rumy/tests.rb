#!/usr/bin/ruby

load "rumy-test.rb"
load "msyksphinz_env.rb"

target   = "./swimmer_riscv"
opts     = "--init_pc 0x80000000 --debug --stop-host --max 50000"

isa_dir = ENV["RISCV"] + "/riscv64-unknown-elf/share/riscv-tests/isa"

test_pats = Array.new
dir = Dir.open(isa_dir)
dir.each {|file|
  if not file.include?(".dump") and
    not file == "." and
    not file == ".." then
    test_pats.push(file)
  end
}

test_pats.each{|pat|
  if pat.include?("rv64") then
    arch = "rv64imafdc"
  else
    arch = "rv32imafdc"
  end
  add_test pat, "#{target} #{opts} --arch #{arch} --binfile #{isa_dir}/#{pat}", "#{pat}.log"
}
