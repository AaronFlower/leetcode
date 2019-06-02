#include "gtest/gtest.h"
#include "solution.h"

#include <iostream>

TEST(Solution, Division_by_sub1) {
    Solution s;

    int quotient, remainder;
    s.division_by_sub1(7, 3, quotient, remainder);
    EXPECT_EQ(quotient, 7 / 3);
    EXPECT_EQ(remainder, 7 % 3);

    s.division_by_sub1(3, 3, quotient, remainder);
    EXPECT_EQ(quotient, 3 / 3);
    EXPECT_EQ(remainder, 3 % 3);

    s.division_by_sub1(3, 7, quotient, remainder);
    EXPECT_EQ(quotient, 3 / 7);
    EXPECT_EQ(remainder, 3 % 7);

    s.division_by_sub1(1, 7, quotient, remainder);
    EXPECT_EQ(quotient, 1 / 7);
    EXPECT_EQ(remainder, 1 % 7);

    s.division_by_sub1(7, 1, quotient, remainder);
    EXPECT_EQ(quotient, 7 / 1);
    EXPECT_EQ(remainder, 7 % 1);
}

TEST(Solution, Division_by_sub2) {
    Solution s;

    int quotient, remainder;
    s.division_by_sub2(7, 3, quotient, remainder);
    EXPECT_EQ(quotient, 7 / 3);
    EXPECT_EQ(remainder, 7 % 3);

    s.division_by_sub2(3, 3, quotient, remainder);
    EXPECT_EQ(quotient, 3 / 3);
    EXPECT_EQ(remainder, 3 % 3);

    s.division_by_sub2(3, 7, quotient, remainder);
    EXPECT_EQ(quotient, 3 / 7);
    EXPECT_EQ(remainder, 3 % 7);

    s.division_by_sub2(1, 7, quotient, remainder);
    EXPECT_EQ(quotient, 1 / 7);
    EXPECT_EQ(remainder, 1 % 7);

    s.division_by_sub2(7, 1, quotient, remainder);
    EXPECT_EQ(quotient, 7 / 1);
    EXPECT_EQ(remainder, 7 % 1);
}

TEST(Solution, Division_by_left_shift) {
    Solution s;

    int quotient, remainder;
    s.division_by_left_shift(7, 3, quotient, remainder);
    EXPECT_EQ(quotient, 7 / 3);
    EXPECT_EQ(remainder, 7 % 3);

    s.division_by_left_shift(3, 3, quotient, remainder);
    EXPECT_EQ(quotient, 3 / 3);
    EXPECT_EQ(remainder, 3 % 3);

    s.division_by_left_shift(3, 7, quotient, remainder);
    EXPECT_EQ(quotient, 3 / 7);
    EXPECT_EQ(remainder, 3 % 7);

    s.division_by_left_shift(1, 7, quotient, remainder);
    EXPECT_EQ(quotient, 1 / 7);
    EXPECT_EQ(remainder, 1 % 7);

    s.division_by_left_shift(7, 1, quotient, remainder);
    EXPECT_EQ(quotient, 7 / 1);
    EXPECT_EQ(remainder, 7 % 1);

    s.division_by_left_shift(2147483647, 57, quotient, remainder);
    EXPECT_EQ(quotient, 2147483647 / 57);
    EXPECT_EQ(remainder, 2147483647 % 57);
}
