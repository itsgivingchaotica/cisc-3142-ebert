#include <iostream>
#include <string>

using std::istream;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::istream;

istream& printIO(istream &is)
{
    int in;
    while (is >> in)
        cout << "print: " << in << endl; //will print if the value is an integer, if not will fail
    is.clear(); //makes valid 
    return is;
}

int main()
{
   istream& is = printIO(cin);
    if (!is.rdstate())
        cout << "Input error, is.rdstate() is " << is.rdstate() << endl; //0 for fail
    return 0;
}
/**
 * 12898
print: 12898
100
print: 100
Hello
Input error, is.rdstate() is 0
*/