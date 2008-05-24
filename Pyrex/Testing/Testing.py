#
#   Code for automatically running tests
#

import glob, os, sys, re, traceback
from os import path
from string import replace, strip

from Pyrex.Compiler import Main
from Pyrex.Utils import replace_suffix
from Pyrex.Compiler.Main import CCompilerError

from Pyrex.Compiler import ModuleNode
ModuleNode.testing_mode = 1

platform = sys.platform
if platform == "mac":
	from Pyrex.Testing.MacTesting import run_python_file
	from Pyrex.Testing.Mac.FileMarking import mark_item, item_mark
	from Pyrex.Mac.MacSystem import c_compile
elif platform == "darwin":
	from Pyrex.Testing.UnixTesting import run_python_file
	from Pyrex.Testing.Mac.FileMarking import mark_item, item_mark
	from Pyrex.Mac.DarwinSystem import c_compile, c_link
elif "linux" in platform:
	from Pyrex.Unix.UnixTesting import \
		run_python_file, mark_item, item_mark
	from Pyrex.Unix.LinuxSystem import c_compile
else:
	raise Exception(
		"Testing not supported on platform '%s'" % sys.platform)


class FailureError(Exception):
	pass

class AbortTesting(Exception):
	pass

failure_flag = 0
stop_at_first_failure = 0

def run_tests():
	"Run tests given as command line arguments."
	global stop_at_first_failure, new_results
	stop_at_first_failure = 0
	new_results = []
	args = sys.argv[1:]
	if args and args[0] == "-1":
		print "Setting stop_at_first_failure flag" ###
		stop_at_first_failure = 1
		del args[0]
	try:
		if args:
			for arg in args:
				run_test(arg)
		else:
			run_all_tests()
	except AbortTesting:
		pass
	for f in new_results:
		print "NEW RESULT:", f
	if not failure_flag:
		print "All tests passed."
	else:
		if stop_at_first_failure:
			print "Testing aborted."
		else:
			print "All tests complete."
		print "FAILURES OCCURRED"
	
def run_all_tests():
	"Run all tests in the Tests folder of the current dir."
	#test_dir = path.join(os.pardir, "Tests")
	test_dir = "Tests"
	return run_tests_in_dir(test_dir)

def run_test(item_path):
	"Run a single test or directory of tests."
	item_name = path.basename(item_path)
	if item_name.startswith("("):
		return "passed"
	elif item_marked_tested(item_path):
		print "Already tested", item_path
		return "passed"
	else:
		print "Running test", item_path
		if path.isdir(item_path):
			if item_name.startswith("R_"):
				return run_functional_test(item_path)
			else:
				return run_tests_in_dir(item_path)
		elif item_name.startswith("r_"):
			return run_functional_test(item_path)
		elif item_name.startswith("b_"):
			return "passed"
		elif item_name.startswith("l_"):
			return run_compile_test(item_path, link = 1)
		else:
			return run_compile_test(item_path)

def run_tests_in_dir(dir):
	"Run all tests in given directory."
	#print "*** run_tests_in_dir:", dir ###
	print "Running tests in", dir
	items = glob.glob(path.join(dir, "*.pyx"))
	result = "passed"
	for item in items:
		#print "*** run_tests_in_dir: doing file", item ###
		#item = path.join(dir, name)
		if run_test(item) <> "passed":
			result = "failed"
	names = os.listdir(dir)
	for name in names:
		if name not in ignore_dir_names:
			#print "*** run_tests_in_dir: checking name", name ###
			item = path.join(dir, name)
			if path.isdir(item):
				if run_test(item) <> "passed":
					result = "failed"
	mark_item(dir, result)
	return result

ignore_dir_names = (
	"Reference", "CantTestYet"
)

