#!/usr/bin/ruby
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


require '../build/riscv_spr_table.rb'
arch_name = 'Riscv'
sysreg_type = 'Xlen_t'

sysreg_rw_c_fp = File.open(sprintf("%s_sysreg_rw.cpp", arch_name.downcase), 'w')

gen_header(sysreg_rw_c_fp) # making header

sysreg_rw_c_fp.puts("#include <stdint.h>")

##
##=== generate Read CSR Function ===
##

# sysreg_rw_c_fp.printf("#include <stdio.h>\n")
sysreg_rw_c_fp.printf("#include \"basic.hpp\"\n")
sysreg_rw_c_fp.printf("#include \"%s_pe_thread.hpp\"\n", ARGV[0])
sysreg_rw_c_fp.printf("#include \"%s_sysreg_impl.hpp\"\n\n", arch_name.downcase)
sysreg_rw_c_fp.printf("\n\n")
if sysreg_type == 'Xlen_t' then
  sysreg_rw_c_fp.printf("template <typename Xlen_t>");
end
sysreg_rw_c_fp.printf("%s CsrEnv::%s_Read_CSR (Addr_t addr, %s *data, PrivMode mode)\n{\n", sysreg_type, arch_name, sysreg_type)
sysreg_rw_c_fp.printf("  switch (addr) {\n")

$sysreg_table.each {|sysreg_info|
  if sysreg_type == 'Xlen_t' then
    sysreg_rw_c_fp.printf("    case SYSREG_ADDR_%s : return Read_%s<%s> (data, mode);\n",
                          sysreg_info[SYSREG::NAME].upcase,
                          sysreg_info[SYSREG::NAME].upcase,
                          sysreg_type)
  else
    sysreg_rw_c_fp.printf("    case SYSREG_ADDR_%s : return Read_%s (data, mode);\n",
                          sysreg_info[SYSREG::NAME].upcase,
                          sysreg_info[SYSREG::NAME].upcase)
  end
}

sysreg_rw_c_fp.printf("    default : Error_CSR_Read (addr); *data = 0x0;\n")
sysreg_rw_c_fp.printf("  }\n")
sysreg_rw_c_fp.printf("  return -1;\n")
sysreg_rw_c_fp.printf("}\n")


##
##=== generate Write CSR Function
##


sysreg_rw_c_fp.printf("\n\n")
if sysreg_type == 'Xlen_t' then
  sysreg_rw_c_fp.printf("template <typename Xlen_t>")
end
sysreg_rw_c_fp.printf("%s CsrEnv::%s_Write_CSR (Addr_t addr, %s data, PrivMode mode)\n{\n", sysreg_type, arch_name, sysreg_type)
sysreg_rw_c_fp.printf("  switch (addr) {\n")

$sysreg_table.each {|sysreg_info|
  if sysreg_type == 'Xlen_t' then
    sysreg_rw_c_fp.printf("    case SYSREG_ADDR_%s : return Write_%s<%s> (data, mode);\n",
                          sysreg_info[SYSREG::NAME].upcase,
                          sysreg_info[SYSREG::NAME].upcase,
                          sysreg_type)
  else
    sysreg_rw_c_fp.printf("    case SYSREG_ADDR_%s : return Write_%s (data, mode);\n",
                          sysreg_info[SYSREG::NAME].upcase,
                          sysreg_info[SYSREG::NAME].upcase)
  end
}

sysreg_rw_c_fp.printf("    default : Error_CSR_Write (addr); break;\n")
sysreg_rw_c_fp.printf("  }\n")
sysreg_rw_c_fp.printf("  return -1;\n")
sysreg_rw_c_fp.printf("}\n")

sysreg_rw_c_fp.puts("\n\nvoid CsrEnv::Error_CSR_Read (Addr_t addr)\n{\n")
sysreg_rw_c_fp.puts("  m_pe_thread->DebugPrint (\"<Error: CSR Read Address \%03x is invalid.>\\n\", addr);\n}")

sysreg_rw_c_fp.puts("\n\nvoid CsrEnv::Error_CSR_Write (Addr_t addr)\n{\n")
sysreg_rw_c_fp.puts("  m_pe_thread->DebugPrint (\"<Error: CSR Write Address \%03x is invalid.>\\n\", addr);\n}")

if sysreg_type == 'Xlen_t' then
  ["Word_t", "DWord_t", "UWord_t", "UDWord_t"].each {|type|
    sysreg_rw_c_fp.printf("template " \
                          "%s CsrEnv::%s_Read_CSR  (Addr_t addr, %s *data, PrivMode mode);\n",
                          type, arch_name, type)
    sysreg_rw_c_fp.printf("template " \
                          "%s CsrEnv::%s_Write_CSR (Addr_t addr, %s data,  PrivMode mode);\n",
                          type, arch_name, type)
  }
end

sysreg_rw_c_fp.close()


##
##=== generate CSR system register type implementation
##

