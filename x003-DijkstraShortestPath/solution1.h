#ifndef LEET_CODE_DIJKSTRA__
#define LEET_CODE_DIJKSTRA__

#include <vector>
#include <cmath>
#include <algorithm>

using std::vector;
using std::min;

class Graph1
{
public:
    using vi = vector<int>;
    using vii = vector<vi>;

    Graph1 (size_t v):n(v){};
    virtual ~Graph1 () = default;

    vi dijkstra(vii &G, size_t start) {
        vi sptSet;
        sptSet.push_back(start);

        vi dist(n, HUGE_VAL);
        dist[start] = 0;

        vi visitedSet(n, 0);
        size_t count = 0;

        while (count < n) {
            size_t  i = findMinDistanceVertex(sptSet, visitedSet, dist);
            visitedSet[i] = 1;
            ++count;

            for (size_t j = 0; j < n; ++j) {
                if (G[i][j] != 0) {
                    dist[j] = min(dist[j], dist[i] + G[i][j]);
                    sptSet.push_back(j);
                }
            }
        }
        return dist;
    }

private:
    // 图中节点的个数。
    size_t n;

    size_t findMinDistanceVertex(vi &sptSet, vi &visitedSet, vi &dist) {
        int min = HUGE_VAL;
        size_t v = 0;
        for (auto n : sptSet) {
            if (!visitedSet[n]) {
                min = min > dist[n] ? dist[n] : min;
                v = n;
            }
        }
        return v;
    }
};
#endif /* ifndef LEET_CODE_DIJKSTRA__ */
