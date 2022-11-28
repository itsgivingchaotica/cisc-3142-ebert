/**
 * Write a program to assign the elements from a `list` 
 * of `char*` pointers to C-style character `string`s. 
*/
#include <iostream>
#include <list>
#include <vector>

using std::string;
using std::vector;
using std::list;
using std::cout;
using std::endl;

int main(){
    list<string> sl = {"Every", "dog", "has", "his", "day"};
    cout << "List of char* pointers: ";
    for (const auto &s : sl)
    {
        cout << s << " ";
    }
    cout << endl;
    vector<const char*> csl = {"Just", "kidding"};
    sl.assign(csl.cbegin(), csl.cend());
    cout << "Assign list of char* pointers to vector of strings: ";
    for (const auto &c : csl)
    {
        cout << c << " ";
    }
    return 0;
}