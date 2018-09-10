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

#include <stdlib.h>
#include <string.h>

#include <bfd.h>
#include <dis-asm.h>

#include "./sc3_pe_thread.hpp"

static void load_bitfile (bfd *b, asection *section, PTR data);
static void load_hex (bfd *b, asection *section, Memory *p_memory);

extern FILE *g_debug_fp;

uint32_t Sc3PeThread::LoadBinary (std::string filename)
{
  // open binary
  bfd *abfd = bfd_openr (filename.c_str(), NULL);
  if (abfd == NULL) {
    perror ("bfd_openr");
    exit (EXIT_FAILURE);
  }


  bfd_check_format (abfd, bfd_object);

  if (FLAGS_only_info_load == false) {
    // disasemble

    bfd_map_over_sections (abfd, load_bitfile, static_cast<void *>(m_memory.get()));
  }

  // LoadFunctionTable (abfd);
  // LoadGVariableTable (abfd);

  return 0;
}


#ifdef _ENABLE_BFD_

void Sc3PeThread::LoadFunctionTable (bfd *abfd)
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

    // fprintf (stdout, "SymbolName=%s : ", bfd_asymbol_name (symbol_table[i]));
    if ((symbol_table[i]->flags & BSF_FUNCTION) != 0x00) {
      Addr_t addr = bfd_asymbol_value(symbol_table[i]);

      FunctionInfo *p_func_info = new FunctionInfo ();

      p_func_info->symbol = bfd_asymbol_name(symbol_table[i]);
      p_func_info->addr   = addr;
      // Insert new function table
      m_func_table->push_back (p_func_info);

      std::stringstream str;
      str << "<BSF_Function: 0x" << std::hex << std::setw(16) << std::setfill('0')
          << addr << " " << bfd_asymbol_name(symbol_table[i]) << ">\n";
      fprintf (g_debug_fp, "%s", str.str().c_str());

    } else if ((symbol_table[i]->flags & BSF_LOCAL) != 0x00) {
      // fprintf (stdout, "BSF_Local ");
    } else if ((symbol_table[i]->flags & BSF_GLOBAL) != 0x00) {
      // fprintf (stdout, "BSF_global ");
    } else {
      // fprintf (stdout, "BSF_others ");
    }
  }

  free (symbol_table);

  DebugPrint ("<Finish loading function symbol table>\n");
}


void Sc3PeThread::LoadGVariableTable (bfd *abfd)
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
      FunctionInfo *p_gvar_info = new FunctionInfo ();
      p_gvar_info->symbol = bfd_asymbol_name(symbol_table[i]);
      p_gvar_info->addr   = bfd_asymbol_value (symbol_table[i]);
      // Insert new function table
      m_gvar_table->push_back (p_gvar_info);

      std::stringstream str;
      str << "<BSF_Global: 0x" << std::hex << std::setw(Addr_bitwidth / 4) << std::setfill('0')
        << bfd_asymbol_value(symbol_table[i]) << " " << bfd_asymbol_name(symbol_table[i]) << ">\n";
      fprintf (g_debug_fp, "%s", str.str().c_str());
    } else {
      // fprintf (stdout, "BSF_others ");
    }
  }

  DebugPrint ("<Finish loading global variable table>\n");
}


static void load_bitfile (bfd *b, asection *section, PTR data)
{
  Memory *p_memory = static_cast<Memory *>(data);

  if (!(section->flags & SEC_ALLOC)) return;
  // if (!(section->flags & SEC_LOAD)) return;
  if (section->flags & SEC_LINKER_CREATED) return;
  if ((section->flags & SEC_CODE) ||
      (section->flags & SEC_LOAD)) {
    if (!strncmp (".plt", section->name, 4) ||
        !strncmp (".got", section->name, 4)) {
      return;
    }
    std::stringstream str;
    str << "<Loading section Code " << section->name << " 0x"
      << std::hex << std::setw(Addr_bitwidth / 4) << std::setfill('0')
      << section->flags << ">\n";
    fprintf (g_debug_fp, "%s", str.str().c_str());
    load_hex (b, section, p_memory);
  } else if (section->flags & SEC_DATA ||
         section->flags & SEC_HAS_CONTENTS) {
    if (!strncmp (".debug", section->name, 6) ||
        !strncmp (".comment", section->name, 8)) {
      return;
    }
    std::stringstream str;
    str << "<Loading section Data " << section->name << " 0x"
      << std::hex << std::setw(Addr_bitwidth / 4) << std::setfill('0')
      << section->flags << ">\n";
    fprintf (g_debug_fp, "%s", str.str().c_str());

    load_hex (b, section, p_memory);
  }

  return;
}


static void load_hex (bfd *b, asection *section, Memory *p_memory)
{
  int size = bfd_section_size (b, section);
  std::unique_ptr<uint8_t[]> buf (new uint8_t[size]);
  // fprintf (g_debug_fp, "<Allocate %d>\n", size);

  if (!bfd_get_section_contents (b, section, buf.get(), 0, size))
    return;

  /* do hex dump of data */
  for (int i = 0; i < size; i+= 16) {
    int j;

    Addr_t addr = addr = section->vma + i;
    if (FLAGS_load_dump == true) {
      std::stringstream str;
      str << std::hex << std::setw(16) << std::setfill('0') << addr;
      fprintf (g_debug_fp, "%s:  ", str.str().c_str());
    }
    for (j = 0;j < 16 && (i+j) < size; j++) {
      if (FLAGS_load_dump == true) {
        fprintf (g_debug_fp, "%02x ", buf[i+j]);
      }
      p_memory->StoreMemByte (addr+j, &buf[i+j]);
    }
    if (FLAGS_load_dump == true) {
      for (; j < 16; j++) {
        fprintf (g_debug_fp, "   ");
      }
      fprintf (g_debug_fp, "  ");
      for (j = 0; j < 16 && j+i < size; j++) {
        fprintf (g_debug_fp, "%c", isprint (buf[i+j]) ? buf[i+j] : '.');
      }
      fprintf (g_debug_fp, "\n");
    }
  }

  return;
}

#endif // _ENABLE_BFD_
