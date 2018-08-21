#include "gtest/gtest.h"
#include "solution.h"

using std::cout;
using std::endl;

TEST(ChessBoard, init) {
    ChessBoard board1;
    ChessBoard board2(8);
}

void printBoard(int **board, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << board[i][j] << "\t";
        }
        cout << endl;
    }
}


TEST(ChessBoard, KnightTour) {
    ChessBoard b(5);
    printBoard(b.getBoard(), 5);
    EXPECT_EQ(b.knightTour(), true);
    cout << "The new tour line is:" << endl;
    printBoard(b.getBoard(), 5);
}

TEST(DISABLED_ChessBoard, KnightTour2) {
    ChessBoard b(8);
    printBoard(b.getBoard(), 8);
    EXPECT_EQ(b.knightTour(), true);
    cout << "The new tour line is:" << endl;
    printBoard(b.getBoard(), 8);
}
