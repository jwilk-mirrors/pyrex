cdef object f(object x) nogil:
	pass

cdef void g(int x) nogil:
	cdef object z
	z = None

cdef void h(int x) nogil:
	p()

cdef object p() nogil:
	pass

cdef void k() nogil:
	q()
	
cdef void m():
	cdef object obj
	cdef int i
	q()
	with nogil:
		k()
		q()
		i = 42
		obj = None

cdef void q():
	pass
