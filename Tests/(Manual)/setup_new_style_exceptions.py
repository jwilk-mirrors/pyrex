from distutils.core import setup
from distutils.extension import Extension
from Pyrex.Distutils import build_ext

setup(
	ext_modules = [
		Extension("new_style_exceptions", ["new_style_exceptions.pyx"]),
	],
	cmdclass = {'build_ext': build_ext}
)
