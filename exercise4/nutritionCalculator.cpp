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
safety of your friend, be sure the program requests the weight at which the dieter will stop
dieting, rather than the dieter’s current weight.
Assume that diet soda contains 1/10th of 1% artificial sweetener.
Use a variable declaration with the modifier const to give a name
to this fraction. You may want to express the percent as the
double value 0.001. Your program should allow the calculation
to be repeated as often as the user wishes.
*/
#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    double mouseDead, mouseWeight, dietGoal, lethalDose, sodaPercent, sweetenerCap, humanDead, maxSoda;
    //assume diet soda contains 1/10th of 1% artificial sweetener
    const double artificialSweetener = 0.001;
    //a single can of soda pop has a mass of 350 grams
    const double sodaWeight = 350.0;
    const double gramsConversion = 453.592;

    cout << "Enter the grams of artificial sweetener consumed by the mouse: ";
    cin >> mouseDead;
    cout << "Mouse weight in grams: ";
    cin >> mouseWeight;
    cout << "What is your weight loss goal (lbs): ";
    cin >> dietGoal;

    //calculate the percentage to body weight that the artificial sweetener is lethal
    lethalDose = mouseDead / mouseWeight;
    //find the percent of soda to body weight allowed in relation to goal
    sweetenerCap = (dietGoal * lethalDose);
    //find the percentage of artificial sweetener in a 350g can of soda
    sodaPercent = artificialSweetener * sodaWeight;
    //find the number of grams of artificial sweetener that would kill a human
    humanDead = sweetenerCap * gramsConversion;
    //find the most amount of cans that is "safe" to drink
    maxSoda = floor((sweetenerCap/sodaPercent));
    cout << "The amount of artificial sweetener that would kill a human is: " << humanDead << " grams, therefore please do not surpass " << maxSoda << " sodas to avoid mortality." << endl;

 return 0;
 
}
