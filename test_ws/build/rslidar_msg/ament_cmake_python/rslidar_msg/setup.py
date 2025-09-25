from setuptools import find_packages
from setuptools import setup

setup(
    name='rslidar_msg',
    version='0.0.0',
    packages=find_packages(
        include=('rslidar_msg', 'rslidar_msg.*')),
)
