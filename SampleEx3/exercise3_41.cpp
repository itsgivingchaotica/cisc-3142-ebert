//program to initialize a vector from an array of ints
#include <iostream>
#include <vector>
#include <iterator>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::begin;
using std::end;


int main()
{
  int size;
  int int_arr[] = {0, 1, 2, 3, 4, 5};

  vector<int> ivec(begin(int_arr), end(int_arr));
  cout << "As a vector: " << endl;
  for (auto it = ivec.cbegin(); it != ivec.cend(); ++it)
    cout << *it << " ";

    cout << endl;
  size = ivec.size();
  int int_arr2[size];
  for (int i = 0; i < size; i++)
  {
    int_arr2[i] = ivec[i];
  }
  cout << "As an array: " << endl;
    for (auto i : int_arr2)
    {
        cout << i << " ";
    }
    cout << endl;

  return 0;
}
