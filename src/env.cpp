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


#include <set>
#include <stdarg.h>
#include <stdint.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <memory>
#include <string.h>
#include <inttypes.h>
#include "mem_body.hpp"
#include "memory_block.hpp"
#include "basic.hpp"
#include "env.hpp"
#include "trace.hpp"


/*!
 * step instruction
 */
void EnvBase::StepSimulation (uint64_t stepCount, LoopType_t inf_loop)
{
  SetStopSim (false);  // at first, release stop condition

  uint64_t max_step = GetMaxCycle ();

  m_loop_type = inf_loop;

  for (uint64_t step = 0;
       (IsStopSim () == false) &&
           ((inf_loop == LoopType_t::InfLoop) ||
            (inf_loop == LoopType_t::FiniteLoop && (step < max_step)));
       step++) {
    GetTrace()->clearTraceInfo ();
    ExecStatus status = StepExec (IsResumeBreak ());
    if (status == ExecStatus::ExecBreakPC) {
      SetResumeBreak (true);
      DebugPrint ("Resume. Return Loop\n");
      return;   // break PC
    } else {
      SetResumeBreak (false);
    }
  }

  return;
}


/*!
 * Reference from Memory
 * \param addr address
 * \param env RISCV environment
 */
MemResult EnvBase::LoadMemByte (Addr_t addr, Byte_t *data)
{
  MemResult ret = m_memory->LoadMemory<Byte_t> (addr, data);
  if (ret != MemResult::MemNoExcept) {
    WarnMemoryResult (ret, addr);
  }
  return ret;
}


/*!
 * Reference from Memory
 * \param addr address
 * \param env RISCV environment
 */
MemResult EnvBase::LoadMemHWord (Addr_t addr, Byte_t *data)
{
  MemResult ret = m_memory->LoadMemory<HWord_t> (addr, data);
  if (ret != MemResult::MemNoExcept) {
    WarnMemoryResult (ret, addr);
  }
  return ret;
}


/*!
 * Reference from Memory
 * \param addr address
 * \param env RISCV environment
 */
MemResult EnvBase::LoadMemWord (Addr_t addr, Byte_t *data)
{
  MemResult ret = m_memory->LoadMemory<Word_t> (addr, data);
  if (ret != MemResult::MemNoExcept) {
    WarnMemoryResult (ret, addr);
  }
  return ret;
}


/*!
 * Reference from Memory
 * \param addr address
 * \param env RISCV environment
 */
MemResult EnvBase::LoadMemDWord (Addr_t addr, Byte_t *data)
{
  MemResult ret = m_memory->LoadMemory<DWord_t> (addr, data);
  if (ret != MemResult::MemNoExcept) {
    WarnMemoryResult (ret, addr);
  }
  return ret;
}


/*!
 * Store Data to Memory (Byte)
 * \param addr address
 * \param env RISCV environment
 */
MemResult EnvBase::StoreMemByte (Addr_t addr, Byte_t *data)
{
  MemResult ret = m_memory->StoreMemory<Byte_t> (addr, data);
  if (ret != MemResult::MemNoExcept) {
    WarnMemoryResult (ret, addr);
  }
  return ret;
}


/*!
 * Store Data to Memory (HWord)
 * \param addr address
 * \param env RISCV environment
 */
MemResult EnvBase::StoreMemHWord (Addr_t addr, Byte_t *data)
{
  MemResult ret = m_memory->StoreMemory<HWord_t> (addr, data);
  if (ret != MemResult::MemNoExcept) {
    WarnMemoryResult (ret, addr);
  }
  return ret;
}


/*!
 * Store Data to Memory (Word)
 * \param addr address
 * \param env RISCV environment
 */
MemResult EnvBase::StoreMemWord (Addr_t addr, Byte_t *data)
{
  MemResult ret = m_memory->StoreMemory<Word_t> (addr, data);
  if (ret != MemResult::MemNoExcept) {
    WarnMemoryResult (ret, addr);
  }
  return ret;
}


/*!
 * Store Data to Memory (Word)
 * \param addr address
 * \param env RISCV environment
 */
MemResult EnvBase::StoreMemDWord (Addr_t addr, Byte_t *data)
{
  MemResult ret = m_memory->StoreMemory<DWord_t> (addr, data);
  if (ret != MemResult::MemNoExcept) {
    WarnMemoryResult (ret, addr);
  }
  return ret;
}


/*!
 * Load Data from Memory
 */
