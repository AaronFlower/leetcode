#ifndef FLOYD_WARSHALL_H__
#define FLOYD_WARSHALL_H__

#include <vector>
#include <cmath>

using std::vector;

struct Edge {
    size_t src;
    size_t dist;
    int weight;
    Edge () {};
    Edge (size_t i, size_t j, int w):src(i), dist(j), weight(w) {};
};

class Graph {
public:
    using vvi = vector<vector<int>>;
    size_t V;

    Graph () :V(0) {};
    Graph (size_t v, vector<Edge> es) : V(v), edges(es) {}
    ~Graph () {}

    vvi floydWarshallDist () {
        vvi dist(V, vector<int>(V, INFINITY));
        
        for (auto e:edges) {
            dist[e.src][e.dist] = e.weight;
        }

        for (size_t i = 0; i < V; ++i) {
            dist[i][i] = 0;
        }

        size_t i, j, k;
        for (k = 0; k < V; ++k) {
            for (i = 0; i < V; ++i) {
                for (j = 0; j < V; ++j) {
                    dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        return dist;
    }

private:
    vector<Edge> edges;
};
#endif /* ifndef FLOYD_WARSHALL_H__ */
