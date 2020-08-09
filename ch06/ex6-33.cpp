#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

void print(vector<int>::iterator v1, vector<int>::iterator v2)
{
    if (v1 != v2)
    {
        cout << *v1 << endl;
        print(++v1, v2);
    }
}

int main()
{
    vector<int> v{1, 2, 3, 4};
    print(v.begin(), v.end());
    return 0;
}

