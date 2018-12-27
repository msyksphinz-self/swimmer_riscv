/*
 * Copyright (c) 2017, msyksphinz
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
#include <regex>

#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>

#include <bfd.h>
#include <dis-asm.h>
#include <limits.h>
#include <stdlib.h>

#include <elf.h>
#include "riscv_pe_thread.hpp"

static void load_bitfile (bfd *b, asection *section, PTR data);
static void load_hex (bfd *b, asection *section, Memory *p_memory);

extern FILE *g_debug_fp;

bool g_dump_hex; // used for Load_hex

int32_t RiscvPeThread::LoadBinary (std::string path_exec, std::string filename, bool is_load_dump)
{
  g_dump_hex = is_load_dump;

  // open binary
  bfd *abfd = bfd_openr (filename.c_str(), NULL);
  if (abfd == NULL) {
    perror (filename.c_str());
    return -1;
  }

  bfd_check_format (abfd, bfd_object);

  bfd_map_over_sections (abfd, load_bitfile, static_cast<void *>(m_memory.get()));

  LoadFunctionTable (abfd);
  LoadGVariableTable (abfd);

  /* Read Entry Point */
  int fd = open(filename.c_str(), O_RDONLY);
  struct stat s;
  assert(fd != -1);
  if (fstat(fd, &s) < 0)
    abort();
  size_t size = s.st_size;

  char* buf = (char*)mmap(NULL, size, PROT_READ, MAP_PRIVATE, fd, 0);
  assert(buf != MAP_FAILED);
  close(fd);

  // assert(size >= sizeof(Elf64_Ehdr));
  // const Elf64_Ehdr* eh64 = (const Elf64_Ehdr*)buf;
  // assert(IS_ELF32(*eh64) || IS_ELF64(*eh64));

  Elf64_Ehdr* eh = (Elf64_Ehdr*)buf;


  Addr_t entry_address = eh->e_entry;

  const int reset_vec_size = 8;

  StoreToBus<Word_t> (0x00001000, 0x00000297                          );       // auipc  t0,0x0
  StoreToBus<Word_t> (0x00001004, 0x28593 + (reset_vec_size * 4 << 20));       // addi   a1, t0, &dtb
  StoreToBus<Word_t> (0x00001008, static_cast<Word_t>(0xf1402573));       // csrr   a0, mhartid
  if (m_bit_mode == RiscvBitMode_t::Bit32) {
    StoreToBus<Word_t> (0x0000100c,   0x0182a283                      );       // lw     t0,24(t0)
  } else {
    StoreToBus<Word_t> (0x0000100c,   0x0182b283                      );       // ld     t0,24(t0)
  }
  StoreToBus<Word_t> (0x00001010, 0x00028067                           );       // jr     t0
  StoreToBus<Word_t> (0x00001014, 0x00000000                           );
  StoreToBus<Word_t> (0x00001018, static_cast<Word_t>(entry_address & 0xffffffff));
  StoreToBus<Word_t> (0x0000101c, static_cast<Word_t>(entry_address >> 32       ));

  if (path_exec != "") {
    char szTmp[32];
    char dtb_path_buf[PATH_MAX];
    sprintf(szTmp, "/proc/%d/exe", getpid());
    int bytes = readlink(szTmp, dtb_path_buf, PATH_MAX);
    if(bytes >= 0)
      dtb_path_buf[bytes] = '\0';

    std::string dtb_path_str = dtb_path_buf;
    std::string dtb_path_str_replace = std::regex_replace(dtb_path_str, std::regex("/[^/]+$"), "/riscv64.dtb");

    FILE *dtb_fp;
    if ((dtb_fp = fopen(dtb_path_str_replace.c_str(), "r")) == NULL) {
      perror (dtb_path_str_replace.c_str());
      return -1;
    }

    Byte_t dtb_buf;
    Addr_t rom_addr = 0x00001020;
    while (fread(&dtb_buf, sizeof(Byte_t), 1, dtb_fp) == 1) {
      StoreMemoryDebug<Byte_t> (rom_addr, &dtb_buf); // To Disable Trace Log
      rom_addr++;
    }
  }

  return 0;
}


int32_t RiscvPeThread::LoadBinaryTable (std::string filename, bool is_load_dump)
{
  g_dump_hex = is_load_dump;

  // open binary
  bfd *abfd = bfd_openr (filename.c_str(), NULL);
  if (abfd == NULL) {
    perror (filename.c_str());
    return -1;
  }

  bfd_check_format (abfd, bfd_object);
  LoadFunctionTable (abfd);
  LoadGVariableTable (abfd);

  return 0;
}


