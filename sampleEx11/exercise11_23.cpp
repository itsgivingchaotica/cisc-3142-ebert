/**
 * Rewrite the `map` that stored `vector`s of children's names with a key that is the family last name for the exercises on p. 424 to use a `multimap`
 */
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

using std::cin;
using std::cout;
using std::multimap;
using std::string;
using std::vector;

void addLastName(multimap<string, vector<string>> &families, const string &last);

void addFirstName(multimap<string, vector<string>> &families, const string &last, const string &first);

int main()
{
    multimap<string, vector<string>> families;

    string lastName, firstName;
    while (cin >> firstName >> lastName)
    {
        addLastName(families, lastName);
        addFirstName(families, lastName, firstName);
    }
    //! iterate through family map.
    cout << "\n";
    for (const auto f : families)
    {
        if (f.second.size() != 0)
        {
            cout << f.first << " family:\n";

            //! iterate through the vector of children.
            for (auto v : f.second)
                cout << v << " ";
            cout << " (" << f.second.size() << " children)\n";
        }
    }

    return 0;
}

void addLastName(multimap<string, vector<string>> &families, const string &last)
{
    families.insert({last, vector<string>()});
}

void addFirstName(multimap<string, vector<string>> &families, const string &last, const string &first)
{
    auto it = families.find(last);
    if (it != families.end())
        it->second.push_back(first);
}