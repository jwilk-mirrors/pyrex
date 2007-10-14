cdef void foo():
	cdef int bool, int1
	cdef char *ptr2
	cdef int *ptr3
	bool = int1 == ptr2 # error
	bool = ptr2 == ptr3 # error
