/**
 * Write a program to process a vector<string> whose elements represent integral values. 
 * Produce the sum of all the elements in that vector. 
 * Change the program so that it sums of `string`s that represent floating point values.
*/
#include <iostream>
#include <vector>

using std::vector;
using std::stoi;
using std::string;
using std::cout;
using std::endl;

int intSum(vector<string> svec)
{
    int sum;
    for (auto it = svec.begin(); it !=svec.end(); ++it)
    {
        sum+=stoi(*it);
    }
    return sum;
}

float floatSum(vector<string> svec)
{
    float sum;
    for (auto it = svec.begin(); it !=svec.end(); ++it)
    {
        sum+=stof(*it);
    }
    return sum;
}

int main()
{
    vector<string> svec = {"1", "2", "3.5", "4", "5.8"};
    int isum;
    float fsum;
    isum = intSum(svec);
    fsum = floatSum(svec);
    cout << "Sum of all vector string elements" << endl;
    cout << "To Integer: " << isum
    << "\nTo Floating Point: " << fsum << endl;
    return 0;
}