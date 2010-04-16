#
#   Pyrex Top Level
#

import os, re, sys
if sys.version_info[:2] < (2, 3):
	print >>sys.stderr, "Sorry, Pyrex requires Python 2.3 or later"
	sys.exit(1)

import os
from time import time
import Builtin
import Code
import Errors
import Parsing
import Version
from Errors import PyrexError, CompileError, error
from Scanning import PyrexScanner
from Symtab import BuiltinScope, DefinitionScope, ImplementationScope
from Pyrex.Utils import set, replace_suffix, modification_time, \
	file_newer_than, castrate_file, map_suffix
from Filenames import cplus_suffix, pxd_suffixes, pyx_suffixes, \
	package_init_files, pyx_to_c_suffix

verbose = 0
debug_timestamps = 0

module_name_pattern = re.compile(
	r"[A-Za-z_][A-Za-z0-9_]*(\.[A-Za-z_][A-Za-z0-9_]*)*$")

class Context:
	#  This class encapsulates the context needed for compiling
	#  one or more Pyrex implementation files along with their
	#  associated and imported declaration files. It holds
	#  the root of the module import namespace and the list
	#  of directories to search for include files.
	#
	#  modules               {string : DefinitionScope}
	#  include_directories   [string]
	
	def __init__(self, include_directories):
		self.modules = {"__builtin__" : Builtin.builtin_scope}
		self.include_directories = include_directories
		
	def find_module(self, module_name, 
			relative_to = None, pos = None, need_pxd = 1):
		# Finds and returns the module scope corresponding to
		# the given relative or absolute module name. If this
		# is the first time the module has been requested, finds
		# the corresponding .pxd file and process it.
		# If relative_to is not None, it must be a module scope,
		# and the module will first be searched for relative to
		# that module, provided its name is not a dotted name.
		debug_find_module = 0
		if debug_find_module:
			print "Context.find_module: module_name =", module_name, \
				"relative_to =", relative_to, "pos =", pos, "need_pxd =", need_pxd
		scope = None
		pxd_pathname = None
		if "." not in module_name and relative_to:
			if debug_find_module:
				print "...trying relative import"
			scope = relative_to.lookup_submodule(module_name)
			if not scope:
				qualified_name = relative_to.qualify_name(module_name)
				pxd_pathname = self.find_pxd_file(qualified_name, pos)
				if pxd_pathname:
					scope = relative_to.find_submodule(module_name)
		if not scope:
			if debug_find_module:
				print "...trying absolute import"
			scope = self
			for name in module_name.split("."):
				scope = scope.find_submodule(name)
		if debug_find_module:
			print "...scope =", scope
		if not scope.pxd_file_loaded:
			if debug_find_module:
				print "...pxd not loaded"
			scope.pxd_file_loaded = 1
			if not pxd_pathname:
				if debug_find_module:
					print "...looking for pxd file"
				pxd_pathname = self.find_pxd_file(module_name, pos)
				if debug_find_module:
					print "......found ", pxd_pathname
				if not pxd_pathname and need_pxd:
					error(pos, "Cannot find .pxd file for module '%s'" % module_name)
			if pxd_pathname:
				try:
					if debug_find_module:
						print "Context.find_module: Parsing", pxd_pathname
					pxd_tree = self.parse(pxd_pathname, scope, pxd = 1)
					pxd_tree.analyse_declarations(scope)
				except CompileError:
					pass
		return scope
	
	def find_pxd_file(self, qualified_name, pos):
		#  Search include path for the .pxd file corresponding to the
		#  given fully-qualified module name.
		#  Will find either a dotted filename or a file in a
		#  package directory. If a source file position is given,
		#  the directory containing the source file is searched first
		#  for a dotted filename, and its containing package root
		#  directory is searched first for a non-dotted filename.
		return self.search_package_directories(qualified_name, pxd_suffixes, pos)
	
	def find_pyx_file(self, qualified_name, pos):
		#  Search include path for the .pyx file corresponding to the
		#  given fully-qualified module name, as for find_pxd_file().
		return self.search_package_directories(qualified_name, pyx_suffixes, pos)
	
	def search_package_directories(self, qualified_name, suffixes, pos):
		dotted_filenames = [qualified_name + suffix for suffix in suffixes]
		if pos:
			here = os.path.dirname(pos[0])
			for dotted_filename in dotted_filenames:
				path = os.path.join(here, dotted_filename)
				if os.path.exists(path):
					return path
		dirs = self.include_directories
		if pos:
			here = self.find_root_package_dir(pos[0])
			dirs = [here] + dirs
		names = qualified_name.split(".")
		package_names = names[:-1]
		module_name = names[-1]
		filenames = [module_name + suffix for suffix in suffixes]
		for root in dirs:
			for dotted_filename in dotted_filenames:
				path = os.path.join(root, dotted_filename)
				if os.path.exists(path):
					return path
			dir = self.descend_to_package_dir(root, package_names)
			if dir:
				for filename in filenames:
					path = os.path.join(dir, filename)
					if os.path.exists(path):
						return path
				for init_filename in package_init_files:
					path = os.path.join(dir, module_name, init_filename)
					if os.path.exists(path):
						return path
	
	def find_root_package_dir(self, file_path):
		#  Given the full pathname of a source file, find the directory
		#  containing the top-level package that it ultimately belongs to.
		dir = os.path.dirname(file_path)
		while 1:
			if not self.is_package_dir(dir):
				return dir
			parent = os.path.dirname(dir)
			if parent == dir:
				return dir
			dir = parent

	def descend_to_package_dir(self, root_dir, package_names):
		#  Starting from the given root directory, look for a nested
		#  succession of package directories. Returns the full pathname
		#  of the innermost one, or None.
		dir = root_dir
		for name in package_names:
			dir = os.path.join(dir, name)
			if not self.is_package_dir(dir):
				return
		return dir
	
	def is_package_dir(self, dir_path):
		#  Return true if the given directory is a package directory.
		for filename in package_init_files:
			path = os.path.join(dir_path, filename)
			if os.path.exists(path):
				return 1
	
	def find_include_file(self, filename, pos):
		# Search list of include directories for filename.
		# Reports an error and returns None if not found.
		path = self.search_include_directories(filename, pos)
		if not path:
			error(pos, "'%s' not found" % filename)
		return path
	
	def search_include_directories(self, filename, pos):
		# Search the list of include directories for the given
		# file name. If a source file position is given, first
		# searches the directory containing that file. Returns
		# None if not found, but does not report an error.
		dirs = self.include_directories
		if pos:
			here_dir = os.path.dirname(pos[0])
			dirs = [here_dir] + dirs
		for dir in dirs:
			path = os.path.join(dir, filename)
			if os.path.exists(path):
				return path
		return None

	def lookup_submodule(self, name):
		# Look up a top-level module. Returns None if not found.
		return self.modules.get(name, None)

	def find_submodule(self, name):
		# Find a top-level module, creating a new one if needed.
		scope = self.lookup_submodule(name)
		if not scope:
			scope = DefinitionScope(name, 
				parent_module = None, context = self)
			self.modules[name] = scope
		return scope

	def parse(self, source_filename, scope, pxd):
		# Parse the given source file and return a parse tree.
		f = open(source_filename, "rU")
		s = PyrexScanner(f, source_filename, scope = scope, context = self)
		try:
			tree = Parsing.p_module(s, pxd)
		finally:
			f.close()
		if Errors.num_errors > 0:
			raise CompileError
		return tree

	def extract_module_name(self, path):
		#  Find fully_qualified module name from the full pathname
		#  of a source file.
		dir, filename = os.path.split(path)
		module_name, _ = os.path.splitext(filename)
		if "." not in module_name:
			if module_name == "__init__":
				dir, module_name = os.path.split(dir)
			names = [module_name]
			while self.is_package_dir(dir):
				parent, package_name = os.path.split(dir)
				if parent == dir:
					break
				names.insert(0, package_name)
				dir = parent
			module_name = ".".join(names)
		if not module_name_pattern.match(module_name):
			raise CompileError((path, 0, 0),
				"'%s' is not a valid module name" % module_name)
		return module_name
	
	def dep_file_out_of_date(self, source_path):
		dep_path = replace_suffix(source_path, ".dep")
		if not os.path.exists(dep_path):
			return 1
		dep_time = modification_time(dep_path)
		return file_newer_than(source_path, dep_time)
	
	def c_file_out_of_date(self, source_path):
		if debug_timestamps:
			print "Checking whether", source_path, "is out of date"
		c_path = map_suffix(source_path, pyx_to_c_suffix, ".c")
		if not os.path.exists(c_path):
			if debug_timestamps:
				print "...yes, c file doesn't exist"
			return 1
		c_time = modification_time(c_path)
		if file_newer_than(source_path, c_time):
			if debug_timestamps:
				print "...yes, newer than c file"
			return 1
		pos = [source_path]
		module_name = self.extract_module_name(source_path)
		pxd_path = self.find_pxd_file(module_name, pos)
		if pxd_path and file_newer_than(pxd_path, c_time):
			if debug_timestamps:
				print "...yes, pxd file newer than c file"
			return 1
		dep_path = replace_suffix(source_path, ".dep")
		if not os.path.exists(dep_path):
			if debug_timestamps:
				print "...yes, dep file does not exist"
			return 1
		for kind, name in self.read_dependency_file(source_path):
			if kind == "cimport":
				dep_path = self.find_pxd_file(name, pos)
			elif kind == "include":
				dep_path = self.search_include_directories(name, pos)
			else:
				continue
			if dep_path and file_newer_than(dep_path, c_time):
				if debug_timestamps:
					print "...yes,", dep_path, "newer than c file"
				return 1
		if debug_timestamps:
			print "...no"
	
	def find_cimported_module_names(self, source_path):
		for kind, name in self.read_dependency_file(source_path):
			if kind == "cimport":
				yield name
	
	def read_dependency_file(self, source_path):
		dep_path = replace_suffix(source_path, ".dep")
		if os.path.exists(dep_path):
			f = open(dep_path, "rU")
			for line in f.readlines():
				chunks = line.strip().split(" ", 1)
				if len(chunks) == 2:
					yield chunks
			f.close()

	def compile(self, source, options = None):
		# Compile a Pyrex implementation file in this context
		# and return a CompilationResult.
		if not options:
			options = default_options
		result = CompilationResult()
		cwd = os.getcwd()
		source = os.path.join(cwd, source)
		if options.use_listing_file:
			result.listing_file = replace_suffix(source, ".lis")
			Errors.open_listing_file(result.listing_file,
				echo_to_stderr = options.errors_to_stderr)
		else:
			Errors.open_listing_file(None)
		if options.output_file:
			result.c_file = os.path.join(cwd, options.output_file)
		else:
			if options.cplus:
				result.c_file = replace_suffix(source, cplus_suffix)
			else:
				result.c_file = map_suffix(source, pyx_to_c_suffix, ".c")
		module_name = self.extract_module_name(source)
		initial_pos = (source, 1, 0)
		def_scope = self.find_module(module_name, pos = initial_pos, need_pxd = 0)
		imp_scope = ImplementationScope(def_scope)
		errors_occurred = False
		try:
			tree = self.parse(source, imp_scope, pxd = 0)
			tree.process_implementation(imp_scope, options, result)
		except CompileError:
			errors_occurred = True
		Errors.close_listing_file()
		result.num_errors = Errors.num_errors
		if result.num_errors > 0:
			errors_occurred = True
		if errors_occurred and result.c_file:
			try:
				st = os.stat(source)
				castrate_file(result.c_file, st)
			except EnvironmentError:
				pass
			result.c_file = None
		if result.c_file and not options.c_only and c_compile:
			result.object_file = c_compile(result.c_file,
				verbose_flag = options.show_version,
				cplus = options.cplus)
			if not options.obj_only and c_link:
				result.extension_file = c_link(result.object_file,
					extra_objects = options.objects,
					verbose_flag = options.show_version,
					cplus = options.cplus)
		return result

