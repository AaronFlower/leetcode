#ifndef LEET_CODE_RADIX_SORT__
#define LEET_CODE_RADIX_SORT__

#include <vector>

using std::vector;

class Solution {
public:
    void radixSort(vector<int> &data) {
        if (data.size() == 0) return;
        int max = getMax(data);
        for (int exp = 1; max / exp > 1; exp *=  10) {
            radixSort(data, exp);
        }
        return;
    }

private:
    int getMax(vector<int> &data) {
        int max = data[0];
        for (size_t i = 1; i < data.size(); ++i) {
            max = max < data[i] ? data[i] : max;
        }
        return max;
    }

    void radixSort(vector<int> &data, int exp) {
        int i, index, count[10] = {0};
        int len = data.size();
        for (i = 0; i < len; ++i) {
            index = (data[i] / exp) % 10;
            count[index]++;
        }

        // 这里循环从 1 开始，下面的循环从 len - 1 逆序就方便多了。
        for (i = 1; i <= 9; ++i) {
            count[i] += count[i - 1];
        }

        vector<int> tmp(len);
        for (i = len - 1; i >= 0; --i) {
            index = --count[(data[i] / exp) % 10];
            tmp[index] = data[i];
        }

        for (i = 0; i < len; ++i) {
            data[i] = tmp[i];
        }
    }
};
#endif /* ifndef LEET_CODE_KNIGHT_TOUR_H__ */
