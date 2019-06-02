include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})


add_executable(testx029 test.cpp solution.h)
target_link_libraries(testx029 gtest_main gmock_main)
add_test(LeetCode-x029 testx029)
