def f():
	cdef int int1, int2
	cdef int *ptr
	int1 = int2 * ptr # error
