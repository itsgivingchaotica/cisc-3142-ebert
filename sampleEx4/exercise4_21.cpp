#include <iostream>
#include <vector>

using std::vector;
using std::cout;

int main()
{
    vector<int> ivec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    //if odd value double the value
    cout << "The odd values in the vector doubled: ";
    for (auto &it : ivec) it = (it % 2) ? (it * 2) : it;
    for (auto it : ivec)
        cout << it << " ";
    return 0;
}

