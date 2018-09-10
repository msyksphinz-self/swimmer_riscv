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

#include <string.h>
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
#include <functional>
#include "riscv_pe_thread.hpp"
#include "riscv_syscall.hpp"

RiscvSyscall_t::RiscvSyscall_t(uint32_t dev_id, RiscvPeThread *pe_thread)
    : RiscvDevice_t(dev_id, pe_thread), table(2048)
{
  table[17] = &RiscvSyscall_t::sys_getcwd;
  table[25] = &RiscvSyscall_t::sys_fcntl;
  table[34] = &RiscvSyscall_t::sys_mkdirat;
  table[35] = &RiscvSyscall_t::sys_unlinkat;
  table[37] = &RiscvSyscall_t::sys_linkat;
  table[38] = &RiscvSyscall_t::sys_renameat;
  table[46] = &RiscvSyscall_t::sys_ftruncate;
  table[48] = &RiscvSyscall_t::sys_faccessat;
  table[49] = &RiscvSyscall_t::sys_chdir;
  table[56] = &RiscvSyscall_t::sys_openat;
  table[57] = &RiscvSyscall_t::sys_close;
  table[62] = &RiscvSyscall_t::sys_lseek;
  table[63] = &RiscvSyscall_t::sys_read;
  table[64] = &RiscvSyscall_t::sys_write;
  table[67] = &RiscvSyscall_t::sys_pread;
  table[68] = &RiscvSyscall_t::sys_pwrite;
  table[79] = &RiscvSyscall_t::sys_fstatat;
  table[80] = &RiscvSyscall_t::sys_fstat;
  table[93] = &RiscvSyscall_t::sys_exit;
  table[1039] = &RiscvSyscall_t::sys_lstat;
  table[2011] = &RiscvSyscall_t::sys_getmainvars;

  // register_command(0, std::bind(&RiscvSyscall_t::handle_syscall, this, _1), "syscall");

  int stdin_fd = dup(0), stdout_fd0 = dup(1), stdout_fd1 = dup(1);
  if (stdin_fd < 0 || stdout_fd0 < 0 || stdout_fd1 < 0)
    throw std::runtime_error("could not dup stdin/stdout");

  fds.alloc(stdin_fd); // stdin -> stdin
  fds.alloc(stdout_fd0); // stdout -> stdout
  fds.alloc(stdout_fd1); // stderr -> stdout
}

void RiscvSyscall_t::HandleCommand (UDWord_t cmd) {
  Addr_t fromhost_addr;
  GetPeThread()->FindGVarAddr (&fromhost_addr, "fromhost");
  handle_syscall (cmd, fromhost_addr);
}


std::string RiscvSyscall_t::do_chroot(const char* fn)
{
  if (!chroot.empty() && *fn == '/')
    return chroot + static_cast<const char *>(fn);
  return fn;
}

std::string RiscvSyscall_t::undo_chroot(const char* fn)
{
  if (chroot.empty())
    return fn;
  if (strncmp(fn, chroot.c_str(), chroot.size()) == 0
      && (chroot.back() == '/' || fn[chroot.size()] == '/'))
    return fn + chroot.size() - (chroot.back() == '/');
  return "/";
}


void RiscvSyscall_t::handle_syscall(UDWord_t cmd, Addr_t fromhost_addr)
{
  if (PAYLOAD(cmd) & 1) { // test pass/fail
    GetPeThread()->SetStopSim(true);
    GetPeThread()->SetResult(PAYLOAD(cmd));
    return;
  } else {
    dispatch(PAYLOAD(cmd));
  }

  Byte_t res_byte[4];
  Word_t res_word;
  res_byte[0] = 1; res_byte[1] = 0; res_byte[2] = 0; res_byte[3] = 0;
  memcpy(&res_word, res_byte, 4);
  GetPeThread()->StoreTo_FromHost (res_word);
}


