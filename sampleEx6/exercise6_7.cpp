#include <iostream>

using std::cout;
using std:: endl;

size_t count_up()
{
    static size_t ctr = 0;
    return ctr++;
}
int main()
{
    for (size_t i = 0; i != 20; ++i)
        cout << count_up() << endl;
    return 0;
}