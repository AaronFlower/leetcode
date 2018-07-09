set (CMAKE_EXPORT_COMPILE_COMMANDS ON)
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

add_executable(test061 test.cpp solution.h)
target_link_libraries(test061 gtest_main gmock_main)
add_test(LeetCode-061 test061)
