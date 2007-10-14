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
static PyObject *__pyx_k1;
static PyObject *__pyx_k2;
static PyObject *__pyx_k3;

static char (__pyx_k4[]) = "This swallow is called";
static char (__pyx_k5[]) = "This swallow is flying at";
static char (__pyx_k6[]) = "furlongs per fortnight";
static char (__pyx_k7[]) = "This swallow is carrying";
static char (__pyx_k8[]) = "coconuts";

static PyObject *__pyx_f_swallow(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_swallow(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_name = 0;
  PyObject *__pyx_v_airspeed = 0;
  PyObject *__pyx_v_coconuts = 0;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  int __pyx_2;
  static char *__pyx_argnames[] = {"name","airspeed","coconuts",0};
  __pyx_v_name = __pyx_k1;
  __pyx_v_airspeed = __pyx_k2;
  __pyx_v_coconuts = __pyx_k3;
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "|OOO", __pyx_argnames, &__pyx_v_name, &__pyx_v_airspeed, &__pyx_v_coconuts)) return 0;
  Py_INCREF(__pyx_v_name);
  Py_INCREF(__pyx_v_airspeed);
  Py_INCREF(__pyx_v_coconuts);

  /* "ProjectsA:Python:Pyrex:Tests:Runnable:r_argdefault.pyx":2 */
  __pyx_1 = __Pyx_GetName(__pyx_b, "None"); if (!__pyx_1) goto __pyx_L1;
  __pyx_2 = __pyx_v_name != __pyx_1;
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  if (__pyx_2) {

    /* "ProjectsA:Python:Pyrex:Tests:Runnable:r_argdefault.pyx":3 */
    __pyx_1 = PyString_FromString(__pyx_k4); if (!__pyx_1) goto __pyx_L1;
    if (__Pyx_PrintItem(__pyx_1) < 0) goto __pyx_L1;
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    if (__Pyx_PrintItem(__pyx_v_name) < 0) goto __pyx_L1;
    if (__Pyx_PrintNewline() < 0) goto __pyx_L1;
    goto __pyx_L2;
  }
  __pyx_L2:;

  /* "ProjectsA:Python:Pyrex:Tests:Runnable:r_argdefault.pyx":4 */
  __pyx_1 = __Pyx_GetName(__pyx_b, "None"); if (!__pyx_1) goto __pyx_L1;
  __pyx_2 = __pyx_v_airspeed != __pyx_1;
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  if (__pyx_2) {

    /* "ProjectsA:Python:Pyrex:Tests:Runnable:r_argdefault.pyx":5 */
    __pyx_1 = PyString_FromString(__pyx_k5); if (!__pyx_1) goto __pyx_L1;
    if (__Pyx_PrintItem(__pyx_1) < 0) goto __pyx_L1;
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    if (__Pyx_PrintItem(__pyx_v_airspeed) < 0) goto __pyx_L1;
    __pyx_1 = PyString_FromString(__pyx_k6); if (!__pyx_1) goto __pyx_L1;
    if (__Pyx_PrintItem(__pyx_1) < 0) goto __pyx_L1;
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    if (__Pyx_PrintNewline() < 0) goto __pyx_L1;
    goto __pyx_L3;
  }
  __pyx_L3:;

  /* "ProjectsA:Python:Pyrex:Tests:Runnable:r_argdefault.pyx":6 */
  __pyx_1 = __Pyx_GetName(__pyx_b, "None"); if (!__pyx_1) goto __pyx_L1;
  __pyx_2 = __pyx_v_coconuts != __pyx_1;
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  if (__pyx_2) {

    /* "ProjectsA:Python:Pyrex:Tests:Runnable:r_argdefault.pyx":7 */
    __pyx_1 = PyString_FromString(__pyx_k7); if (!__pyx_1) goto __pyx_L1;
    if (__Pyx_PrintItem(__pyx_1) < 0) goto __pyx_L1;
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    if (__Pyx_PrintItem(__pyx_v_coconuts) < 0) goto __pyx_L1;
    __pyx_1 = PyString_FromString(__pyx_k8); if (!__pyx_1) goto __pyx_L1;
    if (__Pyx_PrintItem(__pyx_1) < 0) goto __pyx_L1;
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    if (__Pyx_PrintNewline() < 0) goto __pyx_L1;
    goto __pyx_L4;
  }
  __pyx_L4:;

  __pyx_r = Py_None; Py_INCREF(__pyx_r);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_name);
  Py_DECREF(__pyx_v_airspeed);
  Py_DECREF(__pyx_v_coconuts);
  return __pyx_r;
}

static struct PyMethodDef __pyx_methods[] = {
  {"swallow", (PyCFunction)__pyx_f_swallow, METH_VARARGS|METH_KEYWORDS, 0},
{0, 0, 0, 0}
};


void initr_argdefault(void); /*proto*/
void initr_argdefault(void) {
PyObject *__pyx_1 = 0;
PyObject *__pyx_2 = 0;
PyObject *__pyx_3 = 0;
__pyx_m = Py_InitModule4("r_argdefault", __pyx_methods, 0, 0, PYTHON_API_VERSION);
__pyx_b = PyImport_AddModule("__builtin__");
PyObject_SetAttrString(__pyx_m, "__builtins__", __pyx_b);

/* "ProjectsA:Python:Pyrex:Tests:Runnable:r_argdefault.pyx":1 */
__pyx_1 = __Pyx_GetName(__pyx_b, "None"); if (!__pyx_1) goto __pyx_L1;
__pyx_k1 = __pyx_1;
__pyx_1 = 0;
__pyx_2 = __Pyx_GetName(__pyx_b, "None"); if (!__pyx_2) goto __pyx_L1;
__pyx_k2 = __pyx_2;
__pyx_2 = 0;
__pyx_3 = __Pyx_GetName(__pyx_b, "None"); if (!__pyx_3) goto __pyx_L1;
__pyx_k3 = __pyx_3;
__pyx_3 = 0;
return;
__pyx_L1:;
Py_XDECREF(__pyx_1);
Py_XDECREF(__pyx_2);
Py_XDECREF(__pyx_3);
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