template <typename AccType>
MemResult EnvBase::LoadMemory (Addr_t addr, AccType *data)
{
  MemResult res = LoadMemoryDebug<AccType> (addr, data);

  if (IsDebugTrace() == true) {
    DWord_t record_data = 0;
    memcpy (&record_data, data, sizeof(AccType));
    m_trace->RecordTrace (TraceType::MemRead, addr, record_data);

    std::string gvar_symbol;
    if (IsDebugGVar () &&
        (FindGVariable (addr, &gvar_symbol) == true)) {
      DebugPrint ("<GlobalVar: %s(0x%016" PRIx64 ")=>0x%016" PRIx64 ">\n", gvar_symbol.c_str(), addr, record_data);
    }
  }

  return res;
}


/*!
 * Load Data from Memory
 * it is different from LoadMemory, FetchMemory doesn't recorded to trace
 */
MemResult EnvBase::FetchMemory (Addr_t addr, Word_t *data)
{
  Byte_t byte_data[4];
  Addr_t phy_pc;
  MemResult result = ConvertVirtualAddress (&phy_pc, addr, MemAccType::FetchMemType);
  if (result == MemResult::MemTlbError) {
    return result;
  }

  UpdateL1Icache (phy_pc);

  GetTrace()->SetTracePhyPC(phy_pc);

  result = LoadMemWord (phy_pc, byte_data);
  memcpy (data, byte_data, 4);
  return result;
}


template <typename AccType>
MemResult EnvBase::StoreMemory (Addr_t addr, AccType *data)
{
  MemResult res = StoreMemoryDebug<AccType>(addr, data);

  if (IsDebugTrace() == true) {
    DWord_t record_data = 0;
    memcpy (&record_data, data, sizeof(AccType));

    m_trace->RecordTrace (TraceType::MemWrite, addr, record_data);

    std::string gvar_symbol;
    if (IsDebugGVar () &&
        (FindGVariable (addr, &gvar_symbol) == true)) {
      DebugPrint ("<GlobalVar: %s<=%016" PRIx64 ">\n", gvar_symbol.c_str(), record_data);
    }
  }

  return res;
}


template <typename AccType>
MemResult EnvBase::StoreMemoryDebug (Addr_t addr, AccType *data)
{
  Byte_t *byte_data = new Byte_t[sizeof(AccType)];
  memcpy (byte_data, data, sizeof(AccType));

  MemResult res = m_memory->StoreMemory<AccType> (addr, byte_data);

  delete[] byte_data;
  return res;
}


template <typename AccType>
MemResult EnvBase::LoadMemoryDebug (Addr_t addr, AccType *data)
{
  Byte_t *byte_data = new Byte_t[sizeof(AccType)];

  MemResult res = m_memory->LoadMemory<AccType> (addr, byte_data);
  if (res != MemResult::MemNoExcept) {
    WarnMemoryResult (res, addr);
  }
  memcpy (data, byte_data, sizeof(AccType));
  delete[] byte_data;

  return res;
}


void EnvBase::AdvanceStep (void)
{
  m_step++;
  if ((m_loop_type == LoopType_t::FiniteLoop) && (m_step >= m_max_cycle)) {
    SetStopSim (true);
  }
}


/*!
 * load s-rec motrola format
 * \param fp   file pointer to be loaded srec
 * \param env  environment to be load
 * \return   max memory address to be loaded
 */
