/**
* How would you initialize a vector<double> from a list<int>?
* From a vector<int>?
*/

#include <iostream>
#include <list>
#include <vector>

using std::list;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    list<int> nums = {1, 2, 3, 4, 5};
    vector<int> ivec = {6, 7, 8, 9, 10};
    cout << "Integer list: ";
    for (const auto &n : nums)
    {
        cout << n;
    }
    cout << endl;

    cout << "Integer vector: ";
    for (const auto &i : ivec)
    {
        cout << i;
    }
    cout << endl;

    vector<double> dvec(nums.begin(), nums.end());
    cout << "Double vector from Integer List: ";
    for (const auto &d : dvec)
    {
        cout << d;
    }
    cout << endl;

    vector<double> dvec2(ivec.begin(), ivec.end());
    cout << "Double vector from Integer vector: ";
    for (const auto &d2 : dvec2)
    {
        cout << d2;
    }
    cout << endl;

    return 0;
}