cdef class Spam:

	def __delitem__(self, key):
		print "del item %s" % key
