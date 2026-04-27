#include "control_loop.h"
#include "pid.h"
#include "low_pass.h"
#include "config.h"
#include "limits.h"
#include <algorithm>

namespace {
PID pid(config::DEFAULT_KP, config::DEFAULT_KI, config::DEFAULT_KD,
        -limits::MAX_COMMAND, limits::MAX_COMMAND);
LowPassFilter velocity_filter(0.15f);
}

void ControlLoop::init() {
    pid.reset();
    velocity_filter.reset(0.0f);
    initialized_ = false;
}

JointTelemetry ControlLoop::update(float setpoint_rad, float measured_position_rad, float dt) {
    setpoint_rad = std::clamp(setpoint_rad, limits::MIN_POSITION_RAD, limits::MAX_POSITION_RAD);

    float raw_velocity = 0.0f;
    if (initialized_ && dt > 0.0f) {
        raw_velocity = (measured_position_rad - previous_position_rad_) / dt;
    }
    initialized_ = true;
    previous_position_rad_ = measured_position_rad;

    const float velocity = velocity_filter.update(raw_velocity);
    const float command = pid.update(setpoint_rad, measured_position_rad, dt);

    return JointTelemetry{setpoint_rad, measured_position_rad, velocity, command};
}
