#include <iostream>

using std::cout;
using std::endl;
int main()
{
    int arr[3] = {1, 100, 1000};
    int *p = arr;

    for (int i = 0; i < 3; ++i)
        *(p + i) = 0;

    for (auto i : arr)
        cout << i << " ";

    cout << endl;
    return 0;
}
