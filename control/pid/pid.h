#pragma once

class PID {
public:
    PID(float kp, float ki, float kd, float min_output, float max_output);
    float update(float setpoint, float measurement, float dt);
    void reset();
    void set_gains(float kp, float ki, float kd);

private:
    float kp_;
    float ki_;
    float kd_;
    float min_output_;
    float max_output_;
    float integral_ = 0.0f;
    float prev_error_ = 0.0f;
    bool first_update_ = true;
};
