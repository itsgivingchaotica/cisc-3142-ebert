//three different version of program toprint the elements of a multidimentional array
#include <iostream>

using std::cout;
using std::endl;

int main()
{
  int ia[3][4] = {
    {0, 1, 2, 3},
    {4, 5, 6, 7},
    {8, 9, 10, 11}
  };

  cout << "Print a multidimensional array using a range for: ";
  for (int (&row)[4] : ia)
    for (int &col : row)
      cout << col << " ";

  cout << endl;

  cout << "Now using subscript: ";
  for (int i = 0; i < 3; ++i)
  {
    for (int j = 0; j < 4; ++j)
    {
        cout << ia[i][j] << " ";
    }
  }
  cout << endl;

    cout << "Using pointers: ";
  for (int (*row)[4] = ia; row != ia + 3; ++row)
  {
    for (int (*col) = *row; col != *row + 4; ++col)
    {
	  cout << *col << " ";
    }
  }
  cout << endl;
    
  return 0;
}
