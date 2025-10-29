from setuptools import find_packages, setup
from glob import glob
import os

package_name = 'scout_mini_perception'

setup(
    name=package_name,
    version='0.1.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name, 'launch'), glob('launch/*.py')),
        (os.path.join('share', package_name, 'config'), glob('config/*.yaml')),
        (os.path.join('share', package_name, 'docs'), glob('docs/*.md')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='Smit Patel',
    maintainer_email='smit.r.patel5@gmail.com',
    description='Phase 4: Person Following System for Apollo Scout Mini Robot',
    license='MIT',
    extras_require={
        'test': [
            'pytest',
        ],
    },
    entry_points={
        'console_scripts': [
            'person_detector_node = scout_mini_perception.nodes.person_detector_node:main',
            'depth_estimator_node = scout_mini_perception.nodes.depth_estimator_node:main',
            'follow_controller_node = scout_mini_perception.nodes.follow_controller_node:main',
        ],
    },
)