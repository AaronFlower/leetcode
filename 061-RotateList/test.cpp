#include "gtest/gtest.h"
#include "solution.h"

void checkListEqual (ListNode* list, vector<int> data) {
    int i = 0;
    ListNode * p = list;

    while (p) {
        EXPECT_EQ(p->val, data[i++]);
        p = p->next;
    }
    EXPECT_EQ(i, data.size());
}


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
    checkListEqual(list, data);

    Solution::List rlist = s.reverse(list);
    std::reverse(std::begin(data), std::end(data));
    checkListEqual(rlist, data);
}

TEST(LinkList, rotateList) {
    Solution s;
    Solution::List list;
    vector<int> data{1, 2, 3};
    
    s.createList(list, data);
    Solution::List rlist = s.rotateList(list, 2);
    vector<int> rdata{2, 3, 1};
    checkListEqual(rlist, rdata);

    s.createList(list, {1, 2, 3, 4, 5}); 
    checkListEqual(s.rotateList(list, 2), {4, 5, 1, 2, 3});

    s.createList(list, {0, 1, 2}); 
    checkListEqual(s.rotateList(list, 4), {2, 0, 1});
}
