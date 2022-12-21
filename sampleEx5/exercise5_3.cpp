/**
 * Use the comma operator (p. 157) to rewrite the `while` loop from p. 11 so that it no longer requires a block. Explain whether this rewrite improves or diminishes the readability of this code.
 */

#include <iostream>

using std::cout;
using std::endl;

int main()
{
    int sum = 0, val = 1;
    /*
    use comma operator to rewrite while loop so
    that it no longer requires a block
    */
    while (val <= 10 && (sum += val, ++val))
        ;
    cout << "Sum of 1 to 10 inclusive is " << sum << endl;
    // diminishes readability of the code

    return 0;
}