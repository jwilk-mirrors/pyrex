cdef extern class somewhere.Swallow:
	pass

cdef Swallow swallow

def spam(x = swallow, Swallow y or None = swallow):
	pass
