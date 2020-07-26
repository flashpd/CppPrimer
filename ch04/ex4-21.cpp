#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> vec{1, 2, 3, 4, 5};

    for (auto &c : vec)
        (c % 2 == 1) ? (c *= 2) : c;

    for (auto c : vec)
        cout << c << " ";

    cout << endl;

    return 0;
}
