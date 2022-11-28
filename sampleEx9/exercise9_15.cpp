/**
 * Write a program to determine whether two `vector<int>`s are equal.
*/
#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int main() {
    vector<int> v1 = {1, 3, 5, 7, 9};
    vector<int> v2 = {1, 3, 5, 7, 9};
    vector<int> v3 = {1, 3, 5, 7, 9, 11};
    cout << "Vector 1: ";
    for (const auto &a : v1)
    {
        cout << a << " ";
    }
    cout << endl;
    cout << "Vector 2: ";
    for (const auto &b : v2)
    {
        cout << b << " ";
    }
    cout << endl;
    cout << "Vector 3: ";
    for (const auto &c : v3)
    {
        cout << c << " ";
    }
    cout << endl;

    if (v1 == v2)
    {
        cout << "Vectors 1 and 2 are equal" << endl;
    }
    else{
        cout << "Vectors 1 and 2 are not equal" << endl;
    }

    if (v1 == v3)
    {
        cout << "Vectors 1 and 3 are equal" << endl;
    }
    else{
        cout << "Vectors 1 and 3 are not equal" << endl;
    }
    return 0;
}