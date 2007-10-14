cdef struct spam:
	object parrot

def f():
	cdef spam s
	s.parrot = x
