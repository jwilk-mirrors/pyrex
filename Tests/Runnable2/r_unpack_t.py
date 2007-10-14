from r_unpack import f, g, h

f()

try:
	g()
except Exception, e:
	print e

try:
	h()
except Exception, e:
	print e
