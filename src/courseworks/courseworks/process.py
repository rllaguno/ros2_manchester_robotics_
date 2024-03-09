import rclpy
import numpy as np
from rclpy.node import Node
from std_msgs.msg import Float32

class My_Subscriber(Node):
    def __init__(self):
        super().__init__('process')
        self.sub_signal = self.create_subscription(Float32, '/signal', self.signal_callback, 10)
        self.sub_time = self.create_subscription(Float32, '/time', self.time_callback, 10)
        self.proc_signal = self.create_publisher(Float32, '/proc_signal', 10)
        timer_period = 0.1
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.get_logger().info('|process node successfully initialized|')

        self.processed_signal = None

    def signal_callback(self, msg):
        self.get_logger().info('Sin: {:.2f}'.format(msg.data))


    def timer_callback(self):
        if self.processed_signal is not None:
            proc_signal_msg = Float32()
            proc_signal_msg.data = self.processed_signal
            self.proc_signal.publish(proc_signal_msg)
            self.get_logger().info('Manipulated Signal: {:.2f}'.format(proc_signal_msg.data))

    def time_callback(self, msg):
        processed_signal = 5*(np.sin(msg.data)*np.cos(np.pi/4) + np.cos(msg.data)*np.sin(np.pi/4))
        processed_signal += 5
        processed_signal /=  float(2.0)
        self.processed_signal = processed_signal

def main(args=None):
    rclpy.init(args=args)
    m_s = My_Subscriber()
    rclpy.spin(m_s)
    m_s.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

