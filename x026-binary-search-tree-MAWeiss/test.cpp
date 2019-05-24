#include "gtest/gtest.h"
#include "solution.h"


TEST(SearchTree, ADT) {
    searchTree t;

    EXPECT_EQ(t.find(1), nullptr);
    EXPECT_EQ(t.findMax(), nullptr);
    EXPECT_EQ(t.findMin(), nullptr);

    t.insertElement(6);
    EXPECT_EQ(t.findMax()->val, 6);
    EXPECT_EQ(t.findMin()->val, 6);

    t.insertElement(2);
    t.insertElement(8);
    t.insertElement(1);
    t.insertElement(4);
    t.insertElement(3);
    auto res = t.printTree();

    EXPECT_EQ(res.size(), 6);
    for (auto record : res) {
        std::cout << record;
    }
}
