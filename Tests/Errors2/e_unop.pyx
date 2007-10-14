def f():
	cdef int int1
	cdef char *str2
	int1 = -str2 # error
	int1 = ~str2 # error
