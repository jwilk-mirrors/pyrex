ctypedef int foo

cdef foo bar():
    cdef int i

    return (((foo)(i) << 1) | BLAH)
