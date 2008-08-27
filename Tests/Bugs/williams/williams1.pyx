cdef class Foo:
	cdef unsigned int num
	
	def __cinit__(self):
		self.num = 0
		print ['foo', 'bar'][self.num]

