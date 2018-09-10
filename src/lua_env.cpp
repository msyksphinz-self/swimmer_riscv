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

#include <iostream>
#include <stdlib.h>
#include <sys/param.h>
#include <string>

#include "./lua_env.hpp"
#include "./sc3_pe_thread.hpp"


extern FILE  *g_debug_fp;
extern FILE  *g_srec_fp;
extern FILE  *g_uart_fp;


void ExecuteFromFile (const std::string filename)
{
  lua_State *lua_state = luaL_newstate ();
  luaL_openlibs (lua_state);

  // Register Functions
  lua_register (lua_state, "make_core", Lua_MakeCore);
  lua_register (lua_state, "run", Lua_Run);
  lua_register (lua_state, "set_pc", Lua_SetPC);
  lua_register (lua_state, "set_max_cycle", Lua_SetMaxCycle);
  lua_register (lua_state, "load", Lua_LoadBin);
  lua_register (lua_state, "debug", Lua_SetDebug);
  lua_register (lua_state, "get_step", Lua_GetStep);
  lua_register (lua_state, "get_addr", Lua_GetAddr);
  lua_register (lua_state, "set_pcbreak", Lua_SetPCBreak);
  lua_register (lua_state, "get_reg", Lua_GetReg);
  lua_register (lua_state, "get_mem", Lua_GetMem);
  lua_register (lua_state, "dump_regs", Lua_DumpRegs);
  lua_register (lua_state, "skip_hier", Lua_SkipHier);

  int lua_result = luaL_dofile (lua_state, filename.c_str());

  if (lua_result != 0) {
    std::string error_message = lua_tostring (lua_state, -1);
    std::cerr << "<Error calling " << filename << " : " << error_message << ">\n";
  } else {
    std::cerr << "<Success to calling " << filename << ">\n";
  }
}


int Lua_MakeCore (lua_State *L)
{
  // Getting Arguments
  std::string arch_name = lua_tostring (L, 1);

  Sc3PeThread *env;
  if (arch_name == "sc2") {
    env = new Sc3PeThread (g_debug_fp, false, FLAGS_debug, g_uart_fp);
    env->DebugPrint ("<make core: %s %d>\n", arch_name.c_str(), FLAGS_debug);
  } else {
    std::cout << "<Unsupported Architecture : " << arch_name << ">\n";
    return 0;
  }

  env->SetDebugFileSize (FLAGS_max_size * 1024 * 1024);

  env->SetMaxCycle (FLAGS_max);

  Addr_t init_pc;

  if (!FLAGS_init_pc.empty()) {
    char *fail_str;
    init_pc = strtol (FLAGS_init_pc.c_str(), &fail_str, 16);
    if (fail_str == NULL) {
      std::cerr << "Failed to convert " << FLAGS_init_pc.c_str() << " into hex PC" << std::endl;
      exit (EXIT_FAILURE);
    }
  } else {
#ifdef  ARCH_MIPS64
    init_pc = 0xffffffffbfc00000;
#else // ARCH_MIPS64
    init_pc = 0xbfc00000;
#endif // ARCH_MIPS64
  }

  env->SetPC (init_pc);

  env->SetMaxCycle (FLAGS_max);
  env->SetDbgFilePointer (g_debug_fp);

  env->SetDebugFunc (FLAGS_debug_func);
  env->SetDebugGVar (FLAGS_debug_gvar);

#ifdef ARCH_MIPS
  env->SetImgFileName (FLAGS_imgfile);
#endif // ARCH_MIPS

  if (!FLAGS_binfile.empty ()) {
    env->LoadBinary (FLAGS_binfile);
  }
  if (!FLAGS_hexfile.empty ()) {
    env->LoadSrec (FLAGS_hexfile);
  }

  env->SetTraceHier (FLAGS_trace_hier);
  if (!FLAGS_trace_out.empty()) {
    if (FLAGS_trace_hier == false) {
      std::cerr << "--trace_out can be only specified with --trace_hier\n";
      exit (EXIT_FAILURE);
    }

    FILE *trace_fp;
    if ((trace_fp = fopen(FLAGS_trace_out.c_str(), "w")) == NULL) {
      std::stringstream err_str;
      err_str << FLAGS_trace_out << ": fopen";
      perror (err_str.str().c_str());
      exit (EXIT_FAILURE);
    }
    env->GetTrace()->SetTraceHierFp (trace_fp);
  } else {
    env->GetTrace()->SetTraceHierFp (g_debug_fp);
  }


  lua_pushlightuserdata (L, static_cast<void *>(env));

  return 1;
}


int Lua_SetPC (lua_State *L)
{
  // Getting Arguments
  Sc3PeThread *env = static_cast<Sc3PeThread *>(lua_touserdata (L, 1));
  Addr_t pc = lua_tointeger (L, 2);

  env->SetPC (pc);
  env->DebugPrint ("<set_pc (%08x)>\n", pc);

  return 0;
}


int Lua_SetMaxCycle (lua_State *L)
{
  // Getting Arguments
  Sc3PeThread *env = static_cast<Sc3PeThread *>(lua_touserdata (L, 1));
  uint32_t cycle = lua_tointeger (L, 2);

  env->SetMaxCycle (cycle);
  env->DebugPrint ("<set_max_cycle (%d)>\n", cycle);

  return 0;
}


