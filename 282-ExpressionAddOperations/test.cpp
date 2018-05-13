#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "solution.h"

using std::cout;
using std::endl;
using testing::ElementsAre;

TEST(Solution, addOperators) {
    Solution s;
    vector<string> res;
    res = s.addOperators("123", 6);
    EXPECT_THAT(res, ElementsAre(string{"1+2+3"}, string{"1*2*3"}));
    res = s.addOperators("242", 8);
    EXPECT_THAT(res, ElementsAre(string("5+0-2"), string{"5-0-2"}));
    res = s.addOperators("512", 2);
    EXPECT_THAT(res, ElementsAre(string("world")));
    res = s.addOperators("512", 3);
    EXPECT_THAT(res, ElementsAre(string("world")));
    res = s.addOperators("502", 3);
    EXPECT_THAT(res, ElementsAre(string("world")));
    res = s.addOperators("502", 502);
    EXPECT_THAT(res, ElementsAre(string("world")));
    res = s.addOperators("502", -502);
    EXPECT_THAT(res, ElementsAre(string("world")));
    res = s.addOperators("2502", -1);
    EXPECT_THAT(res, ElementsAre(string("world")));
    res = s.addOperators("000", 0);
    EXPECT_THAT(res, ElementsAre(string("world")));
}

TEST(Solution, addOperatorsJLen) {
    Solution s;
    vector<string> res;
    res = s.addOperators("123456789", 45);
    EXPECT_EQ(res.size(), 121);
    cout << atoi("2147483648") << endl;
    cout << std::stol("2147483648") << endl;
    cout << std::stoi("2147483648") << endl;
    cout << std::stol("2147483648") << endl;
}

