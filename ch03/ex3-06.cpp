#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    string s1("Hello"), s2("World");
    cout << "--- 1 ---" << endl;
    for (decltype(s1.size()) index = 0; index != s1.size(); ++index)
    {
        s1[index] = 'X';
    }
    cout << s1 << endl;

    cout << "--- 2 ---" << endl;
    for (auto &c : s2)
    {
        c = 'X';
    }
    cout << s2 << endl;
    return 0;
}
