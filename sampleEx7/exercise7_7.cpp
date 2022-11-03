#include <iostream>
#include <string>
#include "Sales_data.h"

int main()
{
    Sales_data total;
    if (read(cin,total))
    {
        Sales_data trans;
        while (read(cin,total))
        {
            if (total.itemNo == trans.itemNo)
            {
                total.combine(trans);
            }
            else
            {
                print(cout,total);
                total = trans;
            }
        }
        print(cout,total);
    }
    else
    {
        cout << "Data not entered" << '\n';
        return -1;
    }
    return 0;
}