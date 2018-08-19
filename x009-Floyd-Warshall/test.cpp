#include "gtest/gtest.h"
#include "solution.h"

TEST(Graph, create) {
    Graph g;
    Graph g1(4, {Edge(1,2,0), Edge(1, 3, 4)});
}

void printDist(const Graph::vvi dist) {
    for (auto row:dist) {
        for (auto v:row) {
            std::cout << v << "\t";
        }
        std::cout << "\n";
    }
}

TEST(Graph, Floyd) {
    Graph g(4, {
            Edge(0, 2, -2),
            Edge(1, 0, 4),
            Edge(1, 2, 3),
            Edge(2, 3, 2),
            Edge(3, 1, -1),
            });

    Graph::vvi dist = g.floydWarshallDist();
    printDist(dist);
}
