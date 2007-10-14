#ifndef __PYX_HAVE_API__capi
#define __PYX_HAVE_API__capi
static float ((*f)(float ));
#ifndef __PYX_HAVE_API_FUNCS
#define __PYX_HAVE_API_FUNCS

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

static int __Pyx_ImportFunction(PyObject *module, char *funcname, void **f, char *sig) {
	PyObject *cobj = 0;
	char *desc;
	
	cobj = PyObject_GetAttrString(module, funcname);
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
	Py_DECREF(cobj);
	return 0;
bad:
	Py_XDECREF(cobj);
	return -1;
}
#endif
static int import_capi(void) {
  PyObject *module = 0;
  module = __Pyx_ImportModule("capi");
  if (!module) goto bad;
  if (__Pyx_ImportFunction(module, "f", (void**)&f, "float (()(float))") < 0) goto bad;
  Py_DECREF(module);
  return 0;
  bad:
  Py_XDECREF(module);
  return -1;
}
#endif
