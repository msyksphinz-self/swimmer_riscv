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
#include <iomanip>
#include <memory>
#include <string.h>
#include <cmath>
#include <inttypes.h>
#include "memory_block.hpp"
#include "basic.hpp"
#include "riscv_sysreg_impl.hpp"
#include "riscv_pe_thread.hpp"
#include "trace.hpp"
#include "riscv_page_table.hpp"
#include "inst_decoder_riscv.hpp"
#include "riscv_syscall.hpp"
#include "riscv_term.hpp"
#include "riscv_clint.hpp"


IntCode operator|(IntCode L, IntCode R) {
  return static_cast<IntCode>(static_cast<uint64_t>(L) | static_cast<uint64_t>(R));
}

IntCode operator&(IntCode L, IntCode R) {
  return static_cast<IntCode>(static_cast<uint64_t>(L) & static_cast<uint64_t>(R));
}

IntCode operator>>(IntCode L, IntCode R) {
  return static_cast<IntCode>(static_cast<uint64_t>(L) >> static_cast<uint64_t>(R));
}

IntCode operator<<(IntCode L, IntCode R) {
  return static_cast<IntCode>(static_cast<uint64_t>(L) << static_cast<uint64_t>(R));
}

UDWord_t operator<<(UDWord_t L, IntCode R) {
  return L << static_cast<uint64_t>(R);
}


/*!
 * create new RISCV simulation environment
 * \return RiscvPeThread structure (not formatted)
 */
RiscvPeThread::RiscvPeThread (FILE           *dbgfp,
                              RiscvBitMode_t bit_mode,
                              uint64_t       misa,
                              PrivMode       maxpriv,
                              bool           en_stop_host,
                              bool           is_debug_trace,
                              FILE           *uart_fp,
                              bool           trace_hier,
                              std::string    trace_out,
                              bool           is_misa_writable)
    : EnvBase (is_debug_trace, dbgfp, trace_hier, trace_out),
      m_bit_mode (bit_mode),
      m_en_stop_host (en_stop_host),
      m_is_misa_writable (is_misa_writable)
{
  m_ptr_riscv_dec = new RiscvDec(this);

  m_priv = PrivMode::PrivMachine; // set default Priviledge Mode
  m_maxpriv = maxpriv;
  m_vmmode = RiscvVmMode::Vm_Mbare;  // set default Virtualization Type as MBare

  m_inst_env = std::unique_ptr<InstEnv> (new InstEnv (this));
  m_csr_env  = std::unique_ptr<CsrEnv> (new CsrEnv (this));
  m_riscv_page_table = std::unique_ptr<RiscvPageTable>(new RiscvPageTable(this));

  UDWord_t misa_val = (2ULL << 62) | misa;
  CSRWrite (SYSREG_ADDR_MISA, misa_val, PrivMode::PrivMachine);  // Set MISA

  // Floating Point Register Format
  m_regs  = std::unique_ptr<DWord_t[]>(new DWord_t[32]);
  m_fregs = std::unique_ptr<DWord_t[]>(new DWord_t[32]);

  m_device_list = new RiscvDeviceList_t();
  RiscvSyscall_t *riscv_syscall = new RiscvSyscall_t(0, this);
  m_device_list->RegisterDevice(riscv_syscall);  // Device List = 0

  RiscvTerm_t *riscv_term = new RiscvTerm_t (1, this);
  m_device_list->RegisterDevice(riscv_term);     // Device List = 1

  //=================================
  // Add RISC-V Memory Mapped Device
  //=================================
  m_riscv_clint = new RiscvClint_t(this, 0x02000000, 0x0000ffff);
  m_mm_device_list.push_back (m_riscv_clint);

#ifdef NEVER

  Addr_t init_pc = 0;
  if (!FLAGS_init_pc.empty()) {
    char *fail_str;
    init_pc = strtoull (FLAGS_init_pc.c_str(), &fail_str, 16);

    if (fail_str == NULL) {
      std::cerr << "Failed to convert " << FLAGS_init_pc.c_str() << " into hex PC" << std::endl;
      exit (EXIT_FAILURE);
    }
  }

  SetMaxCycle (FLAGS_max);
  SetPC (init_pc);

  // For Future Map simulation
  if (FLAGS_fut_map) {
    m_dst_idx = std::unique_ptr<uint32_t []> (new uint32_t[32]);

    m_dst_idx_head = 0;
    for (int i = 1; i < 32; i++) {
      m_dst_idx[i] = i + (128-32);
    }
    for (int i = 0; i < (128-32); i++) {
      m_dst_queue.push(i);
    }
  }

  // For L1-Dcache simulation
  if (FLAGS_sim_l1d) {
    m_dcache_en   = std::unique_ptr<bool []>(new bool[L1D_LENGTH]);
    m_dcache_addr = std::unique_ptr<Addr_t []>(new Addr_t[L1D_LENGTH]);

    for (int i = 0; i < L1D_LENGTH; i++) {
      m_dcache_en[i] = false;
    }
  }

  // For L1-Icache simulation
  if (FLAGS_sim_l1i) {
    m_icache_en   = std::unique_ptr<bool []>(new bool[L1I_LENGTH]);
    m_icache_addr = std::unique_ptr<Addr_t []>(new Addr_t[L1I_LENGTH]);

    for (int i = 0; i < L1I_LENGTH; i++) {
      m_icache_en[i] = false;
    }
  }


  if (FLAGS_sim_pred) {
    m_branch_his_table    = std::unique_ptr<uint8_t []>(new uint8_t[BRANCH_LOCAL_LENGTH]);
    m_branch_status_table = std::unique_ptr<BranchPredStatus []>(new BranchPredStatus[BRANCH_STATUS_LENGTH]);

    for (int i = 0; i < BRANCH_LOCAL_LENGTH; i++) {
      m_branch_his_table[i] = 0;
    }
    for (int i = 0; i < BRANCH_STATUS_LENGTH; i++) {
      m_branch_status_table[i] = BranchPredStatus::NotTakenStrong;
    }
  }

#endif // NEVER

  m_reg_print_type = AbiRegType::AbiRegSoftName;

  SetStopSim (false);

  FlushTlb();
}


RiscvPeThread::~RiscvPeThread ()
{
  delete m_ptr_riscv_dec;
  delete m_device_list;
}


/*!
 * Load Data from Memory
 * it is different from LoadMemory, FetchMemory doesn't recorded to trace
 */
MemResult RiscvPeThread::FetchMemory (Addr_t addr, Word_t *data)
{
  Byte_t byte_data[4];
  Addr_t phy_pc;
  MemResult result = ConvertVirtualAddress (&phy_pc, addr, MemAccType::FetchMemType);
  if (result == MemResult::MemTlbError) {
    return result;
  }

  UpdateL1Icache (phy_pc);

  GetTrace()->SetTracePhyPC(phy_pc);

  if (addr & 0x2) {
    // HalfWord Fetch
    result = LoadMemHWord (phy_pc + 0, &byte_data[0]);
    result = LoadMemHWord (phy_pc + 2, &byte_data[2]);
  } else {
    // Word Fetch
    result = LoadMemWord (phy_pc, byte_data);
  }
  memcpy (data, byte_data, 4);
  return result;
}


#define likely(x)   __builtin_expect(!!(x), 1)
#define unlikely(x) __builtin_expect(!!(x), 0)

