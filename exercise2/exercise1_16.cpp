#include <iostream>
int main()
{
  int sum = 0, val = 0;
  std::cout << "Input integers to sum, x to escape" << std::endl;
  while (std::cin >> val)
    {
      sum +=  val;
    }
  std::cout << "The sum of the integers is : " << sum << std::endl;
  return 0;
}
