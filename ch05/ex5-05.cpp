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
    if (grade < 60)
        letterGrade = scores[0];
    else if (grade < 70)
        letterGrade = scores[(grade - 50) / 10];
    else if (grade < 80)
        letterGrade = scores[(grade - 50) / 10];
    else if (grade < 90)
        letterGrade = scores[(grade - 50) / 10];
    else
        letterGrade = scores[(grade - 50) / 10];

    cout << letterGrade << endl;

    return 0;
}
