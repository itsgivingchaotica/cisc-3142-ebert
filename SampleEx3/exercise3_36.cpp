//program to compare two arrays and two vectors for equality
#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::begin;
using std::end;
using std::vector;

bool compare(int* const b1, int* const e1, int* const b2, int* const e2)
{
  if ((e1-b1) != (e2-b2))
    return false;
  else
    {
      for (int *i = b1, *j = b2; (i!= e1) && (j != e2); ++i, ++j)
	if (*i != *j)
	  return false;
    }
  return true;
}

int main()
{
    int arr1[5] = {0, 3, 6, 9, 12};
    int arr2[5] = {0, 3, 6, 9, 12};
   
    for (auto a1 : arr1)
        cout << a1 << " ";
    
    cout << " compared to ";
    
    for (auto a2 : arr2)
        cout << a2 << " ";
    
    cout << ": ";
    
   if (compare(begin(arr1), end(arr1), begin(arr2), end(arr2)))
     cout << "Arrays are equal." << endl;
   else
     cout << "Arrays are not equal." << endl;

   int n1 = sizeof(arr1) / sizeof(arr1[0]);
   int n2 = sizeof(arr2) / sizeof(arr2[0]);
   vector<int> ivec1(arr1, arr1 + n1);
   vector<int> ivec2(arr2, arr2 + n2);

    for (auto a3 = ivec1.cbegin(); a3 != ivec1.cend(); ++a3)
        cout << *a3 << " ";
    
    cout << " compared to ";
    
    for (auto a4 = ivec2.cbegin(); a4 != ivec2.cend(); ++a4)
        cout << *a4 << " ";
    
    cout << ": ";
    
   if (ivec1 == ivec2)
     cout << "Vectors are equal." << endl;
   else
     cout << "Vectors are not equal." << endl;

   return 0;
}
