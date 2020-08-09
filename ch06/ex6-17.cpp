#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

bool find_upper(const string &s)
{
    bool flag = false;
    for (auto c : s)
    {
        if (isupper(c))
        {
            flag = true;
            break;
        }
    }
    return flag;
}

void upper_to_lower(string &s)
{
    for (auto &c : s)
        if (isupper(c))
            c = tolower(c);
}

int main()
{
    string str = "Hello";
    if (find_upper(str) == true)
    {
        cout << "Yes" << endl;
        upper_to_lower(str);
    }
    else
        cout << "No" << endl;

    cout << str << endl;

    return 0;
}
