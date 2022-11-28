/**
 * Write a program to find and remove the 
 * odd-valued elements in a forward_list<int>.
*/
#include <iostream>
#include <forward_list>

using std::forward_list;
using std::cout;
using std::endl;

int main()
{
    forward_list<int> flst = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto prev = flst.before_begin();
    auto curr = flst.begin();
    while (curr != flst.end())
    {
        if (*curr % 2 == 0){
            prev = curr;
            ++curr;
        } else 
            curr = flst.erase_after(prev);
    }
    for (auto it = flst.cbegin(); it != flst.cend(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
