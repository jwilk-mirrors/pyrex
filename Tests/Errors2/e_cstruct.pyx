cdef struct Spam:
	int i
	char c
	float *p[42]
	obj             # error - py object

cdef struct Spam: # error - redefined
	int j

cdef struct Grail

cdef void eggs(Spam s):
	cdef int j
	cdef Grail *gp
	j = s.k # error - undef attribute
	j = s.p # type error
	s.p = j # type error
	j = j.i # error - no attributes
	j.i = j # error - no attributes
	j = gp.x # error - incomplete type
	gp.x = j # error - incomplete type
	