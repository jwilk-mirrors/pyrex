#
#   Pyrex -- Things that don't belong
#            anywhere else in particular
#

import os, sys
try:
	from __builtin__ import set
except ImportError:
	from sets import Set as set

def has_suffix(path, suffixes):
	for suffix in suffixes:
		if path.endswith(suffix):
			return True
	return False

def replace_suffix(path, newsuf):
	base, _ = os.path.splitext(path)
	return base + newsuf

def map_suffix(path, mapping, default):
	base, suffix = os.path.splitext(path)
	return base + mapping.get(suffix, default)

def open_new_file(path):
	#  Open and truncate existing file to
	#  preserve metadata on the Mac.
	return open(path, "w+")

def castrate_file(path, st):
	#  Remove junk contents from an output file after a
	#  failed compilation, but preserve metadata on Mac.
	#  Also sets access and modification times earlier
	#  than those specified by st (a stat struct).
	try:
		f = open(path, "r+")
	except EnvironmentError:
		pass
	else:
		f.seek(0, 0)
		f.truncate()
		f.write(
			"#error Do not use this file, it is the result of a failed Pyrex compilation.\n")
		f.close()
		if st:
			os.utime(path, (st.st_atime - 1, st.st_mtime - 1))

def modification_time(path):
	st = os.stat(path)
	return st.st_mtime

def file_newer_than(path, time):
	ftime = modification_time(path)
	return ftime > time

def file_newer_than_file(path1, path2):
	if not os.path.exists(path2):
		return 1
	t1 = modification_time(path1)
	t2 = modification_time(path2)
	return t1 > t2
