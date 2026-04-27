# Robot Joint Firmware Platform

A portfolio-grade embedded robotics project: a real-time C++ firmware stack for a robotic joint actuator, paired with Python simulation, hardware-in-the-loop testing, system identification, and calibration tooling.

## Motivation
This repo is designed to demonstrate firmware engineering skills relevant to humanoid robotics:

- Real-time embedded C++ control loops
- Sensor filtering and actuator command pipelines
- Modular firmware architecture
- Python-based test automation and system identification
- Simulation-to-firmware validation workflow
- Scalable architecture for future CAN/multi-joint extension

## Current implemented scope
- C++ firmware skeleton with deterministic control loop
- PID controller
- Low-pass filter
- Simulated encoder and motor driver
- UART-style packet protocol skeleton
- Python motor/joint simulation
- Step response test pipeline
- System identification metrics
- Unit-test structure

## Quick start

### 1. Clone and enter repo
```bash
git clone <your-repo-url>
cd robot-joint-firmware-platform
```

### 2. Create Python environment
```bash
python3 -m venv .venv
source .venv/bin/activate
pip install -r requirements.txt
```

### 3. Run simulation
```bash
python simulation/control_sim.py
```

### 4. Run step response analysis
```bash
python tests/hardware_in_loop/step_response_test.py --sim
```

### 5. Build firmware simulation target
```bash
cmake -S . -B build
cmake --build build
./build/robot_joint_firmware
```

## Roadmap
- Replace simulated encoder/motor drivers with STM32 or RP2040 hardware drivers
- Add UART serial transport to Python client
- Add CAN message abstraction
- Add Dockerized CI build
- Add closed-loop HIL validation on real actuator hardware
