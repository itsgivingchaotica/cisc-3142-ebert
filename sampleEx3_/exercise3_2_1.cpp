#include <iostream>
#include <string>

// program to read input a line at a time

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
  string line;
  //read until end of file one line at a time
  while (getline(cin, line))
    cout << line << endl;
  return 0;
}
