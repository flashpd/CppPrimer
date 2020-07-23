#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::begin;
using std::end;

int main()
{
    int arr[] = {1, 3, 5, 7, 9};
    vector<int> vec1(begin(arr), end(arr));
    for (auto v : vec1)
        cout << v << " ";

    cout << endl;
    cout << "-------" << endl;

    vector<int> vec2(arr + 0, arr + 5);
    for (auto v : vec1)
        cout << v << " ";

    cout << endl;

    return 0;
}
