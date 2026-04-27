import argparse
import matplotlib.pyplot as plt
from log_parser import read_csv_log

parser = argparse.ArgumentParser()
parser.add_argument("path")
args = parser.parse_args()
rows = read_csv_log(args.path)
plt.figure()
plt.plot([r["time"] for r in rows], [r["target"] for r in rows], label="target")
plt.plot([r["time"] for r in rows], [r["position"] for r in rows], label="position")
plt.xlabel("Time (s)")
plt.ylabel("Position (rad)")
plt.legend()
plt.show()
