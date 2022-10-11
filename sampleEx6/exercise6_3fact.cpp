#include <iostream>
#include "Chapter6.h"

using std::cin;
using std::cout;
using std::endl;

int fact(int val)
{
    int result = 0;
    if (val < 0)
    {
        cout << "Invalid entry";
    }
    else if(val == 0 || val == 1)
    {
        result = 1;
    }
    else
    {
        result = val * fact(val -1);
    }
    return result;
}