def run_compile_test(item, link = 0):
	"""Run a single compile-only or compile-and-link test.
	   If linking, the linked extension module is kept for use by later tests.
	"""
	try:
		mark_item(item, "failed")
		dir = path.dirname(item)
		name = path.basename(item)
		global mangled_module_name
		module_name, _ = os.path.splitext(name)
		mangled_module_name = "%d%s_" % (len(module_name), module_name)
		produces_include_files = name.startswith("i_") or name.startswith("ia_")
		produces_api_file = name.startswith("a_") or name.startswith("ia_")
		is_error_test = (
			name[:2] == "e_" or
			name[:3] == "se_")
		options = Main.CompilationOptions(Main.default_options)
		if is_error_test:
			options.use_listing_file = 1
			options.errors_to_stderr = 0
		try:
			result = Main.compile(item, options)
		except CCompilerError:
			fail("C compilation error.")
		except:
			fail_with_exception("Exception raised in Pyrex compiler.")
		#print "result =", result.__dict__ ###
		if is_error_test:
			if result.num_errors == 0:
				fail("No errors produced, expected some")
			if result.listing_file is None:
				fail("No listing file produced")
			compare_with_reference(result.listing_file, show_diffs = 0,
				line_munger = munge_error_line)
			remove_file(replace_suffix(item, ".c"))
		else:
			if result.num_errors <> 0:
				#display_files(replace_suffix(item, ".lis"))
				fail("%s errors reported, expected none" %
					result.num_errors)
			if result.c_file is None:
				fail("No C file produced")
			compare_with_reference(result.c_file, show_diffs = 1,
				line_munger = munge_c_line)
			if produces_include_files:
				if result.h_file is None:
					fail("No header file produced")
				compare_with_reference(result.h_file, show_diffs = 1,
					line_munger = munge_c_line)
				if result.i_file is None:
					pass
					# .pxi files no longer produced by default
					#fail("No include file produced")
				else:
					compare_with_reference(result.i_file, show_diffs = 1,
						line_munger = None)
			if produces_api_file:
				if result.api_file is None:
					fail("No api header file produced")
				compare_with_reference(result.api_file, show_diffs = 1,
					line_munger = munge_c_line)
			try:
				result.object_file = c_compile(result.c_file)
			except CCompilerError:
				fail("C compilation error.")
			except:
				fail_with_exception("C compiler failed.")
			try:
				cplus_object_file = c_compile(result.c_file, cplus = 1, obj_suffix = ".cplus.o")
			except CCompilerError:
				fail("C++ compilation error.")
			except:
				fail_with_exception("C++ compiler failed.")
			if link:
				try:
					c_link(result.object_file)
				except CCompilerError:
					fail("C linking error.")
			remove_file(result.listing_file)
			remove_file(result.object_file)
			remove_file(cplus_object_file)
		mark_item(item, "passed")
		return "passed"
	except FailureError:
		return "failed"

def run_functional_test_dir(dir, keep_files = 0):
	pyx_files = glob.glob(path.join(dir, "*.pyx"))
	if not pyx_files:
		fail("No .pyx file")
	if len(pyx_files) > 1:
		fail("Too many .pyx files")
	pyx_file = pyx_files[0]
	return run_functional_test(pyx_file, keep_files)

def compile_and_link(pyx_file):
	try:
		result = Main.compile(pyx_file, c_compile = 1, c_link = 1)
	except CCompilerError:
		fail("C compilation failed.")
	except:
		fail_with_exception("Pyrex compiler failed.")
	if result.num_errors <> 0:
		fail("%d Pyrex errors reported" % result.num_errors)
	return result

def functional_test_aux_file(pyx_file):
	dir, name = os.path.split(pyx_file)
	aux_name = "b_" + name[2:]
	return os.path.join(dir, aux_name)

def run_functional_test(pyx_file, keep_files = 0):
	"Run a compile, link and execute test."
	try:
		mark_item(pyx_file, "failed")
		result = compile_and_link(pyx_file)
		aux_pyx_file = functional_test_aux_file(pyx_file)
		if os.path.exists(aux_pyx_file):
			aux_result = compile_and_link(aux_pyx_file)
		else:
			aux_result = None
		#new_c = compare_with_reference(result.c_file, show_diffs = 1)
		new_c = 0
		py_file = replace_suffix(pyx_file, "_t.py")
		out_file = replace_suffix(pyx_file, ".out")
		err_file = replace_suffix(pyx_file, ".err")
		try:
			stat = run_python_file(py_file, out_file, err_file)
		except:
			print_file(err_file)
			fail_with_exception("Python script execution failed.")
		if stat:
			fail("Exit status %s" % stat)
		new_output = compare_with_reference(out_file, show_diffs = 0,
			line_munger = munge_runnable_test_output_line)
		if not keep_files:
			remove_file(replace_suffix(pyx_file, ".lis"))
			if not new_c:
				remove_file(result.c_file)
			remove_file(result.object_file)
			remove_file(result.extension_file)
			remove_file(err_file)
			if aux_result:
				remove_file(replace_suffix(aux_pyx_file, ".lis"))
				remove_file(aux_result.c_file)
				remove_file(aux_result.object_file)
				remove_file(aux_result.extension_file)
		mark_item(pyx_file, "passed")
		return "passed"
	except FailureError:
		return "failed"

def print_file(path):
	text = open(path).read()
	sys.stdout.write(text)
	if not text.endswith("\n"):
		sys.stdout.write("\n")

def compare_with_reference(file_in_question, show_diffs,
		line_munger):
	dir = path.dirname(file_in_question)
	name = path.basename(file_in_question)
	refdir = path.join(dir, "Reference")
	reference_file = path.join(refdir, name)
	if not path.exists(reference_file):
		#print "NEW RESULT:", file_in_question
		new_results.append(file_in_question)
		#display_files(file_in_question)
		return 1
	lines1 = get_lines(file_in_question, line_munger)
	lines2 = get_lines(reference_file, line_munger)
	if not munged_lines_equal(lines1, lines2):
		print "%s differs from reference." % name
		show_munged_lines_difference(lines1, lines2)
		fail("%s differs from reference" % name)
	return 0

def munged_lines_equal(lines1, lines2):
	if len(lines1) <> len(lines2):
		#print "Different numbers of munged lines:", \
		#	len(lines1), len(lines2) ###
		return 0
	for i in xrange(min(len(lines1), len(lines2))):
		#print "%4d: '%r'" % lines1[i] ###
		#print "%4d: '%r'" % lines2[i] ###
		if lines1[i][1] <> lines2[i][1]:
			return 0
	return 1
	
