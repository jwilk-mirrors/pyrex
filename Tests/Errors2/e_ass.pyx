cdef void foo(obj):
	cdef int i1
	cdef char *p1
	cdef int *p2
	i1 = p1 # error
	p2 = obj # error
