cdef int foo() except -1:
	pass

cdef void blarg():
	while foo() == 0:
		pass
