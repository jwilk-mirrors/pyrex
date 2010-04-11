cdef class Spam:
	cdef int eggs

	def __iadd__(self, Spam other or None):
		self.eggs = self.eggs +  other.eggs

