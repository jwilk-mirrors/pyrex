cdef int f() except -1:
	cdef list x
	cdef object y, z
	cdef int i
	cdef unsigned int ui
	z = x[y]
	z = x[i]
	x[y] = z
	x[i] = z
	z = x[ui]
	x[ui] = z
