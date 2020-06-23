#include <iostream>
#include "header/Sales_item.h"

int main()
{
    Sales_item item;
    while (1)
    {
        std::cin >> item;
        std::cout << item << std::endl;
    }
    return 0;
}
