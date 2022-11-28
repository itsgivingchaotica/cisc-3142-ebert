/**
 * The program on page 354 to remove even-valued elements 
 * and duplicate odd ones will not work on a list or forward_list. 
 * Why? Revise the program so that it works on these types as well.
*/
#include <iostream>
#include <list>
#include <forward_list>

using std::list;
using std::forward_list;
using std::cout;
using std::endl;
using std::advance;

int main()
{
    list<int> ilst = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    forward_list<int> flst(ilst.begin(), ilst.end());
    auto iter = ilst.begin();
    auto iter2 = flst.begin();
    auto prev = flst.before_begin();
    while (iter != ilst.end())
    {
        if (*iter % 2){
            iter = ilst.insert(iter, *iter);
            //iter += 2; //list doesn't support iterator arithmetic
            ++iter; //or advance(iter,2);
            ++iter;
        } else {
            iter = ilst.erase(iter);
        }
    }
    while (iter2 != flst.end())
    {
        if (*iter2 %2){
            iter2 = flst.insert_after(prev, *iter2);
            //advance both the current iterator and the previous
            advance(iter2,2);
            advance(prev,2);
        }
        else {
            //use erase_after(previous iterator)
            iter2 = flst.erase_after(prev);
        }
    }
    for (auto it = ilst.cbegin(); it !=ilst.cend(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
    for (auto it2 = flst.cbegin(); it2 != flst.cend(); ++it2)
    {
        cout << *it2 << " ";
    }
    cout << endl;
    return 0;
}