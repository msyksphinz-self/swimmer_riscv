#!/usr/bin/python3

import numpy as np
import re
import sys
import multiprocessing as mp
# import threading
# import queue
from time import sleep

argvs = sys.argv

stop_reading = False

class SpikeData:
  def __init__(self, no, pc, inst, mnemonic):
    self.no = no
    self.pc = pc
    self.inst = inst
    self.mnemonic = mnemonic
    self.is_reg_write = False

  def set_reg(self, reg_addr, reg_data):
    self.is_reg_write = True
    self.reg_addr = reg_addr
    self.reg_data = reg_data

  def no(self):
    return self.no

  def pc(self):
    return self.pc

  def inst(self):
    return self.inst

  def mnemonic(self):
    return self.mnemonic

  def is_reg_write(self):
    return self.is_reg_write

  def reg_addr(self):
    return self.reg_addr

  def reg_data(self):
    return self.reg_data


class ForestData:
  def __init__(self, no, pc, inst):
    self.no = no
    self.pc = pc
    self.inst = inst
    self.is_reg_write = False

  def set_reg(self, reg_addr, reg_data):
    self.is_reg_write = True
    self.reg_addr = reg_addr
    self.reg_data = reg_data

  def no(self):
    return self.no

  def pc(self):
    return self.pc

  def inst(self):
    return self.inst

  def mnemonic(self):
    return self.mnemonic

  def is_reg_write(self):
    return self.is_reg_write

  def reg_addr(self):
    return self.reg_addr

  def reg_data(self):
    return self.reg_data

LOAD_STEP = 1


#================================
# REGISTER RTL TRACE INFORMATION
#================================

if len(argvs) != 5:
  print("usage: comptrace_spike_swimmer.rb spike-trace-file swimmer-trace-file skip=0")
  exit()

spike_inst_log  = mp.Queue()
swimmer_inst_log = mp.Queue()

#======================
# Load Spike Trace Log
#======================
def load_spike_log (spike_trace_fp, skip_inst):
  print("Start load_spike_log()")
  step = 0
  spike_line = spike_trace_fp.readline()
  while spike_line != '' :

    if stop_reading == True:
      exit()

    if re.match('^<', spike_line) or spike_line.find('//') != -1 :
      spike_line = spike_trace_fp.readline()
      continue

    # PC Trace Log
    if re.match(".*core.*", spike_line):
      if spike_line.find("exception") != -1 :
        spike_line = spike_trace_fp.readline()
        continue

      if spike_line.find("core   0:           tval") != -1 :
        spike_line = spike_trace_fp.readline()
        continue

      if step == 0:
        cut_spike_line = re.split(' +', spike_line)
        spike_no       = int(cut_spike_line[0], 10)
        spike_pc       = int(cut_spike_line[3], 16)
        spike_inst     = int(cut_spike_line[4].replace("(0x", "").replace(")",""), 16)
        spike_mnemonic = cut_spike_line[5]

        # print ("spike_no = %d < skip_inst = %d" % (spike_no, skip_inst))
        if spike_no < skip_inst:
          spike_line = spike_trace_fp.readline()
          continue

        spike_data = SpikeData(spike_no, spike_pc, spike_inst, spike_mnemonic)

        while True:
          spike_line = spike_trace_fp.readline()
          if not re.match('^<', spike_line) and not spike_line.find('//') != -1 :
            break

        # RegAddr Trace Log
        if re.match('^3 ' , spike_line) or re.match('^1 ' , spike_line) or re.match('^0 ' , spike_line) or \
           re.match('^:3 ', spike_line) or re.match('^:1 ', spike_line) or re.match('^:0 ', spike_line):

          cut_spike_line = re.split(' +', spike_line)
          if len(cut_spike_line) > 3 and (cut_spike_line[3] != "mem") :
            # spike_pc       = int(cut_spike_line[1], 16)
            # spike_inst     = int(cut_spike_line[2].replace("(0x", "").replace(")",""), 16)
            spike_reg_addr = int(cut_spike_line[3].replace('x','').replace('f',''), 10)
            spike_reg_data = int(cut_spike_line[4], 16)

            # print ("[Spike ] : Register Data R[%d]]<=%08x" % (spike_reg_addr, spike_reg_data))

            spike_data.set_reg(spike_reg_addr, spike_reg_data)
          spike_line = spike_trace_fp.readline()

        if spike_inst_log.qsize() >= 1000000:
          sleep(0.1)
        # print("spike %d, %016lx" % (spike_data.no, spike_data.pc))
        spike_inst_log.put(spike_data)
      else:
        spike_line = spike_trace_fp.readline()
      step = step + 1
      if step == LOAD_STEP:
        step = 0
    else:
      spike_line = spike_trace_fp.readline()

  spike_inst_log.put(SpikeData(-1, -1, -1, ""))
  print("Finished load_spike_log()")



