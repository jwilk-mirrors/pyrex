cimport tree

cdef class _BaseParser

cdef public api class _Document [type LxmlDocumentType, object LxmlDocument]:
    cdef tree.xmlDoc *_c_doc
    cdef _BaseParser _parser

cdef public api class _Element [type LxmlElementType, object LxmlElement]:
    cdef _Document _doc
    cdef tree.xmlNode *_c_node

cdef object getAttributeValue(_Element element, key, default)

