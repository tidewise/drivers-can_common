#ifndef CAN_COMMON_PGNINFO_HPP
#define CAN_COMMON_PGNINFO_HPP

#include <cstdint>

namespace can_common {
    struct PGNInfo {
        uint32_t pgn;
        uint16_t size;

        bool isFastPacket() const;
    };
}

#endif