class StopComparison(Exception):
	pass

def get_lines(filename, line_munger):
	try:
		f = open(filename)
		lines = f.readlines()
		f.close()
	except IOError, e:
		fail(str(e))
	lines2 = []
	i = 0
	for line in lines:
		i += 1
		line = strip(line)
		if line_munger:
			try:
				line = line_munger(line)
			except StopComparison:
				break
		if line:
			lines2.append((i, line))
	return lines2

def munge_error_line(line):
	line = line.replace('"', '')
	file, mess = line.split(None, 1)
	i = line.rfind(":", 3)
	#print "Testing.munge_error_line:" ###
	#print "...file =", repr(file) ###
	#print "...mess =", repr(mess) ###
	#print "...i =", i ###
	line = "%s %s" % (file[i:], mess)
	#print "...new line =", repr(line)
	return line

def munge_runnable_test_output_line(line):
	# Get rid of the leading components of anything
	# that looks like a double-quoted pathname.
	pat = r'\"([^:/]*[:/])*'
	line = re.sub(pat, '"', line)
	line = line.replace("in <module>", "in ?")
	return line

#mangled_module_name = None

def munge_c_line(line):
	#
	#   Try to compensate for changes in code generation
	#   strategy.
	#
	#   MINOR HACKs are relatively harmless since any
	#   problems they mask will be caught due to the
	#   C code failing to compile.
	#
	#   HACKs, on the other hand, could mask real problems.
	#   The reference files should be updated as soon as
	#   possible to make them unnecessary, and they
	#   should be removed.
	#
	# MINOR HACK: Ignore runtime support code
	if line == "/* Runtime support code */":
		raise StopComparison
	# Ignore comments and other easily recognisable junk
	if line[:2] == "/*" and line[-2:] == "*/":
		line = ""
	elif line in ignore_lines:
		line = ""
	line = replace(line, " ", "")
	
	# MINOR HACK: ignore prototypes
	if line[-9:] == "/*proto*/":
		line = ""
		
	# HACK: treat all temp vars as equivalent
	line = re.sub("__pyx_[0-9]+", "__pyx_x", line)
	
	# HACK: ignore differences in source line numbers
	line = re.sub("__pyx_lineno=[0-9]+", "__pyx_lineno=x", line)
	
	# MINOR HACK: ignore temp var declarations
	if line == "PyObject*__pyx_x=0;":
		line = ""
	if line == "int__pyx_x;":
		line = ""
	if line == "Py_ssize_t__pyx_x;":
		line = ""
	
	## MINOR HACK: ignore gcc3.3 bug workaround lines
	#if "__pyx_gcc33_" in line:
	#	line = ""
	
	# ------ End of standing hacks -----
	
	# HACKS for string const changes
	
	if line.startswith("staticchar__pyx_k") \
		or line.startswith("staticPyObject*__pyx_k") \
		or line.startswith("staticPyObject*__pyx_n"):
			line = ""
	line = re.sub("__pyx_k[0-9]+", "__pyx_kx", line)
	line = re.sub("__pyx_k[0-9]+p", "__pyx_kxp", line)
		
	
	# ---------- END HACKS ----------

	return line

# The following are matched after removing leading and trailing
# whitespace but before removing embedded whitespace.

ignore_lines = (
  "#ifndef __stdcall"
  "#define __stdcall"
  "#endif"
  "#ifndef __cdecl"
  "#define __cdecl"
)

def show_munged_lines_difference(newlines, reflines):
	print "Flexidiff:"
	for i in range(min(len(newlines), len(reflines))):
		n1, line1 = newlines[i]
		n2, line2 = reflines[i]
		if line1 <> line2:
			print "New %4d: %s" % (n1, repr(line1))
			print "Ref %4d: %s" % (n2, repr(line2))
			return
	if len(newlines) > len(reflines):
		n1, line1 = newlines[len(reflines)]
		print "New %4d: %s" % (n1, repr(line1))
	elif len(reflines) > len(newlines):
		n2, line2 = reflines[len(newlines)]
		print "Ref %4d: %s" % (n2, repr(line2))

def fail(mess):
	global failure_flag
	failure_flag = 1
	print "TEST FAILED:", mess
	if 0:
		ans = raw_input("Continue testing [y/n]? ")
		if ans[:1] <> "y":
			print "Testing aborted."
			sys.exit(1)
	if stop_at_first_failure:
		raise AbortTesting
	else:
		raise FailureError

def fail_with_exception(mess):
	traceback.print_exc()
	fail(mess)

#def display_files(*filenames):
#	if sys.platform == "mac":
#		for filename in filenames:
#			bbedit_open(filename)

def remove_file(file):
	#print "Removing:", file ###
	if file:
		try:
			os.unlink(file)
		except (IOError, OSError):
			pass

def item_marked_tested(path):
	return item_mark(path) == "passed"
