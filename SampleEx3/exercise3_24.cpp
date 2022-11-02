//print sum of first and last elements, second and second to last etc using iterators
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::cerr;
using std::string;
using std::vector;

int main()
{
    vector<int> ivec;
    int i = 0, len = 1;
    cout << "Enter the integers you wish to put into the vector: " << endl;
    while (cin >> i)
    {
        ivec.push_back(i);
    }
    
    if (ivec.size() > 0)
    {
        cout << "Sum of adjacent elements of the vector: ";
        if (ivec.size() > 1)
        {
            vector<int>::const_iterator it_vec = ivec.begin();
            for ( ; it_vec != ivec.end() - 1; ++it_vec)
            {
                int first = *it_vec+1;
                cout << first + *it_vec << " ";
                ++len;
            }
            cout << endl;
        }
        //print the value of the sole int if only one is inputted into the vector
        else
        {
            cout << ivec[0] << endl;
        }
    
        /*
         //begin to feed the int values into the vector
         cin >> i;
         ivec.push_back(i);
         
         cout << "Enter the next: ";
         int first = i;
         while (cin >> i)
         //iterate until the second to last element in the vector
         {
         //add adjacent elements
         cout << "\nThe sum is: " << first + i << " ";
         first = i;
         ivec.push_back(i);
         ++len;
         cout << "Enter the next: ";
         //
         }
         */
        
        //now print sum of first and last elements, second and second to last etc
        cout << "\nSum of symmetric elements of the vector traveling inward: ";
        vector<int>::const_iterator it_vec1 = ivec.cbegin(), it_vec2 = it_vec1 + len / 2, it_vec3 = ivec.cend() - 1;
        for( ; it_vec1 != it_vec2; ++it_vec1, --it_vec3)
        {
            cout << *it_vec1 + *it_vec3 << " ";
        }
        if (it_vec1 == it_vec3)
        {
            cout << *it_vec1 << endl;
        }
    }
    else
    {
        cerr << "Vector is empty" << endl;
    }
return 0;
}
