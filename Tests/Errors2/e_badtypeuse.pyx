cdef struct Grail

cdef extern object xobj # Python object cannot be extern
cdef object aobj[42]    # array element cannot be Python object
cdef object *pobj       # pointer base type cannot be Python object

cdef int spam[] # incomplete variable type
cdef Grail g     # incomplete variable type
cdef void nada   # incomplete variable type

cdef int a_spam[17][]  # incomplete element type
cdef Grail a_g[42]     # incomplete element type
cdef void a_nada[88]   # incomplete element type

cdef struct Eggs:
	int spam[]

cdef f(Grail g,   # incomplete argument type
	void v,         # incomplete argument type
	int a[]):
		pass

