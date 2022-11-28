/**
 * Rewrite the previous exercise using a position and length 
 * to manage the strings. This time use only the insert function
*/

#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::getline;

string prefixSuffix(const string& name, const string& prefix, const string& suffix)
{
    string title(name);
    //0 as index
    title.insert(0, prefix);
    title.insert(title.length(), suffix);
    return title;
}

int main()
{
    string name, prefix, suffix;

    while (cin)
    {
        getline(cin,name);
        getline(cin,prefix);
        getline(cin,suffix);
        cout << prefixSuffix(name,prefix,suffix) << endl;
    }
    return 0;
}