reg_t RiscvSyscall_t::sys_exit(reg_t code, reg_t a1, reg_t a2, reg_t a3, reg_t a4, reg_t a5, reg_t a6)
{
  GetPeThread()->SetStopSim(true);
  GetPeThread()->SetResult(PAYLOAD(code));

  return 0;
}


static reg_t sysret_errno(sreg_t ret)
{
  return ret == -1 ? -errno : ret;
}


reg_t RiscvSyscall_t::sys_read(reg_t fd, reg_t pbuf, reg_t len, reg_t a3, reg_t a4, reg_t a5, reg_t a6)
{
  Byte_t *buf = new Byte_t[len];
  ssize_t ret = read(fds.lookup(fd), &buf[0], len);
  reg_t ret_errno = sysret_errno(ret);
  if (ret > 0) {
    for (unsigned int idx = 0; idx < len; idx++) {
      GetPeThread()->StoreToBus (pbuf + idx, buf[idx]);
    }
  }
  return ret_errno;
}

reg_t RiscvSyscall_t::sys_pread(reg_t fd, reg_t pbuf, reg_t len, reg_t off, reg_t a4, reg_t a5, reg_t a6)
{
  Byte_t *buf = new Byte_t[len];
  ssize_t ret = pread(fds.lookup(fd), &buf[0], len, off);
  reg_t ret_errno = sysret_errno(ret);
  if (ret > 0) {
    GetPeThread()->DebugPrint ("<Info : System Call sys_pread. Write Memory %016lx>\n", pbuf);
    GetPeThread()->DebugPrint ("<");
    for (unsigned int idx = 0; idx < len; idx++) {
      GetPeThread()->StoreToBus (pbuf + idx, buf[idx]);
      GetPeThread()->DebugPrint ("%02x ", static_cast<uint8_t>(buf[idx]));
    }
    GetPeThread()->DebugPrint (">\n");
  }
  return ret_errno;
}

reg_t RiscvSyscall_t::sys_write(reg_t fd, reg_t pbuf, reg_t len, reg_t a3, reg_t a4, reg_t a5, reg_t a6)
{
  Byte_t *buf = new Byte_t[len];
  for (Addr_t idx = 0; idx < len; idx++) {
    GetPeThread()->LoadMemoryDebug (pbuf + idx, &buf[idx]);
  }
  char *c_buf = new char[len];
  memcpy(c_buf, buf, len);

  reg_t ret = sysret_errno(write(fds.lookup(fd), &c_buf[0], len));
  return ret;
}

reg_t RiscvSyscall_t::sys_pwrite(reg_t fd, reg_t pbuf, reg_t len, reg_t off, reg_t a4, reg_t a5, reg_t a6)
{
  Byte_t *buf = new Byte_t[len];
  for (Addr_t idx = 0; idx < len; idx++) {
    GetPeThread()->LoadMemoryDebug (pbuf + idx, &buf[idx]);
  }
  char *c_buf = new char[len];
  memcpy(c_buf, buf, len);

  reg_t ret = sysret_errno(pwrite(fds.lookup(fd), &buf[0], len, off));
  return ret;
}

reg_t RiscvSyscall_t::sys_close(reg_t fd, reg_t a1, reg_t a2, reg_t a3, reg_t a4, reg_t a5, reg_t a6)
{
  if (close(fds.lookup(fd)) < 0)
    return sysret_errno(-1);
  fds.dealloc(fd);
  return 0;
}

reg_t RiscvSyscall_t::sys_lseek(reg_t fd, reg_t ptr, reg_t dir, reg_t a3, reg_t a4, reg_t a5, reg_t a6)
{
  return sysret_errno(lseek(fds.lookup(fd), ptr, dir));
}

reg_t RiscvSyscall_t::sys_fstat(reg_t fd, reg_t pbuf, reg_t a2, reg_t a3, reg_t a4, reg_t a5, reg_t a6)
{
  struct stat buf;
  reg_t ret = sysret_errno(fstat(fds.lookup(fd), &buf));
  if (ret != (reg_t)-1)
  {
    riscv_stat rbuf(buf);
    Byte_t *rbuf_byte = new Byte_t[sizeof(rbuf)];
    for (unsigned idx = 0; idx < sizeof(rbuf); idx++) {
      GetPeThread()->StoreToBus (pbuf + idx, rbuf_byte[idx]);
    }
  }
  return ret;
}

