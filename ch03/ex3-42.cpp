#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::begin;
using std::end;

int main()
{
    vector<int> vec{1, 3, 5, 7, 9};
    int arr[5];

    for (int i = 0; i < 5; ++i)
        arr[i] = vec[i];

    for (auto a : arr)
        cout << a << " ";

    cout << endl;

    return 0;
}


