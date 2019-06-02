#ifndef LEET_DIVISION__
#define LEET_DIVISION__

#include <cassert>

class Solution {
public:
    void division_by_sub1(int a, int b, int &quotient, int &remainder) {
        assert(b != 0);

        if (a < b) {
            quotient = 0;
            remainder = a;
            return;
        } else if(b == 1) {
            quotient = a;
            remainder = 0;
        } else {
            quotient = 1;
            while (a - b > b) {
                a -= b;
                ++quotient;
            }
            remainder = a - b;
        }
    }

    /**
     * 同样是利用减法，第二种写法就十分简洁了。
     */
    void division_by_sub2(int a, int b, int &quotient, int &remainder) {
        assert(b != 0);

        quotient = 0;
        while (a >= b) {
            a -= b;
            ++quotient;
        }
        remainder = a;
    }

    /**
     * 利用移位来实现, 贪心算法找到下一个最大的可累加值。
     * 注意 b 向左移位可能出现负数，这个要避免。
     */
    void division_by_left_shift(int a, int b, int &quotient, int &remainder) {
        assert(b != 0);

        quotient  = 0;
        remainder = 0;
        int sum = 0;

        for (int i = 31; i >= 0; --i) {
            if ((b << i) >= 0 && (sum + (b << i)) <= a) {
                sum += (b << i);
                quotient |= (1 << i);
            }
            remainder = a - sum;
        }
    }
};
#endif
