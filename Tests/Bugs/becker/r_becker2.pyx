def compute_breakpoints(self,
		 line_lengths,
		 double looseness = 0,
		 double tolerance = 1,
		 double fitness_demerit = 100,
		 double flagged_demerit = 100):
	cdef double r
	r = -1.41176470588
	if -1 <= r <= tolerance:
		print "if passed"
	else:
		print "if failed"

compute_breakpoints(None, None)

