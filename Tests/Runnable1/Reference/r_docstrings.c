#include "Python.h"

#define const


static PyObject *__Pyx_UnpackItem(PyObject *, int);
static int __Pyx_EndUnpack(PyObject *, int);
static int __Pyx_PrintItem(PyObject *);
static int __Pyx_PrintNewline(void);
static void __Pyx_Raise(PyObject *type, PyObject *value, PyObject *tb);
static void __Pyx_ReRaise(void);
static PyObject *__Pyx_Import(PyObject *name, PyObject *from_list);
static PyObject *__Pyx_GetExcValue(void);
static PyObject *__Pyx_GetName(PyObject *dict, char *name);
static int __Pyx_ArgTypeTest(PyObject *obj, PyTypeObject *type, char *name);
static int __Pyx_TypeTest(PyObject *obj, PyTypeObject *type);
static int __Pyx_GetStarArgs(PyObject **args, PyObject **kwds,	char *kwd_list[], int nargs, PyObject **args2, PyObject **kwds2);

static PyObject *__pyx_m;
static PyObject *__pyx_b;
static char __pyx_mdoc[] = "This is a module docstring.";

staticforward PyTypeObject __pyx_type_T;
struct __pyx_obj_T {
  PyObject_HEAD
};


static PyObject *__pyx_f_f(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static char __pyx_doc_f[] = "This is a function docstring.";
static PyObject *__pyx_f_f(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_r;
  static char *__pyx_argnames[] = {0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "", __pyx_argnames)) return 0;

  __pyx_r = Py_None; Py_INCREF(__pyx_r);
  goto __pyx_L0;
  __pyx_L1:;
  __pyx_r = 0;
  __pyx_L0:;
  return __pyx_r;
}

static PyObject *__pyx_tp_new_T(struct _typeobject *t, PyObject *a, PyObject *k) {
  PyObject *o = (*t->tp_alloc)(t, 0);
  struct __pyx_obj_T *p = (struct __pyx_obj_T *)o;
  return o;
}

static void __pyx_tp_dealloc_T(PyObject *o) {
  struct __pyx_obj_T *p = (struct __pyx_obj_T *)o;
  (*o->ob_type->tp_free)(o);
}

static int __pyx_tp_traverse_T(PyObject *o, visitproc v, void *a) {
  int e;
  struct __pyx_obj_T *p = (struct __pyx_obj_T *)o;
  return 0;
}

static int __pyx_tp_clear_T(PyObject *o) {
  struct __pyx_obj_T *p = (struct __pyx_obj_T *)o;
  return 0;
}

static struct PyMethodDef __pyx_methods_T[] = {
{0, 0, 0, 0}
};

