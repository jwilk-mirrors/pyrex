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


static PyObject *__pyx_f_primes(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_primes(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  int __pyx_v_kmax;
  int __pyx_v_n;
  int __pyx_v_k;
  int __pyx_v_i;
  int (__pyx_v_p[1000]);
  PyObject *__pyx_v_result;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  int __pyx_2;
  PyObject *__pyx_3 = 0;
  PyObject *__pyx_4 = 0;
  PyObject *__pyx_5 = 0;
  static char *__pyx_argnames[] = {"kmax",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "i", __pyx_argnames, &__pyx_v_kmax)) return 0;
  __pyx_v_result = Py_None; Py_INCREF(__pyx_v_result);

  /* "ProjectsA:Python:Pyrex:Tests:Runnable:r_primes.pyx":2 */

  /* "ProjectsA:Python:Pyrex:Tests:Runnable:r_primes.pyx":3 */

  /* "ProjectsA:Python:Pyrex:Tests:Runnable:r_primes.pyx":4 */
  __pyx_1 = PyList_New(0); if (!__pyx_1) goto __pyx_L1;
  Py_DECREF(__pyx_v_result);
  __pyx_v_result = __pyx_1;
  __pyx_1 = 0;

  /* "ProjectsA:Python:Pyrex:Tests:Runnable:r_primes.pyx":5 */
  __pyx_2 = (__pyx_v_kmax > 1000);
  if (__pyx_2) {

    /* "ProjectsA:Python:Pyrex:Tests:Runnable:r_primes.pyx":6 */
    __pyx_v_kmax = 1000;
    goto __pyx_L2;
  }
  __pyx_L2:;

  /* "ProjectsA:Python:Pyrex:Tests:Runnable:r_primes.pyx":7 */
  __pyx_v_k = 0;

  /* "ProjectsA:Python:Pyrex:Tests:Runnable:r_primes.pyx":8 */
  __pyx_v_n = 2;

  /* "ProjectsA:Python:Pyrex:Tests:Runnable:r_primes.pyx":9 */
  while (1) {
    __pyx_L3:;
    __pyx_2 = (__pyx_v_k < __pyx_v_kmax);
    if (!__pyx_2) break;

    /* "ProjectsA:Python:Pyrex:Tests:Runnable:r_primes.pyx":10 */
    __pyx_v_i = 0;

    /* "ProjectsA:Python:Pyrex:Tests:Runnable:r_primes.pyx":11 */
    while (1) {
      __pyx_L5:;
      if (__pyx_2 = (__pyx_v_i < __pyx_v_k)) {
        __pyx_2 = ((__pyx_v_n % (__pyx_v_p[__pyx_v_i])) != 0);
      }
      if (!__pyx_2) break;

      /* "ProjectsA:Python:Pyrex:Tests:Runnable:r_primes.pyx":12 */
      __pyx_v_i = (__pyx_v_i + 1);
    }
    __pyx_L6:;

    /* "ProjectsA:Python:Pyrex:Tests:Runnable:r_primes.pyx":13 */
    __pyx_2 = (__pyx_v_i == __pyx_v_k);
    if (__pyx_2) {

      /* "ProjectsA:Python:Pyrex:Tests:Runnable:r_primes.pyx":14 */
      (__pyx_v_p[__pyx_v_k]) = __pyx_v_n;

      /* "ProjectsA:Python:Pyrex:Tests:Runnable:r_primes.pyx":15 */
      __pyx_v_k = (__pyx_v_k + 1);

      /* "ProjectsA:Python:Pyrex:Tests:Runnable:r_primes.pyx":16 */
      __pyx_1 = PyObject_GetAttrString(__pyx_v_result, "append"); if (!__pyx_1) goto __pyx_L1;
      __pyx_3 = PyInt_FromLong(__pyx_v_n); if (!__pyx_3) goto __pyx_L1;
      __pyx_4 = PyTuple_New(1); if (!__pyx_4) goto __pyx_L1;
      PyTuple_SET_ITEM(__pyx_4, 0, __pyx_3);
      __pyx_3 = 0;
      __pyx_5 = PyObject_CallObject(__pyx_1, __pyx_4); if (!__pyx_5) goto __pyx_L1;
      Py_DECREF(__pyx_4); __pyx_4 = 0;
      Py_DECREF(__pyx_5); __pyx_5 = 0;
      goto __pyx_L7;
    }
    __pyx_L7:;

    /* "ProjectsA:Python:Pyrex:Tests:Runnable:r_primes.pyx":17 */
    __pyx_v_n = (__pyx_v_n + 1);
  }
  __pyx_L4:;

  /* "ProjectsA:Python:Pyrex:Tests:Runnable:r_primes.pyx":18 */
  Py_INCREF(__pyx_v_result);
  __pyx_r = __pyx_v_result;
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(__pyx_r);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_3);
  Py_XDECREF(__pyx_4);
  Py_XDECREF(__pyx_5);
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_result);
  return __pyx_r;
}

static struct PyMethodDef __pyx_methods[] = {
  {"primes", (PyCFunction)__pyx_f_primes, METH_VARARGS|METH_KEYWORDS, 0},
{0, 0, 0, 0}
};


void initr_primes(void); /*proto*/
void initr_primes(void) {
__pyx_m = Py_InitModule4("r_primes", __pyx_methods, 0, 0, PYTHON_API_VERSION);
__pyx_b = PyImport_AddModule("__builtin__");
PyObject_SetAttrString(__pyx_m, "__builtins__", __pyx_b);

/* "ProjectsA:Python:Pyrex:Tests:Runnable:r_primes.pyx":1 */
return;
__pyx_L1:;
}

/* Runtime support code */
