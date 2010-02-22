def iowrap(f):
	try:
		e = f()
	except IOError, e:
		pass
	print repr(e)
	return e
