#include <iostream>

using std::cout;
using std::endl;
using std::initializer_list;

int sum(const initializer_list<int> &il)
{
    int sum = 0;
    for (auto i : il)
        sum += i;
    return sum;
}

int main()
{
    int ans = sum({1,2,3,4,5});
    cout << ans << endl;
    return 0;
}