#------------------------------------------------------------------------
#
#  Main Python entry points
#
#------------------------------------------------------------------------

class CompilationOptions:
	"""
	Options to the Pyrex compiler:
	
	show_version      boolean   Display version number
	use_listing_file  boolean   Generate a .lis file
	errors_to_stderr  boolean   Echo errors to stderr when using .lis
	include_path      [string]  Directories to search for include files
	output_file       string    Name of generated .c file
	generate_pxi      boolean   Generate .pxi file for public declarations
	recursive         boolean   Recursively find and compile dependencies
	timestamps        boolean   Only compile changed source files. If None,
	                            defaults to true when recursive is true.
	verbose           boolean   Always print source names being compiled
	quiet             boolean   Don't print source names in recursive mode
	
	Following options are experimental and only used on MacOSX:
	
	c_only            boolean   Stop after generating C file (default)
	obj_only          boolean   Stop after compiling to .o file
	objects           [string]  Extra .o files to link with
	cplus             boolean   Compile as c++ code
	"""
	
	def __init__(self, defaults = None, c_compile = 0, c_link = 0, **kw):
		self.include_path = []
		self.objects = []
		if defaults:
			if isinstance(defaults, CompilationOptions):
				defaults = defaults.__dict__
		else:
			defaults = default_options
		self.__dict__.update(defaults)
		self.__dict__.update(kw)
		if c_compile:
			self.c_only = 0
		if c_link:
			self.obj_only = 0


