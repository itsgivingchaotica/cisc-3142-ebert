/**
 * Write a program using a series of `if` statements to count the number of vowels in text read from `cin`. The modify the program so that it counts both 'a' and 'A' as part of `aCnt` and so forth Modify so that it also counts the number of blank spaces, tabs, and newlines read as well as the number of occurrences of the following two-character sequences: `ff`, `fl` and `fi`
 */

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::noskipws;
using std::string;

int main()
{

    unsigned aCtr = 0, eCtr = 0, iCtr = 0, oCtr = 0, uCtr = 0, spaceCtr = 0,
             tabCtr = 0, newLineCtr = 0, ffCtr = 0, flCtr = 0, fiCtr = 0;
    char ch, prev = '\0';
    cout << "Enter text: ";

    while (cin >> noskipws >> ch)
    {
        switch (ch)
        {
        case 'a':
        case 'A':
            ++aCtr;
            break;
        case 'e':
        case 'E':
            ++eCtr;
            break;
        case 'i':
            if (prev == 'f')
            {
                ++fiCtr;
            }
        case 'I':
            ++iCtr;
            break;
        case 'o':
        case 'O':
            ++oCtr;
            break;
        case 'u':
        case 'U':
            ++uCtr;
            break;
        case ' ':
            ++spaceCtr;
            break;
        case '\t':
            ++tabCtr;
            break;
        case '\n':
            ++newLineCtr;
            break;
        case 'f':
            if (prev == 'f')
            {
                ++ffCtr;
            }
            break;
        case 'l':
            if (prev == 'f')
            {
                ++flCtr;
            }
            break;
        }
        prev = ch;
    }
    cout << "A/a counted: " << aCtr << endl;
    cout << "E/e counted: " << eCtr << endl;
    cout << "I/i counted: " << iCtr << endl;
    cout << "O/o counted: " << oCtr << endl;
    cout << "U/u counted: " << uCtr << endl;
    cout << "ff counted: " << ffCtr << endl;
    cout << "fi counted: " << fiCtr << endl;
    cout << "fl counted: " << flCtr << endl;
    cout << "Tabs counted: " << tabCtr << endl;
    cout << "Spaces counted: " << spaceCtr << endl;
    cout << "New lines counted: " << newLineCtr << endl;

    return 0;
}