cdef int i
j = 0
i = 1
l = ['zero', 'one']
d = {0: 'two', 1: 'three'}
print l[j]
print l[i]
print d[j]
print d[i]
l[j] = 'Zero'
d[j] = 'Two'
print l[j]
print l[i]
print d[j]
print d[i]
l[i] = 'ONE'
d[i] = 'THREE'
print l[j]
print l[i]
print d[j]
print d[i]
