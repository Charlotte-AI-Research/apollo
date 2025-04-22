from setuptools import setup

package_name = 'follow_human'

setup(
    name=package_name,
    version='0.0.1',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='ubuntu',
    maintainer_email='160794076+YousefQanadilo@users.noreply.github.com',
    description='Human following system for Apollo robot using tracking and depth estimation',
    license='Apache License 2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'depth_estimation_node = follow_human.depth_estimation:main',
            'tracking_node = follow_human.tracking_node:main',
        ],
    },
)