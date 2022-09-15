#include <iostream>

int main()
{
  int v1=0, v2=0;
  std::cout << "Enter two integers: " << std::endl;
  std::cin >> v1 >> v2;
  std::cout << " The range between the two integers is: " << std::endl;
  if (v1 > v2)
    {
      for (int i = v1; i>=v2; i--)
	std::cout << i << std::endl;
    }
 else if (v1 < v2)
    {
      for (int i = v1; i <= v2; i++)
	{
	  std::cout << i << std::endl;
	}
    }
return 0;
}
