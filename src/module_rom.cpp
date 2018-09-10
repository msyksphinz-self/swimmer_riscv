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

#include "./module_rom.hpp"
#include "./env.hpp"
#include <string.h>


MemResult ModuleRom::LoadData (Addr_t addr, Size_t size, Word_t *data)
{
  memcpy (data, &m_memory[addr], size);
  m_env->DebugPrint ("<ROM: Load (%08x)=>%08x %c, %d>\n", addr, *data, *data, size);
  m_env->GetTrace()->RecordTrace (TraceType::MemWrite, addr, *data);

  return MemResult::MemNoExcept;
}


MemResult ModuleRom::StoreData (Addr_t addr, Size_t size, Word_t data)
{
  return MemResult::MemNoExcept;
}


ModuleRom::ModuleRom (EnvBase *env, FILE *dbgfp)
{
  m_env = env;

  uint32_t init[8] = {0x7ffff29f,
                      0x00028067,
                      0x00000000,
                      0x00001020,
                      0x00000000,
                      0x00000000,
                      0x00000000,
                      0x00000000};
  for (size_t i = 0; i < sizeof(init); i++) {
    memcpy (&m_memory[i*4], &init[i], 4);
  }

  std::stringstream s;
  s << std::hex <<
      "platform {\n" \
      "  vendor ucb;\n" \
      "  arch spike;\n" \
      "};\n" \
      "rtc {\n" \
      "  addr 0x40000000;\n" \
      "};\n" \
      "ram {\n" \
      "  0 {\n" \
      "    addr 0x80000000;\n" \
      "    size 0xaef00000;\n" \
      "  };\n" \
      "};\n" \
      "core {\n" \
      "  0 {\n" \
      "    0 {\n" \
      "      isa rv64ima;\n" \
      "      timecmp 0x40000008;\n" \
      "      ipi 0x40001000;\n" \
      "    };\n" \
      "  };\n" \
      "};\n";

  std::string config_string = s.str();
  memcpy (&m_memory[0x20], config_string.c_str(), config_string.size());

}
