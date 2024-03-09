import os
from ament_index_python.packages import get_package_share_directory
from launch_ros.actions import Node
from launch import LaunchDescription

def generate_launch_description():
    
    config = os.path.join(
        get_package_share_directory('courseworks_2'),
        'config',
        'params.yaml'
    )

    signal_generator_node = Node(
        package = 'courseworks_2',
        executable = 'signal_generator',
        output = 'screen', 
        parameters = [config]
    )

    reconstruction_node = Node(
        package = 'courseworks_2',
        executable = 'reconstruction',
        output = 'screen'
    )

    rqt_graph_node = Node(
        package = 'rqt_graph',
        executable = 'rqt_graph',
        output = 'screen',
    )

    rqt_plot_node = Node(
        package = 'rqt_plot',
        executable = 'rqt_plot',
        output = 'screen',
        parameters = [{'args': '/signal/data /signal_reconstructed/data'}]
    )

    l_d = LaunchDescription([signal_generator_node, reconstruction_node, rqt_graph_node, rqt_plot_node])
    return l_d