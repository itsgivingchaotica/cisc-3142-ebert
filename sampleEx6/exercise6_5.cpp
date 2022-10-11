#include <iostream>
#include "Chapter6.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int num;
    cout << "Enter value to determine absolute value: ";
    while (cin >> num)
    {
        cout << absolute(num) << endl;
        cout << "Enter value to determine absolute value: ";
    }
    return 0;
}