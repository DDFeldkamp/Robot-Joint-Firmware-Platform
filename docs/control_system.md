# Control System

The baseline controller is PID position control. The loop runs at 1 kHz in the firmware simulation build.

Pipeline:

1. Read encoder position.
2. Estimate velocity by finite difference.
3. Low-pass filter velocity.
4. Compute PID command.
5. Clamp command to safe output limits.
6. Send normalized command to motor driver.

Future additions:

- cascaded position/velocity control
- feedforward terms
- current/torque loop
- automatic PID tuning from system identification
