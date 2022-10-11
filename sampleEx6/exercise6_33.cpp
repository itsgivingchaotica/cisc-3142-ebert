#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

void print (const vector<int> &ivec, int index)
{
    if (index == 0)
    {
        cout << ivec[0] << ' ';
        return;
    }
    print(ivec, index - 1);
    cout << ivec[index] << ' ';
}

int main()
{
    vector<int> ivec = {1,2,3,4,5};
    print(ivec, ivec.size() - 1);
}