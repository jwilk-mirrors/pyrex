cdef extern from "spam.h":

	ctypedef class spam.Spam [object PySpamObject]:
		pass


cdef class SpamAndEggs(Spam):

	cdef cook(self):
		pass
