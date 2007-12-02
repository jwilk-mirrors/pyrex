/* Generated by Pyrex 0.9.6.3 on Sun Dec  2 15:07:15 2007 */

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

static int __Pyx_GetStarArgs(PyObject **args, PyObject **kwds, char *kwd_list[], 	Py_ssize_t nargs, PyObject **args2, PyObject **kwds2, char rqd_kwds[]); /*proto*/

static void __Pyx_AddTraceback(char *funcname); /*proto*/

/* Declarations from extstarargs */

struct __pyx_obj_11extstarargs_Silly {
  PyObject_HEAD
};


static PyTypeObject *__pyx_ptype_11extstarargs_Silly = 0;


/* Implementation of extstarargs */

static int __pyx_f_11extstarargs_5Silly___init__(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static int __pyx_f_11extstarargs_5Silly___init__(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_a = 0;
  int __pyx_r;
  static char *__pyx_argnames[] = {0};
  if (__Pyx_GetStarArgs(&__pyx_args, &__pyx_kwds, __pyx_argnames, 0, &__pyx_v_a, 0, 0) < 0) return -1;
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "", __pyx_argnames)) {
    Py_XDECREF(__pyx_args);
    Py_XDECREF(__pyx_kwds);
    Py_XDECREF(__pyx_v_a);
    return -1;
  }
  Py_INCREF(__pyx_v_self);

  __pyx_r = 0;
  Py_XDECREF(__pyx_v_a);
  Py_DECREF(__pyx_v_self);
  Py_XDECREF(__pyx_args);
  Py_XDECREF(__pyx_kwds);
  return __pyx_r;
}

static PyObject *__pyx_f_11extstarargs_5Silly_spam(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_11extstarargs_5Silly_spam(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_x = 0;
  PyObject *__pyx_v_y = 0;
  PyObject *__pyx_v_z = 0;
  PyObject *__pyx_r;
  static char *__pyx_argnames[] = {"x","y","z",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "OOO", __pyx_argnames, &__pyx_v_x, &__pyx_v_y, &__pyx_v_z)) return 0;
  Py_INCREF(__pyx_v_self);
  Py_INCREF(__pyx_v_x);
  Py_INCREF(__pyx_v_y);
  Py_INCREF(__pyx_v_z);

  __pyx_r = Py_None; Py_INCREF(Py_None);
  Py_DECREF(__pyx_v_self);
  Py_DECREF(__pyx_v_x);
  Py_DECREF(__pyx_v_y);
  Py_DECREF(__pyx_v_z);
  return __pyx_r;
}

static PyObject *__pyx_f_11extstarargs_5Silly_grail(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_11extstarargs_5Silly_grail(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_x = 0;
  PyObject *__pyx_v_y = 0;
  PyObject *__pyx_v_z = 0;
  PyObject *__pyx_v_a = 0;
  PyObject *__pyx_r;
  static char *__pyx_argnames[] = {"x","y","z",0};
  if (__Pyx_GetStarArgs(&__pyx_args, &__pyx_kwds, __pyx_argnames, 3, &__pyx_v_a, 0, 0) < 0) return 0;
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "OOO", __pyx_argnames, &__pyx_v_x, &__pyx_v_y, &__pyx_v_z)) {
    Py_XDECREF(__pyx_args);
    Py_XDECREF(__pyx_kwds);
    Py_XDECREF(__pyx_v_a);
    return 0;
  }
  Py_INCREF(__pyx_v_self);
  Py_INCREF(__pyx_v_x);
  Py_INCREF(__pyx_v_y);
  Py_INCREF(__pyx_v_z);

  __pyx_r = Py_None; Py_INCREF(Py_None);
  Py_XDECREF(__pyx_v_a);
  Py_DECREF(__pyx_v_self);
  Py_DECREF(__pyx_v_x);
  Py_DECREF(__pyx_v_y);
  Py_DECREF(__pyx_v_z);
  Py_XDECREF(__pyx_args);
  Py_XDECREF(__pyx_kwds);
  return __pyx_r;
}

static PyObject *__pyx_f_11extstarargs_5Silly_swallow(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_11extstarargs_5Silly_swallow(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_x = 0;
  PyObject *__pyx_v_y = 0;
  PyObject *__pyx_v_z = 0;
  PyObject *__pyx_v_k = 0;
  PyObject *__pyx_r;
  static char *__pyx_argnames[] = {"x","y","z",0};
  if (__Pyx_GetStarArgs(&__pyx_args, &__pyx_kwds, __pyx_argnames, 3, 0, &__pyx_v_k, 0) < 0) return 0;
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "OOO", __pyx_argnames, &__pyx_v_x, &__pyx_v_y, &__pyx_v_z)) {
    Py_XDECREF(__pyx_args);
    Py_XDECREF(__pyx_kwds);
    Py_XDECREF(__pyx_v_k);
    return 0;
  }
  Py_INCREF(__pyx_v_self);
  Py_INCREF(__pyx_v_x);
  Py_INCREF(__pyx_v_y);
  Py_INCREF(__pyx_v_z);

  __pyx_r = Py_None; Py_INCREF(Py_None);
  Py_XDECREF(__pyx_v_k);
  Py_DECREF(__pyx_v_self);
  Py_DECREF(__pyx_v_x);
  Py_DECREF(__pyx_v_y);
  Py_DECREF(__pyx_v_z);
  Py_XDECREF(__pyx_args);
  Py_XDECREF(__pyx_kwds);
  return __pyx_r;
}

