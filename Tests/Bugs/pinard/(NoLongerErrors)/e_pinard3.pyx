cdef extern from *:
    ctypedef struct SIGDEC_CP:
        char code[3]

cdef class Fiches_CP:
    cdef valeurs(self, SIGDEC_CP *cp):
        pass