sysreg_impl_h_fp = File.open(sprintf('%s_sysreg_impl.hpp', arch_name.downcase), 'w');
sysreg_bit_def_fp = File.open(sprintf('%s_sysreg_bitdef.hpp', arch_name.downcase), 'w');

gen_header(sysreg_impl_h_fp)  # making header
gen_header(sysreg_bit_def_fp) # making header

sysreg_impl_h_fp.printf("#pragma once\n\n\n")
sysreg_impl_h_fp.printf("#include <string>\n")
sysreg_impl_h_fp.printf("#include <stdint.h>\n")

sysreg_impl_h_fp.printf("enum class PrivMode;\n")
sysreg_impl_h_fp.printf("class %sPeThread;\n", arch_name.capitalize)
sysreg_impl_h_fp.printf("class CsrEnv {\n")
sysreg_impl_h_fp.printf(" private:\n")
sysreg_impl_h_fp.printf("  %sPeThread *m_pe_thread;\n", arch_name.capitalize)

sysreg_bit_def_fp.printf("#pragma once\n\n\n")

$sysreg_table.each {|sysreg_info|
  sysreg_bitfields = sysreg_info[SYSREG::BITFIELD];

  if sysreg_bitfields[0][SYSREG_BITFIELD::MAX] - sysreg_bitfields[0][SYSREG_BITFIELD::MIN] + 1 != 64 then

    sysreg_impl_h_fp.printf("\n  union {\n")
    sysreg_impl_h_fp.printf("    struct {\n")

    previous_max = 64
    dummy_index = 0

    sysreg_str_array = Array[]

    sysreg_bitfields.each_with_index {|sysreg_bitfield, index|
      # dummy bitfield insertion
      if previous_max != (sysreg_bitfield[SYSREG_BITFIELD::MAX] + 1) then
        sysreg_str = "      uint64_t dummy_%d : %d;\n"%[dummy_index, previous_max - sysreg_bitfield[SYSREG_BITFIELD::MAX] - 1]
        sysreg_str_array.push(sysreg_str);
        dummy_index = dummy_index + 1
      end

      bitfield_size = sysreg_bitfield[SYSREG_BITFIELD::MAX] - sysreg_bitfield[SYSREG_BITFIELD::MIN] + 1
      sysreg_str = "      uint64_t %s : %d;\n"%[sysreg_bitfield[SYSREG_BITFIELD::NAME], bitfield_size]
      sysreg_str_array.push(sysreg_str)

      previous_max = sysreg_bitfield[SYSREG_BITFIELD::MIN];

      # Print CSR bit poisition define
      sysreg_bit_def_fp.printf("#define SYSREG_%s_%s_MSB (%d)\n",
                               sysreg_info[SYSREG::NAME].upcase,
                               sysreg_bitfield[SYSREG_BITFIELD::NAME].upcase,
                               sysreg_bitfield[SYSREG_BITFIELD::MAX]);
      sysreg_bit_def_fp.printf("#define SYSREG_%s_%s_LSB (%d)\n",
                               sysreg_info[SYSREG::NAME].upcase,
                               sysreg_bitfield[SYSREG_BITFIELD::NAME].upcase,
                               sysreg_bitfield[SYSREG_BITFIELD::MIN]);
    }
    # dummy bitfield insertion
    if previous_max != 0 then
      sysreg_str = "      uint64_t dummy_%d : %d;\n"%[dummy_index, previous_max]
      sysreg_str_array.push(sysreg_str)
    end

    while not sysreg_str_array.empty?
      sysreg_impl_h_fp.printf("%s", sysreg_str_array.pop)
    end

    sysreg_impl_h_fp.printf("    } bit_%s;\n", sysreg_info[SYSREG::NAME]);
    sysreg_impl_h_fp.printf("    uint64_t %s;\n", sysreg_info[SYSREG::NAME])

  else
    sysreg_impl_h_fp.printf("\n\n  struct {\n")
    sysreg_impl_h_fp.printf("    uint64_t %s;\n", sysreg_bitfields[0][SYSREG_BITFIELD::NAME])
  end

  sysreg_impl_h_fp.printf("  } %s;\n", sysreg_info[SYSREG::NAME])
}

$sysreg_table.each {|sysreg_info|
  if sysreg_type == 'Xlen_t' then
    sysreg_impl_h_fp.printf("  template <typename %s>", sysreg_type)
  end
  sysreg_impl_h_fp.printf(" %s Read_%s (%s *data, PrivMode mode);\n",
                          sysreg_type, sysreg_info[SYSREG::NAME].upcase, sysreg_type)
}

$sysreg_table.each {|sysreg_info|
  if sysreg_type == 'Xlen_t' then
    sysreg_impl_h_fp.printf("  template <typename %s>", sysreg_type)
  end
  sysreg_impl_h_fp.printf(" %s Write_%s (%s data, PrivMode mode);\n",
                          sysreg_type, sysreg_info[SYSREG::NAME].upcase, sysreg_type)
}

sysreg_impl_h_fp.printf("public:\n\n")

