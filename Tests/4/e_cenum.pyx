cdef enum Spam:
	a

cdef void eggs():
	cdef Spam s1, s2, s3
	cdef int i
	s1 = i
	s1 = s2 + i
	s1 = s2 + s3
