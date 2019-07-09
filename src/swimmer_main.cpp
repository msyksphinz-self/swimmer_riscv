/*
 * Copyright (c) 2015, msyksphinz
 * All rights reserved.
 *
 *   Redistribution and use in source and binary forms, with or without
 *   modification, are permitted provided that the following conditions are met:
 *   * Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *   * Neither the name of the copyright holder nor the
 *     names of its contributors may be used to endorse or promote products
 *     derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 *   ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY
 *   DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 *   (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 *   ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 *   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

// #define _GLIBCXX_USE_CXX11_ABI 0

#include <unistd.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <memory>
#include <Python.h>

#include "cmdline.h"

#include "swimmer_main.hpp"
#include "swimmer_util.hpp"
#include "python3_env.hpp"
#include "config.hpp"
#include "gdb_env.hpp"

#include "inst_operand_riscv.hpp"
#include "riscv_pe_thread.hpp"

#ifdef USE_PERF
#include <gperftools/profiler.h>
#endif // USE_PERF

// Global Variables for Flags
FILE  *g_uart_fp;

int main (int argc, char *argv[])
{
#ifdef USE_PERF
  ProfilerStart ("swimmer.prof");
#endif // USE_PERF

  FILE *debug_fp;

  std::string	debug_filename;

  int	result = 0;

  cmdline::parser cmd_line;

  //=====================
  // Command Line Parser
  //=====================

  // Commond Options
  cmd_line.add<uint32_t>   ("max_size"       , '\0', "Max size of log file [MB]"   							   , false, 0 );
  cmd_line.add<uint64_t>   ("max"			 , '\0', "Max instructions to simulate"							   , false, 0 );
  cmd_line.add<std::string>("binfile"		 , '\0', "Binary file to simulate."    							   , false, "");
  cmd_line.add<std::string>("hexfile"		 , '\0', "Hex file to simulate."       							   , false, "");
  cmd_line.add<std::string>("imgfile"		 , '\0', "Image file to simulate."     							   , false, "");
  cmd_line.add             ("only_info_load" , '\0', "Debug Info is only loaded (only enable with --binfile)"             );
  cmd_line.add             ("debug"			 , '\0', "Generate debug log"                                                 );
  cmd_line.add<std::string>("out"			 , '\0', "Output log filename"                                     , false    );
  cmd_line.add             ("load-dump"		 , '\0', "Dump Loaded Bin file (only enable with --binfile)"                  );
  cmd_line.add<std::string>("init_pc"        , '\0', "Initial Program Counter Value"                           , false    );

#if defined ARCH_RISCV
  cmd_line.add             ("stop-host"		 , '\0', "Stop simulation by accessing MTOHOST"                               );
  // cmd_line.add<uint32_t>   ("gdb"			 , '\0', "Wait GDB port"                                           , false, -1);
  cmd_line.add<std::string>("use-pk"         , '\0', "Location of RISC-V Proxy Kernel"                         , false    );
  // cmd_line.add<uint32_t>   ("bit-mode"       , '\0', "Execution Bit-Mode (32 or 64)"                           , false, 64);
  cmd_line.add<std::string>("arch"           , '\0', "Support RISC-V Architecture (ex. --arch rv32imafd.../rv64imafd...)" , false, "rv64imafdc");
  cmd_line.add             ("trace-hier"     , '\0', "Generate Hierarcical Trace"                                         );
  cmd_line.add<std::string>("trace-out"      , '\0', "Hierarcical Trace Output Filename"                       , false, "");
  cmd_line.add<std::string>("vmlinux"        , '\0', "Location of vmlinux"                                     , false, "");
  cmd_line.add<uint64_t>   ("logstart"       , '\0', "cycle of log start"                                      , false, 0 );
  cmd_line.add<uint64_t>   ("printstep"      , '\0', "print number of steps each cycle"                        , false, 0 );
  cmd_line.add<std::string>("signature"      , '\0', "Generate Signature and filename "                        , false, "");
  cmd_line.add             ("protect-misa"   , '\0', "Protect to write MISA."                                             );

#endif // defined ARCH_RISCV

  cmd_line.add             ("py"             , 'p',  "Python interactive mode"            );
  cmd_line.add<std::string>("py-scr"         , '\0', "Read Python configuration file"     , false);

  cmd_line.add ("version", 'v', "Show Version Information");

  cmd_line.parse_check (argc, argv);

  if (cmd_line.exist("version")) {
    display_info(stdout);
    return 0;
  }

  std::string hexfile_name    = cmd_line.get<std::string>("hexfile");
  bool        is_cmd_hexfile  = !hexfile_name.empty();
  std::string binfile_name    = cmd_line.get<std::string>("binfile");
  bool        is_cmd_binfile  = !binfile_name.empty();
  std::string init_pc_str     = cmd_line.get<std::string>("init_pc");
  bool        is_init_pc      = !init_pc_str.empty();
  bool        is_debug_trace  = cmd_line.exist("debug");
  bool        is_load_dump    = cmd_line.exist("load-dump");

#if defined ARCH_RISCV
  std::string pk_loc          = cmd_line.get<std::string>("use-pk");
  bool is_stop_host           = cmd_line.exist           ("stop-host");
  // uint32_t bit_mode_n         = cmd_line.get<uint32_t>   ("bit-mode");
  std::string arch_str        = cmd_line.get<std::string>("arch");

  std::transform(arch_str.begin(), arch_str.end(), arch_str.begin(), ::tolower);  // Lower
  if (arch_str[0] != 'r' || arch_str[1] != 'v') {
    fprintf(stderr, "Error : --arch option should start with 'rv'\n");
    exit (EXIT_FAILURE);
  }
  const char *arch_str_c = arch_str.c_str();
  uint32_t    bit_mode_n = ((arch_str_c[2] - '0') * 10) + (arch_str_c[3] - '0');
  RiscvBitMode_t bit_mode;
  if (!(bit_mode_n == 32 || bit_mode_n == 64)) {
    std::cout << "<Error: Bit Mode " << bit_mode_n << " is not supported. Abort.>\n";
    printf("%s\n", arch_str_c);
    printf("%x %x\n", arch_str_c[2], arch_str_c[3]);
    exit (EXIT_FAILURE);
  } else {
    bit_mode = (bit_mode_n == 32) ? RiscvBitMode_t::Bit32 : RiscvBitMode_t::Bit64;
  }

  uint64_t misa_value = (1 << ('u' - 'a')) | (1 << ('s' - 'a'));
  for(size_t idx = 4; idx < arch_str.length(); idx++) {
    if (arch_str[idx] == 'g') {
      arch_str += "imafd";
    }
    misa_value |= 1 << (arch_str[idx] - 'a');
  }

  bool is_trace_hier         = cmd_line.exist("trace-hier");
  std::string trace_hier_str = cmd_line.get<std::string>("trace-out");
  std::string vmlinux_pos    = cmd_line.get<std::string>("vmlinux");
  uint64_t logstart          = cmd_line.get<std::uint64_t>("logstart");
  uint64_t printstep         = cmd_line.get<std::uint64_t>("printstep");
  bool is_gen_sig            = cmd_line.get<std::string>("signature") != "";
  std::string sig_file       = cmd_line.get<std::string>("signature");
  bool is_py_mode            = cmd_line.exist("py");

  std::string pyscr_filename = "";
  if (cmd_line.exist("py-scr")) {
    pyscr_filename = cmd_line.get<std::string>("py-scr");
  }

  bool is_misa_writable = true;
  if (cmd_line.exist("protect-misa")) {
    is_misa_writable = false;
  }

#endif // defined ARCH_RISCV

  Addr_t init_pc = 0x0;
  if (is_init_pc) {
    char *fail_str;
    init_pc = strtoull (init_pc_str.c_str(), &fail_str, 16);
  } else {
    init_pc = 0x1000;
  }

  // opening debug out
  if (!cmd_line.get<std::string>("out").empty()) {
    std::string out_filename = cmd_line.get<std::string>("out");
    if ((debug_fp = fopen(out_filename.c_str(), "w")) == NULL) {
      perror (out_filename.c_str());
      exit (EXIT_FAILURE);
    }
  } else {
    debug_fp = stdout;
  }

  uint64_t max_sim_inst = cmd_line.get<uint64_t>("max");

  FormatOperand ();

  if (is_py_mode) {

    wchar_t *_program_name = Py_DecodeLocale(pyscr_filename.c_str(), NULL);
    char *py_args[] = {"swimmer_riscv"};
    wchar_t **_argv = nstrws_array(1, py_args);

    /* Add a built-in module, before Py_Initialize */
    PyImport_AppendInittab("riscv", InitPyEnv);

    Py_SetProgramName(_program_name);
    Py_Initialize();

    PyImport_ImportModule("riscv");
    PyRun_SimpleString ("import riscv");

    if (pyscr_filename != "") {
      FILE *py_fp;
      if ((py_fp = fopen(pyscr_filename.c_str(), "r")) == NULL) {
        perror (pyscr_filename.c_str());
        exit (EXIT_FAILURE);
      }
      PyRun_SimpleFile (py_fp, pyscr_filename.c_str());
    } else {
      Py_Main(1, _argv);
    }
    Py_Finalize ();

  } else {

    if (is_cmd_hexfile || is_cmd_binfile) {
      RiscvPeThread *m_chip = new RiscvPeThread (debug_fp, bit_mode, misa_value, PrivMode::PrivUser, is_stop_host, is_debug_trace, g_uart_fp, is_trace_hier, trace_hier_str, is_misa_writable);

      m_chip->SetPC (init_pc);
      m_chip->SetMaxCycle (max_sim_inst);

      FILE *hex_fp = nullptr;
      if (is_cmd_hexfile && (hex_fp = fopen(hexfile_name.c_str(), "r")) == NULL) {
        perror (hexfile_name.c_str());
        exit (EXIT_FAILURE);
      }

      if (is_cmd_binfile) {
        if (is_gen_sig) {
          m_chip->SetSignature(sig_file);
        }

        if (m_chip->LoadBinary (argv[0], binfile_name.c_str(), is_load_dump) == -1) {
          delete m_chip;
          return -1;
        }
        m_chip->SetBinaryName (binfile_name);
        if (!pk_loc.empty()) {
          if (m_chip->LoadBinary ("", pk_loc, is_load_dump) == -1) {
            delete m_chip;
            return -1;
          }
        }
        if (!vmlinux_pos.empty()) {
          if (m_chip->LoadBinaryTable (vmlinux_pos, true) == -1) {
            delete m_chip;
            return -1;
          }
        }
        m_chip->SetLogStart(logstart);
        m_chip->SetPrintStep(printstep);
      }
      m_chip->SetDebugFunc(is_trace_hier);
      m_chip->SetDebugGVar(is_trace_hier);
      m_chip->StepSimulation(max_sim_inst, (max_sim_inst == 0) ? LoopType_t::InfLoop : LoopType_t::FiniteLoop);
      result = m_chip->GetResult();

      if (is_gen_sig) {
        m_chip->OutputSignature();
      }

      delete m_chip;

    } else {
      std::cerr << "Input file (--hexfile) is not specified.\n";
      exit (EXIT_FAILURE);
    }
  }

#ifdef USE_PERF
  ProfilerStop ();
#endif // USE_PERF

  if (is_gen_sig) {
    return 0;
  } else {
    return result;
  }
}


/*!
 * display usage
 * \param fp   file pointer to be displaying of usage information
 */
void display_info (FILE *fp)
{
  fprintf (fp, "// Swimmer-RISCV\n");
  fprintf (fp, "//  Version %s Revision %s\n", VERSION, REVISION);
  fprintf (fp, "//  developed by msyksphinz <msyksphinz.dev@gmail.com>\n");
  return;
}
