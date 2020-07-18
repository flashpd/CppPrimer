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
    getline(cin, s2);

    cout << "--- 1 ---" << endl;
    if (s1 == s2)
    {
        cout << s1 << endl;
    }
    else
    {
        cout << (s1 > s2 ? s1 : s2) << endl;
    }

    cout << "--- 2 ---" << endl;
    if (s1.size() == s2.size())
    {
        cout << s1 << endl;
    }
    else
    {
        cout << (s1.size() > s2.size() ? s1 : s2) << endl;
    }


    return 0;
}
