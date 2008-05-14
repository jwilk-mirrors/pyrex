cdef class Foo:

	def report(self):
		print "I am a Foo."
		print "My name is", self.name
		print "My blarg's name is", self.b.name
