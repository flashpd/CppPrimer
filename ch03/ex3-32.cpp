#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
    int arr[10];
    for (int i = 0; i < 10; ++i)
        arr[i] = i;

    int a2[10];
    for (int i = 0; i < 10; ++i)
        a2[i] = arr[i];

    cout << "--------" << endl;
    vector<int> vec(10);
    for (int i = 0; i != 10; ++i)
        vec[i] = arr[i];

    vector<int> v2(vec);
    for (auto i : v2)
        cout << i << " ";

    cout << endl;

    return 0;
}
