cmake_minimum_required(VERSION 3.16)
project(robot_joint_firmware LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
    firmware/include
    firmware/src/config
    control/pid
    control/filters
    drivers/encoder
    drivers/motor
    comms
)

add_executable(robot_joint_firmware
    firmware/src/main.cpp
    firmware/src/app/control_loop.cpp
    firmware/src/app/state_machine.cpp
    firmware/src/app/safety_manager.cpp
    firmware/src/app/estimator.cpp
    firmware/src/board/board_init.cpp
    firmware/src/board/interrupts.cpp
    firmware/src/rtos/scheduler.cpp
    firmware/src/rtos/tasks.cpp
    control/pid/pid.cpp
    control/filters/low_pass.cpp
    control/filters/complementary.cpp
    control/trajectory/trajectory_generator.cpp
    control/trajectory/spline.cpp
    control/models/motor_model.cpp
    drivers/encoder/encoder_driver.cpp
    drivers/motor/pwm_driver.cpp
    drivers/motor/motor_control.cpp
    drivers/imu/imu_driver.cpp
    drivers/comms/uart.cpp
    drivers/comms/spi.cpp
    drivers/comms/i2c.cpp
    comms/packet.cpp
    comms/crc.cpp
    comms/uart_interface.cpp
    comms/can_interface.cpp
)
