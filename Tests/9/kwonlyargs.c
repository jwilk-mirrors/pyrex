/* Generated by Pyrex */

#define PY_SSIZE_T_CLEAN
#include "Python.h"
#include "structmember.h"
#ifndef PY_LONG_LONG
  #define PY_LONG_LONG LONG_LONG
#endif
#if PY_VERSION_HEX < 0x02050000
  typedef int Py_ssize_t;
  #define PY_SSIZE_T_MAX INT_MAX
  #define PY_SSIZE_T_MIN INT_MIN
  #define PyInt_FromSsize_t(z) PyInt_FromLong(z)
  #define PyInt_AsSsize_t(o)	PyInt_AsLong(o)
#endif
#if !defined(WIN32) && !defined(MS_WINDOWS)
  #ifndef __stdcall
    #define __stdcall
  #endif
  #ifndef __cdecl
    #define __cdecl
  #endif
#endif
#ifdef __cplusplus
#define __PYX_EXTERN_C extern "C"
#else
#define __PYX_EXTERN_C extern
#endif
#include <math.h>


typedef struct {PyObject **p; int i; char *s; long n;} __Pyx_StringTabEntry; /*proto*/

static PyObject *__pyx_m;
static PyObject *__pyx_b;
static int __pyx_lineno;
static char *__pyx_filename;
static char **__pyx_f;

static int __Pyx_GetStarArgs(PyObject **args, PyObject **kwds, char *kwd_list[], 	Py_ssize_t nargs, PyObject **args2, PyObject **kwds2, char rqd_kwds[]); /*proto*/

static int __Pyx_InitStrings(__Pyx_StringTabEntry *t); /*proto*/

static void __Pyx_AddTraceback(char *funcname); /*proto*/

/* Declarations from kwonlyargs */


/* Declarations from implementation of kwonlyargs */





static __Pyx_StringTabEntry __pyx_string_tab[] = {
  {0, 0, 0, 0}
};

static PyObject *__pyx_d1;
static PyObject *__pyx_d2;
static PyObject *__pyx_d3;
static PyObject *__pyx_d4;
static PyObject *__pyx_d5;
static PyObject *__pyx_d6;
static PyObject *__pyx_d7;


/* Implementation of kwonlyargs */

static PyObject *__pyx_f_10kwonlyargs_c(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_10kwonlyargs_c(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_a = 0;
  PyObject *__pyx_v_b = 0;
  PyObject *__pyx_v_c = 0;
  PyObject *__pyx_v_z;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  static char *__pyx_argnames[] = {"a","b","c",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "OOO", __pyx_argnames, &__pyx_v_a, &__pyx_v_b, &__pyx_v_c)) return 0;
  Py_INCREF(__pyx_v_a);
  Py_INCREF(__pyx_v_b);
  Py_INCREF(__pyx_v_c);
  __pyx_v_z = Py_None; Py_INCREF(Py_None);
  __pyx_1 = PyInt_FromLong(33); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 2; goto __pyx_L1;}
  Py_DECREF(__pyx_v_z);
  __pyx_v_z = __pyx_1;
  __pyx_1 = 0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  __Pyx_AddTraceback("kwonlyargs.c");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_z);
  Py_DECREF(__pyx_v_a);
  Py_DECREF(__pyx_v_b);
  Py_DECREF(__pyx_v_c);
  return __pyx_r;
}

