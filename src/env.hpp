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

#pragma once

#include <stdarg.h>
#include <sstream>
#include <set>
#include <vector>
#include <utility>
#include <memory>
#include <map>

#ifdef _ENABLE_BFD_
#include <bfd.h>
#include <dis-asm.h>
#endif // _ENABLE_BFD_

#include "./basic.hpp"
#include "./mem_body.hpp"
#include "./trace.hpp"

class InstEnv;

/*!
 * Architecture Environments
 */

#define REG_R0  0
#define REG_R31 31
#define REG_PC  32

enum class ExecStatus {
  ExecNormal,
  ExecStopSim,
  ExecIllegal,
  ExecBreakPC,
  ExecHaltSim,
  ExecPauseSim,
  ExecSyncSim,
  WaitReducSim
};


enum class BranchPredStatus {
  NotTakenStrong = 0,
  NotTakenWeak   = 1,
  TakenWeak      = 2,
  TakenStrong    = 3
};


enum class MemAccType {
  FetchMemType = 0,
  WriteMemType = 1,
  ReadMemType  = 2
};


enum class AbiRegType {
  AbiRegHardName = 0,
  AbiRegSoftName = 1
};


enum class LoopType_t {
  InfLoop = true,
  FiniteLoop = false
};

class EnvBase
{
 public:
  using FunctionInfo = std::map<Addr_t, std::string>;

  using FunctionTable = FunctionInfo;
  using VariableTable = FunctionInfo;

  // BFD debug information
  std::unique_ptr<FunctionTable> m_func_table;
  std::unique_ptr<VariableTable> m_gvar_table;

 protected:
  std::unique_ptr<TraceInfo> m_trace;      // trace information

 private:
  /*!
   * Architecture Implementations
   */
  std::unique_ptr<DWord_t []> m_regs;   // general register

  Addr_t m_current_pc,   // PC before executing branch
       m_previous_pc;

  bool     m_is_jumped;

  /*!
   * debug information
   */
  bool    m_is_debug_print;  // Debug Trace is displayed or not
  bool    m_is_debug_func;   // Debug Function is displayed or not
  bool    m_is_debug_gvar;   // Global Variable is displayed or not

  bool    m_is_trace_hier;   // Hierarchy Function Trace is generated or not

  std::set<Addr_t> m_queue_pc_break;   // PC break list

  bool    m_is_resume_break; // Resume from Break
  LoopType_t m_loop_type;     // Infinite loop or finite loop

  FILE   *m_dbgfp;       // file pointer for debugging output
  uint64_t  m_start_time,    // for debug: performance counter start and stop
            m_stop_time;
  uint64_t  m_max_cycle;     // limit of simulation cycle
  uint64_t  m_step;      // no of simulation step
  uint64_t  m_logstart;
  uint64_t  m_printstep;

  int64_t m_fsize = 0;       // Max File Size

  std::vector<uint64_t> m_inst_count;

  /*!
   * Simulation Control information
   */
  uint8_t m_stop_sim;     //! if this flag is enabled, simulation would be stopped.
  uint8_t m_en_stop_sim;  //! if this flag is enabled, simulation can be stopped by hitting CSR registers
  uint8_t m_result;

 public:
  std::unique_ptr<Memory>  m_memory;

  MemResult LoadMemByte   (Addr_t addr, Byte_t *data);
  MemResult LoadMemHWord  (Addr_t addr, Byte_t *data);
  MemResult LoadMemWord   (Addr_t addr, Byte_t *data);
  MemResult LoadMemDWord  (Addr_t addr, Byte_t *data);
  MemResult StoreMemByte  (Addr_t addr, Byte_t *data);
  MemResult StoreMemHWord (Addr_t addr, Byte_t *data);
  MemResult StoreMemWord  (Addr_t addr, Byte_t *data);
  MemResult StoreMemDWord (Addr_t addr, Byte_t *data);

  static uint32_t htoi (char h);

  std::shared_ptr<InstEnv> m_inst_env;   // Instruction Execution environment

  bool GetJumped (void) { return m_is_jumped; }
  void SetJumped (bool jumped) { m_is_jumped = jumped; }

  void PrintInst (uint32_t inst_hex, uint32_t inst_idx,
                  char *str_out, const uint32_t length);

  void StepSimulation (uint64_t stepCount, LoopType_t inf_loop);
  virtual ExecStatus StepExec (bool is_resume_break) = 0;

  inline uint32_t GetStep (void) { return m_step; }
  inline void SetStep (uint32_t step) { m_step = step; }

  TraceInfo *GetTrace (void) { return m_trace.get(); }
  InstEnv *GetInstEnv (void) { return m_inst_env.get(); }

