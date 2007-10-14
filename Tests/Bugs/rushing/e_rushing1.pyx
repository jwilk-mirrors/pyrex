cdef class thing1:
	cdef int size
	cdef int __len__ (self):
		return self.size

cdef class thing2(thing1):
	pass
