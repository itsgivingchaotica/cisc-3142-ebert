#include <iostream>
#include "Sales_item.h"
int main()
{
  Sales_item book;
  std::cout << "Enter the book sales transactions here (Ctrl+D to end):  " << std::endl;
  while (std::cin >> book)
    {
  std::cout << book << std::endl;
    }
  return 0;
}
