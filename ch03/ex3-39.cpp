#include <iostream>
#include <string>
#include <cstring>

using std::cout;
using std::endl;
using std::string;

int main()
{
    string s1 = "Hello";
    string s2 = "Hello";

    if (s1 == s2)
        cout << "equal" << endl;
    else
        cout << "not equal" << endl;

    cout << "-------" << endl;

    const char c1[] = "Hello";
    const char c2[] = "Hello";

    if (!strcmp(c1, c2))
        cout << "equal" << endl;
    else
        cout << "not equal" << endl;

    return 0;
}
