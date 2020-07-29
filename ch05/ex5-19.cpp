#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    do
    {
        string s1, s2;
        cout << "Please input two string: " << endl;
        cin >> s1 >> s2;
        cout << ((s1.size() < s2.size()) ? s1 : s2) << endl;
    } while(true);

    return 0;
}
