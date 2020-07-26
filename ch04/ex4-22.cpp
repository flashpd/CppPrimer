#include <iostream>

using std::cout;
using std::endl;

int main()
{
    int scores[] = {59, 65, 85, 100};

    for (int i = 0; i < 4; ++i)
        cout << ((scores[i] < 60) ? "fail" : ((scores[i] < 75) ? "low pass" :
                                              ((scores[i] < 90) ? "pass" : "high pass"))) << endl;

    cout << "--------" << endl;

    for (int i = 0; i < 4; ++i)
        if (scores[i] < 60)
            cout << "fail" << endl;
        else if (scores[i] < 75)
            cout << "low pass" << endl;
        else if (scores[i] < 90)
            cout << "pass" << endl;
        else
            cout << "high pass" << endl;

    return 0;
}
