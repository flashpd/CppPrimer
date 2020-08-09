#include <iostream>
#include <initializer_list>

void get_sum(std::initializer_list<int> num)
{
    int sum = 0;
    for (auto n : num)
        sum += n;

    std::cout << sum << std::endl;
}

int main()
{
    auto num = {1, 2, 3, 4};
    get_sum(num);

    return 0;
}

