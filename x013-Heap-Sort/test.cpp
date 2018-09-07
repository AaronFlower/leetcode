#include "gtest/gtest.h"
#include "solution.h"
#include <iostream>

using std::cout;
using std::endl;

void printArr(int *arr, int len) {
    for (int i = 0; i < len; ++i) {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

TEST(Solution, Descent) {
    cout << "Descenting heap sort" << endl;
    Solution s;
    int arr [] = {7, 6, 11, 2, 9, 4};
    int len = 6;
    printArr(arr, len);
    for (int i = (len / 2) - 1; i >= 0; --i) {
        s.heapify(arr, len, i);
    }

    printArr(arr, len);

    s.heapSort(arr, len);
    printArr(arr, len);
}

bool greater(const int &a, const int &b) {
    return a > b;
}

TEST(Solution, ascend) {
    cout << "Ascending heap sort" << endl;
    Solution s(greater);
    int arr [] = {7, 6, 11, 2, 9, 4};
    int len = 6;
    printArr(arr, len);
    s.heapSort(arr, len);
    printArr(arr, len);
}

