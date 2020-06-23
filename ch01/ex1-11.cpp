#include <iostream>

int main()
{
    std::cout << "Enter two numbers: " << std::endl;
    int a = 0, b = 0;
    std::cin >> a >> b;

    while (a <= b)
    {
        std::cout << a << " ";
        ++a;
    }
    std::cout << std::endl;

    return 0;
}
