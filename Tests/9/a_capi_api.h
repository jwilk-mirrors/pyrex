#ifndef __PYX_HAVE_API__a_capi
#define __PYX_HAVE_API__a_capi
#include "Python.h"
#include "a_capi.h"

static PyTypeObject *__pyx_ptype_6a_capi_C;
#define C_Type (*__pyx_ptype_6a_capi_C)

static float (*f)(struct Foo *);
static void (*h)(Zax *);

#ifndef __PYX_HAVE_API_FUNC_import_module
#define __PYX_HAVE_API_FUNC_import_module

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

#endif


#ifndef __PYX_HAVE_RT_ImportFunction
#define __PYX_HAVE_RT_ImportFunction
static int __Pyx_ImportFunction(PyObject *module, char *funcname, void **f, char *sig) {
	PyObject *d = 0;
	PyObject *cobj = 0;
	char *desc;
	
	d = PyObject_GetAttrString(module, "__pyx_capi__");
	if (!d)
		goto bad;
	cobj = PyDict_GetItemString(d, funcname);
	if (!cobj) {
		PyErr_Format(PyExc_ImportError,
			"%s does not export expected C function %s",
				PyModule_GetName(module), funcname);
		goto bad;
	}
	desc = (char *)PyCObject_GetDesc(cobj);
	if (!desc)
		goto bad;
	if (strcmp(desc, sig) != 0) {
		PyErr_Format(PyExc_TypeError,
			"C function %s.%s has wrong signature (expected %s, got %s)",
				PyModule_GetName(module), funcname, sig, desc);
		goto bad;
	}
	*f = PyCObject_AsVoidPtr(cobj);
	Py_DECREF(d);
	return 0;
bad:
	Py_XDECREF(d);
	return -1;
}
#endif


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
#ifdef __PYX_CHECK_IMPORTED_TYPES
	if (((PyTypeObject *)result)->tp_basicsize != size) {
		PyErr_Format(PyExc_ValueError, 
			"%s.%s does not appear to be the correct type object",
			module_name, class_name);
		goto bad;
	}
#endif
	return (PyTypeObject *)result;
bad:
	Py_XDECREF(result);
	return 0;
}
#endif

static int import_a_capi(void) {
  PyObject *module = 0;
  module = __Pyx_ImportModule("a_capi");
  if (!module) goto bad;
  if (__Pyx_ImportFunction(module, "f", (void**)&f, "float (struct Foo *)") < 0) goto bad;
  if (__Pyx_ImportFunction(module, "h", (void**)&h, "void (Zax *)") < 0) goto bad;
  Py_DECREF(module); module = 0;
  __pyx_ptype_6a_capi_C = __Pyx_ImportType("a_capi", "C", sizeof(struct C_Obj)); if (!__pyx_ptype_6a_capi_C) goto bad;
  return 0;
  bad:
  Py_XDECREF(module);
  return -1;
}

#endif
