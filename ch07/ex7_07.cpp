#include <iostream>
//#include <string>
#include "ex7_06.h"

using std::cin;
using std::cout;
using std::endl;
//using std::string;

int main()
{
    Sales_data total;
    if (read(cin, total))
    {  
     //   cout << total.bookNo << " " << total.units_sold << " " << total.revenue << endl;
        Sales_data trans;
        while (read(cin, trans))
        {
            if (total.isbn() == trans.isbn())
            {
                total.combine(trans);
            }
            else
            {
                // cout << total.bookNo << " " << total.units_sold << " " << total.revenue << endl;
                print(cout, total);
                total = trans;
            }
        }
        // cout << total.bookNo << " " << total.units_sold << " " << total.revenue << endl;
        print(cout, total);
    }
    else
    {
        std::cerr << "NO data?!" << endl;
        return -1;
    }

    return 0;
}

