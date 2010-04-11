# Makefile for Darwin

# Change this to your Python source location
PYTHON := /Local/Build/Pythonic/python/2.6.1

# Version 2.3:
#DYNOPT := -framework Python
# Version 2.4+:
DYNOPT := -undefined dynamic_lookup

INCLUDE := -I$(PYTHON) -I$(PYTHON)/Include -I$(PYTHON)/Mac/Include

CCOPTS := -fno-strict-aliasing -Wno-long-double -no-cpp-precomp \
	-mno-fused-madd -fno-common -dynamic

LDOPTS := -Wl,-F.,-w -bundle $(DYNOPT) -framework Carbon

all:	_File.so

_File.o:	_Filemodule_patched.c
	gcc -c $(INCLUDE) $(OPTS) $< -o $@

_File.so:	_File.o
	gcc $(LDOPTS) $< -o $@
