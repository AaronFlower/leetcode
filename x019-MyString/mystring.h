#ifndef LEET_CODE_STRING__
#define LEET_CODE_STRING__ 

#include <iostream>
using std::ostream;

class MyString {
public:
    MyString(const char* str = nullptr);
    MyString(const MyString &other);
    ~MyString();
    
    MyString& operator=(const MyString& other);
    
    friend ostream& operator<<(ostream& out, const MyString& myStr);

private:
    char *pstr;
};

#endif /* ifndef LEET_CODE_STRING__ */
