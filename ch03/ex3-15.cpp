#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    vector<string> vec;
    string str;
    for (int i = 0; i != 3; ++i)
    {
        cin >> str;
        vec.push_back(str);
    }

    for (auto s : vec)
        cout << s << endl;

    return 0;
}
