from setuptools import setup

package_name = 'scout_object_detector'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    # Use this if your files are in src/scout_object_detector
    # package_dir={'': 'src'},
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='Smit Patel',
    maintainer_email='smit.r.patel5@gmail.com',
    description='YOLOv8 object detection node using RealSense',
    license='MIT',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'detection_node = scout_object_detector.object_detection_node:main',
            'object_detection_node = scout_object_detector.object_detection_node:main'
        ],
    },
)