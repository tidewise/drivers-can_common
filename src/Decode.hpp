#ifndef CAN_COMMON_DECODE_HPP
#define CAN_COMMON_DECODE_HPP

#include <algorithm>
#include <cstdint>
#include <string>

namespace can_common {
    namespace decode {
        inline std::uint64_t decode64(std::uint8_t const* byte);
        inline std::uint32_t decode32(std::uint8_t const* byte);
        inline std::uint16_t decode16(std::uint8_t const* byte);
        inline std::uint8_t decode8(std::uint8_t const* byte);
        inline std::string decodeString(std::uint8_t const* byte, int length);
    };
}

#endif