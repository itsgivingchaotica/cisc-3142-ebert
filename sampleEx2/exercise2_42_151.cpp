#include "Sales_data.h"

int main()
{
  Sales_data item;
  double price;
  cin >> item.itemNo >> item.units_sold >> price;
  item.CalcRevenue(price);
  item.Print();
  
  return 0;
}
