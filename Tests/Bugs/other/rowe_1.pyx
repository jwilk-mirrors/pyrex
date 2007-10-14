cdef extern from "foo.h":
	void blarg(int i)

def function(data):
	cdef char *misc
	cdef object a
	blarg(4 * a) # bug
	return data[a:a + b]
