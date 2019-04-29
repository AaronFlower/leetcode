#ifndef WINDOW_SLIDING_MAX_SUB_SUM__
#define WINDOW_SLIDING_MAX_SUB_SUM__

#include <cstdlib>
#include <cassert>

using namespace std;

class Solution {
    public:
        long maxSubSumBrutal(int *data, size_t len, size_t k) {
            assert(k <= len);

            long maxSum = 0;
            long tmpSum = 0;

            size_t i = 0;
            while (i <= len - k) {
                tmpSum = 0;
                for (size_t j = 0; j < k; ++j) {
                    tmpSum += data[i + j];
                }
                maxSum = maxSum < tmpSum ? tmpSum : maxSum;
                ++i;
            }

            return maxSum;
        }

        long maxSubWindowSliding(int *data, size_t len, size_t k)
        {
            assert(k <= len);
            long maxSum = 0;
            long tmpSum = 0;
            for (size_t i = 0; i < k; ++i) {
                tmpSum += data[i];
            }
            maxSum = tmpSum;

            for (size_t i = 1; i < len - k + 1; ++i) {
                tmpSum = tmpSum - data[i - 1] + data[i - 1 + k];
                maxSum = maxSum > tmpSum ? maxSum : tmpSum;
            }
            return maxSum;
        }
};
#endif /* ifndef WINDOW_SLIDING_MAX_SUB_SUM__ */
