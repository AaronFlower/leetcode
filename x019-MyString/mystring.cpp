#include "mystring.h"
#include <cstring>

using std::cout;
using std::endl;

MyString::MyString(const char* str) {
    cout << "MyString : Constructor" << endl;
    if (!str) {
        pstr = nullptr;
        return;
    }
    int len = strlen(str);
    cout << "len" << len << endl;

    pstr = new char[len + 1];
    strcpy(pstr, str);
}

MyString::~MyString() {
    if (pstr) {
        cout << "MyString:: deconstructor " << endl;
        delete []pstr;
    }
}

ostream& operator<<(ostream& out, const MyString& myStr) {
    out << myStr.pstr ;
    return out;
}
