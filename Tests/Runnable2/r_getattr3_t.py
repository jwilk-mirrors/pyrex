from r_getattr3 import test

class Fred:
	pass

fred = Fred()
fred.mary = "Spam"

print test(fred, "mary", "Tomato")
print test(fred, "george", "Tomato")
