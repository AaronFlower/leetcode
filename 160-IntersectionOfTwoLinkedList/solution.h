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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (!headA || !headB) return nullptr;

        /*
        * ListA = A + intersection;
        * ListB = B + intersection;
        * pA = ListA + ListB = (A + intersection + B) + intersection;
        * PB = ListB + ListA = (B + intersection + A) + intersection;
        * So, we will get the second intersection.
        */

        ListNode* pA = headA, *pB = headB;
        while(pA && pB && pA != pB) {
            pA = pA->next;
            pB = pB->next;

            if (pA == pB) return pA;

            if (!pA) pA = headB;
            if (!pB) pB = headA;
        }
        return pA;
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

