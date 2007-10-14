import sys, traceback
import r_traceback

try:
	r_traceback.tomato()
except Exception, e:
	traceback.print_exception(file = sys.stdout, *sys.exc_info())

	