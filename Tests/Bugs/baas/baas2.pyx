def bar():
	cdef int a,b
	
	values = (1,2)
	dummy = 1.0
	
	a = values[0]
	b = values[1]
	
	tup = (a,b)
	print tup
