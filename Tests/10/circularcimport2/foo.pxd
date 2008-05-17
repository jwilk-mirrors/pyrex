from blarg cimport union Eggs, class Blarg

cdef struct Spam:
	Eggs *eggs

cdef class Foo:
	cdef object name
	cdef Blarg blarg
