#include "imu_driver.h"
void ImuDriver::init() {}
ImuSample ImuDriver::read() { return {0, 0, 9.81f, 0, 0, 0}; }
