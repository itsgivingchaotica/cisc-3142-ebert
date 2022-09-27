//use a range `for` to change all the characters in a `string` to `x`
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
  string str;
  cout << "Enter the string: " << endl;
  cin >> str;
  if(!str.empty())
    {
  for (auto &c: str)
    c = 'X';
  cout << str << endl;
}
  return 0;
}

