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
// ostream &print(ostream&, const Sales_data&);
// Sales_data add(const Sales_data &lhs, const Sales_data &rhs);

class Sales_data
{
  friend Sales_data add(const Sales_data &lhs, const Sales_data &rhs);
  friend istream &read(istream&, Sales_data&);
  friend ostream &print(ostream&, const Sales_data&);

  inline double CalcAvgPrice() const;
    string itemNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

  public:
    Sales_data() : Sales_data("", 0, 0.0f){ }
    explicit Sales_data(istream &is) : Sales_data() { read(is, *this); }
    Sales_data(const string &s, unsigned n, double p) : itemNo(s), units_sold(n), revenue(p*n){ }
    explicit Sales_data(const string &s) : Sales_data(s, 0, 0.0f) { }

    string isbn() const { return itemNo; }
    Sales_data& combine(const Sales_data &rhs);
 
};

#endif // SALES_DATA_H