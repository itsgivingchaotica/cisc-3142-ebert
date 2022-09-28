//program to create a vector with ten int elements, using iterator assign element a value twice its current value and print

#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

int main()
{
  vector<int> ivec;
  int i;
  int x = 0;
  cout << "Input ten integers into the vector: \n";
  while(x < 10)
    {
    cin >> i;
    ivec.push_back(i);
    ++x;
    }
    
  for (auto it = ivec.begin(); it != ivec.end(); ++it)
  {
      *it *=2;
      cout << *it << " ";
  }
    cout << ((ivec.cbegin() == ivec.cend()) ? "empty\n" : "\n");
    
  return 0;
}
