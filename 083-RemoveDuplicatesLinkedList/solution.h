#ifndef LEETCODE_SOLUTION_H__
#define LEETCODE_SOLUTION_H__ 

#include <vector>
#include <stack>

using std::vector;
using std::stack;

struct ListNode {
    int val;
    ListNode * next;
    ListNode (int v) : val(v), next(nullptr) {}
};

using LinkList = ListNode *;

class Solution {
public:
    ListNode* removeDuplicates(ListNode* head) {
        ListNode* p = head;
        ListNode* tmp;
        while (p && p->next) {
            if (p->val == p->next->val) {
                tmp = p->next;
                p->next = p->next->next;
                delete tmp;
            } else {
                p = p->next;
            }
        }
        return head;
    }

    void vectorToLinkList(ListNode* &head, vector<int> data) {
        ListNode *p;
        head = nullptr;

        for (auto v: data) {
            if (head == nullptr) {
                head = new ListNode(v);
                p = head;
            } else {
                p->next = new ListNode(v);
                p = p->next;
            }
        }
    }
};

#endif

