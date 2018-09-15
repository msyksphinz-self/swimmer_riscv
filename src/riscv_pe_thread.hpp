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

#include <vector>
#include <sstream>
#include <cstring>
#include <memory>
#include <queue>
#include <math.h>

#include <bfd.h>
#include <dis-asm.h>

#include "softfloat.h"

#include "env.hpp"
#include "riscv_sysreg_impl.hpp"
#include "riscv_sysreg_bitdef.hpp"
#include "dec_utils_riscv.hpp"
#include "inst_riscv.hpp"
#include "riscv_page_table.hpp"
#include "riscv_devices.hpp"
#include "module_rom.hpp"
#include "module_ide.hpp"
#include "module_uart.hpp"
#include "module_crt.hpp"

class RiscvDeviceList_t;
class RiscvMMDevice_t;
class InstEnv;
class CsrEnv;
class RiscvPageTable;
class RiscvClint_t;

/*!
 * Architecture Environments
 */

#define REG_R0  0
#define REG_R31 31
#define REG_PC  32

enum class PrivMode {
  PrivUser       = 0,
  PrivSupervisor = 1,
  PrivHypervisor = 2,
  PrivMachine    = 3
};


enum class ExceptCode {
  Except_InstAddrMisalign  =  0,
  Except_InstAccessFault   =  1,
  Except_IllegalInst       =  2,
  Except_Breakpoint        =  3,
  Except_LoadAddrMisalign  =  4,
  Except_LoadAccessFault   =  5,
  Except_StoreAddrMisalign =  6,
  Except_StoreAccessFault  =  7,
  Except_EcallFromUMode    =  8,
  Except_EcallFromSMode    =  9,
  Except_EcallFromHMode    = 10,
  Except_EcallFromMMode    = 11,
  Except_InstPageFault     = 12,
  Except_LoadPageFault     = 13,
  Except_StorePageFault    = 15
};


enum class IntCode {
  UserSoftware    =  0,
  SuperSoftware   =  1,
  MachineSoftware =  3,
  UserTimer       =  4,
  SuperTimer      =  5,
  MachineTimer    =  7,
  UserExternal    =  8,
  SuperExternal   =  9,
  MachineExternal = 11
};


enum class RiscvVmMode {
  Vm_Mbare = 0,
  Vm_Sv32  = 1,
  Vm_Sv39  = 8,
  Vm_Sv48  = 9,
  Vm_Sv57  = 10,
  Vm_Sv64  = 11
};


enum class RiscvBitMode_t {
  Bit32 = 0,
  Bit64 = 1
};

class RiscvDec;

class RiscvPeThread : public EnvBase
{
 private:
  RiscvDec *m_ptr_riscv_dec;
  std::unique_ptr<DWord_t []> m_regs;   // general register
  std::unique_ptr<DWord_t []> m_fregs;  // floating point registers
  std::unique_ptr<CsrEnv>  m_csr_env;   // CSR system register information
  std::unique_ptr<RiscvPageTable> m_riscv_page_table;   // Page Table for RISC-V
  Addr_t m_load_reservation;

  RiscvBitMode_t m_bit_mode = RiscvBitMode_t::Bit32;

  RiscvDeviceList_t *m_device_list;
  std::vector<RiscvMMDevice_t *> m_mm_device_list;

  bool        m_en_stop_host;
  Addr_t      m_tohost_addr, m_fromhost_addr;
  DWord_t     m_tohost, m_fromhost;
  bool        m_tohost_en = false, m_fromhost_en = false;
  bool        m_is_gen_sig = false;
  std::string m_sig_filename;
  Addr_t      m_sig_addr_start, m_sig_addr_end;

  PrivMode m_priv;
  PrivMode m_maxpriv;
  RiscvVmMode m_vmmode;

  static const uint32_t tlb_width = 1 << 8;
  bool   m_tlb_en[tlb_width];
  Addr_t m_tlb_tag[tlb_width];
  Addr_t m_tlb_addr[tlb_width];


  AbiRegType m_reg_print_type;

  const std::string m_abi_regs[REG_R31+1] = {
    "zero",
    "ra",
    "sp", "gp", "tp", "t0", "t1", "t2",
    "fp", "s1", "a0", "a1", "a2", "a3", "a4", "a5", "a6", "a7",
    "s2", "s3", "s4", "s5", "s6", "s7", "s8", "s9", "s10", "s11",
    "t3", "t4", "t5", "t6"};

  std::unique_ptr<ModuleRom>  m_rom;
  std::unique_ptr<ModuleUart> m_uart;
  std::unique_ptr<ModuleIde>  m_ide;
  std::unique_ptr<ModuleCrt>  m_crt;

