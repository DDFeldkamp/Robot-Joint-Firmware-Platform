import argparse
import csv
from pathlib import Path

import matplotlib.pyplot as plt

from motor_sim import MotorSim

class PID:
    def __init__(self, kp, ki, kd, lo=-1.0, hi=1.0):
        self.kp = kp
        self.ki = ki
        self.kd = kd
        self.lo = lo
        self.hi = hi
        self.integral = 0.0
        self.prev_error = None

    def update(self, target, measured, dt):
        error = target - measured
        self.integral += error * dt
        derivative = 0.0 if self.prev_error is None else (error - self.prev_error) / dt
        self.prev_error = error
        out = self.kp * error + self.ki * self.integral + self.kd * derivative
        return max(self.lo, min(self.hi, out))

def run_step_response(target=1.0, duration=3.0, dt=0.001):
    plant = MotorSim()
    pid = PID(kp=8.0, ki=0.2, kd=0.05)
    rows = []
    t = 0.0
    while t <= duration:
        command = pid.update(target, plant.state.position, dt)
        state = plant.step(command, dt)
        rows.append({"time": t, "target": target, "position": state.position, "velocity": state.velocity, "command": command})
        t += dt
    return rows

def save_csv(rows, path):
    path = Path(path)
    path.parent.mkdir(parents=True, exist_ok=True)
    with path.open("w", newline="") as f:
        writer = csv.DictWriter(f, fieldnames=rows[0].keys())
        writer.writeheader()
        writer.writerows(rows)

def plot(rows):
    t = [r["time"] for r in rows]
    target = [r["target"] for r in rows]
    pos = [r["position"] for r in rows]
    plt.figure()
    plt.plot(t, target, label="target")
    plt.plot(t, pos, label="position")
    plt.xlabel("Time (s)")
    plt.ylabel("Position (rad)")
    plt.title("Simulated Step Response")
    plt.legend()
    plt.show()

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--out", default="docs/experiments/sim_step_response.csv")
    parser.add_argument("--plot", action="store_true")
    args = parser.parse_args()
    data = run_step_response()
    save_csv(data, args.out)
    print(f"wrote {args.out}")
    if args.plot:
        plot(data)
