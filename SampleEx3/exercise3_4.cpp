#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
  string s1, s2;
  cout << "type in two strings: " << endl;
  while (cin >> s1 >> s2){ //read inputs from two stirngs
  //report if equal, if not equal report which is larger
  if (s1 == s2)
    cout << "The two strings are equal." << endl;
  else  if (s1 > s2)
	cout << "The two strings are not equal, " << s1 << " is larger." << endl;
  else cout << "The two strings are not equal, " << s2 << " is larger." << endl;
  auto len1 = s1.size();
  auto len2 = s2.size();
  if (len1 == len2)
     cout << "The two strings are the same length ." << endl;
  else  if (len1 > len2)
	cout << "The two strings are not the same length, " << s1 << " is longer." << endl;
  else cout << "The two strings are not equal, " << s2 << " is longer." << endl;
  }
  return 0;
  }
