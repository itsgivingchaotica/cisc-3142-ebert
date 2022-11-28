/**
 * Repeat the previous program, 
 * but compare elements in a list<int> to a vector<int>.
*/
#include <iostream>
#include <vector>
#include <list>

using std::vector;
using std::cout;
using std::endl;
using std::list;

int main() {
    list<int> list = {1, 3, 5, 7, 9};
    vector<int> v1 = {1, 3, 5, 7, 9};
    vector<int> v2 = {1, 3, 5, 7, 9, 11};
    cout << "Integer List: ";
    for (const auto &l : list)
    {
        cout << l << " ";
    }
    cout << endl;
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

    if (vector<int>(list.begin(),list.end()) == v1)
    {
        cout << "List and Vector 1 are equal" << endl;
    }
    else{
        cout << "List  and Vector 1 are not equal" << endl;
    }

    if (vector<int>(list.begin(),list.end()) == v2)
    {
        cout << "List and Vector 2 are equal" << endl;
    }
    else{
        cout << "List and Vector 2 are not equal" << endl;
    }
    return 0;
}