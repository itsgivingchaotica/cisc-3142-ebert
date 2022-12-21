/**
 * Write a version of the transaction-processing program from p. 24 using the `Sales_data` class you defined for exercises on p. 72. Add the `combine` and `isbn` members to the `Sales_data` class you wrote for exercises on p. 76. Revise your transaction-processing program from p. 256 to use these members.
 */

#include <iostream>
#include <string>
#include "Sales_data.h"

using std::cin;
using std::cout;
using std::endl;

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
    cout << endl;
    return 0;
}