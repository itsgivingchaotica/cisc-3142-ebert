//program that reads a string of characters including punctuation and writes with the punctuation removed
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
  string line;
  cout << "enter the sentence to remove punctuation: " << endl;
  getline(cin, line);
  if (!line.empty())
    {
      for (auto &c : line)
	{
	if (!ispunct(c))
	  cout << c;
	}
      cout << endl;
    }
  return 0;
}
