//using pointers, write a function to swap the values of two ints
//Test the function by calling it and printing the swapped values
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int num1, num2;
    cout << "Enter two numbers to swap: " << endl;
    cin >> num1 >> num2;
    swap(&num1,&num2);
    cout << num1 << '\t' << num2 << endl;

    return 0;
}