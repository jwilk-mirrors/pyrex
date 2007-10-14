from r_toofewargs import Spam

try:
	s = Spam()
except Exception, e:
	print "%s: %s" % (e.__class__.__name__, e)
