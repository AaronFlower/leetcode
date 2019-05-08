#ifndef LEETCODE_SOLUTION_H__
#define LEETCODE_SOLUTION_H__

#include <vector>

using std::vector;

class Solution {
public:
    struct subset {
        int parent;
        int rank;
        subset() = default;
        subset(int p, int r):parent(p), rank(r) {}
    };

    using vi = vector<int>;

    int findCircleNum(vector<vector<int>>& M) {
        size_t n = M.size();
        int count = 0;

        vector<subset> sets;
        for (size_t i = 0; i < n; ++i) {
            sets.push_back(subset(i, 0));
        }

        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < i; ++j) {
                if (M[i][j] == 1) {

                    // find
                    int x = find(sets, i);
                    int y = find(sets, j);

                    // union
                    unionSet(sets, x, y);
                }
            }
        }

        for (size_t i = 0; i < n; ++i) {
            if (sets[i].parent == (int)i) ++count;
        }

        return count;
    }

private:
    int find(vector<subset> &sets, int i) {
        if (sets[i].parent != i) {
            sets[i].parent = find(sets, sets[i].parent);
        }
        return sets[i].parent;
    }

    void unionSet(vector<subset> &sets, int x, int y) {
        if (sets[x].rank < sets[y].rank) {
            sets[x].parent = y;
        } else if (sets[x].rank > sets[y].rank) {
            sets[y].parent = x;
        } else {
            sets[y].parent = x;
            sets[x].rank++;
        }
    }
};

#endif
