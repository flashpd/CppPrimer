#include <iostream>

using std::cout;
using std::endl;
int main()
{
    int a1 = 2147483647;
    cout << a1 << " ";
    cout << a1 + 1 << endl;

    unsigned int a2 = 4294967295;
    cout << a2 << " ";
    cout << a2 + 1 << endl;

    short a3 = 65535;
    cout << a3 << " ";
    cout << a3 + 1 << endl;

    return 0;
}
