//read a set of integers into a vector and print sums, use iterators to loop

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
     int i, j= 0;
    
     cout << "Enter the integers you wish to put into the vector: " << endl;
     //feed the int values into the vector
     while(cin >> i)
     {
     ivec.push_back(i);
     }
     
     if(ivec.size() > 0)
     {
     //sum of adjacent elements
     cout << "Sum of adjacent elements of the vector: ";
     if(ivec.size() > 1)
     {
     //iterate until the second to last element in the vector
     for (auto it_vec = ivec.begin(); it_vec != ivec.end() - 1; ++it_vec)
     {
     //add adjacent elements
     cout << ivec[j] + ivec[j+1] << " ";
         ++j;
     //
     }
     cout << endl;
    
         //now print sum of first and last elements, second and second to last etc
             j = 0;
             cout << "Sum of symmetric elements of the vector traveling inward: ";
         while(j <= ivec.size() - 1 - j)
             {
                 if(j < ivec.size() - 1 - j)
                     cout << ivec[j] + ivec[ivec.size() - 1 - j] << " ";
                 else
                     //print the final int if is the center element of an array of odd elements
                     cout << ivec[j] << " ";
                 ++j;
             }
             cout << endl;
         }
     //if there's only one element in the vector
         else
         {
             cout << ivec[j] << endl;
         }
     }
     else
         cerr << "Vector is empty" << endl;
return 0;
}
