import rclpy
import math
import numpy as np
from rclpy.node import Node
from std_msgs.msg import Float32

class My_Publisher(Node):
    def __init__(self):
        super().__init__('signal_generator')
        self.signal = self.create_publisher(Float32, '/signal', 10)
        self.time = self.create_publisher(Float32, '/time', 10)
        timer_period = 0.1
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.get_logger().info('|signal_generator node successfully initialized|')
        self.msg_signal = Float32()
        self.msg_time = Float32()
        self.counter = 0

    def timer_callback(self):
        self.msg_signal.data = float(5 * np.sin(self.counter))
        self.msg_time.data = float(self.counter)
        self.get_logger().info('Publishing Signal: {:.2f}'.format(self.msg_signal.data))
        self.get_logger().info('Publishing Time: {:.2f}'.format(self.msg_time.data))
        self.signal.publish(self.msg_signal)
        self.time.publish(self.msg_time)
        self.counter += 0.1

def main(args=None):
    rclpy.init(args=args)
    m_p = My_Publisher()
    rclpy.spin(m_p)
    m_p.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()