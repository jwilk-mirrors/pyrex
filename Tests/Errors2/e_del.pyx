cdef struct S:
	int m

def f(a):
	cdef int i, x[2]
	cdef S s
	global j
	del f() # error
	del i # error: deletion of non-Python object
	del j # error: deletion of non-Python object
	del a # error: deletion of local name not supported
	del x[i] # error: deletion of non-Python object
	del s.m # error: deletion of non-Python object
