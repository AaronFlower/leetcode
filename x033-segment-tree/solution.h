#ifndef MY_SOLUTION__
#define MY_SOLUTION__

#define LEFT(i)  2*(i)+1
#define RIGHT(i) 2*(i)+2

#include <vector>
#include <cassert>

using std::vector;

class SegmentTree {
private:
    int n_leaves;
    int *tree;
    vector<int> data;

public:
    SegmentTree():tree(nullptr), n_leaves(0){}
    ~SegmentTree() {
        if (tree) {
            delete []tree;
        }
    }

    void build(vector<int> nums) {
        data = nums;
        n_leaves = data.size();
        if (n_leaves == 0) return;
        tree = new int[n_leaves];
        tree[0] = buildTree(0, 0, n_leaves - 1);
    }

    int sum(int begin, int end) {
        assert(begin >= 0 && end <= n_leaves && begin <= end);
        return segSum(0, 0, n_leaves - 1, begin, end);
    }

    void update(int idx, int val) {
        assert(idx >= 0 && idx < n_leaves);

        int diff = val - data[idx];
        data[idx] = val;
        updateTree(0, 0, n_leaves - 1, idx, diff);
    }

private:
    void updateTree(int root, int begin, int end, int idx, int diff) {
        if (idx < begin || idx > end) {
            return;
        }
        tree[root] += diff;
        if (begin < end) {
            int mid = (begin + end) >> 1;
            int l = LEFT(root);
            int r= RIGHT(root);
            updateTree(l, begin, mid, idx, diff);
            updateTree(r, mid + 1,end, idx, diff);
        }
    }

    int segSum(int root, int r_begin, int r_end, int q_begin, int q_end) {
        if (r_begin >= q_begin && r_end <= q_end) {
            return tree[root];
        }
        if (r_end < q_begin || r_begin > q_end) {
            return 0;
        }
        int mid = (r_begin + r_end) >> 1;
        int l = LEFT(root);
        int r = RIGHT(root);
        return segSum(l, r_begin, mid, q_begin, q_end) + segSum(r, mid + 1, r_end, q_begin, q_end);
    }

    int buildTree(int root, int begin, int end) {
        if (begin >= end) {
            return data[begin];
        }
        int mid = (begin + end) >> 1;
        int l = LEFT(root);
        int r = RIGHT(root);
        tree[l] = buildTree(l, begin, mid);
        tree[r] = buildTree(r, mid + 1, end);
        return tree[l] + tree[r];
    }
};
#endif /* ifndef MY_SOLUTION__ */
