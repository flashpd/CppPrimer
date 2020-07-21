#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> vec;
    for (int i; cin >> i; vec.push_back(i));

    if (vec.empty())
    {
        cout << "vector empty" << endl;
        return 0;
    }
    if (vec.size() == 1)
    {
        cout << vec[0] << endl;
        return 0;
    }

    for (auto beg = vec.begin(), en = vec.end() - 1; beg <= en; ++beg, --en)
        cout << *beg + *en << endl;

    return 0;
}
