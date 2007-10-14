#include "Python.h"

#define const


static PyObject *__Pyx_UnpackItem(PyObject *, int);
static int __Pyx_EndUnpack(PyObject *, int);
static int __Pyx_PrintItem(PyObject *);
static int __Pyx_PrintNewline(void);
static void __Pyx_ReRaise(void);
static void __Pyx_RaiseWithTraceback(PyObject *, PyObject *, PyObject *);
static PyObject *__Pyx_Import(PyObject *name, PyObject *from_list);
static PyObject *__Pyx_GetExcValue(void);
static PyObject *__Pyx_GetName(PyObject *dict, char *name);
static int __Pyx_ArgTypeTest(PyObject *obj, PyTypeObject *type, char *name);
static int __Pyx_TypeTest(PyObject *obj, PyTypeObject *type);

static PyObject *__pyx_m;
static PyObject *__pyx_b;

static char (__pyx_k1[]) = "2b";
static char (__pyx_k2[]) = "Not 2b";
static char (__pyx_k3[]) = "2b?";

static PyObject *__pyx_f_boolExpressionsFail(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_boolExpressionsFail(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_dict;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  PyObject *__pyx_4 = 0;
  int __pyx_5;
  int __pyx_6;
  static char *__pyx_argnames[] = {0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "", __pyx_argnames)) return 0;
  __pyx_v_dict = Py_None; Py_INCREF(__pyx_v_dict);

  /* "ProjectsA:Python:Pyrex:Tests:Bugs:r_mitch_chapman_2.pyx":2 */
  __pyx_1 = PyDict_New(); if (!__pyx_1) goto __pyx_L1;
  __pyx_2 = PyInt_FromLong(1); if (!__pyx_2) goto __pyx_L1;
  __pyx_3 = PyInt_FromLong(1); if (!__pyx_3) goto __pyx_L1;
  if (PyDict_SetItem(__pyx_1, __pyx_2, __pyx_3) < 0) goto __pyx_L1;
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  Py_DECREF(__pyx_v_dict);
  __pyx_v_dict = __pyx_1;
  __pyx_1 = 0;

  /* "ProjectsA:Python:Pyrex:Tests:Bugs:r_mitch_chapman_2.pyx":3 */
  __pyx_2 = PyObject_GetAttrString(__pyx_v_dict, "has_key"); if (!__pyx_2) goto __pyx_L1;
  __pyx_3 = PyString_FromString(__pyx_k1); if (!__pyx_3) goto __pyx_L1;
  __pyx_1 = PyTuple_New(1); if (!__pyx_1) goto __pyx_L1;
  PyTuple_SET_ITEM(__pyx_1, 0, __pyx_3);
  __pyx_3 = 0;
  __pyx_4 = PyObject_CallObject(__pyx_2, __pyx_1); if (!__pyx_4) goto __pyx_L1;
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_5 = PyObject_IsTrue(__pyx_4); if (__pyx_5 < 0) goto __pyx_L1;
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  __pyx_6 = (!__pyx_5);
  if (__pyx_6) {

    /* "ProjectsA:Python:Pyrex:Tests:Bugs:r_mitch_chapman_2.pyx":4 */
    __pyx_3 = PyString_FromString(__pyx_k2); if (!__pyx_3) goto __pyx_L1;
    __pyx_r = __pyx_3;
    __pyx_3 = 0;
    goto __pyx_L0;
    goto __pyx_L2;
  }
  /*else*/ {

    /* "ProjectsA:Python:Pyrex:Tests:Bugs:r_mitch_chapman_2.pyx":6 */
    __pyx_1 = PyString_FromString(__pyx_k3); if (!__pyx_1) goto __pyx_L1;
    __pyx_r = __pyx_1;
    __pyx_1 = 0;
    goto __pyx_L0;
  }
  __pyx_L2:;

  __pyx_r = Py_None; Py_INCREF(__pyx_r);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  Py_XDECREF(__pyx_4);
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_dict);
  return __pyx_r;
}

static struct PyMethodDef __pyx_methods[] = {
  {"boolExpressionsFail", (PyCFunction)__pyx_f_boolExpressionsFail, METH_VARARGS|METH_KEYWORDS, 0},
{0, 0, 0, 0}
};


void initr_mitch_chapman_2(void); /*proto*/
void initr_mitch_chapman_2(void) {
__pyx_m = Py_InitModule4("r_mitch_chapman_2", __pyx_methods, 0, 0, PYTHON_API_VERSION);
__pyx_b = PyImport_AddModule("__builtin__");
PyObject_SetAttrString(__pyx_m, "__builtins__", __pyx_b);

/* "ProjectsA:Python:Pyrex:Tests:Bugs:r_mitch_chapman_2.pyx":1 */
return;
__pyx_L1:;
}

/* Runtime support code */
