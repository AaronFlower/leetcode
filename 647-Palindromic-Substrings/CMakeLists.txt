set(CMAKE_EXPORT_COMPILE_COMMANDS ON )

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_test_SOURCE_DIR})

add_executable(test647 test.cpp solution.h)
target_link_libraries(test647 gtest_main gmock_main) 
add_test(LeetCode-647 test647)

