#include <iostream>

int main()
{
    int a = 10;
    int *b = &a;
    int *c = b;
    int d = 20;
    std::cout << "a " << a << " | *b " << *b << " | *c " << *c << std::endl;

    *b = 11;
    std::cout << "a " << a << " | *b " << *b << " | *c " << *c << std::endl;

    *c = d;
    std::cout << "a " << a << " | *b " << *b << " | *c " << *c << std::endl;
    return 0;
}
