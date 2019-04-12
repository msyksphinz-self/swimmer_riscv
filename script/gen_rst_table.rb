#!/bin/ruby
# coding: utf-8

require "json"

File.open("../build/riscv_arch_table.json") do |file|
  $arch_table = JSON.load(file)
end

$arch_table.each_with_index {|inst_info, index|
  mnemonic = inst_info["name"].split(" ")[0]
  puts(mnemonic + "\n")
  for i in 0..mnemonic.length do
    print('-')
  end
  puts("\n\n")

  print(".. tabularcolumns:: |c|c|c|c|c|c|c|c|\n")
  print(".. table::\n\n")
  print("  +-----+-----+-----+-----+-----+-----+-----+---+\n")
  print("  |31-27|26-25|24-20|19-15|14-12|11-7 |6-2  |1-0|\n")
  print("  +=====+=====+=====+=====+=====+=====+=====+===+\n")
  print("  ")
  printf("|%-5s", inst_info["field"][0])
  printf("|%-5s", inst_info["field"][1])
  printf("|%-5s", inst_info["field"][2])
  printf("|%-5s", inst_info["field"][3])
  printf("|%-5s", inst_info["field"][4])
  printf("|%-5s", inst_info["field"][5])
  printf("|%-5s", inst_info["field"][6])
  printf("|%-3s", inst_info["field"][7])
  puts("|\n")
  print("  +-----+-----+-----+-----+-----+-----+-----+---+\n")
  puts("\n\n")

  printf(":Format:\n")
  printf("  | %s\n", inst_info["name"])
  printf("\n")
  printf(":Description:\n")
  printf("\n")
  printf(":Implementation:\n")
  printf("  | rD <- {imm[31:12], 12'h000}\n")
  printf("\n")
  printf("\n")
  printf("\n")
  printf("\n")

}
