/* Generated by Pyrex 0.9.6.3 on Sun Dec  2 15:07:09 2007 */

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

static int __Pyx_ArgTypeTest(PyObject *obj, PyTypeObject *type, int none_allowed, char *name); /*proto*/

static PyTypeObject *__Pyx_ImportType(char *module_name, char *class_name, long size);  /*proto*/

static PyObject *__Pyx_ImportModule(char *name); /*proto*/

static void __Pyx_AddTraceback(char *funcname); /*proto*/

/* Declarations from extargdefault */

struct __pyx_obj_13extargdefault_Swallow {
  PyObject_HEAD
};


static PyTypeObject *__pyx_ptype_13extargdefault_Swallow = 0;
static struct __pyx_obj_13extargdefault_Swallow *__pyx_v_13extargdefault_swallow;
static PyObject *__pyx_k1;
static struct __pyx_obj_13extargdefault_Swallow *__pyx_k2;


/* Implementation of extargdefault */

static PyObject *__pyx_f_13extargdefault_spam(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_13extargdefault_spam(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_x = 0;
  struct __pyx_obj_13extargdefault_Swallow *__pyx_v_y = 0;
  PyObject *__pyx_r;
  static char *__pyx_argnames[] = {"x","y",0};
  __pyx_v_x = __pyx_k1;
  __pyx_v_y = __pyx_k2;
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "|OO", __pyx_argnames, &__pyx_v_x, &__pyx_v_y)) return 0;
  Py_INCREF(__pyx_v_x);
  Py_INCREF(__pyx_v_y);
  if (!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_y), __pyx_ptype_13extargdefault_Swallow, 1, "y")) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 6; goto __pyx_L1;}

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  __Pyx_AddTraceback("extargdefault.spam");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_x);
  Py_DECREF(__pyx_v_y);
  return __pyx_r;
}

static struct PyMethodDef __pyx_methods[] = {
  {"spam", (PyCFunction)__pyx_f_13extargdefault_spam, METH_VARARGS|METH_KEYWORDS, 0},
  {0, 0, 0, 0}
};

static void __pyx_init_filenames(void); /*proto*/

PyMODINIT_FUNC initextargdefault(void); /*proto*/
PyMODINIT_FUNC initextargdefault(void) {
  __pyx_init_filenames();
  __pyx_m = Py_InitModule4("extargdefault", __pyx_methods, 0, 0, PYTHON_API_VERSION);
  if (!__pyx_m) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; goto __pyx_L1;};
  Py_INCREF(__pyx_m);
  __pyx_b = PyImport_AddModule("__builtin__");
  if (!__pyx_b) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; goto __pyx_L1;};
  if (PyObject_SetAttrString(__pyx_m, "__builtins__", __pyx_b) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; goto __pyx_L1;};
  __pyx_v_13extargdefault_swallow = ((struct __pyx_obj_13extargdefault_Swallow *)Py_None); Py_INCREF(Py_None);
  __pyx_ptype_13extargdefault_Swallow = __Pyx_ImportType("somewhere", "Swallow", sizeof(struct __pyx_obj_13extargdefault_Swallow)); if (!__pyx_ptype_13extargdefault_Swallow) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; goto __pyx_L1;}

  /* "/Local/Projects/D/Pyrex/Source/Tests/5/extargdefault.pyx":6 */
  Py_INCREF(((PyObject *)__pyx_v_13extargdefault_swallow));
  __pyx_k1 = ((PyObject *)__pyx_v_13extargdefault_swallow);
  Py_INCREF(((PyObject *)__pyx_v_13extargdefault_swallow));
  __pyx_k2 = __pyx_v_13extargdefault_swallow;
  return;
  __pyx_L1:;
  __Pyx_AddTraceback("extargdefault");
}

static char *__pyx_filenames[] = {
  "extargdefault.pyx",
};

/* Runtime support code */

static void __pyx_init_filenames(void) {
  __pyx_f = __pyx_filenames;
}

static int __Pyx_ArgTypeTest(PyObject *obj, PyTypeObject *type, int none_allowed, char *name) {
	if (!type) {
		PyErr_Format(PyExc_SystemError, "Missing type object");
		return 0;
	}
	if ((none_allowed && obj == Py_None) || PyObject_TypeCheck(obj, type))
		return 1;
	PyErr_Format(PyExc_TypeError,
		"Argument '%s' has incorrect type (expected %s, got %s)",
		name, type->tp_name, obj->ob_type->tp_name);
	return 0;
}

#ifndef __PYX_HAVE_RT_ImportType
#define __PYX_HAVE_RT_ImportType
static PyTypeObject *__Pyx_ImportType(char *module_name, char *class_name, 
	long size) 
{
	PyObject *py_module = 0;
	PyObject *result = 0;
	
	py_module = __Pyx_ImportModule(module_name);
	if (!py_module)
		goto bad;
	result = PyObject_GetAttrString(py_module, class_name);
	if (!result)
		goto bad;
	if (!PyType_Check(result)) {
		PyErr_Format(PyExc_TypeError, 
			"%s.%s is not a type object",
			module_name, class_name);
		goto bad;
	}
	if (((PyTypeObject *)result)->tp_basicsize != size) {
		PyErr_Format(PyExc_ValueError, 
			"%s.%s does not appear to be the correct type object",
			module_name, class_name);
		goto bad;
	}
	return (PyTypeObject *)result;
bad:
	Py_XDECREF(result);
	return 0;
}
#endif

#ifndef __PYX_HAVE_RT_ImportModule
#define __PYX_HAVE_RT_ImportModule
static PyObject *__Pyx_ImportModule(char *name) {
	PyObject *py_name = 0;
	
	py_name = PyString_FromString(name);
	if (!py_name)
		goto bad;
	return PyImport_Import(py_name);
bad:
	Py_XDECREF(py_name);
	return 0;
}
#endif

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
