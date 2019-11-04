#!/usr/bin/ruby

load "msyksphinz_env.rb"
load "rumy-cpp.rb"

python_cflag  = `python3.6m-config --cflags`.sub("\n", "")
python_ldflag = `python3.6m-config --ldflags`.sub("\n", "")
build_date =    `date +%Y%m%d`.sub("\n", "")
build_version = `git rev-parse --short`.sub("\n", "")

compile_options = []
compile_options = compile_options + ["-DARCH_RISCV"]
compile_options = compile_options + ["-I../vendor/cmdline/"]
compile_options = compile_options + ["-I../vendor/softfloat/SoftFloat-3d/source/include/"]
compile_options = compile_options + ["-I../"]
compile_options = compile_options + ["-I./"]
compile_options = compile_options + ["-std=c++0x -fPIC"]
compile_options = compile_options + [python_cflag]

link_options = []
link_options = [python_ldflag]

link_libs = ["-lbfd", "-lpython3.6m", "-lgmp", "-lgmpxx"]

make_target :gen_riscv_arch_info do
  depends ["../script/gen_arch_table.rb", "../script/gen_decode_table.rb", "../script/gen_operand_table.rb", "../script/gen_inst_mnemonic.rb", "riscv_arch_table.rb"]
  executes ["cd ../src && ruby -I../script/ ../script/gen_arch_table.rb riscv"]
end


make_target :gen_riscv_csr_info do
  depends ["../script/gen_sysreg_table.rb",  "./riscv_spr_table.rb"]
  executes ["cd ../src && ruby -I../script/ ../script/gen_sysreg_table.rb riscv"]
end


cedar_cpp_lists = [
  "../src/riscv_pe_thread.cpp",
  "../src/riscv_syscall.cpp",
  "../src/riscv_fds.cpp",
  "../src/riscv_clint.cpp",
  "../src/env.cpp",
  "../src/inst_category_riscv.cpp",
  "../src/trace.cpp",
  "../src/inst_print_riscv.cpp",
  "../src/inst_mnemonic_riscv.cpp",
  "../src/inst_riscv_init.cpp",
  "../src/inst_decoder_riscv.cpp",
  "../src/inst_riscv.cpp",
  "../src/inst_ops_riscv.cpp",
  "../src/inst_operand_riscv.cpp",
  "../src/dec_utils_riscv.cpp",
  "../src/riscv_sysreg_rw.cpp",
  "../src/riscv_sysreg_impl.cpp",
  "../src/riscv_sysreg_str.cpp",
  "../src/riscv_page_table.cpp",
  "../src/memory_block.cpp",
  "../src/mem_body.cpp",
  "../src/gdb_env.cpp"
]

c_options = compile_options.join(' ').to_s
l_options = link_options.join(' ').to_s

make_library "libriscv_cedar.a", cedar_cpp_lists, compile_options, [], [:gen_riscv_arch_info, :gen_riscv_csr_info]

make_target :config_hpp do
  executes ["sed 's/@VERSION@/#{build_date}/g' config.h.in |
             sed 's/@REVISION@/#{build_version}/g' > config.hpp"]
end

swimmer_cpp_lists = [
  "../src/swimmer_main.cpp",
  "../src/swimmer_util.cpp",
  "../src/riscv_bfd_env.cpp",
  "../src/python3_env.cpp"
]

external_target "../vendor/softfloat/build-rumy/libsoftfloat.a", "../vendor/softfloat/build-rumy/"

make_execute("swimmer_riscv", swimmer_cpp_lists, ["libriscv_cedar.a", "../vendor/softfloat/build-rumy/libsoftfloat.a"],
             compile_options, link_options,
             link_libs,
             [:config_hpp])

if ARGV.length == 0 then
  exec_target "swimmer_riscv"
elsif ARGV[0] == "clean" then
  clean_target "swimmer_riscv"
elsif ARGV[0] == "draw" then
  draw_target "swimmer_riscv"
else
  instance_eval("exec_target ARGV[0]")
end
