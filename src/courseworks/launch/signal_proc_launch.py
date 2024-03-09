from launch_ros.actions import Node
from launch import LaunchDescription

def generate_launch_description():
    
    process_node = Node(
        package = 'courseworks',
        executable = 'process',
        output = 'screen', 
    )

    signal_generator_node = Node(
        package = 'courseworks',
        executable = 'signal_generator',
        output = 'screen', 
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
    )

    l_d = LaunchDescription([process_node, signal_generator_node, rqt_graph_node, rqt_plot_node])
    return l_d