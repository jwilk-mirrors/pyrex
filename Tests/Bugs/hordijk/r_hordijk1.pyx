cdef extern from "Python.h":
	ctypedef class types.ListType [object PyListObject]:
		pass

cdef class Spam(ListType):
	def __init__(self):
		raise StandardError("This is not a spanish inquisition")
