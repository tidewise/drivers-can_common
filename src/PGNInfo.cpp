#include <can_common/PGNInfo.hpp>

using namespace can_common;


bool PGNInfo::isFastPacket() const {
    return size > 8;
}