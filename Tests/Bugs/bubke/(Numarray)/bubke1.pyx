cdef extern from "numarray/numarray.h":

   struct PyArray_Descr:
     int type_num, elsize
     char type

   ctypedef class numarray._numarray._numarray [object PyArrayObject]:
     cdef char *data
     cdef int nd
     cdef int *dimensions, *strides
     cdef object base
     cdef PyArray_Descr *descr
     cdef int flags
     cdef object _data
     cdef object _shadows
     cdef long int nstrides
     cdef long byteoffset
     cdef long bytestride
     cdef long itemsize
     cdef char byteorder
     cdef char _aligned
     cdef char _contiguous
     cdef char *wptr
