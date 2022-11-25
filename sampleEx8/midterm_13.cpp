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
        auto x = val(++i); //i is increased from 1 to 2 for each element in the vector
        cout << "x = " << x << " i = " << i << endl;
    } 

    auto it = vec.begin();
    while (it != vec.end()) 
    {   
        //int temp = *it++; is equivalent. i is increased and then assigned to pointer *it
        *it = val ((float)*it++); //change pointer to position 1
        it++;
    }
    cout << vec[0] << " " << vec[9] << endl;
    return 0;
}