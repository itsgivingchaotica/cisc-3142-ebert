#include <iostream>

int main()
{
  std::cout << "Enter two integers: " << std::endl;
  int v1 = 0, v2 = 0;
  std::cin >> v1 >> v2;
  std::cout << "The range between the two integers is: " << std::endl;
  std::cout << v1 << std::endl;
  while (v1 < v2)
    {
      std::cout << ++v1 << std::endl;
    }
  return 0;
}
