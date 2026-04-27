#pragma once

class LowPassFilter {
public:
    explicit LowPassFilter(float alpha);
    float update(float input);
    void reset(float value = 0.0f);

private:
    float alpha_;
    float state_ = 0.0f;
    bool initialized_ = false;
};