uint32_t EnvBase::LoadSrec (std::string filename)
{
  FILE *fp;
  if ((fp = fopen(filename.c_str(), "r")) == NULL) {
    perror (filename.c_str());
    exit (EXIT_FAILURE);
  }

  char buff[256 + 1];
  char load_data = false;
  uint32_t pc_max = 0x00000000;

  while (fgets (buff, 256, fp) != NULL) {
    if (buff[0] == 'S') { // valid s-record
      uint8_t type = buff[1] - 0x30;
      uint8_t byte_length = (htoi (buff[2]) << 4) + htoi (buff[3]);
      uint32_t address = 0;
      uint8_t addr_len;   // length of address format
      switch (type) {
      case 0 : // Block header
        addr_len = 4; load_data = false; break;  // 2 byte
      case 1 : // Data sequence
        addr_len = 4; load_data = true;  break;  // 2 byte
      case 2 : // Data sequence
        addr_len = 6; load_data = true;  break;  // 3 byte
      case 3 : // Data sequence
        addr_len = 8; load_data = true;  break;  // 4 byte
      case 5 : // m_trace->Record count
        addr_len = 4; load_data = false; break;  // 2 byte
      case 7 : // End of block
        addr_len = 8; load_data = false; break;  // 4 byte
      case 8 : // End of block
        addr_len = 6; load_data = false; break;  // 3 byte
      case 9 : // End of block
        addr_len = 4; load_data = false; break;  // 2 byte
      default : // illegal type
        addr_len = 0;
        load_data = false;
        fprintf (stderr, "<Loading Srecord File : type is illegal %d>\n", type);
        break;
      }

      if (load_data == true) {
        //** read address of S-Rec
        int index; // head of address
        const int addr_head = 4;
        for (index = 0; index < addr_len; index++) {
          address = (address << 4) + htoi (buff[index + addr_head]);
        }

        //** read word
        int data_head = index + addr_head;   // head of data is tail of address information
        for (uint8_t i = 0; i < byte_length - (addr_len / 2) - 1; i++) {
          Byte_t data = (htoi (buff[i * 2 + data_head]) << 4) + htoi (buff[i * 2 + 1 + data_head]);
          StoreMemoryDebug (address, &data);
          address++;
        }
        if (pc_max < address) {
          pc_max = address;
        }
      }
    }
  }

  return pc_max;
}


uint32_t EnvBase::htoi (char h)
{

  if (h >= '0' && h <= '9') {
    return h - '0';  // number
  } else if (h >= 'A' && h <= 'F') {
    return h - 'A' + 10; // 0xA - 0xF
  } else if (h >= 'a' && h <= 'f') {
    return h - 'a' + 10;
  } else {
    return -1;
  }
}



/*!
 * Write new Addr to PC
 * \param reg  register address to write
 * \param daat write data
 * \param env  RISC-V environment
 */
void EnvBase::SetPC (Addr_t addr)
{
  if (IsDebugTrace() == true) {
    m_trace->RecordTrace (TraceType::GRegWrite, REG_PC, addr);
  }

  m_previous_pc = m_current_pc;
  m_current_pc  = addr;

}


/*!
 * Read current PC
 * \param reg  register address to write
 * \param daat write data
 * \param env  RISC-V environment
 */
Addr_t EnvBase::GetPC (void)
{
  return m_current_pc;
}


/*!
 * Read from General Register
 * \param reg register address to read
 */
template <class T>
T EnvBase::ReadGReg (RegAddr_t reg)
{
  T value = m_regs[reg];

  if (IsDebugTrace() == true) {
    m_trace->RecordTrace (TraceType::GRegRead, reg, value);
  }
  return value;
}


/*!
 * Write Data General Register
 * \param reg  register address to write
 * \param daat write data
 * \param env  RISC-V environment
 */
template <class T>
void EnvBase::WriteGReg (RegAddr_t reg, T data)
{
  if (reg != 0x00) {
    if (IsDebugTrace() == true) {
      m_trace->RecordTrace (TraceType::GRegWrite, reg, data);
    }

    m_regs[reg] = data;
  }
}


template <class T>
T EnvBase::GetGReg (RegAddr_t reg_addr)
{
  if (reg_addr < 32) {
    return m_regs[reg_addr];
  } else {
    return 0;
  }
}


void EnvBase::DebugPrint (const char *format, ...)
{
  if (m_is_debug_print && GetLogStart() <= GetStep()) {
    va_list args;
    va_start (args, format);

    char* allocated_buffer;
    vasprintf(&allocated_buffer, format, args);

    fprintf (m_dbgfp, "%s", allocated_buffer);
    fflush(m_dbgfp);

    va_end(args);

    free(allocated_buffer);
  }
}


void EnvBase::InfoPrint (const char *format, ...)
{
  va_list args;
  va_start (args, format);

  char* allocated_buffer;
  vasprintf(&allocated_buffer, format, args);

  fprintf (stdout, "%s", allocated_buffer);

  va_end(args);

  free(allocated_buffer);
}


void EnvBase::ErrorPrint (const char *format, ...)
{
  va_list args;
  va_start (args, format);

  char* allocated_buffer;
  vasprintf(&allocated_buffer, format, args);

  fprintf (m_dbgfp, "%s", allocated_buffer);
  fprintf (stderr,  "%s", allocated_buffer);

  va_end(args);

  free(allocated_buffer);
}


