#include <iostream>

int main()
{
    std::cout << "Enter two numbers." << std::endl;
    int a, b;
    std::cin >> a >> b;
    std::cout << a;
    std::cout << " * ";
    std::cout << b;
    std::cout << " = ";
    std::cout << a * b;
    std::cout << std::endl;

    return 0;
}
