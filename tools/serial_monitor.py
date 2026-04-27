import argparse
import serial

parser = argparse.ArgumentParser()
parser.add_argument("port")
parser.add_argument("--baud", type=int, default=115200)
args = parser.parse_args()

with serial.Serial(args.port, args.baud, timeout=1) as ser:
    while True:
        line = ser.readline()
        if line:
            print(line.decode(errors="replace").rstrip())
