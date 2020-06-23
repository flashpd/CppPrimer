#include <iostream>
#include "header/Sales_item.h"

int main()
{
    Sales_item item1, item2;

    if (std::cin >> item1)
    {
        while (std::cin >> item2)
        {
            if (item1.isbn() == item2.isbn())
                item1 += item2;
            else
                break;
        }
    }
    std::cout << item1 << std::endl;

    return 0;
}
