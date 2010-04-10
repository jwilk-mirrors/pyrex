import traceback

def foo():
	try:
		""[1]
	except IndexError:
		traceback.print_exc()

foo()
