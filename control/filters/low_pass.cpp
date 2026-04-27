#include "low_pass.h"

LowPassFilter::LowPassFilter(float alpha) : alpha_(alpha) {}

float LowPassFilter::update(float input) {
    if (!initialized_) {
        state_ = input;
        initialized_ = true;
        return state_;
    }
    state_ = alpha_ * input + (1.0f - alpha_) * state_;
    return state_;
}

void LowPassFilter::reset(float value) {
    state_ = value;
    initialized_ = true;
}
