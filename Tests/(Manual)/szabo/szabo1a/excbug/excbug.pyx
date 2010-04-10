def iowrap(f):
	print "iowrap" ###
	try:
		###return f()
		e = f()
		print "f ->", repr(e) ###
	except IOError, e:
		###return e
		pass
	print "returning", repr(e) ###
	return e
