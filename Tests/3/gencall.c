/* Generated by Pyrex 0.9.6.4 on Sun Mar 30 09:29:18 2008 */

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
#ifndef WIN32
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


typedef struct {PyObject **p; char *s;} __Pyx_InternTabEntry; /*proto*/
typedef struct {PyObject **p; char *s; long n;} __Pyx_StringTabEntry; /*proto*/

static PyObject *__pyx_m;
static PyObject *__pyx_b;
static int __pyx_lineno;
static char *__pyx_filename;
static char **__pyx_f;

static PyObject *__Pyx_GetName(PyObject *dict, PyObject *name); /*proto*/

static int __Pyx_InternStrings(__Pyx_InternTabEntry *t); /*proto*/

static void __Pyx_AddTraceback(char *funcname); /*proto*/

/* Declarations from gencall */



/* Implementation of gencall */

static PyObject *__pyx_f_7gencall_f(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_7gencall_f(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_x = 0;
  PyObject *__pyx_v_y = 0;
  PyObject *__pyx_r;
  static char *__pyx_argnames[] = {"x","y",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "OO", __pyx_argnames, &__pyx_v_x, &__pyx_v_y)) return 0;
  Py_INCREF(__pyx_v_x);
  Py_INCREF(__pyx_v_y);
  Py_INCREF(__pyx_v_y);
  Py_DECREF(__pyx_v_x);
  __pyx_v_x = __pyx_v_y;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  Py_DECREF(__pyx_v_x);
  Py_DECREF(__pyx_v_y);
  return __pyx_r;
}

static PyObject *__pyx_n_f;
static PyObject *__pyx_n_x;
static PyObject *__pyx_n_y;
static PyObject *__pyx_n_spam;


static PyObject *__pyx_f_7gencall_z(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_7gencall_z(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_a = 0;
  PyObject *__pyx_v_b = 0;
  PyObject *__pyx_v_c = 0;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  PyObject *__pyx_4 = 0;
  static char *__pyx_argnames[] = {"a","b","c",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "OOO", __pyx_argnames, &__pyx_v_a, &__pyx_v_b, &__pyx_v_c)) return 0;
  Py_INCREF(__pyx_v_a);
  Py_INCREF(__pyx_v_b);
  Py_INCREF(__pyx_v_c);

  /* "/Local/Projects/D/Pyrex/Source/Tests/3/gencall.pyx":5 */
  __pyx_1 = __Pyx_GetName(__pyx_m, __pyx_n_f); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 5; goto __pyx_L1;}
  __pyx_2 = PyTuple_New(0); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 5; goto __pyx_L1;}
  __pyx_3 = PyDict_New(); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 5; goto __pyx_L1;}
  __pyx_4 = PyInt_FromLong(42); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 5; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_3, __pyx_n_x, __pyx_4) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 5; goto __pyx_L1;}
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  if (PyDict_SetItem(__pyx_3, __pyx_n_y, __pyx_n_spam) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 5; goto __pyx_L1;}
  __pyx_4 = PyEval_CallObjectWithKeywords(__pyx_1, __pyx_2, __pyx_3); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 5; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  Py_DECREF(__pyx_4); __pyx_4 = 0;

  /* "/Local/Projects/D/Pyrex/Source/Tests/3/gencall.pyx":6 */
  __pyx_1 = __Pyx_GetName(__pyx_m, __pyx_n_f); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 6; goto __pyx_L1;}
  __pyx_2 = PySequence_Tuple(__pyx_v_a); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 6; goto __pyx_L1;}
  __pyx_3 = PyObject_CallObject(__pyx_1, __pyx_2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 6; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_3); __pyx_3 = 0;

  /* "/Local/Projects/D/Pyrex/Source/Tests/3/gencall.pyx":7 */
  __pyx_4 = __Pyx_GetName(__pyx_m, __pyx_n_f); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 7; goto __pyx_L1;}
  __pyx_1 = PyTuple_New(0); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 7; goto __pyx_L1;}
  __pyx_2 = PyEval_CallObjectWithKeywords(__pyx_4, __pyx_1, __pyx_v_b); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 7; goto __pyx_L1;}
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;

  /* "/Local/Projects/D/Pyrex/Source/Tests/3/gencall.pyx":8 */
  __pyx_3 = __Pyx_GetName(__pyx_m, __pyx_n_f); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 8; goto __pyx_L1;}
  __pyx_4 = PyTuple_New(0); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 8; goto __pyx_L1;}
  __pyx_1 = PyDict_New(); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 8; goto __pyx_L1;}
  __pyx_2 = PyInt_FromLong(42); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 8; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_1, __pyx_n_x, __pyx_2) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 8; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  if (PyDict_Update(__pyx_1, __pyx_v_b) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 8; goto __pyx_L1;}
  __pyx_2 = PyEval_CallObjectWithKeywords(__pyx_3, __pyx_4, __pyx_1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 8; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;

  /* "/Local/Projects/D/Pyrex/Source/Tests/3/gencall.pyx":9 */
  __pyx_3 = __Pyx_GetName(__pyx_m, __pyx_n_f); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 9; goto __pyx_L1;}
  __pyx_4 = PyTuple_New(1); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 9; goto __pyx_L1;}
  Py_INCREF(__pyx_v_a);
  PyTuple_SET_ITEM(__pyx_4, 0, __pyx_v_a);
  __pyx_1 = PySequence_Tuple(__pyx_v_b); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 9; goto __pyx_L1;}
  __pyx_2 = PyNumber_Add(__pyx_4, __pyx_1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 9; goto __pyx_L1;}
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_4 = PyObject_CallObject(__pyx_3, __pyx_2); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 9; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_4); __pyx_4 = 0;

  /* "/Local/Projects/D/Pyrex/Source/Tests/3/gencall.pyx":10 */
  __pyx_1 = __Pyx_GetName(__pyx_m, __pyx_n_f); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 10; goto __pyx_L1;}
  __pyx_3 = PyTuple_New(1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 10; goto __pyx_L1;}
  Py_INCREF(__pyx_v_a);
  PyTuple_SET_ITEM(__pyx_3, 0, __pyx_v_a);
  __pyx_2 = PySequence_Tuple(__pyx_v_b); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 10; goto __pyx_L1;}
  __pyx_4 = PyNumber_Add(__pyx_3, __pyx_2); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 10; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  __pyx_3 = PyDict_New(); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 10; goto __pyx_L1;}
  __pyx_2 = PyInt_FromLong(42); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 10; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_3, __pyx_n_x, __pyx_2) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 10; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  if (PyDict_Update(__pyx_3, __pyx_v_c) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 10; goto __pyx_L1;}
  __pyx_2 = PyEval_CallObjectWithKeywords(__pyx_1, __pyx_4, __pyx_3); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 10; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  Py_XDECREF(__pyx_4);
  __Pyx_AddTraceback("gencall.z");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_a);
  Py_DECREF(__pyx_v_b);
  Py_DECREF(__pyx_v_c);
  return __pyx_r;
}

