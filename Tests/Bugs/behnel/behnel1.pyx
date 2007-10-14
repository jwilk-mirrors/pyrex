cdef class Spam:
	cdef eggs(self):
		pass

cdef Spam spam():
	pass

cdef viking():
	return spam().eggs()
