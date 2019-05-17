#include <iostream>
#include <sstream>

using namespace std;

int main(void)
{
    string s = "Hello world Kid!";
    istringstream stream(s);
    ostringstream os;

    string w;
    int i = 0;

    while (stream >> w) {
        cout << i << ") " << w << endl;
        os << w << " | " ;
    }

    string res = os.str();
    cout << res;

    return 0;
}
