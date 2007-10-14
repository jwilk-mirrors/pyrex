ctypedef int size_t

cdef extern from "stdlib.h":
     void* malloc(size_t size)
     void free(void* ptr)

cdef extern from "stdio.h":
     int printf(char* format, ...)

cdef extern from "Python.h":
     void* PyMem_Malloc(size_t n)
     void* PyMem_Realloc(void *p, size_t n)
     void PyMem_Free(void *p)

     int PyCObject_Check(object p)
     object PyCObject_FromVoidPtr(void* cobj, void (*destr)(void *))
     object PyCObject_FromVoidPtrAndDesc(void* cobj, void* desc,
             void (*destr)(void *, void *))
     void* PyCObject_AsVoidPtr(object self)
     void* PyCObject_GetDesc(object self)

cdef wrap_ptr(void* p, char* name):
     return PyCObject_FromVoidPtrAndDesc(p, name, NULL)

cdef void* extract_ptr(object P):
     return PyCObject_AsVoidPtr(P)

def CObject_ToPrettyString(object P):
     cdef int i
     cdef void* p
     cdef char* s
     if not PyCObject_Check(P):
         raise TypeError, 'not a CObject'
     p = PyCObject_AsVoidPtr(P)
     s = <char*> PyCObject_GetDesc(P)
     if p == NULL:
         val = "NULL"
     else:
         i = <int> p
         val = '0x%x' % i
     return '<CObject wrapping %s: %s>' % (s, val)
