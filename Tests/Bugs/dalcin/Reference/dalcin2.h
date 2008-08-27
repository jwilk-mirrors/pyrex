#ifndef __PYX_HAVE__dalcin2
#define __PYX_HAVE__dalcin2
#ifdef __cplusplus
#define __PYX_EXTERN_C extern "C"
#else
#define __PYX_EXTERN_C extern
#endif

typedef struct {
  PyObject_HEAD
} PyFooObject;

#ifndef __PYX_HAVE_API__dalcin2

__PYX_EXTERN_C DL_IMPORT(PyTypeObject) PyFoo_Type;

#endif

PyMODINIT_FUNC initdalcin2(void);

#endif
