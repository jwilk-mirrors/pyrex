cdef extern from *:
	cdef void f() nogil
	cdef void (*fp)()

fp = f
