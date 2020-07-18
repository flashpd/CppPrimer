#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    string s1, s2;
    getline(cin, s1);
    cout << s1 << endl;

    while (getline(cin, s2))
    {
        cout << s2 << endl;
    }

    return 0;
}
