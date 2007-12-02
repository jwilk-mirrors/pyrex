#ifndef __PYX_HAVE__i_burton2
#define __PYX_HAVE__i_burton2
#ifdef __cplusplus
#define __PYX_EXTERN_C extern "C"
#else
#define __PYX_EXTERN_C extern
#endif

struct FooObj {
  PyObject_HEAD
};

#ifndef __PYX_HAVE_API__i_burton2

__PYX_EXTERN_C DL_IMPORT(PyTypeObject) FooType;

#endif

PyMODINIT_FUNC initi_burton2(void);

#endif
