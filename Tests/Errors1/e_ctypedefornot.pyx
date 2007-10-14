cdef struct Foo

ctypedef struct Foo:
	int i
	
ctypedef struct Blarg:
	char c

cdef struct Blarg

cdef class Spam

ctypedef class Spam:
	pass
	
cdef Foo f
cdef Blarg b

