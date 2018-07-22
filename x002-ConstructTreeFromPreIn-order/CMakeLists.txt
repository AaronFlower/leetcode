set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

add_executable(testX002 test.cpp solution.h)
target_link_libraries(testX002 gtest_main gmock_main)
add_test(x-002 testX002)

