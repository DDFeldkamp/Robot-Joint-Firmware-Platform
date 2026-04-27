#include "pid.h"
#include <algorithm>

PID::PID(float kp, float ki, float kd, float min_output, float max_output)
    : kp_(kp), ki_(ki), kd_(kd), min_output_(min_output), max_output_(max_output) {}

float PID::update(float setpoint, float measurement, float dt) {
    const float error = setpoint - measurement;
    integral_ += error * dt;

    float derivative = 0.0f;
    if (!first_update_ && dt > 0.0f) {
        derivative = (error - prev_error_) / dt;
    }
    first_update_ = false;
    prev_error_ = error;

    float output = kp_ * error + ki_ * integral_ + kd_ * derivative;
    output = std::clamp(output, min_output_, max_output_);

    // Simple anti-windup: prevent integral from growing when saturated.
    if (output == max_output_ || output == min_output_) {
        integral_ -= error * dt;
    }

    return output;
}

void PID::reset() {
    integral_ = 0.0f;
    prev_error_ = 0.0f;
    first_update_ = true;
}

void PID::set_gains(float kp, float ki, float kd) {
    kp_ = kp;
    ki_ = ki;
    kd_ = kd;
}
