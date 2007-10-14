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

static char (__pyx_k1[]) = "Test-Exception";

static PyObject *__pyx_f_foo(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_foo(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  PyObject *__pyx_4 = 0;
  static char *__pyx_argnames[] = {0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "", __pyx_argnames)) return 0;

  /* "ProjectsA:Python:Pyrex:Tests:Bugs:baas:r_baas3.pyx":2 */
  __pyx_1 = __Pyx_GetName(__pyx_b, "TypeError"); if (!__pyx_1) goto __pyx_L1;
  __pyx_2 = PyString_FromString(__pyx_k1); if (!__pyx_2) goto __pyx_L1;
  __pyx_3 = PyTuple_New(1); if (!__pyx_3) goto __pyx_L1;
  PyTuple_SET_ITEM(__pyx_3, 0, __pyx_2);
  __pyx_2 = 0;
  __pyx_4 = PyObject_CallObject(__pyx_1, __pyx_3); if (!__pyx_4) goto __pyx_L1;
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __Pyx_Raise(__pyx_4, 0, 0);
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  goto __pyx_L1;

  __pyx_r = Py_None; Py_INCREF(__pyx_r);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  Py_XDECREF(__pyx_4);
  __pyx_r = 0;
  __pyx_L0:;
  return __pyx_r;
}

static struct PyMethodDef __pyx_methods[] = {
  {"foo", (PyCFunction)__pyx_f_foo, METH_VARARGS|METH_KEYWORDS, 0},
{0, 0, 0, 0}
};


void initr_baas3(void); /*proto*/
void initr_baas3(void) {
__pyx_m = Py_InitModule4("r_baas3", __pyx_methods, 0, 0, PYTHON_API_VERSION);
__pyx_b = PyImport_AddModule("__builtin__");
PyObject_SetAttrString(__pyx_m, "__builtins__", __pyx_b);

/* "ProjectsA:Python:Pyrex:Tests:Bugs:baas:r_baas3.pyx":1 */
return;
__pyx_L1:;
}

/* Runtime support code */

static PyObject *__Pyx_GetName(PyObject *dict, char *name) {
	PyObject *result;
	result = PyObject_GetAttrString(dict, name);
	if (!result)
		PyErr_SetString(PyExc_NameError, name);
	return result;
}

static void __Pyx_Raise(PyObject *type, PyObject *value, PyObject *tb) {
	Py_XINCREF(type);
	Py_XINCREF(value);
	Py_XINCREF(tb);
	/* First, check the traceback argument, replacing None with NULL. */
	if (tb == Py_None) {
		Py_DECREF(tb);
		tb = 0;
	}
	else if (tb != NULL && !PyTraceBack_Check(tb)) {
		PyErr_SetString(PyExc_TypeError,
			"raise: arg 3 must be a traceback or None");
		goto raise_error;
	}
	/* Next, replace a missing value with None */
	if (value == NULL) {
		value = Py_None;
		Py_INCREF(value);
	}
	/* Next, repeatedly, replace a tuple exception with its first item */
	while (PyTuple_Check(type) && PyTuple_Size(type) > 0) {
		PyObject *tmp = type;
		type = PyTuple_GET_ITEM(type, 0);
		Py_INCREF(type);
		Py_DECREF(tmp);
	}
	if (PyString_Check(type))
		;
	else if (PyClass_Check(type))
		; /*PyErr_NormalizeException(&type, &value, &tb);*/
	else if (PyInstance_Check(type)) {
		/* Raising an instance.  The value should be a dummy. */
		if (value != Py_None) {
			PyErr_SetString(PyExc_TypeError,
			  "instance exception may not have a separate value");
			goto raise_error;
		}
		else {
			/* Normalize to raise <class>, <instance> */
			Py_DECREF(value);
			value = type;
			type = (PyObject*) ((PyInstanceObject*)type)->in_class;
			Py_INCREF(type);
		}
	}
	else {
		/* Not something you can raise.  You get an exception
		   anyway, just not what you specified :-) */
		PyErr_Format(PyExc_TypeError,
			     "exceptions must be strings, classes, or "
			     "instances, not %s", type->ob_type->tp_name);
		goto raise_error;
	}
	PyErr_Restore(type, value, tb);
	return;
raise_error:
	Py_XDECREF(value);
	Py_XDECREF(type);
	Py_XDECREF(tb);
	return;
}
