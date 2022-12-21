/**
 * Extend the program that assigned high pass, pass, and fail grades to also assign low pass for grades between 60 and 75 inclusive. Write two versions: One version that uses only conditional operators; the other should use one or more `if` statements. Which version do you think is eaisier to understand and why?
 */
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int grade;

    cout << "Enter the grades to print high pass, pass, fail as as well as low pass, Ctrl-D to complete: ";
    // use conditional operator, much easier
    while (cin >> grade)
    {
        cout << ((grade > 90) ? "high pass" : (grade < 60) ? "fail"
                                          : (grade > 75)   ? "pass"
                                                           : "low pass")
             << endl;
        // using if statements, the criteria becomes more complicated for printing the result
        if (grade > 90)
        {
            cout << "high pass" << endl;
            continue;
        }
        if (grade < 60)
            cout << "fail" << endl;
        if (grade > 75 && grade <= 90)
            cout << "pass" << endl;
        else if (grade >= 60 && grade < 75)
            cout << "low pass" << endl;
    }

    return 0;
}
