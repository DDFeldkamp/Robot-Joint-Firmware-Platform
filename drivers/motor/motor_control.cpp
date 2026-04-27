#include "motor_driver.h"
#include <algorithm>

void MotorDriver::init() {
    command_ = 0.0f;
}

void MotorDriver::set_command(float command) {
    command_ = std::clamp(command, -1.0f, 1.0f);
}

float MotorDriver::command() const {
    return command_;
}
