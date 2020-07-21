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
    for (int i = 0; i != vec.size() - 1; ++i)
        cout << vec[i] + vec[i + 1] << endl;

    cout << "-------" << endl;
    for (int i = 0; i != vec.size() / 2 + 1; ++i)
    {
        if (i != (vec.size() - 1) / 2)
            cout << vec[i] + vec[vec.size() - 1] << endl;
        else
            cout << vec[i] << endl;
    }
    return 0;
}
