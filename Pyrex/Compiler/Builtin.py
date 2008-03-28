#
#   Pyrex - Builtin Definitions
#

from Symtab import BuiltinScope
from TypeSlots import Signature

builtin_function_table = [
	# name,        args,   return,  C API func,           py equiv = "*"
	('abs',        "O",    "O",     "PyNumber_Absolute"),
	('bool',       "O",    "i",     "PyObject_IsTrue"),
	#('chr',       "",     "",      ""),
	#('cmp', "",   "",     "",      ""), # int PyObject_Cmp(PyObject *o1, PyObject *o2, int *result)
	#('compile',   "",     "",      ""), # PyObject* Py_CompileString(	char *str, char *filename, int start)
	('delattr',    "OO",   "r",     "PyObject_DelAttr"),
	('dir',        "O",    "O",     "PyObject_Dir"),
	('divmod',     "OO",   "O",     "PyNumber_Divmod"),
	#('eval',      "",     "",      ""),
	#('execfile',  "",     "",      ""),
	#('filter',    "",     "",      ""),
	('getattr',    "OO",   "O",     "PyObject_GetAttr"),
	('getattr3',   "OOO",  "O",     "__Pyx_GetAttr3",       "getattr"),
	('hasattr',    "OO",   "i",     "PyObject_HasAttr"),
	('hash',       "O",    "i",     "PyObject_Hash"),
	#('hex',       "",     "",      ""),
	#('id',        "",     "",      ""),
	#('input',     "",     "",      ""),
	('intern',     "s",    "O",     "PyString_InternFromString"),
	('isinstance', "OO",   "i",     "PyObject_IsInstance"),
	('issubclass', "OO",   "i",     "PyObject_IsSubclass"),
	('iter',       "O",    "O",     "PyObject_GetIter"),
	('len',        "O",    "Z",     "PyObject_Length"),
	#('map',       "",     "",      ""),
	#('max',       "",     "",      ""),
	#('min',       "",     "",      ""),
	#('oct',       "",     "",      ""),
	# Not worth doing open, when second argument would become mandatory
	#('open',       "ss",   "O",     "PyFile_FromString"),
	#('ord',       "",     "",      ""),
	('pow',        "OOO",  "O",     "PyNumber_Power"),
	#('range',     "",     "",      ""),
	#('raw_input', "",     "",      ""),
	#('reduce',    "",     "",      ""),
	('reload',     "O",    "O",     "PyImport_ReloadModule"),
	('repr',       "O",    "O",     "PyObject_Repr"),
	#('round',     "",     "",      ""),
	('setattr',    "OOO",  "r",     "PyObject_SetAttr"),
	#('sum',       "",     "",      ""),
	#('unichr',    "",     "",      ""),
	#('unicode',   "",     "",      ""),
	#('vars',      "",     "",      ""),
	#('zip',       "",     "",      ""),
	#  Can't do these easily until we have builtin type entries.
	#('typecheck',  "OO",   "i",     "PyObject_TypeCheck", False),
	#('issubtype',  "OO",   "i",     "PyType_IsSubtype",   False),
]

	# name,        args,   return,  C API func

dict_methods = [
	("clear",       "O",   "v",     "PyDict_Clear"),
	("copy",        "O",   "O",     "PyDict_Copy"),
	("items",       "O",   "O",     "PyDict_Items"),
	("keys",        "O",   "O",     "PyDict_Keys"),
	("values",      "O",   "O",     "PyDict_Values"),
	("merge",       "OOi", "r",     "PyDict_Merge"),
	("update",      "OO",  "r",     "PyDict_Update"),
	("merge_pairs", "OOi", "r",     "PyDict_MergeFromSeq2"),
]

list_methods = [
	("insert",     "OiO",  "r",     "PyList_Insert"),
	("append",     "OO",   "r",     "PyList_Append"),
	("sort",       "O",    "r",     "PyList_Sort"),
	("reverse",    "O",    "r",     "PyList_Reverse"),
	("as_tuple",   "O",    "O",     "PyList_AsTuple"),
]

slice_methods = [
	("indices",    "O",    "O",     "PySlice_Indices"),
]

slice_members = [
	# name,        type,  access
	("start",      "O",   "ro"),
	("stop",       "O",   "ro"),
	("step",       "O",   "ro"),
]

builtin_type_table = [
	# name,  objstruct,      typeobj,      methods,        members
#  bool - doing this as a function
#  buffer
#  classmethod
	("dict", "PyDictObject", "PyDict_Type", dict_methods),
#  enumerate
#  file
#  float
#  int
	("list", "PyListObject", "PyList_Type", list_methods),
#  long
#  object
#  property
	("slice", "PySliceObject", "PySlice_Type", slice_methods, slice_members),
#  staticmethod
#  super
#  str
#  tuple
#  type
#  xrange
]

# Builtin types
#  list

getattr3_utility_code = ["""
static PyObject *__Pyx_GetAttr3(PyObject *, PyObject *, PyObject *); /*proto*/
""","""
static PyObject *__Pyx_GetAttr3(PyObject *o, PyObject *n, PyObject *d) {
	PyObject *r = PyObject_GetAttr(o, n);
	if (!r) {
		if (!PyErr_ExceptionMatches(PyExc_AttributeError))
			goto bad;
		PyErr_Clear();
		r = d;
		Py_INCREF(d);
	}
	return r;
bad:
	return 0;
}
"""]

builtin_utility_code = {
	'getattr3': getattr3_utility_code,
}

builtin_scope = BuiltinScope()

def declare_builtin_func(name, args, ret, cname, py_equiv = "*"):
	sig = Signature(args, ret)
	type = sig.function_type()
	utility = builtin_utility_code.get(name)
	builtin_scope.declare_builtin_cfunction(name, type, cname, py_equiv, utility)

def declare_builtin_method(self_type, name, args, ret, cname):
	sig = Signature(args, ret)
	meth_type = sig.function_type(self_type)
	self_type.scope.declare_builtin_method(name, meth_type, cname)

member_visibilities = {"ro": 'readonly', "rw": 'public'}

def declare_builtin_member(self_type, name, typecode, rw, cname = None):
	member_type = Signature.format_map[typecode]
	visibility = member_visibilities[rw]
	self_type.scope.declare_builtin_var(name, member_type, cname, visibility)

def declare_builtin_type(name, objstruct, typeobj, methods, members = []):
	entry = builtin_scope.declare_builtin_class(name, objstruct, typeobj)
	type = entry.type
	for desc in methods:
		declare_builtin_method(type, *desc)
	for desc in members:
		declare_builtin_member(type, *desc)

def init_builtin_funcs():
	for desc in builtin_function_table:
		declare_builtin_func(*desc)

def init_builtin_types():
	for desc in builtin_type_table:
		declare_builtin_type(*desc)

def init_builtins():
	init_builtin_funcs()
	init_builtin_types()

init_builtins()
