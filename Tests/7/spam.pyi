cdef extern void f()

cdef int eggs() except -1:
	x = 42
