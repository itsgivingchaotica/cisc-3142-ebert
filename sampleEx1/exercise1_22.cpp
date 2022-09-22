#include <iostream>
#include "Sales_item.h"
int main()
{
  Sales_item total;
  std::cout << "Enter transactions: " << std::endl;
  if (std::cin >> total)
    {
      Sales_item trans;
      int count = 1;
      while (std::cin >> trans)
	{
	  if (total.isbn() == trans.isbn())
	    {
	      total += trans;
	      ++count;
	    }
	  else
	    {
	      std::cout << total.isbn() << " appeared " << count << " times. Total sales: " << total << std::endl;
	      total = trans;
	      count = 1;
	    }
	}
      std::cout << total << " appeared " << count << " times. Total sales:  " << total << std::endl;
    }
  return 0;
}
