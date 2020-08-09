#include <iostream>

using std::cout;
using std::endl;

void my_swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a = 10, b = 20;
    my_swap(&a, &b);
    cout << "a:" << a << " b:" << b << endl;
    return 0;
}
