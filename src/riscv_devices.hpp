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
#include "mem_body.hpp"
#include "riscv_pe_thread.hpp"


// static uint8_t  DEVICE (uint64_t command) { return command >> 56; }
// static uint8_t  COMMAND(uint64_t command) { return command >> 48; }
// static uint64_t PAYLOAD(uint64_t command) { return command << 16 >> 16; }
#define DEVICE(cmd)  ((cmd >> 56) & 0xff)
#define COMMAND(cmd) ((cmd >> 48) & 0xff)
#define PAYLOAD(cmd) (cmd & 0xffffffffffffULL)

#define MAKE_COMMAND(dev, cmd, payload) (static_cast<uint64_t>(dev) << 56 | static_cast<uint64_t>(cmd) << 48 | static_cast<uint64_t>(payload) & 0x0ffff)

class RiscvDevice_t
{
  uint32_t       m_dev_id;
  RiscvPeThread *m_pe_thread;

 public:
  virtual void HandleCommand (UDWord_t cmd) = 0;
  virtual void Tick() = 0;
  RiscvPeThread *GetPeThread() { return m_pe_thread; }

  RiscvDevice_t (uint32_t dev_id, RiscvPeThread *pe_thread) :
      m_dev_id(dev_id), m_pe_thread(pe_thread) {}
  virtual ~RiscvDevice_t () {}

  inline uint32_t GetDevId() { return m_dev_id; }
};


class RiscvMMDevice_t
{
 private:
  Addr_t m_base_addr;
  Addr_t m_size;

 public:
  RiscvPeThread *m_pe_thread;

  virtual MemResult Load  (Addr_t addr, size_t len,  Byte_t *data) = 0;
  virtual MemResult Store (Addr_t addr, size_t size, Byte_t *data) = 0;

  Addr_t GetBaseAddr () { return m_base_addr; }
  Addr_t GetSize () { return m_size; }

  RiscvMMDevice_t (RiscvPeThread *pe_thread, Addr_t base_addr, Addr_t size) {
    m_pe_thread = pe_thread;
    m_base_addr = base_addr;
    m_size = size;
  }
  virtual ~RiscvMMDevice_t () {}
};


class RiscvDeviceList_t
{
 private:
  std::vector<RiscvDevice_t*> m_devices;

 public:

  void RegisterDevice (RiscvDevice_t* dev) {
    m_devices.push_back(dev);
  }

  void HandleCommand (UDWord_t cmd) {
    if (DEVICE(cmd) >= m_devices.size()) {
      fprintf (stderr, "<Info: HandleCommand not found %ld>\n", DEVICE(cmd));
      return;
    }
    m_devices[DEVICE(cmd)]->HandleCommand(cmd);
  }

  void Tick () {
    for (RiscvDevice_t *device : m_devices) {
      device->Tick();
    }
  }

  ~RiscvDeviceList_t ()
  {
    for (RiscvDevice_t *device : m_devices) {
      delete device;
    }
  }

};
