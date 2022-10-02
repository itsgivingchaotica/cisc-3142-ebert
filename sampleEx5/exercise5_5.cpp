#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

int main()
{
    int grade;
    string letterGrade;
    const vector<string> letterScores = {"F", "D", "C", "B", "A", "A++"};
    vector<int> numericScores;
    vector<string> finalScores;
    cout << "Enter the grades (Ctrl+D to complete): " << endl;
    //create vector of numeric scores
    while (cin >> grade)
    {
        numericScores.push_back(grade);
    }
    //assign the proper letter grade based on the numeric scores
    for (auto &n : numericScores)
    {
        if (n < 60)
            letterGrade = letterScores[0];
        else 
        {
            letterGrade = letterScores[(n - 50) / 10];
            if (n != 100)
            {
                if (n % 10 > 7)
                {
                    letterGrade += '+';
                } else if (n % 10 < 3) {
                    letterGrade += '-';
                }
            }
        }
        finalScores.push_back(letterGrade);
    }   
    //print the final letter grade scores
    for (auto f : finalScores)
        cout << f << " ";

    cout << endl;
    return 0;
}      
