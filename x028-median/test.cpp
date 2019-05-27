#include "gtest/gtest.h"
#include "solution.h"

#include <iostream>

TEST(Solution, Initialization) {
    Solution s;

    try {
        s.median();
    }catch(std::out_of_range &e) {
        std::cout << "Out of range";
    }
}

TEST(Solution, Ascending) {
    Solution s;
    s.insert(1);
    EXPECT_EQ(s.median(), 1);
    EXPECT_EQ(s.median(), 1);

    s.insert(2);
    EXPECT_EQ(s.median(), 1.5);
    EXPECT_EQ(s.median(), 1.5);

    s.insert(3);
    EXPECT_EQ(s.median(), 2);

    s.insert(4);
    EXPECT_EQ(s.median(), 2.5);
}


TEST(Solution, Descening) {
    Solution s;

    s.insert(9);
    EXPECT_EQ(s.median(), 9);

    s.insert(8);
    EXPECT_EQ(s.median(), 8.5);

    s.insert(7);
    EXPECT_EQ(s.median(), 8);

    s.insert(6);
    EXPECT_EQ(s.median(), 7.5);
}


TEST(Solution, MixOrder) {
    Solution s;

    s.insert(1);
    s.insert(0);
    s.insert(4);
    s.insert(3);
    s.insert(9);
    s.insert(12);
    s.insert(8);
    s.insert(15);
    s.insert(2);

    /* 0, 1, 2, 3, 4, 8, 9, 12, 15 */
    EXPECT_EQ(s.median(), 4);

    s.insert(-1);
    /* -1, 0, 1, 2, 3, 4, 8, 9, 12, 15 */
    EXPECT_EQ(s.median(), 3.5);
}
