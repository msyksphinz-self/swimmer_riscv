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
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>

#include "./sc3_pe_thread.hpp"

extern FILE *g_debug_fp;

uint32_t Sc3PeThread::LoadImage (std::string filename)
{
  // const int read_size = 1024;
  const int read_size = 8192;

  uint8_t buf[read_size];

  Addr_t start_addr = 0x00000000;

  // open binary
  int fs_img = open (filename.c_str(), O_RDONLY, S_IREAD);
  if (fs_img < 0) {
    perror (filename.c_str());
    exit (EXIT_FAILURE);
  }

  // Seek Kernel Load position
  if (lseek (fs_img, start_addr, 0) == -1) {
    perror ("lseek");
  }

  // Read head 512byte of image file
  int result;
  if ((result = read (fs_img, buf, read_size)) != read_size){
    perror ("read");
    exit (EXIT_FAILURE);
  }

  DebugPrint ("<Load Image %s>\n", filename.c_str());
  for (int byte = 0; byte < read_size; byte++) {
    StoreMemoryDebug (start_addr + byte, Size_Byte, &buf[byte]);
    if (FLAGS_img_dump == true) {
      if ((byte % 16) == 0) {
        DebugPrint ("%08x : ", byte + start_addr);
      }
      DebugPrint ("%02x ", buf[byte]);
      if ((byte % 16) == 15) {
        DebugPrint ("\n");
      }
    }
  }

  return 0;
}
