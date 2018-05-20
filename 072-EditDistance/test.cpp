#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "solution.h"

TEST(MinEditDistance, DP) {
    Solution s;
    string x, y;
    x = "eat";
    y = "tea"; 
    EXPECT_EQ(s.minDistance(x, y), 2);
    
    x = "spark";
    y = "spa";
    EXPECT_EQ(s.minDistance(x, y), 2);

    x = "";
    y = "";
    EXPECT_EQ(s.minDistance(x, y), 0);

    x = "hello";
    y = "";
    EXPECT_EQ(s.minDistance(x, y), 5);

    x = "";
    y = "hello";
    EXPECT_EQ(s.minDistance(x, y), 5);
    
    x = y = "her";
    EXPECT_EQ(s.minDistance(x, y), 0);

    x = "heroine";
    y = "him";
    EXPECT_EQ(s.minDistance(x, y), 5);

    x = "zoologicoarchaeologist";
    y = "zoogeologist";
    EXPECT_EQ(s.minDistance(x, y), 9);
}

TEST(MinEditDistance, DP2) {
    Solution s;
    string x, y;
    x = "eat";
    y = "tea"; 
    EXPECT_EQ(s.minDistance2(x, y), 2);
    
    x = "spark";
    y = "spa";
    EXPECT_EQ(s.minDistance2(x, y), 2);

    x = "";
    y = "";
    EXPECT_EQ(s.minDistance2(x, y), 0);

    x = "hello";
    y = "";
    EXPECT_EQ(s.minDistance2(x, y), 5);

    x = "";
    y = "hello";
    EXPECT_EQ(s.minDistance2(x, y), 5);
    
    x = y = "her";
    EXPECT_EQ(s.minDistance2(x, y), 0);

    x = "heroine";
    y = "him";
    EXPECT_EQ(s.minDistance2(x, y), 5);

    x = "zoologicoarchaeologist";
    y = "zoogeologist";
    EXPECT_EQ(s.minDistance2(x, y), 9);
}

TEST(MinEditDistance, DP3) {
    Solution s;
    string x, y;
    x = "eat";
    y = "tea"; 
    EXPECT_EQ(s.minDistance3(x, y), 2);
    
    x = "horse";
    y = "ros"; 
    EXPECT_EQ(s.minDistance3(x, y), 3);

    x = "zologole";
    y = "zogegole";
    EXPECT_EQ(s.minDistance3(x, y), 10);

    x = "logole";
    y = "gegole";
    EXPECT_EQ(s.minDistance3(x, y), 9);
}
