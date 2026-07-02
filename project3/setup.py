from setuptools import setup, Extension

module = Extension("fastsum", sources=["fastsum.c"])

setup(
    name="fastsum",
    version="1.0",
    ext_modules=[module]
)
