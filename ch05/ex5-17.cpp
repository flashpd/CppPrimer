#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    vector<int> vec1{0, 1, 1, 2};
    vector<int> vec2{0, 1, 1, 2, 3, 5, 8};

    bool flag = true;
    for (int i = 0; i < vec1.size(); ++i)
        if (vec1[i] != vec2[i])
        {
            flag = false;
            break;
        }

    cout << (flag ? "true" : "false") << endl;

    return 0;
}
