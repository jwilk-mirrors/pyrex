def foo(obj):
	cdef int *p
	p = <int *>blarg # okay
	p = <int *>(foo + blarg) # error - temporary
