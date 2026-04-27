from itertools import product
from pathlib import Path
import sys

ROOT = Path(__file__).resolve().parents[2]
sys.path.append(str(ROOT / "simulation"))
sys.path.append(str(ROOT / "python" / "analysis"))

from control_sim import run_step_response
from metrics import step_response_metrics

# Placeholder tuner: currently evaluates the default sim repeatedly.
def score(metrics):
    settling = metrics["settling_time"] if metrics["settling_time"] is not None else 10.0
    return settling + 5.0 * metrics["overshoot"] + 2.0 * metrics["steady_state_error"]

if __name__ == "__main__":
    rows = run_step_response()
    m = step_response_metrics(rows)
    print("baseline metrics:", m)
    print("baseline score:", score(m))
