/**
 * Write a function that takes a `string` representing a name and two other 
 * strings representing a prefix, such as "Mr." or "Ms." and a suffix, 
 * such as "Jr." or "III". Using the iterators and the insert and 
 * append functions, generate and return a new string with the 
 * suffix and prefix added to the given name. 
*/
#include <iostream>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::getline;

string prefixSuffix(const string& name, const string& prefix, const string& suffix)
{
    auto iter = name;
    iter.insert(iter.begin(),prefix.begin(),prefix.end());
    iter.append(suffix);

    return iter;
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