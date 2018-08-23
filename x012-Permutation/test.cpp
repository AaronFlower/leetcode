#include "gtest/gtest.h"
#include "solution.h"


TEST(Solution, init) {
    Solution s;
    s.permute("");
    cout << "permute  HELLO" << endl;
    s.permute("HELLO");

    s.permute("ABC");
    s.permute("ABB");
}