static PyObject *__pyx_f_10kwonlyargs_d(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_10kwonlyargs_d(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_a = 0;
  PyObject *__pyx_v_b = 0;
  PyObject *__pyx_v_c = 0;
  PyObject *__pyx_v_z;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  static char *__pyx_argnames[] = {"a","b","c",0};
  __pyx_v_c = __pyx_d1;
  if (__Pyx_GetStarArgs(&__pyx_args, &__pyx_kwds, __pyx_argnames, 2, 0, 0, 0) < 0) return 0;
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "OO|O", __pyx_argnames, &__pyx_v_a, &__pyx_v_b, &__pyx_v_c)) {
    Py_XDECREF(__pyx_args);
    Py_XDECREF(__pyx_kwds);
    return 0;
  }
  Py_INCREF(__pyx_v_a);
  Py_INCREF(__pyx_v_b);
  Py_INCREF(__pyx_v_c);
  __pyx_v_z = Py_None; Py_INCREF(Py_None);
  __pyx_1 = PyInt_FromLong(44); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 5; goto __pyx_L1;}
  Py_DECREF(__pyx_v_z);
  __pyx_v_z = __pyx_1;
  __pyx_1 = 0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  __Pyx_AddTraceback("kwonlyargs.d");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_z);
  Py_DECREF(__pyx_v_a);
  Py_DECREF(__pyx_v_b);
  Py_DECREF(__pyx_v_c);
  Py_XDECREF(__pyx_args);
  Py_XDECREF(__pyx_kwds);
  return __pyx_r;
}

static PyObject *__pyx_f_10kwonlyargs_e(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_10kwonlyargs_e(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_a = 0;
  PyObject *__pyx_v_b = 0;
  PyObject *__pyx_v_c = 0;
  PyObject *__pyx_v_kwds = 0;
  PyObject *__pyx_v_z;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  static char *__pyx_argnames[] = {"a","b","c",0};
  __pyx_v_c = __pyx_d2;
  if (__Pyx_GetStarArgs(&__pyx_args, &__pyx_kwds, __pyx_argnames, 3, 0, &__pyx_v_kwds, 0) < 0) return 0;
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "OO|O", __pyx_argnames, &__pyx_v_a, &__pyx_v_b, &__pyx_v_c)) {
    Py_XDECREF(__pyx_args);
    Py_XDECREF(__pyx_kwds);
    Py_XDECREF(__pyx_v_kwds);
    return 0;
  }
  Py_INCREF(__pyx_v_a);
  Py_INCREF(__pyx_v_b);
  Py_INCREF(__pyx_v_c);
  __pyx_v_z = Py_None; Py_INCREF(Py_None);
  __pyx_1 = PyInt_FromLong(55); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 8; goto __pyx_L1;}
  Py_DECREF(__pyx_v_z);
  __pyx_v_z = __pyx_1;
  __pyx_1 = 0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  __Pyx_AddTraceback("kwonlyargs.e");
  __pyx_r = 0;
  __pyx_L0:;
  Py_XDECREF(__pyx_v_kwds);
  Py_DECREF(__pyx_v_z);
  Py_DECREF(__pyx_v_a);
  Py_DECREF(__pyx_v_b);
  Py_DECREF(__pyx_v_c);
  Py_XDECREF(__pyx_args);
  Py_XDECREF(__pyx_kwds);
  return __pyx_r;
}

static PyObject *__pyx_f_10kwonlyargs_f(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_10kwonlyargs_f(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_a = 0;
  PyObject *__pyx_v_b = 0;
  PyObject *__pyx_v_c = 0;
  PyObject *__pyx_v_d = 0;
  PyObject *__pyx_v_z;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  static char *__pyx_argnames[] = {"a","b","c","d",0};
  static char __pyx_reqd_kwds[] = {0,0,1,0};
  __pyx_v_d = __pyx_d3;
  if (__Pyx_GetStarArgs(&__pyx_args, &__pyx_kwds, __pyx_argnames, 2, 0, 0, __pyx_reqd_kwds) < 0) return 0;
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "OOO|O", __pyx_argnames, &__pyx_v_a, &__pyx_v_b, &__pyx_v_c, &__pyx_v_d)) {
    Py_XDECREF(__pyx_args);
    Py_XDECREF(__pyx_kwds);
    return 0;
  }
  Py_INCREF(__pyx_v_a);
  Py_INCREF(__pyx_v_b);
  Py_INCREF(__pyx_v_c);
  Py_INCREF(__pyx_v_d);
  __pyx_v_z = Py_None; Py_INCREF(Py_None);
  __pyx_1 = PyInt_FromLong(66); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 11; goto __pyx_L1;}
  Py_DECREF(__pyx_v_z);
  __pyx_v_z = __pyx_1;
  __pyx_1 = 0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  __Pyx_AddTraceback("kwonlyargs.f");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_z);
  Py_DECREF(__pyx_v_a);
  Py_DECREF(__pyx_v_b);
  Py_DECREF(__pyx_v_c);
  Py_DECREF(__pyx_v_d);
  Py_XDECREF(__pyx_args);
  Py_XDECREF(__pyx_kwds);
  return __pyx_r;
}

