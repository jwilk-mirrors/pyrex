#------------------------------------------------------------------------------
#
#   Pyrex - Linux system interface
#
#------------------------------------------------------------------------------

from UnixSystems import UnixSystem, CCompilerError

system = UnixSystem()

c_compile = system.c_compile
c_link = system.c_link
c_link_list = system.c_link_list