#======================
# Load Forest Trace Log
#======================

def load_swimmer_log (swimmer_trace_fp, skip_inst):
  print("Start load_swimmer_log() skip_inst = %d" % skip_inst)
  step = 0
  for swimmer_line in swimmer_trace_fp:

    if stop_reading == True:
      exit()

    # PC Trace Log
    if re.match('^[^<]', swimmer_line) and \
       swimmer_line.find('//') == -1 and \
       swimmer_line.find('<FunctionCall') == -1 and \
       swimmer_line.find('<Return') == -1 :
      if step % LOAD_STEP == 0:
        cut_swimmer_line = swimmer_line.split(':')
        swimmer_no    = int(cut_swimmer_line[0], 10)
        swimmer_pc    = int(cut_swimmer_line[3], 16)
        swimmer_inst  = int(cut_swimmer_line[5], 16)
        swimmer_behav = cut_swimmer_line[7]

        # print ("swimmer_no = %d < skip_inst = %d" % (swimmer_no, skip_inst))
        if swimmer_no < skip_inst:
          continue

        swimmer_data = ForestData(swimmer_no, swimmer_pc, swimmer_inst)

        behav_array = swimmer_behav.split(" ")
        for behav in behav_array:
          # if behav.include?("csrrw") : break
          # if behav.include?("csrrs") : break
          if re.match('[rf][0-9]{2}<=[0-9a-f]+', behav):
            swimmer_reg_addr = int(behav.split("<=")[0].replace('r','').replace('f', ''), 10)
            swimmer_reg_data = int(behav.split("<=")[1], 16)

            swimmer_data.set_reg(swimmer_reg_addr, swimmer_reg_data)

            # print ("[Forest] : Register Data R[%d]]<=%08x" % (swimmer_reg_addr, swimmer_reg_data))

        if swimmer_inst_log.qsize() >= 100000:
          sleep(0.1)
        swimmer_inst_log.put(swimmer_data)
      step = step + 1

  swimmer_inst_log.put(ForestData(-1, -1, ""))
  print("Finished load_swimmer_log()")


