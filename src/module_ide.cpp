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

#include "./riscv_pe_thread.hpp"
#include "./module_ide.hpp"


MemResult ModuleIde::LoadData (Addr_t addr, Size_t size, Word_t *data)
{
  switch (addr) {
  case 0x01f0:  // Data Port
    m_env->DebugPrint ("<IDE: DataPort(0x%08x) Load>\n", addr);
    *data = ReadImgFile ();
    m_env->GenerateInterrupt (IntCode::Software);
    break;
  case 0x01f1:  // Features Error Information
    m_env->DebugPrint ("<IDE: Feat/ErrInfo(0x%08x) Load>\n", addr);
    *data = m_err; break;
  case 0x01f2:  // Sector Count
    m_env->DebugPrint ("<IDE: SectorCount(0x%08x) Load>\n", addr);
    *data = m_sector_count; break;
  case 0x01f3:  // Sector Number LBAlo
    m_env->DebugPrint ("<IDE: SecNum:LBAlo(0x%08x) Load>\n", addr);
    *data = m_sector_number; break;
  case 0x01f4:  // Sector Number LBAmid
    m_env->DebugPrint ("<IDE: SecNum:LBAmid(0x%08x) Load>\n", addr);
    *data = m_cylinder_low; break;
  case 0x01f5:  // Sector Number LBAhi
    m_env->DebugPrint ("<IDE: SecNum:LBAhi(0x%08x) Load>\n", addr);
    *data = m_cylinder_high; break;
  case 0x01f6:  // Drive/Head Port
    m_env->DebugPrint ("<IDE: Drive/HeadPort(0x%08x) Load>\n", addr);
    *data = m_device_head; break;
  case 0x01f7:  // CmdPrt/RegStatusPort
    m_env->DebugPrint ("<IDE: CommandPort:RegularStatus(0x%08x) Load>\n", addr);
    *data = m_status; break;
  case 0x03f7:  // AlternateStatus
    m_env->DebugPrint ("<IDE: AlternateStatus(0x%08x) Load>\n", addr);
    *data = m_alternate_status; break;
  }

  return MemResult::MemNoExcept;
}


MemResult ModuleIde::StoreData (Addr_t addr, Size_t size, Word_t data)
{
  Byte_t byte_data = data & 0x0FFU;
  switch (addr) {
  case 0x01f0:  // Data Port
    m_env->DebugPrint ("<IDE: DataPort(0x%08x)<=%02x Store>\n", addr, byte_data);
    m_data = byte_data;
    break;
  case 0x01f1:  // Features Error Information
    m_env->DebugPrint ("<IDE: Feature(0x%08x)<=%02x Store>\n", addr, byte_data);
    m_feature = byte_data;
    break;
  case 0x01f2:  // Sector Count
    m_env->DebugPrint ("<IDE: SectorCount(0x%08x)<=%02x Store>\n", addr, byte_data);
    m_sector_count = byte_data;
    break;
  case 0x01f3:  // Sector Number LBAlo
    m_env->DebugPrint ("<IDE: SecNum:LBAlo(0x%08x)<=%02x Store>\n", addr, byte_data);
    m_sector_number = byte_data;
    break;
  case 0x01f4:  // Sector Number LBAmid
    m_env->DebugPrint ("<IDE: SecNum:LBAmid(0x%08x)<=%02x Store>\n", addr, byte_data);
    m_cylinder_low = byte_data;
    break;
  case 0x01f5:  // Sector Number LBAhi
    m_env->DebugPrint ("<IDE: SecNum:LBAhi(0x%08x)<=%02x Store>\n", addr, byte_data);
    m_cylinder_high = byte_data;
    break;
  case 0x01f6:  // Drive/Head Port
    m_env->DebugPrint ("<IDE: HeadPort(0x%08x)<=%02x Store>\n", addr, byte_data);
    m_device_head = byte_data;
    break;
  case 0x01f7:  // CmdPrt/RegStatusPort
    m_env->DebugPrint ("<IDE: CommandPort:Command(0x%08x)<=%02x Store>\n", addr, byte_data);
    m_env->DebugPrint ("<Head:0x%02x, Cylinder:0x%02x%02x, SectorNum:0x%02x, SectorCount:0x%02x>\n",
                       m_device_head & 0x0f, m_cylinder_high, m_cylinder_low, m_sector_number, m_sector_count);
    m_command = byte_data;
    OpenImgFile ();
    break;
  case 0x03f6:  // DeviceControl
    m_env->DebugPrint ("<IDE: CommandPort:DeviceControl(0x%08x)<=%02x Store>\n", addr, byte_data);
    m_device_control = byte_data;
    break;
  }

  return MemResult::MemNoExcept;
}


void ModuleIde::OpenImgFile (void)
{
  if ((m_img_fp = fopen (m_img_filename.c_str(), "r")) == NULL) {
    perror (m_img_filename.c_str());
    exit (EXIT_FAILURE);
  }

  // Seek Kernel Load position
  Addr_t seek_addr = m_sector_number * 512;
  if (fseek (m_img_fp, seek_addr, 0) == -1) {
    perror (m_img_filename.c_str());
  }
  m_read_count = 0;
  m_env->DebugPrint ("<Opening Image File seek=%d %s...>\n", seek_addr, m_img_filename.c_str());
}


void ModuleIde::CloseImgFile (void)
{
  fclose (m_img_fp);
}


Word_t ModuleIde::ReadImgFile (void)
{
  Word_t word = 0;
  for (int i = 0; i < 4; i++) {
    Byte_t byte_data;
    if ((byte_data = fgetc (m_img_fp)) == EOF) {
      return 0;
    }
    word = ((word >> 8) & 0x00FFFFFFULL) | (byte_data << 24);
  }

  m_env->DebugPrint ("<ReadImgFile(Index=%d)=>%08x>\n", m_read_count, word);

  if ((++m_read_count) == 512 / 4) {
    CloseImgFile ();
    m_read_count = 0;
  }

  return word;
}


ModuleIde::ModuleIde (RiscvPeThread *env, FILE *debug_fp)
{
  m_env = env;
  m_debug_fp = debug_fp;

  m_status = 0x40;  // RDY = 1

}
