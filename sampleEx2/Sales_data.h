#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>
#include <iostream>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;

struct Sales_data
{
  string itemNo;
  unsigned units_sold = 0;
  double revenue = 0.0;

  Sales_data& combine(const Sales_data &rhs);
  void CalcRevenue(double price);code 
  double CalcAvgPrice() const;
  void SetData(Sales_data data);
  void AddData(Sales_data data);
  void Print();
};

void Sales_data::CalcRevenue(double price)
{
  revenue = units_sold * price;}

void Sales_data::SetData(Sales_data data)
{
  itemNo = data.itemNo;
  units_sold = data.units_sold;
  revenue = data.revenue;
}

Sales_data& combine(const Sales_data &rhs)
{
  units_sold += rhs.units_sold;
  revenue += rhs.revenue;
  return *this;
}

void Sales_data::AddData(Sales_data data)
{
  if (itemNo != data.itemNo)
    {
      return;
    }
    units_sold +=data.units_sold;
    revenue += data.revenue;
}

double Sales_data::CalcAvgPrice() const
{
  if (units_sold != 0)
    {
      return revenue / units_sold;
    }
  else
    {
      return 0.0;
    }
}

void Sales_data::Print()
{
  cout << itemNo << " " << units_sold << " " << revenue << " ";
  double avgPrice = CalcAvgPrice();
  if (avgPrice != 0.0){
  cout << avgPrice << endl;
} else {
    cout << "(no sales)" << endl;
  }   
}

#endif // SALES_DATA_H
    
