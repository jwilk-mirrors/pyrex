cdef extern class external.Spam [object Spam]: pass
cdef extern class external.Eggs [object Eggs]: pass

def ham(Spam s or None, Eggs e not None):
	pass
