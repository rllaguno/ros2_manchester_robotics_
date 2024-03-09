import os
from glob import glob
from setuptools import find_packages, setup

package_name = 'courseworks_2'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        #('share/ament_index/resource_index/packages',
        #    ['resource/' + package_name]),
        #('share/' + package_name, ['package.xml']),
        #(os.path.join('share', package_name, 'launch'), 
        #    glob(os.path.join('launch', '*launch.[pxy][yma]*'))),
        #(os.path.join('share', package_name, 'config'),
        #    glob('config/params.yaml'))
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/launch', ['launch/signal_proc_launch.py']),
        ('share/' + package_name + '/config', ['config/params.yaml'])
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='root',
    maintainer_email='rodrigollagunoc@gmail.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'signal_generator = courseworks_2.signal_generator:main',
            'reconstruction = courseworks_2.reconstruction:main'
        ],
    },
)
