#include "gtest/gtest.h"
#include "solution.h"
#include <iostream>

using std::cout;
using std::endl;


TEST(Union_find, Create) {
    Graph g;
    Graph g1(2, 3);
    Graph g2(3, {Edge(0, 1), Edge(1, 2), Edge(0, 1)});
} 

TEST(Union_find, hasCycle) {
    Graph g(3, {Edge(0, 1), Edge(1, 2), Edge(0, 1)});
    EXPECT_EQ(g.hasCycle(), true);
}

TEST(Union_find, hasCycle2) {
    Graph g(3, {Edge(1, 2), Edge(0, 1)});
    EXPECT_EQ(g.hasCycle(), false);
}
