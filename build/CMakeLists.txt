cmake_minimum_required(VERSION 2.8)

project (swimmer_riscv)

add_definitions(-DARCH_RISCV)

execute_process (COMMAND date +%Y%m%d OUTPUT_VARIABLE CMAKE_VERSION OUTPUT_STRIP_TRAILING_WHITESPACE)
execute_process (COMMAND git rev-parse --short HEAD OUTPUT_VARIABLE CMAKE_REVISION OUTPUT_STRIP_TRAILING_WHITESPACE)

option (USE_PERF "Use Google Profiler" OFF)

set(CMAKE_VERBOSE_MAKEFILE true)

set(CMAKE_CXX_FLAGS_DEBUG   "${CMAKE_CXX_FLAGS_DEBUG}   -Wall -O0 -g -fstack-protector")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall -O3")

set (VERSION ${CMAKE_VERSION})
set (REVISION ${CMAKE_REVISION})
# set (CMAKE_BUILD_TYPE Debug)
set (CMAKE_C_FLAGS   "${CMAKE_C_FLAGS}             ")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
set (CMAKE_LD_FLAGS  "${CMAKE_LD_FLAGS}  -std=c++0x")

include_directories ("../vendor/cmdline/")
include_directories ($ENV{RISCV}/include/fesvr/)
include_directories ("../vendor/softfloat/SoftFloat-3d/source/include/")
link_directories("../vendor/softfloat/build/")
add_subdirectory(../vendor/softfloat/build/ ../vendor/softfloat/build/)


configure_file ("${PROJECT_SOURCE_DIR}/config.h.in" "${PROJECT_SOURCE_DIR}/config.hpp")

include_directories ("./")

add_custom_command (OUTPUT ../src/inst_decoder_riscv.cpp ../src/inst_category_riscv.cpp ../src/inst_operand_riscv.cpp ../src/inst_mnemonic_riscv.cpp ../src/inst_riscv_init.cpp ../src/inst_operand_riscv.hpp ../src/inst_riscv.hpp
  COMMAND ruby -I../script/ ../script/gen_arch_table.rb riscv
  WORKING_DIRECTORY ../src/
  DEPENDS ../script/gen_arch_table.rb ../script/gen_decode_table.rb ../script/gen_operand_table.rb ../script/gen_inst_mnemonic.rb riscv_arch_table.rb
)

add_custom_command (OUTPUT ../src/riscv_sysreg_rw.cpp ../src/riscv_sysreg_impl.hpp ../src/riscv_sysreg_str.cpp ../src/riscv_sysreg_str.hpp
  COMMAND ruby -I../script/ ../script/gen_sysreg_table.rb riscv
  WORKING_DIRECTORY ../src/
  DEPENDS ../script/gen_sysreg_table.rb ./riscv_spr_table.rb
)

add_custom_target (TAGS
  COMMAND etags `find . -name *.hpp -o -name *.cpp -o -name *.c -o -name *.h | grep -v SoftFloat-3a`
  WORKING_DIRECTORY ../
)


add_library (riscv_cedar
  ../src/riscv_pe_thread.cpp
  ../src/riscv_syscall.cpp
  ../src/riscv_fds.cpp
  ../src/riscv_clint.cpp
  ../src/env.cpp
  ../src/inst_category_riscv.cpp
  ../src/trace.cpp
  ../src/inst_print_riscv.cpp
  ../src/inst_mnemonic_riscv.cpp
  ../src/inst_riscv_init.cpp
  ../src/inst_decoder_riscv.cpp
  ../src/inst_riscv.cpp
  ../src/inst_ops_riscv.cpp
  ../src/inst_operand_riscv.cpp
  ../src/dec_utils_riscv.cpp
  ../src/riscv_sysreg_rw.cpp
  ../src/riscv_sysreg_impl.cpp
  ../src/riscv_sysreg_str.cpp
  ../src/riscv_page_table.cpp
  ../src/memory_block.cpp
  ../src/mem_body.cpp
  ../src/gdb_env.cpp
  ../src/module_crt.cpp
  ../src/module_uart.cpp
)

# ../src/module_rom.cpp

add_executable (swimmer_riscv
  ../src/swimmer_main.cpp
  ../src/riscv_bfd_env.cpp
)

target_link_libraries (riscv_cedar softfloat)
target_link_libraries (riscv_cedar gmp)
target_link_libraries (riscv_cedar gmpxx)

target_link_libraries (swimmer_riscv riscv_cedar)
target_link_libraries (swimmer_riscv ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries (swimmer_riscv bfd)

# Device Tree

add_custom_target (riscv64.dtb
  COMMAND dtc -I dts -O dtb -o riscv64.dtb riscv64.dts
  DEPENDS riscv64.dts)

add_dependencies(swimmer_riscv riscv64.dtb)


# Google Performance Analyzer
if (USE_PERF)
   target_link_libraries (swimmer_riscv tcmalloc)
   target_link_libraries (swimmer_riscv profiler)
endif (USE_PERF)

message (STATUS "Generate config.hpp ...")
message (STATUS "USE_PERF=${USE_PERF}")
