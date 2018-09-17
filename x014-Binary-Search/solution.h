#ifndef LEET_CODE_BINARY_SEARCH__
#define LEET_CODE_BINARY_SEARCH__ 

#include <vector>
using std::vector;

class Solution {
public:
    int binarySearch(const vector<int>& data, const int needle) {
        if (data.empty()) return -1;
        int begin = 0;
        int end = data.size() - 1;
        int mid;
        
        while (begin <= end) {
            mid = begin + (end - begin) / 2;
            if (data[mid] == needle) {
                return mid;
            } else if (data[mid] < needle) {
                begin = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return -1;
    }
};
#endif /* ifndef LEET_CODE_KNIGHT_TOUR_H__ */
