#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    string s1("Hello"), s2("World");

    decltype(s2.size()) index = 0;
    while (index != s2.size())
    {
        s2[index++] = 'X';
    }
    cout << s2 << endl;

    for (auto &c : s1)
    {
        c = 'X';
    }
    cout << s1 << endl;
    return 0;
}
