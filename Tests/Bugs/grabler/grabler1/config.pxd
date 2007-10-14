cimport t_config

cdef class config:
	cdef t_config.pyalpm_list *NoUpgrade
	cdef t_config.pyalpm_list *IgnorePkg

