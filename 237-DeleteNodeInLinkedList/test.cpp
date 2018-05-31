#include "gtest/gtest.h"
#include "solution.h"

#include <vector>

using std::vector;
using std::cout;
using std::endl;

TEST(DeleteNodeInLinkedList, ByCopy) {
    Solution s;
    ListNode* list;
    s.createLinkList(list, {1, 2, 3});
    EXPECT_EQ(1, list->val);
    EXPECT_EQ(2, list->next->val);
    EXPECT_EQ(3, list->next->next->val);
    EXPECT_EQ(nullptr, list->next->next->next);

    s.deleteNode(list->next);
    EXPECT_EQ(1, list->val);
    EXPECT_EQ(3, list->next->val);
    EXPECT_EQ(nullptr, list->next->next);


    ListNode *p = list;
    ListNode *pn;
    while(p) {
        pn = p;
        p = p->next;
        delete pn;
    }
}
