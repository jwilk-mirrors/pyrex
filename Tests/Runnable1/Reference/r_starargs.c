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
static int __Pyx_GetStarArgs(PyObject **args, PyObject **kwds, 
	char *kwd_list[], int nargs, PyObject **args2, PyObject **kwds2);

static PyObject *__pyx_m;
static PyObject *__pyx_b;

static char (__pyx_k1[]) = "Name:";
static char (__pyx_k2[]) = "Airspeed:";
static char (__pyx_k3[]) = "Extra args:";
static char (__pyx_k4[]) = "Extra keywords:";

static PyObject *__pyx_f_swallow(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_swallow(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_name = 0;
  PyObject *__pyx_v_airspeed = 0;
  PyObject *__pyx_v_args = 0;
  PyObject *__pyx_v_kwds = 0;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  static char *__pyx_argnames[] = {"name","airspeed",0};
  if (__Pyx_GetStarArgs(&__pyx_args, &__pyx_kwds, __pyx_argnames, 2, &__pyx_v_args, &__pyx_v_kwds) < 0) return 0;
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "OO", __pyx_argnames, &__pyx_v_name, &__pyx_v_airspeed)) {
    Py_XDECREF(__pyx_args);
    Py_XDECREF(__pyx_kwds);
    Py_XDECREF(__pyx_v_args);
    Py_XDECREF(__pyx_v_kwds);
    return 0;
  }
  Py_INCREF(__pyx_v_name);
  Py_INCREF(__pyx_v_airspeed);

  /* "ProjectsA:Python:Pyrex:Tests:Runnable:r_starargs.pyx":2 */
  __pyx_1 = PyString_FromString(__pyx_k1); if (!__pyx_1) goto __pyx_L1;
  if (__Pyx_PrintItem(__pyx_1) < 0) goto __pyx_L1;
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  if (__Pyx_PrintItem(__pyx_v_name) < 0) goto __pyx_L1;
  if (__Pyx_PrintNewline() < 0) goto __pyx_L1;

  /* "ProjectsA:Python:Pyrex:Tests:Runnable:r_starargs.pyx":3 */
  __pyx_1 = PyString_FromString(__pyx_k2); if (!__pyx_1) goto __pyx_L1;
  if (__Pyx_PrintItem(__pyx_1) < 0) goto __pyx_L1;
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  if (__Pyx_PrintItem(__pyx_v_airspeed) < 0) goto __pyx_L1;
  if (__Pyx_PrintNewline() < 0) goto __pyx_L1;

  /* "ProjectsA:Python:Pyrex:Tests:Runnable:r_starargs.pyx":4 */
  __pyx_1 = PyString_FromString(__pyx_k3); if (!__pyx_1) goto __pyx_L1;
  if (__Pyx_PrintItem(__pyx_1) < 0) goto __pyx_L1;
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  if (__Pyx_PrintItem(__pyx_v_args) < 0) goto __pyx_L1;
  if (__Pyx_PrintNewline() < 0) goto __pyx_L1;

  /* "ProjectsA:Python:Pyrex:Tests:Runnable:r_starargs.pyx":5 */
  __pyx_1 = PyString_FromString(__pyx_k4); if (!__pyx_1) goto __pyx_L1;
  if (__Pyx_PrintItem(__pyx_1) < 0) goto __pyx_L1;
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  if (__Pyx_PrintItem(__pyx_v_kwds) < 0) goto __pyx_L1;
  if (__Pyx_PrintNewline() < 0) goto __pyx_L1;

  __pyx_r = Py_None; Py_INCREF(__pyx_r);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  __pyx_r = 0;
  __pyx_L0:;
  Py_XDECREF(__pyx_v_args);
  Py_XDECREF(__pyx_v_kwds);
  Py_DECREF(__pyx_v_name);
  Py_DECREF(__pyx_v_airspeed);
  return __pyx_r;
}

static struct PyMethodDef __pyx_methods[] = {
  {"swallow", (PyCFunction)__pyx_f_swallow, METH_VARARGS|METH_KEYWORDS, 0},
{0, 0, 0, 0}
};


void initr_starargs(void); /*proto*/
void initr_starargs(void) {
__pyx_m = Py_InitModule4("r_starargs", __pyx_methods, 0, 0, PYTHON_API_VERSION);
__pyx_b = PyImport_AddModule("__builtin__");
PyObject_SetAttrString(__pyx_m, "__builtins__", __pyx_b);

/* "ProjectsA:Python:Pyrex:Tests:Runnable:r_starargs.pyx":1 */
return;
__pyx_L1:;
}

/* Runtime support code */

static int __Pyx_GetStarArgs(
	PyObject **args, 
	PyObject **kwds,
	char *kwd_list[], 
	int nargs,
	PyObject **args2, 
	PyObject **kwds2)
{
	PyObject *x = 0, *args1 = 0, *kwds1 = 0;
	
	if (args2)
		*args2 = 0;
	if (kwds2)
		*kwds2 = 0;
	if (args2) {
		args1 = PyTuple_GetSlice(*args, 0, nargs);
		if (!args1)
			goto bad;
		*args2 = PyTuple_GetSlice(*args, nargs, PyTuple_Size(*args));
		if (!*args2)
			goto bad;
	}
	if (kwds2) {
		if (*kwds) {
			char **p;
			kwds1 = PyDict_New();
			if (!kwds)
				goto bad;
			*kwds2 = PyDict_Copy(*kwds);
			if (!*kwds2)
				goto bad;
			for (p = kwd_list; *p; p++) {
				x = PyDict_GetItemString(*kwds, *p);
				if (x) {
					if (PyDict_SetItemString(kwds1, *p, x) < 0)
						goto bad;
					Py_DECREF(x);
					x = 0;
					if (PyDict_DelItemString(*kwds2, *p) < 0)
						goto bad;
				}
				else
					PyErr_Clear();
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
		if (kwds1)
			Py_INCREF(kwds1);
	}
	if (*args2)
		*args = args1;
	if (*kwds2)
		*kwds = kwds1;
	return 0;
bad:
	Py_XDECREF(x);
	Py_XDECREF(args1);
	Py_XDECREF(kwds1);
	if (*args2)
		Py_XDECREF(*args2);
	if (*kwds2)
		Py_XDECREF(*kwds2);
	return -1;
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
