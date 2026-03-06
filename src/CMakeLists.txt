rock_library(can_common
    SOURCES PGNLibrary.cpp PGNInfo.cpp PGNMessage.cpp
    HEADERS PGNLibrary.hpp PGNInfo.hpp PGNMessage.hpp Decode.hpp
    DEPS_PKGCONFIG canbus base-types)

