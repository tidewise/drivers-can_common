rock_library(can_common
    SOURCES Dummy.cpp
    HEADERS Dummy.hpp)

rock_executable(can_common_bin Main.cpp
    DEPS can_common)

