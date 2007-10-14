cdef class C:
	pass

cdef class D:
	def __mod__(x, C y):
		cdef C c
		if c is y:
			pass

cdef void f():
	cdef C c
	if c is None:
		pass
