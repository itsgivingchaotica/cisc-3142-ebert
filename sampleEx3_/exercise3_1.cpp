#include <iostream>
#include <string>

using std::cin;
using std::cout; using std::endl;

struct Sales_data
{
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

int main()
{
  int sum = 0, val = 50;
  while (val <= 100)
    {
      sum += val;
      ++val;
    }
  cout << "Sum of 50 to 100 inclusive is " << sum << endl;

   Sales_data total;
  double price1;
  cout << "Enter transactions by book number, units, sold price, one field per line  Ctrl+D to exit): " << endl;
  if (cin >> total.bookNo >> total.units_sold >> price1)
    {
      total.revenue = total.units_sold * price1;
      Sales_data trans;
      double price2;
      unsigned count = 1;
      cout << "Enter next transaction:  " << endl;
      while (cin >> trans.bookNo >> trans.units_sold >> price2)
	{
	  trans.revenue = trans.units_sold * price2;
	  if (total.bookNo == trans.bookNo)
	    {
	      total.revenue += trans.revenue;
	      ++count;
	      cout << "Enter next transaction:  " << endl;
	    }
	  else
	    {
	      cout << total.bookNo << " appeared " << count << " times. Total sales: " << total.revenue << endl;
	      total.revenue = trans.revenue;
	      count = 1;
	    }
	}
	cout << total.bookNo << " appeared " << count <<  "times. Total sales: " << total.revenue << endl;
	}
  
  return 0;
}
