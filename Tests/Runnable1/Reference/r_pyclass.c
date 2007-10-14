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


static PyObject *__pyx_f_4Spam___init__(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_4Spam___init__ = {"__init__", (PyCFunction)__pyx_f_4Spam___init__, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_f_4Spam___init__(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
PyObject *__pyx_v_self = 0;
PyObject *__pyx_v_w = 0;
PyObject *__pyx_r;
static char *__pyx_argnames[] = {"self","w",0};
if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "OO", __pyx_argnames, &__pyx_v_self, &__pyx_v_w)) return 0;
Py_INCREF(__pyx_v_self);
Py_INCREF(__pyx_v_w);

/* "ProjectsA:Python:Pyrex:Tests:Runnable:r_pyclass.pyx":4 */
if (PyObject_SetAttrString(__pyx_v_self, "weight", __pyx_v_w) < 0) goto __pyx_L1;

__pyx_r = Py_None; Py_INCREF(__pyx_r);
goto __pyx_L0;
__pyx_L1:;
__pyx_r = 0;
__pyx_L0:;
Py_DECREF(__pyx_v_self);
Py_DECREF(__pyx_v_w);
return __pyx_r;
}

static char (__pyx_k2[]) = "tons of spam!";

static PyObject *__pyx_f_4Spam_serve(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_4Spam_serve = {"serve", (PyCFunction)__pyx_f_4Spam_serve, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_f_4Spam_serve(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
PyObject *__pyx_v_self = 0;
PyObject *__pyx_r;
PyObject *__pyx_1 = 0;
static char *__pyx_argnames[] = {"self",0};
if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "O", __pyx_argnames, &__pyx_v_self)) return 0;
Py_INCREF(__pyx_v_self);

/* "ProjectsA:Python:Pyrex:Tests:Runnable:r_pyclass.pyx":7 */
__pyx_1 = PyObject_GetAttrString(__pyx_v_self, "weight"); if (!__pyx_1) goto __pyx_L1;
if (__Pyx_PrintItem(__pyx_1) < 0) goto __pyx_L1;
Py_DECREF(__pyx_1); __pyx_1 = 0;
__pyx_1 = PyString_FromString(__pyx_k2); if (!__pyx_1) goto __pyx_L1;
if (__Pyx_PrintItem(__pyx_1) < 0) goto __pyx_L1;
Py_DECREF(__pyx_1); __pyx_1 = 0;
if (__Pyx_PrintNewline() < 0) goto __pyx_L1;

__pyx_r = Py_None; Py_INCREF(__pyx_r);
goto __pyx_L0;
__pyx_L1:;
Py_XDECREF(__pyx_1);
__pyx_r = 0;
__pyx_L0:;
Py_DECREF(__pyx_v_self);
return __pyx_r;
}


static PyObject *__pyx_f_order(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_order(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
PyObject *__pyx_v_s;
PyObject *__pyx_r;
PyObject *__pyx_1 = 0;
PyObject *__pyx_2 = 0;
PyObject *__pyx_3 = 0;
PyObject *__pyx_4 = 0;
static char *__pyx_argnames[] = {0};
if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "", __pyx_argnames)) return 0;
__pyx_v_s = Py_None; Py_INCREF(__pyx_v_s);

/* "ProjectsA:Python:Pyrex:Tests:Runnable:r_pyclass.pyx":10 */
__pyx_1 = __Pyx_GetName(__pyx_m, "Spam"); if (!__pyx_1) goto __pyx_L1;
__pyx_2 = PyInt_FromLong(42); if (!__pyx_2) goto __pyx_L1;
__pyx_3 = PyTuple_New(1); if (!__pyx_3) goto __pyx_L1;
PyTuple_SET_ITEM(__pyx_3, 0, __pyx_2);
__pyx_2 = 0;
__pyx_4 = PyObject_CallObject(__pyx_1, __pyx_3); if (!__pyx_4) goto __pyx_L1;
Py_DECREF(__pyx_3); __pyx_3 = 0;
Py_DECREF(__pyx_v_s);
__pyx_v_s = __pyx_4;
__pyx_4 = 0;

/* "ProjectsA:Python:Pyrex:Tests:Runnable:r_pyclass.pyx":11 */
__pyx_2 = PyObject_GetAttrString(__pyx_v_s, "serve"); if (!__pyx_2) goto __pyx_L1;
__pyx_3 = PyTuple_New(0); if (!__pyx_3) goto __pyx_L1;
__pyx_1 = PyObject_CallObject(__pyx_2, __pyx_3); if (!__pyx_1) goto __pyx_L1;
Py_DECREF(__pyx_3); __pyx_3 = 0;
Py_DECREF(__pyx_1); __pyx_1 = 0;

