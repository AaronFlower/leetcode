#include "gtest/gtest.h"
#include "solution.h"
#include "iostream"

TEST(Graph, create) {
    Graph g;
    Graph g1(3);
    g1.addEdge(0, 1);
    g1.addEdge(1, 0);
    g1.addEdge(1, 2);
}

void printDFS (const vector<size_t> vertices) {
    for (auto v : vertices) {
        std::cout << v << "\t";
    }
    std::cout << std::endl;
}

TEST(Graph, DFS) {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    printDFS(g.DFS());
}


