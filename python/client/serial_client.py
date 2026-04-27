class SerialClient:
    """Thin wrapper around pyserial. Placeholder until hardware transport is wired."""

    def __init__(self, port: str, baudrate: int = 115200):
        self.port = port
        self.baudrate = baudrate
        self._serial = None

    def connect(self):
        import serial
        self._serial = serial.Serial(self.port, self.baudrate, timeout=1)

    def write(self, data: bytes):
        if self._serial is None:
            raise RuntimeError("Serial port is not connected")
        self._serial.write(data)

    def read(self, n: int) -> bytes:
        if self._serial is None:
            raise RuntimeError("Serial port is not connected")
        return self._serial.read(n)
