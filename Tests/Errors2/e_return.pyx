cdef void g():
	cdef int i
	return i # error

cdef int h():
	cdef int *p
	return # error
	return p # error
