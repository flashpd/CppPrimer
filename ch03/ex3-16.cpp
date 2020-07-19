#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{

    vector<int> v1;
    cout << "--- v1 ---" << endl;
    if (!v1.empty())
        for (auto v : v1)
            cout << v << " ";
    else
        cout << "v1 is empty";

    vector<int> v2(10);
    cout << endl << "--- v2 ---" << endl;
    if (!v2.empty())
        for (auto v : v2)
            cout << v << " ";
    else
        cout << "v2 is empty";

    vector<int> v3(10, 42);
    cout << endl << "--- v3 ---" << endl;
    if (!v3.empty())
        for (auto v : v3)
            cout << v << " ";
    else
        cout << "v3 is empty";

    vector<int> v4{ 10 };
    cout << endl << "--- v4 ---" << endl;
    if (!v4.empty())
        for (auto v : v4)
            cout << v << " ";
    else
        cout << "v4 is empty";

    vector<int> v5{ 10, 42 };
    cout << endl << "--- v5 ---" << endl;
    if (!v5.empty())
        for (auto v : v5)
            cout << v << " ";
    else
        cout << "v5 is empty";

    vector<string> v6{ 10 };
    cout << endl << "--- v6 ---" << endl;
    if (!v6.empty())
        for (auto v : v6)
            cout << v << " ";
    else
        cout << "v6 is empty";

    vector<string> v7{ 10, "hi" };
    cout << endl << "--- v7 ---" << endl;
    if (!v7.empty())
        for (auto v : v7)
            cout << v << " ";
    else
        cout << "v7 is empty";

    cout << endl;
    return 0;
}
