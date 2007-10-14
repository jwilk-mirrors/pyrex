cdef class A:
	def __cinit__(self):
		raise Exception("crash-me")

cdef class B(A):
	def __cinit__(self):
		print "hello world"
