#include <iostream>
#include "Sales_item.h"
int main()
{
  Sales_item item1, item2;
  std::cout << "Enter the book sales from same ISBN (Ctrl+D to exit): " << std::endl;
  while (std::cin >> item1 >> item2)
    {
      if (item1.isbn() == item2.isbn())
    {
      std::cout << item1 + item2 << "\n" << std::endl;
    }
  else
    {
      std::cout << "The ISBN's do not match\nEnter the book sales from same ISBN (Ctrl+D to exit):\n" << std::endl;
    }
  }
    return 0;
}
