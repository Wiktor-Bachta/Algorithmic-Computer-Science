from distutils.core import setup
from distutils.extension import Extension
from Cython.Build import cythonize

examples_extension = Extension(
    name="wrapper",
    sources=["wrapper.pyx"],
    libraries=["c"],
    library_dirs=["."],
    include_dirs=["."]
)
setup(
    name="wrapper",
    ext_modules=cythonize([examples_extension])
)