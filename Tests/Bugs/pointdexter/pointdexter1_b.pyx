cdef class B(pointdexter1_a.A):
	def __init__(self,length,width):
		pointdexter1_a.A.__init__(self,length)
		self.width=width
