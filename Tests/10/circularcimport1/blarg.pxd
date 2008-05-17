cimport foo

cdef struct foo.Spam
cdef class foo.Foo

cdef struct Eggs:
	foo.Spam *spam

cdef class Blarg:
	cdef object name
	cdef foo.Foo foo
