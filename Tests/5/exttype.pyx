cdef class Spam:

	cdef eggs
	cdef int ham

	def __cinit__(self, eggs):
		self.eggs = eggs
		self.ham = 42
	
	def __dealloc__(self):
		self.ham = 0
	
	def eat(self):
		gobble(self.eggs, self.ham)

def f(Spam spam or None):
	x = spam.eggs
	y = spam.ham
	z = spam.foo
	spam.eggs = x
	spam.ham = y
	spam.foo = z
