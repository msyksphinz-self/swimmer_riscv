/*
 * Copyright (c) 2016, msyksphinz
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

#include <stdint.h>
#include <string>
#include <vector>
#include <list>
#include "basic.hpp"

#include "inst_list_riscv.hpp"

// #define TRACE_MAX 64

using PairStackTrace = std::pair<Addr_t, std::string>;

enum class InstSkip_t {
  InstSkip = 1,
  InstNoSkip = 0
};


enum class PrivMode;
enum class RiscvVmMode;
enum TraceType {
  GRegWrite,   GRegRead,    // 32-bit Integer
  XRegWrite,   XRegRead,    // 64-bit Integer
  FRegWrite,   FRegRead,    // Single-Precision Float
  DRegWrite,   DRegRead,    // Double-Precision Float
  MemRead,     MemWrite,    // Memory Write
  CsrWrite,    CsrRead,
  LrRead,      LrWrite,
  SrRead,      SrWrite,
  IlrRead,     IlrWrite,
  CyRead,      CyWrite
};


using PairSkipFunc = std::pair<std::string, InstSkip_t>;

class EnvBase;

class TraceInfo {
 public:

  TraceInfo () {};
  TraceInfo (EnvBase *env);
  void clearTraceInfo ();

  template <typename DataType> void RecordTrace (enum TraceType, Addr_t, DataType);
  template <typename DataType> void RecordMemTrace (enum TraceType, Addr_t, DataType, MemResult);
  template <typename DataType> void RecordVTrace (enum TraceType, Addr_t, DataType *);

  void SetTracePC (Addr_t pc) {
    m_executed_pc = pc;
  }
  Addr_t GetTracePC (void) { return m_executed_pc; }

  void SetTracePhyPC (Addr_t pc) {
    m_executed_phypc = pc;
  }
  Addr_t GetTracePhyPC (void) { return m_executed_phypc; }


  uint32_t GetMax(void) { return m_trace_type.size(); }

  TraceType GetTraceType      (uint32_t index);
  uint8_t   GetTraceSize      (uint32_t index);
  Addr_t    GetTraceAddr      (uint32_t index);
  DWord_t   GetTraceValue     (uint32_t index);
  MemResult GetTraceMemResult (uint32_t index);

  void SetPrivMode (PrivMode priv) { m_priv = priv; }
  PrivMode GetPrivMode ()     { return m_priv; }

  void SetVmMode (RiscvVmMode vmmode) { m_vmmode = vmmode; }
  RiscvVmMode GetVmMode ()     { return m_vmmode; }

  void   SetInstHex (Word_t inst_hex) { m_inst_hex = inst_hex; }
  Word_t GetInstHex (void)      { return m_inst_hex; }

  void     SetInstIdx (InstId_t inst_idx) { m_previous_idx = m_inst_idx; m_inst_idx = inst_idx; }
  InstId_t GetInstIdx (void)              { return m_inst_idx; }
  InstId_t GetPreviousIdx (void)          { return m_previous_idx; }

  void     SetStep (uint32_t step) { m_step = step; }
  uint32_t GetStep (void)          { return m_step; }

  bool FindPCUpdate (Addr_t *addr);

  void  SetTraceHierFp (FILE *fp) { m_trace_hier_fp = fp; }
  FILE* GetTraceHierFp (void) { return m_trace_hier_fp; }
  void  FlushTraceFp () { fflush (m_trace_hier_fp); }

  void   SetHierDepth (uint32_t hier_depth) { m_hier_depth = hier_depth; }
  uint32_t GetHierDepth (void) { return m_hier_depth; }

  void SetSkipTraceFunc (std::string func_name, InstSkip_t inst_skip);

  void HierReturn (Addr_t fetch_pc);
  void HierFunctionCall (Addr_t fetch_pc);

  void AddSkipTraceFunc (std::string func_name, InstSkip_t inst_skip);

  bool IsHierInSkipMode () { return m_hier_debug_in_skip; }

 private:

  EnvBase *m_pe_thread;

  // Array declaration
  // 0: current PC, 1: delayed slot
  PrivMode    m_priv;
  RiscvVmMode m_vmmode;
  Addr_t   m_executed_pc;
  Addr_t   m_executed_phypc;
  Word_t   m_inst_hex;
  InstId_t m_inst_idx, m_previous_idx;
  uint32_t m_step;

  // uint32_t m_max;

  std::vector<TraceType> m_trace_type; // [TRACE_MAX];

  /* for Register Read/Write */
  std::vector<uint8_t>   m_trace_size     ; // [TRACE_MAX];
  std::vector<Addr_t>    m_trace_addr     ; // [TRACE_MAX];
  std::vector<DWord_t>   m_trace_value    ; // [TRACE_MAX];
  std::vector<MemResult> m_trace_memresult; // [TRACE_MAX];  /* Memory Access Result */

  FILE   *m_trace_hier_fp;   // Trace Hierarchy output file pointer
  std::vector<PairStackTrace *> m_hier_stack;  // Stack of Hierarchy Function Trace
                         // It contains return address
  std::vector<PairSkipFunc *> m_hier_skip_func;   // List of Function name that will be skipped
  uint32_t  m_hier_depth;    // Depth of Hierarchy Function Trace
  bool    m_hier_func_in_skip;  // Hier trace function is currently skip condition
  bool    m_hier_debug_in_skip; // Debug output is also skip or not
};
