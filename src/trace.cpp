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

#include <iostream>
#include <iomanip>
#include "env.hpp"
#include "trace.hpp"

#include "inst_decoder_riscv.hpp"

TraceInfo::TraceInfo (EnvBase *env)
  : m_pe_thread (env) {

  // m_max = 0;

  m_hier_debug_in_skip = false;
  m_hier_depth     = 0;
  m_hier_func_in_skip  = false;
  m_hier_func_in_skip  = false;
}


void TraceInfo::clearTraceInfo ()
{
  m_trace_type.clear();
  m_trace_size.clear();
  m_trace_addr.clear();
  m_trace_value.clear();
  m_trace_memresult.clear();
}


TraceType TraceInfo::GetTraceType (uint32_t index) {
  if (index < m_trace_type.size()) {
    return m_trace_type[index];
  } else {
    m_pe_thread->ErrorPrint ("<Internal Error: Bad reference of Trace Info. number of index is %d, and max is %d>\n", index, m_trace_type.size());
    return static_cast<TraceType>(-1);
  }
}

uint8_t TraceInfo::GetTraceSize (uint32_t index) {
  if (index < m_trace_size.size()) {
    return m_trace_size[index];
  } else {
    m_pe_thread->ErrorPrint ("<Internal Error: Bad reference of Trace Size>\n");
    return static_cast<uint8_t>(-1);
  }
}

Addr_t TraceInfo::GetTraceAddr (uint32_t index) {
  if (index < m_trace_addr.size()) {
    return m_trace_addr[index];
  } else {
    m_pe_thread->ErrorPrint ("<Internal Error: Bad reference of Trace Addr>\n");
    return static_cast<Addr_t>(-1);
  }
}

DWord_t TraceInfo::GetTraceValue (uint32_t index) {
  if (index < m_trace_value.size()) {
    return m_trace_value[index];
  } else {
    m_pe_thread->ErrorPrint ("<Internal Error: Bad reference of Trace Value>\n");
    return static_cast<Word_t>(-1);
  }
}

MemResult TraceInfo::GetTraceMemResult (uint32_t index) {
  if (index < m_trace_memresult.size()) {
    return m_trace_memresult[index];
  } else {
    m_pe_thread->ErrorPrint ("<Internal Error: Bad reference of Trace Info. number of index is %d, and max is %d>\n", index, m_trace_memresult.size());
    return static_cast<MemResult>(-1);
  }
}


template <typename DataType>
void TraceInfo::RecordTrace (enum TraceType trace_type, Addr_t addr, DataType value)
{
  // if (m_max < TRACE_MAX) {
  m_trace_type.push_back(trace_type);

  m_trace_size.push_back(sizeof(DataType));
  m_trace_addr.push_back(addr);
  m_trace_value.push_back(value);

  // m_max++;
  // } else {
  //   std::cerr << "<Info: Failed to Record Trace: trace max exceeded = " << m_max << ">\n";
  //   for (uint32_t idx = 0; idx < m_max; idx++) {
  //     std::cerr << "<Info: TraceType = " << static_cast<uint32_t>(m_trace_type[idx]) << ">\n";
  //   }
  //   exit (EXIT_FAILURE);
  // }
}


template <typename DataType>
void TraceInfo::RecordMemTrace (enum TraceType trace_type, Addr_t addr, DataType value, MemResult result)
{
  // if (m_max < TRACE_MAX) {
  m_trace_type.push_back(trace_type);

  m_trace_size.push_back(sizeof (DataType));
  m_trace_addr.push_back(addr);
  m_trace_value.push_back(value);
  m_trace_memresult.push_back(result);

  // m_max++;
  // } else {
  //   std::cerr << "<Info: Failed to Record Trace: trace max exceeded = " << m_max << ">\n";
  //   exit (EXIT_FAILURE);
  // }
}


template <typename DataType>
void TraceInfo::RecordVTrace (enum TraceType trace_type, Addr_t addr, DataType *value)
{
  // if (m_max + 1 >= TRACE_MAX) {
  //   std::cerr << "<<<Internal Error: RecordVTrace capacity is exceeded.>>>\n";
  //   exit(EXIT_FAILURE);
  // }
  m_trace_type .push_back(trace_type);
  m_trace_size .push_back(sizeof (DataType));
  m_trace_addr .push_back(addr);
  m_trace_value.push_back(value->Get64(0));
  // m_max++;

  m_trace_type .push_back(trace_type);
  m_trace_size .push_back(sizeof (DataType));
  m_trace_addr .push_back(addr);
  m_trace_value.push_back(value->Get64(1));
  // m_max++;
}


bool TraceInfo::FindPCUpdate (Addr_t *addr)
{
  bool find_jump_pc = false;
  for (int i = GetMax()-1; i >= 0; i--) {
    if (GetTraceType (i) == TraceType::GRegWrite &&
        GetTraceAddr (i) == REG_PC) {
      *addr = GetTraceValue (i);
      find_jump_pc = true;
      break;
    }
  }
  if (!find_jump_pc) { return false; }

  for (int i = GetMax()-1; i >= 0; i--) {
    if ((GetTraceAddr (i) != REG_PC) &&
        ((GetTraceType (i) == TraceType::GRegWrite) ||
         (GetTraceType (i) == TraceType::XRegWrite))) {
      return true;
    }
  }

  return false;
}


