cdef class C:
	cdef object __weakref__

cdef class D:
	cdef public object __weakref__

cdef class E:
	cdef readonly object __weakref__

cdef void f():
	cdef C c
	cdef object x
	x = c.__weakref__
	c.__weakref__ = x
