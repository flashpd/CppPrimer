#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    string s2("World");
    for (char &c : s2)
    {
        c = 'X';
    }
    cout << s2 << endl;
    return 0;
}