static PyObject *__pyx_f_10kwonlyargs_g(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_10kwonlyargs_g(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_a = 0;
  PyObject *__pyx_v_b = 0;
  PyObject *__pyx_v_c = 0;
  PyObject *__pyx_v_d = 0;
  PyObject *__pyx_v_e = 0;
  PyObject *__pyx_v_f = 0;
  PyObject *__pyx_v_kwds = 0;
  PyObject *__pyx_v_z;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  static char *__pyx_argnames[] = {"a","b","c","d","e","f",0};
  static char __pyx_reqd_kwds[] = {0,0,1,0,0,1};
  __pyx_v_d = __pyx_d4;
  __pyx_v_e = __pyx_d5;
  if (__Pyx_GetStarArgs(&__pyx_args, &__pyx_kwds, __pyx_argnames, 2, 0, &__pyx_v_kwds, __pyx_reqd_kwds) < 0) return 0;
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "OOO|OOO", __pyx_argnames, &__pyx_v_a, &__pyx_v_b, &__pyx_v_c, &__pyx_v_d, &__pyx_v_e, &__pyx_v_f)) {
    Py_XDECREF(__pyx_args);
    Py_XDECREF(__pyx_kwds);
    Py_XDECREF(__pyx_v_kwds);
    return 0;
  }
  Py_INCREF(__pyx_v_a);
  Py_INCREF(__pyx_v_b);
  Py_INCREF(__pyx_v_c);
  Py_INCREF(__pyx_v_d);
  Py_INCREF(__pyx_v_e);
  Py_INCREF(__pyx_v_f);
  __pyx_v_z = Py_None; Py_INCREF(Py_None);
  __pyx_1 = PyInt_FromLong(77); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 14; goto __pyx_L1;}
  Py_DECREF(__pyx_v_z);
  __pyx_v_z = __pyx_1;
  __pyx_1 = 0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  __Pyx_AddTraceback("kwonlyargs.g");
  __pyx_r = 0;
  __pyx_L0:;
  Py_XDECREF(__pyx_v_kwds);
  Py_DECREF(__pyx_v_z);
  Py_DECREF(__pyx_v_a);
  Py_DECREF(__pyx_v_b);
  Py_DECREF(__pyx_v_c);
  Py_DECREF(__pyx_v_d);
  Py_DECREF(__pyx_v_e);
  Py_DECREF(__pyx_v_f);
  Py_XDECREF(__pyx_args);
  Py_XDECREF(__pyx_kwds);
  return __pyx_r;
}

