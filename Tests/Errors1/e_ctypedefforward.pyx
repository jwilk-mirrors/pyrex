ctypedef struct Spam
ctypedef class Eggs

cdef extern from *:
	ctypedef struct Ham

ctypedef struct Spam:
	int i

ctypedef class Eggs:
	pass

ctypedef struct Spam
ctypedef class Eggs
