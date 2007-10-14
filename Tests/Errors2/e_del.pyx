def f(a):
	cdef int i
	global j
	del f() # error
	del i # error: deletion of non-Python object
	del j # error: deletion of non-Python object
	del a # error: deletion of local name not supported