  RiscvClint_t *m_riscv_clint;

  uint32_t m_dst_idx_head;
  std::unique_ptr<uint32_t []> m_dst_idx;
  std::queue<uint32_t> m_dst_queue;
  Addr_t GetTraceDstAddr ();

  static const size_t INTERLEAVE = 5000;
  static const size_t INSNS_PER_RTC_TICK = 100; // 10 MHz clock for 1 BIPS core

  /*
   * L1-Dcache implementation
   */
  const int32_t L1D_SIZE   = 4096;          // 4096Byte
  const int32_t L1D_WORDS  = 4 * 4;         // 16Byte
  const int32_t L1D_LENGTH = L1D_SIZE / L1D_WORDS;
  const Addr_t  L1D_ENTRY_MASK = L1D_LENGTH-1;
  const Addr_t  L1D_ADDR_MASK  = ~(L1D_LENGTH-1);
  std::unique_ptr<bool []>    m_dcache_en;
  std::unique_ptr<Addr_t []>  m_dcache_addr;
  uint32_t MaskL1DIndex (Addr_t addr) {
    const uint32_t addr_mask_length = ceilf(logf(L1D_WORDS) / logf(2));
    return (addr >> addr_mask_length) & L1D_ENTRY_MASK;
  }
  uint32_t MaskL1DAddr (Addr_t addr) {
    const uint32_t addr_mask_length = ceilf(logf(L1D_WORDS) / logf(2));
    return addr & (L1D_ADDR_MASK << addr_mask_length);
  }
  void UpdateL1Dcache (Addr_t addr);


  /*
   * L1-Icache implementation
   */
  const int32_t L1I_SIZE   = 4096;          // 4096Byte
  const int32_t L1I_WORDS  = 4 * 4;         // 16Byte
  const int32_t L1I_LENGTH = L1I_SIZE / L1I_WORDS;
  const Addr_t  L1I_ENTRY_MASK = L1I_LENGTH-1;
  const Addr_t  L1I_ADDR_MASK  = ~(L1I_LENGTH-1);
  std::unique_ptr<bool []>    m_icache_en;
  std::unique_ptr<Addr_t []>  m_icache_addr;
  uint32_t MaskL1IIndex (Addr_t addr) {
    const uint32_t addr_mask_length = ceilf(logf(L1I_WORDS) / logf(2));
    return (addr >> addr_mask_length) & L1I_ENTRY_MASK;
  }
  uint32_t MaskL1IAddr (Addr_t addr) {
    const uint32_t addr_mask_length = ceilf(logf(L1I_WORDS) / logf(2));
    return addr & (L1I_ADDR_MASK << addr_mask_length);
  }
  void UpdateL1Icache (Addr_t addr);


  /*
   * Branch Predictor implementation
   */
  const int32_t BRANCH_LOCAL_BIT     = 3;
  const int32_t BRANCH_ADDR_MASK_LEN = 10;
  const int32_t BRANCH_LOCAL_LENGTH  = 1 << BRANCH_ADDR_MASK_LEN;
  const int32_t BRANCH_STATUS_LENGTH = BRANCH_LOCAL_LENGTH * (1 << BRANCH_LOCAL_BIT);
  std::unique_ptr<uint8_t []> m_branch_his_table;
  std::unique_ptr<BranchPredStatus []> m_branch_status_table;
  Addr_t PredTableIndex (Addr_t addr) {
    return (addr >> 2) & ((1 << BRANCH_ADDR_MASK_LEN)-1);
  }
  Addr_t PredStatusTableIndex (Addr_t addr) {
    Addr_t his_table_idx = PredTableIndex (addr);
    uint8_t his_bit = m_branch_his_table[his_table_idx];

    return ((his_table_idx << BRANCH_LOCAL_BIT) | his_bit) & ((1 << BRANCH_LOCAL_BIT)-1);
  }

  bool m_cpu_wait = false;
  uint64_t m_count_timer = 0;

 public:
  void PrintInst (uint32_t inst_hex, InstId_t inst_idx,
                  char *str_out, const uint32_t length);

  MemResult FetchMemory (Addr_t addr, Word_t *data);

  ExecStatus StepExec (bool is_resume_break);
  void ProceedPC (InstId_t inst_id);
  void PrintOperand (std::stringstream *operand_str);

  template <class T> T  ReadFReg  (RegAddr_t addr);
  template <class T> void WriteFReg (RegAddr_t addr, T data);
  template <class T> T  GetFReg   (RegAddr_t addr);

