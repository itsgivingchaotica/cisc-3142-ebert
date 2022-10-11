#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void swap(int *num1, int *num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int main()
{
    int val1, val2; 
    cout << "Enter two values: ";
    cin >> val1 >> val2;
    cout << "First pointer points to: " << val1 << ", second points to: " << val2 << endl;
    //ask for user input 
    //store the values as ints
    //print 
    swap(&val1,&val2);
    //swap(&num1,&num2)
    cout << "First pointer points to: " << val1 << ", second points to: " << val2 << endl;
    //print 
    return 0;
}