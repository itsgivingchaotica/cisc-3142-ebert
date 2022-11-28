/**
 * Write a program that initializes a string from a vector<char>
*/
#include <iostream>
#include <vector>

using std::vector;
using std::string;
using std::cout;
using std::endl;

int main()
{
    vector<char> cvec = {'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd'};
    string phrase(cvec.begin(),cvec.end());
    phrase.reserve(100);

    for (auto it = phrase.cbegin(); it != phrase.cend(); ++it)
    {
        cout << *it; 
    }
    return 0;
}