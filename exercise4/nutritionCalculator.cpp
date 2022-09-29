/*
A government research lab has concluded that an
artificial sweetener commonly used in diet soda
pop will cause death in laboratory mice. A friend of
yours is desperate to lose weight but cannot give up soda pop.
Your friend wants to know how much diet soda pop it is
possible to drink without dying as a result. Write a program to
supply the answer. The input to the program is the amount of
artificial sweetener needed to kill a mouse (use 5 grams),
the mass of the mouse (use 35 grams), and the weight of the
dieter (use 45400 grams for a 100 pound person). Assume that the
lethal dose for a mouse is proportional to the lethal dose for the human.
A single can of soda pop has a mass of 350 grams. To ensure the
safety of your friend, be sure the program requests the weight at which the dieter will stop dieting, rather than the dieter’s current weight.
Assume that diet soda contains 1/10th of 1% artificial sweetener.
Use a variable declaration with the modifier const to give a name
to this fraction. You may want to express the percent as the
double value 0.001. Your program should allow the calculation
to be repeated as often as the user wishes.
*/

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){

double mDead, mWeight, dietGoal, bwPercent, sodaPercent, sodaCap;
const double artificialSweetener = 0.001;
const double sodaWeight = 350.0;

    cout << "Enter the ounces of artificla sweetener consumed by the mouse: ";
  cin >> mDead;
 cout << "Mouse weight in ounces: ";
 cin >> mWeight;
 cout << "What is your weight loss goal (lbs): ";
 cin >> dietGoal;

 bwPercent = mDead / mWeight;
 sodaCap = (dietGoal * bwPercent);
 sodaPercent = artificialSweetener * sodaWeight;
 cout << "Please do not surpass " << (sodaCap / sodaPercent) <<
   " 350 gram cans of soda to avoid mortality." << endl;

 return 0;
 
}