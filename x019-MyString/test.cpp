#include "gtest/gtest.h"
#include "mystring.h"

#include <iostream>

using std::cout;
using std::endl;
using std::string;


void testLeak() {
    MyString str("Hello My String");
    MyString str2("Hello");
    cout << str << endl;
    cout << str2 << endl;
}

TEST(MyString, Constructor) {
    testLeak();
}


