//rewrite the program from exercise6_10 to use references instead of pointers to swap the value of two ints
//which version do you think would be easier to use and why?
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

//this method is easier to use. 
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int num1, num2;
    cout << "Enter two numbers to swap: " << endl;
    cin >> num1 >> num2;
    swap(num1,num2);
    cout << num1 << '\t' << num2 << endl;

    return 0;
}