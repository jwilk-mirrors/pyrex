cdef int f() nogil except *:
	pass

cdef void g() nogil:
	f()
