cdef struct Spam

cdef extern int spam(void)           # function argument cannot be void
cdef extern int grail(int i, void v) # function argument cannot be void
cdef int tomato(Spam s):             # incomplete type
	pass
