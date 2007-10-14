from r_kwonlyargs import *

def test(func, *args, **kwds):
	argdesc = ", ".join(map(str, args))
	kvs = kwds.items()
	kvs.sort()
	kwddesc = ", ".join(["%s = %r" % kv for kv in kvs])
	desc = ", ".join([x for x in (argdesc, kwddesc) if x])
	print "Calling %s(%s)" % (func.__name__, desc)
	try:
		func(*args, **kwds)
	except Exception, e:
		print "Caught:", e
	else:
		print "Okay"
	print

test(c, 1, 2)
test(c, 1, 2, 3)
test(c, 1, 2, 3, 4)

print "--------------------\n"

test(d, 1)
test(d, 1, 2)
test(d, 1, 2, 3)
test(d, 1, 2, c = 3)

print "--------------------\n"

test(e, 1)
test(e, 1, 2)
test(e, 1, 2, 3)
test(e, 1, 2, 3, 4)
test(e, 1, c = 3, b = 2)
test(e, 1, c = 3, b = 2, d = 4)
test(e, 1, c = 3, b = 2, d = 4, e = 5)

print "--------------------\n"

test(f, 1)
test(f, 1, 2)
test(f, 1, 2, 3)
test(f, 1, 2, c = 3)
test(f, 1, 2, c = 3, d = 4)
test(f, 1, 2, c = 3, d = 4, e = 5)

print "--------------------\n"

test(g, 1, 2)
test(g, 1, 2, 3)
test(g, 1, 2, c = 3)
test(g, 1, 2, c = 3, f = 4)
test(g, 1, 2, c = 3, d = 4, e = 5, f = 6)
test(g, 1, 2, c = 3, f = 4, g = 5, h = 6)

print "--------------------\n"

test(h, 1, 2)
test(h, 1, 2, c = 3)
test(h, 1, 2, c = 3, f = 4)
test(h, 1, 2, 3, 4, c = 5, f = 6)
test(h, 1, 2, c = 3, d = 4, e = 5, f = 6)
test(h, 1, 2, c = 3, f = 4, g = 5, h = 6)
