#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

void print(vector<string> const &svec)
{
  cout << "The vector contains the strings: ";
  for (int i = 0; i < svec.size(); ++i)
    cout << svec.at(i) << ' ';
    cout << endl;
}

int main()
{
  string str;
  vector<string> svec;
  cout << "Enter strings: Ctrl+D to print in full " << endl;
  while (cin >> str)
    {
      svec.push_back(str);
    }
  print (svec);
  return 0;
}
