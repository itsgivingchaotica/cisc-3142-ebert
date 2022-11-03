#include <iostream>
#include <string>
#include "Sales_data.h"

int main()
{
    Sales_data total(cin);
    if (total.isbn().empty() == false)
    {
        while (cin)
        {
            Sales_data trans(cin);
            if (total.isbn() == trans.isbn())
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