ExecStatus RiscvPeThread::StepExec (bool is_resume_break)
{
  if (IsStopSim() == true) {
    return ExecStatus::ExecStopSim;
  }

  SetJumped (false);

  m_count_timer ++;

  if (IsCpuWaitMode() == true) {
    ClearLoadReservation ();
    m_riscv_clint->Increment(INTERLEAVE / INSNS_PER_RTC_TICK);
    HandleCommand ();

    m_device_list->Tick();

    m_count_timer = 0;
    SetCpuWaitMode (false);
    return ExecStatus::ExecNormal;
  }

  uint64_t print_step = GetPrintStep();
  if (print_step != 0) {
    if ((m_trace->GetStep() % print_step) == (print_step-1)) {
      printf("[Swimmer Step = %d]\n", GetStep());
    }
  }

  IntCode code;
  if (CheckInterrupt(&code)) {
    GenerateInterrupt(code);
    return ExecStatus::ExecNormal;
  }

  Word_t    inst_hex;
  MemResult fetch_res;
  Addr_t    fetch_pc = GetPC();

  int32_t vaddr_width = (m_bit_mode == RiscvBitMode_t::Bit32) ? 32/4 : 64/4;
  int32_t paddr_width = (m_bit_mode == RiscvBitMode_t::Bit32) ? 32/4 : 48/4;

  if (FindPCBreak (fetch_pc) &&
    !is_resume_break) {
    DebugPrint ("<Break PC: %08x>\n", fetch_pc);
    return ExecStatus::ExecBreakPC;
  }

  if (!IsSupportCMode() && ((fetch_pc & 0x03) != 0)) {
    GenerateException (ExceptCode::Except_InstAddrMisalign, fetch_pc);
    return ExecStatus::ExecIllegal;
  }

  fetch_res = FetchMemory (fetch_pc, &inst_hex);

  if (fetch_res == MemResult::MemNotDefined) {
    DebugPrint ("<Info: Memory 0x%08x is not defined.>\n", fetch_pc);
  }

  if (fetch_res == MemResult::MemTlbError) {
    DebugPrint ("<Info: MemResult::MemTlbError occured.>\n");
    return ExecStatus::ExecNormal;
  }

  if (fetch_res != MemResult::MemNoExcept) {
    GenerateException (ExceptCode::Except_InstAddrMisalign, fetch_pc);
    return ExecStatus::ExecIllegal;
  }

  // std::string func_symbol;
  // if ((IsDebugFunc () == true) &&
  //     (FindSymbol (fetch_pc, &func_symbol) == true)) {
  //   DebugPrint ("<Func: %s 0x%08x>\n", func_symbol.c_str(), fetch_pc);
  // }

  GetTrace()->SetInstHex (inst_hex);
  GetTrace()->SetPrivMode (GetPrivMode());
  GetTrace()->SetVmMode (GetVmMode());
  GetTrace()->SetTracePC (fetch_pc);
  GetTrace()->SetStep(GetStep());

  AdvanceStep ();  // Update Step Information

  InstId_t inst_idx = m_ptr_riscv_dec->DecodeInst (inst_hex);
  GetTrace()->SetInstIdx (inst_idx);

  if (RiscvDec::GetInstCategory(inst_idx) == InstCategory::COMPRESS) {
    if (!IsSupportCMode()) {
      GenerateException (ExceptCode::Except_InstAddrMisalign, inst_hex);
    }
  }

  if (inst_idx == InstId_t::INST_ID_SENTINEL_MAX) {
    std::stringstream err_str;
    uint32_t bit_length  = m_bit_mode == RiscvBitMode_t::Bit32 ? 8 : 16;
    err_str << "<Error: instruction is not decoded. ["
            << std::hex << std::setfill('0') << std::setw(bit_length) << fetch_pc << "]="
            << std::hex << std::setfill('0') << std::setw(8) << inst_hex << ">\n";
    ErrorPrint ("%s", err_str.str().c_str());
    GenerateException (ExceptCode::Except_IllegalInst, inst_hex);
  } else {
    Addr_t addr_bit_mask;

    if (m_bit_mode == RiscvBitMode_t::Bit32) {
      addr_bit_mask = 0x00ffffffffULL;
    } else {
      addr_bit_mask = 0x00ffffffffffffffffULL;
    }
    m_inst_env->RISCV_Inst_Exec (inst_idx, inst_hex);

    if (IsDebugTrace() == true && GetLogStart() <= GetStep()) {
      DebugPrint ("%10d:", GetTrace()->GetStep ());
      DebugPrint ("%c:", GetTrace()->GetPrivMode() == PrivMode::PrivUser       ? 'U' :
                         GetTrace()->GetPrivMode() == PrivMode::PrivSupervisor ? 'S' :
                         GetTrace()->GetPrivMode() == PrivMode::PrivHypervisor ? 'H' :
                         GetTrace()->GetPrivMode() == PrivMode::PrivMachine    ? 'M' : 'X');
      DebugPrint ("%s:", GetTrace()->GetVmMode() == RiscvVmMode::Vm_Mbare ? "MBar" :
                         GetTrace()->GetVmMode() == RiscvVmMode::Vm_Sv32  ? "Sv32" :
                         GetTrace()->GetVmMode() == RiscvVmMode::Vm_Sv39  ? "Sv39" :
                         GetTrace()->GetVmMode() == RiscvVmMode::Vm_Sv48  ? "Sv48" :
                         "XXXX");
      std::stringstream pc_str;

      Addr_t v_pc = GetTrace()->GetTracePC    () & addr_bit_mask;
      Addr_t p_pc = GetTrace()->GetTracePhyPC () & addr_bit_mask;

      uint32_t inst_length = RiscvDec::GetInstLength (inst_idx);

      pc_str << std::hex << std::setfill('0') << std::setw(vaddr_width) << v_pc << ":P";
      pc_str << std::hex << std::setfill('0') << std::setw(paddr_width) << p_pc << ":";
      if (inst_length == 32) { pc_str << std::hex <<           std::setfill('0') << std::setw(8) << (GetTrace()->GetInstHex ())           << ":"; }
      if (inst_length == 16) { pc_str << std::hex << "    " << std::setfill('0') << std::setw(4) << (GetTrace()->GetInstHex () & 0x0ffff) << ":"; }
      DebugPrint ("%s", pc_str.str().c_str());

      char inst_string[50];
      PrintInst (GetTrace()->GetInstHex(), GetTrace()->GetInstIdx(),
                 inst_string, 50);
      DebugPrint ("%-30s  :", inst_string);

#ifdef NEVER
      // For Future Map simulation
      if (FLAGS_fut_map) {
        if (GetTraceDstAddr() != static_cast<Addr_t>(-1)) {
          DebugPrint ("(%2d,%2d) ", m_dst_queue.front(), m_dst_idx[GetTraceDstAddr()]);

          m_dst_queue.push(m_dst_idx[GetTraceDstAddr()]);
          m_dst_idx[GetTraceDstAddr()] = m_dst_queue.front();
          m_dst_queue.pop();
        } else {
          DebugPrint ("        ");
        }
      }
#endif // NEVER

      std::stringstream operand_str;
      PrintOperand (&operand_str);

      DebugPrint ("%s\n", operand_str.str().c_str());
      // {
      //   UDWord_t mstatus;
      //   CSRReadNoTrace(SYSREG_ADDR_MSTATUS, &mstatus, PrivMode::PrivMachine);
      //   DebugPrint ("<Info: mstatus = %016lx>\n", mstatus);
      // }
    }
    // Hierarchy Trace Mode
    if (GetTraceHier ()) {
      GetTrace()->HierReturn (fetch_pc);
      GetTrace()->HierFunctionCall (GetPreviousPC());
    }
  }

  if (GetJumped () == false) {
    ProceedPC (GetTrace()->GetInstIdx());  // Update PC
  }

  // Check Max Size
  if (GetMaxDebugFileSize() != 0 &&
      stdout != GetDbgFilePointer()) {
    int64_t cur_file_size = GetCurrentDbgFileSize ();
    if ((GetMaxDebugFileSize () != 0) &&
      (cur_file_size > GetMaxDebugFileSize ())) {
      SetStopSim (true);
      DebugPrint ("<Achieved Log File size = %d[byte]>\n", GetCurrentDbgFileSize ());
    }
  }

  CountUpTimer ();

  if (m_count_timer == 5000) {
    HandleCommand ();

    m_count_timer = 0;
  }

  return ExecStatus::ExecNormal;
}


void RiscvPeThread::ProceedPC (InstId_t inst_id)
{
  SetPC (GetPC () + (RiscvDec::GetInstLength(inst_id) / 8));
}


/*!
 * Read from General Register
 * \param reg register address to read
 */
template <class T>
T RiscvPeThread::ReadGReg (RegAddr_t reg)
{
  if (reg == 0) {
	return 0x0;
  } else {
	T value = m_regs[reg];
    if (IsDebugTrace() == true) {
      GetTrace()->RecordTrace (TraceType::GRegRead, reg, value);
    }
	return value;
  }
}


/*!
 * Write Data General Register
 * \param reg  register address to write
 * \param daat write data
 * \param env  RISC-V environment
 */
template <class T>
void RiscvPeThread::WriteGReg (RegAddr_t reg, T data)
{
  if (reg != 0x00) {
    if (IsDebugTrace() == true) {
      GetTrace()->RecordTrace (TraceType::GRegWrite, reg, data);
    }
    m_regs[reg] = data;
  }
}


/*!
 * Read from System Register
 * \param reg register address to read
 * \param env RISC-V environment
 */
