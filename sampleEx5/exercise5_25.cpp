/**
 * Revise your program from the previous exercise to use a `try` block to `catch` the exception. The `catch` clause should print a message to the user and ask them to supply a new number and repeat the code inside the `try`
 */

#include <iostream>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::runtime_error;

int main()
{
    int int1, int2;
    cout << "Enter two integers (bigger first, enter between ints): ";
    while (cin >> int1 >> int2)
    {
        try
        {
            if (int2 == 0)
            {
                throw runtime_error("Second integer cannot be 0");
            }
            double divide = int1 / int2;
            cout << int1 << " divided by " << int2 << " is: " << int1 / int2 << endl;
        }
        catch (runtime_error err)
        {
            cout << err.what() << "\n"
                 << "Try again. Enter two integers: ";
        }
    }
    return 0;
}