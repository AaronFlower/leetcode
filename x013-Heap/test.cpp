#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "solution.h"
#include <queue>

using std::cout;
using std::endl;
using std::vector;
using testing::ElementsAre;
using std::priority_queue;

void printArr(int *arr, int len) {
    for (int i = 0; i < len; ++i) {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

/* TEST(Solution, Descent) { */
/*     cout << "Descenting heap sort" << endl; */
/*     Solution s; */
/*     int arr [] = {7, 6, 11, 2, 9, 4}; */
/*     int len = 6; */
/*     printArr(arr, len); */
/*     for (int i = (len / 2) - 1; i >= 0; --i) { */
/*         s.heapify(arr, len, i); */
/*     } */

/*     printArr(arr, len); */

/*     s.heapSort(arr, len); */
/*     printArr(arr, len); */
/* } */

bool greater(const int &a, const int &b) {
    return a > b;
}
TEST(PriorityQueue, MinHeap) {
    cout << "MaxHeap heap " << endl;
    PriorityQueue q;
    priority_queue<int, vector<int>, std::greater<int>> stdq;
    vector<int> nums{7, 6, 11, 2, 9, 4};
    vector<int> res;

    for (auto n : nums) {
        stdq.push(n);
        q.push(n);
    }

    while (!q.empty()) {
        EXPECT_EQ(q.top(), stdq.top());
        res.push_back(q.top());
        q.pop();
        stdq.pop();
    }

    EXPECT_EQ(q.empty(), stdq.empty());
    EXPECT_THAT(res, ElementsAre(2, 4, 6, 7, 9, 11));
}

TEST(PriorityQueue, MaxHeap) {
    cout << "MaxHeap heap " << endl;
    PriorityQueue q(greater);
    priority_queue<int> stdq;
    vector<int> nums{7, 6, 11, 2, 9, 4};
    vector<int> res;

    for (auto n : nums) {
        stdq.push(n);
        q.push(n);
    }

    q.pop();
    stdq.pop();

    for (auto i : {-1, 2}) {
        q.push(i);
        stdq.push(i);
    }


    while (!q.empty()) {
        EXPECT_EQ(q.top(), stdq.top());
        res.push_back(q.top());
        q.pop();
        stdq.pop();
    }

    EXPECT_EQ(q.empty(), stdq.empty());
    EXPECT_THAT(res, ElementsAre(9, 7, 6, 4, 2, 2, -1));
}
