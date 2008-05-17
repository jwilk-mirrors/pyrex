cimport blarg as blg

cdef class blg.Blarg
cdef struct blg.Eggs

cdef struct Spam:
	blg.Eggs *eggs

cdef class Foo:
	cdef object name
	cdef blg.Blarg blarg
