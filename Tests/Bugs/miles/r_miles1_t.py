import r_miles1, sys, traceback

try:
	r_miles1.my_raise()
except NotImplementedError, e:
	print e.__class__.__name__
	print sys.exc_info()
