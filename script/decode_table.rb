#!/bin/ruby
# -*- coding: utf-8 -*-
#
# Copyright (c) 2015, msyksphinz
# All rights reserved.
#
#   Redistribution and use in source and binary forms, with or without
#   modification, are permitted provided that the following conditions are met:
#   * Redistributions of source code must retain the above copyright
#   notice, this list of conditions and the following disclaimer.
#   * Redistributions in binary form must reproduce the above copyright
#   notice, this list of conditions and the following disclaimer in the
#     documentation and/or other materials provided with the distribution.
#   * Neither the name of the msyksphinz nor the
#     names of its contributors may be used to endorse or promote products
#     derived from this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
#   ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
# DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY
#   DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
#   (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
#    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
#   ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
#   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
#   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#

class FieldArchInfo
  def initialize(f_name, info)
    @field_name = f_name
    @info_arrays = Array[]
    @info_arrays.push(info)
  end

  def field_name
    return @field_name
  end

  def set_field_name(field_name)
    @field_name = field_name
  end

  def info_arrays
    return @info_arrays
  end
end


class MultiFieldArchInfo
  def initialize(f_name, info_arrays)
    @field_name = Array[]
    field_name.push(f_name)
    @info_arrays = info_arrays
  end

  def field_name
    return @field_name
  end

  def push_field_name(field_name)
    @field_name.push(field_name)
  end

  def info_arrays
    return @info_arrays
  end
end


class DecodeFieldInfo
  def initialize (f_name, f_idx, msb, lsb)
    @m_name = f_name
    @m_idx  = f_idx
    @m_msb  = msb
    @m_lsb  = lsb
  end

  def field_name
    return @m_name
  end
  def field_idx
    return @m_idx
  end
  def field_msb
    return @m_msb
  end
  def field_lsb
    return @m_lsb
  end
end  # DecodeFieldInfo


def gen_inst_id_code (inst_mnemonic)
  return inst_mnemonic.split(' ')[0].gsub(/[\.:\[\]]/,'_').gsub('.', '_').upcase
end

def gen_inst_id (inst_mnemonic)
  return "InstId_t::INST_ID_" + gen_inst_id_code(inst_mnemonic)
end
