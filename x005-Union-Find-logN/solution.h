#ifndef LEETCODE_SOLUTION_H__
#define LEETCODE_SOLUTION_H__

#include <vector>

using std::vector;

struct Subset {
    int parent;
    int rank;
    Subset ():rank(0) {}
    Subset (int p):parent(p), rank(0) {}
};

struct Edge {
    int src;
    int dist;
    Edge () {};
    Edge (int s, int d) : src(s), dist(d) {}

    Edge& operator=(const Edge &e) {
        if (this != &e) {
            src = e.src;
            dist = e.dist;
        }
        return *this;
    }
};

class Graph {
public:
    int V;
    int E;
    Graph () :V(0), E(0), edges(nullptr) {};
    Graph (int v, int e) : V(v), E(e) {
        edges = new Edge[E];
    }
    Graph (int v, vector<Edge> edgeList):V(v) {
        E = edgeList.size();
        edges = new Edge[E];

        for (int i = 0; i < E; ++i) {
            edges[i] = edgeList[i];
        }
    }
    ~Graph () {
        if (edges) delete [] edges;
    }

    bool hasCycle() {
        bool ret = false;

        Subset* subsets = new Subset[V];

        for (int i = 0; i < V; ++i) {
            subsets[i].parent = i;
            subsets[i].rank = 0;
        }

        for (int i = 0; i < E; ++i) {
            int x = find(subsets, edges[i].src);
            int y = find(subsets, edges[i].dist);

            if (subsets[x].parent == subsets[y].parent) {
                ret = true;
                break;
            }

            unionSet(subsets[x], subsets[y]);
        }

        delete [] subsets;
        return ret;
    }

private:
    Edge* edges;

    /**
     * 这个实现的 find 方法并没有压缩路径，所以效率有影响。
     */
    int find_(Subset* subsets, int i) {
        if (subsets[i].parent == i) {
            return subsets[i].parent;
        }
        return find_(subsets, subsets[i].parent);
    }

    /*
     * 使用路径压缩, find root and make root as parent of i (path compression)
     */
    int find(Subset* subsets, int i) {
        if (subsets[i].parent != i) {
            subsets[i].parent = find(subsets, subsets[i].parent);
        }
        return subsets[i].parent;
    }

    void unionSet(Subset & xSubset, Subset & ySubset) {
        if (xSubset.rank > ySubset.rank) {
            ySubset.parent = xSubset.parent;
        } else if (xSubset.rank < ySubset.rank) {
            xSubset.parent = ySubset.parent;
        } else {
            xSubset.parent = ySubset.parent;
            ++ySubset.rank;
        }
    }
};

#endif
