cdef class MyClass:
	pass

def foo(MyClass c or None):
	cdef MyClass res
	res = c
	return res
