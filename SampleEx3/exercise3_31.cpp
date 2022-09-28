//program to define an array of ten ints, giving each element the same value as the position in the array, then print the array

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
  int arr[10];
  for (int i=0; i<10; ++i)
    arr[i] = i;

  for (auto it : arr)
    cout << it << " ";
  cout << endl;
  
  return 0;
}