static PyObject *__pyx_f_11extstarargs_5Silly_creosote(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_11extstarargs_5Silly_creosote(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_x = 0;
  PyObject *__pyx_v_y = 0;
  PyObject *__pyx_v_z = 0;
  PyObject *__pyx_v_a = 0;
  PyObject *__pyx_v_k = 0;
  PyObject *__pyx_r;
  static char *__pyx_argnames[] = {"x","y","z",0};
  if (__Pyx_GetStarArgs(&__pyx_args, &__pyx_kwds, __pyx_argnames, 3, &__pyx_v_a, &__pyx_v_k, 0) < 0) return 0;
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "OOO", __pyx_argnames, &__pyx_v_x, &__pyx_v_y, &__pyx_v_z)) {
    Py_XDECREF(__pyx_args);
    Py_XDECREF(__pyx_kwds);
    Py_XDECREF(__pyx_v_a);
    Py_XDECREF(__pyx_v_k);
    return 0;
  }
  Py_INCREF(__pyx_v_self);
  Py_INCREF(__pyx_v_x);
  Py_INCREF(__pyx_v_y);
  Py_INCREF(__pyx_v_z);

  __pyx_r = Py_None; Py_INCREF(Py_None);
  Py_XDECREF(__pyx_v_a);
  Py_XDECREF(__pyx_v_k);
  Py_DECREF(__pyx_v_self);
  Py_DECREF(__pyx_v_x);
  Py_DECREF(__pyx_v_y);
  Py_DECREF(__pyx_v_z);
  Py_XDECREF(__pyx_args);
  Py_XDECREF(__pyx_kwds);
  return __pyx_r;
}

static PyObject *__pyx_tp_new_11extstarargs_Silly(PyTypeObject *t, PyObject *a, PyObject *k) {
  PyObject *o = (*t->tp_alloc)(t, 0);
  if (!o) return 0;
  return o;
}

static void __pyx_tp_dealloc_11extstarargs_Silly(PyObject *o) {
  (*o->ob_type->tp_free)(o);
}

static int __pyx_tp_traverse_11extstarargs_Silly(PyObject *o, visitproc v, void *a) {
  return 0;
}

static int __pyx_tp_clear_11extstarargs_Silly(PyObject *o) {
  return 0;
}

static struct PyMethodDef __pyx_methods_11extstarargs_Silly[] = {
  {"spam", (PyCFunction)__pyx_f_11extstarargs_5Silly_spam, METH_VARARGS|METH_KEYWORDS, 0},
  {"grail", (PyCFunction)__pyx_f_11extstarargs_5Silly_grail, METH_VARARGS|METH_KEYWORDS, 0},
  {"swallow", (PyCFunction)__pyx_f_11extstarargs_5Silly_swallow, METH_VARARGS|METH_KEYWORDS, 0},
  {"creosote", (PyCFunction)__pyx_f_11extstarargs_5Silly_creosote, METH_VARARGS|METH_KEYWORDS, 0},
  {0, 0, 0, 0}
};

static PyNumberMethods __pyx_tp_as_number_Silly = {
  0, /*nb_add*/
  0, /*nb_subtract*/
  0, /*nb_multiply*/
  0, /*nb_divide*/
  0, /*nb_remainder*/
  0, /*nb_divmod*/
  0, /*nb_power*/
  0, /*nb_negative*/
  0, /*nb_positive*/
  0, /*nb_absolute*/
  0, /*nb_nonzero*/
  0, /*nb_invert*/
  0, /*nb_lshift*/
  0, /*nb_rshift*/
  0, /*nb_and*/
  0, /*nb_xor*/
  0, /*nb_or*/
  0, /*nb_coerce*/
  0, /*nb_int*/
  0, /*nb_long*/
  0, /*nb_float*/
  0, /*nb_oct*/
  0, /*nb_hex*/
  0, /*nb_inplace_add*/
  0, /*nb_inplace_subtract*/
  0, /*nb_inplace_multiply*/
  0, /*nb_inplace_divide*/
  0, /*nb_inplace_remainder*/
  0, /*nb_inplace_power*/
  0, /*nb_inplace_lshift*/
  0, /*nb_inplace_rshift*/
  0, /*nb_inplace_and*/
  0, /*nb_inplace_xor*/
  0, /*nb_inplace_or*/
  0, /*nb_floor_divide*/
  0, /*nb_true_divide*/
  0, /*nb_inplace_floor_divide*/
  0, /*nb_inplace_true_divide*/
  #if Py_TPFLAGS_DEFAULT & Py_TPFLAGS_HAVE_INDEX
  0, /*nb_index*/
  #endif
};

