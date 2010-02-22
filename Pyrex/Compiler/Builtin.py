#
#   Pyrex - Builtin Definitions
#

from Symtab import BuiltinScope
from TypeSlots import Signature
from PyrexTypes import py_type_type

builtin_constant_table = [
	# name,         type/ctype,  C API name
	("buffer",      "t",         "(&PyBuffer_Type)"),
	("enumerate",   "t",         "(&PyEnum_Type)"),
	("file",        "t",         "(&PyFile_Type)"),
	("float",       "t",         "(&PyFloat_Type)"),
	("int",         "t",         "(&PyInt_Type)"),
	("long",        "t",         "(&PyLong_Type)"),
	("open",        "t",         "(&PyFile_Type)"),
	("property",    "t",         "(&PyProperty_Type)"),
	("str",         "t",         "(&PyString_Type)"),
	("tuple",       "t",         "(&PyTuple_Type)"),
	("xrange",      "t",         "(&PyRange_Type)"),
	
	("True",        "O",         "Py_True"),
	("False",       "O",         "Py_False"),
	("Ellipsis",    "O",         "Py_Ellipsis"),

	("Exception",             "t/O", "PyExc_Exception"),
	("StopIteration",         "t/O", "PyExc_StopIteration"),
	("StandardError",         "t/O", "PyExc_StandardError"),
	("ArithmeticError",       "t/O", "PyExc_ArithmeticError"),
	("LookupError",           "t/O", "PyExc_LookupError"),

	("AssertionError",        "t/O", "PyExc_AssertionError"),
	("EOFError",              "t/O", "PyExc_EOFError"),
	("FloatingPointError",    "t/O", "PyExc_FloatingPointError"),
	("EnvironmentError",      "t/O", "PyExc_EnvironmentError"),
	("IOError",               "t/O", "PyExc_IOError"),
	("OSError",               "t/O", "PyExc_OSError"),
	("ImportError",           "t/O", "PyExc_ImportError"),
	("IndexError",            "t/O", "PyExc_IndexError"),
	("KeyError",              "t/O", "PyExc_KeyError"),
	("KeyboardInterrupt",     "t/O", "PyExc_KeyboardInterrupt"),
	("MemoryError",           "t/O", "PyExc_MemoryError"),
	("NameError",             "t/O", "PyExc_NameError"),
	("OverflowError",         "t/O", "PyExc_OverflowError"),
	("RuntimeError",          "t/O", "PyExc_RuntimeError"),
	("NotImplementedError",   "t/O", "PyExc_NotImplementedError"),
	("SyntaxError",           "t/O", "PyExc_SyntaxError"),
	("IndentationError",      "t/O", "PyExc_IndentationError"),
	("TabError",              "t/O", "PyExc_TabError"),
	("ReferenceError",        "t/O", "PyExc_ReferenceError"),
	("SystemError",           "t/O", "PyExc_SystemError"),
	("SystemExit",            "t/O", "PyExc_SystemExit"),
	("TypeError",             "t/O", "PyExc_TypeError"),
	("UnboundLocalError",     "t/O", "PyExc_UnboundLocalError"),
	("UnicodeError",          "t/O", "PyExc_UnicodeError"),
	("UnicodeEncodeError",    "t/O", "PyExc_UnicodeEncodeError"),
	("UnicodeDecodeError",    "t/O", "PyExc_UnicodeDecodeError"),
	("UnicodeTranslateError", "t/O", "PyExc_UnicodeTranslateError"),
	("ValueError",            "t/O", "PyExc_ValueError"),
	("ZeroDivisionError",     "t/O", "PyExc_ZeroDivisionError"),
	# Not including these by default because they are platform-specific
	#("WindowsError",          "t/O", "PyExc_WindowsError"),
	#("VMSError",              "t/O", "PyExc_VMSError"),

	("MemoryErrorInst",       "t/O", "PyExc_MemoryErrorInst"),

	("Warning",                   "t/O", "PyExc_Warning"),
	("UserWarning",               "t/O", "PyExc_UserWarning"),
	("DeprecationWarning",        "t/O", "PyExc_DeprecationWarning"),
	("PendingDeprecationWarning", "t/O", "PyExc_PendingDeprecationWarning"),
	("SyntaxWarning",             "t/O", "PyExc_SyntaxWarning"),
	("OverflowWarning",           "t/O", "PyExc_OverflowWarning"),
	("RuntimeWarning",            "t/O", "PyExc_RuntimeWarning"),
	("FutureWarning",             "t/O", "PyExc_FutureWarning"),

]

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
	('typecheck',  "Ot",   "b",     "PyObject_TypeCheck", False),
	('issubtype',  "tt",   "b",     "PyType_IsSubtype",   False),
]

