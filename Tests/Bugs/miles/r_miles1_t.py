import r_miles1, sys, traceback

try:
	r_miles1.my_raise()
except NotImplementedError, e:
	print e.__class__.__name__
	i = sys.exc_info()
	print "(%s, %s, instance of %s)" % (i[0], repr(i[1]), type(i[2]))
