from pathlib import Path
import sys

ROOT = Path(__file__).resolve().parents[2]
sys.path.append(str(ROOT / "simulation"))
sys.path.append(str(ROOT / "python" / "analysis"))

from control_sim import run_step_response
from metrics import step_response_metrics

def test_simulated_step_response_converges():
    rows = run_step_response(duration=3.0)
    m = step_response_metrics(rows)
    assert m["steady_state_error"] < 0.2