template <typename Xlen_t>
Xlen_t RiscvPeThread::CSRRead (Addr_t csr_addr, Xlen_t *data, PrivMode mode)
{
  Xlen_t csr_status = m_csr_env->Riscv_Read_CSR<Xlen_t> (csr_addr, data, mode);
  if (csr_status == 0) {
    if (IsDebugTrace() == true) {
      GetTrace()->RecordTrace (TraceType::CsrRead, csr_addr, *data);
    }
  }

  return csr_status;
}


/*!
 * Read from System Register
 * \param reg register address to read
 * \param env RISC-V environment
 */
template <typename Xlen_t>
Xlen_t RiscvPeThread::CSRRead (Addr_t csr_addr, Xlen_t *data)
{
  Xlen_t csr_status = m_csr_env->Riscv_Read_CSR<Xlen_t> (csr_addr, data, GetPrivMode());
  if (csr_status == 0) {
    if (IsDebugTrace() == true) {
      GetTrace()->RecordTrace (TraceType::CsrRead, csr_addr, *data);
    }
  }

  return csr_status;
}


/*!
 * Read from System Register
 * \param reg register address to read
 * \param env RISC-V environment
 */
template <typename Xlen_t>
Xlen_t RiscvPeThread::CSRReadNoTrace (Addr_t csr_addr, Xlen_t *data)
{
  Xlen_t csr_status = m_csr_env->Riscv_Read_CSR<Xlen_t> (csr_addr, data, GetPrivMode());

  return csr_status;
}


/*!
 * Read from System Register
 * \param reg register address to read
 * \param env RISC-V environment
 */
template <typename Xlen_t>
Xlen_t RiscvPeThread::CSRReadNoTrace (Addr_t csr_addr, Xlen_t *data, PrivMode mode)
{
  Xlen_t csr_status = m_csr_env->Riscv_Read_CSR<Xlen_t> (csr_addr, data, mode);

  return csr_status;
}


/*!
 * Write Data System Register
 * \param reg  register address to write
 * \param daat write data
 * \param env  RISC-V environment
 * \return result
 * \retval -1 can't be written due to CSR specification
 * \retval otherwise can be written
 */
template <typename Xlen_t>
Xlen_t RiscvPeThread::CSRWrite (Addr_t csr_addr, Xlen_t data)
{
  if (m_csr_env->Riscv_Write_CSR<Xlen_t> (csr_addr, data, GetPrivMode()) != 0) {
    return -1;
  }
  if (IsDebugTrace() == true) {
    GetTrace()->RecordTrace (TraceType::CsrWrite, csr_addr, data);
  }
  return 0;
}


/*!
 * Write Data System Register
 * \param reg  register address to write
 * \param daat write data
 * \param env  RISC-V environment
 * \return result
 * \retval -1 can't be written due to CSR specification
 * \retval otherwise can be written
 */
template <typename Xlen_t>
Xlen_t RiscvPeThread::CSRWrite (Addr_t csr_addr, Xlen_t data, PrivMode mode)
{
  if (m_csr_env->Riscv_Write_CSR<Xlen_t> (csr_addr, data, mode) != 0) {
    return -1;
  }
  if (IsDebugTrace() == true) {
    GetTrace()->RecordTrace (TraceType::CsrWrite, csr_addr, data);
  }
  return 0;
}


/*!
 * Read from Floating Point Register
 */
template <class T>
T RiscvPeThread::ReadFReg (RegAddr_t reg)
{
  T value = m_fregs[reg];

  if (IsDebugTrace() == true) {
    GetTrace()->RecordTrace (TraceType::FRegRead, reg, value);
  }
  return value;
}


/*!
 * Write Data into Floating Point Register
 * \param reg  register address to write
 * \param daat write data
 */
template <class T>
void RiscvPeThread::WriteFReg (RegAddr_t reg, T data)
{
  if (IsDebugTrace() == true) {
    GetTrace()->RecordTrace (TraceType::FRegWrite, reg, data);
  }
  DirtyFS ();
  m_fregs[reg] = data;
}


template <class T>
T RiscvPeThread::GetFReg (RegAddr_t reg_addr)
{
  if (reg_addr < 32) {
    return m_fregs[reg_addr];
  } else {
    return 0;
  }
}


template <typename AccType>
MemResult RiscvPeThread::LoadFromBus (Addr_t addr, AccType *data)
{
  MemResult result = MemResult::MemNoExcept;

  UpdateL1Dcache (addr);

  Addr_t paddr;
  MemResult mem_result;
  if ((mem_result = ConvertVirtualAddress (&paddr, addr, MemAccType::ReadMemType)) != MemResult::MemNoExcept) {
    return mem_result;
  }

  if (m_tohost_en && (paddr == m_tohost_addr)) {
    DebugPrint("<Info: Load From ToHost %016" PRIx64 ">\n", m_tohost_addr);
    DWord_t tohost;
    LoadFrom_ToHost (&tohost);
    *data = static_cast<AccType>(tohost);
    return MemResult::MemNoExcept;
  }

  if (m_fromhost_en && (paddr == m_fromhost_addr)) {
    DebugPrint("<Info: Load From FromHost %016" PRIx64 ">\n", m_tohost_addr);
    DWord_t fromhost;
    LoadFrom_FromHost (&fromhost);
    *data = static_cast<AccType>(fromhost);
    return MemResult::MemNoExcept;
  }

  for (const auto &device : m_mm_device_list) {
    if (paddr >= device->GetBaseAddr() && paddr <= device->GetBaseAddr() + device->GetSize()) {
      Byte_t *byte_data = new Byte_t[sizeof(AccType)];
      result = device->Load (paddr - device->GetBaseAddr(), sizeof(AccType), byte_data);
      memcpy (data, byte_data, sizeof(AccType));
      return result;
    }
  }

  result = LoadMemory<AccType> (paddr, data);

  return result;
}


template <typename AccType>
MemResult RiscvPeThread::LoadFromBusDebug (Addr_t addr, AccType *data)
{
  MemResult result;
  Addr_t paddr;
  MemResult mem_result;

  if ((mem_result = ConvertVirtualAddress (&paddr, addr, MemAccType::ReadMemType)) != MemResult::MemNoExcept) {
    return mem_result;
  }
  result = LoadMemoryDebug (paddr, data);
  return result;
}


template <typename AccType>
MemResult RiscvPeThread::StoreToBus (Addr_t addr, AccType data)
{
  Addr_t paddr;

  MemResult mem_result = ConvertVirtualAddress (&paddr, addr, MemAccType::WriteMemType);
  if (mem_result != MemResult::MemNoExcept) {
    return mem_result;
  }

  if (m_tohost_en && (paddr == m_tohost_addr)) {
    DWord_t conv_data = data;
    if (m_en_stop_host) {
      SetStopSim (true); // if TOHOST is hit, ready to stop simulation
      SetResult (conv_data);
    } else {
      DebugPrint("<Info: Store To ToHost %016" PRIx64 ", DEV=%02x, CMD=%02x, PAYLOAD=%010" PRIx64 ">\n",
                 m_tohost_addr, (conv_data >> 56) & 0x0ff, (conv_data >> 48) & 0x0ff, conv_data & 0x0ffffffffffULL);
      StoreTo_ToHost (conv_data);
    }
  }

  if (m_fromhost_en && (paddr == m_fromhost_addr)) {
    DWord_t conv_data = data;
    if (m_en_stop_host) {
      SetStopSim (true); // if FROMHOST is hit, ready to stop simulation
      SetResult (conv_data);
    } else {
      StoreTo_FromHost (conv_data);
      DebugPrint("<Info: Store To FromHost %016" PRIx64 ", DEV=%02x, CMD=%02x, PAYLOAD=%010" PRIx64 ">\n",
                 m_tohost_addr, (conv_data >> 56) & 0x0ff, (conv_data >> 48) & 0x0ff, conv_data & 0x0ffffffffffULL);
    }
  }

  for (const auto &device : m_mm_device_list) {
    if (paddr >= device->GetBaseAddr() && paddr <= device->GetBaseAddr() + device->GetSize()) {
      Byte_t *byte_data = new Byte_t[sizeof(AccType)];
      memcpy (byte_data, &data, sizeof(AccType));
      MemResult result = device->Store (paddr - device->GetBaseAddr(), sizeof(AccType), byte_data);
      return result;
    }
  }

  UpdateL1Dcache (addr);
  return StoreMemory<AccType> (paddr, &data);
}


