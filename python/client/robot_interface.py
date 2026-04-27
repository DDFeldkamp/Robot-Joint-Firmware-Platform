from serial_client import SerialClient

class RobotInterface:
    """High-level command API for the joint controller."""

    def __init__(self, port: str, baudrate: int = 115200):
        self.client = SerialClient(port, baudrate)

    def connect(self):
        self.client.connect()

    def set_position(self, position_rad: float):
        # TODO: serialize with comms packet format.
        payload = f"SET_POS {position_rad:.6f}\n".encode()
        self.client.write(payload)

    def read_telemetry(self):
        # TODO: parse binary telemetry packets.
        return self.client.read(128)
