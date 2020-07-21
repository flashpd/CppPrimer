#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    vector<int> v3(10, 42);
    vector<int>::const_iterator it;

    for (auto it = v3.begin(); it != v3.end(); ++it)
        (*it) *= 2;

    for (auto it = v3.begin(); it != v3.end(); ++it)
        cout << *it << endl;

    return 0;
}
