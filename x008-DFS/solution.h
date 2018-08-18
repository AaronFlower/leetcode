#ifndef DFS_H__
#define DFS_H__ 

#include <vector>

using std::vector;

class Graph {
    public:
        size_t V;
        
        Graph ():V(0), adj(nullptr) {}

        Graph (size_t v) : V(v), adj(nullptr) {
            if (v > 0) adj = new vector<size_t>[V];
        }

        ~Graph () {
            if (adj) delete [] adj;
        }

        void addEdge (size_t i, size_t j) {
            adj[i].push_back(j);
        }

        vector<size_t> DFS () {
            vector<size_t> vertices;
            if (V == 0) return vertices;
            
            vector<bool> visited(V, false);

            for (size_t i = 0; i < V; ++i) {
                if (visited[i] == false) {
                    visited[i] = true;
                    vertices.push_back(i);
                    DFSUtil(i, vertices, visited);
                }
            }

            return vertices;
        }

    private:
        vector<size_t>* adj;

        void DFSUtil(size_t i, vector<size_t> &vertices, vector<bool> &visited) {
            for (auto v : adj[i]) {
                if (visited[v] == false) {
                    visited[v] = true;
                    vertices.push_back(v);
                    DFSUtil(v, vertices, visited);
                }
            }
        }
};
#endif /* ifndef DFS_H__ */
