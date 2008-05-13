/* 0.9.7 on Mon May 12 23:50:23 2008 */

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

/* Declarations from inplace_lhs */

struct __pyx_t_11inplace_lhs_S {
  int q;
};

static int __pyx_f_11inplace_lhs_f(void); /*proto*/


/* Implementation of inplace_lhs */

static PyObject *__pyx_n_g;
static PyObject *__pyx_n_b;
static PyObject *__pyx_n_c;

static int __pyx_f_11inplace_lhs_f(void) {
  int __pyx_v_i;
  int __pyx_v_j;
  int __pyx_v_k;
  float __pyx_v_x;
  float __pyx_v_y;
  float __pyx_v_z;
  PyObject *__pyx_v_a;
  PyObject *__pyx_v_b;
  PyObject *__pyx_v_c;
  PyObject *__pyx_v_d;
  int __pyx_v_m[3];
  struct __pyx_t_11inplace_lhs_S __pyx_v_s;
  int __pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  __pyx_v_a = Py_None; Py_INCREF(Py_None);
  __pyx_v_b = Py_None; Py_INCREF(Py_None);
  __pyx_v_c = Py_None; Py_INCREF(Py_None);
  __pyx_v_d = Py_None; Py_INCREF(Py_None);

  /* "/Local/Projects/D/Pyrex/Source/Tests/10/inplace_lhs.pyx":11 */
  __pyx_v_i += (__pyx_v_j + __pyx_v_k);

  /* "/Local/Projects/D/Pyrex/Source/Tests/10/inplace_lhs.pyx":12 */
  __pyx_v_x += (__pyx_v_y + __pyx_v_z);

  /* "/Local/Projects/D/Pyrex/Source/Tests/10/inplace_lhs.pyx":13 */
  __pyx_v_x += __pyx_v_i;

  /* "/Local/Projects/D/Pyrex/Source/Tests/10/inplace_lhs.pyx":14 */
  __pyx_1 = PyNumber_Add(__pyx_v_b, __pyx_v_c); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 14; goto __pyx_L1;}
  __pyx_2 = PyNumber_InPlaceAdd(__pyx_v_a, __pyx_1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 14; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(__pyx_v_a);
  __pyx_v_a = __pyx_2;

  /* "/Local/Projects/D/Pyrex/Source/Tests/10/inplace_lhs.pyx":15 */
  __pyx_1 = __Pyx_GetName(__pyx_m, __pyx_n_g); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 15; goto __pyx_L1;}
  __pyx_2 = PyNumber_InPlaceAdd(__pyx_1, __pyx_v_a); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 15; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  if (PyObject_SetAttr(__pyx_m, __pyx_n_g, __pyx_2) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 15; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;

  /* "/Local/Projects/D/Pyrex/Source/Tests/10/inplace_lhs.pyx":16 */
  (__pyx_v_m[__pyx_v_i]) += __pyx_v_j;

  /* "/Local/Projects/D/Pyrex/Source/Tests/10/inplace_lhs.pyx":17 */
  __pyx_1 = PyNumber_Add(__pyx_v_b, __pyx_v_c); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 17; goto __pyx_L1;}
  __pyx_2 = PySequence_GetItem(__pyx_v_a, __pyx_v_i); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 17; goto __pyx_L1;}
  __pyx_3 = PyNumber_InPlaceAdd(__pyx_2, __pyx_1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 17; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  if (PySequence_SetItem(__pyx_v_a, __pyx_v_i, __pyx_3) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 17; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;

  /* "/Local/Projects/D/Pyrex/Source/Tests/10/inplace_lhs.pyx":18 */
  __pyx_2 = PyNumber_Add(__pyx_v_b, __pyx_v_c); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 18; goto __pyx_L1;}
  __pyx_1 = PyObject_GetItem(__pyx_v_a, __pyx_2); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 18; goto __pyx_L1;}
  __pyx_3 = PyNumber_InPlaceAdd(__pyx_1, __pyx_v_d); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 18; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  if (PyObject_SetItem(__pyx_v_a, __pyx_2, __pyx_3) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 18; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;

  /* "/Local/Projects/D/Pyrex/Source/Tests/10/inplace_lhs.pyx":19 */
  __pyx_1 = PyNumber_Add(__pyx_v_a, __pyx_v_b); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 19; goto __pyx_L1;}
  __pyx_3 = PyObject_GetItem(__pyx_1, __pyx_v_c); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 19; goto __pyx_L1;}
  __pyx_2 = PyNumber_InPlaceAdd(__pyx_3, __pyx_v_d); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 19; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  if (PyObject_SetItem(__pyx_1, __pyx_v_c, __pyx_2) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 19; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_1); __pyx_1 = 0;

  /* "/Local/Projects/D/Pyrex/Source/Tests/10/inplace_lhs.pyx":20 */
  __pyx_3 = PySequence_GetSlice(__pyx_v_a, __pyx_v_i, __pyx_v_j); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 20; goto __pyx_L1;}
  __pyx_2 = PyNumber_InPlaceAdd(__pyx_3, __pyx_v_b); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 20; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  if (PySequence_SetSlice(__pyx_v_a, __pyx_v_i, __pyx_v_j, __pyx_2) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 20; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;

  /* "/Local/Projects/D/Pyrex/Source/Tests/10/inplace_lhs.pyx":21 */
  __pyx_1 = PyNumber_Add(__pyx_v_a, __pyx_v_b); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 21; goto __pyx_L1;}
  __pyx_3 = PySequence_GetSlice(__pyx_1, __pyx_v_i, __pyx_v_j); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 21; goto __pyx_L1;}
  __pyx_2 = PyNumber_InPlaceAdd(__pyx_3, __pyx_v_c); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 21; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  if (PySequence_SetSlice(__pyx_1, __pyx_v_i, __pyx_v_j, __pyx_2) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 21; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_1); __pyx_1 = 0;

  /* "/Local/Projects/D/Pyrex/Source/Tests/10/inplace_lhs.pyx":22 */
  __pyx_3 = PyNumber_Add(__pyx_v_c, __pyx_v_d); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 22; goto __pyx_L1;}
  __pyx_2 = PyObject_GetAttr(__pyx_v_a, __pyx_n_b); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 22; goto __pyx_L1;}
  __pyx_1 = PyNumber_InPlaceAdd(__pyx_2, __pyx_3); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 22; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  if (PyObject_SetAttr(__pyx_v_a, __pyx_n_b, __pyx_1) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 22; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;

  /* "/Local/Projects/D/Pyrex/Source/Tests/10/inplace_lhs.pyx":23 */
  __pyx_2 = PyNumber_Add(__pyx_v_a, __pyx_v_b); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 23; goto __pyx_L1;}
  __pyx_3 = PyObject_GetAttr(__pyx_2, __pyx_n_c); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 23; goto __pyx_L1;}
  __pyx_1 = PyNumber_InPlaceAdd(__pyx_3, __pyx_v_d); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 23; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  if (PyObject_SetAttr(__pyx_2, __pyx_n_c, __pyx_1) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 23; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;

  /* "/Local/Projects/D/Pyrex/Source/Tests/10/inplace_lhs.pyx":24 */
  __pyx_v_s.q += __pyx_v_i;

  __pyx_r = 0;
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  __Pyx_AddTraceback("inplace_lhs.f");
  __pyx_r = (-1);
  __pyx_L0:;
  Py_DECREF(__pyx_v_a);
  Py_DECREF(__pyx_v_b);
  Py_DECREF(__pyx_v_c);
  Py_DECREF(__pyx_v_d);
  return __pyx_r;
}

