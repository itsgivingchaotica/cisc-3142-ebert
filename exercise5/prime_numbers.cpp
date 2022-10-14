#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

bool checkPrime(int val)
{
    int j = val / 2;
    for (int i = 2; i <= j; i++)
    {
        if (val % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    vector<int> primes;
    int a = 3, b = 100;

    for (int i = a; i <= b; i++)
    {
        if(checkPrime(i))
        primes.push_back(i);
    }

    cout << "List of primes between 3 and 100: ";

    for (auto p : primes)
    {
        cout << p << " ";
    }
    return 0;
}