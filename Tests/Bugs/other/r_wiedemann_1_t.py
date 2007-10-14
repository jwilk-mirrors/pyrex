from r_wiedemann_1 import test
from Numeric import zeros
import sys

def leakage():
	a = zeros((300,300))
	b = zeros((300,300))
	print sys.getrefcount(a), sys.getrefcount(b)
	test(b)
	print sys.getrefcount(a), sys.getrefcount(b)

leakage()