reg_t RiscvSyscall_t::sys_fcntl(reg_t fd, reg_t cmd, reg_t arg, reg_t a3, reg_t a4, reg_t a5, reg_t a6)
{
  return sysret_errno(fcntl(fds.lookup(fd), cmd, arg));
}

reg_t RiscvSyscall_t::sys_ftruncate(reg_t fd, reg_t len, reg_t a2, reg_t a3, reg_t a4, reg_t a5, reg_t a6)
{
  return sysret_errno(ftruncate(fds.lookup(fd), len));
}

reg_t RiscvSyscall_t::sys_lstat(reg_t pname, reg_t len, reg_t pbuf, reg_t a3, reg_t a4, reg_t a5, reg_t a6)
{
  Byte_t *name = new Byte_t[len];
  for (Addr_t idx = 0; idx < len; idx++) {
    GetPeThread()->LoadMemoryDebug (pname + idx, &name[idx]);
  }
  char *c_name = new char[len];
  memcpy(c_name, name, len);

  struct stat buf;
  reg_t ret = sysret_errno(lstat(do_chroot(c_name).c_str(), &buf));
  riscv_stat rbuf(buf);
  if (ret != (reg_t)-1)
  {
    riscv_stat rbuf(buf);
    Byte_t *rbuf_byte = new Byte_t[sizeof(rbuf)];
    for (unsigned idx = 0; idx < sizeof(rbuf); idx++) {
      GetPeThread()->StoreToBus (pbuf + idx, rbuf_byte[idx]);
    }
  }
  return ret;
}

#define AT_SYSCALL(syscall, fd, name, ...) \
  (syscall(fds.lookup(fd), int(fd) == RISCV_AT_FDCWD ? do_chroot(name).c_str() : (name), __VA_ARGS__))

reg_t RiscvSyscall_t::sys_openat(reg_t dirfd, reg_t pname, reg_t len, reg_t flags, reg_t mode, reg_t a5, reg_t a6)
{
  Byte_t *name = new Byte_t[len];
  for (Addr_t idx = 0; idx < len; idx++) {
    GetPeThread()->LoadMemoryDebug (pname + idx, &name[idx]);
  }
  char *c_name = new char[len];
  memcpy(c_name, name, len);

  int fd = sysret_errno(AT_SYSCALL(openat, dirfd, c_name, flags, mode));
  if (fd < 0)
    return sysret_errno(-1);
  return fds.alloc(fd);
}

reg_t RiscvSyscall_t::sys_fstatat(reg_t dirfd, reg_t pname, reg_t len, reg_t pbuf, reg_t flags, reg_t a5, reg_t a6)
{
  Byte_t *name = new Byte_t[len];
  for (Addr_t idx = 0; idx < len; idx++) {
    GetPeThread()->LoadMemory (pname + idx, &name[idx]);
  }
  char *c_name = new char[len];
  memcpy(c_name, name, len);

  struct stat buf;
  reg_t ret = sysret_errno(AT_SYSCALL(fstatat, dirfd, c_name, &buf, flags));
  if (ret != (reg_t)-1)
  {
    riscv_stat rbuf(buf);
    Byte_t *rbuf_byte = new Byte_t[sizeof(rbuf)];
    for (unsigned idx = 0; idx < sizeof(rbuf); idx++) {
      GetPeThread()->StoreToBus (pbuf + idx, rbuf_byte[idx]);
    }
  }
  return ret;
}

reg_t RiscvSyscall_t::sys_faccessat(reg_t dirfd, reg_t pname, reg_t len, reg_t mode, reg_t a4, reg_t a5, reg_t a6)
{
  Byte_t *name = new Byte_t[len];
  for (Addr_t idx = 0; idx < len; idx++) {
    GetPeThread()->LoadMemory (pname + idx, &name[idx]);
  }
  char *c_name = new char[len];
  memcpy(c_name, name, len);

  return sysret_errno(AT_SYSCALL(faccessat, dirfd, c_name, mode, 0));
}

