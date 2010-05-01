#
#   Pyrex - Command Line Parsing
#

import sys
from Filenames import pyx_suffixes
from Pyrex.Utils import has_suffix

usage = """\
Usage: pyrexc [options] sourcefile...
Options:
  -?, --help                Display a summary of command line options
  -V, --version             Display version number of pyrex compiler
  -e, --create-listing      Write error messages to a listing file
  -I, --include-dir <dir>   Search for include files in named directory
  -+, --cplus               Use .cpp as extension of generated C files
  -o, --output-file <file>  Specify name of generated C file
  -r, --recursive           Recursively find and compile dependencies
  -t, --timestamps          Only compile newer source files (implied by -r)
  -f, --force               Compile all source files (overrides implied -t)
  -v, --verbose             Always display module names being compiled
  -q, --quiet               Never display module names being compiled
The following experimental options are supported only on MacOSX and Linux:
  -C, --compile         Compile generated .c file to .o file
  -X, --link            Link .o file to produce extension module (implies -C)
  -V, --verbose         Display compiling and linking commands
  -+, --cplus           Use C++ compiler for compiling and linking
  -N, --numpy           Include numpy header directory in search path
  -L, --library_dir     Search for library files in the named directory
  -l, --library         Link with the named library
  -F, --framework_dir   Search for frameworks in the named directory [MacOSX]
      --framework       Link with the name framework [MacOSX]
  Additional .o files to link may be supplied when using -X."""

def fail(mess):
	print >>sys.stderr, mess
	sys.exit(1)

def bad_usage():
	fail(usage)

def bad_option(option):
	fail("Unrecognized option: %s" % option)

def show_usage():
	print >>sys.stderr, usage
	sys.exit(0)

def get_numpy_include_dir():
	try:
		import numpy
	except ImportError:
		fail("pyrexc: Unable to import numpy to find include directory")
	return numpy.get_include()

def parse_command_line(args):
	from Pyrex.Compiler.Main import \
		CompilationOptions, default_options

	def pop_arg(option = None):
		if args:
			return args.pop(0)
		elif option:
			fail("Missing argument for %s" % option)
		else:
			fail("Missing argument")
	
	def pop_option():
		option = args.pop(0)
		if option.startswith("--"):
			value = None
		else:
			value = option[2:]
			option = option[:2]
		return option, value
	
	def get_param(arg):
		option, value = arg
		if value:
			return value
		else:
			return pop_arg(option)

	options = CompilationOptions(default_options)
	sources = []
	while args:
		if args[0].startswith("-"):
			arg = pop_option()
			option, value = arg
			if option in ("-?", "--help"):
				show_usage()
			elif option in ("-V", "--version"):
				options.show_version = 1
			elif option in ("-v", "--verbose"):
				options.verbose = 1
			elif option in ("-e", "--create-listing"):
				options.use_listing_file = 1
			elif option in ("-C", "--compile"):
				options.c_only = 0
			elif option in ("-X", "--link"):
				options.c_only = 0
				options.obj_only = 0
			elif option in ("-+", "--cplus"):
				options.cplus = 1
			elif option in ("-I", "--include-dir"):
				options.include_path.append(get_param(arg))
			elif option in ("-o", "--output-file"):
				options.output_file = get_param(arg)
			elif option in ("-r", "--recursive"):
				options.recursive = 1
			elif option in ("-t", "--timestamps"):
				options.timestamps = 1
			elif option in ("-f", "--force"):
				options.timestamps = 0
			elif option in ("-N", "--numpy"):
				options.include_path.append(get_numpy_include_dir())
			elif option in ("-L", "--library_dir"):
				options.library_path.append(get_param(arg))
			elif option in ("-l", "--library"):
				options.libraries.append(get_param(arg))
			elif option in ("-F", "--framework_dir"):
				options.framework_path.append(get_param(arg))
			elif option == "--framework":
				options.frameworks.append(get_param(arg))
			else:
				bad_option(option)
		else:
			arg = pop_arg()
			if has_suffix(arg, pyx_suffixes):
				sources.append(arg)
			elif arg.endswith(".o"):
				options.objects.append(arg)
			else:
				print >>sys.stderr, \
					"pyrexc: %s: Unknown filename suffix" % arg
	if options.objects and len(sources) > 1:
		print >>sys.stderr, \
			"pyrexc: Only one source file allowed together with .o files"
	if options.use_listing_file and len(sources) > 1:
		print >>sys.stderr, \
			"pyrexc: Only one source file allowed when using -o"
		sys.exit(1)
	return options, sources

