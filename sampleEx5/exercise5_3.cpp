#include <iostream>
using std::cout;
using std::endl;
int main()
{
    int sum = 0, val = 1;
    /*
    use comma operator to rewrite while loop so 
    that it no longer requires a block
    */
   while (val <= 10 && (sum += val, ++val));
   cout << "Sum of 1 to 10 inclusive is " << sum << endl;
    //diminishes readability of the code

   return 0;
}