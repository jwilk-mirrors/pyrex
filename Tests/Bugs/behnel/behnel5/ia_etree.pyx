cdef struct Foo:
	int spam

cdef public class _Document [type LxmlDocumentType, object LxmlDocument]:
	pass

cdef public class _Element [type LxmlElementType, object LxmlElement]:
	pass
	
cdef class Vorpal:
	pass

cdef class _BaseParser:
	cdef Foo *foo
	cdef Vorpal bunny

cdef object getAttributeValue(_Element element, key, default):
	pass
