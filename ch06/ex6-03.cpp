#include <iostream>

using std::cout;
using std::endl;

int fact(int val)
{
    for (int i = 0; i < 10; ++i)
        val += i;

    return val;
}

int main()
{
    cout << fact(10) << endl;

    return 0;
}