Addr_t RiscvPeThread::GetTraceDstAddr ()
{
  uint32_t trace_count;

  for (trace_count = 0; trace_count < GetTrace()->GetMax (); trace_count ++) {
    uint64_t trace_addr  = GetTrace()->GetTraceAddr (trace_count);

    if (GetTrace()->GetTraceType(trace_count) == TraceType::GRegWrite) {
      if (trace_addr != REG_PC) {
        return trace_addr;
      }
    }
  }
  return static_cast<Addr_t>(-1);
}


void RiscvPeThread::PrintOperand (std::stringstream *operand_str)
{
  uint32_t trace_count;

  uint64_t greg_xlen_mask = (m_bit_mode == RiscvBitMode_t::Bit32) ? 0x00FFFFFFFFULL : 0xFFFFFFFFFFFFFFFFULL;
  uint32_t greg_xlen_byte = (m_bit_mode == RiscvBitMode_t::Bit32) ? 8 : 16;

  for (trace_count = 0; trace_count < GetTrace()->GetMax (); trace_count ++) {
    uint64_t trace_value = GetTrace()->GetTraceValue (trace_count);
    uint64_t trace_addr  = GetTrace()->GetTraceAddr  (trace_count) & greg_xlen_mask;

    switch (GetTrace()->GetTraceType(trace_count)) {
    case TraceType::GRegWrite :
      if (trace_addr == REG_PC) {
        (*operand_str) << "pc<=" << std::hex << std::setw(16) << std::setfill('0') << trace_value << " ";
      } else {
        RegAddr_t reg_addr = trace_addr;
        if (GetPrintRegStyle () == AbiRegType::AbiRegHardName) {
          (*operand_str) << "r"  << std::dec << std::setw(2) << std::setfill('0') << static_cast<uint32_t>(reg_addr);
        } else {
          (*operand_str) << m_abi_regs[reg_addr];
        }
        (*operand_str) << "<=" << std::hex << std::setw(greg_xlen_byte) << std::setfill('0') << (trace_value & greg_xlen_mask) << " ";
      }
      break;
    case TraceType::FRegWrite : {
      RegAddr_t reg_addr = trace_addr;
      (*operand_str) << "f"  << std::dec << std::setw(2) << std::setfill('0') << static_cast<uint32_t>(reg_addr);
      (*operand_str) << "<=" << std::hex << std::setw(16) << std::setfill('0') << trace_value << " ";
      break;
    }
    case TraceType::GRegRead : {
      RegAddr_t reg_addr = trace_addr;
      if (GetPrintRegStyle () == AbiRegType::AbiRegHardName) {
        (*operand_str) << "r"  << std::dec << std::setw(2) << std::setfill('0') << static_cast<uint32_t>(reg_addr);
      } else {
        (*operand_str) << m_abi_regs[reg_addr];
      }
      (*operand_str) << "=>" << std::hex << std::setw(greg_xlen_byte) << std::setfill('0') << (trace_value & greg_xlen_mask) << ' ';
      break;
    }
    case TraceType::FRegRead : {
      RegAddr_t reg_addr = trace_addr;
      (*operand_str) << "f"  << std::dec << std::setw(2) << std::setfill('0') << static_cast<uint32_t>(reg_addr);
      (*operand_str) << "=>" << std::hex << std::setw(16) << std::setfill('0') << trace_value << ' ';
      break;
    }
    case TraceType::MemWrite : {
      (*operand_str) << "("  << std::hex << std::setw(16) << std::setfill('0') << trace_addr << ")"
                     << "<=" << std::hex << std::setw(16) << std::setfill('0') << trace_value << " ";
      break;
    }
    case TraceType::MemRead : {
      (*operand_str) << "("  << std::hex << std::setw(16) << std::setfill('0') << trace_addr << ")"
                     << "=>" << std::hex << std::setw(16) << std::setfill('0') << trace_value << " ";
      break;
    }
    case TraceType::CsrWrite : {
      std::string csr_name = m_csr_env->GetCSRName (trace_addr);
      (*operand_str) << csr_name << "<=" << std::hex << std::setw(16) << std::setfill('0') <<
        trace_value << " ";
      break;
    }
    case TraceType::CsrRead : {
      std::string csr_name = m_csr_env->GetCSRName (trace_addr);
      (*operand_str) << csr_name << "=>" << std::hex << std::setw(16) << std::setfill('0')
                     << trace_value << " ";
      break;
    }
      case TraceType::XRegWrite :
      case TraceType::XRegRead  :
      case TraceType::DRegWrite :
      case TraceType::DRegRead  :
      case TraceType::LrRead    :
      case TraceType::LrWrite   :
      case TraceType::SrRead    :
      case TraceType::SrWrite   :
      case TraceType::IlrRead   :
      case TraceType::IlrWrite  :
      case TraceType::CyRead    :
      case TraceType::CyWrite   : {
        (*operand_str) << "<Internal Error: This type of Trace is not supported in RISC-V Architecture\n>\n";
        break;
      }
    }
  }
}


void RiscvPeThread::PushPrivMode (PrivMode priv)
{
  // UDWord_t curr_mstatus;
  // CSRRead (SYSREG_ADDR_MSTATUS, &curr_mstatus);
  // UDWord_t next_mstatus = ((curr_mstatus << 3) | (static_cast<UDWord_t>(priv) << 1)) & 0xffff;
  // next_mstatus = next_mstatus | (curr_mstatus & 0xffff0000);
  // CSRWrite (SYSREG_ADDR_MSTATUS, next_mstatus);
}


template <typename Xlen_t>
void RiscvPeThread::GenerateException (ExceptCode code, Xlen_t tval)
{
  FlushTlb();

  if (code != ExceptCode::Except_IllegalInst &&
      code != ExceptCode::Except_EcallFromSMode) {
    Addr_t paddr;
    ConvertVirtualAddress (&paddr, GetPC(), MemAccType::ReadMemType);
    DebugPrint ("<Info: GenerateException Code=%d, TVAL=%016lx PC=%016lx,%016lx>\n", code, tval, GetPC(), paddr);
  }

  Addr_t epc;
  if (code == ExceptCode::Except_InstAddrMisalign) {
    epc = GetPreviousPC ();
  } else {
    epc = GetPC ();
  }

  PrivMode curr_priv = GetPrivMode ();

  UDWord_t medeleg;
  UDWord_t mstatus, sstatus;
  Addr_t tvec;
  CSRRead (SYSREG_ADDR_MEDELEG, &medeleg);
  PrivMode next_priv = PrivMode::PrivMachine;
  SetPrivMode (next_priv);
  if (medeleg & (1 << static_cast<UDWord_t>(code))) {
    // Delegation
    CSRWrite (SYSREG_ADDR_SEPC,   epc);
    CSRWrite (SYSREG_ADDR_SCAUSE, static_cast<UDWord_t>(code));
    CSRWrite (SYSREG_ADDR_STVAL,  tval);

    CSRRead  (SYSREG_ADDR_STVEC, &tvec);
    next_priv = PrivMode::PrivSupervisor;
  } else {
    CSRWrite (SYSREG_ADDR_MEPC,   epc);
    CSRWrite (SYSREG_ADDR_MCAUSE, static_cast<UDWord_t>(code));
    CSRWrite (SYSREG_ADDR_MTVAL,  tval);

    CSRRead  (SYSREG_ADDR_MTVEC, &tvec);
  }

  // Update status CSR
  if (medeleg & (1 << static_cast<UDWord_t>(code))) {
    // Delegation
    CSRRead  (SYSREG_ADDR_SSTATUS, &sstatus);
    sstatus = SetBitField(sstatus, ExtractBitField(sstatus, SYSREG_SSTATUS_SIE_MSB, SYSREG_SSTATUS_SIE_LSB),
                          SYSREG_SSTATUS_SPIE_MSB, SYSREG_SSTATUS_SPIE_LSB);
    sstatus = SetBitField(sstatus, static_cast<uint64_t>(curr_priv), SYSREG_SSTATUS_SPP_MSB, SYSREG_SSTATUS_SPP_LSB);
    sstatus = SetBitField(sstatus, 0, SYSREG_SSTATUS_SIE_MSB, SYSREG_SSTATUS_SIE_LSB);
    CSRWrite (SYSREG_ADDR_SSTATUS, sstatus);
  } else {
    CSRRead  (SYSREG_ADDR_MSTATUS, &mstatus);

    mstatus = SetBitField(mstatus, ExtractBitField(mstatus, SYSREG_MSTATUS_MIE_MSB, SYSREG_MSTATUS_MIE_LSB),
                          SYSREG_MSTATUS_MPIE_MSB, SYSREG_MSTATUS_MPIE_LSB);
    mstatus = SetBitField(mstatus, static_cast<uint64_t>(curr_priv), SYSREG_MSTATUS_MPP_MSB, SYSREG_MSTATUS_MPP_LSB);
    mstatus = SetBitField(mstatus, 0, SYSREG_MSTATUS_MIE_MSB, SYSREG_MSTATUS_MIE_LSB);

    CSRWrite (SYSREG_ADDR_MSTATUS, mstatus);
  }

  if (m_bit_mode == RiscvBitMode_t::Bit32) {
    tvec = tvec & 0xffffffffULL;
  }

  SetPrivMode (next_priv);

  SetPC (tvec);
  SetJumped (true);

  DebugPrint ("<Info: Exception. ChangeMode from %s to %s>\n",
              PrintPrivMode(curr_priv).c_str(),
              PrintPrivMode(next_priv).c_str());
  DebugPrint ("<Info: Set Program Counter = 0x%08x%08x>\n", tvec >> 32, tvec);

  // Relesae Load Reservation
  ClearLoadReservation ();

  // CountUp Timer
  m_riscv_clint->Increment(INTERLEAVE / INSNS_PER_RTC_TICK);
  m_count_timer = 0;

  return;
}


