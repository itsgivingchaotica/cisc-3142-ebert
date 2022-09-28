#include <iostream>

using std::begin;
using std::end;
using std::endl;
using std::cout;
int main()
{
int arr[10];
for(int *ptr1 = begin(arr), *ptr2 = end(arr); ptr1 != ptr2; ++ptr1)
{
	*ptr1 = 0;
    cout << *ptr1 << " ";
}
    cout << endl;

 return 0;
}
