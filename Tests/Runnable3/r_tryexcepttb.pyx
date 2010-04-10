def test():
	try:
		raise ValueError("Too many eels in hovercraft")
	except ValueError, e, t:
		print "Exception:", e
		print "Traceback:", t
