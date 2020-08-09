#include <iostream>

using std::cout;
using std::endl;

void print(int (&arr)[3])
{
    for (auto a : arr)
        cout << a << endl;
}

int main()
{
    int arr[3] = {1, 2, 3};
    print(arr);
    return 0;
}
