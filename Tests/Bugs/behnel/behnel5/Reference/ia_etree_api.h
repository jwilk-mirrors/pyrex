#ifndef __PYX_HAVE_API__ia_etree
#define __PYX_HAVE_API__ia_etree
#include "Python.h"
#include "ia_etree.h"

static PyTypeObject *__pyx_ptype_8ia_etree__Document;
#define LxmlDocumentType (*__pyx_ptype_8ia_etree__Document)

static PyTypeObject *__pyx_ptype_8ia_etree__Element;
#define LxmlElementType (*__pyx_ptype_8ia_etree__Element)

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

static int import_ia_etree(void) {
  PyObject *module = 0;
  module = __Pyx_ImportModule("ia_etree");
  if (!module) goto bad;
  Py_DECREF(module);
  __pyx_ptype_8ia_etree__Document = __Pyx_ImportType("ia_etree", "_Document", sizeof(struct LxmlDocument)); if (!__pyx_ptype_8ia_etree__Document) goto bad
  __pyx_ptype_8ia_etree__Element = __Pyx_ImportType("ia_etree", "_Element", sizeof(struct LxmlElement)); if (!__pyx_ptype_8ia_etree__Element) goto bad
  return 0;
  bad:
  Py_XDECREF(module);
  return -1;
}

#endif
