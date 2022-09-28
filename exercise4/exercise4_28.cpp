#include <iostream>

using std::cout;
using std::endl;

int main()
{
  cout << "The following are the sizes of the built-in types" << endl;
  cout << "bool:\t\t\t" << sizeof(bool) << " bytes" << endl;
  cout << "char:\t\t\t" << sizeof(char) << " bytes" << endl;
  cout << "unsigned char:\t\t" << sizeof(unsigned char) << " bytes" << endl;
  cout << "signed char:\t\t" << sizeof(signed char) << " bytes" << endl;
  cout << "char16_t:\t\t" << sizeof(char16_t) << " bytes" << endl;
  cout << "short:\t\t\t" << sizeof(short) << " bytes" << endl;
  cout << "unsigned short:\t\t" << sizeof(unsigned short) << " bytes" << endl;
  cout << "wchar_t:\t\t" << sizeof(wchar_t) << " bytes" << endl;
  cout << "char32_t:\t\t" << sizeof(char32_t) << " bytes" << endl;
  cout << "float:\t\t\t" << sizeof(float) << " bytes" << endl;
  cout << "int:\t\t\t" << sizeof(int) << " bytes" << endl;
  cout << "unsigned int:\t\t" << sizeof(unsigned int) << " bytes" << endl;
  cout << "long:\t\t\t" << sizeof(long) << " bytes" << endl;
  cout << "unsigned long:\t\t" << sizeof(unsigned long) << " bytes" << endl;
  cout << "double:\t\t\t" << sizeof(double) << " bytes" << endl;
  cout << "long double:\t\t" << sizeof(long double) << " bytes" << endl;
  cout << "long long:\t\t" << sizeof(long long) << " bytes" << endl;
  cout << "unsigned long long:\t" << sizeof(unsigned long long) << " bytes" << endl;
  return 0;
}
