/**
 * Revise the program from p. 191 so that it looks only for duplicated words that start with an uppercase letter.
 */

#include <iostream>
#include <string>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string str;
    string prev;
    cout << "Enter words to check (Uppercase sensitive! Ctrl+D to end): " << endl;
    bool repeat = false;
    // while user inputs words
    while (cin >> str)
    {
        // if the word was last word entered and first char was uppercase
        if (str == prev && isupper(prev[0]))
        {
            // repeated! end loop
            repeat = true;
            break;
        }
        else
        {
            // assign the current word to be compared to the next
            prev = str;
        }
    }
    // if loop breaks and finds the word was repeated with uppercase print message
    if (repeat)
    {
        cout << "STOP! " << str << " was repeated in succession." << endl;
    }
    // if break never happened, print this message
    else
    {
        cout << "No word was repeated that had Uppercase first character." << endl;
    }

    return 0;
}