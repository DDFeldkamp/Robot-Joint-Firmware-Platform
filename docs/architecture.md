# Architecture

The system is organized into five layers:

1. **Hardware**: motor driver, encoder, IMU, microcontroller peripherals.
2. **Drivers**: low-level hardware access for sensors, motor output, and buses.
3. **Control**: PID, filters, trajectory generation, and actuator models.
4. **Firmware App**: deterministic control loop, safety manager, state machine, estimator.
5. **Python Tooling**: simulation, calibration, HIL testing, analysis, and visualization.

The current host build simulates hardware so the control logic can be developed before flashing a board.
