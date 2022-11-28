/**
 * Write a function that takes a `forward_list<string>` and two additional `string` arguments. 
 * The function should find the first `string` and insert the second immediately following the first. 
 * If the first `string` is not found, then insert the second `string` at the end of the list.
*/

#include <iostream>
#include <forward_list>

using std::forward_list;
using std::cout;
using std::endl;
using std::string;

void insertAfter(forward_list<string> &flst, const string &first, const string &second)
{
    auto prev = flst.before_begin();
    auto curr = flst.begin();
    //flst.end() hangs off
    while (curr != flst.end()) 
    {
        if (*curr == first)
        {
            cout << "inserting";
            flst.insert_after(curr,second);
            return;
        } else {
            prev = curr;
            ++curr;
        }
    }
    //if first not found, insert after the last element
    flst.insert_after(prev,second);
}

int main()
{
    forward_list<string> flst = {"here", "we", "go","again"};
    for (auto it = flst.cbegin(); it != flst.cend(); ++it)
    {
        cout << *it << " ";
    }
    insertAfter(flst,"we","A");
    for (auto it2 = flst.cbegin(); it2 != flst.cend(); ++it2)
    {
        cout << *it2 << " ";
    }
    insertAfter(flst,"never","B");
    for (auto it3 = flst.cbegin(); it3 != flst.cend(); ++it3)
    {
        cout << *it3 << " ";
    }
    cout << endl;
    return 0;
}