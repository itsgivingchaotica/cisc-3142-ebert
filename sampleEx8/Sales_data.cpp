#include "Sales_data.h"

Sales_data& Sales_data::combine(const Sales_data &rhs)
{
  units_sold += rhs.units_sold;
  revenue += rhs.revenue;
  return *this;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data total = lhs;
    total.combine(rhs);
    return total;
}

istream &read(istream &is, Sales_data &item)
{
  double price = 0;
  is >> item.itemNo >> item.units_sold >> price;
  item.revenue = price * item.units_sold;
  return is;
}

ostream &print(ostream &os, const Sales_data &item)
{
  os << "ISBN#: " << item.isbn() << "\nNumber sold: " << item.units_sold << "\nRevenue: " << item.revenue << "\nAverage price: " << item.CalcAvgPrice() << endl; 
  cout << endl;
  return os;
}

inline double Sales_data::CalcAvgPrice() const 
{ 
  return units_sold ? revenue/units_sold : 0; 
}

void processSales(istream &input, ostream &output) {
    Sales_data total;
    if (read(input, total)) {
        Sales_data trans;
        while (read(input,trans)) {
            if (total.isbn() == trans.isbn()){
                total.combine(trans);
            } else {
                print(output, total) << endl;
                total = trans;
            }
        }
        print(output,total) << endl;
    } else {
        cerr << "Data not entered" << endl;
    }
}