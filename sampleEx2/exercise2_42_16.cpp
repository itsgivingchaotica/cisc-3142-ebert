#include "Sales_data.h"

int main()
{
  Sales_data total;
  double totalPrice;
  if (cin >> total.itemNo >> total.units_sold >> totalPrice)
    {
      total.CalcRevenue(totalPrice);
      Sales_data trans;
      double transPrice;

      while (cin >> trans.itemNo >> trans.units_sold >> transPrice)
	{
	  trans.CalcRevenue(transPrice);
	  if (total.itemNo == trans.itemNo)
	    {
	      total.AddData(trans);
	    }
	  else
	    {
	      total.Print();
	      total.SetData(trans);
	    }
	}
      total.Print();

      return 0;
    }
  else
    {
      cerr << "No data" << endl;
      return -1; // failure
    }
}