static __Pyx_InternTabEntry __pyx_intern_tab[] = {
  {&__pyx_n_f, "f"},
  {&__pyx_n_spam, "spam"},
  {&__pyx_n_x, "x"},
  {&__pyx_n_y, "y"},
  {0, 0}
};

static struct PyMethodDef __pyx_methods[] = {
  {"f", (PyCFunction)__pyx_f_7gencall_f, METH_VARARGS|METH_KEYWORDS, 0},
  {"z", (PyCFunction)__pyx_f_7gencall_z, METH_VARARGS|METH_KEYWORDS, 0},
  {0, 0, 0, 0}
};

static void __pyx_init_filenames(void); /*proto*/

PyMODINIT_FUNC initgencall(void); /*proto*/
PyMODINIT_FUNC initgencall(void) {
  __pyx_init_filenames();
  __pyx_m = Py_InitModule4("gencall", __pyx_methods, 0, 0, PYTHON_API_VERSION);
  if (!__pyx_m) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; goto __pyx_L1;};
  Py_INCREF(__pyx_m);
  __pyx_b = PyImport_AddModule("__builtin__");
  if (!__pyx_b) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; goto __pyx_L1;};
  if (PyObject_SetAttrString(__pyx_m, "__builtins__", __pyx_b) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; goto __pyx_L1;};
  if (__Pyx_InternStrings(__pyx_intern_tab) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; goto __pyx_L1;};

  /* "/Local/Projects/D/Pyrex/Source/Tests/3/gencall.pyx":4 */
  return;
  __pyx_L1:;
  __Pyx_AddTraceback("gencall");
}

static char *__pyx_filenames[] = {
  "gencall.pyx",
};

/* Runtime support code */

static void __pyx_init_filenames(void) {
  __pyx_f = __pyx_filenames;
}

static PyObject *__Pyx_GetName(PyObject *dict, PyObject *name) {
	PyObject *result;
	result = PyObject_GetAttr(dict, name);
	if (!result)
		PyErr_SetObject(PyExc_NameError, name);
	return result;
}

static int __Pyx_InternStrings(__Pyx_InternTabEntry *t) {
	while (t->p) {
		*t->p = PyString_InternFromString(t->s);
		if (!*t->p)
			return -1;
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
