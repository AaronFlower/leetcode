set(CMAKE_EXPORT_COMPILE_COMMANDS ON )

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_test_SOURCE_DIR})

add_executable(testx006 test.cpp solution.h)
target_link_libraries(testx006 gtest_main gmock_main) 
add_test(LeetCode-x006 testx006)

