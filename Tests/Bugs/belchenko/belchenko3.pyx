cdef extern:
	void f(unsigned char a)

cdef void g():
	cdef char c
	f(<unsigned char> c)
