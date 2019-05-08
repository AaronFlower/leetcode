#ifndef LEET_CODE_PRIORITY_QUEUE__
#define LEET_CODE_PRIORITY_QUEUE__

#define PARENT(i)   (((i) - 1) >> 1)
#define LEFT(i)     (((i) << 1) + 1)
#define RIGHT(i)    (((i) << 1) + 2)

#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::swap;

class PriorityQueue
{
typedef bool (*compare)(const int &, const int &);

public:
    PriorityQueue () = default;
    PriorityQueue (compare cmper):cmp(cmper){}
    virtual ~PriorityQueue () = default;

    int top() {
        if (empty()) {
            throw std::out_of_range("The queue has no element");
        }
        return q[0];
    }

    bool empty() {
        return q.size() == 0;
    }

    void push(int n) {
        q.push_back(n);
        int i = q.size() - 1;
        heapify_up(i);
    }

    int pop() {
        if (empty()) {
            throw std::out_of_range("The queue has no element");
        }
        int top = q[0];
        q[0] = q.back();
        q.pop_back();
        heapify_down(0);
        return top;
    }

private:
    static bool less(const int &a, const int &b) {
        return a < b;
    }
    compare cmp = less;
    vector<int> q;


    void heapify_up(int i) {
        if (i == 0) return;
        int p = PARENT(i);
        if (cmp(q[p], q[i])) return;
        swap(q[p], q[i]);
        heapify_up(p);
    }

    void heapify_down(int i) {
        size_t l = LEFT(i);
        size_t r = RIGHT(i);

        size_t v = i;

        if (l < q.size() && cmp(q[l], q[v])) {
            v = l;
        }

        if (r < q.size() && cmp(q[r], q[v])) {
            v = r;
        }

        if ((int)v == i) return;
        swap(q[v], q[i]);
        heapify_down(v);
    }
};
#endif /* ifndef LEET_CODE_PRIORITY_QUEUE__ */
