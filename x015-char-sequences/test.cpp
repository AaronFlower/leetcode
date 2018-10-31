#include "gtest/gtest.h"
#include "solution.h"
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int Fibonacci(int n) {
    if (n == 0) return 0;
    if (n <= 2) return 1;
    int fib[n + 1];
    fib[1] = fib[2] = 1;
    for (int i = 3; i <= n; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return fib[n];
}

int fib2 (int n) {
    int f1 = 0, f2 = 1;
    while (n-- > 0) {
        f2 = f1 + f2;
        f1 = f2 - f1;
    }
    return f1;
}

TEST(Solution, Null) {
    Solution s;
    vector<int> data;
    EXPECT_EQ(s.binarySearch(data, 2), -1);

    char const *str = "Hello world";
    char str2[] = "Hello";
    /* str[0] = 'K'; */
    str2[0] = 'K';
    cout << str << endl;
    cout << str2 << endl;

    cout << "Fibonacci \n" ;
    cout << Fibonacci(2) << endl;
    cout << Fibonacci(5) << endl;
    cout << Fibonacci(6) << endl;
    cout << Fibonacci(7) << endl;
    cout << Fibonacci(8) << endl;
    cout << Fibonacci(20) << endl;
    cout << Fibonacci(29) << endl;

    cout << "fib2 \n" ;
    cout << fib2(2) << endl;
    cout << fib2(5) << endl;
    cout << fib2(6) << endl;
    cout << fib2(7) << endl;
    cout << fib2(8) << endl;
    cout << fib2(20) << endl;
    cout << fib2(29) << endl;
}

