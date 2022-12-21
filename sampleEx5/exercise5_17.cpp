/**
 * Given two `vector`s of `int`s, write a program to determine whether one `vector` is a prefix of the other. For `vector`s of unequal length, compare the number of elements of the smaller `vector`. For example, given the `vector`s containing `0, 1, 1, 2` and `0, 1, 1, 2, 3, 5, 8`, respectively your program should return true.
 */

#include <iostream>
#include <vector>
#include <sstream>

using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stringstream;
using std::getline;

void inputVector(vector<int> &v)
{
    string str;
    getline(cin, str);
    stringstream ss(str);
    int input;
    while (ss >> input){
        v.push_back(input);
    }
}

bool isPrefix(const vector<int> &v1, const vector<int> &v2)
{
    auto it1 = v1.cbegin(), it2 = v2.cbegin();
    for (; it1 != v1.cend() && it2 != v2.cend(); ++it1, ++it2)
        if (*it1 != *it2)
            break;
        return it1 == v1.cend() || it2 == v2.cend();
}

int main()
{
    vector<int> v1, v2;
    cout << "To begin comparing two vectors to determine if one is a prefix of the other: " << endl;
    inputVector(v1);
    cout << "Enter the second vector: " << endl;
    inputVector(v2);
    cout << "The vector ";
    const vector<int> &rhs = v1.size() < v2.size () ? v1 : v2;
     const vector<int> &lhs = rhs == v1 ? v2 : v1;
    for (auto r : rhs)
    {
        cout << r << " ";
    }
    cout << " is prefix of vector ";
    for (auto l : lhs)
    {
        cout << l << ", ";
    }
    cout << " :";

    cout << (isPrefix(v1, v2) ? "true" : "false")  << endl;
    return 0;
}

