/**
 * Rewrite the program from the previous exercise to use a  `list`. 
 * List the changes you needed to make
*/

#include <iostream>
#include <list> //insead of <deque>

using std::string;
using std::cin;
using std::cout;
using std::list; //instead of std::deque

int main() 
{
    //just use list instead of deque
    list<string> list;
    string word;
    //Ctrl+D to exit
    while (cin >> word)
    {
        list.push_back(word);
    }
    for (auto it = list.cbegin(); it != list.cend(); ++it)
    {
        cout << *it << " ";
    }
    return 0;
}