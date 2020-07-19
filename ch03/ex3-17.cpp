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
    //
    vector<string> vec;

    for (string word; cin >> word; vec.push_back(word));
    for (auto &str : vec)
        for (auto &c : str)
            c = toupper(c);

    for (auto str : vec)
        cout << str << " " << endl;

    return 0;
}
