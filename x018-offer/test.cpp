#include "gtest/gtest.h"
#include "solution.h"

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using std::cout;
using std::endl;
using std::vector;
using std::string;

TEST(Compare, sort_by_alphabet) {
    vector<string> words = {"apple", "cat", "dog", "pear", "banana"};
    sort(words.begin(), words.end());
    for (auto w:words) {
        cout << w << "\t";
    }
    cout << endl;
}


/**
 * 通过实现 compare function.
 */
TEST(Compare, sort_by_len) {
    auto cmp= [](const string &a, const string &b) {
        return a.size() < b.size();
    };

    vector<string> words = {"apple", "cat", "dog", "pear", "banana"};
    sort(words.begin(), words.end(), cmp);
    for (auto w:words) {
        cout << w << "\t";
    }
    cout << endl;
}

// 通过重载 < 操作符来实现.
struct Point {
   int x, y; 
   Point ():x(0), y(0) {};
   Point (int x, int y):x(x), y(y) {};

   bool operator<(const Point& other) const {
       return (x * x + y * y) < (other.x * other.x + other.y * other.y);
   }

   friend std::ostream& operator<<(std::ostream &out, const Point &p) {
       out<< " (" << p.x << "," << p.y << ") ";
       return out;
   }
};

TEST(Compare, operatorLess) {
    vector<Point> points{{-1, -1}, {-2, 3}, {1, 0}, {0, 1}, {2, 2}};
    for (Point p:points) {
        cout << p;
    }
    cout << endl ;
    cout << "After sorting " << endl;
    sort(points.begin(), points.end());
    for (Point p:points) {
        cout << p;
    }
    cout << endl ;
}


// 通过重载 < 运算符
struct Edge {
    int weight;
    
    Edge(int w):weight(w){};

    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};


TEST(Compare, operatorFunctor) {
   vector<Edge> edges{{1}, {2}, {0}, {-1}, {6}, {9}, {4}, {-4}}; 

   std::priority_queue<Edge, vector<Edge>> pq;
   for (Edge e:edges) {
       pq.push(e);
   }

   while (!pq.empty()) {
       cout << pq.top().weight << "\t";
       pq.pop();
   }
   cout << endl;
}

class A {
    public:
        int value;
        A (int n) :value(n) {
            cout << "Constructor " << endl; 
        }
        A (const A& other) {
           value = other.value;
           cout << "copy constructor " << endl; 
        }
};

/**
 * copy constructor.
 */
TEST(ClassA, copyConstructor) {
    A a = 10; // call construtor;
    A c(11);
    A b = a;
    cout << a.value << endl;
    cout << b.value << endl;
    cout << c.value << endl;
}

TEST(Bit, PowerOf2) {
    /**
     * 判断一个数 a 是不是 2 的次幂
     * (a & a - 1) == 0
     */
    EXPECT_EQ((1 & (1-1)) == 0, true);
    EXPECT_EQ((4 & (4-1)) == 0, true);
    EXPECT_EQ((8 & (8-1)) == 0, true);
    EXPECT_EQ((1024 & (1024-1)) == 0, true);
    EXPECT_EQ((5 & (5-1)) == 0, false);
}

int countOneOccurences(int n) {
    int count = 0;
    while (n) {
        ++count;
        n = n & (n - 1);
    };
    return count;
}

TEST(Bit, countOneOccurences) {
    for (int i = 0; i <= 15; ++i) {
        cout << i << "(" <<  countOneOccurences(i) << ")\t";
    }
    cout << endl;
}





