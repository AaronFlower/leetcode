include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

add_executable(testx034Huffman test.cpp huffman.h)
target_link_libraries(testx034Huffman gtest_main gmock_main)
