#include <iostream>
int main()
{
  unsigned u = 10, u2 = 42;
  std::cout << "unsigned 42 - unsigned 10 = " << u2 - u << std::endl;
  std::cout << "unsigned 10 - unsigned 42 = " << u - u2 << std::endl;
  
  int i = 10, i2 = 42;
  std::cout << "42 - 10 = " << i2 - i << std::endl;
  std::cout << "10 - 42 = " << i - i2 << std::endl;
  std::cout << "10 - unsigned 10 = " << i - u << std::endl;
  std::cout << "unsigned 10 - 42 = " << u - i2 << std::endl;
  return 0;
}
