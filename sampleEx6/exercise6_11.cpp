#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void reset(int &v)
{
    v = 0;
}

int main()
{
    int val;
    cout << "Enter a value to reset: ";
    cin >> val;
    cout << val << " RESET! ";
    reset(val);
    cout << val << endl;
    return 0;
}