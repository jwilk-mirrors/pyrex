cdef class Swallow:

	def __init__(self, name, airspeed, *args, **kwds):
		print "Name:", name
		print "Airspeed:", airspeed
		print "Extra args:", args
		print "Extra keywords:", kwds
