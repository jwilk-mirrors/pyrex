cdef extern from "complexobject.h":
	
	struct Py_complex:
		double real
		double imag
	
	ctypedef class __builtin__.complex [object PyComplexObject]:
		cdef Py_complex cval
	
def spam(complex c or None):
	print "Real:", c.cval.real
	print "Imag:", c.cval.imag

def eggs():
	return complex(17, 42)
