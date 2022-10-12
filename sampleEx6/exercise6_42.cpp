//Given the third parameter of make_plural a default of 's'. Test your program by printing singular and plural versions of the words success and failure
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

string make_plural(size_t ctr, const string &word, const string &ending = "s")
{
    return (ctr > 1) ? word + ending : word;
}

int main()
{
    string str;
    cout << "Singular: " << make_plural(1, "game") << " " << make_plural(1, "loss", "es") << endl;
    cout << "Plural: " << make_plural(2, "game") << " " << make_plural(2, "loss", "es") << endl;
    return 0;
}