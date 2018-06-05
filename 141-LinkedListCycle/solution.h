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
    bool hasCycle(ListNode* head) {
        ListNode *walker, *runner;
        walker = runner = head;

        while (walker && runner && walker->next && runner->next && runner->next->next) {
            walker = walker->next;
            runner = runner->next->next;
            if (walker == runner) return true;
        }
        return false;
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

