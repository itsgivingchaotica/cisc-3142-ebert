#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

bool valuePresent(vector<int>::iterator itbegin, vector<int>::iterator itend, int val)
{
    for (auto it = itbegin; it != itend; ++it)
    {
        if (*it == val)
        {
            return true;
        }
    }
    return false;
}

vector<int>:: iterator findValue(vector<int>::iterator itbegin, vector<int>::iterator itend, int val)
{
    for (auto it = itbegin; it != itend; ++it)
    {
        if (*it == val)
        {
            return it;
        }
    }
    //handles case where element is not found
    return itend;
}

int main() {
    vector<int> ivec = {1, 2, 3, 4, 5};
    for (const auto &i : ivec)
    {
        cout << i;
    }
    cout << endl;

    if (valuePresent(ivec.begin(), ivec.end(), 6))
    {
        cout << "value is present: 6" << endl;
    } else {
    cout << "value not present: 6" << endl;
    }
    if (valuePresent(ivec.begin(), ivec.end(), 4))
    {
        cout << "value is present: 4" << endl;
    } else {
    cout << "value not present:4 " << endl;
    }
    vector<int>::iterator found;
    found = findValue(ivec.begin(), ivec.end(), 6);
    if (*found == 0)
    {
        cout << "Value is not present: 6" << endl;
    }
    else {
        cout << "Value is present: 6" << endl;
    }
    cout << "iterator function returned " << *found << endl;
    found = findValue(ivec.begin(), ivec.end(), 4);
    if (*found == 0)
    {
        cout << "Value is not present: 4" << endl;
    }
    else {
        cout << "Value is present: " << endl;
    }
    cout << "iterator function returned " << *found << endl;


    return 0;
}