#include <iostream>
#include <string>
#include <cctype>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    string s1, s2;
    cin >> s1;

    for (auto &c : s1)
    {
        if (!ispunct(c))
            s2 += c;
    }
    cout << s2 << endl;
    return 0;
}
