//rewrite 3_6 using a while loop and a traditional for loop
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
  string str1, str2;
  int i = 0;
  cout << "Enter two strings separated by return: " << endl;
  cin >> str1 >> str2;
  if (!str1.empty())
    {
      while (i != str1.size())
	{
	  str1[i] = 'X';
	  ++i;
	}
      cout << str1 << endl;
    }
  if (!str2.empty())
    {
      for (i = 0; i < str2.size(); ++i)
	str2[i] = 'X';
      cout << str2 <<endl;
    }
  return 0;
}
