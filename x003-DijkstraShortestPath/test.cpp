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
    Graph g(9);
    g.G = {
          {0, 4, 0, 0, 0, 0, 0, 8, 0},
          {4, 0, 8, 0, 0, 0, 0, 11, 0},
          {0, 8, 0, 7, 0, 4, 0, 0, 2},
          {0, 0, 7, 0, 9, 14, 0, 0, 0},
          {0, 0, 0, 9, 0, 10, 0, 0, 0},
          {0, 0, 4, 14, 10, 0, 2, 0, 0},
          {0, 0, 0, 0, 0, 2, 0, 1, 6},
          {8, 11, 0, 0, 0, 0, 1, 0, 7},
          {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };
    
    vector<int> dist = g.dijkstra(0);
    printDistance(0, dist);
} 
