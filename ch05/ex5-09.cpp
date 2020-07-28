#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    char c;
    while (cin >> c)
    {
        if (c == 'a')
            ++aCnt;
        else if (c == 'e')
            ++eCnt;
        else if (c == 'i')
            ++iCnt;
        else if (c == 'o')
            ++oCnt;
        else if (c == 'u')
            ++uCnt;
    }
    cout << "a: " << aCnt << endl
         << "e: " << eCnt << endl
         << "i: " << iCnt << endl
         << "o: " << oCnt << endl
         << "u: " << uCnt << endl;

         return 0;
}
