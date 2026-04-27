#include "encoder_driver.h"

void EncoderDriver::init() {}

float EncoderDriver::read_position_rad() {
    return simulated_position_rad_;
}

void EncoderDriver::set_simulated_position(float position_rad) {
    simulated_position_rad_ = position_rad;
}
