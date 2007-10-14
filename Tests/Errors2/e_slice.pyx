def f(obj2):
	cdef int *ptr1
	obj1 = obj2[ptr1::] # error
	obj1 = obj2[:ptr1:] # error
	obj1 = obj2[::ptr1] # error
