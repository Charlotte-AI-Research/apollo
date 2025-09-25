from setuptools import find_packages
from setuptools import setup

setup(
    name='rslidar_laserscan_converter',
    version='1.0.0',
    packages=find_packages(
        include=('rslidar_laserscan_converter', 'rslidar_laserscan_converter.*')),
)
