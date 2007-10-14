#ifndef __PYX_HAVE_API__i_public
#define __PYX_HAVE_API__i_public
#include "Python.h"
#include "i_public.h"

static PyTypeObject *__pyx_ptype_8i_public_sandwich;
#define sandwich_Type (*__pyx_ptype_8i_public_sandwich)

#ifndef __PYX_HAVE_API_FUNC_import_module
#define __PYX_HAVE_API_FUNC_import_module

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

#ifndef __PYX_HAVE_API_FUNC_import_type
#define __PYX_HAVE_API_FUNC_import_type

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

static int import_i_public(void) {
  PyObject *module = 0;
  module = __Pyx_ImportModule("i_public");
  if (!module) goto bad;
  Py_DECREF(module);
  __pyx_ptype_8i_public_sandwich = __Pyx_ImportType("i_public", "sandwich", sizeof(struct sandwich)); if (!__pyx_ptype_8i_public_sandwich) goto bad
  return 0;
  bad:
  Py_XDECREF(module);
  return -1;
}

#endif