class CompilationResult:
	"""
	Results from the Pyrex compiler:
	
	c_file           string or None   The generated C source file
	h_file           string or None   The generated C header file
	i_file           string or None   The generated .pxi file
	api_file         string or None   The generated C API .h file
	listing_file     string or None   File of error messages
	object_file      string or None   Result of compiling the C file
	extension_file   string or None   Result of linking the object file
	num_errors       integer          Number of compilation errors
	"""
	
	def __init__(self):
		self.c_file = None
		self.h_file = None
		self.i_file = None
		self.api_file = None
		self.listing_file = None
		self.object_file = None
		self.extension_file = None


class CompilationResultSet(dict):
	"""
	Results from compiling multiple Pyrex source files. A mapping
	from source file paths to CompilationResult instances. Also
	has the following attributes:
	
	num_errors   integer   Total number of compilation errors
	"""
	
	num_errors = 0

	def add(self, source, result):
		self[source] = result
		self.num_errors += result.num_errors


def compile_single(source, options):
	"""
	compile_single(source, options)
	
	Compile the given Pyrex implementation file and return a CompilationResult.
	Always compiles a single file; does not perform timestamp checking or
	recursion.
	"""
	context = Context(options.include_path)
	return context.compile(source, options)

def compile_multiple(sources, options):
	"""
	compile_multiple(sources, options)
	
	Compiles the given sequence of Pyrex implementation files and returns
	a CompilationResultSet. Performs timestamp checking and/or recursion
	if these are specified in the options.
	"""
	sources = [os.path.abspath(source) for source in sources]
	processed = set()
	results = CompilationResultSet()
	context = Context(options.include_path)
	recursive = options.recursive
	timestamps = options.timestamps
	if timestamps is None:
		timestamps = recursive
	verbose = options.verbose or ((recursive or timestamps) and not options.quiet)
	for source in sources:
		if source not in processed:
			if not timestamps or context.c_file_out_of_date(source):
				if verbose:
					print >>sys.stderr, "Compiling", source
				result = context.compile(source, options)
				results.add(source, result)
			processed.add(source)
			if recursive:
				for module_name in context.find_cimported_module_names(source):
					path = context.find_pyx_file(module_name, [source])
					if path:
						sources.append(path)
					else:
						print >>sys.stderr, \
							"Cannot find .pyx file for cimported module '%s'" % module_name
	return results

