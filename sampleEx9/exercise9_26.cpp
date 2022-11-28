/**
 *  Using the following definition of `ia`, copy `ia` into a `vector` and into a `list`. 
 * Use the single-iterator form of `erase` to remove the elements with odd values from 
 * your `list` and the even values from your `vector`
*/

#include <iostream>
#include <vector>
#include <list>

using std::vector;
using std::list;
using std::cout;
using std::endl;

int main() 
{
    int ia[] = {0, 1, 1 ,2, 3, 5, 8, 13, 21, 55, 89};
    vector<int> ivec;
    list<int> lst;
     for (int i = 0; i < sizeof(ia)/sizeof(int); ++i)
    {
        ivec.push_back(ia[i]);
        lst.push_back(ia[i]);
    }
    auto it = lst.begin();
    //delee all odd integers from list
    while (it != lst.end())
    {
        if (*it % 2 == 0)
            ++it;
        else
            it = lst.erase(it);
    }
    auto it2 = ivec.begin();
    //erase even integers from vector
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