#pragma once

struct JointTelemetry {
    float setpoint_rad;
    float position_rad;
    float velocity_rad_s;
    float motor_command;
};

class ControlLoop {
public:
    void init();
    JointTelemetry update(float setpoint_rad, float measured_position_rad, float dt);

private:
    float previous_position_rad_ = 0.0f;
    bool initialized_ = false;
};
