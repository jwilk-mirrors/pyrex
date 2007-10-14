from Numeric import Float

cdef extern from "Numeric/arrayobject.h":

	struct PyArray_Descr:
		int type_num, elsize
		char type
	
	ctypedef class Numeric.ArrayType [object PyArrayObject]:
		cdef char *data
		cdef int nd
		cdef int *dimensions, *strides
		cdef object base
		cdef PyArray_Descr *descr
		cdef int flags
	
	void import_array()

import_array()

cdef _test(ArrayType img):
	pass

def test(src):
	return _test(src.astype(Float))
