cdef class C(list):
	pass

def f():
	cdef list l
	cdef C c
	cdef object x, y
	x = l[17]
	y = c[42]
	l.append(88)
	c.append(99)
