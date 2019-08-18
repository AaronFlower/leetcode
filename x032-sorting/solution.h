#ifndef LEET_CODE_HEAP_SORT__
#define LEET_CODE_HEAP_SORT__

#define LEFT(i) (((i)<<1) + 1)
#define RIGHT(i) (((i)<<1) + 2)
#define PARENT(i) ((i)>>1)

#include <algorithm>
#include <vector>

using std::vector;
using std::swap;

class Solution {
public:
    Solution () {
        compare = less;
    }
    Solution(bool (*comp)(const int &, const int &)): compare(comp) {}

    void heapify(int *arr, int len, int i) {
        int left = LEFT(i);
        int right = RIGHT(i);
        int m = i;

        if (left < len && compare(arr[left], arr[m])) {
            m = left;
        }

        if (right < len && compare(arr[right], arr[m])) {
            m = right;
        }

        if (m == i) {
            return;
        }
        std::swap(arr[i], arr[m]);
        heapify(arr, len, m);
    }

    void heapSort(int *arr, int len) {
        int lp = (len / 2) - 1;
        for (; lp >= 0; --lp) {
            heapify(arr, len, lp);
        }

        for (int i = len - 1; i > 0; --i) {
            std::swap(arr[i], arr[0]);
            heapify(arr, i, 0);
        }
    }

    /**
     * merge sort
     */
    void mergeSort(vector<int>& nums, int begin, int end) {
        if (end - begin < 1) return;
        int mid = (end + begin) >> 1;
        mergeSort(nums, begin, mid);
        mergeSort(nums, mid + 1, end);
        merge(nums, begin, mid, end);
    }

    static bool less(const int &a,const int &b) {
        return a < b;
    }
private:
    bool (*compare)(const int &, const int &);

public:
    void merge(vector<int> &nums, int lbegin, int mid, int rend) {
        int i = lbegin, j = mid + 1;
        if (nums[mid] < nums[mid + 1]) return;
        while (i <= mid && j <= rend) {
            if (nums[i] <= nums[j]) {
                ++i;

            } else {
                int idx = j;
                int value = nums[idx];
                while (idx > i) {
                    nums[idx] = nums[idx - 1];
                    --idx;
                }
                nums[i] = value;

                ++i;
                ++j;
                ++mid;
            }
        }
    }
};
#endif /* ifndef LEET_CODE_KNIGHT_TOUR_H__ */