reg_t RiscvSyscall_t::sys_renameat(reg_t odirfd, reg_t popath, reg_t olen, reg_t ndirfd, reg_t pnpath, reg_t nlen, reg_t a6)
{
  Byte_t *opath = new Byte_t[olen];
  Byte_t *npath = new Byte_t[nlen];
  for (Addr_t idx = 0; idx < olen; idx++) {
    GetPeThread()->LoadMemory (popath + idx, &opath[idx]);
  }
  for (Addr_t idx = 0; idx < olen; idx++) {
    GetPeThread()->LoadMemory (pnpath + idx, &npath[idx]);
  }

  char *c_opath = new char[olen];
  char *c_npath = new char[nlen];
  memcpy(c_opath, opath, olen);
  memcpy(c_npath, npath, nlen);

  return sysret_errno(renameat(fds.lookup(odirfd), int(odirfd) == RISCV_AT_FDCWD ? do_chroot(c_opath).c_str() : c_opath,
                               fds.lookup(ndirfd), int(ndirfd) == RISCV_AT_FDCWD ? do_chroot(c_npath).c_str() : c_npath));
}

reg_t RiscvSyscall_t::sys_linkat(reg_t odirfd, reg_t poname, reg_t olen, reg_t ndirfd, reg_t pnname, reg_t nlen, reg_t flags)
{
  Byte_t *opath = new Byte_t[olen];
  Byte_t *npath = new Byte_t[nlen];

  for (Addr_t idx = 0; idx < olen; idx++) {
    GetPeThread()->LoadMemory (poname + idx, &opath[idx]);
  }
  for (Addr_t idx = 0; idx < olen; idx++) {
    GetPeThread()->LoadMemory (pnname + idx, &npath[idx]);
  }

  char *c_opath = new char[olen];
  char *c_npath = new char[nlen];
  memcpy(c_opath, opath, olen);
  memcpy(c_npath, npath, nlen);

  return sysret_errno(linkat(fds.lookup(odirfd), int(odirfd) == RISCV_AT_FDCWD ? do_chroot(c_opath).c_str() : c_opath,
                             fds.lookup(ndirfd), int(ndirfd) == RISCV_AT_FDCWD ? do_chroot(c_npath).c_str() : c_npath,
                             flags));
}

reg_t RiscvSyscall_t::sys_unlinkat(reg_t dirfd, reg_t pname, reg_t len, reg_t flags, reg_t a4, reg_t a5, reg_t a6)
{
  Byte_t *name = new Byte_t[len];
  for (Addr_t idx = 0; idx < len; idx++) {
    GetPeThread()->LoadMemory (pname + idx, &name[idx]);
  }

  char *c_name = new char[len];
  memcpy(c_name, name, len);

  return sysret_errno(AT_SYSCALL(unlinkat, dirfd, c_name, flags));
}

reg_t RiscvSyscall_t::sys_mkdirat(reg_t dirfd, reg_t pname, reg_t len, reg_t mode, reg_t a4, reg_t a5, reg_t a6)
{
  Byte_t *name = new Byte_t[len];
  for (Addr_t idx = 0; idx < len; idx++) {
    GetPeThread()->LoadMemory (pname + idx, &name[idx]);
  }
  char *c_name = new char[len];
  memcpy(c_name, name, len);

  return sysret_errno(AT_SYSCALL(mkdirat, dirfd, c_name, mode));
}

