cdef enum Spam:
	a, b, c

cdef void f():
	global a
	a = 42      # assignment to non-lvalue
	
