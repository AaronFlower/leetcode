#include "gtest/gtest.h"
#include "solution.h"
#include <iostream>

using std::cout;
using std::endl;

TEST(Graph, CtorAndDtor) {
    Graph g1;
    Graph g2(3, 3);

    g2.assignEdges({ Edge(0, 1), Edge(1, 2), Edge(1, 2)});
}

TEST(Graph, hasCycle) {
    Graph g1(4, 3); // (节点数，边数)
    g1.assignEdges({ Edge(0, 1), Edge(1, 2), Edge(1, 2)});

    EXPECT_EQ(g1.hasCycle(), true);
}

TEST(Graph, hasCycle2) {
    Graph g1(4, 3);
    g1.assignEdges({ Edge(0, 1), Edge(1, 2), Edge(2, 3)});

    EXPECT_EQ(g1.hasCycle(), false);
}
