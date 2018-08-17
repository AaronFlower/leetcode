#include "gtest/gtest.h"
#include "solution.h"
#include <iostream>

using std::cout;
using std::endl;

void printDistance (int s, vector<int> dist) {
    cout << "The source " << s << " to other vertice distance are as follows: " << endl;
    for (std::size_t i = 0; i < dist.size(); ++i) {
        cout << "\t" << i << "\t" << dist[i] << endl;
    }
}

TEST(Dijkstra, ShortestPath) {
    /* Let us create following weighted graph
             10
        0--------1
        |  \     |
       6|   5\   |15
        |      \ |
        2--------3
            4       */
    Graph g(4, {
            Edge(0, 1, 10),
            Edge(0, 3, 5),
            Edge(0, 2, 6),
            Edge(1, 3, 15),
            Edge(2, 3, 4),
        });
    g.printEdges();
    vector<Edge> edges = g.genKruskalMST();
    std::cout << "After sort \n";
    g.printEdges();

    std::cout << "The MST Tres is : \n"; 
    for (auto e:edges) {
        std::cout << e.src << " ---> " << e.dist << "(" << e.weight << ")" << std::endl;
    }
} 