static PySequenceMethods __pyx_tp_as_sequence_Silly = {
  0, /*sq_length*/
  0, /*sq_concat*/
  0, /*sq_repeat*/
  0, /*sq_item*/
  0, /*sq_slice*/
  0, /*sq_ass_item*/
  0, /*sq_ass_slice*/
  0, /*sq_contains*/
  0, /*sq_inplace_concat*/
  0, /*sq_inplace_repeat*/
};

static PyMappingMethods __pyx_tp_as_mapping_Silly = {
  0, /*mp_length*/
  0, /*mp_subscript*/
  0, /*mp_ass_subscript*/
};

static PyBufferProcs __pyx_tp_as_buffer_Silly = {
  0, /*bf_getreadbuffer*/
  0, /*bf_getwritebuffer*/
  0, /*bf_getsegcount*/
  0, /*bf_getcharbuffer*/
};

PyTypeObject __pyx_type_11extstarargs_Silly = {
  PyObject_HEAD_INIT(0)
  0, /*ob_size*/
  "extstarargs.Silly", /*tp_name*/
  sizeof(struct __pyx_obj_11extstarargs_Silly), /*tp_basicsize*/
  0, /*tp_itemsize*/
  __pyx_tp_dealloc_11extstarargs_Silly, /*tp_dealloc*/
  0, /*tp_print*/
  0, /*tp_getattr*/
  0, /*tp_setattr*/
  0, /*tp_compare*/
  0, /*tp_repr*/
  &__pyx_tp_as_number_Silly, /*tp_as_number*/
  &__pyx_tp_as_sequence_Silly, /*tp_as_sequence*/
  &__pyx_tp_as_mapping_Silly, /*tp_as_mapping*/
  0, /*tp_hash*/
  0, /*tp_call*/
  0, /*tp_str*/
  0, /*tp_getattro*/
  0, /*tp_setattro*/
  &__pyx_tp_as_buffer_Silly, /*tp_as_buffer*/
  Py_TPFLAGS_DEFAULT|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_HAVE_GC, /*tp_flags*/
  0, /*tp_doc*/
  __pyx_tp_traverse_11extstarargs_Silly, /*tp_traverse*/
  __pyx_tp_clear_11extstarargs_Silly, /*tp_clear*/
  0, /*tp_richcompare*/
  0, /*tp_weaklistoffset*/
  0, /*tp_iter*/
  0, /*tp_iternext*/
  __pyx_methods_11extstarargs_Silly, /*tp_methods*/
  0, /*tp_members*/
  0, /*tp_getset*/
  0, /*tp_base*/
  0, /*tp_dict*/
  0, /*tp_descr_get*/
  0, /*tp_descr_set*/
  0, /*tp_dictoffset*/
  __pyx_f_11extstarargs_5Silly___init__, /*tp_init*/
  0, /*tp_alloc*/
  __pyx_tp_new_11extstarargs_Silly, /*tp_new*/
  0, /*tp_free*/
  0, /*tp_is_gc*/
  0, /*tp_bases*/
  0, /*tp_mro*/
  0, /*tp_cache*/
  0, /*tp_subclasses*/
  0, /*tp_weaklist*/
};

static struct PyMethodDef __pyx_methods[] = {
  {0, 0, 0, 0}
};

static void __pyx_init_filenames(void); /*proto*/

PyMODINIT_FUNC initextstarargs(void); /*proto*/
PyMODINIT_FUNC initextstarargs(void) {
  __pyx_init_filenames();
  __pyx_m = Py_InitModule4("extstarargs", __pyx_methods, 0, 0, PYTHON_API_VERSION);
  if (!__pyx_m) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; goto __pyx_L1;};
  Py_INCREF(__pyx_m);
  __pyx_b = PyImport_AddModule("__builtin__");
  if (!__pyx_b) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; goto __pyx_L1;};
  if (PyObject_SetAttrString(__pyx_m, "__builtins__", __pyx_b) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; goto __pyx_L1;};
  if (PyType_Ready(&__pyx_type_11extstarargs_Silly) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; goto __pyx_L1;}
  if (PyObject_SetAttrString(__pyx_m, "Silly", (PyObject *)&__pyx_type_11extstarargs_Silly) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; goto __pyx_L1;}
  __pyx_ptype_11extstarargs_Silly = &__pyx_type_11extstarargs_Silly;

  /* "/Local/Projects/D/Pyrex/Source/Tests/5/extstarargs.pyx":15 */
  return;
  __pyx_L1:;
  __Pyx_AddTraceback("extstarargs");
}

static char *__pyx_filenames[] = {
  "extstarargs.pyx",
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
