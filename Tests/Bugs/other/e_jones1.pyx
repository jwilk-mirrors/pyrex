include "jones-1.pxi"

cdef extern from "tiny.h":

     ctypedef struct Small:
         int iC "i"
         double xC "x"
         int* uC "u"

     ctypedef struct AAA:
         Small smC "sm"
         Small* smpC "smp"

cdef class TemP__Small:
     cdef Small* t

     def __cinit__(self, object iPY, xPY, uPY):
         self.t = <Small*> PyMem_Malloc(sizeof(Small))
         if self.t == NULL:
             raise MemoryError
         self.t.iC = iPY
         self.t.xC = xPY
         if uPY is None:
             self.t.uC = NULL
         else:
             self.t.uC = <int *> extract_ptr(uPY)

     def __dealloc__(self):
         PyMem_Free(self.t)

     def __getattr__(self, name):
         if name == 'i':
             return self.t.iC
         if name == 'x':
             return self.t.xC
         if name == 'u':
             return wrap_ptr(self.t.uC, 'Small.u')
         return object.__getattribute__(self, name)

     def __setattr__(self, name, valPY):
         if name == 'i':
             self.t.iC = valPY
         if name == 'x':
             self.t.xC = valPY
         if name == 'u':
             self.t.uC = <int *> extract_ptr(valPY)
         else:
             object.__setattr__(self, name, valPY)

     def ToPointer(self):
         return  PyCObject_FromVoidPtrAndDesc(self.t, 'type Small*', NULL)

cdef TemP__Small_toC(object PY, Small* C):
     C.iC = PY.i
     C.xC = PY.x
     C.uC = <int *> extract_ptr(PY.u)

cdef TemP__Small_FromC(Small* smC):
     return TemP__Small(smC.iC, smC.xC, wrap_ptr(smC.uC, 'Small.u'))

cdef class TemP__AAA:
     cdef AAA* t

     def __cinit__(self, smPY, smpPY):
         self.t = <AAA*> PyMem_Malloc(sizeof(AAA))
         if self.t == NULL:
             raise MemoryError
         cdef int LocaLi
         cdef int LocaLj
         TemP__Small_toC(smPY, &self.t.smC)
         self.t.smpC = <Small*> extract_ptr(smpPY)

     def __dealloc__(self):
         PyMem_Free(self.t)

     def __getattr__(self, name):
         if name == 'sm':
             return TemP__Small_FromC(&self.t.smC)
         if name == 'smp':
             return self.t.smpC.Topointer()
         return object.__getattribute__(self, name)

     def __setattr__(self, name, valPY):
         cdef int LocaLi
         cdef int LocaLj
         if name == 'sm':
             TemP__Small_toC(valPY, &self.t.smC)
         if name == 'smp':
             return wrap_ptr(self.t.smpC, 'AAA.smp')
         else:
             object.__setattr__(self, name, valPY)

     def ToPointer(self):
         return  PyCObject_FromVoidPtrAndDesc(self.t, 'type AAA*', NULL)

cdef TemP__AAA_toC(object PY, AAA* C):
     TemP__Small_toC(PY.sm, &C.smC)

cdef TemP__AAA_FromC(AAA* C):
     smPY = TemP__Small_FromC(&C.smC)
     return TemP__AAA(smPY)