static PyNumberMethods __pyx_tp_as_number_T = {
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

static PySequenceMethods __pyx_tp_as_sequence_T = {
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

static PyMappingMethods __pyx_tp_as_mapping_T = {
0, /*mp_length*/
0, /*mp_subscript*/
0, /*mp_ass_subscript*/
};

static PyBufferProcs __pyx_tp_as_buffer_T = {
0, /*bf_getreadbuffer*/
0, /*bf_getwritebuffer*/
0, /*bf_getsegcount*/
0, /*bf_getcharbuffer*/
};

statichere PyTypeObject __pyx_type_T = {
PyObject_HEAD_INIT(0)
0, /*ob_size*/
"r_docstrings.T", /*tp_name*/
sizeof(struct __pyx_obj_T), /*tp_basicsize*/
0, /*tp_itemsize*/
__pyx_tp_dealloc_T, /*tp_dealloc*/
0, /*tp_print*/
0, /*tp_getattr*/
0, /*tp_setattr*/
0, /*tp_compare*/
0, /*tp_repr*/
&__pyx_tp_as_number_T, /*tp_as_number*/
&__pyx_tp_as_sequence_T, /*tp_as_sequence*/
&__pyx_tp_as_mapping_T, /*tp_as_mapping*/
0, /*tp_hash*/
0, /*tp_call*/
0, /*tp_str*/
0, /*tp_getattro*/
0, /*tp_setattro*/
&__pyx_tp_as_buffer_T, /*tp_as_buffer*/
Py_TPFLAGS_DEFAULT|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_BASETYPE, /*tp_flags*/
"This is an extension type docstring.", /*tp_doc*/
__pyx_tp_traverse_T, /*tp_traverse*/
__pyx_tp_clear_T, /*tp_clear*/
0, /*tp_richcompare*/
0, /*tp_weaklistoffset*/
0, /*tp_iter*/
0, /*tp_iternext*/
__pyx_methods_T, /*tp_methods*/
0, /*tp_members*/
0, /*tp_getset*/
0, /*tp_base*/
0, /*tp_dict*/
0, /*tp_descr_get*/
0, /*tp_descr_set*/
0, /*tp_dictoffset*/
0, /*tp_init*/
0, /*tp_alloc*/
__pyx_tp_new_T, /*tp_new*/
_PyObject_Del, /*tp_free*/
0, /*tp_is_gc*/
0, /*tp_bases*/
0, /*tp_mro*/
0, /*tp_cache*/
0, /*tp_subclasses*/
0, /*tp_weaklist*/
};

static struct PyMethodDef __pyx_methods[] = {
{"f", (PyCFunction)__pyx_f_f, METH_VARARGS|METH_KEYWORDS, __pyx_doc_f},
{0, 0, 0, 0}
};

static char (__pyx_k1[]) = "C";
static char (__pyx_k2[]) = "This is a class docstring.";

void initr_docstrings(void); /*proto*/
void initr_docstrings(void) {
PyObject *__pyx_1 = 0;
PyObject *__pyx_2 = 0;
PyObject *__pyx_3 = 0;
PyObject *__pyx_4 = 0;
PyObject *__pyx_5 = 0;
__pyx_m = Py_InitModule4("r_docstrings", __pyx_methods, __pyx_mdoc, 0, PYTHON_API_VERSION);
__pyx_b = PyImport_AddModule("__builtin__");
PyObject_SetAttrString(__pyx_m, "__builtins__", __pyx_b);
if (PyType_Ready(&__pyx_type_T) < 0) goto __pyx_L1;
if (PyObject_SetAttrString(__pyx_m, "T", (PyObject *)&__pyx_type_T) < 0) goto __pyx_L1;

/* "ProjectsA:Python:Pyrex:Tests:Runnable:r_docstrings.pyx":3 */

/* "ProjectsA:Python:Pyrex:Tests:Runnable:r_docstrings.pyx":6 */
__pyx_1 = PyDict_New(); if (!__pyx_1) goto __pyx_L1;
__pyx_2 = PyString_FromString(__pyx_k1); if (!__pyx_2) goto __pyx_L1;
__pyx_3 = PyTuple_New(0); if (!__pyx_3) goto __pyx_L1;
__pyx_4 = PyString_FromString(__pyx_k2); if (!__pyx_4) goto __pyx_L1;
__pyx_5 = PyClass_New(__pyx_3, __pyx_1, __pyx_2); if (!__pyx_5) goto __pyx_L1;
if (PyObject_SetAttrString(__pyx_5, "__doc__", __pyx_4) < 0) goto __pyx_L1;
Py_DECREF(__pyx_2); __pyx_2 = 0;
Py_DECREF(__pyx_3); __pyx_3 = 0;
Py_DECREF(__pyx_4); __pyx_4 = 0;
if (PyObject_SetAttrString(__pyx_m, "C", __pyx_5) < 0) goto __pyx_L1;
Py_DECREF(__pyx_5); __pyx_5 = 0;
Py_DECREF(__pyx_1); __pyx_1 = 0;

/* "ProjectsA:Python:Pyrex:Tests:Runnable:r_docstrings.pyx":9 */
return;
__pyx_L1:;
Py_XDECREF(__pyx_1);
Py_XDECREF(__pyx_2);
Py_XDECREF(__pyx_3);
Py_XDECREF(__pyx_4);
Py_XDECREF(__pyx_5);
}

/* Runtime support code */
