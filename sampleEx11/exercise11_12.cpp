/**
 * Write a program to read a sequence of `string`s and `int`s, 
 * storing each into a `pair`. Store the `pair`s in a `vector` 
*/
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using std::vector;
using std::pair;
using std::string;
using std::ifstream;
using std::getline;
using std::istringstream;
using std::cout;
using std::endl;

void printPairs(vector<pair<string,int>> &pvec)
{
    for (auto p = pvec.cbegin(); p != pvec.cend(); ++p)
    {
        cout << (*p).first << " paired with " << ((*p).second) << endl;
    }
}

int main()
{
    
    vector<pair<string,int>> mvec, vvec, evec;
    ifstream in("pairs.txt");
    string line, word;
    int num;
    if (in.is_open())
    {
        pair<string,int> pair;
        while (in.good())
        {
            while (getline(in,line))
            {
            istringstream iss(line); 
            iss >> word >> num;
            pair = make_pair(word,num);
            mvec.push_back(pair);
            vvec.push_back({word,num}); //
            evec.emplace_back(word,num); //removes need to explicitly construct pair object
            }
        }
    }
    cout << "printing using make_pair() and push_back: \n";
    printPairs(mvec);
    cout << endl;
    cout << "printing using only push_back(): \n";
    printPairs(vvec);
    cout << endl;
    cout << "printing using emplace(): \n";
    printPairs(evec);
    cout << endl;

    return 0;
}