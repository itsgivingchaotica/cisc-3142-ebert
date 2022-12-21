/**
 * Write a program that reads two integers from the standard input and prints the result of dividing the first number by the second. Revise your program to throw an exception if the second number is zero. 
 */

#include <iostream>
#include <stdexcept>

using std::cout;
using std::cin;
using std::endl;
using std::runtime_error;

int main()
{
    int int1, int2;
    cout << "Enter two integers (bigger first): " << endl;
    cin >> int1 >> int2;
    if (int2 == 0)
    {
        throw runtime_error("Second integer cannot be 0");
    }
    double divide = int1/int2;
    cout << int1 << " divided by " << int2 << " is: " << int1/int2 << endl;
    return 0;
}