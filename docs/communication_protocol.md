# Communication Protocol

Current binary packet format:

| Field | Size | Description |
|---|---:|---|
| Start byte | 1 | `0xAA` |
| Message ID | 1 | Command or telemetry type |
| Payload length | 1 | Number of payload bytes |
| Payload | N | Message data |
| CRC8 | 1 | CRC over all previous bytes |

Planned commands:

- `SET_POSITION`
- `SET_VELOCITY`
- `ENABLE_MOTOR`
- `DISABLE_MOTOR`
- `READ_TELEMETRY`
- `CLEAR_FAULTS`
