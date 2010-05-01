#------------------------------------------------------------------------------
#
#   Pyrex - Operating system interface - Unix
#
#------------------------------------------------------------------------------

import os, sys
from Pyrex.Utils import replace_suffix, file_newer_than_file
from Pyrex.Compiler.Errors import PyrexError

version = "%s.%s" % sys.version_info[:2]
py_include_dirs = [
	"%s/include/python%s" % (sys.prefix, version)
]

class CCompilerError(PyrexError):
	pass

#------------------------------------------------------------------------------

class UnixSystem(object):

	verbose = 0
	gcc_pendantic = False
	gcc_no_long_long_warning = True    # Don't warn about use of long long
	gcc_warnings_are_errors = True
	gcc_all_warnings = True
	gcc_optimize = False

	compilers = ["gcc", "g++"]
	
	default_compiler_options = \
		"-g -c -fno-strict-aliasing -Wno-long-double -no-cpp-precomp " \
		"-mno-fused-madd -fno-common -dynamic " \
		.split()
	
	linkers = ["gcc", "g++"]
	
	default_linker_options = \
		"-shared" \
		.split()
	
	def __init__(self):
		self.compiler_options = self.default_compiler_options[:]
		self.linker_options = self.default_linker_options[:]
		if self.gcc_pendantic:
			self.compiler_options.append("-pedantic")
		if self.gcc_no_long_long_warning:
			self.compiler_options.append("-Wno-long-long")
		if self.gcc_warnings_are_errors:
			self.compiler_options.append("-Werror")
		if self.gcc_all_warnings:
			self.compiler_options.append("-Wall")
			self.compiler_options.append("-Wno-unused-function")
		if self.gcc_optimize:
			compiler_options.append("-O")

	def c_compile(self, c_file, verbose_flag = 0, cplus = 0, obj_suffix = ".o",
			use_timestamps = 0, options = None):
		#  Compile the given C source file to produce
		#  an object file. Returns the pathname of the
		#  resulting file.
		c_file = os.path.join(os.getcwd(), c_file)
		o_file = replace_suffix(c_file, obj_suffix)
		if use_timestamps and not file_newer_than_file(c_file, o_file):
			return
		include_dirs = []
		if options:
			include_dirs.extend(options.include_path)
		include_dirs.extend(py_include_dirs)
		include_options = ["-I%s" % dir for dir in include_dirs]
		compiler = self.compilers[bool(cplus)]
		args = [compiler] + self.compiler_options + include_options \
			+ [c_file, "-o", o_file]
		if verbose_flag or self.verbose:
			print " ".join(args)
		status = os.spawnvp(os.P_WAIT, compiler, args)
		if status <> 0:
			raise CCompilerError("C compiler returned status %s" % status)
		return o_file

	def c_link(self, obj_file, verbose_flag = 0, extra_objects = [], cplus = 0,
			use_timestamps = 0, options = None):
		return self.c_link_list([obj_file] + extra_objects, verbose_flag, cplus,
			use_timestamps, options)
	
	def c_link_list(self, obj_files, verbose_flag = 0, cplus = 0, 
		use_timestamps = 0, options = None):
		#  Link the given object files into a dynamically
		#  loadable extension file. Returns the pathname
		#  of the resulting file.
		in_file = obj_files[0]
		out_file = replace_suffix(in_file, ".so")
		if use_timestamps and not file_newer_than_file(in_file, out_file):
			return
		linker = self.linkers[bool(cplus)]
		args = [linker] + self.get_linker_options(options) + obj_files \
			+ self.get_libraries(options) + ["-o", out_file]
		if verbose_flag or self.verbose:
			print " ".join(args)
		status = os.spawnvp(os.P_WAIT, linker, args)
		if status <> 0:
			raise CCompilerError("Linker returned status %s" % status)
		return out_file

	def get_linker_options(self, options):
		return self.linker_options[:]

	def get_libraries(self, options):
		result = []
		if options:
			for library in options.libraries:
				result.append("-l" + library)
		return result
