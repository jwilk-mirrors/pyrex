#------------------------------------------------------------------------------
#
#   Pyrex - Darwin system interface
#
#------------------------------------------------------------------------------

import os
from Pyrex.Unix.UnixSystems import UnixSystem, CCompilerError

#version_string = "%s.%s" % sys.version_info[:2]
#
#py_include_dirs = [
#	"/Library/Frameworks/Python.framework/Versions/%s/Headers" % version_string
#]

class DarwinSystem(UnixSystem):

	default_linker_options = \
		"-Wl,-F.,-w -bundle -undefined dynamic_lookup" \
		.split()

#def c_compile(c_file, verbose_flag = 0, cplus = 0, obj_suffix = ".o",
#		use_timestamps = 0, options = None):
#	#  Compile the given C source file to produce
#	#  an object file. Returns the pathname of the
#	#  resulting file.
#	c_file = os.path.join(os.getcwd(), c_file)
#	o_file = replace_suffix(c_file, obj_suffix)
#	if use_timestamps and not file_newer_than_file(c_file, o_file):
#		return
#	include_dirs = []
#	if options:
#		include_dirs.extend(options.include_path)
#	include_dirs.extend(py_include_dirs)
#	include_options = []
#	for dir in include_dirs:
#		include_options.append("-I%s" % dir)
#	compiler = compilers[bool(cplus)]
#	args = [compiler] + compiler_options + include_options + [c_file, "-o", o_file]
#	if verbose_flag or verbose:
#		print " ".join(args)
#	#print compiler, args ###
#	status = os.spawnvp(os.P_WAIT, compiler, args)
#	if status <> 0:
#		raise CCompilerError("C compiler returned status %s" % status)
#	return o_file

#def c_link(obj_file, verbose_flag = 0, extra_objects = [], cplus = 0,
#		use_timestamps = 0, options = None):
#	return c_link_list([obj_file] + extra_objects, verbose_flag, cplus,
#		use_timestamps)

	def c_link_list(self, *args, **kwds):
		name = "MACOSX_DEPLOYMENT_TARGET"
		if not os.environ.get(name):
			os.environ[name] = "10.3"
		UnixSystem.c_link_list(self, *args, **kwds)

#	#  Link the given object files into a dynamically
#	#  loadable extension file. Returns the pathname
#	#  of the resulting file.
#	in_file = obj_files[0]
#	out_file = replace_suffix(in_file, ".so")
#	if use_timestamps and not file_newer_than_file(in_file, out_file):
#		return
#	linker = linkers[bool(cplus)]
#	args = [linker] + linker_options + obj_files + ["-o", out_file]
#	if verbose_flag or verbose:
#		print " ".join(args)
#	status = os.spawnvp(os.P_WAIT, linker, args)
#	if status <> 0:
#		raise CCompilerError("Linker returned status %s" % status)
#	return out_file

	def get_linker_options(self, options):
		result = UnixSystem.get_linker_options(self, options)
		if options:
			for dir in options.framework_path:
				options.append("-F" + dir)
		return result
	
	def get_libraries(self, options):
		result = UnixSystem.get_libraries(self, options)
		if options:
			for framework in options.frameworks:
				result.extend(["-framework", framework])
		return result

#------------------------------------------------------------------------------

system = DarwinSystem()

c_compile = system.c_compile
c_link = system.c_link
c_link_list = system.c_link_list
