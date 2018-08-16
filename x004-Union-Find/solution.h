#ifndef LEETCODE_SOLUTION_H__
#define LEETCODE_SOLUTION_H__ 

#include <vector>

using std::vector;

struct Edge {
    int src;
    int dist;
    Edge () {};
    Edge (int s, int d) : src(s), dist(d) {}
};

class Graph {
    public:
        int V;
        int E;
        
        Graph ():V(0), E(0), edges(nullptr) {}
        Graph (int v, int e):V(v), E(e) {
            edges = new Edge[e];
        }

        ~Graph () {
            if (edges) delete [] edges;
        }

        void assignEdges (vector<Edge> eList) {
            int i = 0;
            for (auto e : eList) {
                if (i < E) {
                    edges[i].src = e.src;
                    edges[i].dist = e.dist;
                    ++i; 
                }
            }
        }

        bool hasCycle () {
            int* parent = new int[V];
            memset(parent, -1, V * sizeof(int));

            bool ret = false;

            for (int i = 0; i < E; ++i) {
                int src = edges[i].src;
                int dist = edges[i].dist;

                int srcP = find(parent, src);
                int distP = find(parent, dist);

                if (srcP == distP ) {
                    ret = true;
                    break;
                } 
                unionSet(parent, srcP, distP);
            }
            delete [] parent;

            return ret;
        }

    private:
        Edge* edges;

        int find (int *parent, int i) {
            if (parent[i] == -1) return i;
            return find(parent, parent[i]);
        }
        
        void unionSet(int *parent, int src, int dist) {
            parent[src] = dist;
        }
};

#endif