reg_t RiscvSyscall_t::sys_getcwd(reg_t pbuf, reg_t size, reg_t a2, reg_t a3, reg_t a4, reg_t a5, reg_t a6)
{
  std::vector<char> buf(size);
  char* ret = getcwd(&buf[0], size);
  if (ret == NULL)
    return sysret_errno(-1);
  std::string tmp = undo_chroot(&buf[0]);
  if (size <= tmp.size())
    return -ENOMEM;
  const char *c_tmp = tmp.c_str();
  for (unsigned int idx = 0; idx < tmp.size() + 1; idx++) {
    Byte_t c = static_cast<Byte_t>(c_tmp[idx]);
    GetPeThread()->StoreToBus (pbuf + idx, c);
  }
  return tmp.size() + 1;
}

reg_t RiscvSyscall_t::sys_getmainvars(reg_t pbuf, reg_t limit, reg_t a2, reg_t a3, reg_t a4, reg_t a5, reg_t a6)
{
  // std::vector<std::string> args = htif->target_args();
  std::vector<std::string> args = {"pk", "file_access_riscv"};
  std::vector<uint64_t> words(args.size()+3, 0);
  words[0] = args.size();
  words[args.size()+1] = 0; // argv[argc] = NULL
  words[args.size()+2] = 0; // envp[0] = NULL

  size_t sz = (args.size() + 3) * sizeof(words[0]);
  for (size_t i = 0; i < args.size(); i++)
  {
    words[i+1] = sz + pbuf;
    sz += args[i].length() + 1;
  }

  std::vector<char> bytes(sz);
  memcpy(&bytes[0], &words[0], sizeof(words[0]) * words.size());
  for (size_t i = 0; i < args.size(); i++)
    strcpy(&bytes[words[i+1] - pbuf], args[i].c_str());

  if (bytes.size() > limit)
    return -ENOMEM;

  GetPeThread()->DebugPrint("<Info: sys_getmainvars : Store %08lx>\n", pbuf);
  for (unsigned int idx = 0; idx < bytes.size() + 1; idx++) {
    Byte_t c = static_cast<Byte_t>(bytes[idx]);
    GetPeThread()->StoreToBus (pbuf + idx, c);
  }

  return 0;
}

reg_t RiscvSyscall_t::sys_chdir(reg_t path, reg_t a1, reg_t a2, reg_t a3, reg_t a4, reg_t a5, reg_t a6)
{
  size_t size = 0;
  Byte_t path_data;
  do {
    GetPeThread()->LoadMemory(path + size++, &path_data);
  } while (path_data);
  // std::vector<char> buf(size);
  Byte_t *buf = new Byte_t[size];
  for (size_t offset = 0;; offset++)
  {
    GetPeThread()->LoadMemory(path + offset, &buf[offset]);
    if (!buf[offset])
      break;
  }

  char *c_buf = new char[size];
  memcpy(c_buf, buf, size);
  return sysret_errno(chdir(c_buf));
}

void RiscvSyscall_t::dispatch(reg_t mm)
{
  reg_t magicmem[8];
  Byte_t *c_magicmem = new Byte_t[sizeof(magicmem)];

  GetPeThread()->DebugPrint("<Info: Dispatch called mm = %016lx size=%d>\n", mm, sizeof(magicmem));

  for (unsigned int idx = 0; idx < sizeof(magicmem); idx++) {
    GetPeThread()->LoadMemoryDebug (mm + idx, &c_magicmem[idx]);
  }
  memcpy (magicmem, c_magicmem, sizeof(magicmem));

  reg_t n = magicmem[0];
  if (n >= table.size() || !table[n]) {
    GetPeThread()->ErrorPrint("<Info: Bad Syscall = %d>\n", n);
    // throw std::runtime_error("bad syscall #" + std::to_string(n));
  }

  GetPeThread()->DebugPrint("<Info: Syscall Number = %d>\n", n);

  magicmem[0] = (this->*table[n])(magicmem[1], magicmem[2], magicmem[3], magicmem[4], magicmem[5], magicmem[6], magicmem[7]);

  memcpy (c_magicmem, magicmem, sizeof(magicmem));
  for (unsigned int idx = 0; idx < sizeof(magicmem); idx++) {
    GetPeThread()->StoreToBus (mm + idx, c_magicmem[idx]);
  }
}
