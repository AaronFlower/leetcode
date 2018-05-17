#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "solution.h"

using testing::ElementsAre;

TEST(TwoSum, BruteForce) {
    Solution s;
    ListNode *l1 = NULL;
    ListNode *l2 = NULL;
    ListNode *l3 = s.addTwoNumbers(l1, l2);
    EXPECT_EQ((l3 == NULL), true);

/* // [2,4,3] */
/* [5,6,4] */
    /* [7,0,8] */
    // [5] 
    // [5]
    // [0, 1]
}
