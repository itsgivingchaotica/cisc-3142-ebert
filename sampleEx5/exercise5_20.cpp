#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main()
{
    string str;
    string prev;
    cout << "Enter words to check (Ctrl+D to end): " << endl;
    bool repeat = false;
    //while user inputs words
    while (cin >> str)
    {
        //if the word was last word entered
        if (str == prev)
        {
            //repeated! end loop
            repeat = true;
            break;
        }
        else{
            //assign the current word to be compared to the next
            prev = str;
        }
    }
    //if loop breaks and finds the word was repeated print message
    if (repeat)
    {
        cout << "STOP! " << str << " was repeated in succession." << endl;
    }
    //if break never happened, print this message
    else
    {
        cout << "No word was repeated." << endl;
    }

    return 0;
}