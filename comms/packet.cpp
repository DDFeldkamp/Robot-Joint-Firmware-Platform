#include "packet.h"
#include <cstddef>

uint8_t crc8(const std::vector<uint8_t>& data);

std::vector<uint8_t> serialize_packet(const Packet& packet) {
    std::vector<uint8_t> bytes;
    bytes.push_back(0xAA);
    bytes.push_back(packet.message_id);
    bytes.push_back(static_cast<uint8_t>(packet.payload.size()));
    bytes.insert(bytes.end(), packet.payload.begin(), packet.payload.end());
    bytes.push_back(crc8(bytes));
    return bytes;
}

bool parse_packet(const std::vector<uint8_t>& bytes, Packet& packet) {
    if (bytes.size() < 4 || bytes[0] != 0xAA) return false;
    const auto payload_len = static_cast<size_t>(bytes[2]);
    if (bytes.size() != payload_len + 4) return false;

    std::vector<uint8_t> without_crc(bytes.begin(), bytes.end() - 1);
    if (crc8(without_crc) != bytes.back()) return false;

    packet.message_id = bytes[1];
    packet.payload.assign(bytes.begin() + 3, bytes.end() - 1);
    return true;
}
