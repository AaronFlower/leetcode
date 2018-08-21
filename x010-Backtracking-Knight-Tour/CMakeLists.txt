include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})


add_executable(testx010 test.cpp solution.h)
target_link_libraries(testx010 gtest_main gmock_main)
add_test(LeetCode-x010 testx010)
