# **Exercise 4** 

# From C++ Primer (Lippman et al)
## *Exercise 3.17*
> Read a sequence of words from cin and store the values as a vector. After you've
> read all the words, process the vector and change each word to uppercase.
> Print the transformed elements, eight words to a line.

```
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

int main()
{
  string str;
  vector<string> svec;

  cout << "Enter a sequence of words separated by enter : " << endl;
  //for all strings input, push into the vector
  while (getline(cin, str))
  {
      svec.push_back(str);
  }
    for (int i = 0; i < svec.size(); ++i)
       {
       for (char &c : svec[i])
         {
         if(isalpha(c) && !isupper(c))
        //for each character in each string in the vector, move to uppercase
        c = toupper(c);
         }
        //for every eight word, go to next line
        if (i%8 == 0)
        {
            cout << "\n";
        }
        //print each element of the vector separated by a space
        cout << svec[i] << " ";
    }
    cout << endl;
    
    return 0;
}
```
## *Example:*
```
Enter a sequence of words separated by enter : 
it
was
the
best
of
times
it
was
the
worst
of
times
^D
IT WAS THE BEST OF TIMES IT WAS 
THE WORST OF TIMES 
```

## *Exercise 3.23*
> Write a program to create a vector with ten int elements. Using an iterator,
> assign each element a value that is twice its current value.
> Test your program by printing the vector

```
#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

int main()
{
  vector<int> ivec;
  int i;
  int x = 0;
  cout << "Input ten integers into the vector: \n";
  while(x < 10)
    {
    cin >> i;
    ivec.push_back(i);
    ++x;
    }
    
  //use iterator to proceed through values in the vector and assign each element its value times 2
  for (auto it = ivec.begin(); it != ivec.end(); ++it)
  {
      *it *=2;
      //print the new value
      cout << *it << " ";
  }
    //if the vector is empty, print message
    cout << ((ivec.cbegin() == ivec.cend()) ? "empty\n" : "\n");
    
  return 0;
}
```
## *Example:*
```
Input ten integers into the vector: 
4
6
2
8
4
6
2
99
34
1
Each value in the vector doubled: 8 12 4 16 8 12 4 198 68 2 
```

## *Exercise 4.28*
> Write a program to print the size of each of the built-in-types

```
#include <iostream>

using std::cout;
using std::endl;

int main()
{
  cout << "The following are the sizes of the built-in types" << endl;
  cout << "bool:\t\t\t" << sizeof(bool) << " bytes" << endl;
  cout << "char:\t\t\t" << sizeof(char) << " bytes" << endl;
  cout << "unsigned char:\t\t" << sizeof(unsigned char) << " bytes" << endl;
  cout << "signed char:\t\t" << sizeof(signed char) << " bytes" << endl;
  cout << "char16_t:\t\t" << sizeof(char16_t) << " bytes" << endl;
  cout << "short:\t\t\t" << sizeof(short) << " bytes" << endl;
  cout << "unsigned short:\t\t" << sizeof(unsigned short) << " bytes" << endl;
  cout << "wchar_t:\t\t" << sizeof(wchar_t) << " bytes" << endl;
  cout << "char32_t:\t\t" << sizeof(char32_t) << " bytes" << endl;
  cout << "float:\t\t\t" << sizeof(float) << " bytes" << endl;
  cout << "int:\t\t\t" << sizeof(int) << " bytes" << endl;
  cout << "unsigned int:\t\t" << sizeof(unsigned int) << " bytes" << endl;
  cout << "long:\t\t\t" << sizeof(long) << " bytes" << endl;
  cout << "unsigned long:\t\t" << sizeof(unsigned long) << " bytes" << endl;
  cout << "double:\t\t\t" << sizeof(double) << " bytes" << endl;
  cout << "long double:\t\t" << sizeof(long double) << " bytes" << endl;
  cout << "long long:\t\t" << sizeof(long long) << " bytes" << endl;
  cout << "unsigned long long:\t" << sizeof(unsigned long long) << " bytes" << endl;
  
  return 0;
}
```
## *Output*

```
The following are the sizes of the built-in types
bool:                  1 bytes
char:                  1 bytes
unsigned char:         1 bytes
signed char:           1 bytes
char16_t:              2 bytes
short:                 2 bytes
unsigned short:        2 bytes
wchar_t:               4 bytes
char32_t:              4 bytes
float:                 4 bytes
int:                   4 bytes
unsigned int:          4 bytes
long:                  8 bytes
unsigned long:         8 bytes
double:                8 bytes
long double:           8 bytes
long long:             8 bytes
unsigned long long:    8 bytes
```

# Practice Problems
## *Inflation*
> It is difficult to make a budget that spans several
> years because prices are not stable. If your company needs
> 200 pencils per year, you cannot simply use this year’s
> price as the cost of pencils 2 years from now.
> Because of inflation the cost is likely to be higher than it is today.
> Write a program to gauge the expected cost of an
> item in a specified number of years. The program asks
> for the cost of the item, the number of years from now
> that the item will be purchased, and the rate of inflation.
> The program then outputs the estimated cost of the item
> after the specified period. Have the user enter the
> inflation rate as a percentage, like 5.6 (percent).
> Your program should then convert the percent to a fraction,
> like 0.056, and should use a loop to estimate the price
> adjusted for inflation.

```
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
```
## *Example:*
```
To calculate the rate of inflation, follow the prompts: 
Enter the cost of  the item: 24.50
Enter the number of years from now that the item will be purchased: 4
Enter the rate of inflation as a percentage: 5.75
The price adjusted for inflation is for 4 years is: $30.64
```

## *Nutrition Calculator*
> A government research lab has concluded that an
> artificial sweetener commonly used in diet soda
> pop will cause death in laboratory mice. A friend of
> yours is desperate to lose weight but cannot give up soda pop.
> Your friend wants to know how much diet soda pop it is
> possible to drink without dying as a result. Write a program to
> supply the answer. The input to the program is the amount of
> artificial sweetener needed to kill a mouse (use 5 grams),
> the mass of the mouse (use 35 grams), and the weight of the
> dieter (use 45400 grams for a 100 pound person). Assume that the
> lethal dose for a mouse is proportional to the lethal dose for the human.
> A single can of soda pop has a mass of 350 grams. To ensure the
> safety of your friend, be sure the program requests the weight at which 
> the dieter will stop dieting, rather than the dieter’s current weight.
> Assume that diet soda contains 1/10th of 1% artificial sweetener.
> Use a variable declaration with the modifier const to give a name
> to this fraction. You may want to express the percent as the
> double value 0.001. Your program should allow the calculation
> to be repeated as often as the user wishes.

```
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
```
## *Example:*
```
Enter the grams of artificial sweetener consumed by the mouse: 5
Mouse weight in grams: 35
What is your weight loss goal (lbs): 155
The amount of artificial sweetener that would kill a human is: 10043.8 grams, therefore please do not surpass 63 sodas to avoid mortality.
```