void TraceInfo::HierReturn (Addr_t fetch_pc)
{
  // Return from Function

  // Addr_t phy_fetch_pc;
  // if (m_pe_thread->ConvertVirtualAddress (&phy_fetch_pc, fetch_pc, MemAccType::ReadMemType) != MemResult::MemNoExcept) {
  //   return;
  // }

  if (!m_hier_stack.empty ()) {
    bool is_found_pc = false;
    int32_t pop_count = 0;
    auto trace_it = m_hier_stack.end();
    trace_it--;
    for (; trace_it != m_hier_stack.begin(); trace_it--) {
      if ((*trace_it)->first == fetch_pc) {
        is_found_pc = true;
        break;
      }
      pop_count++;
    }
    if (is_found_pc == true) {
      while (pop_count-- >= 0) {
        m_hier_stack.pop_back();
        SetHierDepth (GetHierDepth()-1);
      }
      for (uint32_t i = 0; i < GetHierDepth (); i++) {
        fprintf (GetTraceHierFp(), "  ");
      }
      fprintf (GetTraceHierFp(), "<Return %d %s>\n", GetStep(), (*trace_it)->second.c_str());

      m_hier_func_in_skip  = false;
      m_hier_debug_in_skip = false;
    }
  }
}


void TraceInfo::HierFunctionCall (Addr_t fetch_pc)
{
  if (m_hier_func_in_skip == true) {
    return;
  }

  // Jump to Function

  Addr_t jump_pc;
  bool is_find_jump_pc = FindPCUpdate (&jump_pc);

  std::string func_symbol;
  if (is_find_jump_pc) {
    if (m_pe_thread->FindSymbol (jump_pc, &func_symbol) == true) {
      for (uint32_t i = 0; i < GetHierDepth (); i++) {
        fprintf (GetTraceHierFp(), "  ");
      }
      std::stringstream str;
      str << "<FunctionCall " << GetStep() << " " << func_symbol << " (0x"
          << std::hex << std::setw(16) << std::setfill('0') << jump_pc << ")";
      fprintf (GetTraceHierFp(), "%s", str.str().c_str());
      SetHierDepth (GetHierDepth()+1);
      PairStackTrace *stack_trace = new PairStackTrace();
      Addr_t next_pc = fetch_pc + RiscvDec::GetInstLength (GetInstIdx()) / 8;
      *stack_trace = std::make_pair (next_pc, func_symbol);
      m_hier_stack.push_back (stack_trace);

      // find skip list
      for (auto it = m_hier_skip_func.begin ();
           it != m_hier_skip_func.end ();
           it++) {
        if ((*it)->first == func_symbol) {
          m_hier_func_in_skip = true;
          if ((*it)->second == InstSkip_t::InstSkip) {
            m_hier_debug_in_skip = true;
          }
          fprintf (GetTraceHierFp(), " ...");
          break;
        }
        it++;
      }
      fprintf (GetTraceHierFp(), ">\n");
    }
  }
}


void TraceInfo::AddSkipTraceFunc (std::string func_name, InstSkip_t inst_skip)
{
  PairSkipFunc *pair_skip_trace = new PairSkipFunc ();
  *pair_skip_trace = std::make_pair (func_name, inst_skip);
  m_hier_skip_func.push_back (pair_skip_trace);

  return;
}


template void TraceInfo::RecordTrace (enum TraceType trace_type, Addr_t addr, UByte_t  value);
template void TraceInfo::RecordTrace (enum TraceType trace_type, Addr_t addr, Byte_t   value);
template void TraceInfo::RecordTrace (enum TraceType trace_type, Addr_t addr, HWord_t  value);
template void TraceInfo::RecordTrace (enum TraceType trace_type, Addr_t addr, UHWord_t value);
template void TraceInfo::RecordTrace (enum TraceType trace_type, Addr_t addr, Word_t   value);
template void TraceInfo::RecordTrace (enum TraceType trace_type, Addr_t addr, UWord_t  value);
template void TraceInfo::RecordTrace (enum TraceType trace_type, Addr_t addr, DWord_t  value);
template void TraceInfo::RecordTrace (enum TraceType trace_type, Addr_t addr, UDWord_t value);

template void TraceInfo::RecordMemTrace (enum TraceType trace_type, Addr_t addr, UByte_t  value, MemResult result);
template void TraceInfo::RecordMemTrace (enum TraceType trace_type, Addr_t addr, Byte_t   value, MemResult result);
template void TraceInfo::RecordMemTrace (enum TraceType trace_type, Addr_t addr, HWord_t  value, MemResult result);
template void TraceInfo::RecordMemTrace (enum TraceType trace_type, Addr_t addr, UHWord_t value, MemResult result);
template void TraceInfo::RecordMemTrace (enum TraceType trace_type, Addr_t addr, Word_t   value, MemResult result);
template void TraceInfo::RecordMemTrace (enum TraceType trace_type, Addr_t addr, UWord_t  value, MemResult result);
template void TraceInfo::RecordMemTrace (enum TraceType trace_type, Addr_t addr, DWord_t  value, MemResult result);
template void TraceInfo::RecordMemTrace (enum TraceType trace_type, Addr_t addr, UDWord_t value, MemResult result);

template void TraceInfo::RecordVTrace (enum TraceType trace_type, Addr_t addr, V2d_t* value);
template void TraceInfo::RecordVTrace (enum TraceType trace_type, Addr_t addr, V8h_t* value);
template void TraceInfo::RecordVTrace (enum TraceType trace_type, Addr_t addr, V4f_t* value);
