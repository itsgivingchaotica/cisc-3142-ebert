#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::cin;
using std::endl;

int main()
{
    vector<int> grades;
    int grade;
    
    cout << "Enter the grades to print high pass, pass, fail as as well as low pass, Ctrl-D to complete: ";
    //use conditional operator, much easier
    while (cin >> grade)
    {
    cout << ((grade > 90) ? "high pass" : (grade < 60) ? "fail" : (grade > 75) ? "pass" : "low pass") << endl;
        //using if statements, the criteria becomes more complicated for printing the result
        if (grade > 90){
            cout << "high pass" << endl;
            continue;
        }
        if (grade < 60)
            cout << "fail" << endl;
        if (grade > 75 && grade <=90)
            cout << "pass" << endl;
        else if (grade >=60 && grade <75)
            cout << "low pass" << endl;
    }
    
    return 0;
}
