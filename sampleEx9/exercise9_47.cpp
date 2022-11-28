/**
 * Write a program that finds each numeric character 
 * and then each alphabetic character in the `string` "ab2c3d7R4E6". 
 * Write two versions of the program. 
 * The first should use `find_first_of` and the second `find_first_not_of`
*/

#include <iostream>

using std::string;
using std::cout;
using std::endl;

int main()
{
    string nums{"0123456789"};
    string alphas{"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string str{"ab2c3d7R4E6"};
    string::size_type pos = 0;

    cout << str << endl;

    cout << "Listing the numeric characters: ";
    while ((pos = str.find_first_of(nums, pos)) != string::npos){
        cout << str[pos] << " ";
        ++pos;
    }
    cout << endl;
    cout << "Listing the alphabetical characters: ";
    pos = 0;
    while ((pos = str.find_first_of(alphas, pos)) != string::npos){
        cout << str[pos] << " ";
        ++pos;
    }
    cout << endl;

    return 0;
}