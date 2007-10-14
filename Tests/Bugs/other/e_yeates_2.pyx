cdef extern class external.PyArrayObject
cdef float *tmp
print boo[0:10]
print boo.typecode()
tmp=<float *>((<PyArrayObject>(boo)).data)
print tmp[0]
