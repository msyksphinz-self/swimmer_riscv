#!/bin/ruby
# coding: utf-8

require "json"

require '../build/riscv_arch_table.rb'

File.open("../build/riscv_arch_table.json") do |file|
  $arch_table = JSON.load(file)
end

$decode_length_array = Array[]
$decode_field_list.each{|decode_field|
  msb_len = if decode_field.field_msb != 0 then Math.log10(decode_field.field_msb).to_i+1 else 1 end
  lsb_len = if decode_field.field_lsb != 0 then Math.log10(decode_field.field_lsb).to_i+1 else 1 end
  $decode_length_array.push( msb_len + lsb_len + 1)
}

$rst_fp = Hash[]

def gen_bit_table(fp, inst_info)

  def print_bit_line(fp, inst_field_info)
    fp.print("  +")
    inst_field_info.each_with_index {|inst_field, field_idx|
      bitfield_length = [$decode_length_array[field_idx], inst_field.size].max
      for i in 0..bitfield_length-1 do
        fp.print("-")
      end
      fp.print("+")
    }
    fp.print("\n")
  end

  bitfield_length = Array[]

  $decode_field_list.each_with_index{|decode_field, index|
    bitfield_length.push ([$decode_length_array[index], inst_info["field"][index].size].max)
  }

  fp.print(".. tabularcolumns:: |c|c|c|c|c|c|c|c|\n")
  fp.print(".. table::\n\n")

  print_bit_line(fp, inst_info["field"])

  fp.print("  ")
  $decode_field_list.each_with_index {|decode_field, field_idx|
    fp.printf("|%d-%d", decode_field.field_msb, decode_field.field_lsb)
    for i in 0..(bitfield_length[field_idx] - $decode_length_array[field_idx]-1) do
      fp.print(" ")
    end
  }
  fp.print("|\n")

  print_bit_line(fp, inst_info["field"])

  fp.print("  ")
  inst_info["field"].each_with_index{|inst_field, field_idx|
    bitfield_length = [$decode_length_array[field_idx], inst_field.size].max
    reg_name_match = inst_info["inst_ctrl"].map{ |item|
      item[0] == 'R' and
        item.split('_')[0] == $decode_field_list[field_idx].field_name
    }.reduce(:|)


    if reg_name_match then
      print_inst_field = $decode_field_list[field_idx].field_name.downcase
                           .gsub(/r1/, 'rs1')
                           .gsub(/r2/, 'rs2')
    else
      print_inst_field = inst_field
    end
    fp.printf("|%s", print_inst_field)
    for i in 0..(bitfield_length - print_inst_field.size-1) do
      fp.print(" ")
    end
  }
  fp.print("|\n")

  print_bit_line(fp, inst_info["field"])

  fp.print("\n")
  fp.print("\n")
  fp.print("\n")
end


def print_inst_format(fp, inst_name)
  fp.printf(":Format:\n")
  print_inst_name = inst_name.gsub(/[fr]\[11:7\]/, 'rd')
                      .gsub(/[fr]\[19:15\]/, 'rs1')
                      .gsub(/uj\[31:12\]/, 'offset')
                      .gsub(/[fr]\[24:20\]/, 'rs2')
                      .gsub(/u\[31:31\]\|u\[7:7\]\|u\[30:25\]\|u\[11:8\]/, 'offset')
                      .gsub(/h\[31:20\]/, 'offset')
                      .gsub(/h\[31:12\]/, 'imm')


  fp.printf("  | %s\n", print_inst_name)
  fp.printf("\n")
end


$arch_table.each_with_index {|inst_info, index|

  if $rst_fp[inst_info["category"]] == nil then
    $rst_fp[inst_info["category"]] = File.open(inst_info["category"] + ".rst", "w")
  end

  fp = $rst_fp[inst_info["category"]]

  mnemonic = inst_info["name"].split(" ")[0]
  fp.print(mnemonic + "\n")
  for i in 0..mnemonic.length do
    fp.print('-')
  end
  fp.print("\n\n")

  ## Bit-Field
  gen_bit_table(fp, inst_info)

  ## Format
  print_inst_format(fp, inst_info["name"])

  fp.printf(":Description:\n")
  fp.printf("  |\n")
  fp.printf(":Implementation:\n")
  if inst_info["impl"].size == 1 then
    fp.printf("  | None\n")
  else
    fp.printf("  | %s\n", inst_info["impl"][inst_info["impl"].size-1])
  end
  fp.printf("\n")
  fp.printf("\n")
  fp.printf("\n")
  fp.printf("\n")

}
