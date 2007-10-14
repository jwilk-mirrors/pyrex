def test(l):
	for x in l:
		try:
			return raises()
		except:
			pass
	return 1
