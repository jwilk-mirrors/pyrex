cdef class Widget
cdef class Container

cdef class Widget:
	cdef Container parent

cdef class Container(Widget):
	pass
