/**
 * Using a `map` iterator write an expression that assigns a value to an element.
 */

#include <iostream>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::string;

int main()
{
    map<string, string> names;
    string first, last;

    while (cin >> first >> last)
    {
        // iterator = map_name.find(key)
        auto it = names.find(first);
        if (it != names.end())
            it->second = last;
        else
            names.insert({first, last});
    }
    for (auto it = names.cbegin(); it != names.cend(); ++it)
    {
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}