  void   SetStopSim (bool stop_sim) { m_stop_sim = stop_sim; }
  bool   IsStopSim  (void) { return m_stop_sim; }

  void    SetResult (uint8_t result) { m_result = result; }
  uint8_t GetResult (void) { return m_result; }

  void   DebugPrint (const char *format, ...);
  void   InfoPrint  (const char *format, ...);
  void   ErrorPrint (const char *format, ...);
  void   WarnMemoryResult (MemResult ret, Addr_t addr);

  /*!
   * === Architecture Environments ===
   */
  template <class T> T    ReadGReg  (RegAddr_t);
  template <class T> void WriteGReg (RegAddr_t, T data);

  template <class T> T  GetGReg (RegAddr_t reg_addr);

  void   SetPC (Addr_t);
  Addr_t   GetPC (void);
  Addr_t   GetPreviousPC (void) { return m_previous_pc; }
  void   ProceedPC (void);

  MemResult FetchMemory (Addr_t, Word_t *);
  template <typename AccType> MemResult LoadMemory  (Addr_t, AccType *);
  template <typename AccType> MemResult StoreMemory (Addr_t, AccType *);
  template <typename AccType> MemResult LoadMemoryDebug  (Addr_t, AccType *);
  template <typename AccType> MemResult StoreMemoryDebug (Addr_t, AccType *);

  void   AdvanceStep (void);

  virtual std::string GetRegSoftName (RegAddr_t addr) = 0;
  virtual AbiRegType GetPrintRegStyle (void) = 0;

  uint32_t LoadSrec (std::string filename);
  uint32_t LoadBinary (std::string filename);
  uint32_t LoadImage (std::string filename);
#ifdef _ENABLE_BFD_
  void   LoadFunctionTable (bfd *abfd);
  void   LoadGVariableTable (bfd *abfd);
#endif // _ENABLE_BFD_

  uint64_t GetMaxCycle () { return m_max_cycle; }
  void SetMaxCycle (uint64_t max_cycle) { m_max_cycle = max_cycle; }

  //! Following should be fixed
  FILE* GetDbgFilePointer (void) { return m_dbgfp; }
  void SetDebugFileSize (int64_t fsize) { m_fsize = fsize; }
  int64_t GetMaxDebugFileSize (void) { return m_fsize; }

  int64_t GetCurrentDbgFileSize (void) {
    fpos_t fsize;
    fgetpos (m_dbgfp, &fsize);
    return fsize.__pos;
  }
  void SetDbgFilePointer (FILE *dbgfp) { m_dbgfp = dbgfp; }

  void SetImgFileName (std::string img_filename);

  bool IsResumeBreak (void) { return m_is_resume_break; }
  void SetResumeBreak (bool is_resume_break) { m_is_resume_break = is_resume_break; }

  bool IsDebugTrace (void) { return m_is_debug_print; }
  void SetDebugTrace (bool is_debug_print) { m_is_debug_print = is_debug_print; }

  bool IsDebugFunc (void) { return m_is_debug_func; }
  void SetDebugFunc (bool is_debug_func) { m_is_debug_func = is_debug_func; }

  bool IsDebugGVar (void) { return m_is_debug_gvar; }
  void SetDebugGVar (bool is_debug_gvar) { m_is_debug_gvar = is_debug_gvar; }

  bool FindSymbol (Addr_t addr, std::string *symbol);
  bool FindGVariable (Addr_t addr, std::string *symbol);

  bool FindFuncAddr (Addr_t *addr, std::string symbol);
  bool FindGVarAddr (Addr_t *addr, std::string symbol);

  void AddPCBreak (Addr_t addr);
  bool RemovePCBreak (Addr_t addr);
  bool FindPCBreak (Addr_t addr);

  inline uint64_t GetLogStart () { return m_logstart; }
  inline void SetLogStart (uint64_t logstart) { m_logstart = logstart; }
  inline uint64_t GetPrintStep () { return m_printstep; }
  inline void SetPrintStep (uint64_t printstep) { m_printstep = printstep; }

  void FlushDbgFile () { fflush (m_dbgfp); }
  void FlushTraceFp () { GetTrace()->FlushTraceFp (); }

  // Function Trace Hierarchy Functions
  void SetTraceHier (bool trace_hier) { m_is_trace_hier = trace_hier; }
  bool GetTraceHier (void) { return m_is_trace_hier; }

  virtual void UpdateL1Icache (Addr_t addr) = 0;
  // Virtual Memory
  virtual MemResult ConvertVirtualAddress (Addr_t *paddr, Addr_t vaddres, MemAccType acc_type) = 0;

  EnvBase (bool is_debug_print, FILE *dbgfp, bool trace_hier, std::string trace_out);
  virtual ~EnvBase();
};