def compile(source, options = None, c_compile = 0, c_link = 0, **kwds):
	"""
	compile(source [, options], [, <option> = <value>]...)
	
	Compile one or more Pyrex implementation files, with optional timestamp
	checking and recursing on dependecies. The source argument may be a string
	or a sequence of strings. If it is a string and no recursion or timestamp
	checking is requested, a CompilationResult is returned, otherwise a
	CompilationResultSet is returned.
	"""
	options = CompilationOptions(defaults = options, c_compile = c_compile,
		c_link = c_link, **kwds)
	if isinstance(source, basestring) and not options.timestamps \
			and not options.recursive:
		return compile_single(source, options)
	else:
		return compile_multiple(source, options)

#------------------------------------------------------------------------
#
#  Main command-line entry point
#
#------------------------------------------------------------------------

def main(command_line = 0):
	args = sys.argv[1:]
	any_failures = 0
	if command_line:
		from CmdLine import parse_command_line
		options, sources = parse_command_line(args)
	else:
		options = CompilationOptions(default_options)
		sources = args
	if options.show_version:
		print >>sys.stderr, "Pyrex version %s" % Version.version
	try:
		result = compile(sources, options)
		if result.num_errors > 0:
			any_failures = 1
	except EnvironmentError, e:
		print >>sys.stderr, e
		any_failures = 1
	if any_failures:
		sys.exit(1)

#------------------------------------------------------------------------
#
#  Set the default options depending on the platform
#
#------------------------------------------------------------------------

default_options = dict(
	show_version = 0,
	use_listing_file = 0,
	errors_to_stderr = 1,
	c_only = 1,
	obj_only = 1,
	cplus = 0,
	output_file = None,
	generate_pxi = 0,
	recursive = 0,
	timestamps = None,
	verbose = 0,
	quiet = 0)
	
if sys.platform == "mac":
	from Pyrex.Mac.MacSystem import c_compile, c_link, CCompilerError
	default_options['use_listing_file'] = 1
elif sys.platform == "darwin":
	from Pyrex.Mac.DarwinSystem import c_compile, c_link, CCompilerError
else:
	c_compile = None
	c_link = None


