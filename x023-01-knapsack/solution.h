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
        int keep[len + 1][capacity + 1];            // keep to tracks the path.
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
                if (n >= curWeight && curVal + m[i - 1][n - curWeight] >  m[i - 1][n]) {
                    m[i][n] = curVal + m[i - 1][n - curWeight];
                    keep[i][n] = 1;
                } else {
                    m[i][n] = m[i - 1][n];
                    keep[i][n] = 0;
                }
            }
        }

        for (i = 0; i <= len; ++i) {
            for (n = 0; n <= capacity; ++n) {
                std::cout << m[i][n] << "\t";
            }
            std::cout<< std:: endl;
        }


        int K = capacity;
        for (i = len; i >= 1; --i) {
            if (keep[i][K] == 1) {
               std::cout << " (" << weights[i - 1] << "," <<  vals[i - 1] << ")";
               K = K - weights[i - 1];
            }
        }
        std::cout << std::endl;
        return m[len][capacity];
    }
};
#endif
