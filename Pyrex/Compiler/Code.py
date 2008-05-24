##########################################################################
#
#   Pyrex - Code output module
#
##########################################################################

import os, re
import Naming
from Pyrex.Utils import open_new_file
from PyrexTypes import py_object_type, c_char_array_type, typecast

identifier_pattern = re.compile(r"[A-Za-z_][A-Za-z0-9_]*$")
max_intern_length = 30

class CCodeWriter:
	# f                file            output file
	# level            int             indentation level
	# bol              bool            beginning of line?
	# marker           string          comment to emit before next line
	
	def __init__(self, f):
		#self.f = open_new_file(outfile_name)
		self.f = f
		self.level = 0
		self.bol = 1
		self.marker = None
	
	def putln(self, code = ""):
		if self.marker and self.bol:
			self.emit_marker()
		if code:
			self.put(code)
		self.f.write("\n");
		self.bol = 1
	
	def emit_marker(self):
		self.f.write("\n");
		self.indent()
		self.f.write("/* %s */\n" % self.marker)
		self.marker = None

	def put(self, code):
		dl = code.count("{") - code.count("}")
		if dl < 0:
			self.level += dl
		if self.bol:
			self.indent()
		self.f.write(code)
		self.bol = 0
		if dl > 0:
			self.level += dl
	
	def increase_indent(self):
		self.level = self.level + 1
	
	def decrease_indent(self):
		self.level = self.level - 1
	
	def begin_block(self):
		self.putln("{")
		self.increase_indent()
	
	def end_block(self):
		self.decrease_indent()
		self.putln("}")
	
	def indent(self):
		self.f.write("  " * self.level)
	
	def mark_pos(self, pos):
		file, line, col = pos
		self.marker = '"%s":%s' % (file, line)

	def put_var_declarations(self, entries, static = 0, dll_linkage = None,
			definition = True):
		for entry in entries:
			if not entry.in_cinclude:
				self.put_var_declaration(entry, static, dll_linkage, definition)
	
	def put_var_declaration(self, entry, static = 0, dll_linkage = None,
			definition = True):
		#print "Code.put_var_declaration:", entry.name, repr(entry.type) ###
		visibility = entry.visibility
		if visibility == 'private' and not definition:
			#print "...private and not definition, skipping" ###
			return
		if not entry.used and visibility == "private":
			#print "not used and private, skipping" ###
			return
		storage_class = ""
		if visibility == 'extern':
			storage_class = Naming.extern_c_macro
		elif visibility == 'public':
			if not definition:
				storage_class = Naming.extern_c_macro
		elif visibility == 'private':
			if static:
				storage_class = "static"
		if storage_class:
			self.put("%s " % storage_class)
		if visibility <> 'public':
			dll_linkage = None
		self.put(entry.type.declaration_code(entry.cname,
			dll_linkage = dll_linkage))
		if entry.init is not None:
			self.put(" = %s" % entry.type.literal_code(entry.init))
		self.putln(";")
	
	def entry_as_pyobject(self, entry):
		type = entry.type
		if (not entry.is_self_arg and not entry.type.is_complete()) \
			or (entry.type.is_extension_type and entry.type.base_type):
			return "(PyObject *)" + entry.cname
		else:
			return entry.cname
	
	def as_pyobject(self, cname, type):
		if type:
			return typecast(py_object_type, type, cname)
		else:
			return cname
	
	def put_incref(self, cname, type = None):
		self.putln("Py_INCREF(%s);" % self.as_pyobject(cname, type))
	
	def put_decref(self, cname, type = None):
		self.putln("Py_DECREF(%s);" % self.as_pyobject(cname, type))
	
	def put_var_incref(self, entry):
		if entry.type.is_pyobject:
			self.putln("Py_INCREF(%s);" % self.entry_as_pyobject(entry))
	
	def put_decref_clear(self, cname, type = None):
		self.putln("Py_DECREF(%s); %s = 0;" % (
			self.as_pyobject(cname, type), cname)) # What was wrong with this?
			#typecast(py_object_type, type, cname), cname))
	
	def put_xdecref(self, cname, type):
		self.putln("Py_XDECREF(%s);" % self.as_pyobject(cname, type))
	
	def put_xdecref_clear(self, cname, type):
		self.putln("Py_XDECREF(%s); %s = 0;" % (
			self.as_pyobject(cname, type), cname))

	def put_var_decref(self, entry):
		if entry.type.is_pyobject:
			self.putln("Py_DECREF(%s);" % self.entry_as_pyobject(entry))
	
	def put_var_decref_clear(self, entry):
		if entry.type.is_pyobject:
			self.putln("Py_DECREF(%s); %s = 0;" % (
				self.entry_as_pyobject(entry), entry.cname))
	
	def put_var_xdecref(self, entry):
		if entry.type.is_pyobject:
			self.putln("Py_XDECREF(%s);" % self.entry_as_pyobject(entry))
	
	def put_var_xdecref_clear(self, entry):
		if entry.type.is_pyobject:
			self.putln("Py_XDECREF(%s); %s = 0;" % (
				self.entry_as_pyobject(entry), entry.cname))
	
	def put_var_decrefs(self, entries, used_only = 0):
		for entry in entries:
			if not used_only or entry.used:
				if entry.xdecref_cleanup:
					self.put_var_xdecref(entry)
				else:
					self.put_var_decref(entry)
	
	def put_var_xdecrefs(self, entries):
		for entry in entries:
			self.put_var_xdecref(entry)
	
	def put_var_xdecrefs_clear(self, entries):
		for entry in entries:
			self.put_var_xdecref_clear(entry)
	
	def put_init_to_py_none(self, cname, type):
		py_none = typecast(type, py_object_type, "Py_None")
		self.putln("%s = %s; Py_INCREF(Py_None);" % (cname, py_none))
	
	def put_init_var_to_py_none(self, entry, template = "%s"):
		code = template % entry.cname
		self.put_init_to_py_none(code, entry.type)

	def put_pymethoddef(self, entry, term):
		if entry.doc:
			doc_code = entry.doc_cname
		else:
			doc_code = 0
		self.putln(
			'{"%s", (PyCFunction)%s, METH_VARARGS|METH_KEYWORDS, %s}%s' % (
				entry.name, 
				entry.func_cname, 
				doc_code,
				term))
	
	def put_h_guard(self, guard):
		self.putln("#ifndef %s" % guard)
		self.putln("#define %s" % guard)
	