bool RiscvPeThread::CheckInterrupt (IntCode *ret_intcode)
{
  UDWord_t mie, mip, mstatus, mideleg;
  CSRReadNoTrace(SYSREG_ADDR_MIE,     &mie,     PrivMode::PrivMachine);
  CSRReadNoTrace(SYSREG_ADDR_MIP,     &mip,     PrivMode::PrivMachine);
  CSRReadNoTrace(SYSREG_ADDR_MSTATUS, &mstatus, PrivMode::PrivMachine);
  CSRReadNoTrace(SYSREG_ADDR_MIDELEG, &mideleg, PrivMode::PrivMachine);

  UDWord_t pending_interrupts = mip & mie;
  PrivMode curr_priv = GetPrivMode ();

  UDWord_t mstatus_mie = ExtractBitField (mstatus, SYSREG_MSTATUS_MIE_MSB, SYSREG_MSTATUS_MIE_LSB);
  UDWord_t m_enabled = IsCpuWaitMode() || (curr_priv < PrivMode::PrivMachine) || (curr_priv == PrivMode::PrivMachine && mstatus_mie);
  UDWord_t enabled_interrupts = pending_interrupts & ~mideleg & -m_enabled;

  UDWord_t mstatus_sie = ExtractBitField (mstatus, SYSREG_MSTATUS_SIE_MSB, SYSREG_MSTATUS_SIE_LSB);
  UDWord_t s_enabled = IsCpuWaitMode() || (curr_priv < PrivMode::PrivSupervisor) || (curr_priv == PrivMode::PrivSupervisor && mstatus_sie);

  // if (mip != 0) {
  //   DebugPrint ("<Info: Pending Interrupt MIP=%016lx MSTATUS=%016lx MIE=%016lx MIDELEG=%016lx>\n",
  //               mip, mstatus, mie, mideleg);
  // }

  // M-ints have highest priority; consider S-ints only if no M-ints pending
  if (enabled_interrupts == 0) {
    enabled_interrupts = pending_interrupts & mideleg & -s_enabled;
  }

  if (enabled_interrupts) {
    // SetDebugTrace (true);
    // DebugPrint ("<Info: EnableInterrupt Asserted %016lx mstatus=%016lx>\n", enabled_interrupts, mstatus);
    // InfoPrint  ("<Info: EnableInterrupt Asserted %016lx mstatus=%016lx>\n", enabled_interrupts, mstatus);
    if (IsCpuWaitMode ()) { SetCpuWaitMode(false); }

    if (enabled_interrupts & (1 << IntCode::MachineExternal)) {
      // nonstandard interrupts have highest priority
      *ret_intcode = IntCode::MachineExternal;
      return true;
    } else if (enabled_interrupts & (1 << IntCode::SuperExternal)) {
      // external interrupts have next-highest priority
      *ret_intcode = IntCode::SuperExternal;
      return true;
    } else if (enabled_interrupts & (1 << IntCode::MachineSoftware)) {
      *ret_intcode = IntCode::MachineSoftware;
      return true;
    } else if (enabled_interrupts & (1 << IntCode::SuperSoftware)) {
      // software interrupts have next-highest priority
      *ret_intcode = IntCode::SuperSoftware;
      return true;
    } else if (enabled_interrupts & (1 << IntCode::MachineTimer)) {
      // timer interrupts have next-highest priority
      *ret_intcode = IntCode::MachineTimer;
      return true;
    } else if (enabled_interrupts & (1 << IntCode::SuperTimer)) {
      *ret_intcode = IntCode::SuperTimer;
      return true;
    } else {
      DebugPrint("<Error: Ilegal Interrupt %08x>\n", enabled_interrupts);
      return false;
    }
  } else {
    return false;
  }
}


void RiscvPeThread::GenerateInterrupt (IntCode code)
{
  FlushTlb();

  DebugPrint ("<Info: Generate Interrupt Code = %d>\n", static_cast<int>(code));

  PrivMode curr_priv = GetPrivMode ();

  Addr_t   epc = GetPC ();
  UDWord_t mideleg;
  UDWord_t mstatus, sstatus;
  Addr_t tvec;
  CSRRead (SYSREG_ADDR_MIDELEG, &mideleg);
  PrivMode next_priv = PrivMode::PrivMachine;
  SetPrivMode (next_priv);
  if (curr_priv <= PrivMode::PrivSupervisor && (mideleg & (1 << static_cast<UDWord_t>(code)))) {
    // Delegation
    CSRWrite (SYSREG_ADDR_SEPC,   epc);
    if (m_bit_mode == RiscvBitMode_t::Bit64) {
      UDWord_t int_code = 0x8000000000000000ULL | static_cast<UDWord_t>(code);
      CSRWrite (SYSREG_ADDR_SCAUSE, int_code);
    } else {
      UDWord_t int_code = 0x80000000ULL         | static_cast<UDWord_t>(code);
      CSRWrite (SYSREG_ADDR_SCAUSE, int_code);
    }
    CSRWrite (SYSREG_ADDR_STVAL,  static_cast<UDWord_t>(0x0));
    CSRRead  (SYSREG_ADDR_STVEC, &tvec);
    next_priv = PrivMode::PrivSupervisor;
  } else {
    CSRWrite (SYSREG_ADDR_MEPC,   epc);
    if (m_bit_mode == RiscvBitMode_t::Bit64) {
      UDWord_t int_code = 0x8000000000000000ULL | static_cast<UDWord_t>(code);
      CSRWrite (SYSREG_ADDR_MCAUSE, int_code);
    } else {
      UDWord_t int_code = 0x80000000ULL         | static_cast<UDWord_t>(code);
      CSRWrite (SYSREG_ADDR_MCAUSE, int_code);
    }
    CSRWrite (SYSREG_ADDR_MTVAL, static_cast<UDWord_t>(0x0));
    CSRRead  (SYSREG_ADDR_MTVEC, &tvec);
  }

  // Update status CSR
  if (mideleg & (1 << static_cast<UDWord_t>(code))) {
    // Delegation
    CSRRead  (SYSREG_ADDR_SSTATUS, &sstatus);
    sstatus = SetBitField(sstatus, ExtractBitField(sstatus, SYSREG_SSTATUS_SIE_MSB, SYSREG_SSTATUS_SIE_LSB),
                          SYSREG_SSTATUS_SPIE_MSB, SYSREG_SSTATUS_SPIE_LSB);
    sstatus = SetBitField(sstatus, static_cast<uint64_t>(curr_priv), SYSREG_SSTATUS_SPP_MSB, SYSREG_SSTATUS_SPP_LSB);
    sstatus = SetBitField(sstatus, 0, SYSREG_SSTATUS_SIE_MSB, SYSREG_SSTATUS_SIE_LSB);

    CSRWrite (SYSREG_ADDR_SSTATUS, sstatus);
  } else {
    CSRRead  (SYSREG_ADDR_MSTATUS, &mstatus);

    mstatus = SetBitField(mstatus, ExtractBitField(mstatus, SYSREG_MSTATUS_MIE_MSB, SYSREG_MSTATUS_MIE_LSB),
                          SYSREG_MSTATUS_MPIE_MSB, SYSREG_MSTATUS_MPIE_LSB);
    mstatus = SetBitField(mstatus, static_cast<uint64_t>(curr_priv), SYSREG_MSTATUS_MPP_MSB, SYSREG_MSTATUS_MPP_LSB);
    mstatus = SetBitField(mstatus, 0, SYSREG_MSTATUS_MIE_MSB, SYSREG_MSTATUS_MIE_LSB);

    CSRWrite (SYSREG_ADDR_MSTATUS, mstatus);
  }

  if (m_bit_mode == RiscvBitMode_t::Bit32) {
    tvec = tvec & 0xffffffffULL;
  }

  SetPrivMode (next_priv);

  SetPC (tvec);
  SetJumped (true);

  DebugPrint ("<Info: Interrupt. ChangeMode from %s to %s>\n",
              PrintPrivMode(curr_priv).c_str(),
              PrintPrivMode(next_priv).c_str());
  DebugPrint ("<Info: Set Program Counter = 0x%08x%08x>\n", tvec >> 32, tvec);

  // Relesae Load Reservation
  ClearLoadReservation ();

  // CountUp Timer
  m_riscv_clint->Increment(INTERLEAVE / INSNS_PER_RTC_TICK);
  m_count_timer = 0;

  return;
}


