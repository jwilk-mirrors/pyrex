#cdef extern from "r_bishop3_debug.h":
#	void bugrit(char *, type)

cdef class Foo:
	cdef int val
	cdef object obj

	def __init__(self):
		self.val = 0


cdef class Fee(Foo):

	def bof(self):
		print 'Fee bof', self.val


cdef class Faa(Fee):

	def bof(self):
		print 'Foo bof', self.val

#bugrit("Foo", Foo)
#bugrit("Fee", Fee)
#bugrit("Faa", Faa)
