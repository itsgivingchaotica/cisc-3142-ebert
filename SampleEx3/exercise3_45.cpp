//print the elements of a multidimensional array using auto
#include <iostream>

using std::cout;
using std::endl;

int main()
{
    int ia[3][4] = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11}
    };
    cout << "Using auto: ";
    for (auto &row : ia)
        for (auto &col : row)
            cout << col << " ";
    
    cout << endl;
    
    return 0;
}
