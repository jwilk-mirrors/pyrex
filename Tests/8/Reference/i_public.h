#ifdef __cplusplus
#define __PYX_EXTERN_C extern "C"
#else
#define __PYX_EXTERN_C extern
#endif

struct sandwich {
  PyObject_HEAD
  int tomato;
  float lettuce;
};

#ifndef __PYX_HAVE_API__i_public

__PYX_EXTERN_C DL_IMPORT(int) grail;

__PYX_EXTERN_C DL_IMPORT(PyObject) *spam(int);

__PYX_EXTERN_C DL_IMPORT(PyTypeObject) sandwich_Type;

#endif

PyMODINIT_FUNC initi_public(void);
