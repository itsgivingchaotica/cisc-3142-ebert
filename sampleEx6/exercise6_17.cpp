#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::boolalpha;

bool hasUppercase(const string &str)
{
    for (auto c : str)
    {
        if (isupper(c))
        {}
            return true;
        }   
        return false;
}

const string &makeLowercase(string &str)
{
    for (auto &c : str)
        if (isupper(c))
            c = tolower(c);
    return str;
}

int main()
{
    string str;
    cout << "Enter the text to check capitalization: ";
    //initialize string from user input
   while (getline(cin,str))
   {
     //call method to determine if str has capital letters
    if (hasUppercase(str) == true)
        {
            cout << "Input has uppercase leters" << endl;
            cout << "Making all lowercase: ";
            //call method to change to all lowercase returning 
            cout << makeLowercase(str) << endl;
        }
    else
    {
        cout << "No uppercase lettesr detected. ";
    }
    cout << "Enter the text to check capitalization: ";
   }
   return 0;
}