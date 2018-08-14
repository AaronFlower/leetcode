#ifndef LEETCODE_SOLUTION_H__
#define LEETCODE_SOLUTION_H__ 

#include <vector>
#include <unordered_map>
#define INF (0x0fffffff)

using std::vector;
using std::size_t;
using std::min;

class Graph {
public:
    std::size_t num_vertices;
    vector<vector<int>> G;
    
    Graph (int v):num_vertices(v) {}

    vector<int> dijkstra (int s) {
        vector<int> dist(num_vertices, INF);
        dist[s] = 0;
        
        vector<int> sptSet;
        sptSet.push_back(s);
        vector<bool> visited(num_vertices, false);
        size_t visitedCount = 0;

        while (visitedCount != num_vertices) {
            int minV = findMinVertice(visited, sptSet, dist);
            visited[minV] = true;
            visitedCount++;

            for (size_t i = 0; i < num_vertices; ++i) {
                if (G[minV][i] != 0) {
                    dist[i] = min(dist[i], dist[minV] + G[minV][i]);
                    sptSet.push_back(i);
                }
            }
        }
        return dist;
    }

private:
    int findMinVertice(vector<bool> visited, vector<int> sptSet, vector<int> dist) {
        int min = INF;
        int vertice = -1;
        
        for (auto ele : sptSet) {
            if (visited[ele] == false && dist[ele] <= min) {
                min = dist[ele];
                vertice = ele;
            }
        }
        return vertice;
    }
};

#endif

