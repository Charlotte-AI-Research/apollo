from setuptools import find_packages
from setuptools import setup

setup(
    name='scout_object_detector',
    version='0.0.0',
    packages=find_packages(
        include=('scout_object_detector', 'scout_object_detector.*')),
)