MemResult RiscvPeThread::ConvertVirtualAddress (Addr_t *paddr, Addr_t vaddr, MemAccType acc_type)
{
  UDWord_t mstatus;
  CSRReadNoTrace(SYSREG_ADDR_MSTATUS, &mstatus, PrivMode::PrivMachine);
  uint8_t mprv = ExtractBitField (mstatus, SYSREG_MSTATUS_MPRV_MSB, SYSREG_MSTATUS_MPRV_LSB);
  PrivMode mpp  = static_cast<PrivMode>(ExtractBitField (mstatus, SYSREG_MSTATUS_MPP_MSB, SYSREG_MSTATUS_MPP_LSB));
  PrivMode priv_mode = (acc_type != MemAccType::FetchMemType && mprv) ? mpp : GetPrivMode();

  if (GetVmMode() == RiscvVmMode::Vm_Sv39 && (priv_mode == PrivMode::PrivSupervisor ||
                                              priv_mode == PrivMode::PrivUser)) {
    uint32_t ppn_idx[3] = {12, 21, 30};
    Addr_t   pte_len[3] = { 9,  9, 26};
    Addr_t   pte_idx[3] = {10, 19, 28};
    Addr_t   vpn_len[3] = { 9,  9,  9};
    uint32_t vpn_idx[3] = {12, 21, 30};
    const int PAGESIZE = std::pow(2, 12);
    const int PTESIZE  = 8;
    return WalkPageTable (paddr, vaddr, acc_type,
                          3, ppn_idx,
                          pte_len, pte_idx,
                          vpn_len, vpn_idx,
                          PAGESIZE, PTESIZE);
  } else if (GetVmMode() == RiscvVmMode::Vm_Sv32 && (priv_mode == PrivMode::PrivSupervisor ||
                                                     priv_mode == PrivMode::PrivUser)) {
    uint32_t ppn_idx[2] = {12, 22};
    Addr_t   pte_len[2] = {10, 12};
    Addr_t   pte_idx[2] = {10, 20};
    Addr_t   vpn_len[2] = {10, 10};
    uint32_t vpn_idx[2] = {12, 22};
    const int PAGESIZE = std::pow(2, 12);
    const int PTESIZE  = 4;

    return WalkPageTable (paddr, vaddr, acc_type,
                          2, ppn_idx,
                          pte_len, pte_idx,
                          vpn_len, vpn_idx,
                          PAGESIZE, PTESIZE);
  } else {
    *paddr = vaddr;
    return MemResult::MemNoExcept;
  }
}

MemResult RiscvPeThread::WalkPageTable (Addr_t *paddr, Addr_t vaddr, MemAccType acc_type,
                                        uint32_t init_level, uint32_t *ppn_idx,
                                        Addr_t   *pte_len, Addr_t   *pte_idx,
                                        Addr_t   *vpn_len, uint32_t *vpn_idx,
                                        const int PAGESIZE, const int PTESIZE)
{
  //===================
  // Simple TLB Search
  //===================
  Addr_t  vaddr_vpn = (vaddr >> 12);
  uint8_t vaddr_tag = vaddr_vpn & (tlb_width-1);
  if (m_tlb_en[vaddr_tag] && m_tlb_tag[vaddr_tag] == vaddr_vpn) {
    *paddr = (m_tlb_addr[vaddr_tag] & ~0x0fff) + (vaddr & 0x0fff);
    UDWord_t pte_val = m_tlb_addr[vaddr_tag] & 0x0ff;

    if (!IsAllowedAccess ((pte_val >> 1) & 0x0f, acc_type, GetPrivMode())) {
      DebugPrint ("<Page Access Failed. Allowed Access Failed PTE_VAL=%016lx>\n", pte_val);
      return MemResult::MemTlbError;
    }
    if (((pte_val & 0x40) == 0) || // PTE.A
        ((acc_type == MemAccType::WriteMemType) && (pte_val & 0x80) == 0)) { // PTE.D
      std::stringstream str;
      str << "<Access Fault : Page Permission Fault " << ((pte_val >> 1) & 0x0f) << ">\n";
      DebugPrint ("%s", str.str().c_str());
      if (acc_type == MemAccType::FetchMemType) {
        GenerateException (ExceptCode::Except_InstPageFault, vaddr);
      }
      return MemResult::MemTlbError;
    }
    return MemResult::MemNoExcept;
  }

  Addr_t  phy_addr = vaddr & 0x0fff;

  UDWord_t sptbr;
  CSRReadNoTrace (SYSREG_ADDR_SATP, &sptbr);
  UDWord_t pte_base = ExtractSptbrPpnField(sptbr);

  UDWord_t pte_val;
  Addr_t   pte_addr = pte_base * PAGESIZE;
  int level = init_level-1;

  // DebugPrint ("<Info: SATP=%016lx>\n", sptbr);

  for (; level >= 0; level--) {
    // bool is_leaf_achieve = false;
    Addr_t va_vpn_i = (vaddr >> vpn_idx[level]) & ((1 << vpn_len[level]) - 1);
    pte_addr += (va_vpn_i * PTESIZE);

    if (m_bit_mode == RiscvBitMode_t::Bit64) {
      LoadMemoryDebug<UDWord_t> (pte_addr, &pte_val);
    } else {
      pte_addr &= 0x0FFFFFFFFULL;
      Word_t pte_val_word;
      LoadMemoryDebug<Word_t> (pte_addr, &pte_val_word);
      pte_val = pte_val_word;
    }

    DebugPrint ("<Info: VAddr = 0x%016lx PTEAddr = 0x%016x : PPTE = 0x%016x>\n", vaddr, pte_addr, pte_val);

    // 3. If pte:v = 0, or if pte:r = 0 and pte:w = 1, stop and raise a page-fault exception.
    if ((pte_val & 0x01) == 0 ||
        (((pte_val & 0x02) == 0) && ((pte_val & 0x04) == 0x04))) {
      {
        uint32_t bit_length  = m_bit_mode == RiscvBitMode_t::Bit32 ? 8 : 16;
        std::stringstream str;
        str << "<Page Table Error : "
            << std::hex << std::setw(16) << std::setfill('0') << pte_addr << " = "
            << std::hex << std::setw(bit_length) << std::setfill('0') << pte_val
            << " is not valid Page Table. Generate Exception>\n";
        DebugPrint ("%s", str.str().c_str());
      }
      if (acc_type == MemAccType::FetchMemType) {
        GenerateException (ExceptCode::Except_InstPageFault, vaddr);
      }
      return MemResult::MemTlbError;
    }

    // If pte:r = 1 or pte:x = 1, go to step 5. Otherwise, this PTE is a
    // pointer to the next level of the page table. Let i = i − 1. If i < 0, stop and raise a page-fault
    // exception. Otherwise, let a = pte:ppn × PAGESIZE and go to step 2.
    if (((pte_val & 0x08) == 0x08) || ((pte_val & 0x02) == 0x02)) {
      break;
    } else {
      if (level == 0) {
        std::stringstream str;
        str << "<Access Fault : Tried to Access to Page " << ((pte_val >> 1) & 0x0f) << '\n';
        DebugPrint ("%s", str.str().c_str());
        if (acc_type == MemAccType::FetchMemType) {
          GenerateException (ExceptCode::Except_InstPageFault, vaddr);
        }
        return MemResult::MemTlbError;
      }
    }
    Addr_t pte_ppn = ExtractBitField (pte_val, pte_len[init_level-1] + pte_idx[init_level-1] - 1, pte_idx[0]);
    pte_addr  = pte_ppn * PAGESIZE;
    // if (is_leaf_achieve) break;
  }

  if (!IsAllowedAccess ((pte_val >> 1) & 0x0f, acc_type, GetPrivMode())) {
    DebugPrint ("<Page Access Failed. Allowed Access Failed PTE_VAL=%016lx>\n", pte_val);
    return MemResult::MemTlbError;
  }

  if (level != 0 && ExtractBitField (pte_val, pte_len[level-1]+pte_idx[level-1]-1, pte_idx[0]) != 0) {
    // 6. If i > 0 and pa:ppn[i−1:0] != 0, this is a misaligned superpage
    // stop and raise a page-fault exception.
    // DebugPrint ("<Page Access Failed. Last PTE != 0>\n");
    return MemResult::MemTlbError;
  }

  if (((pte_val & 0x40) == 0) || // PTE.A
      ((acc_type == MemAccType::WriteMemType) && (pte_val & 0x80) == 0)) { // PTE.D
    std::stringstream str;
    str << "<Access Fault : Page Permission Fault " << ((pte_val >> 1) & 0x0f) << ">\n";
    DebugPrint ("%s", str.str().c_str());
    if (acc_type == MemAccType::FetchMemType) {
      GenerateException (ExceptCode::Except_InstPageFault, vaddr);
    }
    return MemResult::MemTlbError;
  }

  phy_addr = ExtractBitField (pte_val, pte_len[init_level-1] + pte_idx[init_level-1] - 1, pte_idx[level]) << ppn_idx[level];
  for (level = level-1; level >= 0; level--) {
    Addr_t vaddr_vpn = ExtractBitField(vaddr, vpn_len[level] + vpn_idx[level] - 1, vpn_idx[level]);
    phy_addr |= (vaddr_vpn << ppn_idx[level]);
  }

  // Finally Add Page Offset
  phy_addr |= ExtractBitField(vaddr, vpn_idx[0] - 1, 0);

  *paddr = phy_addr;

  //==========================
  // Update Simple TLB Search
  //==========================
  DebugPrint("<Info: TLB[%d] <= 0x%016lx(0x%016lx)>\n", vaddr_tag, vaddr_vpn, *paddr & ~0x0fff);
  m_tlb_en  [vaddr_tag] = true;
  m_tlb_tag [vaddr_tag] = vaddr_vpn;
  m_tlb_addr[vaddr_tag] = (*paddr & ~0x0fff) | (pte_val & 0x0ff);

  DebugPrint("Converted Virtual Address is = 0x%016lx\n", *paddr);

  return MemResult::MemNoExcept;
}


