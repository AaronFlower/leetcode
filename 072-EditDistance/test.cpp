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
    EXPECT_EQ(s.minDistance(x, y), 10);
}

TEST(MinEditDistance, DP_COLUMN) {
    Solution s;
    string x, y;
    x = "eat";
    y = "tea"; 
    EXPECT_EQ(s.minDistanceColumn(x, y), 2);
    
    x = "spark";
    y = "spa";
    EXPECT_EQ(s.minDistanceColumn(x, y), 2);

    x = "";
    y = "";
    EXPECT_EQ(s.minDistanceColumn(x, y), 0);

    x = "hello";
    y = "";
    EXPECT_EQ(s.minDistanceColumn(x, y), 5);

    x = "";
    y = "hello";
    EXPECT_EQ(s.minDistanceColumn(x, y), 5);
    
    x = y = "her";
    EXPECT_EQ(s.minDistanceColumn(x, y), 0);

    x = "heroine";
    y = "him";
    EXPECT_EQ(s.minDistanceColumn(x, y), 5);

    x = "zoologicoarchaeologist";
    y = "zoogeologist";
    EXPECT_EQ(s.minDistanceColumn(x, y), 10);

    x = "logicoarchaeologist";
    y = "geologist";
    EXPECT_EQ(s.minDistanceColumn(x, y), 10);
}

TEST(MinEditDistance, DP_ROW) {
    Solution s;
    string x, y;
    x = "eat";
    y = "tea"; 
    EXPECT_EQ(s.minDistanceRow(x, y), 2);
    
    x = "spark";
    y = "spa";
    EXPECT_EQ(s.minDistanceRow(x, y), 2);

    x = "";
    y = "";
    EXPECT_EQ(s.minDistanceRow(x, y), 0);

    x = "hello";
    y = "";
    EXPECT_EQ(s.minDistanceRow(x, y), 5);

    x = "";
    y = "hello";
    EXPECT_EQ(s.minDistanceRow(x, y), 5);
    
    x = y = "her";
    EXPECT_EQ(s.minDistanceRow(x, y), 0);

    x = "heroine";
    y = "him";
    EXPECT_EQ(s.minDistanceRow(x, y), 5);

    x = "zoologicoarchaeologist";
    y = "zoogeologist";
    EXPECT_EQ(s.minDistanceRow(x, y), 10);

    x = "logicoarchaeologist";
    y = "geologist";
    EXPECT_EQ(s.minDistanceRow(x, y), 10);
}

