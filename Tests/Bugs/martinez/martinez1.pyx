cdef class CoordSyst:
	pass

cdef extern void *chunk_get_ptr()

cdef int f() except -1:
	cdef CoordSyst  parent
	parent  = <CoordSyst> chunk_get_ptr()
