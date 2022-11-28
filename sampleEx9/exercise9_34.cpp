/**
 * Assuming vi is a container of ints that includes 
 * even and odd values, predict the behavior of the following loop. 
 * After you've analyzed this loop, write a program to test 
 * whether your expectations were correct.
*/

#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int main()
{
    vector<int> vi{2, 3, 4};
    //vector<int> vi = {2, 4};

    // Once an odd value is inserted, it will 
    //keep inserting because iter will always be odd
    auto iter = vi.begin();
    while (iter != vi.end())
    {  // The loop body should be a block.
        if (*iter % 2){
            iter = vi.insert(iter, *iter);
        // Once an odd value is inserted, it will keep inserting because iter will always be odd
            cout << "infinite" << " ";
        }
        ++iter;
    }
  
    //the following will never compile because 
    //the program is stuck in an inifinite loop
    for (auto it = vi.cbegin(); it != vi.cend(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

  return 0;
}