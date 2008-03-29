cdef int f() except -1:
	cdef object x, y, z
	cdef int i
	z = x[y]
	z = x[i]
	x[y] = z
	x[i] = z
