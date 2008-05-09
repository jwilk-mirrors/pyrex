cdef int i, j, k
cdef object a, b, x

for 0 <= i < 10:
	pass

for 0 < i <= 10:
	pass

for 10 >= i > 0:
	pass

for 10 > i >= 0:
	pass

for 0 <= x <= 10:
	pass

for a <= i <= b:
	pass

for k <= i <= j:
	pass

for k * 42 <= i <= j / 18:
	pass

while j:
	for i from 0 <= i <= 10:
		continue
		break
	else:
		continue
		break

