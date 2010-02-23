from foo cimport foo_t

cdef extern from "bar.h":
    ctypedef foo_t bar_t
