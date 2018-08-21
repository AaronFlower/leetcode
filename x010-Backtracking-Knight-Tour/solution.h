#ifndef LEET_CODE_KNIGHT_TOUR_H__
#define LEET_CODE_KNIGHT_TOUR_H__ 

#include <vector>
#include <cstddef> 
#include <cstring> 
#include <iostream>

using std::pair;
using std::vector;
using std::make_pair;

class ChessBoard {
public:
    ChessBoard ():N(0), board(nullptr) {
        std::cout << "empty constructor" << std::endl;
    };
    ChessBoard (int n):N(n), board(nullptr) {
        steps = {
            make_pair(2, 1),
            make_pair(1, 2),
            make_pair(-1, 2),
            make_pair(-2, 1),
            make_pair(-2, -1),
            make_pair(-1, -2),
            make_pair(1, -2),
            make_pair(2, -1)
        };
        board = new int*[N];
        for (int i = 0; i < N; ++i) {
            board[i] = new int[N];
            memset(board[i], -1, sizeof(int) * N);
        }
    }

    ~ChessBoard () {
        std::cout << "Destructor" << std::endl;
        if (board) {
            for (int i = 0; i < N; ++i) {
                delete [] board[i];
            }
            delete [] board;
        }
    }

    bool knightTour () {
        board[0][0] = 0;
        return knightTourUtil(0, 0, 1);
    }

    int** getBoard () {
        return board;
    }

private:
    int N;
    int **board;
    vector<pair<int, int>> steps;

    bool knightTourUtil (int x, int y, int movei) {
        if (movei == N * N) return true;
        for (int i = 0; i < 8; ++i) {
            int nextX = x + steps[i].first;
            int nextY = y + steps[i].second;
            if (isSafe(nextX, nextY)) {
                board[nextX][nextY] = movei;
                
                // checkforward
                if (knightTourUtil(nextX, nextY, movei + 1)) {
                    return true;
                } else {
                    // forward failed && go backtracking;
                    board[nextX][nextY] = -1;
                }
            }
        }
        return false;
    }

    bool isSafe(int x, int y) {
        return x >= 0 && x < N && y >= 0  && y < N && board[x][y] == -1;
    }
};
#endif /* ifndef LEET_CODE_KNIGHT_TOUR_H__ */
