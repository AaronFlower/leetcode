#ifndef LEET_KNAPSACK_SORT__
#define LEET_KNAPSACK_SORT__

#include <vector>
#include <algorithm>
#include <iostream>
using std::vector;
using std::max;

using std::cout;

class Solution {
public:
    int knapSack(int vals[], int weights[], int len, int capacity) {
        int m[len + 1][capacity + 1];
        int i, n;

        for (i = 0; i <= len; ++i) {
            m[i][0] = 0;
        }

        for (i = 0; i <= capacity; ++i) {
            m[0][i] = 0;
        }


        for (i = 1; i <= len; ++i) {
            int curVal = vals[i - 1];
            int curWeight = weights[i - 1];
            for (n = 1; n <= capacity; ++n) {
                if (n >= curWeight) {
                    m[i][n] = max(curVal + m[i - 1][n - curWeight], m[i - 1][n]);
                } else {
                    m[i][n] = m[i - 1][n];
                }
            }
        }

        for (i = 0; i <= len; ++i) {
            for (n = 0; n <= capacity; ++n) {
                std::cout << m[i][n] << "\t";
            }
            std::cout<< std:: endl;
        }

        return m[len][capacity];
    }
};
#endif
