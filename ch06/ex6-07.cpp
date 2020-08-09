#include <iostream>

using std::cout;
using std::endl;

size_t my_call()
{
    static int n = 0;
    return n++;
}

int main()
{
    for (int i = 0; i < 10; ++i)
        cout << my_call() << endl;

    return 0;
}
