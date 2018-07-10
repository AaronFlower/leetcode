#include <vector>

using std::vector;

struct ListNode {
    int val;
    ListNode *next;
    ListNode (int x) : val(x), next(nullptr){}
};

class Solution {
    public:
        using List = ListNode*;
        void createList(List & list, vector<int> data) {
            ListNode head(-1);
            ListNode *tail = &head;
            for (auto v:data) {
                ListNode* node = new ListNode(v);
                node->next = tail->next;
                tail->next = node;
                tail = node;
            }
            list = head.next;
        }

        List reverse(List & list) {
            ListNode head(-1);
            ListNode *tmp;
            List p = list;
            while (p) {
                tmp = p->next;
                p->next = head.next;
                head.next = p;
                p = tmp;
            }

            return head.next;
        }

        ListNode * rotateList(ListNode *head, int k) {
            if (!head) return head;
            
            int len = 1;
            ListNode* tail = head;
            while (tail->next) {
                ++len;
                tail = tail->next;
            }

            tail->next = head;

            if (k % len) {
                int remain = len - (k % len);
                for (int i = 0; i < remain; ++i) {
                    tail = tail->next;
                }
            }

            ListNode *newHead = tail->next;
            tail->next = nullptr;
            return newHead;
        }
};
