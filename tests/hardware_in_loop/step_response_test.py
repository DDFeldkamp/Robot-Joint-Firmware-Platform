import argparse
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.append(str(ROOT / "simulation"))
sys.path.append(str(ROOT / "python" / "analysis"))

from control_sim import run_step_response, save_csv
from metrics import step_response_metrics

parser = argparse.ArgumentParser()
parser.add_argument("--sim", action="store_true", help="Run against the simulator instead of hardware.")
parser.add_argument("--out", default="docs/experiments/hil_or_sim_step_response.csv")
args = parser.parse_args()

if not args.sim:
    raise SystemExit("Hardware serial path not implemented yet. Use --sim for now.")

rows = run_step_response()
save_csv(rows, ROOT / args.out)
print(step_response_metrics(rows))
print(f"wrote {args.out}")
