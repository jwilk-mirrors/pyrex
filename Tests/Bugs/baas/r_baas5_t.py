import sys
import r_baas5

try:
	try:
		r_baas5.foo()
	except IOError:
		print "xxx"
except:
	e = sys.exc_value
	print "%s: %s" % (e.__class__.__name__, e)
