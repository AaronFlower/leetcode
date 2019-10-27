#include "gtest/gtest.h"
#include "solution.h"

TEST(FBT, create) {
    Solution s;

    EXPECT_EQ(true, s.divideGame(2));
    EXPECT_EQ(true, s.divideGame(1024));
    EXPECT_EQ(false, s.divideGame(1023));
    EXPECT_EQ(false, s.divideGame(7));

    EXPECT_EQ(true, s.divideGameDP(2));
    EXPECT_EQ(true, s.divideGameDP(1024));
    EXPECT_EQ(false, s.divideGameDP(1023));
    EXPECT_EQ(false, s.divideGameDP(7));
}
