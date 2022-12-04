/**
 * Extend the `map` of children for their family name that you wrote for the exercises by having the `vector` store a `pair` that holds a child's name and birthday.
 */
#include <iostream>
#include <vector>
#include <map>
#include <set>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::make_pair;
using std::map;
using std::ostream;
using std::pair;
using std::set;
using std::string;
using std::vector;

class Family
{
public:
     using Child = pair<string, string>;
     using Children = vector<Child>;
     using Lineage = map<string, Children>;

     void add(string const &lastName, string const &firstName, string birthday)
     {
          familyData[lastName].push_back(make_pair(firstName, birthday));
     }

     ostream &print(ostream &os) const
     {
          if (familyData.empty())
          {
               return os << "No family data entered. " << endl;
          }
          for (const auto &entry : familyData)
          {
               os << entry.first << " Family:\n";
               for (const auto &child : entry.second)
                    os << child.first << " " << child.second << endl;
               os << endl;
          }
          return os;
     }

private:
     Lineage familyData;
};

int main()
{
     Family families;
     set<string> endit = {"No", "N", "n", "NO", "no"};
     string lastName, child, birthday;
     string response;
     cout << "Enter the family name, child name, birthday: ";
     while (cin >> lastName >> child >> birthday)
     {
          if (lastName == "q" || child == "q" || birthday == "q")
               break;
          families.add(lastName, child, birthday);

          cout << "continue? ";
          cin >> response;
          if (endit.find(response) != endit.end())
          {
               families.print(cout << "\nData collected: " << endl);
          }
          else
          {
               cout << "Enter the family name, child name, birthday: ";
          }
     }
     return 0;
}