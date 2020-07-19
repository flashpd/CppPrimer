#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> vec;
    int num;
    for (int i = 0; i != 3; ++i)
    {
        cin >> num;
        vec.push_back(num);
    }

    for (auto n : vec)
        cout << n << endl;

    return 0;
}
