/* author: Saoirse Siobhan Ebert*/
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
// Write a lambda that takes two ints and returns their sum
int main()
{
    auto add = [](int a, int b)
    {
        return a + b;
    };
    int a, b;
    cin >> a >> b;
    cout << "The sum of " << a << " + " << b << " using lambda function is : " << add(a, b) << endl;
    return 0;
}