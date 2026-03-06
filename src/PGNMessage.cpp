#include <can_common/PGNMessage.hpp>
#include <cstring>

using namespace can_common;

canbus::Message PGNMessage::toCAN() const {
    canbus::Message can;

    can.time = time;
    can.size = size;
    std::memcpy(can.data, payload, size);

    uint32_t can_id =
        source |
        (priority & 0x7) << 26 |
        pgn << 8;

    bool pdu2 = 0xF000 == (pgn & 0xF000);
    if (!pdu2) {
        can_id |= (static_cast<uint32_t>(destination) << 8);
    }
    can.can_id = can_id | canbus::FLAG_EXTENDED_FRAME;
    return can;
}

PGNMessage PGNMessage::fromCAN(canbus::Message const& can) {
    PGNMessage message;

    message.time = can.time;
    message.size = can.size;
    std::memcpy(message.payload, can.data, can.size);
    message.source   = can.can_id & 0xFF;
    message.priority = (can.can_id >> 26) & 0x7;
    uint32_t pgn = (can.can_id >> 8) & 0x3FFFF;

    bool pdu2 = 0xF000 == (pgn & 0xF000);
    if (pdu2) {
        // PDU2 format
        message.destination = NO_DESTINATION;
        message.pgn = pgn;
    }
    else {
        // PDU1 format
        message.destination = pgn & 0xFF;
        message.pgn = pgn & 0x3FF00;
    }
    return message;
}

bool PGNMessage::operator == (PGNMessage const& other) const {
    return time == other.time &&
        priority == other.priority &&
        source == other.source &&
        destination == other.destination &&
        pgn == other.pgn &&
        size == other.size &&
        std::memcmp(payload, other.payload, size) == 0;
}