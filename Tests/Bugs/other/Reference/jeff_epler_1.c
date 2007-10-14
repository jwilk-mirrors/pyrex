#include "Python.h"


static PyObject *__Pyx_UnpackItem(PyObject *, int);
static int __Pyx_EndUnpack(PyObject *, int);
static int __Pyx_PrintItem(PyObject *);
static int __Pyx_PrintNewline(void);
static void __Pyx_ReRaise(void);
static void __Pyx_RaiseWithTraceback(PyObject *, PyObject *, PyObject *);
static PyObject *__Pyx_Import(PyObject *name, PyObject *from_list);
static PyObject *__Pyx_GetExcValue(void);
static PyObject *__Pyx_GetName(PyObject *dict, char *name);

static PyObject *__pyx_m;
static PyObject *__pyx_b;


PyObject *__pyx_f_blowup(PyObject *__pyx_self, PyObject *__pyx_args); /*proto*/
PyObject *__pyx_f_blowup(PyObject *__pyx_self, PyObject *__pyx_args) {
  PyObject *__pyx_v_p = 0;
  PyObject *__pyx_v_q = 0;
  int __pyx_v_n;
  int __pyx_v_i;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  PyObject *__pyx_4 = 0;
  if (!PyArg_ParseTuple(__pyx_args, "OO", &__pyx_v_p, &__pyx_v_q)) return 0;
  Py_INCREF(__pyx_v_p);
  Py_INCREF(__pyx_v_q);

  /* "ProjectsA:Python:Pyrex:Tests:Bugs:jeff_epler_1.pyx":2 */

  /* "ProjectsA:Python:Pyrex:Tests:Bugs:jeff_epler_1.pyx":3 */
  __pyx_3 = PyInt_FromLong(__pyx_v_n); if (!__pyx_3) goto __pyx_L1;
  __pyx_1 = PyInt_FromLong(__pyx_v_i); if (!__pyx_1) goto __pyx_L1;
  __pyx_2 = PyObject_GetItem(__pyx_v_p, __pyx_1); if (!__pyx_2) goto __pyx_L1;
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_4 = PyNumber_Remainder(__pyx_3, __pyx_2); if (!__pyx_4) goto __pyx_L1;
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  __pyx_r = __pyx_4;
  __pyx_4 = 0;
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(__pyx_r);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  Py_XDECREF(__pyx_4);
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_p);
  Py_DECREF(__pyx_v_q);
  return __pyx_r;
}

static struct PyMethodDef __pyx_methods[] = {
  {"blowup", (PyCFunction)__pyx_f_blowup, METH_VARARGS, 0},
  {0, 0, 0, 0}
};

void initjeff_epler_1(void); /*proto*/
void initjeff_epler_1(void) {
  __pyx_m = Py_InitModule4("jeff_epler_1", __pyx_methods, 0, 0, PYTHON_API_VERSION);
  __pyx_b = PyImport_AddModule("__builtin__");
  PyDict_SetAttrString(__pyx_m, "__builtins__", __pyx_b);
}
/* Runtime support code */
