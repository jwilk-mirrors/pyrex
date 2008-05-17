from foo cimport class Foo, struct Spam

cdef union Eggs:
	Spam *spam

cdef class Blarg:
	cdef object name
	cdef Foo foo
