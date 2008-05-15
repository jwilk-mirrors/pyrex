cimport foo

cdef class foo.Foo
cdef struct foo.Spam

cdef struct Eggs:
	foo.Spam *spam

cdef class Blarg:
	cdef object name
	cdef foo.Foo foo
