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

staticforward PyTypeObject __pyx_type_Spam;
struct __pyx_obj_Spam {
  PyObject_HEAD
  int tons;
};


static int __pyx_f_4Spam___new__(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static int __pyx_f_4Spam___new__(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  int __pyx_r;
  static char *__pyx_argnames[] = {0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "", __pyx_argnames)) return 0;
  Py_INCREF(__pyx_v_self);

  /* "ProjectsA:Python:Pyrex:Tests:Runnable:r_spamtype.pyx":6 */
  ((struct __pyx_obj_Spam *)__pyx_v_self)->tons = 17;

  __pyx_r = 0;
  goto __pyx_L0;
  __pyx_L1:;
  __pyx_r = -1;
  __pyx_L0:;
  Py_DECREF(__pyx_v_self);
  return __pyx_r;
}

static char (__pyx_k1[]) = "tons of spam is history.";

static void __pyx_f_4Spam___dealloc__(PyObject *__pyx_v_self); /*proto*/
static void __pyx_f_4Spam___dealloc__(PyObject *__pyx_v_self) {
  PyObject *__pyx_1 = 0;
  Py_INCREF(__pyx_v_self);

  /* "ProjectsA:Python:Pyrex:Tests:Runnable:r_spamtype.pyx":9 */
  __pyx_1 = PyInt_FromLong(((struct __pyx_obj_Spam *)__pyx_v_self)->tons); if (!__pyx_1) goto __pyx_L1;
  if (__Pyx_PrintItem(__pyx_1) < 0) goto __pyx_L1;
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_1 = PyString_FromString(__pyx_k1); if (!__pyx_1) goto __pyx_L1;
  if (__Pyx_PrintItem(__pyx_1) < 0) goto __pyx_L1;
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  if (__Pyx_PrintNewline() < 0) goto __pyx_L1;

  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  __pyx_L0:;
  Py_DECREF(__pyx_v_self);
}


static PyObject *__pyx_f_4Spam_get_tons(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_4Spam_get_tons(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  static char *__pyx_argnames[] = {0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "", __pyx_argnames)) return 0;
  Py_INCREF(__pyx_v_self);

  /* "ProjectsA:Python:Pyrex:Tests:Runnable:r_spamtype.pyx":12 */
  __pyx_1 = PyInt_FromLong(((struct __pyx_obj_Spam *)__pyx_v_self)->tons); if (!__pyx_1) goto __pyx_L1;
  __pyx_r = __pyx_1;
  __pyx_1 = 0;
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(__pyx_r);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_self);
  return __pyx_r;
}


static PyObject *__pyx_f_4Spam_set_tons(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_4Spam_set_tons(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_x = 0;
  PyObject *__pyx_r;
  int __pyx_1;
  static char *__pyx_argnames[] = {"x",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "O", __pyx_argnames, &__pyx_v_x)) return 0;
  Py_INCREF(__pyx_v_self);
  Py_INCREF(__pyx_v_x);

  /* "ProjectsA:Python:Pyrex:Tests:Runnable:r_spamtype.pyx":15 */
  __pyx_1 = PyInt_AsLong(__pyx_v_x); if (PyErr_Occurred()) goto __pyx_L1;
  ((struct __pyx_obj_Spam *)__pyx_v_self)->tons = __pyx_1;

  __pyx_r = Py_None; Py_INCREF(__pyx_r);
  goto __pyx_L0;
  __pyx_L1:;
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_self);
  Py_DECREF(__pyx_v_x);
  return __pyx_r;
}

static PyObject *__pyx_tp_new_Spam(struct _typeobject *t, PyObject *a, PyObject *k) {
  PyObject *o = (*t->tp_alloc)(t, 0);
  struct __pyx_obj_Spam *p = (struct __pyx_obj_Spam *)o;
  if (__pyx_f_4Spam___new__(o, a, k) < 0) {
    Py_DECREF(o); o = 0;
  }
  return o;
}

static void __pyx_tp_dealloc_Spam(PyObject *o) {
  struct __pyx_obj_Spam *p = (struct __pyx_obj_Spam *)o;
  ++o->ob_refcnt;
  __pyx_f_4Spam___dealloc__(o);
  if (PyErr_Occurred()) PyErr_WriteUnraisable(o);
  --o->ob_refcnt;
  (*o->ob_type->tp_free)(o);
}

static int __pyx_tp_traverse_Spam(PyObject *o, visitproc v, void *a) {
  int e;
  struct __pyx_obj_Spam *p = (struct __pyx_obj_Spam *)o;
  return 0;
}

static int __pyx_tp_clear_Spam(PyObject *o) {
  struct __pyx_obj_Spam *p = (struct __pyx_obj_Spam *)o;
  return 0;
}

