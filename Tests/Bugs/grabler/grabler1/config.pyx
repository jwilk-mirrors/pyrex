cdef extern from "stdlib.h":
	ctypedef unsigned long size_t
	void *malloc(int len)
	size_t sizeof(void *)

from t_config cimport pyalpm_list

cdef class config:
	def addIgnorePkg(self, char *in_pkgname):
		cdef t_config.pyalpm_list *ptr

		if self.IgnorePkg:
			ptr = self.IgnorePkg
			while ptr.next:
				ptr = ptr.next

			#ptr.next = <t_config.pyalpm_list *> malloc(sizeof(t_config.pyalpm_list))
			ptr.next = <pyalpm_list *> malloc(sizeof(pyalpm_list))
			ptr = ptr.next
			ptr.pkgname = in_pkgname
		else:
			#self.IgnorePkg = <t_config.pyalpm_list *> malloc(sizeof(t_config.pyalpm_list))
			self.IgnorePkg = <pyalpm_list *> malloc(sizeof(pyalpm_list))
			self.IgnorePkg.pkgname = in_pkgname

		return

	def remIgnorePkg(self, char *pkgname):
		return 1

