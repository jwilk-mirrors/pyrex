cdef int f() except -1:
	cdef list l
	cdef object z
	l = list(x)
	l = list(*y)
	z = l.insert
	l.insert(17, 42)
	l.append(88)
	l.sort()
	l.reverse()
	z = l.as_tuple()
