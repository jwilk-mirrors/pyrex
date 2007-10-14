def f():
	cdef char *str1
	cdef float flt1, flt2, flt3
	flt1 = str1 ** flt3 # error
	flt1 = flt2 ** str1 # error
