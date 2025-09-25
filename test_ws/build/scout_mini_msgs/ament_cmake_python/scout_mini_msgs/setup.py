from setuptools import find_packages
from setuptools import setup

setup(
    name='scout_mini_msgs',
    version='0.1.0',
    packages=find_packages(
        include=('scout_mini_msgs', 'scout_mini_msgs.*')),
)
