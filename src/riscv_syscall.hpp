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

#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <limits.h>
#include <errno.h>
#include <stdlib.h>
#include <assert.h>
#include <termios.h>
#include <sstream>
#include <iostream>

#include "basic.hpp"
#include "riscv_fds.hpp"
#include "riscv_devices.hpp"

#define RISCV_AT_FDCWD -100

typedef uint64_t reg_t;
typedef int64_t  sreg_t;

class RiscvPeThread;
class RiscvSyscall_t;
typedef reg_t (RiscvSyscall_t::*syscall_func_t)(reg_t, reg_t, reg_t, reg_t, reg_t, reg_t, reg_t);


struct riscv_stat
{
  uint64_t dev;
  uint64_t ino;
  uint32_t mode;
  uint32_t nlink;
  uint32_t uid;
  uint32_t gid;
  uint64_t rdev;
  uint64_t __pad1;
  uint64_t size;
  uint32_t blksize;
  uint32_t __pad2;
  uint64_t blocks;
  uint64_t atime;
  uint64_t __pad3;
  uint64_t mtime;
  uint64_t __pad4;
  uint64_t ctime;
  uint64_t __pad5;
  uint32_t __unused4;
  uint32_t __unused5;

  riscv_stat(const struct stat& s)
    : dev(s.st_dev), ino(s.st_ino), mode(s.st_mode), nlink(s.st_nlink),
      uid(s.st_uid), gid(s.st_gid), rdev(s.st_rdev), __pad1(0),
      size(s.st_size), blksize(s.st_blksize), __pad2(0),
      blocks(s.st_blocks), atime(s.st_atime), __pad3(0),
      mtime(s.st_mtime), __pad4(0), ctime(s.st_ctime), __pad5(0),
      __unused4(0), __unused5(0) {}
};


class RiscvSyscall_t : public RiscvDevice_t
{
  RiscvPeThread *m_pe_thread;
  std::vector<syscall_func_t> table;

  fds_t fds;

 public:

  RiscvSyscall_t (uint32_t dev_id, RiscvPeThread *pe_thread);

  std::string chroot;
  std::string do_chroot(const char* fn);
  std::string undo_chroot(const char* fn);

  void HandleCommand (UDWord_t cmd);
  void Tick () {}

  void handle_syscall(UDWord_t cmd, Addr_t fromhost_addr);

  reg_t sys_exit        (reg_t, reg_t, reg_t, reg_t, reg_t, reg_t, reg_t);
  reg_t sys_openat      (reg_t, reg_t, reg_t, reg_t, reg_t, reg_t, reg_t);
  reg_t sys_read        (reg_t, reg_t, reg_t, reg_t, reg_t, reg_t, reg_t);
  reg_t sys_pread       (reg_t, reg_t, reg_t, reg_t, reg_t, reg_t, reg_t);
  reg_t sys_write       (reg_t, reg_t, reg_t, reg_t, reg_t, reg_t, reg_t);
  reg_t sys_pwrite      (reg_t, reg_t, reg_t, reg_t, reg_t, reg_t, reg_t);
  reg_t sys_close       (reg_t, reg_t, reg_t, reg_t, reg_t, reg_t, reg_t);
  reg_t sys_lseek       (reg_t, reg_t, reg_t, reg_t, reg_t, reg_t, reg_t);
  reg_t sys_fstat       (reg_t, reg_t, reg_t, reg_t, reg_t, reg_t, reg_t);
  reg_t sys_lstat       (reg_t, reg_t, reg_t, reg_t, reg_t, reg_t, reg_t);
  reg_t sys_fstatat     (reg_t, reg_t, reg_t, reg_t, reg_t, reg_t, reg_t);
  reg_t sys_faccessat   (reg_t, reg_t, reg_t, reg_t, reg_t, reg_t, reg_t);
  reg_t sys_fcntl       (reg_t, reg_t, reg_t, reg_t, reg_t, reg_t, reg_t);
  reg_t sys_ftruncate   (reg_t, reg_t, reg_t, reg_t, reg_t, reg_t, reg_t);
  reg_t sys_renameat    (reg_t, reg_t, reg_t, reg_t, reg_t, reg_t, reg_t);
  reg_t sys_linkat      (reg_t, reg_t, reg_t, reg_t, reg_t, reg_t, reg_t);
  reg_t sys_unlinkat    (reg_t, reg_t, reg_t, reg_t, reg_t, reg_t, reg_t);
  reg_t sys_mkdirat     (reg_t, reg_t, reg_t, reg_t, reg_t, reg_t, reg_t);
  reg_t sys_getcwd      (reg_t, reg_t, reg_t, reg_t, reg_t, reg_t, reg_t);
  reg_t sys_getmainvars (reg_t, reg_t, reg_t, reg_t, reg_t, reg_t, reg_t);
  reg_t sys_chdir       (reg_t, reg_t, reg_t, reg_t, reg_t, reg_t, reg_t);

  void dispatch(reg_t mm);

};
