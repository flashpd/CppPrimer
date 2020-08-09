#include <iostream>

using std::cout;
using std::endl;

void my_swap(int *&a, int *&b)
{
    int *temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a = 10, b = 20;
    int *addrA = &a, *addrB = &b;
    cout << addrA << " " << addrB << endl;
    my_swap(addrA, addrB);
    cout << "a:" << a << " b:" << b << endl;
    cout << addrA << " " << addrB << endl;

    return 0;
}
