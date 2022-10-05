#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::cin;

int main()
{
    string ans, str1, str2;

    do
    {
        cout << "Input two strings: ";
        cin >> str1 >> str2;
        if (str1 == str2)
        {
            cout << str1 << " is equal to " << str2;
        }
        cout << (str1 <= str2 ? str1 : str2) << " is smaller\n";
        cout << "Go again? (y/n): ";
        cin >> ans;
    }
    while (ans == "y");
    return 0;
}