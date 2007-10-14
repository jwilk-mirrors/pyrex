from r_barbieri1 import B

try:
	B()
except Exception, e:
	print "%s: %s" % (e.__class__.__name__, e)
