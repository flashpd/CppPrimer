#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

const char c1[] = "Hello";
const char c2[] = "Hello";

int main()
{
    constexpr size_t len = strlen(c1) + strlen(c2) + 1;
    char c3[len];
    strcpy(c3, c1);
    strcat(c3, c2);

    cout << c3 << endl;

    return 0;
}
