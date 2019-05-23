#ifndef LEET_KNAPSACK_SORT__
#define LEET_KNAPSACK_SORT__

#include <cassert>

class Solution {
public:
    long long pow(int x, int n) {
        assert(n >= 0);
        long long res = 1;
        while (n) {
            if (n & 1) {
                res = res * x;
            }
            x = x * x;
            x = x >> 1;
        }
        return res;
    }
};
#endif