#--------------------------------------------------------------------------

class MainCCodeWriter(CCodeWriter):
	#  Code writer for executable C code.
	#
	#  global_state     GlobalCodeState    module-wide state
	#  return_label     string             function return point label
	#  error_label      string             error catch point label
	#  continue_label   string             loop continue point label
	#  break_label      string             loop break point label
	#  label_counter    integer            counter for naming labels
	#  in_try_finally   boolean            inside try of try...finally
	#  exc_vars         (string * 3)       exception vars for reraise, or None

	in_try_finally = 0
	
	def __init__(self, f, base = None):
		CCodeWriter.__init__(self, f)
		if base:
			self.global_state = base.global_state
		else:
			self.global_state = GlobalCodeState()
		self.label_counter = 1
		self.error_label = None
		self.exc_vars = None

	def init_labels(self):
		self.label_counter = 0
		self.labels_used = {}
		self.return_label = self.new_label()
		self.new_error_label()
		self.continue_label = None
		self.break_label = None
	
	def new_label(self):
		n = self.label_counter
		self.label_counter = n + 1
		return "%s%d" % (Naming.label_prefix, n)
	
	def new_error_label(self):
		old_err_lbl = self.error_label
		self.error_label = self.new_label()
		return old_err_lbl
	
	def get_loop_labels(self):
		return (
			self.continue_label,
			self.break_label)
	
	def set_loop_labels(self, labels):
		(self.continue_label,
		 self.break_label) = labels
	
	def new_loop_labels(self):
		old_labels = self.get_loop_labels()
		self.set_loop_labels(
			(self.new_label(), 
			 self.new_label()))
		return old_labels
	
	def get_all_labels(self):
		return (
			self.continue_label,
			self.break_label,
			self.return_label,
			self.error_label)

	def set_all_labels(self, labels):
		(self.continue_label,
		 self.break_label,
		 self.return_label,
		 self.error_label) = labels

	def all_new_labels(self):
		old_labels = self.get_all_labels()
		new_labels = []
		for old_label in old_labels:
			if old_label:
				new_labels.append(self.new_label())
			else:
				new_labels.append(old_label)
		self.set_all_labels(new_labels)
		return old_labels
	
	def use_label(self, lbl):
		self.labels_used[lbl] = 1

	def put_label(self, lbl):
		if lbl in self.labels_used:
			self.putln("%s:;" % lbl)
	
	def put_goto(self, lbl):
		self.use_label(lbl)
		self.putln("goto %s;" % lbl)
	
	def error_goto(self, pos):
		lbl = self.error_label
		self.use_label(lbl)
		return "{%s = %s[%s]; %s = %s; goto %s;}" % (
			Naming.filename_cname,
			Naming.filetable_cname,
			self.lookup_filename(pos[0]),
			Naming.lineno_cname,
			pos[1],
			lbl)
		
	def lookup_filename(self, filename):
		return self.global_state.lookup_filename(filename)

	def use_utility_code(self, uc):
		self.global_state.use_utility_code(uc)

	def get_string_const(self, text):
		#  Get C name for a string constant, adding a new one
		#  if necessary.
		return self.global_state.get_string_const(text).cname
	
	def new_const(self, type):
		#  Get C name for a new precalculated value.
		return self.global_state.new_const(type).cname
	
	def get_py_string_const(self, text):
		#  Get C name for a Python string constant, adding a new one
		#  if necessary. If the string is name-like, it will be interned.
		return self.global_state.get_py_string_const(text).cname

	def intern(self, name):
		return self.get_py_string_const(name)

