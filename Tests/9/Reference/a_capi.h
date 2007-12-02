#ifndef __PYX_HAVE__a_capi
#define __PYX_HAVE__a_capi
#ifdef __cplusplus
#define __PYX_EXTERN_C extern "C"
#else
#define __PYX_EXTERN_C extern
#endif

struct Foo {
  int a;
  int b;
};

typedef struct Foo Zax;

struct C_Obj {
  PyObject_HEAD
};

#ifndef __PYX_HAVE_API__a_capi

__PYX_EXTERN_C Zax *blarg;

__PYX_EXTERN_C DL_IMPORT(void) g(__pyx_t_6a_capi_Blarg *);
__PYX_EXTERN_C DL_IMPORT(void) h(Zax *);

__PYX_EXTERN_C DL_IMPORT(PyTypeObject) C_Type;

#endif

PyMODINIT_FUNC inita_capi(void);

#endif
