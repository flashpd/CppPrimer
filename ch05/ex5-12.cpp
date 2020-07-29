#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    unsigned spaceCnt = 0, tabCnt = 0, newlineCnt = 0;
    unsigned ffCnt = 0, flCnt = 0, fiCnt = 0;
    char c, preC = '\0';
    while (cin >> c)
    {
        switch (c)
        {
        case 'a':
        case 'A':
            ++aCnt;
            break;
        case 'e':
        case 'E':
            ++eCnt;
            break;
        case 'i':
            if (preC == 'f')
                ++fiCnt;
            break;
        case 'I':
            ++iCnt;
            break;
        case 'o':
        case 'O':
            ++oCnt;
            break;
        case 'u':
        case 'U':
            ++uCnt;
            break;

        case ' ':
            ++spaceCnt;
            break;
        case '\t':
            ++tabCnt;
            break;
        case '\n':
            ++newlineCnt;
            break;

        case 'l':
            if (preC == 'f')
                ++flCnt;
            break;
        case 'f':
            if (preC == 'f')
                ++ffCnt;
            break;
        }
        preC = c;
    }
    cout << "a: " << aCnt << endl
         << "e: " << eCnt << endl
         << "i: " << iCnt << endl
         << "o: " << oCnt << endl
         << "u: " << uCnt << endl
         << "space: " << spaceCnt << endl
         << "\\t: " << tabCnt << endl
         << "\\n: " << newlineCnt << endl
         << "fi: " << fiCnt << endl
         << "fl: " << flCnt << endl
         << "ff: " << ffCnt << endl;

    return 0;
}