static __Pyx_InternTabEntry __pyx_intern_tab[] = {
  {&__pyx_n_b, "b"},
  {&__pyx_n_c, "c"},
  {&__pyx_n_g, "g"},
  {0, 0}
};

static struct PyMethodDef __pyx_methods[] = {
  {0, 0, 0, 0}
};

static void __pyx_init_filenames(void); /*proto*/

PyMODINIT_FUNC initinplace_lhs(void); /*proto*/
PyMODINIT_FUNC initinplace_lhs(void) {
  __pyx_init_filenames();
  __pyx_m = Py_InitModule4("inplace_lhs", __pyx_methods, 0, 0, PYTHON_API_VERSION);
  if (!__pyx_m) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; goto __pyx_L1;};
  Py_INCREF(__pyx_m);
  __pyx_b = PyImport_AddModule("__builtin__");
  if (!__pyx_b) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; goto __pyx_L1;};
  if (PyObject_SetAttrString(__pyx_m, "__builtins__", __pyx_b) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; goto __pyx_L1;};
  if (__Pyx_InternStrings(__pyx_intern_tab) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; goto __pyx_L1;};

  /* "/Local/Projects/D/Pyrex/Source/Tests/10/inplace_lhs.pyx":4 */
  return;
  __pyx_L1:;
  __Pyx_AddTraceback("inplace_lhs");
}

static char *__pyx_filenames[] = {
  "inplace_lhs.pyx",
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
