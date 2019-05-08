#ifndef LEETCODE_SOLUTION_H__
#define LEETCODE_SOLUTION_H__

#include <vector>
#include <cstdlib>
#include <iostream>
#include <queue>


using std::vector;
using std::qsort;
using std::priority_queue;

struct Edge {
    int src, dist, weight;
    Edge () {}
    Edge(int s, int d, int w) : src(s), dist(d), weight(w) {}
};

struct Subset {
    int parent;
    int rank;
};


int comp (const void * a, const void * b) {
    Edge *e1 = (Edge *)a;
    Edge *e2 = (Edge *)b;
    return e1->weight - e2->weight;
}

class Graph {
    public:
        int V;
        int E;
        Graph (int v, int e) : V(v), E(e), edges(nullptr) {}
        Graph (int v, vector<Edge> edgeList) : V(v) {
            E = edgeList.size();
            edges = new Edge[E];
            int i = 0;
            for (auto e : edgeList) {
                edges[i++] = e;
            }
        }
        ~Graph () {
            /* if (edges) delete [] edges; */
        }

        vector<Edge> genKruskalMST () {
            vector<Edge> result;
            qsort(edges, E, sizeof(edges[0]), comp);

            Subset* subsets = new Subset[V];
            for (int i = 0; i < V; ++i) {
                subsets[i].parent = i;
                subsets[i].rank = 0;
            }


            int e = 0;
            int i = 0;
            while (e < V - 1) {
                Edge edge = edges[i++];

                int x = find(subsets, edge.src);
                int y = find(subsets, edge.dist);

                if (subsets[x].parent != subsets[y].parent) {
                    ++e;
                    result.push_back(edge);
                    unionSet(subsets[x], subsets[y]);
                }
            }
            delete [] subsets;

            return result;
        }

        void printEdges () {
            int i = 0;
            while (i < E) {
                std::cout << edges[i].src << " ---> " << edges[i].dist << "(" << edges[i].weight << ")" << std::endl;
                ++i;
            }
        }

        vector<Edge> genKruskalMST2() {
            auto cmp = [](const Edge *a, const Edge *b) {
                return a->weight > b->weight;
            };

            priority_queue<Edge *, vector<Edge *>, decltype(cmp)> q(cmp);

            for (int i = 0; i < E; ++i) {
                q.push(edges + i);
            }

            Subset* sets = new Subset[V];
            for (int i = 0; i < V; ++i) {
                sets[i].parent = i;
                sets[i].rank = 0;
            }

            vector<Edge> res;

            for (int i = 0; i < E - 1; ++i) {
                Edge *e = q.top();
                q.pop();
                int x = find(sets, e->src);
                int y = find(sets, e->dist);

                /* if (sets[x].parent != sets[y].parent) { */
                if (x != y) {
                    unionSet(sets[x], sets[y]);
                    res.push_back(*e);
                }
            }

            delete []sets;
            return res;
        }

    private:
        Edge* edges;

        int find (Subset* subsets, int i) {
            if (subsets[i].parent != i) {
                return find(subsets, subsets[i].parent);
            }
            return subsets[i].parent;
        }

        void unionSet(Subset &xSet, Subset &ySet) {
            if (xSet.rank == ySet.rank) {
                xSet.parent = ySet.parent;
                ++ySet.rank;
            } else if (xSet.rank < ySet.rank) {
                xSet.parent = ySet.parent;
            } else {
                ySet.parent = xSet.parent;
            }
        }
};

#endif
