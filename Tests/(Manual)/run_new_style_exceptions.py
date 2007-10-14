import sys
from new_style_exceptions import test

def pytest(obj):
	print "Raising:", repr(obj)
	try:
		raise obj
	except:
		info = sys.exc_info()
		print "Python: Caught: %r %r" % (info[0], info[1])

class Old:
	pass

class New(object):
	pass


test("Foo")
test(Old)
test(Old())

try:
	class Exc(BaseException):
		pass
except NameError:
	print "New style exceptions not available"
else:
	test(Exc)
	test(Exc())
	pytest(Exc)
	pytest(Exc())