sysreg_impl_h_fp.printf("  CsrEnv (%sPeThread *env);\n", arch_name.capitalize)
sysreg_impl_h_fp.printf("  std::string GetCSRName (Addr_t addr);\n")
if sysreg_type == 'Xlen_t' then
  sysreg_impl_h_fp.printf("  template <typename %s> ", sysreg_type)
end
sysreg_impl_h_fp.printf("%s %s_Read_CSR  (Addr_t addr, %s *data, PrivMode mode);\n",
                        sysreg_type, arch_name, sysreg_type)
if sysreg_type == 'Xlen_t' then
sysreg_impl_h_fp.printf("  template <typename %s> ", sysreg_type)
end
sysreg_impl_h_fp.printf("%s %s_Write_CSR (Addr_t addr, %s data,  PrivMode mode);\n",
                        sysreg_type, arch_name, sysreg_type)

# generate Read_Write Error methods for CSR

sysreg_impl_h_fp.printf("  void Error_CSR_Read (Addr_t addr);\n")
sysreg_impl_h_fp.printf("  void Error_CSR_Write (Addr_t addr);\n")

sysreg_impl_h_fp.printf("};\n")

# generate SYMBOL list
$sysreg_table.each_with_index {|sysreg_info, inde|
  sysreg_bitfields = sysreg_info[SYSREG::BITFIELD];

  sysreg_impl_h_fp.printf("#define SYSREG_ADDR_%s 0x%03x\n", sysreg_info[SYSREG::NAME].upcase, sysreg_info[SYSREG::ADDR])
}

sysreg_impl_h_fp.close()
sysreg_bit_def_fp.close()

### generate string list
sysreg_str_c_fp = File.open(sprintf('%s_sysreg_str.cpp', arch_name.downcase), 'w');

gen_header(sysreg_str_c_fp) # making header

sysreg_str_c_fp.printf("#include <string>\n")
sysreg_str_c_fp.printf("#include \"basic.hpp\"\n\n")
sysreg_str_c_fp.printf("#include \"%s_sysreg_impl.hpp\"\n\n", arch_name.downcase)

sysreg_str_c_fp.printf("std::string csr_name[%d] = {\n", $sysreg_table.length)
$sysreg_table.each_with_index {|sysreg_info, index|
  sysreg_bitfields = sysreg_info[SYSREG::BITFIELD]

  sysreg_str_c_fp.printf("  \"%s\"", sysreg_info[SYSREG::NAME])
  if index != $sysreg_table.length-1 then
  sysreg_str_c_fp.printf(",")
  end
  sysreg_str_c_fp.printf("\n")
}
sysreg_str_c_fp.printf("};\n")

sysreg_str_c_fp.printf("std::string CsrEnv::GetCSRName (Addr_t addr)\n{\n")
sysreg_str_c_fp.printf("  switch (addr) {\n")

$sysreg_table.each_with_index {|sysreg_info, index|
  sysreg_str_c_fp.printf("    case SYSREG_ADDR_%s : return csr_name[%d];\n", sysreg_info[SYSREG::NAME].upcase, index)
}

sysreg_str_c_fp.printf("    default : return \"INVLD_CSR\";\n")
sysreg_str_c_fp.printf("  }\n")
sysreg_str_c_fp.printf("  return NULL;\n")
sysreg_str_c_fp.printf("}\n")

sysreg_str_c_fp.close()


### generate string list
sysreg_str_h_fp = File.open(sprintf('%s_sysreg_str.hpp', arch_name.downcase), 'w');

gen_header(sysreg_str_h_fp) # making header

sysreg_str_h_fp.printf("#pragma once\n\n")

sysreg_str_h_fp.printf("#include \"basic.hpp\"\n\n")
sysreg_str_h_fp.printf("#include \"%s_sysreg_impl.hpp\"\n\n", arch_name.downcase)

sysreg_str_h_fp.printf("extern char** csr_name;");

sysreg_str_h_fp.close()


### Generate Template List of CSR Access Functions

sysreg_impl_template_fp = File.open(sprintf('%s_sysreg_template_list.hpp', arch_name.downcase), 'w');
gen_header(sysreg_impl_template_fp)

$sysreg_table.each {|sysreg_info|
  ["Word_t", "DWord_t", "UWord_t", "UDWord_t"].each {|type|
    sysreg_impl_template_fp.printf("template " \
                                   " %s CsrEnv::Read_%s (%s *data, PrivMode mode);\n",
                                   type, sysreg_info[SYSREG::NAME].upcase, type)
  }
}

$sysreg_table.each {|sysreg_info|
  ["Word_t", "DWord_t", "UWord_t", "UDWord_t"].each {|type|
    sysreg_impl_template_fp.printf("template " \
                                   " %s CsrEnv::Write_%s (%s data, PrivMode mode);\n",
                                   type, sysreg_info[SYSREG::NAME].upcase, type)
  }
}

sysreg_impl_template_fp.close
