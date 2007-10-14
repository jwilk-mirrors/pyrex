from r_hordijk1 import Spam
try:
	s = Spam()
except StandardError, e:
	print "Exception:", e
else:
	print "Did not raise the expected exception"
