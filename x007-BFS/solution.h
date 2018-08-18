#ifndef LEET_CODE_X007_BFS__
#define LEET_CODE_X007_BFS__ 

#include <vector>
#include <queue>

using std::vector;
using std::queue;

class Graph {
    public:
        size_t V;

        Graph (): V(0), adj(nullptr) {}

        Graph (size_t v) : V(v), adj(nullptr) {
            if (v > 0) adj = new vector<size_t>[V];
        }

        ~Graph () {
            if (adj) delete [] adj;
        }

        void addEdge (size_t i, size_t j) {
            adj[i].push_back(j);
        }

        vector<size_t> BFS (size_t s) {
            vector<size_t> vertices;
            if (V == 0) return vertices;
            vector<bool> visited(V, false);

            queue<size_t> q;
            q.push(s);
            visited[s] = true;
            vertices.push_back(s);

            while (!q.empty()) {
                size_t top = q.front();
                q.pop();
                for (auto dist : adj[top]) {
                    if (!visited[dist]) {
                        vertices.push_back(dist);
                        visited[dist] = true;
                        q.push(dist);
                    }
                }
            }
            
            return vertices;
        }
    private:
        vector<size_t> *adj;
};
#endif /* ifndef LEET_CODE_X007_BFS__ */
