cdef class A
cdef class B
cdef class C(A)
cdef class D(A)
cdef class E(A)

cdef class A:
	pass

cdef class B(A):
	pass

cdef class C:
	pass

cdef class D(B):
	pass

cdef class E(A):
	pass
