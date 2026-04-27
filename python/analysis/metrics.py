def step_response_metrics(rows, tolerance=0.02):
    target = rows[-1]["target"]
    positions = [r["position"] for r in rows]
    times = [r["time"] for r in rows]

    peak = max(positions)
    overshoot = max(0.0, (peak - target) / abs(target)) if target else 0.0
    steady_state_error = abs(target - positions[-1])

    settling_time = None
    band = tolerance * abs(target)
    for i, pos in enumerate(positions):
        if all(abs(target - p) <= band for p in positions[i:]):
            settling_time = times[i]
            break

    return {
        "overshoot": overshoot,
        "steady_state_error": steady_state_error,
        "settling_time": settling_time,
    }
