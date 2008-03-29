ctypedef enum enum_type:
	AAA

ctypedef enum_type enum2_type

cdef int test2() except -1:
	cdef enum_type  p
	cdef enum2_type q
	cdef int i
	i = p == q
