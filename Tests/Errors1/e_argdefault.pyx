cdef spam(int i, char *s = "blarg", float f): # can't have default value
	pass

def swallow(x, y = 42, z): # non-default after default
	pass

cdef class Grail:

	def __add__(x, y = 42): # can't have default value
		pass
