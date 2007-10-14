cdef extern grail(char *s, int i)
cdef extern spam(char *s, int i,...)

cdef f():
	grail() # too few args
	grail("foo") # too few args
	grail("foo", 42, 17) # too many args
	spam() # too few args
	spam("blarg") # too few args
