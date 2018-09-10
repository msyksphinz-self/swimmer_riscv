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
#include <vector>

class RiscvPeThread;

typedef union {
    struct {
        uint64_t V    : 1;
        uint64_t Type : 4;
        uint64_t R    : 1;
        uint64_t D    : 1;
        uint64_t dummy_0 : 3;
        uint64_t PPN_0 : 9;
        uint64_t PPN_1 : 9;
        uint64_t PPN_2 : 20;
        uint64_t dummy_1 : 16;
    };
    uint64_t sv39_entry;
} Sv39Entry_t;

class RiscvPageTable {
private:
    std::unique_ptr<Sv39Entry_t []> m_sv39_entry_list;
    RiscvPeThread *m_env;

public:
    RiscvPageTable (RiscvPeThread *env);
    // MemResult LoadTableEntry (Addr_t offset_addr, Size_t, Word_t *data);
    // MemResult StoreTableEntry (Addr_t offset_addr, Size_t, Word_t data);
};
