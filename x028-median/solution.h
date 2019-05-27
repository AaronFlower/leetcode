#ifndef LEET_KNAPSACK_SORT__
#define LEET_KNAPSACK_SORT__

#include <set>

using std::set;
using std::next;

class Solution {

public:
    Solution():mp(s.end()) {}

    double median() {
        if (s.empty()) {
            throw std::out_of_range("The set is empty!");
        }

        if (isEven()) {
            return (*mp + *next(mp)) / 2.0;
        } else {
            return *mp;
        }
    }

    void insert(int x) {
        s.insert(x);
        if (s.size() == 1) {
            mp = s.begin();
            return;
        }

        if (*mp < x) {
            if (!isEven()) {
                ++mp;
            }
        } else {
            if (isEven()) {
                --mp;
            }
        }
    }

private:
    set<int> s;
    set<int>::iterator mp;

    bool isEven () {
        return s.size() % 2 == 0;
    }

};
#endif
