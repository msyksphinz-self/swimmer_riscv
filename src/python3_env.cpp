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
 *   * Neither the name of the msyksphinz nor the
 *     names of its contributors may be used to endorse or promote products
 *     derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 *   ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL MSYKSPHINZ BE LIABLE FOR ANY
 *   DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 *   (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 *   ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 *   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "python3_env.hpp"

#include "riscv_pe_thread.hpp"

struct module_state {
  PyObject *error;
};

#define GETSTATE(m) ((struct module_state*)PyModule_GetState(m))

PyMethodDef riscv_methods[] = {
  { NULL         , NULL                      ,            0, NULL                             } /* Sentinel */
};

typedef struct {
  PyObject_HEAD
  RiscvPeThread *pe_thread;
  int number;
} RiscvPeObject;

static int InitRiscvChip (RiscvPeObject *self, PyObject* args, PyObject *kwds);
static PyObject* MakeRiscvChip (PyTypeObject *type, PyObject* args, PyObject *kwds);
static PyObject* SimRiscvChip (RiscvPeObject *self, PyObject* args);
static PyObject* LoadBinaryRiscvChip (RiscvPeObject *self, PyObject* args);

PyMethodDef riscv_chip_methods[] = {
  { "py_add"     , (PyCFunction)HelloAdd            , METH_VARARGS, "Example ADD"                    },
  { "simulate"   , (PyCFunction)SimRiscvChip        , METH_VARARGS, "Simulate RiscvChip"             },
  { "load_bin"   , (PyCFunction)LoadBinaryRiscvChip , METH_VARARGS, "Load Binary file"               },
  { NULL         , NULL                             ,            0, NULL                             } /* Sentinel */
};


static void RiscvPeDealloc(RiscvPeObject *self)
{
  Py_XDECREF(self->pe_thread);
  Py_TYPE(self)->tp_free((PyObject *) self);
}


static PyTypeObject RiscvPeType = {
  PyVarObject_HEAD_INIT(NULL, 0)
};

static int riscv_traverse(PyObject *m, visitproc visit, void *arg) {
  Py_VISIT(GETSTATE(m)->error);
  return 0;
}

static int riscv_clear(PyObject *m) {
  Py_CLEAR(GETSTATE(m)->error);
  return 0;
}

static struct PyModuleDef moduledef = {
  PyModuleDef_HEAD_INIT,
  "riscv",
  NULL,
  sizeof(struct module_state),
  riscv_methods,
  NULL,
  riscv_traverse,
  riscv_clear,
  NULL
};


PyObject* HelloAdd (PyObject* self, PyObject* args)
{
  int x, y, g;
  PyObject *py_chip;

  if (!PyArg_ParseTuple(args, "Oii", &py_chip, &x, &y))
    return NULL;
  g = x + y;
  return Py_BuildValue("I", g);
}


static PyObject* MakeRiscvChip (PyTypeObject *type, PyObject* args, PyObject *kwds)
{
  RiscvPeObject *self = (RiscvPeObject *) type->tp_alloc(type, 0);

  RiscvPeThread *chip = new RiscvPeThread (stdout, RiscvBitMode_t::Bit64, 0xffffffff, PrivMode::PrivUser,
                                           true, true, stdout, true, "trace_out.log");

  self->pe_thread = chip;

  return (PyObject *)self;
}


static int InitRiscvChip (RiscvPeObject *self, PyObject* args, PyObject *kwds)
{
  return 0;
}


static PyObject* LoadBinaryRiscvChip (RiscvPeObject *self, PyObject* args)
{
  char *filename;
  if (!PyArg_ParseTuple(args, "s", &filename)) {
    return PyLong_FromLong (-1);
  }

  if (self->pe_thread->LoadBinary("swimmer_riscv", filename, true) == -1) {
    return PyLong_FromLong (-1);
  }

  return PyLong_FromLong (0);
}


static PyObject* SimRiscvChip (RiscvPeObject *self, PyObject* args)
{
  self->pe_thread->SetMaxCycle (100);
  self->pe_thread->StepSimulation(100, LoopType_t::FiniteLoop);

  return PyLong_FromLong(0);
}


PyMODINIT_FUNC InitPyEnv (void)
{
    RiscvPeType.tp_name      = "riscv.RiscvPe";
    RiscvPeType.tp_basicsize = (Py_ssize_t) sizeof(RiscvPeObject);
    RiscvPeType.tp_itemsize  = 0;
    RiscvPeType.tp_dealloc   = (destructor) RiscvPeDealloc;
    RiscvPeType.tp_flags     = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE;
    RiscvPeType.tp_doc       = "Riscv objects";
    RiscvPeType.tp_methods   = riscv_chip_methods;
    RiscvPeType.tp_members   = NULL;
    RiscvPeType.tp_init      = (initproc) InitRiscvChip;
    RiscvPeType.tp_new       = MakeRiscvChip;

    if (PyType_Ready(&RiscvPeType) < 0)
    return NULL;

  PyObject *module = PyModule_Create (&moduledef);
  if (module == NULL) {
    return NULL;
  }
  Py_INCREF(&RiscvPeType);
  PyModule_AddObject(module, "RiscvPe", (PyObject *) &RiscvPeType);

  return module;
}
