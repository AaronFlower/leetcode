include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})


add_executable(testx020 test.cpp string_search.c string_search.h)
target_link_libraries(testx020 gtest_main gmock_main)
add_test(LeetCode-x020 testx020)