bool RiscvPeThread::IsAllowedAccess (uint8_t type, MemAccType acc_type, PrivMode priv_mode)
{
  if ((priv_mode == PrivMode::PrivUser) && !(type & 0x08)) {
    return false;
  }
  switch (acc_type) {
    case MemAccType::FetchMemType : return ((type & 0x04) != 0);
    case MemAccType::WriteMemType : return ((type & 0x01) != 0) && ((type & 0x02) != 0);
    case MemAccType::ReadMemType  : {
      UDWord_t mstatus;
      CSRReadNoTrace (SYSREG_ADDR_MSTATUS, &mstatus, PrivMode::PrivMachine);
      uint8_t mxr = ExtractBitField (mstatus, SYSREG_MSTATUS_MXR_MSB, SYSREG_MSTATUS_MXR_LSB);
      return ((type & 0x01) != 0) | ((mxr & (type & 0x04)) != 0);
    }
  }
  return false;
}


RiscvVmMode RiscvPeThread::GetVmMode (void)
{
  DWord_t satp_val;
  CSRReadNoTrace (SYSREG_ADDR_SATP, &satp_val);
  if (m_bit_mode == RiscvBitMode_t::Bit32) {
    uint32_t mode = ExtractBitField(satp_val, SYSREG_SATP_MODE_MSB, SYSREG_SATP_MODE_LSB);
    return mode ? RiscvVmMode::Vm_Sv32 : RiscvVmMode::Vm_Mbare;
  } else {
    return static_cast<RiscvVmMode>(ExtractBitField(satp_val, SYSREG_SATP_MODE_MSB, SYSREG_SATP_MODE_LSB));
  }
}


void RiscvPeThread::SetImgFileName (std::string img_filename)
{
  m_ide->SetImgFileName (img_filename);

  return;
}


void RiscvPeThread::HandleCommand (void)
{
  DWord_t tohost;
  LoadFrom_ToHost (&tohost);
  if (tohost != 0) {
    DebugPrint("<Info: HandleCommand %016" PRIx64 ">\n", tohost);
    m_device_list->HandleCommand (tohost);
  }
  StoreTo_ToHost (0x0);
}


void RiscvPeThread::CountUpTimer (void)
{
  // static const size_t CPU_HZ = 1000000000; // 1GHz CPU
  // uint64_t step = GetStep();

  if (m_count_timer == 5000) {
    ClearLoadReservation ();
    m_riscv_clint->Increment(INTERLEAVE / INSNS_PER_RTC_TICK);

    m_device_list->Tick();
  }
}


void RiscvPeThread::OutputSignature()
{
  FILE *fp;
  if ((fp = fopen(m_sig_filename.c_str(), "w")) == NULL) {
    ErrorPrint ("<Error: couldn't open signature file %s>\n", m_sig_filename.c_str());
    return;
  }
  for (Addr_t addr = m_sig_addr_start; addr <= ((m_sig_addr_end-1) | 0xf); addr += 0x10) {
    for (Addr_t b_addr = addr + 0xf; b_addr >= addr; b_addr--) {
      UByte_t b_data;
      LoadMemoryDebug<UByte_t> (b_addr, &b_data);
      fprintf (fp, "%02x", b_data);
    }
    fprintf (fp, "\n");
  }
  fclose(fp);
}


void RiscvPeThread::UpdateL1Icache (Addr_t addr)
{
#ifdef NEVER
  if (FLAGS_sim_l1i) {
    Addr_t l1i_addr      = MaskL1IAddr (addr);
    Addr_t l1i_entry_idx = MaskL1IIndex (addr);
    if (!m_icache_en[l1i_entry_idx]) {   // L1I corresponding entry is empty
      m_icache_addr[l1i_entry_idx] = l1i_addr;
      m_icache_en  [l1i_entry_idx] = true;
      DebugPrint ("[L1I:E:%08x,%03d]            ", l1i_addr, l1i_entry_idx);
    } else {
      if (m_icache_addr[l1i_entry_idx] == l1i_addr) {  // L1I corresponding entry is HIT
        DebugPrint ("[L1I:H:%08x,%03d]            ", l1i_addr, l1i_entry_idx);
      } else {   // L1I corresponding entry is MISS
        DebugPrint ("[L1I:R:%08x-->%08x,%03d] ", m_icache_addr[l1i_entry_idx], l1i_addr, l1i_entry_idx);
        m_icache_addr[l1i_entry_idx] = l1i_addr;
      }
    }
  }
#endif // NEVER
}


void RiscvPeThread::UpdateL1Dcache (Addr_t addr)
{
#ifdef NEVER
  if (FLAGS_sim_l1d) {
    Addr_t l1d_addr      = MaskL1DAddr (addr);
    Addr_t l1d_entry_idx = MaskL1DIndex (addr);
    if (!m_dcache_en[l1d_entry_idx]) {   // L1D corresponding entry is empty
      m_dcache_addr[l1d_entry_idx] = l1d_addr;
      m_dcache_en  [l1d_entry_idx] = true;
      DebugPrint ("[L1D:E:%08x,%03d]\n", l1d_addr, l1d_entry_idx);
    } else {
      if (m_dcache_addr[l1d_entry_idx] == l1d_addr) {  // L1D corresponding entry is HIT
        DebugPrint ("[L1D:H:%08x,%03d]\n", l1d_addr, l1d_entry_idx);
      } else {   // L1D corresponding entry is MISS
        DebugPrint ("[L1D:R:%08x-->%08x,%03d]\n", m_dcache_addr[l1d_entry_idx], l1d_addr, l1d_entry_idx);
        m_dcache_addr[l1d_entry_idx] = l1d_addr;
      }
    }
  }
#endif // NEVER
}


