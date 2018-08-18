#include "gtest/gtest.h"
#include "solution.h"
#include <iostream>

TEST(Grap, LinkListAdj) {
   Graph g;
   Graph g2(3);
}

void printBFS (vector<size_t> vertices) {
    for (auto v:vertices) {
        std::cout << v << "\t";
    }
    std::cout << std::endl;
}

TEST(Grap, BFS) {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    printBFS(g.BFS(2));
    printBFS(g.BFS(1));
}
