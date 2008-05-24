cdef extern object g(object x) nogil
cdef extern void g2(object x) nogil

cdef void (*fp)(object)
cdef void (*fq)(object) nogil

cdef extern from "nogil.h" nogil:
	void e1()
	int *e2()

cdef void f(int x) nogil:
	cdef int y
	y = 42

cdef void h(object x) nogil:
	global fp, fq
	cdef void *p
	g2(x)
	g2(<object>p)
	p = <void *>x
	e1()
	e2()
	fp = g2
	fp = fq
