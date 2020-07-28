#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::string;

int main()
{
    const vector<string> scores = { "F", "D", "C", "B", "A", "A++" };
    string letterGrade;
    int grade = 100;
    letterGrade = ((grade < 60) ? scores[0] :
                   ((grade == 100) ? scores[5] : scores[(grade - 50) / 10]));

    cout << letterGrade << endl;

    return 0;
}
