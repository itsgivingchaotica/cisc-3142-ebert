//if we change the for loop control variable to char then the characters will not be changed
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
      //changed from auto &c : str
  for (char c : str)
    c = 'X';
  cout << str << endl;
}
  return 0;
}
