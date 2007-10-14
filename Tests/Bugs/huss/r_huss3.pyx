def bar():
	try:
		raise TypeError
	except TypeError:
		pass

def foo():
	try:
		raise ValueError
	except ValueError, e:
		bar()
		raise
