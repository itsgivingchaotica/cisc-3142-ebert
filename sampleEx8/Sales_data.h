#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>
#include <iostream>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::istream;
using std::ostream;

class Sales_data;
istream& read(istream&, Sales_data&);
ostream &print(ostream&, const Sales_data&);
Sales_data add(const Sales_data &lhs, const Sales_data &rhs);

class Sales_data
{
  friend Sales_data add(const Sales_data &lhs, const Sales_data &rhs);
  friend istream &read(istream&, Sales_data&);
  friend ostream &print(ostream&, const Sales_data&);
  public:
    Sales_data() = default;
    //Sales_data(const string &s) : itemNo(s){ }
    Sales_data(istream &is) { read(is, *this); }
    Sales_data() : Sales_data("", 0, 0.0f)
    {
      cout << "Sales_data() initialized to null/zero" << endl;
    }
    Sales_data(const string &s) : Sales_data(s, 0, 0.0f)
    {
      cout << "Sales_data(const string &s) initialized" << endl;
    }
    Sales_data(const string &s, unsigned n, double p) : itemNo(s), units_sold(n), revenue(p*n)
    { 
      cout << "Sales_data(const std::string&, unsigned, double)" << endl; 
    }
    string isbn() const { return itemNo; }
    Sales_data& combine(const Sales_data &rhs);
 
  private:
    inline double CalcAvgPrice() const;
    string itemNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

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
  os << " ISBN#: " << item.isbn() << "number sold: " << item.units_sold << ", revenue: " << item.revenue << " average price: " << item.CalcAvgPrice(); 
  return os;
}

inline double Sales_data::CalcAvgPrice() const 
{ 
  return units_sold ? revenue/units_sold : 0; 
}

#endif // SALES_DATA_H