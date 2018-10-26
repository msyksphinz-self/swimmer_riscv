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

#include <cstdio>
#include <cstring>
#include <clocale>
#include <cstdlib>
#include <ctime>
#include <cwchar>

/** Unix-like platform char * to wchar_t conversion. */
wchar_t *nstrws_convert(char *raw) {
  wchar_t *rtn = (wchar_t *) calloc(1, (sizeof(wchar_t) * (std::strlen(raw) + 1)));
  std::setlocale(LC_ALL,"en_US.UTF-8"); // Unless you do this python 3 crashes.
  mbstowcs(rtn, raw, strlen(raw));
  return rtn;
}

/** Dispose of an array of wchar_t * */
void nstrws_dispose(int count, wchar_t ** values) {
  for (int i = 0; i < count; i++) {
    free(values[i]);
  }
  free(values);
}

/** Convert an array of strings to wchar_t * all at once. */
wchar_t **nstrws_array(int argc, char *argv[]) {
  wchar_t **rtn = (wchar_t **) calloc(argc, sizeof(wchar_t *));
  for (int i = 0; i < argc; i++) {
    rtn[i] = nstrws_convert(argv[i]);
  }
  return rtn;
}
