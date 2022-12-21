/**
 *  Using the following definition of `ia`, copy `ia` into a `vector` and into a `list`.
 * Use the single-iterator form of `erase` to remove the elements with odd values from
 * your `list` and the even values from your `vector`
 */

#include <iostream>
#include <vector>
#include <list>

using std::begin;
using std::cout;
using std::end;
using std::endl;
using std::list;
using std::vector;

int main()
{
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    vector<int> ivec(begin(ia), end(ia));
    list<int> lst(ivec.begin(), ivec.end());
    // delee all odd integers from list
    for (auto it = lst.begin(); it != lst.end();)
    {
        if (*it % 2 == 0)
            ++it;
        else
            it = lst.erase(it);
    }
    auto it2 = ivec.begin();
    // erase even integers from vector
    while (it2 != ivec.end())
    {
        if (*it2 % 2 == 0)
            it2 = ivec.erase(it2);
        else
            ++it2;
    }
    for (auto i : ivec)
    {
        cout << i << " ";
    }
    cout << endl;
    for (auto l : lst)
    {
        cout << l << " ";
    }
    cout << endl;
    return 0;
}