#pragma once
#include <cstdint>
#include <vector>

struct Packet {
    uint8_t message_id;
    std::vector<uint8_t> payload;
};

std::vector<uint8_t> serialize_packet(const Packet& packet);
bool parse_packet(const std::vector<uint8_t>& bytes, Packet& packet);
