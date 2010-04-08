#
#   Pyrex - Filename suffixes
#

cplus_suffix = ".cpp"
pxd_suffixes = (".pxd",)
pyx_suffixes = (".pyx", ".pyx+")
package_init_files = ("__init__.py", "__init__.pyx", "__init__.pyx+")
pyx_to_c_suffix = {".pyx": ".c", ".pyx+": cplus_suffix}
