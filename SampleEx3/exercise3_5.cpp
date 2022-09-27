#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::cerr;
using std::string;

int main()
{
  string input, line1, line2;
  cout << "Enter words to concatenate. Ctrl + D to finish: " << endl;
  while (cin >> input)
    {
      line1 += input;
      line2 = line2 + input + " ";
    }
  if (!line1.empty())
    cout << line1 << endl;
  if (!line2.empty())
    cout << line2 << endl;
  else
    cerr << "Error! No input given" << endl;
  return 0;
}
