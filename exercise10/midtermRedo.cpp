/* author: Saoirse Siobhan Ebert */
#include <iostream>
#include <vector>
#include <set>

using std::cout;
using std::endl;
using std::set;
using std::string;
using std::vector;

// count the word with the most repeated occurrences in a vector
int main()
{
    set<string> aset;
    vector<string> svec = {"how", "now", "now", "now", "brown", "how", "cow"};
    int currCount, maxCount;
    string currWord, maxWord;
    for (auto it = svec.begin(); it != svec.end(); ++it)
    {
        aset.insert(*it);
    }
    for (auto a : aset)
    {
        currWord = a;
        // using count algorithm
        currCount = count(svec.begin(), svec.end(), a);
        if (currCount > maxCount)
        {
            maxCount = currCount;
            maxWord = currWord;
        }
    }
    cout << maxWord << " had the most repetitions: " << maxCount;

    return 0;
}