#include <iostream>
#include <string>

struct Sales_data
{
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

int main()
{
  Sales_data total;
  double price1;
  std::cout << "Enter transactions by book number, units, sold price, one field per line  Ctrl+D to exit): " << std::endl;
  if (std::cin >> total.bookNo >> total.units_sold >> price1)
    {
      total.revenue = total.units_sold * price1;
      Sales_data trans;
      double price2;
      unsigned count = 1;
      std::cout << "Enter next transaction:  " << std::endl;
      while (std::cin >> trans.bookNo >> trans.units_sold >> price2)
	{
	  trans.revenue = trans.units_sold * price2;
	  if (total.bookNo == trans.bookNo)
	    {
	      total.revenue += trans.revenue;
	      ++count;
	      std::cout << "Enter next transaction:  " << std::endl;
	    }
	  else
	    {
	      std::cout << total.bookNo << " appeared " << count << " times. Total sales: " << total.revenue << std::endl;
	      total.revenue = trans.revenue;
	      count = 1;
	    }
	}
	std::cout << total.bookNo << " appeared " << count <<  "times. Total sales: " << total.revenue << std::endl;
	}
      return 0;
}	
