ctypedef char carray[10]

cdef void f():
	cdef carray a[1]
	a[0] = "abcdef"
