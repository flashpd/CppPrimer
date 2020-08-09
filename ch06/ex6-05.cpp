#include <iostream>

using std::cout;
using std::endl;

int my_abs(int num)
{
   return (num >= 0) ? num : -num;
}

int main()
{
    cout << my_abs(-1) << endl;
    return 0;;
}
