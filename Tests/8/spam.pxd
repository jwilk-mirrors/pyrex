cdef struct Spam:
	int i
	char *s

cdef extern void eat(Spam)

cdef extern float tons