  template <typename Dst_t, typename Src_t, typename Func> void Func_R_RR (InstWord_t inst_hex, Func func);
  template <typename Dst_t, typename Src_t, typename Func> void Func_R_R  (InstWord_t inst_hex, Func func);
  template <typename Dst_t, typename Src_t, typename Func> void Func_R_RI (InstWord_t inst_hex, Func func);
  template <typename Dst_t, typename Src_t, typename Func> void Func_R_RU (InstWord_t inst_hex, Func func);
  template <typename Dst_t, typename Src_t, typename Func> void Func_F_FF (InstWord_t inst_hex, Func func);
  template <typename Src_t, typename Func>                 void Func_F_FFF(InstWord_t inst_hex, Func func);
  template <typename Dst_t, typename Src_t, typename Func> void Func_R_FF (InstWord_t inst_hex, Func func);
  template <typename Dst_t, typename Src_t, typename Func> void Func_F_F  (InstWord_t inst_hex, Func func);
  template <typename Dst_t, typename Src_t, typename Func> void Func_R_F  (InstWord_t inst_hex, Func func);
  template <typename Dst_t, typename Src_t, typename Func> void Func_F_R  (InstWord_t inst_hex, Func func);

  MemResult FetchFromBus (Addr_t addr, Byte_t *data);
  template <typename AccType> MemResult LoadFromBus (Addr_t addr, AccType *data);
  template <typename AccType> MemResult StoreToBus  (Addr_t addr, AccType  data);

  MemResult LoadFrom_ToHost   (DWord_t *word) { *word = m_tohost;   return MemResult::MemNoExcept; }
  MemResult StoreTo_ToHost    (DWord_t  word) { m_tohost = word;    return MemResult::MemNoExcept; }
  MemResult LoadFrom_FromHost (DWord_t *word) { *word = m_fromhost; return MemResult::MemNoExcept; }
  MemResult StoreTo_FromHost  (DWord_t  word) { m_fromhost = word;  return MemResult::MemNoExcept; }

  void SetSignature(std::string filename) {
    m_is_gen_sig = true;
    m_sig_filename = filename;
  }
  bool IsGenSignature() { return m_is_gen_sig; }

  template <typename AccType> MemResult LoadFromBusDebug (Addr_t addr, AccType *data);

  void SetLoadReservation(Addr_t val) { m_load_reservation = val; }
  Addr_t GetLoadReservation () { return m_load_reservation; }
  void ClearLoadReservation() { m_load_reservation = -1; }

  PrivMode GetPrivMode (void) { return m_priv; }
  void SetPrivMode (PrivMode priv) { m_priv = priv; FlushTlb(); }

  PrivMode GetMaxPriv (void) { return m_maxpriv; }
  void SetMaxPriv (PrivMode maxpriv) { m_maxpriv = maxpriv; }

  RiscvVmMode GetVmMode (void);
  void SetVmMode (RiscvVmMode vmmode) { m_vmmode = vmmode; }

  RiscvBitMode_t GetBitMode (void) { return m_bit_mode; }
  uint32_t GetBitModeInt (void) { return GetBitMode() == RiscvBitMode_t::Bit32 ? 32 : 64; }

  inline void DirtyFS () {
    UDWord_t mstatus;
    CSRReadNoTrace (SYSREG_ADDR_MSTATUS, &mstatus, PrivMode::PrivMachine);
    // Set Dirty Bit
    mstatus = SetBitField (mstatus, 0x03, SYSREG_MSTATUS_FS_MSB, SYSREG_MSTATUS_FS_LSB);
    CSRWrite (SYSREG_ADDR_MSTATUS, mstatus, PrivMode::PrivMachine);
  }

  inline bool IsFPAvailable () {
    UDWord_t mstatus;
    CSRReadNoTrace (SYSREG_ADDR_MSTATUS, &mstatus, PrivMode::PrivMachine);
    uint8_t fs = ExtractBitField (mstatus, SYSREG_MSTATUS_FS_MSB, SYSREG_MSTATUS_FS_LSB);
    return (fs != 0);
  }

  std::string PrintPrivMode(PrivMode priv) {
    switch (priv) {
      case PrivMode::PrivUser       : return "UserMode";
      case PrivMode::PrivSupervisor : return "SuprevisorMode";
      case PrivMode::PrivHypervisor : return "HypervisorMode";
      case PrivMode::PrivMachine    : return "MachineMode";
      default : DebugPrint ("<Internal Error: PrivMode %d is illegal>\n", static_cast<uint32_t>(priv)); exit (EXIT_FAILURE);
    }
  }

