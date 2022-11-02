#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> ivec = {0, 1, 2, 3, 4, 5};
    
    vector<int>::size_type cnt = ivec.size();
    for (vector<int>::size_type ix = 0; ix != ivec.size(); ++ix, --cnt)
    {
        //
        ivec[ix] = cnt;
        cout << ivec [ix] << " " << cnt << endl;
    }
    
    vector<int>::size_type cnt2 = ivec.size();
    for (vector<int>::size_type ix = 0; ix != ivec.size(); ix++, cnt2--)
    {
        //
        ivec[ix] = cnt2;
        cout << ivec [ix] << " " << cnt2 << endl;
    }
    
    return 0;
}
