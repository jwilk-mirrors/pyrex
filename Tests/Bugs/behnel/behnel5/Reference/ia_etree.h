#ifndef __PYX_HAVE__ia_etree
#define __PYX_HAVE__ia_etree
#ifdef __cplusplus
#define __PYX_EXTERN_C extern "C"
#else
#define __PYX_EXTERN_C extern
#endif

struct LxmlDocument {
  PyObject_HEAD
  struct __pyx_t_4tree_xmlDoc *_c_doc;
  struct __pyx_obj_8ia_etree__BaseParser *_parser;
};

struct LxmlElement {
  PyObject_HEAD
  struct LxmlDocument *_doc;
  struct __pyx_t_4tree_xmlNode *_c_node;
};

#ifndef __PYX_HAVE_API__ia_etree

__PYX_EXTERN_C DL_IMPORT(PyTypeObject) LxmlDocumentType;
__PYX_EXTERN_C DL_IMPORT(PyTypeObject) LxmlElementType;

#endif

PyMODINIT_FUNC initia_etree(void);

#endif