static PyObject *__pyx_f_10kwonlyargs_h(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_10kwonlyargs_h(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_a = 0;
  PyObject *__pyx_v_b = 0;
  PyObject *__pyx_v_c = 0;
  PyObject *__pyx_v_d = 0;
  PyObject *__pyx_v_e = 0;
  PyObject *__pyx_v_f = 0;
  PyObject *__pyx_v_args = 0;
  PyObject *__pyx_v_kwds = 0;
  PyObject *__pyx_v_z;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  static char *__pyx_argnames[] = {"a","b","c","d","e","f",0};
  static char __pyx_reqd_kwds[] = {0,0,1,0,0,1};
  __pyx_v_d = __pyx_d6;
  __pyx_v_e = __pyx_d7;
  if (__Pyx_GetStarArgs(&__pyx_args, &__pyx_kwds, __pyx_argnames, 2, &__pyx_v_args, &__pyx_v_kwds, __pyx_reqd_kwds) < 0) return 0;
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "OOO|OOO", __pyx_argnames, &__pyx_v_a, &__pyx_v_b, &__pyx_v_c, &__pyx_v_d, &__pyx_v_e, &__pyx_v_f)) {
    Py_XDECREF(__pyx_args);
    Py_XDECREF(__pyx_kwds);
    Py_XDECREF(__pyx_v_args);
    Py_XDECREF(__pyx_v_kwds);
    return 0;
  }
  Py_INCREF(__pyx_v_a);
  Py_INCREF(__pyx_v_b);
  Py_INCREF(__pyx_v_c);
  Py_INCREF(__pyx_v_d);
  Py_INCREF(__pyx_v_e);
  Py_INCREF(__pyx_v_f);
  __pyx_v_z = Py_None; Py_INCREF(Py_None);
  __pyx_1 = PyInt_FromLong(88); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 17; goto __pyx_L1;}
  Py_DECREF(__pyx_v_z);
  __pyx_v_z = __pyx_1;
  __pyx_1 = 0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  __Pyx_AddTraceback("kwonlyargs.h");
  __pyx_r = 0;
  __pyx_L0:;
  Py_XDECREF(__pyx_v_args);
  Py_XDECREF(__pyx_v_kwds);
  Py_DECREF(__pyx_v_z);
  Py_DECREF(__pyx_v_a);
  Py_DECREF(__pyx_v_b);
  Py_DECREF(__pyx_v_c);
  Py_DECREF(__pyx_v_d);
  Py_DECREF(__pyx_v_e);
  Py_DECREF(__pyx_v_f);
  Py_XDECREF(__pyx_args);
  Py_XDECREF(__pyx_kwds);
  return __pyx_r;
}

static struct PyMethodDef __pyx_methods[] = {
  {"c", (PyCFunction)__pyx_f_10kwonlyargs_c, METH_VARARGS|METH_KEYWORDS, 0},
  {"d", (PyCFunction)__pyx_f_10kwonlyargs_d, METH_VARARGS|METH_KEYWORDS, 0},
  {"e", (PyCFunction)__pyx_f_10kwonlyargs_e, METH_VARARGS|METH_KEYWORDS, 0},
  {"f", (PyCFunction)__pyx_f_10kwonlyargs_f, METH_VARARGS|METH_KEYWORDS, 0},
  {"g", (PyCFunction)__pyx_f_10kwonlyargs_g, METH_VARARGS|METH_KEYWORDS, 0},
  {"h", (PyCFunction)__pyx_f_10kwonlyargs_h, METH_VARARGS|METH_KEYWORDS, 0},
  {0, 0, 0, 0}
};

static void __pyx_init_filenames(void); /*proto*/

