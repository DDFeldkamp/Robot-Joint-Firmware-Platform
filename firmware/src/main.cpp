#include "control_loop.h"
#include "encoder_driver.h"
#include "motor_driver.h"
#include "config.h"
#include <chrono>
#include <iostream>
#include <thread>

int main() {
    ControlLoop loop;
    EncoderDriver encoder;
    MotorDriver motor;

    loop.init();
    encoder.init();
    motor.init();

    float simulated_position = 0.0f;
    const float target = 1.0f;

    for (int i = 0; i < 3000; ++i) {
        encoder.set_simulated_position(simulated_position);
        const auto telemetry = loop.update(target, encoder.read_position_rad(), config::DT_SECONDS);
        motor.set_command(telemetry.motor_command);

        // Simple host-side plant model for local firmware demo.
        simulated_position += motor.command() * config::DT_SECONDS * 3.0f;

        if (i % 100 == 0) {
            std::cout << "t=" << i * config::DT_SECONDS
                      << " setpoint=" << telemetry.setpoint_rad
                      << " position=" << telemetry.position_rad
                      << " velocity=" << telemetry.velocity_rad_s
                      << " command=" << telemetry.motor_command << '\n';
        }
        std::this_thread::sleep_for(std::chrono::microseconds(1000));
    }

    return 0;
}
