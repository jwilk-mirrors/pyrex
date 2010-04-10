cdef int f(a) except -1:
	cdef int i
	cdef object e, t
	try:
		i = 1
	except a, e, t:
		i = 2
