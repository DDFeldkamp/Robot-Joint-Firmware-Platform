#pragma once

class EncoderDriver {
public:
    void init();
    float read_position_rad();
    void set_simulated_position(float position_rad);

private:
    float simulated_position_rad_ = 0.0f;
};