__pyx_r = Py_None; Py_INCREF(__pyx_r);
goto __pyx_L0;
__pyx_L1:;
Py_XDECREF(__pyx_1);
Py_XDECREF(__pyx_2);
Py_XDECREF(__pyx_3);
Py_XDECREF(__pyx_4);
__pyx_r = 0;
__pyx_L0:;
Py_DECREF(__pyx_v_s);
return __pyx_r;
}

static struct PyMethodDef __pyx_methods[] = {
{"order", (PyCFunction)__pyx_f_order, METH_VARARGS|METH_KEYWORDS, 0},
{0, 0, 0, 0}
};

static char (__pyx_k1[]) = "Spam";

void initr_pyclass(void); /*proto*/
void initr_pyclass(void) {
PyObject *__pyx_1 = 0;
PyObject *__pyx_2 = 0;
PyObject *__pyx_3 = 0;
PyObject *__pyx_4 = 0;
PyObject *__pyx_5 = 0;
PyObject *__pyx_6 = 0;
__pyx_m = Py_InitModule4("r_pyclass", __pyx_methods, 0, 0, PYTHON_API_VERSION);
__pyx_b = PyImport_AddModule("__builtin__");
PyObject_SetAttrString(__pyx_m, "__builtins__", __pyx_b);

/* "ProjectsA:Python:Pyrex:Tests:Runnable:r_pyclass.pyx":1 */
__pyx_1 = PyDict_New(); if (!__pyx_1) goto __pyx_L1;
__pyx_2 = PyString_FromString(__pyx_k1); if (!__pyx_2) goto __pyx_L1;
__pyx_3 = PyTuple_New(0); if (!__pyx_3) goto __pyx_L1;
__pyx_4 = PyClass_New(__pyx_3, __pyx_1, __pyx_2); if (!__pyx_4) goto __pyx_L1;
Py_DECREF(__pyx_2); __pyx_2 = 0;
Py_DECREF(__pyx_3); __pyx_3 = 0;

/* "ProjectsA:Python:Pyrex:Tests:Runnable:r_pyclass.pyx":3 */
__pyx_5 = PyCFunction_New(&__pyx_mdef_4Spam___init__, 0); if (!__pyx_5) goto __pyx_L1;
__pyx_6 = PyMethod_New(__pyx_5, 0, __pyx_4); if (!__pyx_6) goto __pyx_L1;
Py_DECREF(__pyx_5); __pyx_5 = 0;
if (PyObject_SetAttrString(__pyx_4, "__init__", __pyx_6) < 0) goto __pyx_L1;
Py_DECREF(__pyx_6); __pyx_6 = 0;

/* "ProjectsA:Python:Pyrex:Tests:Runnable:r_pyclass.pyx":6 */
__pyx_2 = PyCFunction_New(&__pyx_mdef_4Spam_serve, 0); if (!__pyx_2) goto __pyx_L1;
__pyx_3 = PyMethod_New(__pyx_2, 0, __pyx_4); if (!__pyx_3) goto __pyx_L1;
Py_DECREF(__pyx_2); __pyx_2 = 0;
if (PyObject_SetAttrString(__pyx_4, "serve", __pyx_3) < 0) goto __pyx_L1;
Py_DECREF(__pyx_3); __pyx_3 = 0;
if (PyObject_SetAttrString(__pyx_m, "Spam", __pyx_4) < 0) goto __pyx_L1;
Py_DECREF(__pyx_4); __pyx_4 = 0;
Py_DECREF(__pyx_1); __pyx_1 = 0;

/* "ProjectsA:Python:Pyrex:Tests:Runnable:r_pyclass.pyx":9 */
return;
__pyx_L1:;
Py_XDECREF(__pyx_1);
Py_XDECREF(__pyx_2);
Py_XDECREF(__pyx_3);
Py_XDECREF(__pyx_4);
Py_XDECREF(__pyx_5);
Py_XDECREF(__pyx_6);
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

static PyObject *__Pyx_GetName(PyObject *dict, char *name) {
	PyObject *result;
	result = PyObject_GetAttrString(dict, name);
	if (!result)
		PyErr_SetString(PyExc_NameError, name);
	return result;
}
