cdef extern from "Python.h":
	void Py_INCREF(object o)
	void Py_DECREF(object o)
