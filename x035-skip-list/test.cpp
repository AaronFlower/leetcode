#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "skiplist.h"

#include <iostream>
#include <map>
#include <vector>

using std::map;
using std::vector;
using std::cout;
using std::endl;

TEST(test,tossup) {
    // Seed random number generator
    srand((unsigned)time(0));

    // 通常一个具有 n 个元素的 skiplist 会有 log2(n) 层。 当然我们的概率取的是 0.5;
    SkipList sl(10, 0.5);
    map<int, int> countMap;
    for (int i = 0; i < 1024; ++i) {
        int layer = sl.getRandomLayer();
        ++countMap[layer];
    }

    cout << endl;
    for (auto e:countMap) {
        cout << "Layer: " << e.first << ", expected elements: " << e.second << endl;
    }
}

TEST(test, insertSkipList) {
    srand(unsigned(time(0)));
    cout << "Test InsertSkipList" << endl;

    SkipList sl(6, 0.5);

    vector<int> nums{3, 6, 7, 9, 12, 19, 17, 26, 21, 25};
    for (int i = -20; i < 30; ++i) {
        sl.insert(i);
    }
    for (int n:nums) {;
        sl.insert(n);
    }
    sl.display();
}

TEST(test, testSearch) {
    srand(unsigned(time(0)));

    SkipList sl(4, 0.5);
    vector<int> nums{3, 6, 7, 9, 12, 19, 17, 26, 21, 25};
    for (int n:nums) {
        sl.insert(n);
    }

    EXPECT_EQ(-1, sl.search(0));
    EXPECT_EQ(1, sl.search(19));
}
