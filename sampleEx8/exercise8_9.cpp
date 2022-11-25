#include <iostream>
#include <string>
#include <sstream>

using std::istream;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::istream;
using std::istringstream;

/**
 * 
*/
istream& print(istream &is)
{
    //is.clear();
    string str;
    while (is >> str)
        cout << str << " "; //will print if the value is an integer, if not will fail
    cout << endl;
    is.clear(); //makes valid 
    return is;
}

int main()
{
    string str;
    getline(cin, str);
    istringstream iss(str);
    print(iss);
    return 0;
}