void EnvBase::WarnMemoryResult (MemResult ret, Addr_t addr)
{
  std::stringstream str;

  switch (ret) {
    case MemResult::MemNotDefined :
      str << "<Warning: Memory Region " << std::hex << std::setw(16) << addr << std::setfill('0') << " is not defined.>\n";
      DebugPrint ("%s", str.str().c_str());
      break;
    case MemResult::MemMisAlign :
      str << "<Warning: Memory " << std::hex << std::setw(16) << addr << std::setfill('0') << " MisAlign Access.>\n";
      DebugPrint ("%s", str.str().c_str());
      break;
    case MemResult::MemNewRegion :
      str << "<Info: NewMemory Region " << std::hex << std::setw(16) << std::setfill('0') << addr << " is defined.>\n";
      DebugPrint ("%s", str.str().c_str());
      break;
    default :
      break;
  }
  return;
}


bool EnvBase::FindSymbol (Addr_t addr, std::string *symbol)
{
  auto it = m_func_table->find(addr);
  if (it != m_func_table.get()->end()) {
    *symbol = it->second;
    return true;
  } else {
    return false;
  }
}


bool EnvBase::FindGVariable (Addr_t addr, std::string *symbol)
{
  auto it = m_gvar_table->find(addr);
  if (it != m_gvar_table.get()->end()) {
    *symbol = it->second;
    return true;
  } else {
    return false;
  }
}


bool EnvBase::FindFuncAddr (Addr_t *addr, std::string symbol)
{
  for (auto it = m_func_table.get()->begin ();
     it != m_func_table->end ();
     it++) {
    if (it->second == symbol) {
      *addr = it->first;
      return true;
    }
  }
  return false;
}


bool EnvBase::FindGVarAddr (Addr_t *addr, std::string symbol)
{
  for (auto it = m_gvar_table->begin ();
       it != m_gvar_table->end ();
       it++) {
    if (it->second == symbol) {
      *addr = it->first;
      return true;
    }
  }
  return false;
}


void EnvBase::AddPCBreak (Addr_t addr)
{
  if (m_queue_pc_break.find (addr) == m_queue_pc_break.end()) {
    InfoPrint ("<set_pc_break : %08x>\n", addr);
    m_queue_pc_break.insert (addr);
  } else {
    InfoPrint ("<set_pc_break : already inserted %08x>\n", addr);
  }
  return;
}


bool EnvBase::RemovePCBreak (Addr_t addr)
{
  for (auto it = m_queue_pc_break.begin();
     it != m_queue_pc_break.end();
     it++) {
    if ((*it) == addr) {
      InfoPrint ("<remove_pc_break : %08x>\n", addr);
      m_queue_pc_break.erase (it);
      return true;
    }
  }
  return false;
}


bool EnvBase::FindPCBreak (Addr_t addr)
{
  if (m_queue_pc_break.find (addr) == m_queue_pc_break.end()) {
    return false;
  } else {
    return true;
  }
}


EnvBase::EnvBase (bool is_debug_print, FILE *dbgfp, bool trace_hier, std::string trace_out)
    : m_is_debug_print(is_debug_print), m_dbgfp(dbgfp)
{
  m_step   = 0;
#ifdef  ARCH_RISCV
  m_regs   = std::unique_ptr<DWord_t[]>(new DWord_t[32]);
#endif // ARCH_RISCV

  m_memory   = std::unique_ptr<Memory> (new Memory ());

  m_func_table = std::unique_ptr<FunctionTable> (new FunctionTable ());
  m_gvar_table = std::unique_ptr<VariableTable> (new VariableTable ());

  m_stop_sim = false;
  m_result   = false;

  m_is_debug_func  = false;
  m_is_debug_gvar  = false;

  m_trace = std::unique_ptr<TraceInfo> (new TraceInfo(this));

  for (uint32_t idx = 0;
       idx < (static_cast<uint32_t>(InstId_t::INST_ID_SENTINEL_MAX));
       idx++) {
    m_inst_count.push_back(0);
  }

  SetTraceHier (trace_hier);
  if (trace_hier && !trace_out.empty()) {
    FILE *trace_fp;
    if ((trace_fp = fopen(trace_out.c_str(), "w")) == NULL) {
      std::stringstream err_str;
      err_str << trace_out << ": fopen";
      perror (err_str.str().c_str());
      exit (EXIT_FAILURE);
    }
    GetTrace()->SetTraceHierFp (trace_fp);
  } else {
    GetTrace()->SetTraceHierFp (GetDbgFilePointer ());
  }
}


EnvBase::~EnvBase()
{
}



// Template instantiation

