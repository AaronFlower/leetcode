#ifndef LEETCODE_SOLUTION_H__
#define LEETCODE_SOLUTION_H__ 

#include <vector>
#include <climits>
using std::vector;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v):val(v), next(nullptr){}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(INT_MIN);
        ListNode* tail = &dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }

    void createLinkList(ListNode* & list,  vector<int> data) {
        ListNode *p;
        list = nullptr;
        for (auto val : data) {
            if (list == nullptr) {
                list = new ListNode(val);
                p = list;
            } else {
                p->next = new ListNode(val);
                p = p->next;
            } 
        }
    }

    void destroyLinkList(ListNode* list) {
        destroy(list);
    }
private:
    void destroy(ListNode* list) {
        if (list->next) {
            destroy(list->next);
        }
        delete list;
    }
};
#endif

