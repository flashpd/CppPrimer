#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    string s1, s2, s3;

    while (getline(cin, s3))
    {
        s1 += s3;
        cout << s1 << endl;

        s2 += s3;
        s2 += " ";
        cout << s2 << endl;
    }

    return 0;
}
