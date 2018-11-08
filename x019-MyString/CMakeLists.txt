include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})


add_executable(testx019 test.cpp mystring.cpp mystring.h)
target_link_libraries(testx019 gtest_main gmock_main)
add_test(LeetCode-x019 testx019)