dict_methods = [
	# name,         args,   return,  C API func
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
	# name,        args,   return,  C API func
	("insert",     "OiO",  "r",     "PyList_Insert"),
	("append",     "OO",   "r",     "PyList_Append"),
	("iappend",     "OO",   "i",     "PyList_Append"),
	("sort",       "O",    "r",     "PyList_Sort"),
	("reverse",    "O",    "r",     "PyList_Reverse"),
	("as_tuple",   "O",    "O",     "PyList_AsTuple"),
]

slice_methods = [
	# name,        args,   return,  C API func
	("indices",    "O",    "O",     "PySlice_Indices"),
]

slice_members = [
	# name,        type
	("start",      "O"),
	("stop",       "O"),
	("step",       "O"),
]

builtin_type_table = [
	# name,  objstruct,      typeobj,      methods,        members
#  bool - function
#  buffer - constant
#  classmethod
	("dict", "PyDictObject", "PyDict_Type", dict_methods),
#  enumerate - constant
#  file - constant
#  float - constant
#  int - constant
	("list", "PyListObject", "PyList_Type", list_methods),
#  long - constant
#  object
#  property - constant
	("slice", "PySliceObject", "PySlice_Type", slice_methods, slice_members),
#  staticmethod
#  super
#  str - constant
#  tuple - constant
	("type",  "PyTypeObject",  "PyType_Type", []),
#  xrange - constant
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

def type_and_ctype(typecode, c_typecode = None):
	type = Signature.format_map[typecode]
	if c_typecode:
		ctype = Signature.format_map[c_typecode]
	else:
		ctype = None
	return type, ctype

def declare_builtin_constant(name, typecode, cname):
	type, ctype = type_and_ctype(*typecode.split("/"))
	builtin_scope.declare_builtin_constant(name, type, cname, ctype)

def declare_builtin_func(name, args, ret, cname, py_equiv = "*"):
	sig = Signature(args, ret)
	type = sig.function_type()
	utility = builtin_utility_code.get(name)
	builtin_scope.declare_builtin_cfunction(name, type, cname, py_equiv, utility)

def declare_builtin_method(self_type, name, args, ret, cname):
	sig = Signature(args, ret)
	meth_type = sig.function_type(self_type)
	self_type.scope.declare_builtin_method(name, meth_type, cname)

def declare_builtin_member(self_type, name, typecode, cname = None):
	member_type = Signature.format_map[typecode]
	self_type.scope.declare_builtin_var(name, member_type, cname)

def declare_builtin_type(name, objstruct, typeobj, methods, members = []):
	entry = builtin_scope.declare_builtin_class(name, objstruct, typeobj)
	type = entry.type
	for desc in methods:
		declare_builtin_method(type, *desc)
	for desc in members:
		declare_builtin_member(type, *desc)

def init_builtin_constants():
	for desc in builtin_constant_table:
		declare_builtin_constant(*desc)

def init_builtin_funcs():
	for desc in builtin_function_table:
		declare_builtin_func(*desc)

def init_builtin_types():
	for desc in builtin_type_table:
		declare_builtin_type(*desc)
	py_type_type.define(builtin_scope.find_type("type"))

def init_builtins():
	init_builtin_constants()
	init_builtin_funcs()
	init_builtin_types()

init_builtins()
