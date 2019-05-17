include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})


add_executable(testx018 test.cpp solution.h)
target_link_libraries(testx018 gtest_main gmock_main)
add_test(LeetCode-x018 testx018)
