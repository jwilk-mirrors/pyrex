import spam
print "Imported spam"
d = dir(spam)
for n in d:
	if n[0] <> "_":
		print n

import sys
print "Imported sys"
print sys

