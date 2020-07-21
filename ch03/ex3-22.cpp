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
    vector<string> str;
    for (string line; getline(cin, line); str.push_back(line));

    for (auto &word : str)
    {
        for (auto &ch : word)
        {
            if (isalpha(ch))
                ch = toupper(ch);
        }
        cout << word << endl;
    }


    return 0;
}
