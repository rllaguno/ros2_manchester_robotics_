#include <micro_ros_arduino.h>

#include <stdio.h>
#include <rcl/rcl.h>
#include <rcl/error_handling.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>

#include <std_msgs/msg/float32.h>

rcl_publisher_t publisher_pot;
rcl_publisher_t publisher_voltage;
rcl_subscription_t subscriber;

std_msgs__msg__Float32 msg;
rclc_executor_t executor;
rclc_support_t support;
rcl_allocator_t allocator;
rcl_node_t node;
rcl_timer_t timer_1;
rcl_timer_t timer_2;

#define LED_PIN 13
#define POT_PIN 34
#define PWM_PIN 33

float pot_value = 0;
float voltage = 0;
float pwm_value = 0;

#define RCCHECK(fn) { rcl_ret_t temp_rc = fn; if((temp_rc != RCL_RET_OK)){error_loop();}}
#define RCSOFTCHECK(fn) { rcl_ret_t temp_rc = fn; if((temp_rc != RCL_RET_OK)){}}


void error_loop(){
  while(1){
    digitalWrite(LED_PIN, !digitalRead(LED_PIN));
    delay(100);
  }
}

void timer_callback_1(rcl_timer_t * timer, int64_t last_call_time)
{  
  RCLC_UNUSED(last_call_time);
  if (timer != NULL) {
    pot_value = analogRead(POT_PIN);
  }

  analogWrite(PWM_PIN, ((pwm_value*255)/100));
}

void timer_callback_2(rcl_timer_t * timer, int64_t last_call_time)
{  
  RCLC_UNUSED(last_call_time);
  if (timer != NULL) {
    //Publish pot_value to /raw_pot
    msg.data = pot_value;
    RCSOFTCHECK(rcl_publish(&publisher_pot, &msg, NULL));

    //Publish voltage to /voltage
    voltage = pot_value * (3.3 / 4095.0);
    msg.data = voltage;
    RCSOFTCHECK(rcl_publish(&publisher_voltage, &msg, NULL));
  }
}

void subscription_callback(const void * msgin){
  const std_msgs__msg__Float32 * msg = (const std_msgs__msg__Float32 *)msgin;
  pwm_value = msg->data;
}

void setup() {
  set_microros_transports();
  
  pinMode(LED_PIN, OUTPUT);
  pinMode(PWM_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);  
  
  delay(2000);

  allocator = rcl_get_default_allocator();

  //create init_options
  RCCHECK(rclc_support_init(&support, 0, NULL, &allocator));

  // create node
  RCCHECK(rclc_node_init_default(&node, "micro_ros_esp32_node", "", &support));

  // create raw pot publisher
  RCCHECK(rclc_publisher_init_default(
    &publisher_pot,
    &node,
    ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Float32),
    "/raw_pot"));

  // create voltage publisher
  RCCHECK(rclc_publisher_init_default(
    &publisher_voltage,
    &node,
    ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Float32),
    "/voltage"));

  // create subscriber //pwm_duty_cycle
  RCCHECK(rclc_subscription_init_default(
    &subscriber,
    &node,
    ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Float32),
    "/pwm_duty_cycle"));

  // create timer_1, 10 ms, raw_pot
  const unsigned int timer_timeout_1 = 10;
  RCCHECK(rclc_timer_init_default(
    &timer_1,
    &support,
    RCL_MS_TO_NS(timer_timeout_1),
    timer_callback_1));

  // create timer_2, 100 ms, voltage
  const unsigned int timer_timeout_2 = 100;
  RCCHECK(rclc_timer_init_default(
    &timer_2,
    &support,
    RCL_MS_TO_NS(timer_timeout_2),
    timer_callback_2));

  // create executor
  RCCHECK(rclc_executor_init(&executor, &support.context, 3, &allocator));
  RCCHECK(rclc_executor_add_subscription(&executor, &subscriber, &msg, &subscription_callback, ON_NEW_DATA));
  RCCHECK(rclc_executor_add_timer(&executor, &timer_1));
  RCCHECK(rclc_executor_add_timer(&executor, &timer_2));

  msg.data = 0;
}

void loop() {
  delay(100);
  RCSOFTCHECK(rclc_executor_spin_some(&executor, RCL_MS_TO_NS(100)));
}
