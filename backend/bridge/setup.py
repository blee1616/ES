from setuptools import setup, Extension

cpp_extension = Extension(
    'cpp_module',
    sources=['cpp_module.cpp'],
    include_dirs=['../cpp/include'],
    language='c++'
)

setup(
    name='energy_simulation_bridge',
    version='0.1',
    description='Bridge between C++ backend and Python for energy simulation',
    ext_modules=[cpp_extension],
)