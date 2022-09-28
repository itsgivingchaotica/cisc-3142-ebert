//change all elements in text to uppercase
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
  vector<string> text;
  string str;
  cout << "Enter your text: ";
  while (getline(cin,str))
    {
      text.push_back(str);
    }
    vector<string>::iterator it = text.begin();
  for (; it != text.end() && !it->empty(); ++it)
    {
      for (char &c : *it)
	{
	  if (isalpha(c) && !isupper(c))
          c = toupper(c);
	}
      cout << *it << " ";
    }
    cout << endl;
  return 0;
}
