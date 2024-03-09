import rclpy
import numpy as np
from rclpy.node import Node
from std_msgs.msg import Float32
from msgs.msg import SignalParams

class My_Subscriber(Node):
    def __init__(self):
        super().__init__('reconstruction')
        self.sub_signal_params = self.create_subscription(SignalParams, '/signal_params', self.signal_params_callback, 10)
        self.proc_signal = self.create_publisher(Float32, '/signal_reconstructed', 10)
        self.get_logger().info('|reconstruction node successfully initialized|')
        self.t = 0
        self.timer_period = 0.01
        self.timer = self.create_timer(self.timer_period, self.timer_callback)

        self.st = 0
        self.a = 0.0
        self.f = 0.0
        self.o = 0.0
        self.t = 0.0

        self.msg_signal_reconstructed = Float32()

    def timer_callback(self):
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

        self.msg_signal_reconstructed.data = generated_signal
        self.proc_signal.publish(self.msg_signal_reconstructed)

    def signal_params_callback(self, msg):
        self.st = msg.type_signal
        self.a = msg.amplitude
        self.f = msg.frequency
        self.o = msg.offset
        self.t = msg.time

def main(args=None):
    rclpy.init(args=args)
    m_s = My_Subscriber()
    rclpy.spin(m_s)
    m_s.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()