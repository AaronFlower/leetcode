#ifndef LEET_CODE_KNIGHT_TOUR_H__
#define LEET_CODE_KNIGHT_TOUR_H__ 

#include <iostream>
#include <random>

class Maze {
public:
    Maze () : N(0), maze(nullptr) {}
    Maze (int n):N(n), maze(nullptr) {
        if (N > 0) {
            maze = new int*[N];
            for (int i = 0; i < N; ++i) {
                maze[i] = new int[N];
            }
        } 
        initMaze();
    };

    ~Maze () {
        if (maze) {
            for (int i = 0; i < N; ++i) {
                delete [] maze[i];
            }
            delete [] maze;
        }
    }

    int** getMaze () {
        return maze;
    }

    void printPath(int** path) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                std::cout << path[i][j] << "\t";
            }
            std::cout << std::endl;
        }
    }

    void findPath () {
        int **path = new int*[N];
        for (int i = 0; i < N; ++i) {
            path[i] = new int[N];
            memset(path[i], 0, sizeof(int) * N);
        }

        if(solveMaze(0, 0, path)) {
            printPath(path);
        }
        
        for (int i = 0; i < N; ++i) delete [] path[i];
        delete [] path;
    }

private:
    int N; 
    int **maze;

    bool solveMaze(int x, int y, int **path) {
        if (x == N - 1 && y == N - 1) {
            path[x][y] = 1;
            return true;
        }
        
        if (isSafe(x, y)) {
            // mark x,y as the valid path
            path[x][y] = 1;
            if (solveMaze(x + 1, y, path)) {
                return true;
            }
            if (solveMaze(x, y + 1, path)) {
                return true;
            }
            // If none of the above movements work then backtrack:
            // unmark x,y as the valid path
            path[x][y] = 0; 
            return false;
        }

        return false;
    }

    bool isSafe(int x, int y) {
        return x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1;
    }

    void initMaze () {
        std::random_device seed;
        std::mt19937 gen(seed());
        std::uniform_int_distribution<int> dist(0, 100);

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                maze[i][j] = dist(gen) % 3 ? 1 : 0;
            }
        }
    }

};
#endif /* ifndef LEET_CODE_KNIGHT_TOUR_H__ */
