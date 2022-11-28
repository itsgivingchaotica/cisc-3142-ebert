/**
 * Write a program to copy elements from a  `list<int>` into two `deque`s. 
 * The even-valued elements should go into one `deque` and the odds one into the other
*/

#include <iostream>
#include <list>
#include <deque>

using std::list;
using std::deque;
using std::cout;
using std::endl;

int main() 
{
    list<int> list = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    deque<int> odd;
    deque<int> even;

    for (auto it = list.cbegin(); it != list.cend(); ++it)
    {
        if (*it % 2 == 0)
            even.push_back(*it);
        else
            odd.push_back(*it);
    }
    cout << "Even integers: ";
    for (auto it = even.cbegin(); it != even.cend(); ++it)
    {
        cout << *it << " ";
    }
    cout << "\nOdd integers: ";
    for (auto it = odd.cbegin(); it != odd.cend(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}