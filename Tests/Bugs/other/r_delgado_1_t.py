from r_delgado_1 import eggs

try:
	eggs().eat()
except RuntimeError, e:
	print "%s: %s" % (e.__class__.__name__, e)
