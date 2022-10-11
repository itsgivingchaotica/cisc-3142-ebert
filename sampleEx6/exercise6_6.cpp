#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int running_count(int val)
{
    static int sum = 0; 
    return sum += val;
} 
int main()
{
    int num;
    vector<int> ivec;
    while (cin >> num)
    {
        ivec.push_back(num);
    }
    for (auto i : ivec)
    {
        cout << running_count(i) << " ";
    }
    cout << endl;
    return 0;
}