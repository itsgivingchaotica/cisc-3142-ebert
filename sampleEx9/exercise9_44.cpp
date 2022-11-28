/**
 * Rewrite the previous function using an index and replace()
*/ 

#include <iostream>

using std::string;
using std::cout;
using std::endl;

void replace(string &s, const string &oldVal, const string &newVal)
{
    //for each element in the string
    for (string::size_type index = 0; index != s.size(); ++index)
    {
        //if the word matches the old value
        if (s.substr(index, oldVal.size()) == oldVal)
        {
            //replace the old value with the new value
            s.replace(index, oldVal.size(), newVal);
            /**
             * increment the index past the word inserted
            * we continue through the string until all 
            * of the oldVals are replaced by the newVals
            */
            index += newVal.size() -1;
        }
    }
}

int main() 
{   
    string str = "Even tho I tried my best, it felt like there was no way thru the semester";
    replace(str, "tho", "though");
    replace(str, "thru", "through");
    cout << str << endl;

    return 0;
}