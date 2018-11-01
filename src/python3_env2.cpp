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
//  { "py_add"     , (PyCFunction)HelloAdd     , METH_VARARGS, "Example ADD"                    },
//  { "riscv_chip" , (PyCFunction)MakeRiscvChip, METH_VARARGS, "Make RiscvChip"                 },
//  { "simulate"   , (PyCFunction)SimRiscvChip , METH_VARARGS, "Simulate RiscvChip"             },
  { NULL         , NULL                      ,            0, NULL                             } /* Sentinel */
};

PyMethodDef riscv_chip_methods[] = {
  { "py_add"     , (PyCFunction)HelloAdd     , METH_VARARGS, "Example ADD"                    },
  { "__init__"   , (PyCFunction)MakeRiscvChip, METH_VARARGS, "Make RiscvChip"                 },
  { "simulate"   , (PyCFunction)SimRiscvChip , METH_VARARGS, "Simulate RiscvChip"             },
  { NULL         , NULL                      ,            0, NULL                             } /* Sentinel */
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


PyObject* MakeRiscvChip (PyObject* self, PyObject* args)
{
  // if (!PyArg_ParseTuple(args, "")
  //   return NULL;

  RiscvPeThread *chip = new RiscvPeThread (stdout, RiscvBitMode_t::Bit64, 0xffffffff, PrivMode::PrivUser,
                                           true, true, stdout, true, "trace_out.log");

  PyObject* chip_capsule = PyCapsule_New((void *)chip, "chip_ptr", NULL);

  printf("MakeRiscvChip %p\n", chip_capsule);

  PyModule_AddObject(self, "RiscvChip", chip_capsule);
 return NULL;
  // return Py_BuildValue("O", chip_capsule);
}


PyObject* SimRiscvChip (PyObject* self, PyObject* args)
{
    PyObject *py_chip, *py_chip_self;
  int max_inst;
  // if (!PyArg_ParseTuple(args, "Oi", &py_chip, &max_inst)) {
  if (!PyArg_UnpackTuple(args, "ref", 2, 2, &py_chip, &max_inst)) {
    return NULL;
  }

  // if (!PyCapsule_CheckExact(py_chip)) {
  //     printf("Error: is not PyCapsule.");
  // }
  // if (!PyCapsule_CheckExact(py_chip_self)) {
  //     printf("Error: is not PyCapsule.");
  // }

  printf("SimRiscvChip %p\n", py_chip);

  RiscvPeThread *chip;
  if ((chip = (RiscvPeThread *)PyCapsule_GetPointer(py_chip, "chip_ptr")) == NULL) {
      printf("Error: object is not valid.");
      return Py_BuildValue("I", 0);
  }

  printf("Phase1.\n");
  chip->SetMaxCycle (max_inst);
  printf("Phase2.\n");
  chip->StepSimulation(max_inst, (max_inst == 0) ? LoopType_t::InfLoop : LoopType_t::FiniteLoop);
  printf("Phase3.\n");

  return Py_BuildValue("I", 0);
}


PyMODINIT_FUNC InitPyEnv (void)
{
  PyObject *module = PyModule_Create (&moduledef);

  if (module == NULL) {
    return NULL;
  }

  struct module_state *st = GETSTATE(module);

  st->error = PyErr_NewException("riscv.Error", NULL, NULL);
  if (st->error == NULL) {
    Py_DECREF(module);
    return NULL;
  }

  PyObject *module_dict = PyModule_GetDict (module);
  PyObject *class_dict  = PyDict_New ();
  PyObject *class_name  = PyUnicode_FromString("RiscvChip");
  PyObject *class_bases = PyTuple_New(0); // An empty tuple for bases is equivalent to `(object,)`

  /* add methods to class */
  for (PyMethodDef *def = riscv_chip_methods; def->ml_name != NULL; def++) {
      PyObject *func   = PyCFunction_New(def, NULL);
      PyObject *method = PyInstanceMethod_New(func);
      PyDict_SetItemString(class_dict, def->ml_name, method);
      Py_DECREF(func);
      Py_DECREF(method);
  }

  PyObject *riscv_class   = PyObject_CallFunctionObjArgs((PyObject *)&PyType_Type, class_name, class_bases, class_dict, NULL);

  PyModule_AddObject(module, "RiscvChip", riscv_class);
  Py_DECREF(class_dict);
  Py_DECREF(class_name);
  Py_DECREF(riscv_class);

  return module;
}