  bool IsBranchTaken (Addr_t addr);
  void UpdateBranchPrediction (Addr_t addr, bool is_taken);

  /*!
   * === Architecture Environments ===
   */
  template <class T> T    ReadGReg  (RegAddr_t);
  template <class T> void WriteGReg (RegAddr_t, T data);

  template <typename Xlen_t> Xlen_t CSRRead        (Addr_t csr_addr, Xlen_t *data);
  template <typename Xlen_t> Xlen_t CSRRead        (Addr_t csr_addr, Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t CSRReadNoTrace (Addr_t csr_addr, Xlen_t *data);
  template <typename Xlen_t> Xlen_t CSRReadNoTrace (Addr_t csr_addr, Xlen_t *data, PrivMode mode);
  template <typename Xlen_t> Xlen_t CSRWrite       (Addr_t csr_addr, Xlen_t  data);
  template <typename Xlen_t> Xlen_t CSRWrite       (Addr_t csr_addr, Xlen_t  data, PrivMode mode);

  uint8_t EncodeRMField (uint8_t rm) {
    switch (rm) {
      case 0x00 : return softfloat_round_near_even;
      case 0x01 : return softfloat_round_minMag;
      case 0x02 : return softfloat_round_min;
      case 0x03 : return softfloat_round_max;
      case 0x04 : return softfloat_round_near_maxMag;
      case 0x07 : {
        uint32_t frm;
        CSRRead(SYSREG_ADDR_FRM, &frm);
        return ExtractBitField(frm, 2, 0);
      }
      default   : {
        DebugPrint ("<Internal Error: EncodeRMField %d is illegal>\n");
        return 0;
      }
    }
  }


  void PushPrivMode (PrivMode priv);
  template <typename Xlen_t> void GenerateException (ExceptCode code, Xlen_t tval);
  bool CheckInterrupt (IntCode *ret_intcode);
  void GenerateInterrupt (IntCode code);

  void SetPrintRegStyle (AbiRegType reg_type) { m_reg_print_type = reg_type; }
  AbiRegType GetPrintRegStyle (void) { return AbiRegType::AbiRegHardName; }

  std::string GetRegSoftName (RegAddr_t addr) {
    return m_abi_regs[addr];
  }

  void FlushTlb() { for (int i = 0; i < 0x100; i++) { m_tlb_en[i] = false; }}

  MemResult ConvertVirtualAddress (Addr_t *paddr, Addr_t vaddr, MemAccType acc_type);
  MemResult WalkPageTable (Addr_t *paddr, Addr_t vaddr, MemAccType acc_type,
                           uint32_t init_level, uint32_t *ppn_idx,
                           Addr_t   *pte_len, Addr_t   *pte_idx,
                           Addr_t   *vpn_len, uint32_t *vpn_idx,
                           const int PAGESIZE, const int PTESIZE);

  bool IsAllowedAccess (uint8_t type, MemAccType acc_type, PrivMode vm_mode);

  void SetImgFileName (std::string img_filename);

  // Timer Counter
  void CountUpTimer ();

  void HandleCommand();

  // Page Table
  static uint64_t ExtractSptbrAsidField (UWord_t csr_data) {
    return (csr_data >> 22) & (static_cast<uint64_t>((1 << 10))-1);
  }
  static uint64_t ExtractSptbrPpnField (UWord_t csr_data) {
    return (csr_data >> 0) & (static_cast<uint64_t>((1 << 22))-1);
  }

  inline DWord_t  SExtXlen (DWord_t  hex) { return (hex << (64-GetBitModeInt())) >> (64-GetBitModeInt()); }
  inline UDWord_t UExtXlen (UDWord_t hex) { return (hex << (64-GetBitModeInt())) >> (64-GetBitModeInt()); }

  RiscvPeThread (FILE *dbgfp, RiscvBitMode_t bit_mode, PrivMode maxpriv, bool en_stop_host, bool is_debug_trace, FILE *uart_fp, bool trace_hier, std::string trace_out);
  ~RiscvPeThread ();

  int32_t LoadBinary (std::string path_exec, std::string filename, bool is_load_dump);
  int32_t LoadBinaryTable (std::string filename, bool is_load_dump);
  void LoadFunctionTable (bfd *abfd);
  void LoadGVariableTable (bfd *abfd);

  void OutputSignature ();

  bool IsCpuWaitMode () { return m_cpu_wait; }
  void SetCpuWaitMode (bool wait_mode) { m_cpu_wait = wait_mode; }

};
