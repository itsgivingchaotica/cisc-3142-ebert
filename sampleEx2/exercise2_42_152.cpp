#include "Sales_data.h"

int main()
{
  Sales_data item1, item2;
  double price1, price2;
  cin >> item1.itemNo >> item1.units_sold >> price1;
  cin >> item2.itemNo >> item2.units_sold >> price2;
  item1.CalcRevenue(price1);
  item2.CalcRevenue(price2);

  if (item1.itemNo == item2.itemNo)
    {
      item1.AddData(item2);
      item1.Print();

      return 0;
    }
	else
	  {
	    cerr << "Diferent ISBN, must be the same" << endl;
	    return -1; // failure
	  }
      }