void RiscvPeThread::LoadFunctionTable (bfd *abfd)
{
  long    storage_needed;
  asymbol **symbol_table;
  long    number_of_symbols;

  storage_needed = bfd_get_symtab_upper_bound (abfd);
  if (storage_needed < 0) {
    std::cerr << "Error storage_needed < 0\n";
    exit (EXIT_FAILURE);
  }
  if (storage_needed == 0) {
    std::cerr << "Error storage_needed == 0\n";
    exit (EXIT_FAILURE);
  }

  symbol_table = (asymbol **) malloc (storage_needed);

  number_of_symbols = bfd_canonicalize_symtab (abfd, symbol_table);

  if (number_of_symbols < 0) {
    std::cerr << "Error: number_of_symbols < 0\n";
    exit (EXIT_FAILURE);
  }
  for (int i = 0; i < number_of_symbols; i++) {

    if (g_dump_hex) {
      DebugPrint ("<Info: SymbolName= %s, FLAG=%x, Addr=%016lx>\n",
                  bfd_asymbol_name (symbol_table[i]), symbol_table[i]->flags, bfd_asymbol_value(symbol_table[i]));
    }
    if ((symbol_table[i]->flags & BSF_FUNCTION ) != 0x00 ||
        (symbol_table[i]->flags & BSF_DEBUGGING) != 0x00 ||
        (symbol_table[i]->flags & BSF_GLOBAL)    != 0x00) {
      Addr_t addr = bfd_asymbol_value(symbol_table[i]);

      // FunctionInfo *p_func_info = new FunctionInfo ();
      // p_func_info->symbol = bfd_asymbol_name(symbol_table[i]);
      // p_func_info->addr   = addr;
      // Insert new function table
      // m_func_table->push_back (p_func_info);
      m_func_table->insert(std::make_pair(addr, bfd_asymbol_name(symbol_table[i])));

      if (g_dump_hex) {
        std::stringstream str;
        str << "<BSF_Function: 0x" << std::hex << std::setw(16) << std::setfill('0')
            << addr << " " << bfd_asymbol_name(symbol_table[i]) << ">\n";
        DebugPrint ("%s", str.str().c_str());
      }
    } else if ((symbol_table[i]->flags & BSF_LOCAL) != 0x00) {
      // fprintf (stdout, "BSF_Local ");
    } else {
      // fprintf (stdout, "BSF_others ");
    }
  }

  free (symbol_table);

  if (g_dump_hex) {
    DebugPrint ("<Finish loading function symbol table>\n");
  }
}


void RiscvPeThread::LoadGVariableTable (bfd *abfd)
{
  long    storage_needed;
  asymbol **symbol_table;
  long    number_of_symbols;

  storage_needed = bfd_get_symtab_upper_bound (abfd);
  if (storage_needed < 0) {
    std::cerr << "Error storage_needed < 0\n";
    exit (EXIT_FAILURE);
  }
  if (storage_needed == 0) {
    std::cerr << "Error storage_needed == 0\n";
    exit (EXIT_FAILURE);
  }

  symbol_table = (asymbol **) malloc (storage_needed);

  number_of_symbols = bfd_canonicalize_symtab (abfd, symbol_table);

  if (number_of_symbols < 0) {
    std::cerr << "Error: number_of_symbols < 0\n";
    exit (EXIT_FAILURE);
  }
  for (int i = 0; i < number_of_symbols; i++) {

    //  fprintf (stdout, "SymbolName=%s : ", bfd_asymbol_name (symbol_table[i]));
    if ((symbol_table[i]->flags & BSF_FUNCTION) != 0x00) {
      // fprintf (stdout, "BSF_Function ");

    } else if ((symbol_table[i]->flags & BSF_LOCAL) != 0x00) {
      // fprintf (stdout, "BSF_Local %s %08x\n",

    } else if ((symbol_table[i]->flags & BSF_GLOBAL) != 0x00) {
      // FunctionInfo *p_gvar_info = new FunctionInfo ();
      // p_gvar_info->symbol = bfd_asymbol_name(symbol_table[i]);
      // p_gvar_info->addr   = bfd_asymbol_value (symbol_table[i]);
      // Insert new function table
      // m_gvar_table->push_back (p_gvar_info);
      m_gvar_table->insert(std::make_pair(bfd_asymbol_value (symbol_table[i]),
                                          bfd_asymbol_name(symbol_table[i])));

      if (g_dump_hex) {
        std::stringstream str;
        str << "<BSF_Global: 0x" << std::hex << std::setw(Addr_bitwidth / 4) << std::setfill('0')
            << bfd_asymbol_value(symbol_table[i]) << " " << bfd_asymbol_name(symbol_table[i]) << ">\n";
        DebugPrint ("%s", str.str().c_str());
      }
      if (!strcmp(bfd_asymbol_name(symbol_table[i]), "tohost")) {
        if (g_dump_hex) {
          std::stringstream str;
          str << "<Info: set tohost address " << std::hex << std::setw(Addr_bitwidth / 4) << std::setfill('0')
              << bfd_asymbol_value(symbol_table[i]) << ">\n";
          DebugPrint ("%s", str.str().c_str());
        }
        m_tohost_addr = bfd_asymbol_value(symbol_table[i]);
        m_tohost_en = true;
      }
      if (!strcmp(bfd_asymbol_name(symbol_table[i]), "fromhost")) {
        if (g_dump_hex) {
          std::stringstream str;
          str << "<Info: set fromhost address " << std::hex << std::setw(Addr_bitwidth / 4) << std::setfill('0')
              << bfd_asymbol_value(symbol_table[i]) << ">\n";
          DebugPrint ("%s", str.str().c_str());
        }
        m_fromhost_addr = bfd_asymbol_value(symbol_table[i]);
        m_fromhost_en = true;
      }

      if (IsGenSignature() &&
          !strcmp(bfd_asymbol_name(symbol_table[i]), "begin_signature")) {
        m_sig_addr_start = bfd_asymbol_value(symbol_table[i]);
      } else {
        m_sig_addr_start = 0x100;
      }
      if (IsGenSignature() &&
          !strcmp(bfd_asymbol_name(symbol_table[i]), "end_signature")) {
        m_sig_addr_end = bfd_asymbol_value(symbol_table[i]);
      } else {
        m_sig_addr_end = 0x400;
      }
    } else {
      // fprintf (stdout, "BSF_others ");
    }
  }
  if (g_dump_hex) {
    DebugPrint ("<Finish loading global variable table>\n");
  }
}


