cdef class DD:
#	cdef int _dd, _opened

	def term(self):
#		self._opened
#		if self._opened: self.close()
		self.close()
#		check_status(SXLB_TERM_DD(self._dd))

	def close(self):
#		self._opened
#		check_status(SXLB_CLOSE(self._dd,0))
#		self._opened=0
		pass
