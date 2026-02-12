#ifndef CAN_COMMON_PGN_MESSAGE_HPP
#define CAN_COMMON_PGN_MESSAGE_HPP

#include <base/Time.hpp>
#include <canbus/Message.hpp>

namespace can_common {
    /** A PGN message */
    struct PGNMessage {
        static const int MAX_PAYLOAD_LENGTH = 1785;
        static const int NO_DESTINATION = 0xFF;

        base::Time time;

        uint8_t priority = 0;
        uint8_t source = 0;
        uint8_t destination = 0;
        uint32_t pgn = 0;
        uint8_t size = 0;
        uint8_t payload[MAX_PAYLOAD_LENGTH];

        canbus::Message toCAN() const;
        static PGNMessage fromCAN(canbus::Message const& can);

        bool operator == (PGNMessage const& other) const;
    };
}

#endif