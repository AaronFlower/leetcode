#include "gtest/gtest.h"
#include "solution.h"

TEST(LinkList, create) {
    Solution s;
    Solution::List list;
    vector<int> data{1, 2, 3};
    
    s.createList(list, data);
    EXPECT_EQ(list->val, 1); 
    EXPECT_EQ(list->next->val, 2); 
    EXPECT_EQ(list->next->next->val, 3); 
    EXPECT_EQ(list->next->next->next, nullptr); 
}

TEST(LinkList, reverseAList) {
    Solution s;
    Solution::List list;
    vector<int> data{1, 2, 3};
    
    s.createList(list, data);
    Solution::List rlist = s.reverse(list);
    EXPECT_EQ(rlist->val, 3); 
    EXPECT_EQ(rlist->next->val, 2); 
    EXPECT_EQ(rlist->next->next->val, 1); 
    EXPECT_EQ(rlist->next->next->next, nullptr); 
}
