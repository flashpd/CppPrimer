#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::begin;
using std::end;

int main()
{
    int a1[3] = {1, 100, 1000};
    int a2[3] = {1, 100, 1000};


    if ((end(a1) - begin(a1)) != (end(a2) - begin(a2)))
        cout << "not equal" << endl;
    else
    {
        bool flag = true;
        for (auto pbeg1 = begin(a1), pbeg2 = begin(a2);
                pbeg1 != end(a1), pbeg2 != end(a2); ++pbeg1, ++pbeg2)
        {
            if (*pbeg1 != *pbeg2)
            {
                flag = false;
                break;
            }
        }

        if (flag)
            cout << "equal" << endl;
        else
            cout << "not equal" << endl;
    }

    cout << "-------" << endl;

    vector<int> v1{1, 2, 3};
    vector<int> v2{1, 2, 4};

    if (v1 == v2)
        cout << "equal" << endl;
    else
        cout << "not equal" << endl;

    return 0;
}
