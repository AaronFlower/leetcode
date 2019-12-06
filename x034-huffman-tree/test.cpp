#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "huffman.h"

#include <iostream>

TEST(test, INIT) {
    std::cout << "Hello x034-huffman-tree" << std::endl;
    vector<freq> freqs{
            {'a', 12},
            {'b', 2},
            {'c', 7},
            {'d', 13},
            {'e', 14},
            {'f', 85},
    };

    Huffman h;
    h.build(freqs);
    h.printTree();
}
