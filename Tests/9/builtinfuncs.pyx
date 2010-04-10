cdef int f() except -1:
	cdef object x, y, z, w
	cdef int i
	x = abs(y)
	i = bool(x)
	delattr(x, 'spam')
	x = dir(y)
	x = divmod(y, z)
	x = getattr(y, 'spam')
	i = hasattr(y, 'spam')
	i = hash(y)
	x = cintern(y)
	i = isinstance(y, z)
	i = issubclass(y, z)
	x = iter(y)
	x = iter2(y, z)
	i = len(x)
	x = open(y, z)
	x = pow(y, z, w)
	x = reload(y)
	x = repr(y)
	setattr(x, y, z)
	x = abs
