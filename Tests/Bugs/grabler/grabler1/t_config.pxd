cdef struct pyalpm_list:
	char *pkgname
	pyalpm_list *next
