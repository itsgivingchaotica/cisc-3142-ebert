/**
 * Define a `map` for which the key is the family's last name 
 * and the value is a `vector` of the children's names. 
 * Write code to add new families and to add new children to an existing family.
*/

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <sstream>

using std::vector;
using std::map;
using std::string;
using std::set;
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::pair;
using std::istringstream;

void printFamilies(map<string,vector<pair<string,string>>> families)
{
for (auto it = families.begin(); it != families.end(); ++it)
        {
            vector<pair<string,string>> dropChildren = it->second;
            cout << "The " << it->first << " family has " << dropChildren.size() << " children: ";
            for (unsigned i = 0; i < dropChildren.size(); i++)
            {
                cout << dropChildren[i].first << ", DOB: " << dropChildren[i].second;
            }
            cout << endl;
        }
}

int main()
{
    //map<string, vector<string>> families;
    map<string,vector<pair<string,string>>> families;
    set<string> endit = {"No", "N", "n", "NO","no"};
    string lastName;
    string response;
    cout << "Enter the family name: ";
    while (cin >> lastName)
    {
        cout << "Enter the children's names and birthdays, 'q' to end family line: ";
        string line, child, birthday;
        vector<pair<string,string>> children;
        while (getline(cin,line))
        {
            if (child == "q")
               break;
            pair<string,string> pair;
            istringstream iss(line);
            iss >> child >> birthday;
            pair = make_pair(child,birthday);
            children.push_back(pair);
        }
    families[lastName] = children;
   
    cout << "continue? ";
    cin >> response;
    if (endit.find(response) != endit.end())
    {
        printFamilies(families);
    }
    cout << "Enter the family name: ";
    }
    return 0;
}
