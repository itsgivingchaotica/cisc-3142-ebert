#include <iostream>
#include <string>
#include "Sales_data.h"

int main()
{
    Sales_data total;
    if (cin >> total.itemNo >> total.units_sold >> total.revenue)
    {
        Sales_data trans;
        while (cin >> trans.itemNo >> trans.units_sold >> trans.revenue)
        {
            if (total.itemNo == trans.itemNo)
            {
                total.combine(trans);
            }
            else
            {
                cout << "Book No: " << total.itemNo << ", units: " << total.units_sold << ", revenue: " << total.revenue << '\n';
                total = trans;
            }
        }
        cout << "Book No: " << total.itemNo << ", units: " << total.units_sold << ", revenue: " << total.revenue << '\n';
    }
    else
    {
        cout << "Data not entered" << '\n';
        return -1;
    }
    return 0;
}