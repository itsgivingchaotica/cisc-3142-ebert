#include <iostream>
#include "Chapter6.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int num;
    char choose;
    
    do
    {
        cout << "Enter a factorial: ";
        cin >> num;
        cout << fact(num) << endl;
        cout << "Go again? (y/n): ";
        cin >> choose;
    }while (choose == 'y' || choose == 'Y');

    cout << "Enter value to determine absolute value: ";
    int val;
    while (cin >> val)
    {
        cout << absolute(val) << endl;
        cout << "Enter value to determine absolute value: ";
    }
    return 0;

}