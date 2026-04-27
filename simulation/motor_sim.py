from dataclasses import dataclass

@dataclass
class MotorState:
    position: float = 0.0
    velocity: float = 0.0

class MotorSim:
    """Simple second-order joint actuator model for controller development."""

    def __init__(self, inertia=0.03, damping=0.08, torque_constant=1.0):
        self.inertia = inertia
        self.damping = damping
        self.torque_constant = torque_constant
        self.state = MotorState()

    def step(self, command: float, dt: float) -> MotorState:
        command = max(-1.0, min(1.0, command))
        torque = self.torque_constant * command
        acceleration = (torque - self.damping * self.state.velocity) / self.inertia
        self.state.velocity += acceleration * dt
        self.state.position += self.state.velocity * dt
        return self.state
