#include "gtest/gtest.h"
#include "solution.h"

using std::cout;
using std::endl;

TEST(Maze, init) {
    Maze board1;
    Maze board2(8);
}

void printBoard(int **board, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << board[i][j] << "\t";
        }
        cout << endl;
    }
}


TEST(Maze, RatTour) {
    Maze b(5);
    cout << "Check if maze has path" << endl;
    b.findPath();

    Maze c(5);
    cout << "Check if maze has path" << endl;
    c.findPath();

    Maze d(6);
    cout << "Check if maze has path" << endl;
    c.findPath();
}

TEST(Maze, RatTour2) {
    Maze b(8);
    /* printBoard(b.getMaze(), 8); */
    cout << "Check if maze has path" << endl;
    b.findPath();
}
