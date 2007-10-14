import sys, traceback
import r_tbfilename
try:
	r_tbfilename.foo()
except:
	traceback.print_exc(None, sys.stdout)
