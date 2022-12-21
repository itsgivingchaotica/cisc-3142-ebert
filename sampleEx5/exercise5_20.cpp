/**
 * Write a program to read a sequence of `string`s from the standard input until either the same word occurs twice in succession or all the words have been read. Use a `while` loop to read the text one word at a time. Use the `break` statement to terminate the loop if a word occurs twice in succession. Print the word if it occurs twice in succession, or else print a message saying that no word was repeated.
 */

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string str;
    string prev;
    cout << "Enter words to check (Ctrl+D to end): " << endl;
    bool repeat = false;
    // while user inputs words
    while (cin >> str)
    {
        // if the word was last word entered
        if (str == prev)
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
    // if loop breaks and finds the word was repeated print message
    if (repeat)
    {
        cout << "STOP! " << str << " was repeated in succession." << endl;
    }
    // if break never happened, print this message
    else
    {
        cout << "No word was repeated." << endl;
    }

    return 0;
}