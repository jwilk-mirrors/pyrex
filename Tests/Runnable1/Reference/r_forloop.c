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

static char (__pyx_k1[]) = "Spam!";

static PyObject *__pyx_f_go(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_go(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_i;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  PyObject *__pyx_4 = 0;
  PyObject *__pyx_5 = 0;
  PyObject *__pyx_6 = 0;
  static char *__pyx_argnames[] = {0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "", __pyx_argnames)) return 0;
  __pyx_v_i = Py_None; Py_INCREF(__pyx_v_i);

  /* "ProjectsA:Python:Pyrex:Tests:Runnable:r_forloop.pyx":2 */
  __pyx_1 = __Pyx_GetName(__pyx_b, "range"); if (!__pyx_1) goto __pyx_L1;
  __pyx_2 = PyInt_FromLong(5); if (!__pyx_2) goto __pyx_L1;
  __pyx_3 = PyTuple_New(1); if (!__pyx_3) goto __pyx_L1;
  PyTuple_SET_ITEM(__pyx_3, 0, __pyx_2);
  __pyx_2 = 0;
  __pyx_4 = PyObject_CallObject(__pyx_1, __pyx_3); if (!__pyx_4) goto __pyx_L1;
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_5 = PyObject_GetIter(__pyx_4); if (!__pyx_5) goto __pyx_L1;
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  for (;;) {
    __pyx_L2:;
    __pyx_6 = PyIter_Next(__pyx_5);
    if (!__pyx_6) {
      if (PyErr_Occurred()) goto __pyx_L1;
      break;
    }
    Py_DECREF(__pyx_v_i);
    __pyx_v_i = __pyx_6;
    __pyx_6 = 0;

    /* "ProjectsA:Python:Pyrex:Tests:Runnable:r_forloop.pyx":3 */
    __pyx_2 = PyString_FromString(__pyx_k1); if (!__pyx_2) goto __pyx_L1;
    if (__Pyx_PrintItem(__pyx_2) < 0) goto __pyx_L1;
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    if (__Pyx_PrintNewline() < 0) goto __pyx_L1;
  }
  __pyx_L3:;
  Py_DECREF(__pyx_5); __pyx_5 = 0;

  __pyx_r = Py_None; Py_INCREF(__pyx_r);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  Py_XDECREF(__pyx_4);
  Py_XDECREF(__pyx_5);
  Py_XDECREF(__pyx_6);
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_i);
  return __pyx_r;
}

static struct PyMethodDef __pyx_methods[] = {
  {"go", (PyCFunction)__pyx_f_go, METH_VARARGS|METH_KEYWORDS, 0},
{0, 0, 0, 0}
};


void initr_forloop(void); /*proto*/
void initr_forloop(void) {
__pyx_m = Py_InitModule4("r_forloop", __pyx_methods, 0, 0, PYTHON_API_VERSION);
__pyx_b = PyImport_AddModule("__builtin__");
PyObject_SetAttrString(__pyx_m, "__builtins__", __pyx_b);

/* "ProjectsA:Python:Pyrex:Tests:Runnable:r_forloop.pyx":1 */
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
