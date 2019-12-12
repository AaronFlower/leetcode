include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

add_executable(x035-skip-list test.cpp skiplist.h)
target_link_libraries(x035-skip-list gtest_main gmock_main)