#--------------------------------------------------------------------------

class StringConst:
	#  Info held by GlobalCodeState about a string constant.
	#
	#  cname       string
	#  text        string
	#  py_const    Const     Corresponding Python string

	py_const = None

	def __init__(self, cname, text):
		self.cname = cname
		self.text = text

#--------------------------------------------------------------------------

class Const:
	#  Info held by GlobalCodeState about a precalculated value.
	#
	#  cname      string
	#  type       PyrexType
	#  intern     boolean      for Python strings
	
	intern = 0

	def __init__(self, cname, type):
		self.cname = cname
		self.type = type

#--------------------------------------------------------------------------

class GlobalCodeState:
	#  State pertaining to code generation for a whole module.
	#
	#  filename_table   {string : int}     for finding filename table indexes
	#  filename_list    [string]           filenames in filename table order
	#  utility_code     {int : int}        id to utility_list index
	#  utility_list     list               utility code used
	#  const_counter    int                for generating const names
	#  string_index     {string : String}  string constant index
	#  string_consts    [StringConst]      all string constants
	#  other_consts     [Const]            other precalculated values

	def __init__(self):
		self.filename_table = {}
		self.filename_list = []
		self.utility_code = {}
		self.utility_list = []
		self.const_counter = 1
		self.string_index = {}
		self.string_consts = []
		self.other_consts = []

	def lookup_filename(self, filename):
		try:
			index = self.filename_table[filename]
		except KeyError:
			index = len(self.filename_list)
			self.filename_list.append(filename)
			self.filename_table[filename] = index
		return index

	def generate_filename_table(self, code):
		code.putln("")
		code.putln("static char *%s[] = {" % Naming.filenames_cname)
		if self.filename_list:
			for filename in self.filename_list:
				filename = os.path.basename(filename)
				escaped_filename = filename.replace("\\", "\\\\").replace('"', r'\"')
				code.putln('"%s",' % 
					escaped_filename)
		else:
			# Some C compilers don't like an empty array
			code.putln("0")
		code.putln("};")

	def use_utility_code(self, uc):
		i = id(uc)
		if i not in self.utility_code:
			self.utility_code[i] = len(self.utility_list)
			self.utility_list.append(uc)
	
	def generate_utility_functions(self, code):
		code.putln("")
		code.putln("/* Runtime support code */")
		code.putln("")
		code.putln("static void %s(void) {" % Naming.fileinit_cname)
		code.putln("%s = %s;" % 
			(Naming.filetable_cname, Naming.filenames_cname))
		code.putln("}")
		for utility_code in self.utility_list:
			code.h.put(utility_code[0])
			code.put(utility_code[1])
	
	def new_const_name(self):
		#  Create a new globally-unique name for a constant.
		name = "%s%s" % (Naming.const_prefix, self.const_counter)
		self.const_counter += 1
		return name
	
	def new_string_const(self, text):
		#  Add a new C string constant.
		c = StringConst(self.new_const_name(), text)
		self.string_consts.append(c)
		self.string_index[text] = c
		return c
	
	def new_const(self, type, cname = None):
		if not cname:
			cname = self.new_const_name()
		c = Const(cname, type)
		self.other_consts.append(c)
		return c
	
	def new_py_const(self, cname = None, intern = 0):
		#  Add a new Python constant.
		c = self.new_const(py_object_type, cname)
		if intern:
			c.intern = 1
		return c
	
	def get_string_const(self, text):
		#  Get a C string constant, adding a new one if necessary.
		c = self.string_index.get(text)
		if not c:
			c = self.new_string_const(text)
		return c
	
	def get_py_string_const(self, text):
		#  Get a Python string constant, adding a new one if necessary.
		#  If the string is name-like, it will be interned.
		s = self.get_string_const(text)
		if not s.py_const:
			intern = len(text) <= max_intern_length and identifier_pattern.match(text)
			if intern:
				cname = Naming.interned_prefix + text
			else:
				cname = s.cname + "p"
			s.py_const = self.new_py_const(cname, intern)
		return s.py_const

	def generate_const_declarations(self, code):
		self.generate_string_const_declarations(code)
		self.generate_other_const_declarations(code)
		self.generate_stringtab(code)
	
	def generate_string_const_declarations(self, code):
		code.putln("")
		for c in self.string_consts:
			code.putln('static char %s[] = "%s";' % (c.cname, c.text))
	
	def generate_other_const_declarations(self, code):
		interned = []
		uninterned = []
		for c in self.other_consts:
			if c.intern:
				interned.append(c)
			else:
				uninterned.append(c)
		interned.sort(lambda c1, c2: cmp(c1.cname, c2.cname))
		def put_consts(consts):
			code.putln("")
			for c in consts:
				decl = c.type.declaration_code(c.cname)
				code.putln("static %s;" % decl)
		put_consts(interned)
		put_consts(uninterned)
	
	def generate_stringtab(self, code):
		interned = []
		uninterned = []
		for s in self.string_consts:
			p = s.py_const
			if p:
				if p.intern:
					interned.append(s)
				else:
					uninterned.append(s)
		interned.sort(lambda c1, c2: cmp(c1.py_const.cname, c2.py_const.cname))
		def put_stringtab(consts, intern):
			for c in consts:
				cname = c.cname
				code.putln("{&%s, %d, %s, sizeof(%s)}," % (
					c.py_const.cname, intern, cname, cname))
		code.putln("")
		code.putln("static __Pyx_StringTabEntry %s[] = {" % Naming.stringtab_cname)
		put_stringtab(interned, 1)
		put_stringtab(uninterned, 0)
		code.putln("{0, 0, 0, 0}")
		code.putln("};")

#--------------------------------------------------------------------------

class PyrexCodeWriter:
	# f                file      output file
	# level            int       indentation level

	def __init__(self, outfile_name):
		self.f = open_new_file(outfile_name)
		self.level = 0
	
	def putln(self, code):
		self.f.write("%s%s\n" % (" " * self.level, code))
	
	def indent(self):
		self.level += 1
	
	def dedent(self):
		self.level -= 1

