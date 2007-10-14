from r_huss3 import foo

try:
	foo()
except Exception, e:
	print "%s: %s" % (e.__class__.__name__, e)