def compare_spike_swimmer ():
  swimmer_log_idx = 0
  swimmer_log = ForestData(0, 0, 0)

  while True:
    while spike_inst_log.empty():
      # print("spike_inst_log is empty")
      sleep(0.1)
    spike_log = spike_inst_log.get()
    if spike_log.pc == -1:
      print("//=========================================================")
      print("// Spike Log is Finished")
      print("//=========================================================")
      stop_reading = True
      exit()

    while swimmer_inst_log.empty():
      print("swimmer_inst_log is empty")
      sleep(0.1)
    swimmer_log = swimmer_inst_log.get()
    if swimmer_log.pc == -1:
      print("//=========================================================")
      print("// Forest Log is Finished")
      print("//=========================================================")
      stop_reading = True
      exit()

    # if spike_log.mnemonic.find("addi") != -1:
    #   continue

    # if swimmer_log.no != spike_log.no :
    #   print("//=========================================================")
    #   print("// Number Mismatched! Spike=%d Forest=%d" % (spike_log.no, swimmer_log.no))
    #   print("//=========================================================")
    #   stop_reading = True
    #   exit()

    if swimmer_log.pc != spike_log.pc :
      print("//=========================================================")
      print("// PC Mismatched! Spike=%016x Forest=%016x" % (spike_log.pc, swimmer_log.pc))
      print("// No=%d / %d, %s" % (spike_log.no, swimmer_log.no, spike_log.mnemonic))
      print("//=========================================================")
      stop_reading = True
      exit()

    if swimmer_log.is_reg_write != spike_log.is_reg_write :
      print("//=========================================================")
      print("// Register Write Mismatched! Spike=%s Forest=%s" % ("True" if spike_log.is_reg_write else "False", "True" if swimmer_log.is_reg_write else "False"))
      print("// No=%d / %d, PC=%016x, %s" % (spike_log.no, swimmer_log.no, swimmer_log.pc, spike_log.mnemonic))
      print("//=========================================================")
      stop_reading = True
      exit()

    if swimmer_log.is_reg_write == True and spike_log.is_reg_write == True :
      if swimmer_log.reg_addr != spike_log.reg_addr :
        print("//=========================================================")
        print("// Write Register Address Mismatched! Spike=%d Forest=%d" % (spike_log.reg_addr, swimmer_log.reg_addr))
        print("// No=%d / %d, PC=%016x, %s" % (spike_log.no, swimmer_log.no, swimmer_log.pc, spike_log.mnemonic))
        print("//=========================================================")
        stop_reading = True
        exit()

      if swimmer_log.reg_data != spike_log.reg_data :
        print("//=========================================================")
        print("// Write Register Data Mismatched! Spike=%016x Forest=%016x" % (spike_log.reg_data, swimmer_log.reg_data))
        print("// No=%d / %d, PC=%016x, %s" % (spike_log.no, swimmer_log.no, swimmer_log.pc, spike_log.mnemonic))
        print("//=========================================================")
        stop_reading = True
        exit()

    if swimmer_log.no % 300 == 0:
      print("// No = %d / %d, PC=%016x, %s" % (spike_log.no, swimmer_log.no, swimmer_log.pc, spike_log.mnemonic),)

    swimmer_log_idx = swimmer_log_idx + 1



# spike_inst_log.each { |log|
#   printf("[spike]PC = %08x (%08x)", log.pc, log.inst)
#   if log.is_reg_write == True :
#     printf(" Reg[%d]<=%016x", log.reg_addr, log.reg_data)
#   else:
#     printf("")
#
# }
# swimmer_inst_log.each { |log|
#   printf("[swimmer]PC = %08x (%08x)", log.pc, log.inst)
#   if log.is_reg_write == True :
#     printf(" Reg[%d]<=%016x", log.reg_addr, log.reg_data)
#   else:
#     printf("")
#
# }

try:
  spike_trace_fp  = open (argvs[1], 'r')
except IOError:
  print("%s cannot be opened." % argvs[1])
  exit()

try:
  swimmer_trace_fp = open (argvs[2], 'r')
except IOError:
  print("%s cannot be opened." % argvs[2])
  exit()

skip_spike_inst   = int(argvs[3], 10)
skip_swimmer_inst = int(argvs[4], 10)

th_spike_trace   = mp.Process(target=load_spike_log, args=(spike_trace_fp, skip_spike_inst,))
th_swimmer_trace = mp.Process(target=load_swimmer_log, args=(swimmer_trace_fp, skip_swimmer_inst,))
th_compare       = mp.Process(target=compare_spike_swimmer)

th_spike_trace.start()
th_swimmer_trace.start()
th_compare.start()

th_spike_trace.join()
th_swimmer_trace.join()

th_compare.join()
