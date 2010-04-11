from r_toofewargs import Spam

try:
	s = Spam()
except Exception, e:
	print e.__class__.__name__