PyMODINIT_FUNC initkwonlyargs(void); /*proto*/
PyMODINIT_FUNC initkwonlyargs(void) {
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  PyObject *__pyx_4 = 0;
  PyObject *__pyx_5 = 0;
  PyObject *__pyx_6 = 0;
  PyObject *__pyx_7 = 0;
  __pyx_init_filenames();
  __pyx_m = Py_InitModule4("kwonlyargs", __pyx_methods, 0, 0, PYTHON_API_VERSION);
  if (!__pyx_m) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; goto __pyx_L1;};
  Py_INCREF(__pyx_m);
  __pyx_b = PyImport_AddModule("__builtin__");
  if (!__pyx_b) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; goto __pyx_L1;};
  if (PyObject_SetAttrString(__pyx_m, "__builtins__", __pyx_b) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; goto __pyx_L1;};
  if (__Pyx_InitStrings(__pyx_string_tab) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; goto __pyx_L1;};

  /* "/Local/Projects/D/Pyrex/Source/Tests/9/kwonlyargs.pyx":4 */
  __pyx_1 = PyInt_FromLong(88); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 4; goto __pyx_L1;}
  __pyx_d1 = __pyx_1;
  __pyx_1 = 0;

  /* "/Local/Projects/D/Pyrex/Source/Tests/9/kwonlyargs.pyx":7 */
  __pyx_2 = PyInt_FromLong(88); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 7; goto __pyx_L1;}
  __pyx_d2 = __pyx_2;
  __pyx_2 = 0;

  /* "/Local/Projects/D/Pyrex/Source/Tests/9/kwonlyargs.pyx":10 */
  __pyx_3 = PyInt_FromLong(42); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 10; goto __pyx_L1;}
  __pyx_d3 = __pyx_3;
  __pyx_3 = 0;

  /* "/Local/Projects/D/Pyrex/Source/Tests/9/kwonlyargs.pyx":13 */
  __pyx_4 = PyInt_FromLong(42); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 13; goto __pyx_L1;}
  __pyx_d4 = __pyx_4;
  __pyx_4 = 0;
  __pyx_5 = PyInt_FromLong(17); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 13; goto __pyx_L1;}
  __pyx_d5 = __pyx_5;
  __pyx_5 = 0;

  /* "/Local/Projects/D/Pyrex/Source/Tests/9/kwonlyargs.pyx":16 */
  __pyx_6 = PyInt_FromLong(42); if (!__pyx_6) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 16; goto __pyx_L1;}
  __pyx_d6 = __pyx_6;
  __pyx_6 = 0;
  __pyx_7 = PyInt_FromLong(17); if (!__pyx_7) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 16; goto __pyx_L1;}
  __pyx_d7 = __pyx_7;
  __pyx_7 = 0;
  return;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  Py_XDECREF(__pyx_4);
  Py_XDECREF(__pyx_5);
  Py_XDECREF(__pyx_6);
  Py_XDECREF(__pyx_7);
  __Pyx_AddTraceback("kwonlyargs");
}

static char *__pyx_filenames[] = {
  "kwonlyargs.pyx",
};

/* Runtime support code */

static void __pyx_init_filenames(void) {
  __pyx_f = __pyx_filenames;
}

static int __Pyx_GetStarArgs(
	PyObject **args, 
	PyObject **kwds,
	char *kwd_list[], 
	Py_ssize_t nargs,
	PyObject **args2, 
	PyObject **kwds2,
	char rqd_kwds[])
{
	PyObject *x = 0, *args1 = 0, *kwds1 = 0;
	int i;
	char **p;
	
	if (args2)
		*args2 = 0;
	if (kwds2)
		*kwds2 = 0;
	
	if (args2) {
		args1 = PyTuple_GetSlice(*args, 0, nargs);
		if (!args1)
			goto bad;
		*args2 = PyTuple_GetSlice(*args, nargs, PyTuple_GET_SIZE(*args));
		if (!*args2)
			goto bad;
	}
	else if (PyTuple_GET_SIZE(*args) > nargs) {
		int m = nargs;
		int n = PyTuple_GET_SIZE(*args);
		PyErr_Format(PyExc_TypeError,
			"function takes at most %d positional arguments (%d given)",
				m, n);
		goto bad;
	}
	else {
		args1 = *args;
		Py_INCREF(args1);
	}
	
	if (rqd_kwds && !*kwds)
			for (i = 0, p = kwd_list; *p; i++, p++)
				if (rqd_kwds[i])
					goto missing_kwarg;
	
	if (kwds2) {
		if (*kwds) {
			kwds1 = PyDict_New();
			if (!kwds1)
				goto bad;
			*kwds2 = PyDict_Copy(*kwds);
			if (!*kwds2)
				goto bad;
			for (i = 0, p = kwd_list; *p; i++, p++) {
				x = PyDict_GetItemString(*kwds, *p);
				if (x) {
					if (PyDict_SetItemString(kwds1, *p, x) < 0)
						goto bad;
					if (PyDict_DelItemString(*kwds2, *p) < 0)
						goto bad;
				}
				else if (rqd_kwds && rqd_kwds[i])
					goto missing_kwarg;
			}
		}
		else {
			*kwds2 = PyDict_New();
			if (!*kwds2)
				goto bad;
		}
	}
	else {
		kwds1 = *kwds;
		Py_XINCREF(kwds1);
		if (rqd_kwds && *kwds)
			for (i = 0, p = kwd_list; *p; i++, p++)
				if (rqd_kwds[i] && !PyDict_GetItemString(*kwds, *p))
						goto missing_kwarg;
	}
	
	*args = args1;
	*kwds = kwds1;
	return 0;
missing_kwarg:
	PyErr_Format(PyExc_TypeError,
		"required keyword argument '%s' is missing", *p);
bad:
	Py_XDECREF(args1);
	Py_XDECREF(kwds1);
	if (args2) {
		Py_XDECREF(*args2);
	}
	if (kwds2) {
		Py_XDECREF(*kwds2);
	}
	return -1;
}

