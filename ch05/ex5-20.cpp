#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string s1, temp;
    while (true)
    {
        cin >> s1;
        if (s1 == temp)
        {
            cout << "OK" << endl;
            break;
        }
        temp = s1;
    }

    return 0;
}
