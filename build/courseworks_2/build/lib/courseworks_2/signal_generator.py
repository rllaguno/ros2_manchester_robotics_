import rclpy
import numpy as np
from rclpy.node import Node
from std_msgs.msg import Float32
from msgs.msg import SignalParams
import yaml

class My_Publisher(Node):
    def __init__(self):
        super().__init__('signal_generator')
        self.signal = self.create_publisher(Float32, '/signal', 10)
        self.signal_params = self.create_publisher(SignalParams, '/signal_params', 10)
        self.timer_period_signal = 0.01
        self.timer_period_params = 0.1
        self.timer_signal = self.create_timer(self.timer_period_signal, self.timer_callback_signal)
        self.timer_params = self.create_timer(self.timer_period_params, self.timer_callback_params)
        self.get_logger().info('|signal_generator node successfully initialized|')

        self.st = 0
        self.a = 0.0
        self.f = 0.0
        self.o = 0.0
        self.t = 0.0

        self.declare_parameter('type_signal', rclpy.Parameter.Type.INTEGER)
        self.declare_parameter('amplitude', rclpy.Parameter.Type.DOUBLE)
        self.declare_parameter('frequency', rclpy.Parameter.Type.DOUBLE)
        self.declare_parameter('offset', rclpy.Parameter.Type.DOUBLE)

        self.msg_signal = Float32()
        self.msg_signal_params = SignalParams()

    def timer_callback_signal(self):
        self.st = self.get_parameter('type_signal').get_parameter_value().integer_value
        self.a = self.get_parameter('amplitude').get_parameter_value().double_value
        self.f = self.get_parameter('frequency').get_parameter_value().double_value
        self.o = self.get_parameter('offset').get_parameter_value().double_value
        self.t += self.timer_period_signal

        if self.st == 2:
            generated_signal = self.a * np.sign(np.sin(2 * np.pi * self.f * self.t)) + self.o
        elif self.st == 3:
            generated_signal = self.a * (2 * (self.t * self.f - np.floor(self.t * self.f + 0.5))) + self.o
        elif self.st == 4:
            generated_signal = self.a * np.cos(2 * np.pi * self.f * self.t) + self.o
        elif self.st == 5:
            generated_signal = self.a * np.tan(2 * np.pi * self.f * self.t ) + self.o
        else:
            generated_signal = self.a * np.sin(2 * np.pi * self.f * self.t) + self.o

        self.msg_signal.data = generated_signal
        self.signal.publish(self.msg_signal)
        
    def timer_callback_params(self):
        self.msg_signal_params.type_signal = self.st
        self.msg_signal_params.amplitude = self.a
        self.msg_signal_params.frequency = self.f
        self.msg_signal_params.offset = self.o
        self.msg_signal_params.time = self.t
        self.signal_params.publish(self.msg_signal_params)

def main(args=None):
    rclpy.init(args=args)
    m_p = My_Publisher()
    rclpy.spin(m_p)
    m_p.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()