static int __Pyx_InitStrings(__Pyx_StringTabEntry *t) {
	while (t->p) {
		*t->p = PyString_FromStringAndSize(t->s, t->n - 1);
		if (!*t->p)
			return -1;
		if (t->i)
			PyString_InternInPlace(t->p);
		++t;
	}
	return 0;
}

#include "compile.h"
#include "frameobject.h"
#include "traceback.h"

static void __Pyx_AddTraceback(char *funcname) {
	PyObject *py_srcfile = 0;
	PyObject *py_funcname = 0;
	PyObject *py_globals = 0;
	PyObject *empty_tuple = 0;
	PyObject *empty_string = 0;
	PyCodeObject *py_code = 0;
	PyFrameObject *py_frame = 0;
	
	py_srcfile = PyString_FromString(__pyx_filename);
	if (!py_srcfile) goto bad;
	py_funcname = PyString_FromString(funcname);
	if (!py_funcname) goto bad;
	py_globals = PyModule_GetDict(__pyx_m);
	if (!py_globals) goto bad;
	empty_tuple = PyTuple_New(0);
	if (!empty_tuple) goto bad;
	empty_string = PyString_FromString("");
	if (!empty_string) goto bad;
	py_code = PyCode_New(
		0,            /*int argcount,*/
		0,            /*int nlocals,*/
		0,            /*int stacksize,*/
		0,            /*int flags,*/
		empty_string, /*PyObject *code,*/
		empty_tuple,  /*PyObject *consts,*/
		empty_tuple,  /*PyObject *names,*/
		empty_tuple,  /*PyObject *varnames,*/
		empty_tuple,  /*PyObject *freevars,*/
		empty_tuple,  /*PyObject *cellvars,*/
		py_srcfile,   /*PyObject *filename,*/
		py_funcname,  /*PyObject *name,*/
		__pyx_lineno,   /*int firstlineno,*/
		empty_string  /*PyObject *lnotab*/
	);
	if (!py_code) goto bad;
	py_frame = PyFrame_New(
		PyThreadState_Get(), /*PyThreadState *tstate,*/
		py_code,             /*PyCodeObject *code,*/
		py_globals,          /*PyObject *globals,*/
		0                    /*PyObject *locals*/
	);
	if (!py_frame) goto bad;
	py_frame->f_lineno = __pyx_lineno;
	PyTraceBack_Here(py_frame);
bad:
	Py_XDECREF(py_srcfile);
	Py_XDECREF(py_funcname);
	Py_XDECREF(empty_tuple);
	Py_XDECREF(empty_string);
	Py_XDECREF(py_code);
	Py_XDECREF(py_frame);
}
