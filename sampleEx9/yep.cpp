#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int main() 
{
    vector<int> ivec = {1, 2, 3};
    cout << "ivec.at(0): " << ivec.at(0) << "\nivec[0]: " << ivec[0] 
    << "\n*ivec.begin(): " << *ivec.begin() << "\nivec.front(): " << ivec.front() << endl;
    vector<int> ivec2;
    //these would all fail
    //cout << "ivec2.at(0): " << ivec2.at(0); //terminating with uncaught exception of type std::out_of_range: vector
    //cout << "\nivec2[0]: " << ivec2[0];//segmentation fault
    //cout << "\n*ivec2.begin(): " << *ivec2.begin(); //segmentation fault
    //cout << "\nivec2.front()" << ivec2.front(); //segmentation fault
    cout << endl;

    return 0;
}