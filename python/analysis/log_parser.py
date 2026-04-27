import csv

def read_csv_log(path):
    with open(path, newline="") as f:
        return [{k: float(v) for k, v in row.items()} for row in csv.DictReader(f)]
