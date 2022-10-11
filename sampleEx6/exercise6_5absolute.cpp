#include "Chapter6.h"

int absolute(int val)
{
    if (val > 0 || val == 0)
        return val;
    else 
    {
        return val * -1;
    }
}