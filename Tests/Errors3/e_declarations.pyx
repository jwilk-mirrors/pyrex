cdef extern void fa[5]()
cdef extern int af()[5]
cdef extern int ff()()

cdef void f():
	cdef void *p
	cdef int (*h)()
	h = <int ()()>f