static void load_bitfile (bfd *b, asection *section, PTR data)
{
  Memory *p_memory = static_cast<Memory *>(data);

  // std::stringstream str;
  // str << "<Loading section ... " << section->name << " 0x"
  //     << std::hex << std::setw(Addr_bitwidth / 4) << std::setfill('0')
  //     << section->flags << ">\n";
  // fprintf (stderr, "%s", str.str().c_str());

  // if (!(section->flags & SEC_ALLOC)) return;
  // if (!(section->flags & SEC_LOAD)) return;
  if (section->flags & SEC_LINKER_CREATED) return;
  if ((section->flags & SEC_CODE) ||
      (section->flags & SEC_ALLOC)) {
    if (!strncmp (".plt", section->name, 4) ||
        !strncmp (".got", section->name, 4)) {
      return;
    }
    // std::stringstream str;
    // str << "<Loading section Code " << section->name << " 0x"
    //   << std::hex << std::setw(Addr_bitwidth / 4) << std::setfill('0')
    //   << section->flags << ">\n";
    // fprintf (stderr, "%s", str.str().c_str());
    load_hex (b, section, p_memory);
  } else if (section->flags & SEC_DATA ||
             section->flags & SEC_HAS_CONTENTS) {
    if (!strncmp (".debug", section->name, 6) ||
      !strncmp (".comment", section->name, 8)) {
      return;
    }
    // std::stringstream str;
    // str << "<Loading section Data " << section->name << " 0x"
    //   << std::hex << std::setw(Addr_bitwidth / 4) << std::setfill('0')
    //   << section->flags << ">\n";
    // fprintf (stderr, "%s", str.str().c_str());

    load_hex (b, section, p_memory);
  }

  return;
}


static void load_hex (bfd *b, asection *section, Memory *p_memory)
{
  int size = bfd_section_size (b, section);
  std::unique_ptr<Byte_t[]> buf (new Byte_t[size]);
  // fprintf (stderr, "<Allocate %d>\n", size);

  if (!bfd_get_section_contents (b, section, buf.get(), 0, size))
    return;

  /* do hex dump of data */
  for (int i = 0; i < size; i+= 16) {
    int j;

    Addr_t addr = section->vma + i;
    if (g_dump_hex == true) {
      std::stringstream str;
      str << std::hex << std::setw(16) << std::setfill('0') << addr;
      fprintf (stderr, "%s:  ", str.str().c_str());
    }
    for (j = 0;j < 16 && (i+j) < size; j++) {
      if (g_dump_hex == true) {
        fprintf (stderr, "%02x ", static_cast<UByte_t>(buf[i+j]) & 0x00ff);
      }
      p_memory->StoreMemory<Byte_t> (addr+j, static_cast<Byte_t *>(&buf[i+j]));
    }
    if (g_dump_hex == true) {
      for (; j < 16; j++) {
        fprintf (stderr, "   ");
      }
      fprintf (stderr, "  ");
      for (j = 0; j < 16 && j+i < size; j++) {
        fprintf (stderr, "%c", isprint (buf[i+j]) ? buf[i+j] : '.');
      }
      fprintf (stderr, "\n");
    }
  }

  return;
}
