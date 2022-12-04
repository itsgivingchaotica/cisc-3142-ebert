/**
 * Define a `map` for which the key is the family's last name
 * and the value is a `vector` of the children's names.
 * Write code to add new families and to add new children to an existing family.
 */

#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

using std::cin;
using std::cout;
using std::map;
using std::string;
using std::vector;

int main()
{
    map<string, vector<string>> families;

    std::string lastName, firstName;

    while ([&]() -> bool
           {
        std::cout << "Please enter last name:\n";

        return cin >> lastName && lastName != "q"; }())

    {
        std::cout << "Enter children's name:\n";
        while (cin >> firstName && firstName != "q")
        {
            // add a new child
            families[lastName].push_back(firstName);
        }
    }

    //! iterate through family map.
    for (auto f : families)
    {
        std::cout << f.first << " family:\n";

        //! iterate through the vector of children.
        for (auto v : f.second)
            cout << v << " ";
        cout << " (" << f.second.size() << " children)\n";
    }

    return 0;
}