static struct PyMethodDef __pyx_methods_Spam[] = {
  {"get_tons", (PyCFunction)__pyx_f_4Spam_get_tons, METH_VARARGS|METH_KEYWORDS, 0},
  {"set_tons", (PyCFunction)__pyx_f_4Spam_set_tons, METH_VARARGS|METH_KEYWORDS, 0},
{0, 0, 0, 0}
};

static PyNumberMethods __pyx_tp_as_number_Spam = {
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
};

static PySequenceMethods __pyx_tp_as_sequence_Spam = {
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

static PyMappingMethods __pyx_tp_as_mapping_Spam = {
0, /*mp_length*/
0, /*mp_subscript*/
0, /*mp_ass_subscript*/
};

static PyBufferProcs __pyx_tp_as_buffer_Spam = {
0, /*bf_getreadbuffer*/
0, /*bf_getwritebuffer*/
0, /*bf_getsegcount*/
0, /*bf_getcharbuffer*/
};

statichere PyTypeObject __pyx_type_Spam = {
PyObject_HEAD_INIT(0)
0, /*ob_size*/
"r_spamtype.Spam", /*tp_name*/
sizeof(struct __pyx_obj_Spam), /*tp_basicsize*/
0, /*tp_itemsize*/
__pyx_tp_dealloc_Spam, /*tp_dealloc*/
0, /*tp_print*/
0, /*tp_getattr*/
0, /*tp_setattr*/
0, /*tp_compare*/
0, /*tp_repr*/
&__pyx_tp_as_number_Spam, /*tp_as_number*/
&__pyx_tp_as_sequence_Spam, /*tp_as_sequence*/
&__pyx_tp_as_mapping_Spam, /*tp_as_mapping*/
0, /*tp_hash*/
0, /*tp_call*/
0, /*tp_str*/
0, /*tp_getattro*/
0, /*tp_setattro*/
&__pyx_tp_as_buffer_Spam, /*tp_as_buffer*/
Py_TPFLAGS_DEFAULT|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_BASETYPE, /*tp_flags*/
0, /*tp_doc*/
__pyx_tp_traverse_Spam, /*tp_traverse*/
__pyx_tp_clear_Spam, /*tp_clear*/
0, /*tp_richcompare*/
0, /*tp_weaklistoffset*/
0, /*tp_iter*/
0, /*tp_iternext*/
__pyx_methods_Spam, /*tp_methods*/
0, /*tp_members*/
0, /*tp_getset*/
0, /*tp_base*/
0, /*tp_dict*/
0, /*tp_descr_get*/
0, /*tp_descr_set*/
0, /*tp_dictoffset*/
0, /*tp_init*/
0, /*tp_alloc*/
__pyx_tp_new_Spam, /*tp_new*/
_PyObject_Del, /*tp_free*/
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


void initr_spamtype(void); /*proto*/
void initr_spamtype(void) {
__pyx_m = Py_InitModule4("r_spamtype", __pyx_methods, 0, 0, PYTHON_API_VERSION);
__pyx_b = PyImport_AddModule("__builtin__");
PyObject_SetAttrString(__pyx_m, "__builtins__", __pyx_b);
if (PyType_Ready(&__pyx_type_Spam) < 0) goto __pyx_L1;
if (PyObject_SetAttrString(__pyx_m, "Spam", (PyObject *)&__pyx_type_Spam) < 0) goto __pyx_L1;

/* "ProjectsA:Python:Pyrex:Tests:Runnable:r_spamtype.pyx":1 */
return;
__pyx_L1:;
}

/* Runtime support code */

static PyObject *__Pyx_GetStdout(void) {
	PyObject *f = PySys_GetObject("stdout");
	if (!f) {
		PyErr_SetString(PyExc_RuntimeError, "lost sys.stdout");
	}
	return f;
}

static int __Pyx_PrintItem(PyObject *v) {
	PyObject *f;
	
	if (!(f = __Pyx_GetStdout()))
		return -1;
	if (PyFile_SoftSpace(f, 1)) {
		if (PyFile_WriteString(" ", f) < 0)
			return -1;
	}
	if (PyFile_WriteObject(v, f, Py_PRINT_RAW) < 0)
		return -1;
	if (PyString_Check(v)) {
		char *s = PyString_AsString(v);
		int len = PyString_Size(v);
		if (len > 0 &&
			isspace(Py_CHARMASK(s[len-1])) &&
			s[len-1] != ' ')
				PyFile_SoftSpace(f, 0);
	}
	return 0;
}

static int __Pyx_PrintNewline(void) {
	PyObject *f;
	
	if (!(f = __Pyx_GetStdout()))
		return -1;
	if (PyFile_WriteString("\n", f) < 0)
		return -1;
	PyFile_SoftSpace(f, 0);
	return 0;
}