template Word_t   EnvBase::ReadGReg (RegAddr_t reg);
template UWord_t  EnvBase::ReadGReg (RegAddr_t reg);
template DWord_t  EnvBase::ReadGReg (RegAddr_t reg);
template UDWord_t EnvBase::ReadGReg (RegAddr_t reg);

template void EnvBase::WriteGReg (RegAddr_t reg, Word_t   data);
template void EnvBase::WriteGReg (RegAddr_t reg, UWord_t  data);
template void EnvBase::WriteGReg (RegAddr_t reg, DWord_t  data);
template void EnvBase::WriteGReg (RegAddr_t reg, UDWord_t data);

template Word_t   EnvBase::GetGReg (RegAddr_t reg_addr);
template UWord_t  EnvBase::GetGReg (RegAddr_t reg_addr);
template DWord_t  EnvBase::GetGReg (RegAddr_t reg_addr);
template UDWord_t EnvBase::GetGReg (RegAddr_t reg_addr);

template MemResult EnvBase::LoadMemory<Word_t  > (Addr_t addr, Word_t   *data);
template MemResult EnvBase::LoadMemory<UWord_t > (Addr_t addr, UWord_t  *data);
template MemResult EnvBase::LoadMemory<DWord_t > (Addr_t addr, DWord_t  *data);
template MemResult EnvBase::LoadMemory<UDWord_t> (Addr_t addr, UDWord_t *data);
template MemResult EnvBase::LoadMemory<HWord_t > (Addr_t addr, HWord_t  *data);
template MemResult EnvBase::LoadMemory<UHWord_t> (Addr_t addr, UHWord_t *data);
template MemResult EnvBase::LoadMemory<Byte_t  > (Addr_t addr, Byte_t   *data);
template MemResult EnvBase::LoadMemory<UByte_t > (Addr_t addr, UByte_t  *data);

template MemResult EnvBase::LoadMemoryDebug<Word_t  > (Addr_t addr, Word_t   *data);
template MemResult EnvBase::LoadMemoryDebug<UWord_t > (Addr_t addr, UWord_t  *data);
template MemResult EnvBase::LoadMemoryDebug<DWord_t > (Addr_t addr, DWord_t  *data);
template MemResult EnvBase::LoadMemoryDebug<UDWord_t> (Addr_t addr, UDWord_t *data);
template MemResult EnvBase::LoadMemoryDebug<HWord_t > (Addr_t addr, HWord_t  *data);
template MemResult EnvBase::LoadMemoryDebug<UHWord_t> (Addr_t addr, UHWord_t *data);
template MemResult EnvBase::LoadMemoryDebug<Byte_t  > (Addr_t addr, Byte_t   *data);
template MemResult EnvBase::LoadMemoryDebug<UByte_t > (Addr_t addr, UByte_t  *data);

template MemResult EnvBase::StoreMemory<Word_t  > (Addr_t addr, Word_t   *data);
template MemResult EnvBase::StoreMemory<UWord_t > (Addr_t addr, UWord_t  *data);
template MemResult EnvBase::StoreMemory<DWord_t > (Addr_t addr, DWord_t  *data);
template MemResult EnvBase::StoreMemory<UDWord_t> (Addr_t addr, UDWord_t *data);
template MemResult EnvBase::StoreMemory<HWord_t > (Addr_t addr, HWord_t  *data);
template MemResult EnvBase::StoreMemory<UHWord_t> (Addr_t addr, UHWord_t *data);
template MemResult EnvBase::StoreMemory<Byte_t  > (Addr_t addr, Byte_t   *data);
template MemResult EnvBase::StoreMemory<UByte_t > (Addr_t addr, UByte_t  *data);

template MemResult EnvBase::StoreMemoryDebug<Word_t  > (Addr_t addr, Word_t   *data);
template MemResult EnvBase::StoreMemoryDebug<UWord_t > (Addr_t addr, UWord_t  *data);
template MemResult EnvBase::StoreMemoryDebug<DWord_t > (Addr_t addr, DWord_t  *data);
template MemResult EnvBase::StoreMemoryDebug<UDWord_t> (Addr_t addr, UDWord_t *data);
template MemResult EnvBase::StoreMemoryDebug<HWord_t > (Addr_t addr, HWord_t  *data);
template MemResult EnvBase::StoreMemoryDebug<UHWord_t> (Addr_t addr, UHWord_t *data);
template MemResult EnvBase::StoreMemoryDebug<Byte_t  > (Addr_t addr, Byte_t   *data);
template MemResult EnvBase::StoreMemoryDebug<UByte_t > (Addr_t addr, UByte_t  *data);
