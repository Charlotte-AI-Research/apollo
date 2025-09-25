from setuptools import find_packages
from setuptools import setup

setup(
    name='follow_human',
    version='0.0.1',
    packages=find_packages(
        include=('follow_human', 'follow_human.*')),
)
