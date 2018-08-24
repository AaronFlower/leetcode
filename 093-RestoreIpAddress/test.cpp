#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "solution.h"

using testing::ElementsAre;


TEST (String, JOIN) {
    Solution s;
    vector<string> ips = {"123", "12", "23", "255"};
    EXPECT_EQ(s.join(ips), "123.12.23.255");
}

TEST (Solution, RestoreIP) {
    Solution s;
    s.restoreIpAddresses("123255255255");
    EXPECT_THAT(s.restoreIpAddresses("123255255255"), ElementsAre("123.255.255.255"));
    EXPECT_THAT(s.restoreIpAddresses("25525511135"), ElementsAre("255.255.11.135", "255.255.111.35"));
    EXPECT_THAT(s.restoreIpAddresses("0000"), ElementsAre("0.0.0.0"));
    EXPECT_THAT(s.restoreIpAddresses("010010"), ElementsAre("0.10.0.10","0.100.1.0"));
}

