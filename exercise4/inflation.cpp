/*
It is difficult to make a budget that spans several
years because prices are not stable. If your company needs
200 pencils per year, you cannot simply use this year’s
price as the cost of pencils 2 years from now.
Because of inflation the cost is likely to be higher than it is today.
Write a program to gauge the expected cost of an
item in a specified number of years. The program asks
for the cost of the item, the number of years from now
that the item will be purchased, and the rate of inflation.
The program then outputs the estimated cost of the item
after the specified period. Have the user enter the
inflation rate as a percentage, like 5.6 (percent).
Your program should then convert the percent to a fraction,
like 0.056, and should use a loop to estimate the price
adjusted for inflation
 */
#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::fixed;
using std::setprecision;

int main()
{
  double cost, infl, inflRate;
  int years;
  
  cout << "To calculate the rate of inflation, follow the prompts: " << endl;
  cout << "Enter the cost of  the item: ";
  cin >> cost;
  cout << "Enter the number of years from now that the item will be purchased: ";
  cin >> years;
  cout << "Enter the rate of inflation as a percentage: ";
  cin >> infl;
  
  //the inflation rate coverted to fraction
  inflRate = infl/100;
  //for each year that will pass, add the inflated cost of the product
  for (int i = 1; i<= years; i++)
    {
      cost += cost*inflRate;
    }
  //print the inflated price to two decimal places 
  cout << "The price adjusted for inflation is for " << years << " years is: $" << fixed << setprecision(2) << cost << endl;
  return 0;
}
