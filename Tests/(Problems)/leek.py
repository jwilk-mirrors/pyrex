import gc
from naanou_1 import f

gc.set_debug(gc.DEBUG_LEAK | gc.DEBUG_STATS)
print "Doing it"
for i in xrange(10):
	for i in xrange(100):
		f(42, "a", 88.8, fred = "pants")
	print "Collecting"
	gc.collect()
print "Done"
