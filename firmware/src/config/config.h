#pragma once

namespace config {
constexpr float CONTROL_HZ = 1000.0f;
constexpr float DT_SECONDS = 1.0f / CONTROL_HZ;
constexpr float DEFAULT_KP = 8.0f;
constexpr float DEFAULT_KI = 0.2f;
constexpr float DEFAULT_KD = 0.05f;
}
