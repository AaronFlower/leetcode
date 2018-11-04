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

