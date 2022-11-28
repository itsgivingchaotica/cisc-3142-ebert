/** Write a program to read a sequence of `string`s from 
* the standard input into a `deque`. 
* Use iterators to write a loop to print the elements in the deque. 
*/

#include <iostream>
#include <deque>

using std::string;
using std::deque;
using std::cin;
using std::cout;

int main() 
{
    deque<string> dq;
    string word;
    //Ctrl+D to exit
    while (cin >> word)
    {
        dq.push_back(word);
    }
    for (auto it = dq.cbegin(); it != dq.cend(); ++it)
    {
        cout << *it << " ";
    }
    return 0;
}