#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
int main()
{
    int arr[10], arr2[10];
    for(int i = 0; i < 10; ++i)
        arr[i] = i;
    for(int i = 0; i < 10; ++i)
        arr2[i] = arr[i];

    for (auto it : arr2)
      cout << it << " ";
    cout << endl;

    vector<int> ivec(10);
    for (int i=0; i<10; ++i)
      ivec[i] = i;
    vector<int> ivec2 = ivec;

    for (auto it_vec : ivec)
      cout << it_vec << " ";
    cout << endl;
    
    return 0;
}
