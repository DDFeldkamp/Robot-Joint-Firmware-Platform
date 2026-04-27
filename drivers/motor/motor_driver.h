#pragma once

class MotorDriver {
public:
    void init();
    void set_command(float command);
    float command() const;

private:
    float command_ = 0.0f;
};
