cdef object f(object x) nogil:
	pass

cdef void g(int x) nogil:
	cdef object z
	z = None

cdef void h(int x) nogil:
	p()

cdef p():
	pass