int Lua_Run (lua_State *L)
{
  // Getting Arguments
  Sc3PeThread *env = static_cast<Sc3PeThread *>(lua_touserdata (L, 1));
  env->DebugPrint ("<Run: RISC-V>\n", env->GetMaxCycle());

  env->StepSimulation (env->GetMaxCycle(), LoopType_t::FiniteLoop);

  return 0;
}


int Lua_LoadBin (lua_State *L)
{
  // Getting Arguments
  Sc3PeThread *env = static_cast<Sc3PeThread *>(lua_touserdata (L, 1));

  std::string path = lua_tostring (L, 2);
  env->DebugPrint ("<Load: %s>\n", path.c_str());

  env->LoadBinary (path);

  return 0;
}


int Lua_SetDebug (lua_State *L)
{
  // Getting Arguments
  Sc3PeThread *env = static_cast<Sc3PeThread *>(lua_touserdata (L, 1));

  std::string path = lua_tostring (L, 2);

  if (path == "func") {
    env->SetDebugFunc (true);
  } else if (path == "gvar") {
    env->SetDebugGVar (true);
  } else if (path == "on") {
    env->SetDebugTrace (true);
  } else if (path == "off") {
    env->SetDebugTrace (false);
  }

  return 0;
}


int Lua_GetStep (lua_State *L)
{
  // Getting Arguments
  Sc3PeThread *env = static_cast<Sc3PeThread *>(lua_touserdata (L, 1));

  uint32_t step = env->GetStep();
  lua_pushinteger (L, step);

  return 1;
}


int Lua_GetAddr (lua_State *L)
{
  // Getting Arguments
  Sc3PeThread *env = static_cast<Sc3PeThread *>(lua_touserdata (L, 1));

  std::string symbol = lua_tostring (L, 2);
  Addr_t addr;
  if (env->FindFuncAddr (&addr, symbol) == true) {
    lua_pushinteger (L, addr);
  } else if (env->FindGVarAddr (&addr, symbol) == true) {
    lua_pushinteger (L, addr);
  } else {
    lua_pushinteger (L, -1);
  }

  return 1;
}


int Lua_SetPCBreak (lua_State *L)
{
  // Getting Arguments
  Sc3PeThread *env = static_cast<Sc3PeThread *>(lua_touserdata (L, 1));

  Addr_t pc_addr = lua_tointeger (L, 2);
  env->AddPCBreak (pc_addr);

  return 1;
}


int Lua_GetReg (lua_State *L)
{
  // Getting Arguments
  Sc3PeThread *env = static_cast<Sc3PeThread *>(lua_touserdata (L, 1));

  RegAddr_t reg_addr = lua_tointeger (L, 2);
  env->DebugPrint ("<get reg: r%02d=%08x>\n", reg_addr, env->GetGReg<UWord_t> (reg_addr));

  return 0;
}


int Lua_GetMem (lua_State *L)
{
  // Getting Arguments
  Sc3PeThread *env = static_cast<Sc3PeThread *>(lua_touserdata (L, 1));

  Addr_t addr = lua_tointeger (L, 2);
  Word_t word;
  env->LoadFromBusDebug (addr, Size_Word, reinterpret_cast<Byte_t *>(&word));
  env->DebugPrint ("<get memory: [%08x]=%08x>\n", addr, word);

  return 0;
}


int Lua_DumpRegs (lua_State *L)
{
  // Getting Arguments
  Sc3PeThread *env = static_cast<Sc3PeThread *>(lua_touserdata (L, 1));

  env->DebugPrint ("<dump regs>\n");
  for (int reg_addr = 0; reg_addr < 32; reg_addr++) {
    if (FLAGS_reg_abi == "soft") {
      env->DebugPrint (" %s=%08x\n", env->GetRegSoftName (reg_addr).c_str(), env->GetGReg<UWord_t> (reg_addr));
    } else {
      env->DebugPrint (" r%02d=%08x\n", reg_addr, env->GetGReg<UWord_t> (reg_addr));

    }
  }

  return 0;
}


/*!
 * Skip Showing Trace after the depth of the funcition
 */
int Lua_SkipHier (lua_State *L)
{
  // Getting Arguments
  int arg_size = lua_gettop (L);
  Sc3PeThread *env = static_cast<Sc3PeThread *>(lua_touserdata (L, 1));

  std::string func_name = lua_tostring (L, 2);
  InstSkip_t inst_skip = InstSkip_t::InstNoSkip;
  if (arg_size >= 3) {
    std::string debug_option = lua_tostring (L, 3);
    if (debug_option == "debug_skip") {
      env->DebugPrint ("<Skip_hier: %s debug_skip>\n", func_name.c_str());
      inst_skip = InstSkip_t::InstSkip;
    } else {
      std::cerr << "Error: unknown option in skip_hier \"" << debug_option.c_str() << "\"\n";
      exit (EXIT_FAILURE);
    }
  } else {
    env->DebugPrint ("<Skip_hier: %s>\n", func_name.c_str());
  }

  env->GetTrace ()->AddSkipTraceFunc (func_name, inst_skip);

  return 0;
}
