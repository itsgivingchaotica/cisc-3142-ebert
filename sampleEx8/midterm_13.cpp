#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int val(int &i) { return i+i; }
float val(float i) { return i*10; }

int main()
{
    vector<int> vec(10,1);
    
    for (auto &i : vec){
        auto x = val(++i);
        cout << "x = " << x << " i = " << i << endl;
    }

    auto it = vec.begin();
    while (it != vec.end()) 
    {
        *it = val ((float)*it++);
        it++;
    }
    cout << vec[0] << " " << vec[9] << endl;
    return 0;
}