bool RiscvPeThread::IsBranchTaken (Addr_t addr)
{
#ifdef NEVER
  if (FLAGS_sim_pred) {
    Addr_t status_table_idx = PredStatusTableIndex (addr);
    BranchPredStatus status_bit = m_branch_status_table[status_table_idx];

    DebugPrint ("[BR:%04d:", status_table_idx);

    switch (status_bit) {
      case BranchPredStatus::TakenWeak:      DebugPrint ("TW");  break;
      case BranchPredStatus::TakenStrong:    DebugPrint ("TS");  break;
      case BranchPredStatus::NotTakenWeak:   DebugPrint ("NTW"); break;
      case BranchPredStatus::NotTakenStrong: DebugPrint ("NTS"); break;
    }

    DebugPrint ("]\n");

    if ((status_bit == BranchPredStatus::TakenWeak) || (status_bit == BranchPredStatus::TakenStrong)) {
      return true;
    } else {
      return false;
    }
  }
#endif // NEVER
  return false;
}


void RiscvPeThread::UpdateBranchPrediction (Addr_t addr, bool is_taken)
{
#ifdef NEVER
  if (FLAGS_sim_pred) {
    Addr_t status_table_idx = PredStatusTableIndex (addr);
    BranchPredStatus status_bit = m_branch_status_table[status_table_idx];

    switch (status_bit) {
      case BranchPredStatus::NotTakenWeak :
        if (is_taken) { status_bit = BranchPredStatus::NotTakenStrong; }
        else          { status_bit = BranchPredStatus::NotTakenWeak;   }
        break;
      case BranchPredStatus::NotTakenStrong :
        if (is_taken) { status_bit = BranchPredStatus::TakenWeak;      }
        else          { status_bit = BranchPredStatus::NotTakenStrong; }
        break;
      case BranchPredStatus::TakenWeak :
        if (is_taken) { status_bit = BranchPredStatus::TakenStrong;    }
        else          { status_bit = BranchPredStatus::NotTakenWeak;   }
        break;
      case BranchPredStatus::TakenStrong :
        if (is_taken) { status_bit = BranchPredStatus::TakenStrong;    }
        else          { status_bit = BranchPredStatus::TakenWeak;      }
        break;
      default:
        break;
    }
    m_branch_status_table[status_table_idx] = status_bit;
  }

  return;
#endif // NEVER
}


template Word_t   RiscvPeThread::ReadGReg (RegAddr_t reg);
template UWord_t  RiscvPeThread::ReadGReg (RegAddr_t reg);
template DWord_t  RiscvPeThread::ReadGReg (RegAddr_t reg);
template UDWord_t RiscvPeThread::ReadGReg (RegAddr_t reg);

template void RiscvPeThread::WriteGReg (RegAddr_t reg, Word_t   data);
template void RiscvPeThread::WriteGReg (RegAddr_t reg, UWord_t  data);
template void RiscvPeThread::WriteGReg (RegAddr_t reg, DWord_t  data);
template void RiscvPeThread::WriteGReg (RegAddr_t reg, UDWord_t data);

template Word_t   RiscvPeThread::ReadFReg (RegAddr_t reg);
template UWord_t  RiscvPeThread::ReadFReg (RegAddr_t reg);
template DWord_t  RiscvPeThread::ReadFReg (RegAddr_t reg);
template UDWord_t RiscvPeThread::ReadFReg (RegAddr_t reg);

template void RiscvPeThread::WriteFReg (RegAddr_t reg, Word_t   data);
template void RiscvPeThread::WriteFReg (RegAddr_t reg, UWord_t  data);
template void RiscvPeThread::WriteFReg (RegAddr_t reg, DWord_t  data);
template void RiscvPeThread::WriteFReg (RegAddr_t reg, UDWord_t data);

template Word_t   RiscvPeThread::GetFReg (RegAddr_t reg_addr);
template DWord_t  RiscvPeThread::GetFReg (RegAddr_t reg_addr);
template UDWord_t RiscvPeThread::GetFReg (RegAddr_t reg_addr);

template MemResult RiscvPeThread::LoadFromBus (Addr_t addr, Word_t   *data);
template MemResult RiscvPeThread::LoadFromBus (Addr_t addr, UWord_t  *data);
template MemResult RiscvPeThread::LoadFromBus (Addr_t addr, DWord_t  *data);
template MemResult RiscvPeThread::LoadFromBus (Addr_t addr, UDWord_t *data);
template MemResult RiscvPeThread::LoadFromBus (Addr_t addr, HWord_t  *data);
template MemResult RiscvPeThread::LoadFromBus (Addr_t addr, UHWord_t *data);
template MemResult RiscvPeThread::LoadFromBus (Addr_t addr, Byte_t   *data);
template MemResult RiscvPeThread::LoadFromBus (Addr_t addr, UByte_t  *data);

template MemResult RiscvPeThread::StoreToBus (Addr_t addr, Word_t   data);
template MemResult RiscvPeThread::StoreToBus (Addr_t addr, UWord_t  data);
template MemResult RiscvPeThread::StoreToBus (Addr_t addr, DWord_t  data);
template MemResult RiscvPeThread::StoreToBus (Addr_t addr, UDWord_t data);
template MemResult RiscvPeThread::StoreToBus (Addr_t addr, HWord_t  data);
template MemResult RiscvPeThread::StoreToBus (Addr_t addr, UHWord_t data);
template MemResult RiscvPeThread::StoreToBus (Addr_t addr, Byte_t   data);
template MemResult RiscvPeThread::StoreToBus (Addr_t addr, UByte_t  data);

template Word_t  RiscvPeThread::CSRWrite       (Addr_t csr_addr, Word_t  data);
template Word_t  RiscvPeThread::CSRWrite       (Addr_t csr_addr, Word_t  data, PrivMode mode);
template Word_t  RiscvPeThread::CSRRead        (Addr_t csr_addr, Word_t *data, PrivMode mode);
template Word_t  RiscvPeThread::CSRRead        (Addr_t csr_addr, Word_t *data);
template Word_t  RiscvPeThread::CSRReadNoTrace (Addr_t csr_addr, Word_t *data);
template Word_t  RiscvPeThread::CSRReadNoTrace (Addr_t csr_addr, Word_t *data, PrivMode mode);

template UWord_t RiscvPeThread::CSRWrite 		 (Addr_t csr_addr, UWord_t data);
template UWord_t RiscvPeThread::CSRWrite 		 (Addr_t csr_addr, UWord_t data, PrivMode mode);
template UWord_t RiscvPeThread::CSRRead  		 (Addr_t csr_addr, UWord_t *data, PrivMode mode);
template UWord_t RiscvPeThread::CSRRead  		 (Addr_t csr_addr, UWord_t *data);
template UWord_t RiscvPeThread::CSRReadNoTrace (Addr_t csr_addr, UWord_t *data);
template UWord_t RiscvPeThread::CSRReadNoTrace (Addr_t csr_addr, UWord_t *data, PrivMode mode);

template DWord_t  RiscvPeThread::CSRWrite       (Addr_t csr_addr, DWord_t data);
template DWord_t  RiscvPeThread::CSRWrite       (Addr_t csr_addr, DWord_t data, PrivMode mode);
template DWord_t  RiscvPeThread::CSRRead        (Addr_t csr_addr, DWord_t *data, PrivMode mode);
template DWord_t  RiscvPeThread::CSRRead        (Addr_t csr_addr, DWord_t *data);
template DWord_t  RiscvPeThread::CSRReadNoTrace (Addr_t csr_addr, DWord_t *data);
template DWord_t  RiscvPeThread::CSRReadNoTrace (Addr_t csr_addr, DWord_t *data, PrivMode mode);

template UDWord_t RiscvPeThread::CSRWrite 		 (Addr_t csr_addr, UDWord_t data);
template UDWord_t RiscvPeThread::CSRWrite 		 (Addr_t csr_addr, UDWord_t data, PrivMode mode);
template UDWord_t RiscvPeThread::CSRRead  		 (Addr_t csr_addr, UDWord_t *data, PrivMode mode);
template UDWord_t RiscvPeThread::CSRRead  		 (Addr_t csr_addr, UDWord_t *data);
template UDWord_t RiscvPeThread::CSRReadNoTrace (Addr_t csr_addr, UDWord_t *data);
template UDWord_t RiscvPeThread::CSRReadNoTrace (Addr_t csr_addr, UDWord_t *data, PrivMode mode);

template void RiscvPeThread::GenerateException (ExceptCode code, Word_t tval);
template void RiscvPeThread::GenerateException (ExceptCode code, UWord_t tval);
template void RiscvPeThread::GenerateException (ExceptCode code, DWord_t tval);
template void RiscvPeThread::GenerateException (ExceptCode code, UDWord_t tval);
