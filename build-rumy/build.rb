#!/usr/bin/ruby

load "rumy-main.rb"

python_cflag  = `python3.6m-config --cflags`.sub("\n", "")
python_ldflag = `python3.6m-config --ldflags`.sub("\n", "")
build_date =    `date +%Y%m%d`.sub("\n", "")
build_version = `git rev-parse --short`.sub("\n", "")

compile_options = []
compile_options = compile_options + ["-DARCH_RISCV"]
compile_options = compile_options + ["-I../vendor/cmdline/"]
compile_options = compile_options + ["-I../vendor/softfloat/SoftFloat-3d/source/include/"]
compile_options = compile_options + ["-I."]
compile_options = compile_options + ["-std=c++0x -fPIC"]
compile_options = compile_options + [python_cflag]

link_options = []
link_options = [python_ldflag]

make_target "test" do
  global
  depends ["test.c"]
  executes ["gcc test.c -o test"]
end

obj_lists = [
  "riscv_pe_thread.o",
  "riscv_syscall.o",
  "riscv_fds.o",
  "riscv_clint.o",
  "env.o",
  "inst_category_riscv.o",
  "trace.o",
  "inst_print_riscv.o",
  "inst_mnemonic_riscv.o",
  "inst_riscv_init.o",
  "inst_decoder_riscv.o",
  "inst_riscv.o",
  "inst_ops_riscv.o",
  "inst_operand_riscv.o",
  "dec_utils_riscv.o",
  "riscv_sysreg_rw.o",
  "riscv_sysreg_impl.o",
  "riscv_sysreg_str.o",
  "riscv_page_table.o",
  "memory_block.o",
  "mem_body.o",
  "gdb_env.o"
]

c_options = compile_options.join(' ').to_s
l_options = link_options.join(' ').to_s

obj_lists.each {|obj|
  make_target obj do
    src = "../src/" + obj.sub(".o", ".cpp")
    depends [src]
    executes ["g++ #{c_options} -c #{src} -o #{obj}"]
  end
}

make_target "libriscv_cedar.a" do
  depends obj_lists
  executes ["ar qc libriscv_cedar.a #{obj_lists.join(' ').to_s}"]
end

make_target :config_hpp do
  executes ["sed 's/@VERSION@/#{build_date}/g' config.h.in |
             sed 's/@REVISION@/#{build_version}/g' > config.hpp"]
end

make_target "swimmer_main.o" do
  src = "../src/swimmer_main.cpp"
  depends [:config_hpp]
  executes ["g++ #{c_options} -c #{src} -o swimmer_main.o"]
end

swimmer_obj_lists = [
  "swimmer_util.o",
  "riscv_bfd_env.o",
  "python3_env.o"
]


swimmer_obj_lists.each {|obj|
  make_target obj do
    src = "../src/" + obj.sub(".o", ".cpp")
    depends [src]
    executes ["g++ #{c_options} -c #{src} -o #{obj}"]
  end
}


make_target "swimmer_riscv" do
  global
  depends swimmer_obj_lists + ["swimmer_main.o"] + ["libriscv_cedar.a"]
  link_libs = ["-lbfd", "-lpython3.6m", "-lgmp", "-lgmpxx"].join(' ').to_s
  executes ["g++ #{l_options} #{swimmer_obj_lists.join(' ').to_s} \
            swimmer_main.o \
            libriscv_cedar.a \
            ../vendor/softfloat/build/libsoftfloat.a \
            -o swimmer_riscv \
            #{link_libs}"]
end


if ARGV.length == 0 then
  exec_target "swimmer_riscv"
elsif ARGV[0] == "clean" then
  clean_target "swimmer_riscv"
elsif ARGV[0] == "draw" then
  draw_target "swimmer_riscv"
else
  instance_eval("exec_target ARGV[0]")
end
