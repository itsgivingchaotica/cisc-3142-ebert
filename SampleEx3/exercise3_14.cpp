//program to read a sequence of ints from cin and store those values in a vector
#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

void print(vector<int> const &ivec)
{
  cout << "The vector contains the integers: ";
  for (int i = 0; i < ivec.size(); ++i)
    cout << ivec.at(i) << ' ';
}

int main()
{
  int i;
  vector<int> ivec;
  cout << "Enter integers: Ctrl+D to print in full " << endl;
  while (cin >> i)
    {
      ivec.push_back(i);
    }
  print (ivec);
  return 0;
}
