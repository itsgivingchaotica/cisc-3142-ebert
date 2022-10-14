#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

int main()
{
    int val, digits;
    int sum = 0;

    cout << "Enter a value to calculate the sum of digits: ";
    cin >> val;
    while (val > 0)
    {
        digits = val%10;
        sum+=digits;
        val /= 10;
    }
    cout << "The sum of digits is: " << sum << endl;

    return 0;
}