#include <cstdint>
#include <vector>

uint8_t crc8(const std::vector<uint8_t>& data) {
    uint8_t crc = 0;
    for (uint8_t b : data) {
        crc ^= b;
        for (int i = 0; i < 8; ++i) {
            crc = (crc & 0x80) ? static_cast<uint8_t>((crc << 1) ^ 0x07) : static_cast<uint8_t>(crc << 1);
        }
    }
    return crc;
}
