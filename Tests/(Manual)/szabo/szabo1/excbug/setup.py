#! /usr/local/bin/stackless2.6
# by pts@fazekas.hu at Tue Feb  9 18:42:57 CET 2010

import glob
import os
import os.path
import sys
from distutils.core import Extension
from distutils.core import setup

Extension(name='excbug', sources=['excbug.c'], libraries=[])

setup(name='excbug',
      ext_modules = [ Extension(name='excbug', sources=['excbug.c']) ],
     )
