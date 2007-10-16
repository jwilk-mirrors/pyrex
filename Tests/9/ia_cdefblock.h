#ifndef __PYX_HAVE__ia_cdefblock
#define __PYX_HAVE__ia_cdefblock
#ifdef __cplusplus
#define __PYX_EXTERN_C extern "C"
#else
#define __PYX_EXTERN_C extern
#endif

struct PubFoo {
  int i;
};

struct PubBlargObj {
  PyObject_HEAD
};

#ifndef __PYX_HAVE_API__ia_cdefblock

__PYX_EXTERN_C DL_IMPORT(int) pub_v;

__PYX_EXTERN_C DL_IMPORT(void) pub_f(void);
__PYX_EXTERN_C DL_IMPORT(void) pub_api_f(void);

__PYX_EXTERN_C DL_IMPORT(PyTypeObject) PubBlargType;

#endif

PyMODINIT_FUNC initia_cdefblock(void);

#endif
