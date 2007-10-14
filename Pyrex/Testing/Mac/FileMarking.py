import os, sys
#from Carbon.File import FSSpec
#from Carbon.File import FSRef
# We're using our own local patched version of _File
from _File import FSRef
from Carbon.Files import kFSCatInfoFinderInfo

# Make sure the _File we got supports access to the finderInfo
# attribute of FSCatalogInfo instances.

from _File import FSCatalogInfo
if not hasattr(FSCatalogInfo, 'finderInfo'):
	print >>sys.stderr, \
		"Carbon.File.FSCatalogInfo does not support access to finderInfo.\n" \
		"Patched version of _Filemodule.c needs to be compiled.\n" \
		"Source is in the Pyrex/Mac directory."
	raise ImportError("No file marking support")

no_colour = 0
passed_colour = 2
failed_colour = 6

#def colour_item(path, colour):
#	if os.path.isdir(path):
#		colour_directory(path, colour)
#	else:
#		colour_file(path, colour)

#def colour_directory(path, colour):
#	import findertools
#	findertools.label(path, (8 - colour) & 7)

#def colour_file(path, colour):
#	fsspec = FSSpec(path)
#	finfo = fsspec.GetFInfo()
#	finfo.Flags = (finfo.Flags & 0xfff1) | (colour << 1)
#	fsspec.SetFInfo(finfo)

#def get_item_colour(path):
#	import findertools
#	print "FileMarking.get_item_colour: Getting colour of", path ###
#	result = (8 - findertools.label(path)) & 7
#	#print "...result =", result ###
#	return result

def set_item_colour(path, colour):
	#print "Setting colour of", path, "to", colour ###
	fsref = FSRef(path)
	catinfo = fsref.FSGetCatalogInfo(kFSCatInfoFinderInfo)[0]
	finfo = catinfo.finderInfo
	finfo.Flags = (finfo.Flags & 0xfff1) | (colour << 1)
	catinfo.finderInfo = finfo
	fsref.FSSetCatalogInfo(kFSCatInfoFinderInfo, catinfo)

def get_item_colour(path):
	fsref = FSRef(path)
	catinfo = fsref.FSGetCatalogInfo(kFSCatInfoFinderInfo)[0]
	finfo = catinfo.finderInfo
	return (finfo.Flags >> 1) & 7

#def mark_path_untested(path):
#	#print "Marking untested:", path ###
#	set_item_colour(path, no_colour)

def mark_untested(item):
	if os.path.isdir(item):
		#set_item_colour(item, no_colour)
		mark_item(item, "untested")
		for name in os.listdir(item):
			if name <> "Reference":
				mark_untested(os.path.join(item, name))
	elif item.endswith(".pyx"):
		#set_item_colour(item, no_colour)
		mark_item(item, "untested")

def mark_args_untested():
	for item in sys.argv[1:]:
		mark_untested(item)

def mark_item(path, state):
	#print "Marking", path, "as", state ###
	if sys.platform in ["mac", "darwin"]:
		if state == "passed":
			colour = passed_colour
		elif state == "failed":
			colour = failed_colour
		elif state == "untested":
			colour = no_colour
		else:
			raise ValueError("Unknown state '%s'" % state)
		set_item_colour(path, colour)

def item_mark(path):
	colour = get_item_colour(path)
	if colour == passed_colour:
		return "passed"
	elif colour == failed_colour:
		return "failed"
	else:
		return "untested"
