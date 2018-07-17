#include <vector>

using std::vector;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int v):val(v),next(nullptr){}
};


class Solution {
    public:
        using LinkList = ListNode*;
        void createList(LinkList &list, vector<int> data){
            ListNode dummyHead(-1);
            ListNode* tail = &dummyHead;
            for(auto v : data) {
                ListNode *node = new ListNode(v);
                node->next = tail->next; 
                tail->next = node;
                tail = node;
            }
            list = dummyHead.next;
        }

        LinkList reverse(LinkList list) {
            if (!list) return nullptr;
            ListNode dummyHead(-1);
            ListNode *p = list;
            while (p) {
                ListNode * tmp = p->next;
                p->next = dummyHead.next;
                dummyHead.next = p;
                p = tmp;
            }
            return dummyHead.next;
        }

        LinkList reverseBetween(LinkList list, int m, int n) {
            if (m >= n) return list;
            n -=m;

            ListNode dummyHead(-1);
            dummyHead.next = list;

            ListNode *anchor, *preCur, *cursor, *curNext;
            anchor = &dummyHead;

            while(--m) anchor = anchor->next;
            preCur = anchor->next;
            cursor = preCur->next;

            while(n--) {
                curNext = cursor->next;
                cursor->next = anchor->next;
                anchor->next = cursor;
                preCur->next = curNext;
                cursor = curNext;
            }
            return dummyHead.next;
        }
};


