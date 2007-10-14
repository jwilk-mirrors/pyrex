from weakref import ref
from r_extweakref import Animal

a = Animal()
a.name = "Boris"
w = ref(a)
print "The animal's name is", w().name
a = None
print "Bang!"
print "The animal is now", w()
